--Profession NPC

insert  into `creature_template`(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`faction`,`npcflag`,`speed_walk`,`speed_run`,`scale`,`rank`,`dmgschool`,`BaseAttackTime`,`RangeAttackTime`,`BaseVariance`,`RangeVariance`,`unit_class`,`unit_flags`,`unit_flags2`,`dynamicflags`,`family`,`type`,`type_flags`,`lootid`,`pickpocketloot`,`skinloot`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`HoverHeight`,`HealthModifier`,`ManaModifier`,`ArmorModifier`,`DamageModifier`,`ExperienceModifier`,`RacialLeader`,`movementId`,`RegenHealth`,`mechanic_immune_mask`,`spell_school_immune_mask`,`flags_extra`,`ScriptName`,`VerifiedBuild`) values 
(190019,0,0,0,0,0,31833,0,0,0,'Kaylub','|cff00ccffProfessions NPC|r','Speak',0,80,80,2,35,1,1,1.14286,1,0,0,2000,2000,1,1,1,0,2048,0,0,7,0,0,0,0,0,0,0,0,'SmartAI',0,1,1,1,1,1,1,0,0,1,0,0,0,'NPC_Profession',0);

-- Spawn

insert  into `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) values 
(214027,190019,1,0,0,1,1,0,0,16215.7,16243.3,10.7358,0.369863,300,0,0,67,0,0,0,0,0,'',0),
(214030,190000,1,0,0,1,1,0,0,16233.9,16243.7,15.8666,2.63575,300,0,0,67,0,0,0,0,0,'',0),
(214031,190019,0,0,0,1,1,0,0,-8843.91,618.659,93.5453,5.92271,300,0,0,12600,0,0,0,0,0,'',0),
(214032,190019,1,0,0,1,1,0,0,9892.76,2438.34,1315.89,2.64367,300,0,0,12600,0,0,0,0,0,'',0),
(214033,190019,0,0,0,1,1,0,0,-4901.67,-920.221,501.645,5.21688,300,0,0,12600,0,0,0,0,0,'',0),
(214034,190019,530,0,0,1,1,0,0,-3905.11,-11632.7,-138.012,1.42455,300,0,0,12600,0,0,0,0,0,'',0),
(214035,190019,1,0,0,1,1,0,0,1595.05,-4406.53,6.96853,1.88837,300,0,0,12600,0,0,0,0,0,'',0),
(214036,190019,1,0,0,1,1,0,0,-1269.9,87.8146,128.225,3.86651,300,0,0,12600,0,0,0,0,0,'',0),
(214037,190019,0,0,0,1,1,0,0,1587.04,201.087,-43.1038,1.41537,300,0,0,12600,0,0,0,0,0,'',0),
(214038,190019,530,0,0,1,1,0,0,9715.47,-7452.33,13.5806,1.70503,300,0,0,12600,0,0,0,0,0,'',0),
(214039,190019,571,0,0,1,1,0,0,5796.05,487.74,657.578,5.44251,300,0,0,12600,0,0,0,0,0,'',0),
(214040,190019,530,0,0,1,1,0,0,-1878.7,5444.63,-12.4277,2.32697,300,0,0,12600,0,0,0,0,0,'',0);