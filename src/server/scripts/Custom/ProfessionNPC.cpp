#include "WorldSession.h"
#include "Player.h"
#include "DatabaseEnv.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Chat.h"
#include "RBAC.h"
#include "WorldSession.h"
#include "World.h"
#include "Language.h"
#include <DataStores/DBCStores.cpp>
#define DEFAULT_MESSAGE 907
class NPC_Profession : public CreatureScript
{
public:
    NPC_Profession() : CreatureScript("NPC_Profession") {}
    struct NPC_ProfessionAI : public ScriptedAI
    {
        NPC_ProfessionAI(Creature* creature) : ScriptedAI(creature) { }

        bool PlayerAlreadyHasTwoProfessions(Player* player)
        {
            uint32 skillCount = 0;

            if (player->HasSkill(SKILL_MINING))
                skillCount++;
            if (player->HasSkill(SKILL_SKINNING))
                skillCount++;
            if (player->HasSkill(SKILL_HERBALISM))
                skillCount++;

            if (skillCount >= 3)
                return true;

            for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
            {
                SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(i);
                if (!SkillInfo)
                    continue;

                if (SkillInfo->CategoryID == SKILL_CATEGORY_SECONDARY)
                    continue;

                if ((SkillInfo->CategoryID != SKILL_CATEGORY_PROFESSION) || !SkillInfo->CanLink)
                    continue;

                const uint32 skillID = SkillInfo->ID;
                if (player->HasSkill(skillID))
                    skillCount++;

                if (skillCount >= 2)
                    return true;
            }
            return false;
        }

        bool LearnAllRecipesInProfession(Player* player, SkillType skill)
        {
            //;
            char* skill_name;

            SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
            //  skill_name = SkillInfo->Name[handler.GetSessionDbcLocale()];

            if (!SkillInfo)

                return false;
            // sLog->outError(LOG_FILTER_SERVER_LOADING, "Profession NPC: received non-valid skill ID (LearnAllRecipesInProfession)");


            LearnSkillRecipesHelper(player, SkillInfo->ID);

            player->SetSkill(SkillInfo->ID, player->GetSkillStep(SkillInfo->ID), 450, 450);
            ChatHandler(player->GetSession()).PSendSysMessage("Your skill done");

            return true;
        }

        void LearnSkillRecipesHelper(Player* player, uint32 skill_id)
        {
            uint32 classmask = player->GetClassMask();

            for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
            {
                SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
                if (!skillLine)
                    continue;

                // wrong skill
                if (skillLine->SkillLine != skill_id)
                    continue;

                // not high rank
                if (skillLine->SupercededBySpell)
                    continue;

                // skip racial skills
                if (skillLine->RaceMask != 0)
                    continue;

                // skip wrong class skills
                if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
                    continue;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell);
                if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                    continue;

                player->LearnSpell(skillLine->Spell, false);
            }
        }

        bool IsSecondarySkill(SkillType skill)
        {
            return skill == SKILL_COOKING || skill == SKILL_FIRST_AID || skill == SKILL_FISHING;
        }

        void CompleteLearnProfession(Player* player, Creature* creature, SkillType skill)
        {
            if (PlayerAlreadyHasTwoProfessions(player) && !IsSecondarySkill(skill))
                ChatHandler(player->GetSession()).PSendSysMessage("You already know two professions!");
            else
            {
                if (!LearnAllRecipesInProfession(player, skill))
                    ChatHandler(player->GetSession()).PSendSysMessage("Internal error occured!");
            }
        }

