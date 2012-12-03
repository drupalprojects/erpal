/**
 * HTTPPerDrupal server module.
 * 
 * @author 		Marc Sven Kleinböhl, Karsten Planz
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function HTTPPerDrupal () {
	
	var self = this;
	
	this.eventHandler = require ('../misc/eventhandler.js');
	this.queryString  = require ('querystring');
	
	/*
	 * Splits an URL into segments.
	 * @param object	An URL object.
	 * @return array	An array which contains the segments.
	 */ 	
	this.parseRequestURL = function (url) {
		
		var urlString = url.toString ();
		
		return urlString.split (/\//);
	}; 
 	
	/*
	 * Creating the server instance.
	 */
	this.httpServer = require('http').createServer(function (request, response) {
		

		var urlSegments = self.parseRequestURL (request.url);
 
		// Routing --->
		
		// Is the request a "caller info request"?
		if (urlSegments.length == 2 && urlSegments[1] == 'ingoing' && request.method == 'POST') {
			
			self.handleIngoingData (request, response);	
		}
		
		// Is the request a "caller info request"?
		if (urlSegments.length == 2 && urlSegments[1] == 'register' && request.method == 'POST') {
			
			self.handleClientRegistering (request, response);	
		}
		
		// <-- Routing
	
		return;
	});
}

/*
 * Handles ingoing caller data.
 * @param object	request 
 * @param object	response
 */
HTTPPerDrupal.prototype.handleIngoingData = function (request, response) {
	
	var postData = "";
	var self	 = this;
	
  request.on('data', function(chunk) {
    postData += chunk.toString();
  });
  
  	    
  request.on('end', function(chunk) {
    var post = self.queryString.parse (postData);	 
    self.eventHandler.invokeListeners('sendData',  post);
            
    response.writeHead(200, {
      'Content-Type': 'application/json',
      'Access-Control-Allow-Origin' : '*'
    });

    var response_ok = { status : "ok" };
    response.write (JSON.stringify(response_ok)); // Pro forma
    response.end ();
  });
	
	return;
};

/*
 * Handles client data registering
 * @param object	request 
 * @param object	response
 */
HTTPPerDrupal.prototype.handleClientRegistering = function (request, response) {
	
	var postData = "";
	var self	 = this;
	
  request.on('data', function(chunk) {
    postData += chunk.toString();
  });
  // console.log('---------------------------------------------------------');
  // console.log(postData);
  // console.log('---------------------------------------------------------');
  request.on('end', function(chunk) {

    var post = self.queryString.parse (postData);	 
    self.eventHandler.invokeListeners('registerClientData', post);

    response.writeHead(200, {
      'Content-Type': 'application/json',
      'Access-Control-Allow-Origin' : '*'
    });

    var response_ok = { status : "ok" };
    response.write (JSON.stringify(response_ok)); // Pro forma
    response.end ();
  });
	
	return;
};

/*
 * Starts the HTTPPerDrupal server.
 * @param integer port	The Port were the server shall listen.
 */
HTTPPerDrupal.prototype.start = function (port) {
	
	this.httpServer.listen (port);
	
	return;
}; 

/*
 * Stops the HTTPPerDrupal server.
 */
HTTPPerDrupal.prototype.stop = function () {
	
	this.httpServer.close ();
	
	return;
};

/*
 * Adds a listener object.
 * @param	object	The listener object.
 */
HTTPPerDrupal.prototype.addListener = function (listenerObject) {

	this.eventHandler.addListener (listenerObject, null);
	
	return;
};



// Module export.
module.exports = new HTTPPerDrupal ();
