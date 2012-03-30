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
	/*this.netSocketServer = require('net').createServer(function(connection) {

		connection.on('connect', function() {
	
			   console.log ('Client ' + connection.remoteAddress + ' connected.');
			
			   self.clientManager.saveSocketClientObject (
						connection.remoteAddress,
						connection
				);
				
				return;
		});
			
		connection.on('close', function() {
				
				console.log ('Client ' + connection.remoteAddress + ' disconnected.');
			
				self.clientManager.removeClientBySocketClientObject (connection);
				
				return;
		});
			
		connection.on('data', function(data) {
	 
        console.log(data.toString());
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
		
	});*/

	return;
}

/*
 * Sends data to the client.
 * @param 	string	postData	The post data string.
 * @return  boolen				TRUE on success.
 */
Socket.prototype.sendData = function (postData) {

console.log("sendData");

	var socketClientObject = this.clientManager.getSocketClientByPhoneNumber(
			postData['receiverPhoneNumber']
	);
	  console.log(socketClientObject);
	if (socketClientObject == null) {
		return false;
	}
	
	//socketClientObject.write (postData['caller_data']);
	socketClientObject.emit('caller_data', { caller_data: postData['caller_data'] });

	return true;
};
   
/*
 * Starts the socket server.
 * @param integer	port	The number of the port the server shall listen.
 */
Socket.prototype.start = function (port) {
	
	//this.netSocketServer.listen(port);
  var self			 = this;	
  
  var io = require('socket.io').listen(3081);

  io.sockets.on('connection', function (socket) {
  
    var address = socket.handshake.address.address;
			   console.log ('Client ' + address + ' connected.');

			   self.clientManager.saveSocketClientObject (
						address,
						socket
				);
        
    socket.emit('status', { status : 'ok' });
  
    socket.on('connect', function() {
         
				
				return;
		});
			
		socket.on('disconnect', function() {
				var address = socket.handshake.address.address;
				console.log ('Client ' + address + ' disconnected.');
			
				self.clientManager.removeClientBySocketClientObject (socket);
				
				return;
		});
			
		socket.on('data', function(data) {
	 
        console.log(data.toString());
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
    
  

   // socket.emit('news', { hello: 'world' });


  });

  
	return;
};

/*
 * Stops the socket server.
 */
Socket.prototype.stop = function () {
	
	//this.netSocketServer.close ();
	
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
