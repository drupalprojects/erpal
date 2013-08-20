(function($) {
  
  if( !navigator.userAgent.match( /AppleWebKit/ ) )
    return;
  
  var waitForUpload     = null;
  var waitForAJAXUpload = null;
  var ajaxFormElement   = null;
  // Config - translations
  var messages      = {
    confirm           : "Do you wish to upload the file now?\n\t\nElse you can still add some tags.",
    drop              : 'Simply drop your file here.',
    edit              : 'Drop here to edit %title.',
    error             : 'Please finish uploading first.'
  };
  
  if( !window.erpal_file_drag_drop_content_selector )
    window.erpal_file_drag_drop_content_selector  = '.erpal-region-content';
  
  // All file items with their corresponding names, drop targets and message object and an optional human readable name. Their visibility will also be stored.
  var aFileItems      = [];
  // Store how many of the possible drop targets are currently visible
  aFileItems.iVisible = 0;
  var pInput          = null;
  var pInputParent    = null;
  
  // Get file item from the aFileItems list by it's name (check existence for example)
  function getFileItemByName( sName ) {
    for( var i=0; i<aFileItems.length; i++ )
      if( aFileItems[i].sName==sName )
        return aFileItems[i];
    
    return null;
  }
  
  // Add file item. If the name already exists, the item will be overridden
  function addFileItem( sName, sSelector, mMessageBlock, sHumanName ) {
    var pItem = {
      sName       : sName,
      sSelector   : sSelector,
      sHumanName  : sHumanName,
      bVisible    : false
    };
    
    if( typeof mMessageBlock=='string' ) {
      pItem.sMessageBlock = mMessageBlock;
      pItem.pMessageBlock = $('<div />').addClass('erpal-file-drag-drop-message efddm-'+sName).insertBefore( $( pItem.sSelector ) ).hide();
      $('<div />')
        .addClass('message-inner')
        .appendTo( pItem.pMessageBlock );
    }
    else {
      pItem.pMessageBlock = mMessageBlock.hide();
    }
    
    for( var i=0; i<aFileItems.length; i++ )
      if( aFileItems[i].sName==pItem.sName )
        return aFileItems[i]  = pItem;
    
    aFileItems.push( pItem );
  }
  
  // Check all file items for visibility, update .bVisible and .iVisible
  function checkFileItemsVisibility() {
    
    aFileItems.iVisible = 0;
    for( var i=0; i<aFileItems.length; i++ ) {
      aFileItems[i].bVisible  = !!$(aFileItems[i].sSelector+':visible').size();
      if( aFileItems[i].bVisible )
        aFileItems.iVisible++;
    }
    
  }
  
  // Show drop or error message and display both message and form element (latter only if no error happened)
  function show( bError ) {
    
    // Simply use first item's message block to display the error
    if( bError ) {
      var pItem = aFileItems[0].pMessageBlock;
      
      pItem
        .addClass( 'error' )
        .show()
        .css( { position:'fixed', top:'0', left:'0', right:'0', bottom:'0', zIndex:'1000000' } );
      pItem
        .find('.message-inner')
        .text( messages.error );
      
      return;
    }
    
    for( var i=0; i<aFileItems.length; i++ ) {
      if( !aFileItems[i].bVisible )
        continue;
      
      var iLeft   = 100 / aFileItems.iVisible * i;
      var iRight  = 100 - 100 / aFileItems.iVisible * (i+1);
      aFileItems[i]
        .pMessageBlock
        .removeClass( 'error' )
        .show()
        .css( { position:'fixed', top:'0', left:iLeft+'%', right:iRight+'%', bottom:'0', zIndex:'1000000' } )
        .find('.message-inner')
        .text( aFileItems[i].sHumanName ? messages.edit.replace( /%title/, aFileItems[i].sHumanName ) : messages.drop );
      
      $( aFileItems[i].sSelector )
        .css( { position:'fixed', top:'0', left:iLeft+'%', right:iRight+'%', bottom:'0', zIndex:'1000001', opacity:'0' } );
    }
    
    //$('#erpal-file-block-edit form>div>.field-type-file-form').css( { overflow:'visible', width:'auto', height:'auto' } );
    
  }
  
  // Hide messages and input elements
  function hide() {
    
    for( var i=0; i<aFileItems.length; i++ ) {
      aFileItems[i]
        .pMessageBlock
        .hide();
      
      $( aFileItems[i].sSelector )
        .attr( "style", "" );
    }
    
    //$('#erpal-file-block-edit form>div>.field-type-file-form').css( { overflow:'hidden', width:'0', height:'0' } );
    
  }
  
  $( function() {
    
    // We're getting an "dragenter" event each time the drag enters a new element. Thus we count for- and backwards to know when the user left the whole page again to hide the elements
    var iEntered      = 0;
    
    $('html').bind( 'dragenter', function(e) {
      
      checkFileItemsVisibility();
      
      if( !aFileItems.iVisible ) {
        show( true );
      }
      else if( !iEntered ) {
        show();
      }
      else {
        for( var i=0; i<aFileItems.length; i++ ) {
          if( $(e.target).is( aFileItems[i].sSelector ) ) {
            aFileItems[i]
              .pMessageBlock
              .addClass( 'active-drop-target' );
          }
          else {
            aFileItems[i]
              .pMessageBlock
              .removeClass( 'active-drop-target' );
          }
        }
      }
      
      iEntered++;
      
    } );
    
    $('html').bind( 'dragleave', function(e) {
      
      if( !iEntered )
        return;
      
      iEntered--;
      
      if( !iEntered )
        hide();
      
    } );
    
    $('html').bind( 'drop', function(e) {
      
      if( !aFileItems.length ) {
        e.preventDefault();
        return false;
      }
      
      iEntered  = 0;
      hide();
      
    } );
    
    // Wait for the upload to finish, then confirm direct form processing (else the user can still add tags to the file)
    window.erpal_file_block_check_upload_progress = function(editing) {
      if( $('#erpal-file-block'+(editing?'-edit':'')+' .form-file').size() )
        return;
      
      clearTimeout( waitForUpload );
      waitForUpload = null;
      
      if( editing || window.confirm( messages.confirm ) )
        $('#erpal-file-block'+(editing?'-edit':'')+' form').submit();
      
    };
    
    // AJAX add: Step 1 -> Waiting for file to finish upload
    window.erpal_file_block_check_ajax_upload_progress  = function() {
      if( $('#erpal-file-block-ajax .form-file').size() ) {
        if( $('#erpal-file-block-ajax .messages').size() ) {
          $('#erpal-file-block-ajax .messages')
            .insertBefore( ajaxFormElement );
          ajaxFormElement.val( "" );
          
          clearTimeout( waitForAJAXUpload );
          waitForAJAXUpload = null;
        }
        
        return;
      }
      
      clearTimeout( waitForAJAXUpload );
      waitForAJAXUpload = null;
      
      waitForAJAXUpload = setInterval( 'erpal_file_block_check_ajax_submit_progress()', 333 );
      
      ajaxFormElement.val( 'Creating file node...' );
      $('#erpal-file-block-ajax .form-submit[id^="edit-submit"]')
        .mousedown()
        .click()
        .mouseup();
    };
    
    // AJAX add: Step 2 -> Waiting for node form to be successfully submitted
    window.erpal_file_block_check_ajax_submit_progress  = function() {
      if( !$('#erpal-file-block-ajax-value:visible').size() )
        return;
      
      clearTimeout( waitForAJAXUpload );
      waitForAJAXUpload = null;
      
      var sValue  = $('#erpal-file-block-ajax-value:visible').text();
      
      $('#erpal-file-block-ajax-value:visible').remove();
      
      var sSelector = '.field-type-entityreference-form.field-name-field-asset-files-form.field-widget-entityreference-autocomplete';
      ajaxFormElement.val( sValue );
      
      // Display "file has been created message"
      $('#erpal-file-block-ajax #messages')
        .insertBefore( ajaxFormElement );
      
      // Automatically add one more item...
      $(sSelector+' .field-add-more-submit')
        .mousedown()
        .click()
        .mouseup();
      
      // Allow more uploads. Currently doesn't work since the form gets invalidated as soon as it's been processed...
      $('#erpal-file-block-ajax .form-submit[id$="remove-button"]')
        .mousedown()
        .click()
        .mouseup();
    };
    
  } );
  
  Drupal.behaviors.erpal_file_drag_drop = {
    
    attach  : function( context, settings ) {
      
      // Load translations
      if( settings.erpal_file_drag_drop && settings.erpal_file_drag_drop.messages ) {
        for( var key in settings.erpal_file_drag_drop.messages )
          messages[ key ] = settings.erpal_file_drag_drop.messages[ key ];
      }
      
      // Add auto-submit handlers
      var pAddForm  = $('#erpal-file-block .form-file');
      
      if( pAddForm.size() && !getFileItemByName('erpal-file-block') ) {
        pAddForm
          .bind( 'change', function(e) {
            
            // Safari doesn't call drop...
            hide();
            
            $('#erpal-file-block .form-file')
              .siblings('.form-submit')
              .mousedown()
              .click()
              .mouseup();
            
            waitForUpload = setInterval( 'erpal_file_block_check_upload_progress()', 333 );
            
          } );
        
        addFileItem( 'erpal-file-block', '#erpal-file-block .form-file', $('#erpal-file-block-message') );
      }
      
      if( $('#erpal-file-block .form-file').size() ) {
        pInput        = $('#erpal-file-block .form-file')
          .addClass( 'erpal-file-block-form-file' );
        pInputParent  = pInput.parent();
      }
      
      // Viewing file?
      if( $('#erpal-file-block-edit').size() ) {
        
        // Add single event handlers
        if( !$('#erpal-file-block-edit').hasClass('erpal-file-block-processed') ) {
          $('#erpal-file-block-edit').addClass( 'erpal-file-block-processed' );
          
          // Remove current image (as long as the form isn't submitted this isn't final, but to add a new file, the old one must have gone...)
          $('#erpal-file-block-edit .file-widget.form-managed-file .form-submit')
            .mousedown()
            .click()
            .mouseup();
          
          // Auto submit on change
          $('#erpal-file-block-edit .form-file')
            .live( 'change', function(e) {
              
              $('#erpal-file-block-edit form')
                .submit();
              
              //waitForUpload = setInterval( 'erpal_file_block_check_upload_progress(true)', 333 );
              
            } );
          
          // Add as drop target
          addFileItem( 'erpal-file-block-edit', '#erpal-file-block-edit .form-file', $('#erpal-file-block-edit-message'), $('#erpal-file-block-edit-message .edit-title').text() );
          
        }
        
      }
      
      // Check for file fields within the content area (editing an erpal file for example) that can be used as drop targets
      var aSelectors  = window.erpal_file_drag_drop_content_selector.split(',');
      for( var i=0; i<aSelectors.length; i++ )
        $(aSelectors[i]+' .form-file').each( function() {
          
          var pSelf = $(this);
          var sID   = pSelf.attr("id");
          if( getFileItemByName(sID) )
            return;
          
          addFileItem( sID, aSelectors[i]+' #'+sID, sID, pSelf.parent().parent().find('label').text() );
          
          pSelf.change( function(e) {
            
            $(e.target)
              .siblings('.form-submit')
              .mousedown()
              .click()
              .mouseup();
            
          } );
          
        } );
      
      // Selector for the autocomplete entity reference field (i.e. referencing an ERPAL file)
      var sSelector = '.field-type-entityreference-form.field-name-field-asset-files-form.field-widget-entityreference-autocomplete';
      var pElement  = $(sSelector);
      var pAJAXForm = $('#erpal-file-block-ajax');
      if( pElement.size() && pAJAXForm.size() && !pAJAXForm.hasClass('erpal-file-drag-drop-processed') ) {
        
        pAJAXForm.addClass('erpal-file-drag-drop-processed');
        
        // Add/Overwrite AJAX handler item
        var sTitle  = $(sSelector+' .field-label').text().replace( /(^[\s]+)|([\s]+)$/g, "" );
        addFileItem( 'erpal-file-block-ajax', '#erpal-file-block-ajax .form-file', $('#erpal-file-block-ajax-message'), sTitle );
        
        // When the user dropped the file, we upload it (callback for progress)
        $('#erpal-file-block-ajax .form-file').change( function(e) {
          
          ajaxFormElement   = $(sSelector+' .form-text.form-autocomplete');
          ajaxFormElement   = ajaxFormElement.last();
          ajaxFormElement.val( 'Uploading file...' );
          waitForAJAXUpload = setInterval( 'erpal_file_block_check_ajax_upload_progress()', 333 );
          
          $('#erpal-file-block-ajax .form-file')
            .siblings('.form-submit')
            .mousedown()
            .click()
            .mouseup();
          
        } );
        
      }
      
      var sSelector         = '.field-type-entityreference-form.field-name-field-asset-files-form.field-widget-inline-entity-form';
      var pInlineReferences = $(sSelector);
      var pFileField        = $( sSelector+' .form-file:not(.erpal-file-drag-drop-processed)' ); 
      if( pFileField.size() ) {
        
        var sID         = pFileField.attr("id");
        
        pFileField.addClass( 'erpal-file-drag-drop-processed' );
        
        addFileItem( sID, sSelector+' #'+sID, sID, pInlineReferences.find('fieldset>legend>span').text() );
        
        
      }
      else if( pInlineReferences.size() ) {
        
        pInlineReferences.find('#edit-field-asset-files-und-actions-ief-add')
          .mousedown()
          .click()
          .mouseup();
        
      }
      
    }
    
  };
  
})(jQuery);