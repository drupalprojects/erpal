/**
 * Provides a client manager.
 * 
 * @author 		Marc Sven Kleinböhl, Karsten Planz
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function ClientManager () {
	
	this.clientEntities = new Array ();
	this.socketClients  = new Array ();

}

ClientManager.prototype.register = function (phoneNumbers, ip) {
  
	this.clientEntities[ip] = {
			'phoneNumbers': 		JSON.parse (phoneNumbers),
			'socketClientObject': 	this.socketClients[ip],
			'status':				true
	};
	return;
};

/*
 * Returns the socket client object of a specific phone number.
 * @param string 	phoneNumber 	The phone number of the client.
 * @return object					The selected socket client object.
 */
ClientManager.prototype.getSocketClientByPhoneNumber = function (phoneNumber) {
	
  
	for (clientIndex in this.clientEntities) {
		for (phoneNumberIndex in this.clientEntities[clientIndex].phoneNumbers) {
			if (phoneNumber == this.clientEntities[clientIndex].phoneNumbers[phoneNumberIndex]) {
				return this.clientEntities[clientIndex].socketClientObject;
			}
		}
	}
	
	return null;
};

/*
 * Removes a client object of a specific socket client object. 
 * @param object socketClientObject	The socket client object whose client data you want to delete.
 */
ClientManager.prototype.removeClientBySocketClientObject = function (socketClientObject) {
	
	for (clientIndex in this.clientEntities) {
		
		if (socketClientObject == this.clientEntities[clientIndex].socketClientObject) {
			this.clientEntities.slice(clientIndex, 1);
		}
	}
	
	return;
};

/*
 * Saves a socket clients socket client object by IP.
 * @param string ip					The IP of the socket client.
 * @param object socketClientObject	The socket client object whose client data you want to save.
 */
ClientManager.prototype.saveSocketClientObject = function (ip, socketClientObject) {
	this.socketClients[ip] = socketClientObject;
	return;
};

/*
 * Sets the status of the client.
 * @param boolean	status	The boolean status. TRUE for available.
 */
ClientManager.prototype.setStatus = function (socketClientObject, status) {
	
	for (clientIndex in this.clientEntities) {
		
		if (socketClientObject == this.clientEntities[clientIndex].socketClientObject) {
			this.clientEntities[clientIndex].status = status;
		}
	}
	
	return;
};

module.exports = new ClientManager ();
