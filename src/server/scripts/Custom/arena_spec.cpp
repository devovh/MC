/*
* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/* ScriptData
Name: Arena Spectator
%Complete: 100
Comment: Script allow spectate arena games
Category: Custom Script
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "ArenaTeamMgr.h"
#include "BattlegroundMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "ArenaTeam.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "CreatureTextMgr.h"
#include "Config.h"
#include "ScriptedGossip.h"
#include "CreatureAI.h"

int8 UsingGossip;

class arena_spectator_commands : public CommandScript
{
public:
    arena_spectator_commands() : CommandScript("arena_spectator_commands") { }

    static bool HandleSpectateCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid target_guid;
        std::string target_name;
        if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
            return false;

        Player* player = handler->GetSession()->GetPlayer();
        if (target == player || target_guid == player->GetGUID())
        {
            handler->PSendSysMessage("You can't spectate yourself.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->IsInCombat())
        {
            handler->PSendSysMessage("You are in combat.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!target)
        {
            handler->PSendSysMessage("Target is not online or does not exist.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetPet())
        {
            handler->PSendSysMessage("You must hide your pet.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetMap()->IsBattlegroundOrArena() && !player->IsSpectator())
        {
            handler->PSendSysMessage("You are already in a battleground or arena.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Map* cMap = target->GetMap();
        if (!cMap->IsBattleArena())
        {
            handler->PSendSysMessage("Player is not in an Arena match.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetMap()->IsBattleground())
        {
            handler->PSendSysMessage("You can't do that while in a battleground.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->HasAura(32728) || target->HasAura(32727))
        {
            handler->PSendSysMessage("You can't do that. The Arena match didn't start yet.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->IsSpectator())
        {
            handler->PSendSysMessage("You can't do that. Your target is a spectator.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        
        if (player->IsMounted())
        {
            handler->PSendSysMessage("Cannot Spectate while mounted.");
            handler->SetSentErrorMessage(true);
            return false;
        }


        // all's well, set bg id
        // when porting out from the bg, it will be reset to 0
        player->SetBattlegroundId(target->GetBattlegroundId(), target->GetBattlegroundTypeId());
        // remember current position as entry point for return at bg end teleportation
        if (!player->GetMap()->IsBattlegroundOrArena())
            player->SetBattlegroundEntryPoint();

        // stop flight if need
        if (player->IsInFlight())
        {
            player->GetMotionMaster()->Clear();
            player->CleanupAfterTaxiFlight();
        }
        // save only in non-flight case
        else
            player->SaveRecallPosition();

        // search for two teams
        Battleground *bGround = target->GetBattleground();
        if (bGround->isRated())
        {
            uint32 slot = bGround->GetArenaType() - 2;
            if (bGround->GetArenaType() > 3)
                slot = 2;
            uint32 firstTeamID = target->GetArenaTeamId(slot);
            uint32 secondTeamID = 0;
            Player *firstTeamMember  = target;
            Player *secondTeamMember = NULL;
            for (Battleground::BattlegroundPlayerMap::const_iterator itr = bGround->GetPlayers().begin(); itr != bGround->GetPlayers().end(); ++itr)
                if (Player* tmpPlayer = ObjectAccessor::FindPlayer(itr->first))
                {
                    if (tmpPlayer->IsSpectator())
                        continue;

                    uint32 tmpID = tmpPlayer->GetArenaTeamId(slot);
                    if (tmpID != firstTeamID && tmpID > 0)
                    {
                        secondTeamID = tmpID;
                        secondTeamMember = tmpPlayer;
                        break;
                    }
                }

                if (firstTeamID > 0 && secondTeamID > 0 && secondTeamMember)
                {
                    ArenaTeam *firstTeam  = sArenaTeamMgr->GetArenaTeamById(firstTeamID);
                    ArenaTeam *secondTeam = sArenaTeamMgr->GetArenaTeamById(secondTeamID);
                    if (firstTeam && secondTeam)
                    {
                        handler->PSendSysMessage("You entered a Rated Arena.");
                        handler->PSendSysMessage("Teams:");
                        handler->PSendSysMessage("|cFFffffff%s|r vs |cFFffffff%s|r", firstTeam->GetName().c_str(), secondTeam->GetName().c_str());
                        handler->PSendSysMessage("|cFFffffff%u(%u)|r -- |cFFffffff%u(%u)|r", firstTeam->GetRating(), firstTeam->GetAverageMMR(firstTeamMember->GetGroup()),
                            secondTeam->GetRating(), secondTeam->GetAverageMMR(secondTeamMember->GetGroup()));
                    }
                }
        }

        // to point to see at target with same orientation
        float x, y, z;
        target->GetContactPoint(player, x, y, z);

        player->TeleportTo(target->GetMapId(), x, y, z, player->GetAbsoluteAngle(target), TELE_TO_GM_MODE);
        player->SetPhaseMask(target->GetPhaseMask(), true);
        player->SetSpectate(true);
        target->GetBattleground()->AddSpectator(player->GetGUID());

        return true;
    }

    static bool HandleSpectateCancelCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player =  handler->GetSession()->GetPlayer();

        if (!player->IsSpectator() || player->IsSpectateCanceled())
        {
            handler->PSendSysMessage("You are not a spectator.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        // RemoveSpectator shouldn't be needed to be done explicitly as it'll be done in the CancelSpectate func
        player->GetBattleground()->RemoveSpectator(player->GetGUID());
        player->CancelSpectate();
        player->TeleportToBGEntryPoint();

        return true;
    }

    static bool HandleSpectateFromCommand(ChatHandler* handler, const char *args)
    {
        Player* target;
        ObjectGuid target_guid;
        std::string target_name;
        if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
            return false;

        Player* player = handler->GetSession()->GetPlayer();

        if (!target)
        {
            handler->PSendSysMessage("Player is not online or does not exist.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!player->IsSpectator())
        {
            handler->PSendSysMessage("You are not a spectator, spectate someone first.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->IsSpectator() && target != player)
        {
            handler->PSendSysMessage("You can't do that. Your target is a spectator.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetMap() != target->GetMap())
        {
            handler->PSendSysMessage("You can't do that. Your target might be in a different arena match.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target && target->HasAuraType(SPELL_AURA_MOD_STEALTH))
        {
            handler->PSendSysMessage("You can't target stealthed players.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check for arena preperation
        // if exists than battle didn`t begin
        if (target && target->HasAura(32728) || target->HasAura(32727))
        {
            handler->PSendSysMessage("You can't do that. The Arena match didn't start yet.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target == player && player->GetSpectateFrom())
            player->SetViewpoint(player->GetSpectateFrom(), false);
        else
            player->SetViewpoint(target, true);
        return true;
    }

    // addon data
    static bool HandleSpectateResetCommand(ChatHandler* handler, const char *args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player->IsSpectator())
        {
            handler->PSendSysMessage("You are not a spectator.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Battleground *bGround = player->GetBattleground();
        if (!bGround)
            return false;

        if (bGround->GetStatus() != STATUS_IN_PROGRESS)
            return true;

        for (Battleground::BattlegroundPlayerMap::const_iterator itr = bGround->GetPlayers().begin(); itr != bGround->GetPlayers().end(); ++itr)
            if (Player* tmpPlayer = ObjectAccessor::FindPlayer(itr->first))
            {
                if (tmpPlayer->IsSpectator())
                    continue;

                uint32 tmpID = bGround->GetPlayerTeam(tmpPlayer->GetGUID());

                // generate addon massage
                std::string pName = tmpPlayer->GetName();
                std::string tName = "";

                if (Player *target = tmpPlayer->GetSelectedPlayer())
                    tName = target->GetName();

                SpectatorAddonMsg msg;
                msg.SetPlayer(pName);
                if (tName != "")
                    msg.SetTarget(tName);
                msg.SetStatus(tmpPlayer->IsAlive());
                msg.SetClass(tmpPlayer->GetClass());
                msg.SetCurrentHP(tmpPlayer->GetHealth());
                msg.SetMaxHP(tmpPlayer->GetMaxHealth());
                Powers powerType = tmpPlayer->GetPowerType();
                msg.SetMaxPower(tmpPlayer->GetMaxPower(powerType));
                msg.SetCurrentPower(tmpPlayer->GetPower(powerType));
                msg.SetPowerType(powerType);
                msg.SetTeam(tmpID);
                msg.SendPacket(player->GetGUID());
            }

            return true;
    }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> spectateCommandTable =
        {
            { "player",	 rbac::RBAC_PERM_COMMAND_SPECTATE_PLAYER, true, &HandleSpectateCommand,       "" },
            { "view",	 rbac::RBAC_PERM_COMMAND_SPECTATE_VIEW,   true, &HandleSpectateFromCommand,   "" },
            { "reset",   rbac::RBAC_PERM_COMMAND_SPECTATE_RESET,  true, &HandleSpectateResetCommand,  "" },
            { "leave",   rbac::RBAC_PERM_COMMAND_SPECTATE_LEAVE,  true, &HandleSpectateCancelCommand, "" },
            //{ NULL,					0,						 false,				NULL,			  "" }
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "spectate", rbac::RBAC_PERM_COMMAND_SPECTATE, false, NULL, "", spectateCommandTable },
            //{ NULL, 0, false, NULL, "", NULL }
        };

        return commandTable;
    }
};

enum NpcSpectatorActions {
    NPC_SPECTATOR_ACTION_2V2_GAMES = 1000,
    NPC_SPECTATOR_ACTION_3V3_GAMES = 2000,
    NPC_SPECTATOR_ACTION_5V5_GAMES = 3000,
    NPC_SPECTATOR_ACTION_SPECIFIC = 500,
    NPC_SPECTATOR_ACTION_SELECTED_PLAYER = 4000
};

class ArenaSpectatorNPC
{
public:
    static ArenaSpectatorNPC* instance();

    std::string GetClassIconById(uint8 id);
    std::string GetGamesStringData(Battleground* team, uint16 mmr, uint16 mmrTwo, std::string firstTeamName, std::string secondTeamName);
    ObjectGuid GetFirstPlayerGuid(Battleground* team);
    //std::string GetMatchCount(uint8 type);
    void GetMatchInformation(Battleground* arena, Player* target, uint32& firstTeamId, std::string& firstTeamName, std::string& secondTeamName, uint16& mmr, uint16& mmrTwo);
    void ShowPage(Player* player, uint16 page, uint32 IsTop);
    void AddBGToMap(Battleground* bg);
    void RemoveBGFromMap(Battleground* bg);
    void ClearBGMap();

private:
    const uint8 GamesOnPage = 14;

    typedef std::unordered_map<uint32, Battleground*> BGMap;
    BGMap _bgMap;
};

#define sArenaSpectatorNPC ArenaSpectatorNPC::instance()

class ArenaSpectatorNPC_BG : public PlayerScript
{
public:
    ArenaSpectatorNPC_BG() : PlayerScript("ArenaSpectatorNPC_BGScript") { }

    void OnBattlegroundCreate(Battleground* bg) {
        if (bg->isArena())
        {
            sArenaSpectatorNPC->AddBGToMap(bg);
        }
    }

    void OnBattlegroundDestroy(Battleground* bg) {
        sArenaSpectatorNPC->RemoveBGFromMap(bg);
    }
};

ArenaSpectatorNPC* ArenaSpectatorNPC::instance()
{
    static ArenaSpectatorNPC instance;
    return &instance;
}

std::string ArenaSpectatorNPC::GetClassIconById(uint8 id) {
    std::string sClass = "";
    switch (id) {
    case CLASS_WARRIOR:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:0:1:0:1|t|r";
        break;
    case CLASS_PALADIN:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:0:1:2:3|t|r";
        break;
    case CLASS_HUNTER:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:0:1:1:2|t|r";
        break;
    case CLASS_ROGUE:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:2:3:0:1|t|r";
        break;
    case CLASS_PRIEST:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:2:3:1:2|t|r";
        break;
    case CLASS_DEATH_KNIGHT:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:1:2:2:3|t|r";
        break;
    case CLASS_SHAMAN:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:1:2:1:2|t|r";
        break;
    case CLASS_MAGE:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:1:2:0:1|t|r";
        break;
    case CLASS_WARLOCK:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:3:4:1:2|t|r";
        break;
    case CLASS_DRUID:
        sClass = "|TInterface\\WorldStateFrame\\Icons-Classes:13:13:0:0:4:4:3:4:0:1|t|r";
        break;
    }
    return sClass;
}

std::string ArenaSpectatorNPC::GetGamesStringData(Battleground* team, uint16 mmr, uint16 mmrTwo, std::string firstTeamName, std::string secondTeamName) {
    std::string teamsMember[PVP_TEAMS_COUNT];
    uint32 firstTeamId = 0;
    for (Battleground::BattlegroundPlayerMap::const_iterator itr = team->GetPlayers().begin(); itr != team->GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first)) {
            if (player->IsSpectator())
                continue;

            if (player->IsGameMaster())
                continue;

            uint32 team = itr->second.Team;
            if (!firstTeamId)
                firstTeamId = team;

            teamsMember[firstTeamId == team] += GetClassIconById(player->GetClass());
        }

    std::string data = teamsMember[0] + "" + secondTeamName + " (";
    std::stringstream ss;
    std::stringstream sstwo;
    ss << mmr;
    sstwo << mmrTwo;
    data += sstwo.str();
    data += ") - ";
    data += "(" + ss.str();
    data += ") " + firstTeamName + "" + teamsMember[1];
    return data;
}

ObjectGuid ArenaSpectatorNPC::GetFirstPlayerGuid(Battleground* team) {
    for (Battleground::BattlegroundPlayerMap::const_iterator itr = team->GetPlayers().begin();
        itr != team->GetPlayers().end(); ++itr)
        if (Player* player = ObjectAccessor::FindPlayer(itr->first))
            return itr->first;
    return ObjectGuid::Empty;
}

/*std::string ArenaSpectatorNPC::GetMatchCount(uint8 type) {
    uint16 i = 0;

    for (auto& itr : _bgMap)
    {
        Battleground* bg = itr.second;
        if (BattlegroundMgr::IsArenaType(bg->GetTypeID()) && bg->GetArenaType() == type && bg->isRated())
            i++;
    }

    return std::to_string(i);
}
*/
void ArenaSpectatorNPC::GetMatchInformation(Battleground* arena, Player* target, uint32& firstTeamId, std::string& firstTeamName, std::string& secondTeamName, uint16& mmr, uint16& mmrTwo) {
    uint8 slot;

    switch (arena->GetArenaType())
    {
    case ARENA_TYPE_2v2:
        slot = 0;
        break;
    case ARENA_TYPE_3v3:
        slot = 1;
        break;
    case ARENA_TYPE_5v5:
        slot = 2;
        break;
    default:
        return;
    }

    firstTeamId = target->GetArenaTeamId(slot);
    firstTeamName = (sArenaTeamMgr->GetArenaTeamById(firstTeamId))->GetName();
    Battleground::BattlegroundPlayerMap::const_iterator citr = arena->GetPlayers().begin();
    for (; citr != arena->GetPlayers().end(); ++citr)
    {
        if (Player* plrs = ObjectAccessor::FindPlayer(citr->first)) {
            if (plrs->GetArenaTeamId(slot) != firstTeamId) {
                mmrTwo = arena->GetArenaMatchmakerRating(citr->second.Team);
                secondTeamName = (sArenaTeamMgr->GetArenaTeamById(plrs->GetArenaTeamId(0)))->GetName();
            }
            else if (plrs->GetArenaTeamId(slot) == firstTeamId) {
                mmr = arena->GetArenaMatchmakerRating(citr->second.Team);
            }
        }
    }
}

