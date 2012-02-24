/**
 * Provides a client data entity.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function ClientEntity () {
	
	this.data   = {
			'ip' 			: '',
			'socketClient'  : null
	};
}

/*
 * Returns the IP of the client entity.
 * @param string 	The IP.
 */
ClientEntity.prototype.setIP = function (ip) {

	this.ip = ip;
	
	return;
};

/*
 * Returns the IP of the client entity.
 * @return string 	The IP.
 */
ClientEntity.prototype.getIP = function () {

	return this.ip;
};



module.exports = ClientEntity;
