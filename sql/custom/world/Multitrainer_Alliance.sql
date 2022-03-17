SET @MENU_ID = (SELECT max(menuid)+1 FROM gossip_menu_option);

INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(190011, 5080, "Rakka", "Multi Trainer", NULL, @MENU_ID, 10, 10, 0, 35, 17, 1, 1.14286, 1, 0, 0, 1500, 0, 1, 512, 2048, 0, 0, 7, 138412032, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 0, 0, 1, 0, 2, '');

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, 0, 3, 'Druid Trainer', 5, 16, 5504, 0, 0, 0, ''),
(@MENU_ID, 1, 3, 'Hunter Trainer', 5, 16, 5515, 0, 0, 0, ''),
(@MENU_ID, 2, 3, 'Mage Trainer', 5, 16, 331, 0, 0, 0, ''),
(@MENU_ID, 3, 3, 'Paladin Trainer', 5, 16, 928, 0, 0, 0, ''),
(@MENU_ID, 4, 3, 'Priest Trainer', 5, 16, 376, 0, 0, 0, ''),
(@MENU_ID, 5, 3, 'Rogue Trainer', 5, 16, 918, 0, 0, 0, ''),
(@MENU_ID, 6, 3, 'Shaman Trainer', 5, 16, 20407, 0, 0, 0, ''),
(@MENU_ID, 7, 3, 'Warlock Trainer', 5, 16, 461, 0, 0, 0, ''),
(@MENU_ID, 8, 3, 'Warrior Trainer', 5, 16, 914, 0, 0, 0, ''),
(@MENU_ID, 9, 3, 'Death Knight Trainer', 5, 16, 28474, 0, 0, 0, ''),
(@MENU_ID, 10, 3, 'Darnassus Weapon Master', 5, 16, 11866, 0, 0, 0, ''),
(@MENU_ID, 11, 3, 'Stormwind Weapon Master', 5, 16, 11867, 0, 0, 0, ''),
(@MENU_ID, 12, 3, 'Ironforge Weapon Master', 5, 16, 11865, 0, 0, 0, ''),
(@MENU_ID, 13, 3, 'Riding Trainer', 5, 16, 31238, 0, 0, 0, '');