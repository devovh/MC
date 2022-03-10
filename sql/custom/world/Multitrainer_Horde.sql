SET @MENU_ID = (SELECT max(menuid)+1 FROM gossip_menu_option);

INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(190012, 5080, "Rakka", "Multi Trainer", NULL, @MENU_ID, 10, 10, 0, 29, 17, 1, 1.14286, 1, 0, 0, 1500, 0, 1, 512, 2048, 8, 0, 7, 138412032, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 0, 0, 1, 0, 2, '');

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, 0, 3, 'Druid Trainer', 5, 16, 3034, 0, 0, 0, ''),
(@MENU_ID, 1, 3, 'Hunter Trainer', 5, 16, 3352, 0, 0, 0, ''),
(@MENU_ID, 2, 3, 'Mage Trainer', 5, 16, 5882, 0, 0, 0, ''),
(@MENU_ID, 3, 3, 'Paladin Trainer', 5, 16, 23128, 0, 0, 0, ''),
(@MENU_ID, 4, 3, 'Priest Trainer', 5, 16, 5994, 0, 0, 0, ''),
(@MENU_ID, 5, 3, 'Rogue Trainer', 5, 16, 3401, 0, 0, 0, ''),
(@MENU_ID, 6, 3, 'Shaman Trainer', 5, 16, 3344, 0, 0, 0, ''),
(@MENU_ID, 7, 3, 'Warlock Trainer', 5, 16, 3324, 0, 0, 0, ''),
(@MENU_ID, 8, 3, 'Warrior Trainer', 5, 16, 3353, 0, 0, 0, ''),
(@MENU_ID, 9, 3, 'Death Knight Trainer', 5, 16, 28474, 0, 0, 0, '');