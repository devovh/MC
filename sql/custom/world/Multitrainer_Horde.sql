--
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(190012, 14429, "Destroyer", "Multi Trainer", NULL, 100001, 10, 10, 0, 35, 17, 1, 1.14286, 1, 0, 0, 1500, 0, 1, 512, 2048, 0, 0, 7, 138412032, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 0, 0, 1, 0, 2, '');

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(100001, 1, 3, 'Druid Trainer', 5, 16, 3034, 0, 0, 0, ''),
(100001, 2, 3, 'Hunter Trainer', 5, 16, 3352, 0, 0, 0, ''),
(100001, 3, 3, 'Mage Trainer', 5, 16, 5882, 0, 0, 0, ''),
(100001, 4, 3, 'Paladin Trainer', 5, 16, 23128, 0, 0, 0, ''),
(100001, 5, 3, 'Priest Trainer', 5, 16, 5994, 0, 0, 0, ''),
(100001, 6, 3, 'Rogue Trainer', 5, 16, 3401, 0, 0, 0, ''),
(100001, 7, 3, 'Shaman Trainer', 5, 16, 3344, 0, 0, 0, ''),
(100001, 8, 3, 'Warlock Trainer', 5, 16, 3324, 0, 0, 0, ''),
(100001, 9, 3, 'Warrior Trainer', 5, 16, 3353, 0, 0, 0, ''),
(100001, 10, 3, 'Death Knight Trainer', 5, 16, 28474, 0, 0, 0, ''),
(100001, 11, 3, 'Thunder Bluff Weapon Master', 5, 16, 11869, 0, 0, 0, ''),
(100001, 12, 3, 'Orgrimmar Weapon Master', 5, 16, 11868, 0, 0, 0, ''),
(100001, 13, 3, 'Undercity Weapon Master', 5, 16, 11870, 0, 0, 0, ''),
(100001, 14, 3, 'Riding Trainer', 5, 16, 31238, 0, 0, 0, ''),
(100001, 15, 3, 'Orgrimmar Portal Trainer', 5, 16, 5958, 0, 0, 0, ''),
(100001, 16, 3, 'Thunder Bluff Portal Trainer', 5, 16, 5957, 0, 0, 0, ''),
(100001, 17, 3, 'Undercity Portal Trainer', 5, 16, 2492, 0, 0, 0, ''),
(100001, 18, 3, 'Silvermoon Portal Trainer', 5, 16, 16654, 0, 0, 0, ''),
(100001, 19, 3, 'Shattrath Portal Trainer', 5, 16, 20791, 0, 0, 0, '');
