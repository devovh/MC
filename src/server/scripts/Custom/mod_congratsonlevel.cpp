/*
# Congrats On Level #
#### A module for AzerothCore by [StygianTheBest](https://github.com/StygianTheBest/AzerothCore-Content/tree/master/Modules)
------------------------------------------------------------------------------------------------------------------
### Description ###
------------------------------------------------------------------------------------------------------------------
This module rewards players when they reach specific levels. It has the option to reward gold, two items, and a
buff or any combination. It also announces to the world when a player levels up. All rewards can be set in the
config file for quick modifications.
### Features ###
------------------------------------------------------------------------------------------------------------------
- Announces player level up to world
- Awards the player for gaining new levels
- The player forfeits the rewards if their bags are full
### Data ###
------------------------------------------------------------------------------------------------------------------
- Type: Player/Server
- Script: CongratsOnLevel
- Config: Yes
    - Enable Module
    - Enable Module Announce
    - Set Items/Gold/Buffs Given At Each Level
- SQL: No
### Version ###
------------------------------------------------------------------------------------------------------------------
- v2017.08.06 - Release
- v2017.09.30 - Fix Level Display Bug. Update Strings.
### Credits ###
------------------------------------------------------------------------------------------------------------------
- [LordPsyan](https://bitbucket.org/lordpsyan/lordpsyan-patches)
- [Blizzard Entertainment](http://blizzard.com)
- [TrinityCore](https://github.com/TrinityCore/TrinityCore/blob/3.3.5/THANKS)
- [SunwellCore](http://www.azerothcore.org/pages/sunwell.pl/)
- [AzerothCore](https://github.com/AzerothCore/azerothcore-wotlk/graphs/contributors)
- [AzerothCore Discord](https://discord.gg/gkt4y2x)
- [EMUDevs](https://youtube.com/user/EmuDevs)
- [AC-Web](http://ac-web.org/)
- [ModCraft.io](http://modcraft.io/)
- [OwnedCore](http://ownedcore.com/)
- [OregonCore](https://wiki.oregon-core.net/)
- [Wowhead.com](http://wowhead.com)
- [AoWoW](https://wotlk.evowow.com/)
### License ###
------------------------------------------------------------------------------------------------------------------
- This code and content is released under the [GNU AGPL v3](https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3).
*/

#include "Define.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Pet.h"
#include "Player.h"
#include "ScriptPCH.h"
#include "ScriptedGossip.h"
#include "GossipDef.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Chat.h"
#include "Config.h"

class CongratsOnLevel : public PlayerScript
{

public:
    CongratsOnLevel() : PlayerScript("CongratsOnLevel") { }

    // Announce Module
    void OnLogin(Player* player, bool firstLogin)
    {
        if (sConfigMgr->GetBoolDefault("Congrats.Enable", true))
        {
            if (firstLogin) {
                if (sConfigMgr->GetBoolDefault("Congrats.Announce", true))
                {
                    ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00CongratsOnLevel |rmodule.");
                }
            }
        }
    }

