#include "Chat.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "ObjectAccessor.h"
#include "ArenaTeamMgr.h"
#include "WorldSession.h"

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
			Player *firstTeamMember = target;
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
				ArenaTeam *firstTeam = sArenaTeamMgr->GetArenaTeamById(firstTeamID);
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
		Player* player = handler->GetSession()->GetPlayer();

		if (!player->IsSpectator())
		{
			handler->PSendSysMessage("You are not a spectator.");
			handler->SetSentErrorMessage(true);
			return false;
		}

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

		if (target->HasAuraType(SPELL_AURA_MOD_STEALTH))
		{
			handler->PSendSysMessage("You can't target stealthed players.");
			handler->SetSentErrorMessage(true);
			return false;
		}

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

		// check for arena preperation
		// if exists than battle didn`t begin
		if (target->HasAura(32728) || target->HasAura(32727))
		{
			handler->PSendSysMessage("You can't do that. The Arena match didn't start yet.");
			handler->SetSentErrorMessage(true);
			return false;
		}

		(target == player && player->GetSpectateFrom()) ? player->SetViewpoint(player->GetSpectateFrom(), false) :
			player->SetViewpoint(target, true);
		return true;
	}

	static bool HandleSpectateResetCommand(ChatHandler* handler, const char *args)
	{
		Player* player = handler->GetSession()->GetPlayer();

		if (!player)
		{
			handler->PSendSysMessage("Cant find player.");
			handler->SetSentErrorMessage(true);
			return false;
		}

		if (!player->IsSpectator())
		{
			handler->PSendSysMessage("You are not a spectator!");
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

				SpectatorAddonMsg msg; // Travis
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

void AddSC_spectate_commandscript()
{
	new arena_spectator_commands();
}
