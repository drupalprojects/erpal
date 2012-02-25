/**
 * HTTP server module.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function Socket () {
	
	var self			 = this;	
	this.clientManager	 = require ('../data/clientmanager.js');
	this.netSocketServer = require('net').createServer(function(connection) {

		connection.on('connect', function() {
	
			   self.clientManager.saveSocketClientObject (
						connection.remoteAddress,
						connection
				);
				
				return;
		});
			
		connection.on('close', function() {
				
				self.clientManager.removeClientBySocketClientObject (connection);
				
				return;
		});
			
		connection.on('data', function(data) {
	 
				var event = JSON.parse(data.toString ());
				
				switch (event.eventID) {					
					case 'not available':
						self.clientManager.setStatus (connection, false);
						break;	
						
					case 'available':
						self.clientManager.setStatus (connection, true);
						break;	
				}
				
				return;
		});
		
	});

	return;
}

/*
 * Sends data to the client.
 * @param	string	ip		The IP address of the client.
 * @param 	string	data	The data string.
 * @return  boolen			TRUE on success.
 */
Socket.prototype.sendData = function (postData) {

	var socketClientObject = this.clientManager.getSocketClientByPhoneNumber(
			postData['receiverPhoneNumber']
	);
	
	if (socketClientObject == null) {
		return false;
	}
	
	socketClientObject.write (postData['caller_data']);

	return true;
};
   
/*
 * Starts the socket server.
 * @param integer	port	The number of the port the server shall listen.
 */
Socket.prototype.start = function (port) {
	
	this.netSocketServer.listen(port);
	
	return;
};

/*
 * Stops the socket server.
 */
Socket.prototype.stop = function () {
	
	this.netSocketServer.close ();
	
	return;
};

/*
 * Registers a clients phonenumbers.
 * It is just a proxy function for ClientManager.register.
 */
Socket.prototype.registerClientData = function (phonenumbers, ip) {
	
	this.clientManager.register (phonenumbers, ip);
	
	return;
};

// Module export.
module.exports = new Socket ();
