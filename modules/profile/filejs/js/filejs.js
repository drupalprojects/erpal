		jQuery.extend( BoxJS.pTranslations['en'], {
      drupal					: {
        view            : 'View',
        edit            : 'Edit',
        'delete'        : 'Delete'
      }
    } );
    
    createClass( 'Drupal.NodeBox', 'FileJS.FileBox' );
		BoxJS.pBoxTypes.drupal_nodebox                = Drupal.NodeBox;
		Drupal.NodeBox.aReferencableDropTargets				= [ '.field-widget-entityreference-autocomplete .references-dialog-insert', '.field-widget-entityreference-autocomplete .form-type-textfield' ];
		Drupal.NodeBox.getReferencableDropTargets			= function( sNodeType ) {
			var sClasses	= '';
			var aTargets	= Drupal.NodeBox.aReferencableDropTargets;
			var aTypes		= [ ' .node-type-'+sNodeType.replace( /_/g, "-" ), ' .no-node-type' ];
			for( var i=0; i<aTargets.length; i++ )
				for( var n=0; n<aTypes.length; n++ )
					sClasses	+= aTargets[i] + aTypes[n] + ', ';
			
			return sClasses.substr( 0, sClasses.length-2 );
		};
		Drupal.NodeBox.prototype.sUploadURL           = '';
		Drupal.NodeBox.prototype.sClassName           = 'Drupal.NodeBox';
		Drupal.NodeBox.prototype.pNode                = null;
		Drupal.NodeBox.prototype.NodeBox              = function( pBoxJS, pBoxData, iFrameMode ) {
      pBoxData	= this.ensureBoxData( pBoxJS, pBoxData, [ 'minimize', 'restore', 'maximize', 'close' ] );
      
      pBoxData.pConfig.html = '<a href="#" class="view-node"> </a> <a href="#" class="edit-node"> </a> <a href="#" class="delete-node"> </a> <div class="preview"></div>';
      
      this.pNode  = pBoxData.pNode ? pBoxData.pNode : (pBoxData.pConfig.node ? pBoxData.pConfig.node : pBoxData.pFile.contents.node);
      pBoxData.mDropTargets = Drupal.NodeBox.getReferencableDropTargets( this.pNode.type );
      
      this.FileBox( pBoxJS, pBoxData, iFrameMode );
      
      this.pContainer.addClass( 'nodebox' );
      
      this.pElements.pContents.find( '.view-node' )
        .attr( 'href', Drupal.settings.basePath + 'node/' + this.pNode.nid )
        .text( this.pBoxJS.translate( 'drupal', 'view' ) );
      
      this.pElements.pContents.find( '.edit-node' )
        .attr( 'href', Drupal.settings.basePath + 'node/' + this.pNode.nid + '/edit' )
        .text( this.pBoxJS.translate( 'drupal', 'edit' ) );
      
      this.pElements.pContents.find( '.delete-node' )
        .attr( 'href', Drupal.settings.basePath + 'node/' + this.pNode.nid + '/delete' )
        .text( this.pBoxJS.translate( 'drupal', 'delete' ) );
			
			if( this.pFile && this.pFile.contents && this.pFile.contents.url ) {
				if( this.pFile.contents.type.substr(0,6)=='image/' )
					this.pElements.pContents.find( '.preview' )
						.html( '<img src="'+this.pFile.contents.url+'" alt="Preview" />' );
				else
					this.pElements.pContents.find( '.preview' )
						.html( '<embed src="'+this.pFile.contents.url+'" type="'+this.pFile.contents.type+'" width="100%" height="100%">' );
			}
			else {
				this.pElements.pContents.find( '.preview' )
					.hide();
			}
    };
		Drupal.NodeBox.prototype.setSyncData		      = function( pData ) {
			
			this.pNode  = pData.pNode;
			this.pFile  = pData.pFile;
			
			this.__parent.setSyncData.apply( this, arguments );
		};
		Drupal.NodeBox.prototype.getSyncData		      = function() {
			var pData		= this.__parent.getSyncData.apply( this, [] );
			
			pData.pNode	  = this.pNode;
			pData.pFile	  = this.pFile;
			pData.sClass	= this.sClassName;
			
			return pData;
		};
    
    Drupal.NodeBox.close  = function( iNodeID ) {
      for( var iID in BoxJS.INSTANCES ) {
        var aBoxes  = BoxJS.INSTANCES[iID].aInPageBoxes;
        
        for( var i=0; i<aBoxes.length; i++ )
          if( aBoxes[i].instanceOf( Drupal.NodeBox ) && aBoxes[i].pNode.nid==iNodeID )
            aBoxes[i].handleAction( 'close' );
      }
    };
    
    createClass( 'Drupal.FileJSBox', 'FileJS.UploadBox' );
		BoxJS.pBoxTypes.drupal_filebox                = Drupal.FileJSBox;
		Drupal.FileJSBox.prototype.iMaxReadSize				= 1024 * 32;
		Drupal.FileJSBox.prototype.sUploadURL         = '';
		Drupal.FileJSBox.prototype.sClassName         = 'Drupal.FileJSBox';
		Drupal.FileJSBox.prototype.aPreviewFiles      = null;
    Drupal.FileJSBox.prototype.bAsyncUpload       = false;
		Drupal.FileJSBox.prototype.FileJSBox          = function( pBoxJS, pBoxData, iFrameMode ) {
			pBoxData	= this.ensureBoxData( pBoxJS, pBoxData, [ 'minimize', 'restore', 'maximize', 'close', 'add_file', 'upload_files', 'cancel_upload', 'view_file' ] );
			
			this.aPreviewFiles	= [];
			
			this.UploadBox( pBoxJS, pBoxData, iFrameMode );
			
			this.on( 'updated', function(aFiles,aContents) {
				if( this.pConfig.action=='upload' ) {
					this.aPreviewFiles	= this.aFiles;
					this.sync();
				}
			}, this );
		};
		Drupal.FileJSBox.prototype.registerActions	= function() {
			this.__parent.registerActions.apply( this, [] );
			
			this.pActions.view_file		= {
				caption						: 'View',
				container					: 'tr.has-preview>td.file-actions'
			};
		};
		Drupal.FileJSBox.prototype.handleAction		= function( sAction, pContainer ) {
			if( sAction=='view_file' ) {
				var pRow	= pContainer.parent();
				var pFile	= pRow.data( 'file' );
				
				if( pFile.contents ) {
					for( var i=0; i<this.aPreviewFiles.length; i++ ) {
						if( this.aPreviewFiles[i].contents.url==pFile.contents.url )
							break;
					}
					
					if( i==this.aPreviewFiles.length ) {
						this.aPreviewFiles.push( pFile );
						this.sync();
					}
				}
				
				return true;
			}
			
			return this.__parent.handleAction.applyEx( this, arguments, Drupal.FileJSBox );
		};
		Drupal.FileJSBox.prototype.setSyncData		= function( pData ) {
			
			this.aPreviewFiles	= pData.aPreviewFiles;
			
			if( this.aPreviewFiles.length && !this.iFrameMode ) {
				var pBox	= null;
        console.log( this.aPreviewFiles );
				for( var i=0, pFile; pFile=this.aPreviewFiles[i]; i++ ) {
					if( !pFile.preview_box /*&& pFile.type.substr(0,6)=='image/'*/ && pFile.contents && pFile.contents.node ) {
						var pBoxData		  = { pConfig:{ sync:this.pConfig.action=='upload', node:pFile.contents.node, caption:pFile.contents.node.title }, pFile:pFile };
						pBox				      = this.pBoxJS.createBox( pBoxData, 'drupal_nodebox' );
						pFile.preview_box	= pBoxData.sID;
						
						if( i==this.aPreviewFiles.length-1 && this.pStates.maximized.state ) {
							//this.handleAction( 'restore' );
							
							//pBox.handleAction( 'maximize' );
						}
					}
				}
				
				if( this.pConfig.action=='upload' )
					this.destroy();
				else if( pBox )
					this.sync();
			}
			
			this.__parent.setSyncData.apply( this, arguments );
		};
		Drupal.FileJSBox.prototype.getSyncData		= function() {
			var pData		= this.__parent.getSyncData.apply( this, [] );
			
			pData.aPreviewFiles	= this.aPreviewFiles;
			
			return pData;
		};

(function($) {
  
  Drupal.behaviors.filejs = {
    attach  : function( context, settings ) {
			var sSelector	= Drupal.NodeBox.aReferencableDropTargets.join( ' input, ' ) + ' input';
      $(sSelector,context).live( 'box_drop', function(e,pBox) {
        var sValue  = pBox.pNode.title + ' ('+pBox.pNode.nid+')';
        //console.log( sValue );
        $(e.target).val( sValue );
        $(e.target).change();
      } ); 
    }
  };
  
  $( function() {
    Drupal.FileJSBox.prototype.sUploadURL = Drupal.settings.basePath + 'filejs/upload';
  } );
  
})(jQuery);