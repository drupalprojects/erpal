(function($){
  var pConfig        = {
    translations        : {
      click_here          : 'Click here to copy image from clipboard',
      press_ctrl_v        : 'Now press CTRL+V',
      unknown_file_type   : 'Can\'t read file of type ',
      use_real_browser    : 'Please use Firefox or Chrome for advanced web standards like this.'
    },
    hide_in_ie          : true,
    insert_element      : { relative:'before', element:'.form-item-body-und-0-value' },
    paste_to            : { type:'ckeditor', element:'edit-body-und-0-value' },
    paste_types         : {
      ckeditor            : function( html, config ) {
        var object      = CKEDITOR.dom.element.createFromHtml( html );
        CKEDITOR.instances[ config.element ].insertElement( object );
      }
    }
  };
  window.ClipboardImage = pConfig;
  
  $( function() {
    var bWaitingForInput  = false;
    
    var pCopyElement  = $('<div />')
      .addClass( 'copy-image-from-clipboard' )
      .text( pConfig.translations.click_here )
      .click( function(e) {
        
        if( window.clipboardData ) {
          pCopyElement.text( pConfig.translations.use_real_browser );
          return;
          var sData     = window.clipboardData.getData("Text");
        }
        
        bWaitingForInput  = true;
        
        if( window.Clipboard ) {
          
          $(e.target).text( pConfig.translations.press_ctrl_v );
        }
        else {
          $(e.target).text( pConfig.translations.press_ctrl_v );
          document.execCommand( 'selectAll', false, null );
        }
        
      } );
    
    if( pConfig.insert_element.relative=='before' )
      pCopyElement.insertBefore( pConfig.insert_element.element );
    else if( pConfig.insert_element.relative=='after' )
      pCopyElement.insertAfter( pConfig.insert_element.element );
    else
      pCopyElement.appendTo( pConfig.insert_element.element );
    
    if( !window.Clipboard && !window.clipboardData ) {
      pCopyElement
        .attr( "contenteditable", "" );
    }
    else if( window.clipboardData && pConfig.hide_in_ie ) {
      pCopyElement.hide();
    }
    
    
    $( document ).bind( "paste", function(event) {
      if( event.originalEvent.clipboardData ) {
        var items = event.originalEvent.clipboardData.items;
        
        if( !items[0] || items[0].type.substr(0,5)!="image" ) {
          if( items[0] ) {
            if( bWaitingForInput )
              pCopyElement.text( pConfig.translations.unknown_file_type+items[0].type );
          }
          
          bWaitingForInput  = false;
          
          return;
        }
        
        var blob      = items[0].getAsFile();
        var reader    = new FileReader();
        reader.onload = function( event ) {
          
          paste( null, event.target.result );
          
        };
        
        reader.readAsDataURL(blob);
        
        return false;
      }
      else {
        
        setTimeout( function() {
          
          paste( pCopyElement.html() );
          
        }, 200 );
        
        return true;
        
      }
      
    } );
    
    function paste( html, image ) {
      
      if( image )
        html  = "<img src=\""+image+"\" />";
      
      pConfig.paste_types[ pConfig.paste_to.type ]( html, pConfig.paste_to );
      
      pCopyElement.text( pConfig.translations.click_here );
      bWaitingForInput  = false;
      
    }
  } );
})(jQuery);