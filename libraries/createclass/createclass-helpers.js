/*
 * createClass (v 0.2)
 * Copyright (c) 2012 Thiemo Müller
 * MORPOL Softwareentwicklung (createclass@morpol.de, www.morpol.de)
 * 
 * A fully functional OOP framework that's still based on JavaScript's
 * own OOP understanding, tools and syntax (i.e. Prototyping).
 * If you have any questions, bug reports or feature requests please
 * contact createclass@morpol.de
 * 
 * https://github.com/MORPOL/createClass
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


/**
 *	Get all keys (i.e. names of children) of the given object
 *	
 *	@param pObject The object to get the keys from
 *	@param bExcludeFunctions Whether or not functions shall be excluded from the returned list
 *	@return An array of keys that the given object contains
 */
createClass.Tools.getObjectKeys							= function( pObject, bExcludeFunctions ) {
	var aResult	= [];
	for( var sName in pObject )
		if( !bExcludeFunctions || typeof(pObject[sName])!='function' )
			aResult.push( sName );
	return aResult;
};
/**
 *	Get all values of child elements for the given object
 *	
 *	@param pObject The object whose children shall be gotten
 *	@param bExcludeFunctions Whether or not functions shall be excluded from the returned list
 *	@return An array of all child-values that the given object contains
 */
createClass.Tools.getObjectValues						= function( pObject, bExcludeFunctions ) {
	var aResult	= [];
	for( var sName in pObject )
		if( !bExcludeFunctions || typeof(pObject[sName])!='function' )
			aResult.push( pObject[ sName ] );
	return aResult;
};
/**
 *	Get the file ending of the given file
 *	
 *	@param sFileName The filename to get the part after the last dot for
 *	@return The file ending
 */
createClass.Tools.getFileEnding							= function( sFileName ) {
	var aParts	= sFileName.split( '.' );
	return aParts.length==1 ? '' : aParts[ aParts.length-1 ];
};



/**
 *	Get a camel-case version of the given string
 *	
 *	@param bStartWithUpperCase (optional) Whether or not the string shall start upper-case
 *	@return The camel case version of the string. All non-letters and -numbers will be removed as well
 */
String.prototype.toCamelCase	= function( bStartWithUpperCase ) {
	var sResult	= this.replace( /([^0-9A-Za-z]+)([a-zA-Z]{1})/gi, function( sMatch, sSpecial, sConvert ) {
		return sConvert.toUpperCase();
	} );
	
	if( bStartWithUpperCase )
		sResult	= sResult.charAt(0).toUpperCase() + sResult.substr(1);
	
	return sResult.replace( /([^0-9a-zA-Z]+)/, "" );
};



/**
 *	WeightedItemsArray An array that is sorted by weight.
 *	Each element requires a function getWeight() determining it's weight (see WeightedItemsArray.IItem).
 *	Currently this class is simply overwriting the .push() function to place the given items correctly.
 */
createClass( "WeightedItemsArray", "Array" );
/**
 *	The constructor of the array. Will pass all given arguments to .push()
 */
WeightedItemsArray.prototype.WeightedItemsArray	= function() {
	
	if( arguments.length )
		this.push.apply( this, arguments );
	
};
WeightedItemsArray.prototype					= new Array();
/**
 *	Overwrite push function to place items correctly
 *	
 *	@return NULL
 */
WeightedItemsArray.prototype.push				= function() {
	
	for( var i=0; i<arguments.length; i++ ) {
		
		var iIndex	= 0;
		var pItem	= arguments[i];
		var iWeight	= pItem.getWeight();
		while( iIndex<this.length && this[iIndex].getWeight()<=iWeight )
			iIndex++;
		
		this.splice( iIndex, 0, pItem );
		
	}
	
};
/**
 *	Disable sort function
 *	
 *	@return NULL
 */
WeightedItemsArray.prototype.sort				= function() {}
createClass( "WeightedItemsArray.IItem" );
WeightedItemsArray.IItem.prototypeVirtual( "getWeight" );	// ():float



/**
 *	Define an array whose children are kept apart by distinct features
 */
createClass( "DistinctFeatureArray" );
/**
 *	Overwrite constructor completely
 *	
 *	@param A list of features to be used to distinguish child elements
 *	@param aChildren Init the array with elements
 */
DistinctFeatureArray						= function( mFeatures, aChildren ) {
	
	this._aFeatures	= createClass.Tools.isArray( mFeatures ) ? mFeatures : ( mFeatures ? [mFeatures] : [] );
	
	if( aChildren )
		this.push.apply( this, aChildren );
	
};
DistinctFeatureArray.prototype				= new Array();
DistinctFeatureArray.prototype._aFeatures	= [];	// Child features
/**
 *	Core: Find an element within the array, as given by mValue
 *	
 *	@param mValue Whatever value you're searching
 *	@return The matching element or NULL of none was found
 */
DistinctFeatureArray.prototype.find			= function( mValue ) {
	
	var bIsArray	= createClass.Tools.isArray( mValue );
	
	for( var i=0; i<this._aFeatures.length; i++ ) {
		
		var mFeature	= this._aFeatures[i];
		
		if( bIsArray ) {
			
			if( !createClass.Tools.isArray( mFeature ) )
				continue;
			
			for( var n=0; n<this.length; n++ ) {
				
				for( var c=0; c<mFeature.length; c++ ) {
					
					var sFeature	= mFeature[c];
					if( !(sFeature in this[n]) || this[n][sFeature]!=mValue )
						break;
					
				}
				
				if(  c==mFeature.length )
					return this[n];
				
			}
			
		}
		else {
			
			if( createClass.Tools.isArray( mFeature ) )
				continue;
			
			for( var n=0; n<this.length; n++ ) {
				
				if( (mFeature in this[n]) && this[n][mFeature]==mValue ) {
					
					return this[n];
				
				}
				
			}
			
		}
		
	}
	
};