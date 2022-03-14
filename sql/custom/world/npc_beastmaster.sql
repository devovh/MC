-- USE world;

-- ######################################################--
--	BEASTMASTER - 601026
-- ######################################################--
-- SET
-- 190014 		:= 190014,
-- @Model 		:= 729, -- Shadowfang Moonwalker (White Worgen)
-- @Name 		:= "White Fang",
-- @Title 		:= "BeastMaster",
-- @Icon 		:= "Speak",
-- @GossipMenu := 0,
-- @MinLevel 	:= 80,
-- @MaxLevel 	:= 80,
-- @Faction 	:= 35,
-- @NPCFlag 	:= 4194433,
-- @Scale		:= 1.0,
-- @Rank		:= 0,
-- @Type 		:= 7,
-- @TypeFlags 	:= 0,
-- @FlagsExtra := 2,
-- @AIName		:= "SmartAI",
-- @Script 	:= "BeastMaster";

-- NPC
DELETE FROM creature_template WHERE entry = 190014;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `ManaModifier`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
('190014','0','0','0','0','0','729','0','0','0','White Fang','Beast Master','Speak','0','80','80','0','35','4194433','0.91','1.14286','1','0','0','2000','2000','1','1','1','0','2048','0','0','7','0','0','0','0','0','0','0','0','SmartAI','0','1','0.0125','1','1','1','1','0','0','1','0','0','2','BeastMaster','0');

-- NPC
-- DELETE FROM creature_template WHERE entry = 190014;
-- INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, faction, npcflag, speed_walk, speed_run, scale, rank, unit_class, unit_flags, type, type_flags, RegenHealth, flags_extra, AiName, ScriptName) VALUES
-- (190014, @Model, @Name, @Title, @Icon, @GossipMenu, @MinLevel, @MaxLevel, @Faction, @NPCFlag, 1, 1.14286, @Scale, @Rank, 1, 2, @Type, @TypeFlags, 1, @FlagsExtra, @AIName, @Script);

-- NPC EQUIPPED
DELETE FROM `creature_equip_template` WHERE `CreatureID`=190014 AND `ID`=1;
INSERT INTO `creature_equip_template` VALUES (190014, 1, 2196, 1906, 0, 18019); -- Haunch of Meat, Torch

-- NPC TEXT
DELETE FROM `npc_text` WHERE `ID`=190014;
INSERT INTO `npc_text` (`ID`, `text0_0`) VALUES (190014, 'Greetings $N. And when, on the still cold nights, he pointed his nose at a star and howled long and wolflike, it was his ancestors, dead and dust, pointing nose at star and howling down through the centuries and through him.');

-- NPC ITEMS
DELETE FROM npc_vendor WHERE entry = 190014;
INSERT INTO npc_vendor (entry, item) VALUES 
-- MEAT
(190014,35953),	-- (75) -- Mead Blasted Caribou 
(190014,33454),	-- (65) -- Salted Venison 
(190014,27854),	-- (55) -- Smoked Talbuk Venison
(190014,8952),	-- (45) -- Roasted Quail 
(190014,4599),	-- (35) -- Cured Ham Steak  
(190014,3771),	-- (25) -- Wild Hog Shank 
(190014,3770),	-- (15) -- Mutton Chop
(190014,2287),	-- (5)  -- Haunch of Meat
(190014,117),	-- (1)  -- Tough Jerky
-- FUNGUS
(190014,35947),	-- (75) -- Sparkling Frostcap
(190014,33452),	-- (65) -- Honey-Spiced Lichen 
(190014,27859),	-- (55) -- Zangar Caps
(190014,8948),	-- (45) -- Dried King Bolete
(190014,4608),	-- (35) -- Raw Black Truffle 
(190014,4607),	-- (25) -- Delicious Cave Mold
(190014,4606),	-- (15) -- Spongy Morel
(190014,4605),	-- (5)  -- Red-Speckled Mushroom 
(190014,4604),	-- (1)  -- Forest Mushroom Cap
-- BREAD
(190014,35950),	-- (75) -- Sweet Potato Bread
(190014,33449),	-- (65) -- Crusty Flatbread
(190014,27855),	-- (55) -- Mag'har Grainbread
(190014,8950),	-- (45) -- Homemade Cherry Pie
(190014,4601),	-- (35) -- Soft Banana Bread
(190014,4544),	-- (25) -- Mulgore Spice Bread
(190014,4542),	-- (15) -- Moist Cornbread
(190014,4541),	-- (5)  -- Freshly Baked Bread
(190014,4540),	-- (1)  -- Tough Hunk of Bread
-- FRUIT
(190014,35948),	-- (75) -- Savory Snowplum
(190014,35949),	-- (65) -- Tundra Berries
(190014,27856),	-- (55) -- Sklethyl Berries
(190014,8953),	-- (45) -- Deep Fried Plantains
(190014,4602),	-- (35) -- Moon Harvest Pumpkin
(190014,4539),	-- (25) -- Goldenbark Apple
(190014,4538),	-- (15) -- Snapvine Watermelon
(190014,4537),	-- (5)  -- Tel'Abim Banana
(190014,4536),	-- (1)  -- Shiny Red Apple
-- FISH
(190014,35951),	-- (75) -- Poached Emperor Salmon
(190014,33451),	-- (65) -- Filet of Icefin
(190014,27858),	-- (55) -- Sunspring Carp
(190014,8957),	-- (45) -- Spinefin Halibut
(190014,21552),	-- (35) -- Striped Yellowtail
(190014,4594),	-- (25) -- Rockscale Cod
(190014,4593),	-- (15) -- Bristle Whisker Catfish
(190014,4592),	-- (5)  -- Longjaw Mud Snapper
(190014,787),	-- (1)  -- Slitherskin Mackeral
-- CHEESE
(190014,35952),	-- (75) -- Briny Hardcheese
(190014,33443),	-- (65) -- Sour Goat Cheese
(190014,27857),	-- (55) -- Gradar Sharp
(190014,8932),	-- (45) -- Alterac Swiss
(190014,3927),	-- (35) -- Fine Aged Chedder
(190014,1707),	-- (25) -- Stormwind Brie
(190014,422),	-- (15) -- Dwarven Mild
(190014,414),	-- (5)  -- Dalaran Sharp
(190014,2070),	-- (1)  -- Darnassian Bleu
-- BUFF
(190014,33875),	-- Kibler's Bits
-- RARE
(190014,21024);	-- Chimaerok Tenderloin