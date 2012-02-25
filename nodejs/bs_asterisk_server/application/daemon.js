/**
 * Provides some daemon functions for the bs_asterisk_server application.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function Daemon () {
	
	var self	   = this;
	this.arguments = new Array ();
	
	process.argv.forEach(function (val, index, array) {
		
		switch (val) {
			case '-socket_port':
				self.arguments['socket_port'] = array[index + 1];
				break;
				
			case '-http_port':
				self.arguments['http_port'] = array[index + 1];
				break;	
				
			case '-stop':
				self.killMasterAndExit ();
				break;
		}
		
    });	
};

/*
 * Returns the value of a specific commandline argument.
 * @param string	key				The key name of the commandline argument.
 * @param string	defaultValue	The default value of the commandline argument.
 * @param mixed						The value of the commandline argument.
 */
Daemon.prototype.getCMDArgument = function (key, defaultValue) {

	return this.arguments[key] ? this.arguments[key] : defaultValue;
};

/*
 * Kills the master process.
 */
Daemon.prototype.killMasterAndExit = function () {
	
//	var process = require ('process');
	var pid 	= this.getMasterPid();
	
	process.kill(pid);
	process.exit ();
	
	return;
};

/*
 * Sets the current process as master process.
 */
Daemon.prototype.setMaster = function () {

	require('fs').writeFile('bs_asterisk_server.pid', process.pid + "", function (error) {
		
	  if (error) {
	    console.log(error);
	  }
	});
	
	return;
};

/*
 * Returns the pid of the master process.
 * @return integer The pid of the master process.
 */
Daemon.prototype.getMasterPid = function () {
	
	return require('fs').readFileSync('bs_asterisk_server.pid', 'ascii');;
};

module.exports = new Daemon ();
