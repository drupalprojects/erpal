/**
 *  @file commander_shortcut_keys/js/commander_shortcut_keys.js
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  Expose execution of commander-commands to shortcut_keys module
 */

Drupal.behaviors.commander_shortcut_keys  = {
  
  attach  : function( context, settings ) {
    
    shortcut_keys.callbacks.command = commander.execute_shortcut;
    
  }
  
};