        bool OnGossipHello(Player* player)
        {
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\trade_alchemy:30|t Alchemy.", GOSSIP_SENDER_MAIN, 1);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\INV_Ingot_05:30|t Blacksmithing.", GOSSIP_SENDER_MAIN, 2);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\INV_Misc_LeatherScrap_02:30|t Leatherworking.", GOSSIP_SENDER_MAIN, 3);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\INV_Fabric_Felcloth_Ebon:30|t Tailoring.", GOSSIP_SENDER_MAIN, 4);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\inv_misc_wrench_01:30|t Engineering.", GOSSIP_SENDER_MAIN, 5);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\trade_engraving:30|t Enchanting.", GOSSIP_SENDER_MAIN, 6);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\inv_misc_gem_01:30|t Jewelcrafting.", GOSSIP_SENDER_MAIN, 7);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\INV_Scroll_08:30|t Inscription.", GOSSIP_SENDER_MAIN, 8);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\INV_Misc_Herb_07:30|t Herbalism.", GOSSIP_SENDER_MAIN, 9);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\inv_misc_pelt_wolf_01:30|t Skinning.", GOSSIP_SENDER_MAIN, 10);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\trade_mining:30|t Mining.", GOSSIP_SENDER_MAIN, 11);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\inv_misc_food_15:30|t Cooking.", GOSSIP_SENDER_MAIN, 12);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\spell_holy_sealofsacrifice:30|t First Aid.", GOSSIP_SENDER_MAIN, 13);
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "|TInterface\\icons\\trade_fishing:30|t Fishing.", GOSSIP_SENDER_MAIN, 14);
            AddGossipItemFor(player, GOSSIP_ICON_TALK, "|TInterface/ICONS/Thrown_1H_Harpoon_D_01Blue:30|t Nevermind!", GOSSIP_SENDER_MAIN, 15);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
            return true;
        }
        bool OnGossipSelect(Player* player, uint32 uiSender, uint32 uiAction)  override

        {
            uint32 senders = player->PlayerTalkClass->GetGossipOptionSender(uiSender);
            uint32 actions = player->PlayerTalkClass->GetGossipOptionAction(uiAction);
            ClearGossipMenuFor(player);

            switch (actions)
            {
            case 1:
                if (player->HasSkill(SKILL_ALCHEMY))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }

                CompleteLearnProfession(player, me, SKILL_ALCHEMY);

                ClearGossipMenuFor(player);
                break;
            case 2:
                if (player->HasSkill(SKILL_BLACKSMITHING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_BLACKSMITHING);

                ClearGossipMenuFor(player);
                break;
            case 3:
                if (player->HasSkill(SKILL_LEATHERWORKING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_LEATHERWORKING);

                ClearGossipMenuFor(player);
                break;
            case 4:
                if (player->HasSkill(SKILL_TAILORING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_TAILORING);

                ClearGossipMenuFor(player);
                break;
            case 5:
                if (player->HasSkill(SKILL_ENGINEERING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_ENGINEERING);

                ClearGossipMenuFor(player);
                break;
            case 6:
                if (player->HasSkill(SKILL_ENCHANTING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_ENCHANTING);

                ClearGossipMenuFor(player);
                break;
            case 7:
                if (player->HasSkill(SKILL_JEWELCRAFTING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_JEWELCRAFTING);

                ClearGossipMenuFor(player);
                break;
            case 8:
                if (player->HasSkill(SKILL_INSCRIPTION))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_INSCRIPTION);

                ClearGossipMenuFor(player);
                break;
            case 9:
                if (player->HasSkill(SKILL_HERBALISM))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }

                CompleteLearnProfession(player, me, SKILL_HERBALISM);
                ClearGossipMenuFor(player);
                break;
            case 10:
                if (player->HasSkill(SKILL_SKINNING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }

                CompleteLearnProfession(player, me, SKILL_SKINNING);
                ClearGossipMenuFor(player);
                break;
            case 11:
                if (player->HasSkill(SKILL_MINING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }

                CompleteLearnProfession(player, me, SKILL_MINING);
                ClearGossipMenuFor(player);
                break;
            case 12:
                if (player->HasSkill(SKILL_COOKING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }

                CompleteLearnProfession(player, me, SKILL_COOKING);
                ClearGossipMenuFor(player);
                break;
            case 13:
                if (player->HasSkill(SKILL_FIRST_AID))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_FIRST_AID);
                ClearGossipMenuFor(player);
                break;
            case 14:
                if (player->HasSkill(SKILL_FISHING))
                {
                    ClearGossipMenuFor(player);
                    return false;
                }
                CompleteLearnProfession(player, me, SKILL_FISHING);
                ClearGossipMenuFor(player);
                break;
            case 15:
                ClearGossipMenuFor(player);
                break;
            }



            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new NPC_ProfessionAI(creature);
    }
};

void AddSC_NPC_Profession()
{
    new NPC_Profession();
}
