/**
 * Bright Solutions asterisk server.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */


// Including daemon module.
var daemon = require ('./application/daemon.js');
daemon.setMaster ();// The current process has to be the master process.

 
// Load config data.
var config = require ('./application/config.js');


//Declaring port constants.
var socket_port = daemon.getCMDArgument ('socket_port', config.getValue ('socket', 'port', 3081));
var http_port	= daemon.getCMDArgument ('http_port', config.getValue ('http', 'port', 8080));


// Including server modules
var socketServer = require ('./server/socket.js');
var httpServer   = require ('./server/HTTPPerDrupal.js');


// Starting servers.
socketServer.start (socket_port);
httpServer.start (http_port);
httpServer.addListener (socketServer);
