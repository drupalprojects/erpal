/**
 *  @file commander/js/commander.js
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  Define the commander JavaScript interface. This may also be used by other modules, as the commander_shortcut_keys module does.
 */

// Global commander JavaScript interface
commander = {
  
  /**
   *  Show/Hide the console
   *  
   *  @return NULL
   */
  toggle_console    : function() {
    
    // Skip unpatience
    if( commander.console_loading )
      return;
    
    // Console loaded already? Simply toggle visiblity
    if( commander.console ) {
      commander.console.toggle();
      
      if( commander.console.is(':visible') )
        commander.console.find( '#commander-console-input input:first' ).focus();
      
      return;
    }
    
    // Alright, load it. For those unpatient users we'll display the overlay already...
    commander.console_loading = true;
    var pReplaceMe            = jQuery('<div id="commander-console-overlay"></div>').appendTo( jQuery('body') );
    
    // Request the plain console
    jQuery.ajax( {
      url     : Drupal.settings.basePath + 'commander/ajax/console?environment='+JSON.stringify(commander.environment),
      success : function(data) {
        commander.console_loading = false;
        
        commander.console = jQuery( data );
        // Replace dummy overlay
        pReplaceMe.replaceWith( commander.console );
        
        // Scroll log down
        commander.console.find( '#commander-console-log' ).scrollTop( 99999 );
        
        // Allow users to hide the console using the ESC key
        commander.console.find( '#commander-console-input input:first' )
          .keydown( function(e) {
            
            if( (e.keyCode||e.which)==27 )
              commander.console.hide();
            
          } )
          .focus();
        
        // Click on overlay closes console...
        commander.console.click( function(e) {
          
          if( jQuery(e.target).is( '#commander-console-overlay' ) )
            commander.console.hide();
          
        } );
        
        Drupal.attachBehaviors( commander.console );
      },
      error   : function() {
        console.error( 'The console could not be loaded!' );
      }
    } );
    
  },
  
  /**
   *  Execute the given command
   *  
   *  @TODO
   *  @param command (string) The input command to be executed
   *  @param callback (function) A function to be called as function( successful:bool, messages:[ { type:'error'|'warning'|..., message:'The result message', timestamp:35234636 }, ... ], display:'<div...' )
   *  @return NULL
   */
  execute           : function( command, callback ) {
    
    jQuery.ajax( {
      url     : Drupal.settings.basePath + 'commander/ajax/execute?environment='+JSON.stringify(commander.environment)+'&input='+command,
      success : function(data) {
        callback( data.result, data.messages, data.display );
      },
      error   : function() {
        console.error( 'The command could not be executed by AJAX!' );
        
        if( callback )
          callback( false );
        
      }
    } );
    
  },
  
  /**
   *  Execute the given shortcut
   *
   *  @param shortcut The shortcut definition
   *  @return NULL
   */
  execute_shortcut  : function( shortcut ) {
    
    // Simply pass on
    // @TODO: Is there any smarter way for displaying this? Like adding it to the block if available or just opening the console once finished? At least we should strip all markup...
    commander.execute( shortcut.value, function( successful, messages, display ) {
      
      for( var i=0; i<messages.length; i++ )
        alert( messages[i].message );
      
    } );
    
  },
  
  console_loading   : false,  // Are we loading the console already? (fight unpatience)
  console           : null,   // The console overlay top element
  environment       : {}      // Environmental variables to overwrite defaults. Currently used for the 'q' key
  
};

Drupal.behaviors.commander  = {
  
  attach  : function( context, settings ) {
    
    // Add environmental keys
    if( settings.commander && settings.commander.environment )
      for( var name in settings.commander.environment )
        commander.environment[name]     = settings.commander.environment[name];
    
  }
  
};