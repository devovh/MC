--
SET @MENU_ID = (SELECT max(menuid)+1 FROM gossip_menu_option);

INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`) VALUES
(190018, 1298, "Herbert", "Miscellaneous", NULL, @MENU_ID, 10, 10, 0, 35, 129, 1, 1.14286, 1, 0, 0, 1500, 0, 1, 512, 2048, 0, 0, 7, 138412032, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 0, 0, 1, 0, 2, '');

INSERT INTO `gossip_menu_option` (`menuid`, `optionid`, `optionicon`, `optiontext`, `optiontype`, `optionnpcflag`, `actionmenuid`, `actionpoiid`, `boxcoded`, `boxmoney`, `boxtext`) VALUES
(@MENU_ID, 1, 6, 'Miscellaneous Items', 3, 128, 190111, 0, 0, 0, 'These goods are special, so pay up!'),
(@MENU_ID, 2, 6, 'Poisons - Rogue', 3, 128, 3334, 0, 0, 0, 'These goods are special, so pay up!'),
(@MENU_ID, 3, 6, 'Reagents', 3, 128, 1351, 0, 0, 0, 'These goods are special, so pay up!');

INSERT INTO `creature_template`(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`dmgschool`,`BaseAttackTime`,`RangeAttackTime`,`BaseVariance`,`RangeVariance`,`unit_class`,`unit_flags`,`unit_flags2`,`dynamicflags`,`family`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`HoverHeight`,`HealthModifier`,`ManaModifier`,`ArmorModifier`,`DamageModifier`,`ExperienceModifier`,`RacialLeader`,`movementId`,`RegenHealth`,`mechanic_immune_mask`,`spell_school_immune_mask`,`flags_extra`,`ScriptName`,`VerifiedBuild`) VALUES 
(190111,0,0,0,0,0,29851,0,0,0,'Miscellaneous Items','Vendor','',0,80,80,2,2123,128,1,1.14286,1,0,0,2000,2000,1,1,1,768,2048,0,0,7,0,0,0,0,0,0,0,0,'',0,1,1,1,1,1,1,0,0,1,0,0,66,'',12340);

INSERT INTO `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`VerifiedBuild`) VALUES
(190111,0,6265,0,0,0,0),
(190111,0,5175,0,0,0,0),
(190111,0,5176,0,0,0,0),
(190111,0,5177,0,0,0,0),
(190111,0,5178,0,0,0,0),
(190111,0,21215,0,0,0,0);