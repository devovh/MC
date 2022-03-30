--Login 2 Characters on GM Account - Faction Alliance, Horde and /join world. Remember this action on fresh startup server.
--Since the player will not have a moderator when performing this operation, you can block access to the server and grant access only at the GM level to enter the server and at this point log in to these two characters after different factions. 
--Yes, you can prevent the player from intercepting the chat. 
--At a later date, I may find a solution for this in the script that will automatically prevent this problem that needs to be done manually at the moment.
INSERT INTO `channels`(`name`,`team`,`announce`,`ownership`,`password`,`bannedList`,`lastUsed`) VALUES
('world',67,0,0,'',NULL,0), 
('world',469,0,0,'',NULL,0);