    // Level Up Rewards
    void OnLevelChanged(Player* player, uint8 oldLevel)
    {
        // If enabled...
        if (sConfigMgr->GetBoolDefault("Congrats.Enable", true)) {

            std::string level;
            uint32 money, item1, item2, spell;

            switch (++oldLevel)
            {

            case 10:
            {
                // Level 10
                const uint32 L101 = sConfigMgr->GetIntDefault("Congrats.L101", NULL);
                const uint32 L102 = sConfigMgr->GetIntDefault("Congrats.L102", NULL);
                const uint32 L10M = sConfigMgr->GetIntDefault("Congrats.L10M", NULL);
                const uint32 L10S = sConfigMgr->GetIntDefault("Congrats.L10S", NULL);

                level = "10";
                item1 = L101;
                item2 = L102;
                money = L10M;
                spell = L10S;
                break;
            }

            case 20:
            {
                // Level 20
                const uint32 L201 = sConfigMgr->GetIntDefault("Congrats.L201", NULL);
                const uint32 L202 = sConfigMgr->GetIntDefault("Congrats.L202", NULL);
                const uint32 L20M = sConfigMgr->GetIntDefault("Congrats.L20M", NULL);
                const uint32 L20S = sConfigMgr->GetIntDefault("Congrats.L20S", NULL);

                level = "20";
                item1 = L201;
                item2 = L202;
                money = L20M;
                spell = L20S;
                break;
            }

            case 30:
            {
                // Level 30
                const uint32 L301 = sConfigMgr->GetIntDefault("Congrats.L301", NULL);
                const uint32 L302 = sConfigMgr->GetIntDefault("Congrats.L302", NULL);
                const uint32 L30M = sConfigMgr->GetIntDefault("Congrats.L30M", NULL);
                const uint32 L30S = sConfigMgr->GetIntDefault("Congrats.L30S", NULL);

                level = "30";
                item1 = L301;
                item2 = L302;
                money = L30M;
                spell = L30S;
                break;
            }

            case 40:
            {
                // Level 40
                const uint32 L401 = sConfigMgr->GetIntDefault("Congrats.L401", NULL);
                const uint32 L402 = sConfigMgr->GetIntDefault("Congrats.L402", NULL);
                const uint32 L40M = sConfigMgr->GetIntDefault("Congrats.L40M", NULL);
                const uint32 L40S = sConfigMgr->GetIntDefault("Congrats.L40S", NULL);

                level = "40";
                item1 = L401;
                item2 = L402;
                money = L40M;
                spell = L40S;
                break;
            }

            case 50:
            {
                // Level 50
                const uint32 L501 = sConfigMgr->GetIntDefault("Congrats.L501", NULL);
                const uint32 L502 = sConfigMgr->GetIntDefault("Congrats.L502", NULL);
                const uint32 L50M = sConfigMgr->GetIntDefault("Congrats.L50M", NULL);
                const uint32 L50S = sConfigMgr->GetIntDefault("Congrats.L50S", NULL);

                level = "50";
                item1 = L501;
                item2 = L502;
                money = L50M;
                spell = L50S;
                break;
            }

            case 60:
            {
                // Level 60
                const uint32 L601 = sConfigMgr->GetIntDefault("Congrats.L601", NULL);
                const uint32 L602 = sConfigMgr->GetIntDefault("Congrats.L602", NULL);
                const uint32 L60M = sConfigMgr->GetIntDefault("Congrats.L60M", NULL);
                const uint32 L60S = sConfigMgr->GetIntDefault("Congrats.L60S", NULL);

                level = "60";
                item1 = L601;
                item2 = L602;
                money = L60M;
                spell = L60S;
                break;
            }

            case 70:
            {
                // Level 70
                const uint32 L701 = sConfigMgr->GetIntDefault("Congrats.L701", NULL);
                const uint32 L702 = sConfigMgr->GetIntDefault("Congrats.L702", NULL);
                const uint32 L70M = sConfigMgr->GetIntDefault("Congrats.L70M", NULL);
                const uint32 L70S = sConfigMgr->GetIntDefault("Congrats.L70S", NULL);

                level = "70";
                item1 = L701;
                item2 = L702;
                money = L70M;
                spell = L70S;
                break;
            }

            case 80:
            {
                // Level 80
                const uint32 L801 = sConfigMgr->GetIntDefault("Congrats.L801", NULL);
                const uint32 L802 = sConfigMgr->GetIntDefault("Congrats.L802", NULL);
                const uint32 L80M = sConfigMgr->GetIntDefault("Congrats.L80M", NULL);
                const uint32 L80S = sConfigMgr->GetIntDefault("Congrats.L80S", NULL);

                level = "80";
                item1 = L801;
                item2 = L802;
                money = L80M;
                spell = L80S;
                break;
            }

            default:
            {
                // Issue a server notification for the player on level up.
                std::ostringstream ss;
                ss << "|cffFFFFFF[ |cffFF0000C|cffFFA500O|cffFFFF00N|cff00FF00G|cff00FFFFR|cff6A5ACDA|cffFF00FFT|cff98FB98S|cffFF0000! |cffFFFFFF] : |cff4CFF00 " << player->GetName() << " |cffFFFFFFhas reached |cff4CFF00Level " << std::to_string(player->GetLevel()) << "|cffFFFFFF!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
                break;
            }
            
            return;
            }

            // If level is defined, they hit a reward level.
            if (!level.empty())
            {
                // Issue a server notification for the player on level up.
                std::ostringstream ss;
                ss << "|cffFFFFFF[ |cffFF0000C|cffFFA500O|cffFFFF00N|cff00FF00G|cff00FFFFR|cff6A5ACDA|cffFF00FFT|cff98FB98S|cffFF0000! |cffFFFFFF] : |cff4CFF00 " << player->GetName() << " |cffFFFFFFhas reached |cff4CFF00Level " << level << "|cffFFFFFF!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());

                // Give the items to the player
                player->AddItem(item1, 1);				// Defined Item 1
                player->AddItem(item2, 1);				// Defined Item 2

                // Give gold to the player
                player->ModifyMoney(money*GOLD);		// Defined Gold

                // Buff the player
                player->CastSpell(player, spell);		// Defined Spell

                // Issue a raid warning to the player
                std::ostringstream ss2;
                ss2 << "Congrats on Level " << level << " " << player->GetName() << "! You've been awarded " << money << " gold and a few treasures!";
                player->GetSession()->SendNotification(ss2.str().c_str());

                return;
            }
        }
    }
};

void AddSC_AddCongratsOnLevelScripts()
{
    new CongratsOnLevel();
}
