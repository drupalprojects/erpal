/**
 * HTTP server module.
 * 
 * @author 		Marc Sven Kleinböhl, Karsten Planz
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function Socket () {
	
	var self			 = this;	
	this.clientManager	 = require ('../data/clientmanager.js');

	return;
}

/*
 * Sends data to the client.
 * @param 	string	postData	The post data string.
 * @return  boolen				TRUE on success.
 */
Socket.prototype.sendData = function (postData) {

	var socketClientObject = this.clientManager.getSocketClientByPhoneNumber(
			postData['destination']
	);
  
	if (socketClientObject == null) {
		return false;
	}
	
	socketClientObject.emit('caller_data', { caller_data: postData['caller_data'] });

	return true;
};
   
/*
 * Starts the socket server.
 * @param integer	port	The number of the port the server shall listen.
 */
Socket.prototype.start = function (port) {
	
  var self = this;  
  // TODO: check why inserting variable port here throws error
  var io = require('socket.io').listen(3081);

  io.sockets.on('connection', function (socket) {
    var address = socket.handshake.address.address;
		console.log ('Client ' + address + ' connected.');

    self.clientManager.saveSocketClientObject (
      address,
      socket
    );

    socket.emit('status', { status : 'ok', ip : address });
  
    socket.on('connect', function() {
				return;
		});
			
		socket.on('disconnect', function() {
				var address = socket.handshake.address.address;
				console.log ('Client ' + address + ' disconnected.');			
				self.clientManager.removeClientBySocketClientObject (socket);
				
				return;
		});
			
		socket.on('action', function(data) {
      switch (data.name) {					
        case 'not available':
          self.clientManager.setStatus (socket, false);
          break;	
          
        case 'available':
          self.clientManager.setStatus (socket, true);
          break;	
      }
      
			return;
		});
  });

  
	return;
};

/*
 * Stops the socket server.
 */
Socket.prototype.stop = function () {
	
  // TODO: check if that works
	// this.io.server.close();
  
	return;
};

/*
 * Registers a clients phonenumbers.
 * It is just a proxy function for ClientManager.register.
 */
Socket.prototype.registerClientData = function (postData) {
	console.log(postData.phone_numbers);
	this.clientManager.register (postData.phone_numbers, postData.ip);
	
	return;
};

// Module export.
module.exports = new Socket ();
