/*
 * inter-tab-js (v 0.1.0-beta)
 * Copyright (c) 2012 Thiemo Müller
 * MORPOL Softwareentwicklung (inter-tab-js@morpol.de, www.morpol.de)
 * 
 * A framework allowing you to communicate between tabs/windows of the
 * same (i.e. your) origin using sessionStorage, localStorage or cookies.
 * Requires web-filesystem and createClass as well as jQuery.
 * If you have any questions, bug reports or feature requests please
 * contact inter-tab-js@morpol.de
 * 
 * https://github.com/MORPOL/inter-tab-js
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
	
	var aParts	= $.fn.jquery.split( '.' );
	var bOldJQuery						= aParts[0]=='1' && parseInt(aParts[1])<7;
	var iLocalID						= 1;
	window.INTER_TAB_JS					= {
		old_jquery							: bOldJQuery,
		local_id							: 1,
		instances							: [],
		UPDATE_INTERVAL						: 333,
		CACHE_TIME							: 10000,
		global_session_data					: {
			aLocalSessions						: []
		},
		findInstanceByPrefix				: function( sPrefix, pHandlers ) {
			for( var i=0; i<this.instances.length; i++ )
				if( this.instances[i].sPrefix==sPrefix )
					return this.instances[i];
			
			if( pHandlers )
				return new InterTabJS( sPrefix, pHandlers );
			
			return null;
		},
		init								: function() {
			
			if( !INTER_TAB_JS.instance )
				INTER_TAB_JS.instance	= new InterTabJS();
			
		}
	};
	
	function getTimeStamp() {
		return (new Date()).getTime();
	}
	
	createClass( "InterTabJS" );
	InterTabJS.getTimeStamp					= getTimeStamp;
	InterTabJS.prototype.sPrefix			= null;
	InterTabJS.prototype.pStorage			= null;
	InterTabJS.prototype.bStorageEvent		= true;
	InterTabJS.prototype.sTestData			= "storage-event-test-";
	InterTabJS.prototype.aHandlers			= null;
	InterTabJS.prototype.pHandlers			= null;
	InterTabJS.prototype.iLocalID			= 0;
	InterTabJS.prototype.iCheckForUpdates	= 0;
	InterTabJS.prototype.pCache				= null;
	InterTabJS.prototype.pSessionData		= null;
	InterTabJS.prototype.iSessionID			= null;
	InterTabJS.prototype.pSessions			= null;
	InterTabJS.prototype.sEncoding			= "utf8";
	InterTabJS.prototype.InterTabJS			= function( sPrefix, pHandlers ) {
		this.iLocalID		= INTER_TAB_JS.local_id++;
		
		this.sPrefix		= typeof sPrefix=='undefined' ? 'inter-tab-js' : sPrefix;
		this.pStorage		= new FileSystem.HTMLWebStorageRWEFileSystem( this.sPrefix+"/[filename]" );
		
		this.pCache			= {};
		this.pHandlers		= pHandlers ? pHandlers : { events:{} };
		this.aHandlers		= [];
		
		this.pSessionData	= {};
		
		if( bOldJQuery )
			$(window).bind( "storage", {pHandler:this}, InterTabJS.onStorage );
		else
			$(window).on( "storage", null, {pHandler:this}, InterTabJS.onStorage );
		
		var pSelf		= this;
		this.sTestData	+= this.iLocalID + '-' + getTimeStamp();
		
		/*this.pStorage.writeFile( this.sTestData, this.sTestData, pSelf.sEncoding, function() {
			
			pSelf.pStorage.readFile( pSelf.sTestData, pSelf.sEncoding, function(sData) {
				
				if( sData!=pSelf.sTestData )
					console.error( "WebFileSystem doesn't store data correctly!", pSelf.sTestData, sData );*/
				
				pSelf.init();
				
			/*} );
			
		} );*/
		
	};
	InterTabJS.prototype.$InterTabJS		= function() {
		if( this.iCheckForUpdates ) {
			clearInterval( this.iCheckForUpdates );
			this.iCheckForUpdates	= null;
		}
		
		INTER_TAB_JS.global_session_data.aLocalSessions.findAndRemove( this.iSessionID );
	};
	InterTabJS.prototype.addHandler			= function( sName, pConfig, bDontInit ) {
		
		var pHandler	= new InterTabJS.Handler.pTypes[ sName ]( this, pConfig );
		
		this.aHandlers.push( pHandler );
		this.pHandlers[sName]	= pHandler;
		
		if( !bDontInit )
			this.initHandler( pHandler );
		
		return pHandler;
		
	};
	InterTabJS.prototype.initHandler		= function( pHandler ) {
		
		var pSelf		= this;
		this.pStorage.readFile( pHandler.sKey, this.sEncoding, function(sData) {
			
			var pData	= null;
			if( sData ) {
				pData	= JSON.parse( sData );
				
				pHandler.init( pData.mData, pData.iChanged, pData.iSessionID );
			}
			else {
				pHandler.init( null, null, null );
			}
			
			pSelf.pCache[ pHandler.sKey ]	= sData;
			
		} );
		
	};
	InterTabJS.prototype.reset				= function( bSessionsAsWell ) {
		for( var sName in this.pHandlers ) {
			
			var pHandler	= this.pHandlers[sName];
			this.pStorage.writeFile( pHandler.sKey, null, this.sEncoding );
			
		}
		
		if( bSessionsAsWell )
			pSelf.pStorage.writeFile( pSelf.sPrefix, null, pSelf.sEncoding );
	};
	InterTabJS.prototype.init				= function() {
		
		var pSelf	= this;
		
		for( var sName in this.pHandlers ) {
			
			this.addHandler( sName, this.pHandlers[sName] );
			
		}
		
		INTER_TAB_JS.instances[ this.iLocalID ]	= this;
		this.iCheckForUpdates					= setInterval( "INTER_TAB_JS.instances[ "+pSelf.iLocalID+" ].checkForUpdates();", INTER_TAB_JS.UPDATE_INTERVAL );
		
		this.pStorage.readFile( this.sPrefix, this.sEncoding, function(sData) {
			
			var pData	= { pSessions:{}, iSessionID:1 };
			if( sData )
				pData		= JSON.parse( sData );
			
			pSelf.iSessionID	= pData.iSessionID++;
			
			INTER_TAB_JS.global_session_data.aLocalSessions.push( pSelf.iSessionID );
			
			sData		= JSON.stringify( pData );
			
			pSelf.pStorage.writeFile( pSelf.sPrefix, sData, pSelf.sEncoding, function() {
				
				pSelf.checkForUpdates();
				
			} );
			
		} );
		
	};
	InterTabJS.prototype.checkForUpdates	= function() {
		
		var pSelf	= this;
		
		if( !pSelf.bStorageEvent ) {
			
			for( var i=0; i<this.aHandlers.length; i++ ) {
				
				var pHandler	= this.aHandlers[i];
				this.pStorage.readFile( pHandler.sKey, this.sEncoding, function(sData) {
					
					if( pSelf.pCache[ pHandler.sKey ]!=sData ) {
						
						var pData	= JSON.parse( sData );
						
						pSelf.changed( pHandler.sKey, sData, pSelf.pCache[ pHandler.sKey ], pData.origin );
						
					}
					
				} );
				
			}
			
		}
		
		this.pSessionData.iLastUpdate	= getTimeStamp();
		this.pSessionData.sURL			= location.href;
		
		for( var sKey in INTER_TAB_JS.global_session_data ) {
			this.pSessionData[sKey]	= INTER_TAB_JS.global_session_data[ sKey ];
		}
		
		this.pStorage.readFile( this.sPrefix, this.sEncoding, function(sData) {
			
			var pData	= { pSessions:{}, iSessionID:1 };
			if( sData )
				pData		= JSON.parse( sData );
			
			if( !pData.pSessions )
				pData.pSessions	= {};
			
			var iCache	= getTimeStamp()-INTER_TAB_JS.CACHE_TIME;
			for( var iSessionID in pData.pSessions ) {
				
				if( pData.pSessions[ iSessionID ].iLastUpdate<iCache )
					delete pData.pSessions[ iSessionID ];
				
			}
			
			pData.pSessions[ pSelf.iSessionID ]	= pSelf.pSessionData;
			
			sData		= JSON.stringify( pData );
			pSelf.pStorage.writeFile( pSelf.sPrefix, sData, pSelf.sEncoding, function() {
				
				pSelf.pSessions	= pData;
				
			} );
			
		} );
		
	};
	InterTabJS.prototype.changed			= function( sName, sValue, sOldValue, sPageURL ) {
		
		if( sName.substr(0,19)=="storage-event-test-" )
			return;
		
		//console.log( sName, sValue );
		
		var pData	= { mData:null, iChanged:null, iSessionID:null };
		if( sValue )
			pData	= JSON.parse( sValue );
		
		$(window).trigger( 'inter-tab-js-before-change', [this,pData,sValue,sOldValue] );
		
		for( var i=0; i<this.aHandlers.length; i++ ) {
			if( this.aHandlers[i].sKey==sName ) {
				this.aHandlers[i].changed( pData.mData, pData.iChanged, pData.iSessionID, sValue, sOldValue );
				break;
			}
		}
		
		if( i==this.aHandlers.length )
			console.warn( 'Inter Tab JS: Unhandled changed event of type '+sName );
		
		$(window).trigger( 'inter-tab-js-after-change', [this,pData,sValue,sOldValue] );
		
	};
	InterTabJS.prototype.update			= function( sName, mData ) {
		
		var pData	= {
			mData		: mData,
			iChanged	: getTimeStamp(),
			iSessionID	: this.iSessionID
		};
		
		var sData	= JSON.stringify( pData );
		
		this.pCache[ sName ]	= sData;
		
		this.pStorage.writeFile( sName, sData, this.sEncoding );
		
	};
	InterTabJS.onStorage				= function(event) {
		
		var pSelf	= event.data.pHandler;
		var e		= event.originalEvent;
		
		var sKey;
		if( e.key.substr( 0, pSelf.sPrefix.length+1 )==pSelf.sPrefix+'/' && e.newValue!=pSelf.pCache[ sKey=e.key.substr( pSelf.sPrefix.length+1 ) ] && sKey!=pSelf.sPrefix ) {
			
			pSelf.changed( sKey, e.newValue, e.oldValue, e.url ? e.url : e.uri );
			
		}
		
	};
	
	
	
	createClass( "InterTabJS.Handler" );
	InterTabJS.Handler.pTypes				= {};
	InterTabJS.Handler.prototype.sKey		= null;
	InterTabJS.Handler.prototype.pManager	= null;
	InterTabJS.Handler.prototype.Handler	= function( pManager ) {
		this.pManager	= pManager;
	};
	InterTabJS.Handler.prototypeVirtual( "init" );		// ( mData:mixed, iLastUpdate:timestamp, iSessionID:session_id ):null
	InterTabJS.Handler.prototypeVirtual( "changed" );	// ( mData:mixed, iChanged:timestamp, iSessionID:session_id, sRawValue:string, sOldRawValue:string ):null
	
	
	
	createClass( "InterTabJS.Handler.Events", "InterTabJS.Handler" );
	InterTabJS.Handler.pTypes.events					= InterTabJS.Handler.Events;
	InterTabJS.Handler.Events.prototype.sKey			= "events";
	InterTabJS.Handler.Events.prototype.iLastUpdate		= null;
	InterTabJS.Handler.Events.prototype.pData			= null;
	InterTabJS.Handler.Events.prototype.Events			= function( pManager, pConfig ) {	
		this.Handler( pManager );
		
		this.iLastUpdate	= getTimeStamp();
	};
	InterTabJS.Handler.Events.prototype.init			= function( mData, iLastUpdate, iSessionID ) {
		
		this.pData			= mData;
		
	};
	InterTabJS.Handler.Events.prototype.trigger			= function( sEventName, pEventData ) {
		
		var pData			= this.pData ? this.pData : { aEvents:[] };
		
		var aEvents			= pData.aEvents;
		var iCache			= getTimeStamp()-INTER_TAB_JS.CACHE_TIME;
		for( var i=0; i<aEvents.length; ) {
			if( aEvents[i].iTimeStamp<iCache )
				aEvents.splice( i, 1 );
			else
				i++;
		}
		
		pData.aEvents.push( {
			sEventName	: sEventName,
			pEventData	: pEventData,
			iTimeStamp	: getTimeStamp(),
			iSessionID	: this.pManager.iSessionID
		} );
		
		this.pManager.update( this.sKey, pData );
		
	};
	InterTabJS.Handler.Events.prototype.triggerLocal	= function( sEventName, pEventData, iTimeStamp, iSessionID ) {
		$(window).trigger( sEventName, [pEventData,iTimeStamp,iSessionID,this.pManager] );
	};
	InterTabJS.Handler.Events.prototype.changed			= function( mData, iChanged, iSessionID, sRawValue, sOldRawValue ) {
		
		var iNow	= getTimeStamp();
		var aEvents	= mData.aEvents;
		for( var i=0; i<aEvents.length; i++ ) {
			
			if( aEvents[i].iTimeStamp>this.iLastUpdate && aEvents[i].iSessionID!=this.pManager.iSessionID ) {
				
				this.triggerLocal( aEvents[i].sEventName, aEvents[i].pEventData, aEvents[i].iTimeStamp, aEvents[i].iSessionID );
				
			}
			
		}
		
		this.iLastUpdate	= iNow;
		this.pData			= mData;
		
	};
	
	
	
	$( INTER_TAB_JS.init );
	
	
	
})(jQuery);