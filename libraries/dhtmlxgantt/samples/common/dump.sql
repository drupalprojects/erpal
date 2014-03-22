/*
MySQL Data Transfer
Source Host: localhost
Source Database: sampledb
Target Host: localhost
Target Database: sampledb
Date: 07-Aug-13 10:50:54
*/

SET FOREIGN_KEY_CHECKS=0;
-- ----------------------------
-- Table structure for gantt_links
-- ----------------------------
DROP TABLE IF EXISTS `gantt_links`;
CREATE TABLE `gantt_links` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `source` int(11) NOT NULL,
  `target` int(11) NOT NULL,
  `type` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Table structure for gantt_tasks
-- ----------------------------
DROP TABLE IF EXISTS `gantt_tasks`;
CREATE TABLE `gantt_tasks` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `text` varchar(255) NOT NULL,
  `start_date` datetime NOT NULL,
  `duration` int(11) NOT NULL,
  `progress` float NOT NULL,
  `order` double NOT NULL,
  `parent` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records 
-- ----------------------------
INSERT INTO `gantt_links` VALUES ('1', '1', '2', '0');
INSERT INTO `gantt_links` VALUES ('2', '1', '3', '0');
INSERT INTO `gantt_links` VALUES ('3', '1', '4', '0');
INSERT INTO `gantt_links` VALUES ('4', '2', '6', '0');
INSERT INTO `gantt_tasks` VALUES ('1', 'Project #1', '2013-04-01 00:00:00', '5', '0.8', '20', '0');
INSERT INTO `gantt_tasks` VALUES ('2', 'Task #1', '2013-04-06 00:00:00', '4', '0.5', '10', '1');
INSERT INTO `gantt_tasks` VALUES ('3', 'Task #2', '2013-04-05 00:00:00', '6', '0.7', '20', '1');
INSERT INTO `gantt_tasks` VALUES ('4', 'Task #3', '2013-04-07 00:00:00', '2', '0', '30', '1');
INSERT INTO `gantt_tasks` VALUES ('5', 'Task #1.1', '2013-04-05 00:00:00', '5', '0.34', '10', '2');
INSERT INTO `gantt_tasks` VALUES ('6', 'Task #1.2', '2013-04-11 13:22:17', '4', '0.491477', '20', '2');
INSERT INTO `gantt_tasks` VALUES ('7', 'Task #2.1', '2013-04-07 00:00:00', '5', '0.2', '10', '3');
INSERT INTO `gantt_tasks` VALUES ('8', 'Task #2.2', '2013-04-06 00:00:00', '4', '0.9', '20', '3');
INSERT INTO `gantt_tasks` VALUES ('9', 'Task #3.1', '2013-04-06 00:00:00', '5', '1', '10', '4');
INSERT INTO `gantt_tasks` VALUES ('10', 'Task #3.2', '2013-04-06 00:00:00', '3', '0', '20', '4');
INSERT INTO `gantt_tasks` VALUES ('11', 'Task #3.3', '2013-04-06 00:00:00', '4', '0.33', '30', '4');
INSERT INTO `gantt_tasks` VALUES ('12', 'Project #2', '2013-04-02 08:34:17', '18', '0', '10', '0');
INSERT INTO `gantt_tasks` VALUES ('13', 'Task #1', '2013-04-02 08:13:42', '10', '0.2', '15', '12');
INSERT INTO `gantt_tasks` VALUES ('14', 'Task #2', '2013-04-04 00:00:00', '4', '0.9', '20', '12');
INSERT INTO `gantt_tasks` VALUES ('15', 'Task #3', '2013-04-05 00:00:00', '3', '0.6', '30', '12');
INSERT INTO `gantt_tasks` VALUES ('16', 'Task #4', '2013-04-01 00:00:00', '3', '0.214286', '40', '12');
INSERT INTO `gantt_tasks` VALUES ('17', 'Task #5', '2013-04-06 00:00:00', '6', '0.5', '50', '12');
INSERT INTO `gantt_tasks` VALUES ('18', 'Task #2.1', '2013-04-05 00:00:00', '5', '0.3', '39.999999994179234', '14');
INSERT INTO `gantt_tasks` VALUES ('19', 'Task #2.2', '2013-04-05 00:00:00', '6', '0.6', '29.999999995343387', '14');
INSERT INTO `gantt_tasks` VALUES ('20', 'Task #2.3', '2013-04-05 00:00:00', '4', '0.512605', '39.99999999534339', '14');
INSERT INTO `gantt_tasks` VALUES ('21', 'Task #2.4', '2013-04-05 00:00:00', '6', '0.7', '39.99999999301508', '14');
INSERT INTO `gantt_tasks` VALUES ('22', 'Task #4.1', '2013-04-05 00:00:00', '7', '1', '10', '16');
INSERT INTO `gantt_tasks` VALUES ('23', 'Task #4.2', '2013-04-05 00:00:00', '5', '1', '20', '16');
INSERT INTO `gantt_tasks` VALUES ('24', 'Task #4.3', '2013-04-05 00:00:00', '5', '0', '30', '16');