void ArenaSpectatorNPC::ShowPage(Player* player, uint16 page, uint32 IsTop) {
    uint32 firstTeamId = 0;
    uint16 TypeOne = 0;
    uint16 TypeTwo = 0;
    uint16 TypeThree = 0;
    uint16 mmr = 0;
    uint16 mmrTwo = 0;
    std::string firstTeamName = "";
    std::string secondTeamName = "";
    bool hasNextPage = false;
    uint16 currentPage;

    if (_bgMap.empty())
        return;

    for (auto& itr : _bgMap) {
        Battleground* arena = itr.second;
        Player* target = ObjectAccessor::FindPlayer(GetFirstPlayerGuid(arena));

        if (!arena->GetPlayersSize())
            continue;

        if (!arena->isRated()) {
            continue;
        }

        GetMatchInformation(arena, target, firstTeamId, firstTeamName, secondTeamName, mmr, mmrTwo);

        if (IsTop == 2 && arena->GetArenaType() == ARENA_TYPE_2v2) {
            TypeOne++;
            if (TypeOne > (page + 1) * GamesOnPage) {
                hasNextPage = true;
                break;
            }
            if (TypeOne >= page * GamesOnPage)
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, GetGamesStringData(arena, mmr, mmrTwo, firstTeamName, secondTeamName), GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + GetFirstPlayerGuid(arena).GetCounter());
        }
        else if (IsTop == 3 && arena->GetArenaType() == ARENA_TYPE_3v3) {
            TypeTwo++;
            if (TypeTwo > (page + 1) * GamesOnPage) {
                hasNextPage = true;
                break;
            }
            if (TypeTwo >= page * GamesOnPage)
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, GetGamesStringData(arena, mmr, mmrTwo, firstTeamName, secondTeamName), GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + GetFirstPlayerGuid(arena).GetCounter());
        }
        else if (IsTop == 5 && arena->GetArenaType() == ARENA_TYPE_5v5) {
            TypeThree++;
            if (TypeThree > (page + 1) * GamesOnPage) {
                hasNextPage = true;
                break;
            }
            if (TypeThree >= page * GamesOnPage)
                AddGossipItemFor(player, GOSSIP_ICON_BATTLE, GetGamesStringData(arena, mmr, mmrTwo, firstTeamName, secondTeamName), GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SELECTED_PLAYER + GetFirstPlayerGuid(arena).GetCounter());
        }
    }

    switch (IsTop)
    {
    case 2:
        currentPage = NPC_SPECTATOR_ACTION_2V2_GAMES + page;
        break;
    case 3:
        currentPage = NPC_SPECTATOR_ACTION_3V3_GAMES + page;
        break;
    case 5:
        currentPage = NPC_SPECTATOR_ACTION_5V5_GAMES + page;
        break;
    default:
        return;
    }

    if (page > 0)
    {
        AddGossipItemFor(player, 7, "<- Back", GOSSIP_SENDER_MAIN, currentPage - 1);
    }

    if (hasNextPage)
    {
        AddGossipItemFor(player, 7, "Next ->", GOSSIP_SENDER_MAIN, currentPage + 1);
    }
}

