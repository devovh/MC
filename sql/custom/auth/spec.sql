--
INSERT INTO `rbac_permissions` (`id`, `name`) VALUES
('1000', 'spectate'),
('1001', 'spectate player'),
('1002', 'spectate view'),
('1003', 'spectate reset'),
('1004', 'spectate leave');

DELETE FROM `rbac_linked_permissions` WHERE `linkedId` IN ("1003","1004","1005","1006","1007");

INSERT INTO `rbac_linked_permissions` (`id`, `linkedId`) VALUES
('195','1000'),
('195','1001'),
('195','1002'),
('195','1003'),
('195','1004');