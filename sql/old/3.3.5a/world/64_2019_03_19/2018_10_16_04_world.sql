-- 
DELETE FROM `creature` WHERE `guid` IN (91696, 91697, 91698, 91699, 91700, 91701, 91702,91704,91705,91706,91707,91772,91773,91774,91775,91776,91777,91778,91779,91794);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(91696, 9701, 229, 1, 1, 0, 0, -112.9, -323.074, 64.3181, 5.41052, 7200, 5, 1),
(91697, 9701, 229, 1, 1, 0, 0, -112.332, -331.009, 63.2146, 3.07178, 7200, 5, 1),
(91698, 9701, 229, 1, 1, 0, 0, -109.429, -324.918, 64.3253, 0.03491, 7200, 5, 1),
(91699, 9701, 229, 1, 1, 0, 0, -80.8737, -298.923, 61.8178, 5.18363, 7200, 5, 1),
(91700, 9701, 229, 1, 1, 0, 0, -80.2467, -313.909, 59.7635, 0.45379, 7200, 5, 1),
(91701, 9701, 229, 1, 1, 0, 0, -77.2828, -324.738, 59.1126, 4.99164, 7200, 5, 1),
(91702, 10177, 229, 1, 1, 0, 0, -111.704, -348.742, 60.0788, 0.82031, 7200, 5, 1),
(91704, 10177, 229, 1, 1, 0, 0, -71.569, -358.213, 54.5978, 2.3911, 7200, 5, 1),
(91705, 10177, 229, 1, 1, 0, 0, -72.0317, -347.075, 54.8219, 1.36136, 7200, 5, 1),
(91706, 10177, 229, 1, 1, 0, 0, -66.8659, -352.762, 54.4785, 1.0821, 7200, 5, 1),
(91707, 10177, 229, 1, 1, 0, 0, -110.012, -356.647, 58.5433, 4.36332, 7200, 5, 1),
(91772, 10177, 229, 1, 1, 0, 0, -112.261, -336.356, 62.3371, 4.92183, 7200, 5, 1),
(91773, 10177, 229, 1, 1, 0, 0, -107.424, -351.94, 59.7058, 4.4855, 7200, 5, 1),
(91774, 10177, 229, 1, 1, 0, 0, -108.382, -341.04, 61.1785, 1.64061, 7200, 5, 1),
(91775, 10177, 229, 1, 1, 0, 0, -102.763, -349.062, 60.7782, 1.51844, 7200, 5, 1),
(91776, 10177, 229, 1, 1, 0, 0, -79.7917, -328.192, 58.547, 5.95157, 7200, 5, 1),
(91777, 10177, 229, 1, 1, 0, 0, -75.4103, -341.562, 55.3937, 4.90438, 7200, 5, 1),
(91778, 10177, 229, 1, 1, 0, 0, -68.8686, -343.093, 55.116, 1.81514, 7200, 5, 1),
(91779, 10177, 229, 1, 1, 0, 0, -73.5343, -331.947, 56.8824, 3.94444, 7200, 5, 1),
(91794, 10177, 229, 1, 1, 0, 0, -108.927, -364.601, 56.6248, 1.0472, 7200, 5, 1);
