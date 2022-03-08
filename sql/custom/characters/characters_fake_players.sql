/*
SQLyog Enterprise - MySQL GUI v8.18
MySQL - 5.1.66-0+squeeze1 : Database - lithathrad_characters
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `characters_fake` */

DROP TABLE IF EXISTS `characters_fake`;

CREATE TABLE `characters_fake` (
  `name` varchar(36) NOT NULL,
  `race` mediumint(3) NOT NULL DEFAULT '0',
  `class` mediumint(3) NOT NULL DEFAULT '0',
  `level` mediumint(3) NOT NULL DEFAULT '0',
  `zone` mediumint(9) NOT NULL DEFAULT '0',
  `gender` mediumint(3) NOT NULL DEFAULT '0',
  `online` mediumint(3) NOT NULL DEFAULT '0'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

/*Data for the table `characters_fake` */

INSERT INTO `characters_fake`(`name`,`race`,`class`,`level`,`zone`,`gender`,`online`) VALUE ('Drikish',10,8,80,22,0,2),('Sovelis',1,1,75,11,0,2),('Cuddles',10,2,80,37,0,2),('Epiasdv',8,4,80,1,0,2),('Mac',5,4,80,44,0,2),('Tiesto',8,6,80,22,0,2),('Ihavfacebook',11,7,80,22,1,2),('Mimik',10,4,80,24,0,2),('Deadmau',5,4,80,36,0,2),('Smoosh',8,1,80,29,0,2),('Shadowcrest',4,4,80,24,1,2),('Lolol',4,5,75,30,1,2),('Prox',11,1,80,28,1,2),('Rovip',10,4,80,22,0,2),('Ryan',10,8,80,17,0,2),('Holysmite',1,2,80,24,0,2),('Airagon',10,2,80,36,0,2),('Fracture',5,1,80,4,0,2),('Supershen',10,2,80,14,1,2),('Jana',2,4,75,41,0,2),('Gamm',2,1,75,35,0,2),('Emoarchie',10,8,80,2,0,2),('Melia',10,2,75,4,1,2),('Balu',6,11,75,22,0,2),('Jabari',2,1,75,5,0,2),('Sinan',10,2,75,6,0,2),('Shisha',10,4,75,22,1,2),('Killbill',1,4,75,8,0,2),('Gaby',4,11,75,12,1,2),('Fallen',4,4,75,37,0,2),('Druidita',6,11,75,47,0,2),('Pigolo',6,11,75,22,0,2),('Saga',10,2,75,22,0,2),('Deadmask',10,2,75,41,0,2),('Assasincz',4,4,75,41,0,2),('Petracz',1,4,75,22,1,2),('Aleks',10,2,75,20,0,2),('Cazadormen',4,4,75,14,1,2),('Kireth',1,2,75,9,1,2),('Liesma',1,1,75,5,1,2),('Tyller',1,1,75,46,0,2),('Astrabutaz',1,2,75,22,0,2),('Carlita',7,8,75,26,1,2),('beanie',10,2,80,40,0,2),('Nergal',10,3,75,22,0,2),('Smikis',10,5,75,22,0,2),('Peperoma',11,2,75,30,0,2),('May',1,2,75,32,1,2),('Keyadis',8,7,75,47,0,2),('Preatorian',10,2,75,29,0,2),('Mitza',1,9,75,1,0,2),('Keedor',10,2,75,21,0,2),('Kekw',4,3,75,1,1,2),('Wark',1,2,75,42,0,2),('Barrabus',10,2,75,6,0,2),('Malodetehepy',4,11,75,1,0,2),('Dranati',10,2,75,40,0,2),('Sorin',2,1,75,36,0,2),('Resan',4,4,75,18,0,2),('Silverhilt',1,1,75,31,1,2),('Chirica',10,2,75,2,0,2),('Trias',10,8,75,16,0,2),('Prdo',5,1,75,22,0,2),('Guten',8,7,75,36,0,2),('Sonsia',4,3,75,48,1,2),('Smikiss',10,4,75,37,0,2),('Ledy',4,1,75,34,1,2),('Rymar',5,4,75,9,0,2),('Rokass',5,1,75,38,0,2),('Waisha',10,3,75,11,1,2),('Xenon',4,1,75,16,0,2),('Palanoski',1,2,75,6,0,2),('Helona',6,11,75,47,1,2),('Skalons',2,1,75,14,0,2),('Zazlock',5,9,75,31,0,2),('Zazk',6,7,75,20,0,2),('Ezekiel',10,9,75,12,0,2),('Deiv',10,8,75,1,0,2),('Crashwar',5,1,75,16,0,2),('Bandaid',5,5,75,28,0,2),('Hunterherbie',4,3,75,3,0,2),('Cheesebeard',3,1,90,4,0,2),('Phin',7,8,75,3,0,2),('Prig',10,5,75,48,0,2),('Eraevel',10,5,75,28,1,2),('Bourne',5,4,75,47,0,2),('Twoogi',5,8,75,48,0,2),('Devon',5,4,76,6,0,2),('Ledystar',1,2,75,29,1,2),('Frostie',10,8,75,25,1,2),('Kie',5,4,80,38,0,2),('Reios',1,2,75,16,0,2),('Zero',4,4,75,30,0,2),('Wuk',2,1,75,1,0,2),('Sylvaediir',4,3,75,21,0,2),('Kansetsu',11,2,75,10,0,2),('Makura',11,2,75,44,1,2),('Demonia',11,2,75,17,1,2),('Stonebull',6,11,75,50,0,2),('Marianus',10,2,75,50,0,2);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;