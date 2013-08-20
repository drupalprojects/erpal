/*
 * web-filesystem (v 0.1.0-beta)
 * Copyright (c) 2012 Thiemo Müller
 * MORPOL Softwareentwicklung (web-filesystem@morpol.de, www.morpol.de)
 * 
 * A simple web-filesystem using sessionStorage, localStorage, cookies
 * or web requests to save and retrieve files as well as checking their
 * existence. Requires createClass.
 * If you have any questions, bug reports or feature requests please
 * contact web-filesystem@morpol.de
 * 
 * https://github.com/MORPOL/web-filesystem
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


createClass( "FileSystem.IRWEFileSystem" );					// (Interface) Read/Write/Exists File System
FileSystem.IRWEFileSystem.prototypeVirtual( "exists" );		// ( sPath:string, callback:function(bExists:bool) ):null
FileSystem.IRWEFileSystem.prototypeVirtual( "readFile" );	// ( sPath:string, sEncoding:string, callback:function(pError:Error,sData:string) ):null
FileSystem.IRWEFileSystem.prototypeVirtual( "writeFile" );	// ( sPath:string, sData:string, sEncoding:string, callback:function(pError:Error,sData:string) ):null

createClass( "FileSystem.HTTPRWEFileSystem", "FileSystem.IRWEFileSystem" );
FileSystem.HTTPRWEFileSystem.prototype.pJQuery					= null;
FileSystem.HTTPRWEFileSystem.prototype.sURLPrefix				= null;
FileSystem.HTTPRWEFileSystem.prototype.sContentsKey				= null;
FileSystem.HTTPRWEFileSystem.prototype.sSaveRequestType			= null;
FileSystem.HTTPRWEFileSystem.prototype.HTTPRWEFileSystem		= function( sURLPrefix, pJQuery, sContentsKey, sSaveRequestType ) {
	this.pJQuery			= pJQuery ? pJQuery : (typeof jQuery=='undefined' ? require( 'jquery' ) : jQuery);
	this.sURLPrefix			= sURLPrefix;
	this.sContentsKey		= sContentsKey ? sContentsKey : 'contents';
	this.sSaveRequestType	= sSaveRequestType ? sSaveRequestType : 'POST';
};
FileSystem.HTTPRWEFileSystem.prototype.exists					= function( sPath, pCallback ) {
	if( this.sURLPrefix && sPath.substr(0,4)!='http' )
		sPath	= this.sURLPrefix + sPath;
	
	this.pJQuery.ajax( {
		cache		: false,
		dataType	: 'text',
		type		: 'HEAD',
		url			: sPath,
		success		: function( data, textStatus, jqXHR ){
			pCallback(true);
		},
		error		: function( jqXHR, textStatus, errorThrown ) {
			pCallback(false);
		}
	} );
};
FileSystem.HTTPRWEFileSystem.prototype.readFile					= function( sPath, sEncoding, pCallback ) {
	if( this.sURLPrefix && sPath.substr(0,4)!='http' )
		sPath	= this.sURLPrefix + sPath;
	
	this.pJQuery.ajax( {
		cache		: false,
		dataType	: 'text',
		type		: 'GET',
		url			: sPath,
		success		: function( data, textStatus, jqXHR ){
			pCallback( null, data );
		},
		error		: function( jqXHR, textStatus, errorThrown ) {
			pCallback( new Error( 'Unable to get contents from URL '+sPath ) );
		}
	} );
};
FileSystem.HTTPRWEFileSystem.prototype.writeFile					= function( sPath, sData, sEncoding, pCallback ) {
	if( this.sURLPrefix && sPath.substr(0,4)!='http' )
		sPath	= this.sURLPrefix + sPath;
	
	var pData	= {};
	pData[ this.sContentsKey ]	= sData;
	this.pJQuery.ajax( {
		cache		: false,
		dataType	: 'text',
		type		: this.sSaveRequestType,
		url			: sPath,
		data		: pData,
		success		: function( data, textStatus, jqXHR ){
			pCallback( null );
		},
		error		: function( jqXHR, textStatus, errorThrown ) {
			pCallback( new Error( 'Unable to post contents to URL '+sPath ) );
		}
	} );
};

createClass( "FileSystem.HTMLWebStorageRWEFileSystem", "FileSystem.IRWEFileSystem" );
FileSystem.HTMLWebStorageRWEFileSystem.isAvailable								= function() {
	return typeof(Storage)!=='undefined';
};
createClass( "FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage" );
FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage.prototype.iExpireIn		= 0;
FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage.prototype.CookieStorage	= function( iExpireIn ) {
	this.iExpireIn	= iExpireIn;
};
FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage.prototype.getCookieName	= function( sName ) {
	return escape( sName );//sName.replace( /([^a-zA-Z0-9.-_])/g, "_" );
};
FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage.prototype.getItem			= function( sName ) {
	
	var sCookieName	= this.getCookieName( sName );
	var aCookies	= document.cookie.split( ";" );
	for( var i=0; i<aCookies.length; i++ ) {
		var sCookie	= aCookies[ i ];
		var iIndex	= sCookie.indexOf( "=" );
		var sName	= sCookie.substr( 0, iIndex ).replace( /^\s+|\s+$/g, "" );
		if( sName==sCookieName )
			return unescape( sCookie.substr( iIndex+1 ) );
	}
	
	return null;
	
};
FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage.prototype.setItem			= function( sName, sValue ) {
	
	var sCookieName	= this.getCookieName( sName );
	var sValue		= sCookieName + "=" + escape( sValue );
	var iExpireIn	= sValue===null ? 0 : (this.iExpireIn>0 ? this.iExpireIn : ( this.iExpireIn<0 ? 20*365*24*60*60 : 0 ));
	if( iExpireIn ) {
		var pDate		= new Date();
		pDate.setTime( pDate.getTime() + iExpireIn*1000 );
		sValue			+= "; expires=" + pDate.toUTCString();
	}
	
	document.cookie	= sValue;
	
};
FileSystem.HTMLWebStorageRWEFileSystem.prototype.sKeyFormat						= null;
FileSystem.HTMLWebStorageRWEFileSystem.prototype.pStorage						= null;
FileSystem.HTMLWebStorageRWEFileSystem.prototype.HTMLWebStorageRWEFileSystem	= function( sKeyFormat, iExpireIn ) {
	this.sKeyFormat		= sKeyFormat ? sKeyFormat : '[filename]';
	
	// Use non-expiring local storage by default
	if( typeof iExpireIn==='undefined' )
		iExpireIn			= -1;
	
	this.pStorage		= FileSystem.HTMLWebStorageRWEFileSystem.isAvailable() && iExpireIn<=0 ? (iExpireIn==0 ? sessionStorage : localStorage) : new FileSystem.HTMLWebStorageRWEFileSystem.CookieStorage( iExpireIn );
};
FileSystem.HTMLWebStorageRWEFileSystem.prototype.exists							= function( sPath, pCallback ) {
	var sFilePath	= this.sKeyFormat.replace( /\[filename\]/, sPath );
	
	var pData		= this.pStorage.getItem( sFilePath );
	pCallback( pData || pData==="" );
};
FileSystem.HTMLWebStorageRWEFileSystem.prototype.readFile						= function( sPath, sEncoding, pCallback ) {
	var sFilePath	= this.sKeyFormat.replace( /\[filename\]/, sPath );
	
	var sData		= this.pStorage.getItem( sFilePath );
	
	pCallback( sData );
};
FileSystem.HTMLWebStorageRWEFileSystem.prototype.writeFile						= function( sPath, sData, sEncoding, pCallback ) {
	var sFilePath	= this.sKeyFormat.replace( /\[filename\]/, sPath );
	
	if( sData==null && typeof this.pStorage.instanceOf!='function' )
		delete this.pStorage[sFilePath]
	else
		this.pStorage.setItem( sFilePath, sData );
	
  if( pCallback )
    pCallback( null );
};