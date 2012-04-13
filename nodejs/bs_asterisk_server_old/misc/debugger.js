/**
 * A simple debugging interface.
 * 
 * @author 		Marc Sven Kleinböhl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */
 
var test; 
 
module.exports = (test = function () {
	
	this.test++;
	
	var self = this;
	

}

);

	test.prototype.testfunc = function () {
		console.log (self.test);
	};