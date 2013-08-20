/*
 * FileJS (v 0.1.0)
 * Copyright (c) 2012 Thiemo Müller
 * MORPOL Softwareentwicklung (filejs@morpol.de, www.morpol.de)
 * 
 * File JS encapsulates the features of the HTML5 File API and
 * adds advanced functionality like background/framed file uploads.
 * If you have any questions, bug reports or feature requests please
 * contact filejs@morpol.de
 * 
 * https://github.com/MORPOL/filejs
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

(function($,undefined) {
	
	$.extend( BoxJS.pTranslations['en'], {
		filejs					: {
			double_click_here		: 'Double-click here to upload a file.',
			click_here				: 'Click here to upload a file.',
			no_support				: 'Sorry, your browser doesn\'t support file handling!',
			drag_here				: 'You can also drop a file from your desktop here.',
			preview					: 'Preview',
			name					: 'Name',
			size					: 'Size',
			progress				: 'Progress',
			actions					: 'Actions',
			add_file				: 'Add file',
			upload_files			: 'Upload files',
			cancel_upload			: 'Cancel upload',
			no_file_selected		: 'Please select a file to continue.',
			one_file_selected		: 'You have selected one file.',
			multiple_files_selected	: 'You have selected [number] files.',
			dialog_add_file			: 'Please add files only in the tab where you started listing them ([title]).'
		}
	} );
	
	
	var iDragCounter	= 0;
	$( function() {
		
    if( window.INTER_TAB_JS.old_jquery )
      $('body')
        .bind( 'dragenter', null, function(e) {
          var pTarget	= $(e.target);
          if( !iDragCounter )
            $('body').addClass( 'filejs-dragging' );
          iDragCounter++;
        } )
        .bind( 'dragleave', null, function(e) {
          var pTarget	= $(e.target);
          if( !(--iDragCounter) )
            $('body').removeClass( 'filejs-dragging' );
        } );
		
	} );
	
	createClass( "FileJS.FileBox", "BoxJS.SimpleBox" );
	BoxJS.pBoxTypes.file							= FileJS.FileBox;
	FileJS.FileBox.prototype.pFile					= null;
	FileJS.FileBox.prototype.FileBox				= function( pBoxJS, pBoxData, iFrameMode ) {
		if( !pBoxData.pConfig )
			pBoxData.pConfig			= {};
		
		this.pFile					= pBoxData.pFile;
		
		if( !pBoxData.pConfig.html && this.pFile.type.substr(0,6)=='image/' && this.pFile.contents )
			pBoxData.pConfig.html		= '<div class="filejs-file-preview"><img src="'+this.pFile.contents.url+'" alt="'+this.pFile.name+'" /></div>';
		
		pBoxData.pConfig.caption	= this.pFile.name;
		
		this.SimpleBox( pBoxJS, pBoxData, iFrameMode );
		
		this.pContainer
			.addClass( 'filebox' );
		
		this.updateHeight();
		
		//this.pBoxJS.reorderInPageBoxes();
	};
	
	createClass( "FileJS.UploadBox", "BoxJS.SimpleBox" );
	BoxJS.pBoxTypes.upload							= FileJS.UploadBox;
	
	FileJS.FILE_ACTIONS	= new Flags( 'READ', 'UPLOAD' );
	FileJS.READ_AS		= new Enum( 'BINARY_STRING', 'TEXT', 'DATA_URL', 'ARRAY_BUFFER' );
	FileJS.STATES		= new Enum( 'NO_FILE_SELECTED', 'FILES_SELECTED', 'PROCESSING_FILES', 'FILES_PROCESSED', 'PROCESSING_FAILED' );
	
	FileJS.UploadBox.prototype.iMaxReadSize			= 1024*1024;
	FileJS.UploadBox.prototype.iFileActions			= 0;
	FileJS.UploadBox.prototype.iReadAs				= FileJS.READ_AS.BINARY_STRING;
	FileJS.UploadBox.prototype.sEncoding			= 'UTF-8';
	FileJS.UploadBox.prototype.sUploadURL			= null;
	FileJS.UploadBox.prototype.fProgress			= 0;
	FileJS.UploadBox.prototype.bProcessing			= 0;
	FileJS.UploadBox.prototype.iState				= FileJS.STATES.NO_FILE_SELECTED;
	FileJS.UploadBox.prototype.bAsyncUpload			= true;
	FileJS.UploadBox.prototype.pPages				= null;
	FileJS.UploadBox.prototype.aFiles				= null;
	FileJS.UploadBox.prototype._aFiles				= null;
	FileJS.UploadBox.prototype.bActiveFrame			= null;
	FileJS.UploadBox.prototype.iActiveFrame			= null;
	FileJS.UploadBox.prototype.sClassName			= 'FileJS.UploadBox';
	FileJS.UploadBox.prototype.UploadBox			= function( pBoxJS, pBoxData, iFrameMode ) {
		
		pBoxData	= this.ensureBoxData( pBoxJS, pBoxData, [ 'minimize', 'restore', 'maximize', 'close', 'add_file', 'upload_files', 'cancel_upload' ] );
		
		this.pBoxJS			= pBoxJS;
		this.cleanConfig( pBoxData );
		
		this.iFileActions	= this.pConfig.action=='read' ? FileJS.FILE_ACTIONS.READ : (this.pConfig.action=='upload' ? FileJS.FILE_ACTIONS.UPLOAD : (this.pConfig.action=='both' ? FileJS.FILE_ACTIONS.READ|FileJS.FILE_ACTIONS.UPLOAD : 0));
		this.iReadAs		= this.readAsToInt( this.pConfig.read_as );
		if( this.pConfig.encoding )
			this.sEncoding		= this.pConfig.encoding;
		if( this.pConfig.upload_url )
			this.sUploadURL		= this.pConfig.upload_url;
		
		this.iActiveFrame	= pBoxData.iActiveFrame;
		
		//this.EventEmitter();
		this.SimpleBox( pBoxJS, pBoxData, iFrameMode );
		
		this.pContainer
			.addClass( 'uploadbox' )
			.addClass( FileJS.bSupportsFileDrop ? 'supports-file-drop' : 'doesnt-support-file-drop' )
			.addClass( FileJS.bSupportsXHRFileUpload ? 'supports-xhr-file-upload' : 'doesnt-support-xhr-file-upload' )
			.addClass( FileJS.bSupportsFileInputDrop ? 'supports-file-input-drop' : 'doesnt-support-file-input-drop' );
		
		if( iFrameMode )
			this.initFramed();
		
		this.updateHeight();
	};
	FileJS.UploadBox.prototype.initFramed			= function() {
		
		var pBox	= this;
		
		this.bActiveFrame	= !this.iActiveFrame;
		
		this.pPages	= {
			pSelect		: this.pElements.pContents.find( '#filejs-select-form' ),
			pProgress	: this.pElements.pContents.find( '#filejs-progress-box' )
		};
		
		this.pElements.pContents
			.find('.message-drop-here')
			.text( this.pBoxJS.translate( 'filejs', 'drag_here' ) );
		
		this.pElements.pContents
			.find( '.drop-target' )
			.bind( 'dragover', function(e) {
				if( !pBox.bActiveFrame )
					return;
				
				e.stopPropagation();
				e.preventDefault();
			} )
			.bind( 'drop', function(e) {
				if( !pBox.bActiveFrame )
					return;
				
				if( e.originalEvent.dataTransfer && e.originalEvent.dataTransfer.files && e.originalEvent.dataTransfer.files.length ) {
					pBox.emit( 'selected', e.originalEvent.dataTransfer.files );
					
					iDragCounter	= 0;
					$('body').removeClass( 'filejs-dragging' );
				}
				
				e.stopPropagation();
				e.preventDefault();
			} );
		
		this.reset();
		
		this.on( 'selected', function( aFiles, bSuppressDefault ) {
			this.showProgress( aFiles );
			
			if( bSuppressDefault )
				return;
			
			if( this.iFileActions&FileJS.FILE_ACTIONS.READ )
				this.readFiles( aFiles );
			
			if( this.iFileActions&FileJS.FILE_ACTIONS.UPLOAD )
				this.uploadFiles( aFiles );
		}, this );
		
		this.on( 'progress', function( aFiles, aProgress, iActive ) {
			var fProgress	= 0;
			for( var i=0; i<aProgress.length; i++ )
				fProgress		+= aProgress[i];
			fProgress		/= aProgress.length;
			
			this.fProgress	= fProgress;
			
			this.updateProgress( aFiles, aProgress, iActive );
			/*this.pContents
				.find('.message-click-here')
				.text( Math.round(fProgress*100)+'%' );*/
		}, this );
		
		this.on( 'reading', function( aFiles ) {
			this.updateProgress( aFiles, null, 0 );
		}, this );
		
		this.on( 'uploading', function( aFiles ) {
			this.updateProgress( aFiles, null, 0 );
		}, this );
		
		function update( aFiles, aContents ) {
			var pBox	= this;
			
			for( var i=0; i<aContents.length; i++ ) {
				this.aFiles[i].contents	= aContents[i];
				/*var pRow	= this.pPages.pProgress.find( 'tbody>tr:eq('+aFiles[i].iIndex+')' );
				
				pRow.data( 'contents', aContents[i] );*/
			}
			
			this.updateActions( this.pConfig.actions );
			
			this.sync();
			//this.reset();
			
			this.emit( 'updated', aFiles, aContents );
		};
		
		this.on( 'read', update, this );
		this.on( 'uploaded', update, this );
		
		
		this.pPages.pSelect
			.find('.message-click-here')
			.text( FileJS.bSupportsFileInput ? (FileJS.bSupportsInputDoubleClick ? this.pBoxJS.translate( 'filejs', 'double_click_here' ) : this.pBoxJS.translate( 'filejs', 'click_here' )) : this.pBoxJS.translate( 'filejs', 'no_support' ) );
		
		
		var pProgress	= this.pPages.pProgress;
		
		
		pProgress.find( 'th.file-preview' ).text( this.pBoxJS.translate( 'filejs', 'preview' ) );
		pProgress.find( 'th.file-name' ).text( this.pBoxJS.translate( 'filejs', 'name' ) );
		pProgress.find( 'th.file-size' ).text( this.pBoxJS.translate( 'filejs', 'size' ) );
		pProgress.find( 'th.file-progress' ).text( this.pBoxJS.translate( 'filejs', 'progress' ) );
		pProgress.find( 'th.file-actions' ).text( this.pBoxJS.translate( 'filejs', 'actions' ) );
		
		function setupFileInput( pInput ) {
			return pInput
				.bind( 'change', function(e) {
					var pInput	= $(e.target);
					var pClone	= setupFileInput( pInput.clone() )
						.insertBefore( pInput );
					
					pInput
						.appendTo( pBox.pElements.pContents.find( 'form' ) )
						.attr( 'class', 'selected-file-input' )
						.attr( 'name', 'file-'+(pBox.aFiles?pBox.aFiles.length:0) )
						.hide();
					
					pBox.emit( 'selected', e.target.files );
				} )
				.click( function(e) {
					return true;
				} );
		}
		
		var pFileInput		= this.pPages.pSelect.find('.file-input');
		setupFileInput( pFileInput );
		
		var pAddFileInput	= pFileInput
			.clone()
			.appendTo( pProgress.find( '.actions>.boxjs-box-action-add_file' ) );
		setupFileInput( pAddFileInput );
		
		//this.updateHeight();
		
	};
	FileJS.UploadBox.prototype.registerStates		= function() {
		this.__parent.registerStates.apply( this, [] );
		
		this.pStates.state			= {
			attribute					: 'iState',
			state						: this.iState,
			classes						: [ 'filejs-no-files-selected', 'filejs-files-selected', 'filejs-processing', 'filejs-finished', 'filejs-failed' ]
		};
	};
	FileJS.UploadBox.prototype.registerActions		= function() {
		this.__parent.registerActions.apply( this, [] );
		
		this.pActions.add_file		= {
			caption						: this.pBoxJS.translate( 'filejs', 'add_file' ),
			container					: '.actions'
		};
		
		this.pActions.upload_files	= {
			caption						: this.pBoxJS.translate( 'filejs', 'upload_files' ),
			container					: '.actions'
		};
		
		this.pActions.cancel_upload	= {
			caption						: this.pBoxJS.translate( 'filejs', 'cancel_upload' ),
			container					: '.actions'
		};
	};
	FileJS.UploadBox.prototype.formatSize			= function( iSize ) {
		var sType;
		if( iSize>1024*1024*1024 ) {
			iSize	/= 1024*1024*1024;
			sType	= 'GiB';
		}
		else if( iSize>1024*1024 ) {
			iSize	/= 1024*1024;
			sType	= 'MiB';
		}
		else if( iSize>1024 ) {
			iSize	/= 1024;
			sType	= 'KiB';
		}
		else {
			sType	= 'B';
		}
		
		iSize	= Math.round( iSize*10 )/10;
		return iSize+' '+sType;
	};
	FileJS.UploadBox.prototype.updateProgress		= function( aFiles, aProgress, iActive ) {
		var pProgress	= this.pPages.pProgress;
		var pBody		= pProgress.find('tbody');
		pBody
			.find( 'tr:lt('+(iActive+1)+')>.file-progress>.progress-bar' )
			.removeClass( 'disabled' )
			.removeClass( 'active' )
			.addClass( 'enabled' );
		
		pBody
			.find('tr:eq('+iActive+')>.file-progress>.progress-bar')
			.addClass( 'active' );
		
		if( aProgress ) {
			for( var i=0; i<aProgress.length; i++ ) {
				pBody
					.find('tr:eq('+i+')>.file-progress .progress-bar-progress')
					.css( 'width', aProgress[i]*100+'%' )
					.text( Math.round( aProgress[i]*100 )+'%' );
			}
		}
	};
	FileJS.UploadBox.prototype.showProgress			= function( aFiles ) {
		
		if( !this.iActiveFrame ) {
			this.iActiveFrame	= this.pBoxJS.iParentFrameSessionID;
			this.bActiveFrame	= true;
		}
		
		this.setState( 'state', FileJS.STATES.FILES_SELECTED );
		
		if( !this.aFiles )
			this.aFiles		= [];
		if( !this._aFiles )
			this._aFiles	= [];
		
		for( var i=0, pFile; pFile=aFiles[i]; i++ ) {
			if( !pFile.index && !pFile.iIndex ) {
				pFile.iIndex	= this.aFiles.length;
				this.aFiles.push( { size:pFile.size, name:pFile.name, type:pFile.type, progress:null, contents:null, active:false, preview_url:null, index:pFile.iIndex } );
				this._aFiles.push( pFile );
			}
			else {
				while( this.aFiles.length<=pFile.index )
					this.aFiles.push( null );
				
				this.aFiles[pFile.index]	= pFile;
			}
		}
		
		var iSelected	= this.aFiles.length;
		this.pElements.pContents.find('.message').text( iSelected>1 ? this.pBoxJS.translate( 'filejs', 'multiple_files_selected', {number:iSelected} ) : this.pBoxJS.translate( 'filejs', 'one_file_selected' ) );
		
		var pProgress	= this.pPages.pProgress;
		
		var pBody		= pProgress.find('tbody');
		var aPreview	= [];
		this.pPages.pProgress.find('tbody').children().remove();
		for( var i=0, pFile; pFile=this.aFiles[i]; i++ ) {
			var pRow		= $('<tr />')
				.data( 'file', pFile )
				.addClass( i%2 ? 'odd' : 'even' )
				.appendTo( pBody );
			
			var pColumn		= $('<td class="file-preview" />')
				.appendTo( pRow );
			
			if( pFile.type.substr(0,6)=='image/' ) {
				pRow.addClass( 'has-preview' );
				if( pFile.preview_url ) {
					pColumn
						.html( '<img src="'+pFile.preview_url+'" alt="'+pFile.name+'" />' );
				}
				else if( this.bActiveFrame ) {
					pRow
						.addClass( 'preview-'+aPreview.length );
					aPreview.push( this._aFiles[i] );
				}
			}
			
			$('<td class="file-name" />')
				.append( $('<div class="contents" />').text( pFile.name ) )
				.appendTo( pRow );
			
			$('<td class="file-size" />')
				.append( $('<div class="contents" />').text( this.formatSize( pFile.size ) ) )
				.appendTo( pRow );
			
			var pColumn		= $('<td class="file-progress" />')
				.appendTo( pRow );
			var pBar		= $('<div class="progress-bar"></div>')
				.appendTo( pColumn );
			if( pFile.progress===null )
				pBar.addClass('disabled');
			else {
				pBar.addClass('enabled');
				if( pFile.active )
					pBar.addClass( 'active' );
			}
			var pProgress	= $('<div class="progress-bar-progress"></div>')
				.appendTo( pBar );
			if( pFile.progress!==null )
				pProgress
					.css( 'width', pFile.progress*100+'%' )
					.text( Math.round( pFile.progress*100 )+'%' )
			
			$('<td class="file-actions" />')
				.appendTo( pRow );
		}
		
		var pBox	= this;
		if( aPreview.length ) {
			this.readFiles( aPreview, function( _, aResult ) {
				for( var i=0, sURL; sURL=aResult[i]; i++ ) {
					pBox.aFiles[ aPreview[i].iIndex ].preview_url	= sURL;
					var pRow	= pBody
						.find('.preview-'+i);
					pRow.find('.file-preview')
						.html( '<img src="'+sURL+'" alt="'+pRow.find('.file-name .contents').html()+'" />' );
				}
				
				pBox.updateHeight();
			}, FileJS.READ_AS.DATA_URL );
		}
		
		if( this.bActiveFrame )
			this.updateHeight();
		
	};
	FileJS.UploadBox.prototype.reset				= function() {
		this.aFiles		= null;
		this._aFiles	= null;
		this.fProgress	= 0;
		var pBox		= this;
		
		this.pElements.pContents.find('.message').text( this.pBoxJS.translate( 'filejs', 'no_file_selected' ) );
		
		this.setState( 'state', FileJS.STATES.NO_FILE_SELECTED, this.iState==FileJS.STATES.NO_FILE_SELECTED );
		//this.updateHeight();
		
	};
	FileJS.UploadBox.prototype.readAsToInt			= function( sReadAs ) {
		return sReadAs=='text' ? FileJS.READ_AS.TEXT : (sReadAs=='data_url' ? FileJS.READ_AS.DATA_URL : (sReadAs=='array_buffer' ? FileJS.READ_AS.ARRAY_BUFFER : FileJS.READ_AS.BINARY_STRING))
	};
	FileJS.UploadBox.prototype.readAsToString		= function( iReadAs ) {
		return iReadAs==FileJS.READ_AS.TEXT ? 'text' : (iReadAs==FileJS.READ_AS.DATA_URL ? 'data_url' : (iReadAs==FileJS.READ_AS.ARRAY_BUFFER ? 'array_buffer' : 'binary_string'));
	};
	FileJS.UploadBox.prototype.readFiles			= function( aFiles, pCallback, iReadAs ) {
		if( iReadAs===undefined )
			iReadAs	= this.iReadAs;
		
		if( !FileJS.bSupportsFileReader )
			return this.uploadFiles( aFiles, this.readAsToString(iReadAs), pCallback );
		
		if( !pCallback ) {
			if( this.bProcessing )
				return false;
			
			this.setState( 'state', FileJS.STATES.PROCESSING_FILES );
			this.emit( 'reading', aFiles );
		}
		
		var aResults	= [];
		var iProcessed	= 0;
		var pBox		= this;
		var aProgress	= [];
		
		for( var i=0, pFile; pFile=aFiles[i]; i++ ) {
			
			aResults.push( null );
			aProgress.push( 0 );
			
			if( pFile.size>this.iMaxReadSize )
				continue;
			
			(function(pFile,iIndex) {
				var pReader		= new FileReader();
				
				pReader.onloadend	= function( e ) {
					
					if( pReader.error ) {
						aResults[iIndex]	= pReader.error;
					}
					else {
						aResults[iIndex]	= this.result;
					}
					
					if( (++iProcessed)==aResults.length ) {
						if( pCallback )
							pCallback( aFiles, aResults );
						else {
							for( var i=0; i<aProgress.length; i++ )
								aProgress[i]	= 1;
							pBox.emit( 'progress', aFiles, aProgress, i );
							pBox.setState( 'state', FileJS.STATES.FILES_PROCESSED );
							pBox.emit( 'read', aFiles, aResults );
						}
					}
				};
				if( !pCallback ) {
					pReader.onprogress	= function( e ) {
						if( !e.lengthComputable )
							return;
						
						aProgress[ iIndex ]	= e.loaded / e.total;
						pBox.emit( 'progress', aFiles, aProgress, iIndex );
					};
				}
				
				if( iReadAs==FileJS.READ_AS.TEXT )
					pReader.readAsText( pFile, pBox.sEncoding );
				else if( iReadAs==FileJS.READ_AS.ARRAY_BUFFER )
					pReader.readAsArrayBuffer( pFile );
				else if( iReadAs==FileJS.READ_AS.DATA_URL )
					pReader.readAsDataURL( pFile );
				else
					pReader.readAsBinaryString( pFile );
				
			})( pFile, i );
			
		}
		
	};
	FileJS.UploadBox.prototype.getPostData			= function( aFiles, sBoundary, pCallback ) {
		var aParts	= [];
		var NL		= "\r\n";
		
		for( var i=0, pFile; pFile=aFiles[i]; i++ ) {
			(function(pFile) {
				sPart	= "";
				sPart	+= 'Content-Disposition: form-data; ';
				sPart	+= 'name="file-' + i + '"; ';
				sPart	+= 'filename="'+ pFile.name + '"' + NL;
				sPart	+= "Content-Type: application/octet-stream";
				sPart	+= NL + NL;
				sPart	+= aFiles[i].getAsBinary() + NL;
				
				aParts.push( sPart );
			})(pFile);
		}
		
		sPart	= "";
		sPart	+= 'Content-Disposition: form-data; ';
		sPart	+= 'name="file-count"' + NL + NL;
		sPart	+= i + NL;
		aParts.push( sPart );
		
		var sResult	=	"--" + sBoundary + NL +
						aParts.join( "--" + sBoundary + NL ) +
						"--" + sBoundary + "--" + NL;
		
		return sResult;
	};
	FileJS.UploadBox.prototype.uploadFiles			= function( aFiles, sReadAs, pCallback, pProgress ) {
		if( !aFiles )
			aFiles	= this._aFiles;
		
		if( !pCallback ) {
			if( this.bProcessing )
				return false;
			
			this.setState( 'state', FileJS.STATES.PROCESSING_FILES );
			this.emit( 'uploading', aFiles );
		}
		
		var aProgress	= [];
		var pBox			= this;
		var sEvent			= sReadAs ? 'read' : 'uploaded';
		
		if( aFiles.length>1 && this.bAsyncUpload ) {
			
			var aResults	= [];
			var iRemaining	= aFiles.length;
			
			for( var i=0, pFile; pFile=aFiles[i]; i++ ) {
				aProgress.push( 0 );
				aResults.push( null );
				
				(function(pFile,iIndex) {
					
					pBox.uploadFiles( [pFile], sReadAs, function( _aFiles, _aResults ) {
						if( _aResults )
							aResults[iIndex]	= _aResults[0];
						
						if( !(--iRemaining) ) {
							if( pCallback )
								pCallback( aFiles, aResults );
							else
								pBox.emit( sEvent, aFiles, aResults );
						}
					}, function( _aFiles, _aProgress, _iIndex ) {
						aProgress[iIndex]	= _aProgress[0];
						
						if( !pCallback )
							pBox.emit( 'progress', aFiles, aProgress, iIndex );
						else if( pProgress )
							pProgress( aFiles, aProgress, iIndex );
					} );
					
				})(pFile,i);
			}
			return;
		}
		
		var pFormData	= new FormData();
		//var pFormData	= {};
		var iSizeAdded	= 0;
		var iSizeIndex	= 0;
		var aSizes		= [];
		
		for( var i=0, pFile; pFile=aFiles[i]; ++i ) {
			aProgress.push( 0 );
			aSizes.push( pFile.size );
			pFormData.append( "file-"+i, pFile, pFile.name );
			//pFormData["file-"+i]	= pFile;
		}
		
		pFormData.append( "file-count", i );
		//pFormData["file-count"]	= i;
		
		/*var sBoundary	= '';
		for( var i=0; i<32; i++ ) {
			var iChar	= Math.floor( Math.random() * 62 );
			sBoundary	+= iChar>=52 ? String.fromCharCode(iChar-52+48) : (iChar>=26 ? String.fromCharCode(iChar-26+65) : String.fromCharCode(iChar+97));
		}
		
		$.ajax( {
			type		: 'POST',
			url			: sReadAs ? this.sUploadURL+(this.sUploadURL.indexOf(/\?/)>=0?'&':'?')+'read_as='+sReadAs+'&encoding='+this.sEncoding : this.sUploadURL,
			data		: this.getPostData( aFiles, sBoundary ),//pFormData,
			processData	: false,
			headers		: {
				"Content-type"	: "multipart/form-data; boundary=" + sBoundary
			},
			xhr			: function() {
				pXHR = $.ajaxSettings.xhr();
				
				if( pXHR.upload && (!pCallback || pProgress) ) {
					
					pXHR.upload.addEventListener( 'progress', function( e ) {
						
						if( !e.lengthComputable || iSizeIndex>aProgress.length )
							return;
						
						var iMax	= aSizes[ iSizeIndex ];
						var iSize	= e.loaded - iSizeAdded;
						if( iSize>=iMax ) {
							iSizeAdded	+= aSizes[ iSizeIndex ];
							iSize		-= aSizes[ iSizeIndex ];
							aProgress[ iSizeIndex ]	= 1;
							iSizeIndex++;
						}
						
						if( iSizeIndex<aProgress.length )
							aProgress[ iSizeIndex ]	= iSize / aSizes[iSizeIndex];
						
						if( pProgress )
							pProgress( aFiles, aProgress, iSizeIndex );
						else
							pBox.emit( 'progress', aFiles, aProgress, iSizeIndex );
						
					}, false);
					
				}
				else
					console.log( 'No progress possible...' );
				
				return pXHR;
			},
			/ *beforeSend	: function( pRequest ) {
				
				pRequest.upload.addEventListener("progress", function(e){
					
					if( !e.lengthComputable || iSizeIndex>aProgress.length )
						return;
					
					var iMax	= aSizes[ iSizeIndex ];
					var iSize	= e.loaded - iSizeAdded;
					if( iSize>=iMax ) {
						iSizeAdded	+= aSizes[ iSizeIndex ];
						iSize		-= aSizes[ iSizeIndex ];
						aProgress[ iSizeIndex ]	= 1;
						iSizeIndex++;
					}
					
					if( iSizeIndex<aProgress.length )
						aProgress[ iSizeIndex ]	= iSize / aSizes[iSizeIndex];
					
					pBox.emit( 'progress', aFiles, aProgress, iSizeIndex );
					
				}, false);
				
			},* /
			error		: function() {
				if( pCallback ) {
					pCallback( aFiles, null );
				}
				else {
					pBox.setState( 'state', FileJS.STATES.PROCESSING_FAILED );
					pBox.emit( sEvent, aFiles, null );
				}
			},
			success		: function( pData ){
				var pResult			= pData;
				var aResults		= pResult.contents;
				if( pCallback ) {
					pCallback( aFiles, aResults );
				}
				else {
					pBox.setState( 'state', FileJS.STATES.FILES_PROCESSED );
					pBox.emit( sEvent, aFiles, aResults );
				}
			}
		} );*/
		
		var pFormData	= new FormData();
		var aProgress	= [];
		var iSizeAdded	= 0;
		var iSizeIndex	= 0;
		var aSizes		= [];
		
		for( var i=0, pFile; pFile=aFiles[i]; ++i ) {
			aProgress.push( 0 );
			aSizes.push( pFile.size );
			pFormData.append( "file-"+i, pFile, pFile.name );
		}
		
		pFormData.append( "file-count", i );
		
		var pBox			= this;
		var sEvent			= sReadAs ? 'read' : 'uploaded';
		var pXHR			= new XMLHttpRequest();
		pXHR.open( 'POST', sReadAs ? this.sUploadURL+(this.sUploadURL.indexOf(/\?/)>=0?'&':'?')+'read_as='+sReadAs : this.sUploadURL, true );
		//pXHR.setRequestHeader( 'Content-Type', "multipart/form-data" );
		pXHR.onload			= function( e ) {
			var pResult			= JSON.parse( this.responseText );
			var aResults		= pResult.contents;
			
			pBox.setState( 'state', FileJS.STATES.FILES_PROCESSED );
			
			if( pCallback )
				pCallback( aFiles, aResults );
			else {
				for( var i=0; i<aProgress.length; i++ )
					aProgress[i]	= 1;
				pBox.emit( 'progress', aFiles, aProgress, i );
				pBox.emit( sEvent, aFiles, aResults );
			}
		};
		if( pXHR.upload ) {
			pXHR.upload.onprogress		= function( e ) {
				if( !e.lengthComputable || iSizeIndex>aProgress.length )
					return;
				
				var iMax	= aSizes[ iSizeIndex ];
				var iSize	= e.loaded - iSizeAdded;
				if( iSize>=iMax ) {
					iSizeAdded	+= aSizes[ iSizeIndex ];
					iSize		-= aSizes[ iSizeIndex ];
					aProgress[ iSizeIndex ]	= 1;
					iSizeIndex++;
				}
				
				if( iSizeIndex<aProgress.length )
					aProgress[ iSizeIndex ]	= iSize / aSizes[iSizeIndex];
				
				if( pProgress )
					pProgress( aFiles, aProgress, iSizeIndex );
				else if( !pCallback )
					pBox.emit( 'progress', aFiles, aProgress, iSizeIndex );
			};
		}
		pXHR.onerror		= function(e) {
			if( pCallback )
				pCallback( aFiles, null );
			else {
				pBox.setState( 'state', FileJS.STATES.PROCESSING_FAILED );
				pBox.emit( sEvent, aFiles, null );
			}
		};
		pXHR.onabort		= function(e) {
			if( pCallback )
				pCallback( aFiles, null );
			else {
				pBox.setState( 'state', FileJS.STATES.PROCESSING_FAILED );
				pBox.emit( sEvent, aFiles, null );
			}
		};
		
		pXHR.send( pFormData );
	};
	FileJS.UploadBox.prototype.cleanConfig			= function( pBoxData ) {
		var pConfig	= pBoxData.pConfig;
		delete pConfig.text;
		delete pConfig.html;
		delete pConfig.url;
		delete pConfig.element;
		
		pConfig.url		= this.pBoxJS.getFrameURL( (this.sID?this.sID:(pBoxData.sID?pBoxData.sID:pConfig.id)) );
		pConfig.html	= '\
	<div id="filejs-progress-box">\
		<div class="message"></div>\
		<table class="list">\
			<thead>\
				<tr><th class="file-preview"></th><th class="file-name"></th><th class="file-size"></th><th class="file-progress"></th><th class="file-actions"></th></tr>\
			</thead>\
			<tbody>\
			</tbody>\
		</table>\
		<div id="filejs-select-form">\
			<form action=""  method="post" enctype="multipart/form-data">\
				<div class="message-click-here"></div>\
				<div class="message-drop-here"></div>\
				<input class="hidden-input" type="hidden" name="file-count" value="1" />\
				<input class="file-input" type="file" name="file" size="50" />\
			</form>\
		</div>\
		<div class="drop-target"></div>\
		<div class="actions"></div>\
	</div>';
	};
	FileJS.UploadBox.prototype.setState				= function( sName, mState, bDontSync ) {
		if( sName=='state' && mState==FileJS.STATES.FILES_PROCESSED && bDontSync ) {
			this.highlightBox();
		}
		
		this.__parent.setState.apply( this, arguments );
	};
	FileJS.UploadBox.prototype.setSyncData			= function( pData ) {
		
		var pConfig			= pData.pConfig;
		
		this.iFileActions	= pConfig.action=='read' ? FileJS.FILE_ACTIONS.READ : (pConfig.action=='upload' ? FileJS.FILE_ACTIONS.UPLOAD : (pConfig.action=='both' ? FileJS.FILE_ACTIONS.READ|FileJS.FILE_ACTIONS.UPLOAD : 0));
		this.iReadAs		= this.readAsToInt( pConfig.read_as );
		this.sEncoding		= pConfig.encoding;
		this.sUploadURL		= pConfig.upload_url;
		this.fProgress		= pConfig.progress;
		this.iActiveFrame	= pData.iActiveFrame;
		
		if( pData.iActiveFrame )
			this.bActiveFrame	= pData.iActiveFrame==this.pBoxJS.iParentFrameSessionID || pData.iActiveFrame==this.pBoxJS.getSessionID();
		
		if( pData.sActivePageTitle )
			this.sCantAddFileDialogBody	= this.pBoxJS.translate( 'filejs', 'dialog_add_file', {title:pData.sActivePageTitle} );
		
		this.aContents		= pData.aContents;
		if( pData.aFiles ) {
			if( !this.aFiles ) {
				if( !this.bActiveFrame ) {
					if( this.iFrameMode )
						this.showProgress( pData.aFiles );
					
					if( !this.pContainer.hasClass( 'filejs-inactive' ) )
						this.pContainer.addClass( 'filejs-inactive' );
					
					//this.updateProgress( pData.aFiles );
				}
				else
					this.aFiles			= pData.aFiles;
			}
			else if( this.iFrameMode && !this.bActiveFrame ) {
				if( pData.aFiles.length>this.aFiles.length )
					this.showProgress( pData.aFiles.slice( this.aFiles.length ) );
			}
			else {
				this.aFiles			= pData.aFiles;
			}	
		}
		
		if( this.bActiveFrame && !this.iFrameMode ) {
			if( pData.pRuntime.state==FileJS.STATES.PROCESSING_FILES && this.pStates.state.state<FileJS.STATES.PROCESSING_FILES && this._aFiles ) {
				this.uploadFiles();
			}
		}
		
		this.__parent.setSyncData.apply( this, arguments );
	};
	FileJS.UploadBox.prototype.getSyncData			= function() {
		var pData		= this.__parent.getSyncData.apply( this, [] );
		var pConfig		= pData.pConfig;
		
		this.cleanConfig( pData );
		
		if( this.bActiveFrame && !this.iFrameMode )
			pData.sActivePageTitle	= $('head>title').text();
		
		pConfig.action		= this.iFileActions&FileJS.FILE_ACTIONS.READ ? (this.iFileActions&FileJS.FILE_ACTIONS.UPLOAD ? 'both' : 'read') : (this.iFileActions&FileJS.FILE_ACTIONS.UPLOAD ? 'upload' : 'none');
		pConfig.read_as		= this.readAsToString( this.iReadAs );
		pConfig.encoding	= this.sEncoding;
		pConfig.upload_url	= this.sUploadURL;
		pConfig.progress	= this.fProgress;
		
		pData.aContents		= this.aContents;
		pData.aFiles		= this.aFiles;
		
		pData.iActiveFrame	= this.iActiveFrame;
		
		return pData;
	};
	FileJS.UploadBox.prototype.handleAction			= function( sAction, pContainer, bDontSync ) {
		if( sAction=='upload_files' ) {
			if( !this.bActiveFrame ) {
				this.setState( 'state', FileJS.STATES.PROCESSING_FILES );
			}
			else {
				this.uploadFiles();
			}
			
			return true;
		}
		else if( sAction=='add_file' ) {
			if( !this.bActiveFrame ) {
				this.openDialog( this.sCantAddFileDialogBody, {dialog_close:this.pBoxJS.translate( 'box', 'dialog_button_ok' )} );
			}
			
			return false;
		}
		else if( sAction=='close' ) {
			if( this.bProcessing && !confirm('This box is still reading a file. Are you sure you want to close it?') )
				return false;
		}
		
		return this.__parent.handleAction.applyEx( this, arguments, FileJS.UploadBox );
	};
	
	
	FileJS.bSupportsFileInput			= false;
	FileJS.bSupportsInputDoubleClick	= false;
	FileJS.bSupportsFileInputDrop		= false;
	FileJS.bSupportsFileDrop			= false;
	FileJS.bSupportsXHRFileUpload		= false;
	FileJS.bSupportsFileReader			= false;
	
	(function() {
		
		// For features that can't be tested (and aren't of a big importance)
		var bMSIE		= navigator.userAgent.indexOf( 'MSIE' )>=0;
		var bFirefox	= navigator.userAgent.indexOf( 'Firefox' )>=0;
		var bChrome		= navigator.userAgent.indexOf( 'Chrome' )>=0;
		
		FileJS.bSupportsFileInput			= Modernizr.fileinput;
		FileJS.bSupportsInputDoubleClick	= bMSIE;
		FileJS.bSupportsFileInputDrop		= bFirefox || bChrome;
		
		FileJS.bSupportsFileDrop			= Modernizr.draganddrop;
		FileJS.bSupportsFileReader			= Modernizr.filereader;
		
		FileJS.bSupportsXHRFileUpload		= Modernizr.xhr2;
		
	})();
	
	
})(jQuery);
