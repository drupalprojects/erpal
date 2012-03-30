/**
 * Generic event handler module.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

var EventHandler = (function () {
	
	this.listeners = new Array ();
	
});

/*
 * Adds a listener object to the internal list of listeners.
 * @param function 	listenerObject	Listener object.
 * @param mixed		bypassedParams	An optional param which will bypassed to the listener method.
 */
EventHandler.prototype.addListener = function (listenerObject, bypassedParams) {
	
	this.listeners.push (
		{
			'listenerObject' 	: listenerObject,
			'bypassedParams'	: bypassedParams
		}	
	);
	
	return;
};

/*
 * Sends an invent to all registered listners.
 * @param string	method		The method identifier.
 * @param mixed		The data parameter of an event.
 */
EventHandler.prototype.invokeListeners = function (method, eventParam) {
	
	for (listener in this.listeners) {
    //this.listeners[listener].listenerObject.registerClientData(eventParam);
    
 		eval (
 				'try {this.listeners[listener].listenerObject.' + 
 				method + 
 				'(eventParam);}' + 
 				'catch (e){console.log("Listener has not implemented required method.");}'
 	    );
	}
	
	return;
};

// Module export.
module.exports = new EventHandler ();
