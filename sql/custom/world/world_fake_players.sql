DELETE FROM `trinity_string` WHERE `entry` IN (10100, 10101, 10102);

INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) values
('10100','Message: \"Do not disturb\".',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'РЎРѕРѕР±С‰РµРЅРёРµ: \"РќРµ Р±РµСЃРїРѕРєРѕРёС‚СЊ\".'),
('10101','Message: \"Player already in guild\".',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'РЎРѕРѕР±С‰РµРЅРёРµ: \"РќРµ Р±РµСЃРїРѕРєРѕРёС‚СЊ\".'),
('10102','Message: \"Player already in party\".',NULL,NULL,NULL,NULL,NULL,NULL,NULL,'РЎРѕРѕР±С‰РµРЅРёРµ: \"РќРµ Р±РµСЃРїРѕРєРѕРёС‚СЊ\".');