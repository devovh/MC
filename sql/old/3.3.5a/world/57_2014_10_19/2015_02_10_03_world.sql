-- Fireguard Destroyer SAI
SET @ENTRY := 8911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,30,9000,11000,11,15243,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fireguard Destroyer - Within 0-30 Range - Cast 'Fireball Volley' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,5000,8000,11,16788,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fireguard Destroyer - In Combat - Cast 'Fireball'");
