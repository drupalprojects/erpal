/**
 *  @file shortcut_keys/js/shortcut_keys.js
 *  @author Thiemo Müller
 *  @version 1.0
 *  
 *  Define the shortcut_keys JavaScript interface.
 */

var shortcut_keys = {
  
  /**
   *  Extend this object to add your custom type callbacks
   */
  callbacks                   : {
    
    /**
     *  Simply load the given URL
     *  
     *  @param shortcut The shortcut definition
     *  @return NULL
     */
    url                         : function(shortcut) {
      var value = shortcut.value;
      value     = value.replace( /\[q\]/g, shortcut_keys.q );
      value     = value.replace( /\[([0-9]+)\]/g, function($0,$1) {
        $1        = Number($1);
        
        if( $1>=shortcut_keys.arg.length )
          return "";
        
        return shortcut_keys.arg[ $1 ];
      } );
      
      var url;
      if( value.match( /^([a-z\-0-9]+):\/\// ) || value.substr(0,7)=='mailto:' )
        url = value;
      else
        url = Drupal.settings.basePath + ( value=='<front>' ? '' : value );
      
      location.href = url;
    },
    
    /**
     *  Simply execute the given JavaScript snippet
     *  
     *  @param shortcut The shortcut definition
     *  @return NULL
     */
    javascript                  : function(shortcut) {
      eval( shortcut.value );
    }
    
  },
  
  /**
   *  Init the JavaScript once the shortcuts are available
   *  
   *  @return NULL
   */
  init                        : function() {
    
    console.log( 'Shortcut keys inited with the following commands: ', shortcut_keys.shortcuts );
    
    jQuery('body')
      .keydown( function(e) {
        
        var keycode = e.keyCode || e.which;
        shortcut_keys.keys_down[ keycode ]  = true;
        
		if( jQuery.isArray(shortcut_keys.shortcuts) )
			return;
		
        for( var name in shortcut_keys.shortcuts ) {
          
          var shortcut        = shortcut_keys.shortcuts[ name ];
          
          // Check that all keys are currently down and that the key that was just pressed is also a part of the command's keys definition
          var keys            = shortcut.keys.split( '+' );
          var bKeyIncluded    = false;
          var bAllOthersDown  = true;
          for( var i=0; i<keys.length; i++ ) {
            var req_keycode = shortcut_keys.keycode_table[ keys[i] ];
            
            if( req_keycode==keycode ) {
              bKeyIncluded    = true;
            }
            else if( !shortcut_keys.keys_down[ req_keycode ] ) {
              bAllOthersDown  = false;
              break;
            }
          }
          
          if( bKeyIncluded && bAllOthersDown ) {
            // If it has to be double-pressed, we just skip execution until the second call
            if( !shortcut.press_double || (shortcut_keys.potential_command==name && ((new Date()).getTime()-shortcut_keys.potential_command_at)<500) ) {
              shortcut_keys.potential_command     = null;
              shortcut_keys.potential_command_at  = 0;
              
              if( shortcut_keys.execute( shortcut ) ) {
                
                shortcut_keys.keys_down[ keycode ]  = false;
                
                //shortcut_keys.last_key_was_command  = true;
              }
              
              e.preventDefault();
              return false;
              
            }
            else {
              shortcut_keys.potential_command     = name;
              shortcut_keys.potential_command_at  = (new Date()).getTime();
            }
          }
          
        }
        
      } )
      .keypress( function(e) {
        
        if( shortcut_keys.last_key_was_command ) {
          e.preventDefault();
          return false;
        }
        
      } )
      .keyup( function(e) {
        
        var keycode = e.keyCode || e.which;
        shortcut_keys.keys_down[ keycode ]  = false;
        
        if( shortcut_keys.last_key_was_command ) {
          shortcut_keys.last_key_was_command  = false;
          e.preventDefault();
          return false;
        }
        
      } );
    
  },
  last_key_was_command        : false,  // Whether or not the last down'ed key resulted in a command being executed
  potential_command           : null,   // The command that was almost executed, if not for double pressing
  potential_command_at        : 0,      // When the last command was almost executed, so that double pressing isn't allowed when seconds lie inbetween
  
  /**
   *  Execute the given shortcut
   *  
   *  @param shortcut The shortcut definition
   *  @return NULL
   */
  execute                     : function( shortcut ) {
    
    // Input element selected? Not all shortcuts like that
    if( !shortcut.always_execute && jQuery('input:focus,select:focus,textarea:focus').size() )
      return false;
    
    // Confirmation required?
    if( shortcut.confirm_dialog && !window.confirm( Drupal.t( 'Are you sure you want to !action?', { '!action':shortcut.name } ) ) )
      return false;
    
    // Alright, go for it.
    shortcut_keys.callbacks[ shortcut.type ]( shortcut );
    
    return true;
    
  },
  
  /**
   *  Add handler to simply display the currently pressed keys
   *  
   *  @param element (jQuery) The element to add the handlers to
   *  @return NULL
   */
  register_shortcut_textfield : function(element) {
    element
      .blur( function(e) {
        var element   = jQuery(e.target);
        element.data( 'keys-down', 0 );
      } )
      .keydown( function(e) {
        var element   = jQuery(e.target);
        var keysdown  = element.data( 'keys-down' );
        
        if( !keysdown ) {
          element.val( '' );
          keysdown  = 0;
        }
        
        var keycode = e.keyCode || e.which;
        var keyname = null;
        
        for( var name in shortcut_keys.keycode_table ) {
          if( shortcut_keys.keycode_table[name]==keycode ) {
            keyname = name;
            break;
          }
        }
        
        if( keyname ) {
          var val;
          if( val=element.val() ) {
            
            val += '+';
            if( !val.match( new RegExp( "(^|\\+)"+keyname+"\\+", "g" ) ) ) {
              element.val( val + keyname );
              keysdown++;
            }
          }
          else {
            element.val( keyname );
            keysdown++;
          }
        }
        
        element.data( 'keys-down', keysdown );
        
        e.preventDefault();
        
        return false;
      } )
      .keypress( function(e) {
        e.preventDefault();
        
        return false;
      } )
      .keyup( function(e) {
        var element   = jQuery(e.target);
        element.data( 'keys-down', element.data( 'keys-down' ) - 1 );
        
        e.preventDefault();
        
        return false;
      } );
  },
  
  // Store all downed keys
  keys_down           : {},
  
  // List of all shortcuts, may be edited live
  shortcuts           : {},
  
  // Will be filled by settings
  keycode_table       : {},
  
  // Arguments of the current page as well the called path
  q                   : "",
  arg                 : []
  
};

Drupal.behaviors.shortcut_keys  = {
  
  attach  : function( context, settings ) {
    
    // Add settings
    if( Drupal.settings.shortcut_keys ) {
      shortcut_keys.keycode_table = Drupal.settings.shortcut_keys.keycode_table;
      shortcut_keys.shortcuts     = Drupal.settings.shortcut_keys.shortcuts;
      shortcut_keys.q             = Drupal.settings.shortcut_keys.q;
      shortcut_keys.arg           = Drupal.settings.shortcut_keys.arg;
      
      shortcut_keys.init();
    }
    
    // Register shortcut textfield to ignore all key events, if available
    shortcut_keys.register_shortcut_textfield( jQuery('#shortcut-keys-admin-shortcut-edit-form #edit-keys') );
    
    jQuery('#shortcut-keys-admin-shortcut-edit-form #edit-machine-name, #shortcut-keys-admin-shortcut-group-edit-form #edit-machine-name')
      .focus( function(e) {
        
        var input = jQuery(e.target);
        if( !input.val() )
          input.val( jQuery('#shortcut-keys-admin-shortcut-edit-form #edit-name, #shortcut-keys-admin-shortcut-group-edit-form #edit-name').val().toLowerCase().replace( /([^a-z0-9_]+)/g, '_' ) );
        
      } );
    
  }
  
};