void ArenaSpectatorNPC::AddBGToMap(Battleground* bg)
{
    if (!bg)
        return;

    _bgMap[bg->GetInstanceID()] = bg;
}

void ArenaSpectatorNPC::RemoveBGFromMap(Battleground* bg)
{
    _bgMap.erase(bg->GetInstanceID());
}

void ArenaSpectatorNPC::ClearBGMap()
{
    _bgMap.clear();
}

//const uint8  GamesOnPage    = 15;

class npc_arena_spectator : public CreatureScript
{
public:
    npc_arena_spectator() : CreatureScript("npc_arena_spectator") { }

    // Passive Emotes
    struct NPC_PassiveAI : public ScriptedAI
    {
        NPC_PassiveAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override {
            if (!player || !me)
                return true;

            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_Arena_2v2_4:16|t 2v2"/*+ sArenaSpectatorNPC->GetMatchCount(ARENA_TYPE_2v2) */, + GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_2V2_GAMES);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_Arena_3v3_4:16|t 3v3"/*+ sArenaSpectatorNPC->GetMatchCount(ARENA_TYPE_3v3) */, + GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_3V3_GAMES);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_Arena_5v5_4:16|t 5v5"/*+ sArenaSpectatorNPC->GetMatchCount(ARENA_TYPE_5v5) */, + GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_5V5_GAMES);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\achievement_boss_cthun:16|tSpectate Specific Player", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_SPECIFIC, "", 0, true);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\PaperDollInfoFrame\\UI-GearManager-Undo:16|tRefresh", GOSSIP_SENDER_MAIN, 100);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\gossipframe\\dailyactivequesticon:16|tHelp", GOSSIP_SENDER_MAIN, 200);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*sender*/, uint32 action) override {
            if (!player || !me)
                return true;

            ClearGossipMenuFor(player);

            if (action == 100) {
                OnGossipHello(player);
            }

            if (action >= NPC_SPECTATOR_ACTION_2V2_GAMES && action < NPC_SPECTATOR_ACTION_3V3_GAMES) {
                AddGossipItemFor(player, 11, "< Main Menu >", GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player, 4, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_2V2_GAMES);
                sArenaSpectatorNPC->ShowPage(player, action - NPC_SPECTATOR_ACTION_2V2_GAMES, ARENA_TYPE_2v2);
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
            }
            else if (action >= NPC_SPECTATOR_ACTION_3V3_GAMES && action < NPC_SPECTATOR_ACTION_5V5_GAMES) {
                AddGossipItemFor(player, 11, "< Main Menu >", GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player, 4, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_3V3_GAMES);
                sArenaSpectatorNPC->ShowPage(player, action - NPC_SPECTATOR_ACTION_3V3_GAMES, ARENA_TYPE_3v3);
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
            }
            else if (action >= NPC_SPECTATOR_ACTION_5V5_GAMES && action < NPC_SPECTATOR_ACTION_SELECTED_PLAYER) {
                AddGossipItemFor(player, 11, "< Main Menu >", GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player, 4, "Refresh", GOSSIP_SENDER_MAIN, NPC_SPECTATOR_ACTION_5V5_GAMES);
                sArenaSpectatorNPC->ShowPage(player, action - NPC_SPECTATOR_ACTION_5V5_GAMES, ARENA_TYPE_5v5);
                SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
            }
            else if (action == 200) {
                AddGossipItemFor(player, 11, "< Main Menu >", GOSSIP_SENDER_MAIN, 100);
                SendGossipMenuFor(player, 190112, me-GetGUID());
            }
            else {
                ObjectGuid guid = ObjectGuid(HighGuid::Player, action - NPC_SPECTATOR_ACTION_SELECTED_PLAYER);
                if (Player* target = ObjectAccessor::FindPlayer(guid)) {
                    ChatHandler handler(player->GetSession());
                    char const* pTarget = target->GetName().c_str();
                    arena_spectator_commands::HandleSpectateCommand(&handler, pTarget);
                }
            }
            return true;
        }

        bool OnGossipSelectCode(Player* player, uint32 sender, uint32 action, const char* code) override {
            ClearGossipMenuFor(player);

            if (sender != GOSSIP_SENDER_MAIN)
            {
                return false;
            }

            if (!code)
            {
                code = "";
            }

            if (action == NPC_SPECTATOR_ACTION_SPECIFIC) {
                const char* plrName = code;

                char playerName[50];
                strcpy(playerName, plrName);

                for (int i = 0; i < 13; i++) {
                    if (!playerName[i])
                        break;
                    if (i == 0 && playerName[i] > 96)
                        playerName[0] -= 32;
                    else if (playerName[i] < 97)
                        playerName[i] += 32;
                }

                if (Player* target = ObjectAccessor::FindPlayerByName(playerName)) {
                    ChatHandler handler(player->GetSession());
                    char const* pTarget = target->GetName().c_str();
                    CloseGossipMenuFor(player);
                    arena_spectator_commands::HandleSpectateCommand(&handler, pTarget);
                    return true;
                }
                ChatHandler(player->GetSession()).PSendSysMessage("Player is not online or does not exist.");
                OnGossipHello(player);
                return false;
            }
            CloseGossipMenuFor(player);
            return true;
        }
};

// CREATURE AI
CreatureAI* GetAI(Creature* creature) const override
{
    return new NPC_PassiveAI(creature);
}
};


void AddSC_arena_spectator_script()
{
    new arena_spectator_commands();
    new npc_arena_spectator();
    new ArenaSpectatorNPC_BG();
}
