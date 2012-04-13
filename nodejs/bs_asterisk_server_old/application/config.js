/**
 * Handles the configuration data.
 * 
 * @author 		Marc Sven Kleinb�hl
 * @copyright 	2012 (c) Bright Solutions GmbH
 * 				All rights reserved.
 */

function Config () {

    var self		= this;    
    this.configData = null;
    
    function loadConfig () {

        var iniparser   = require('../misc/iniparser.js');
        self.configData = iniparser.parseSync('./config.ini');
 
        return;
    };
    
    loadConfig();
};

Config.prototype.getValue = function (group, key, defaultValue) {
 
	return this.configData[group][key] ? this.configData[group][key] : defaultValue;
};

module.exports = new Config ();