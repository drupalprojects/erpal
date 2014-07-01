/*
 * createClass (v 0.2.1)
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

(function(undefined) {
	// Keep reference to window (browser) or global (nodeJS) element
	var root	= typeof global=="undefined" ? this : global;
	
	if( typeof module!=='undefined' ) {
		
		// NodeJS module extension
		module.exports	= {
			/**
			 *	Load additional helpers of createClass
			 *	
			 *	@return The createclass-helpers module pointer, as returned by require()
			 */
			loadHelpers		: function() {
				return require( './createclass-helpers' );
			}
		};
		
	}
	
	var tools	= "jQuery" in root ? {inArray:root.jQuery.inArray,isArray:root.jQuery.isArray} : {
		/**
		 *	Check whether or not the given element exists in the given array
		 *	
		 *	@param mElement The element to be searched for (double equal comparison)
		 *	@param aArray The array to be searched
		 *	@return The index of the element within the array or -1 if it wasn't found
		 */
		inArray		: function( mElement, aArray ) {
			for( var i=0; i<aArray.length; i++ )
				if( aArray[i]==mElement )
					return i;
			
			return -1;
		},
		/**
		 *	Check whether the given variable is an array
		 *	
		 *	@param mArray The potential array
		 *	@return (bool) Whether or not the given data was an array
		 */
		isArray		: function( mArray ) {
			return Object.prototype.toString.call(mArray)=='[object Array]';
		}
	};
	
	/**
	 *	Get the Greatest Common Divisor
	 *	Currently used for optimization
	 *	
	 *	@param aNumbers An array of numbers to get the GCD for
	 *	@return The GCD (number) or 0 if no numbers were given
	 */
	Math.getGCD	= function( aNumbers ) {
		if(!aNumbers.length)
			return 0;
		
		for( var n, u, i=aNumbers.length-1, iGCDNum=aNumbers[i]; i; )
			for( u=aNumbers[--i]; n=u%iGCDNum; u=iGCDNum, iGCDNum=n )
				;
		
		return iGCDNum;
	};
	
	/**
	 *	Find and remove a given element from an array
	 *	
	 *	@param mElement The element to be removed
	 *	@return The index of the removed element or -1 if none was found
	 */
	tools.findAndRemove	= function( aArray, mElement ) {
    __findAndRemove.apply( aArray, [mElement] );
  };
  function __findAndRemove( mElement ) {
		var iIndex	= tools.inArray( mElement, this );
		if( iIndex>=0 )
			this.splice( iIndex, 1 );
		
		return iIndex;
	};
	
	/**
	 *	Clone the given array, optionally including the children
	 *	
	 *	@param iChildrenCloneDepth The max depth to clone children to
	 *	@return The new array
	 */
	tools.clone			= function( mObject, iChildrenCloneDepth ) {
    return __clone.apply( mObject, [iChildrenCloneDepth] );
  };
  function __clone( iChildrenCloneDepth ) {
		var aClone	= [];
		
		if( iChildrenCloneDepth ) {
			for( var i=0; i<this.length; i++ )
				if( typeof this[i].clone=='function' )
					aClone[i]	= tools.clone( this[i], iChildrenCloneDepth-1 );
				else
					aClone[i]	= this[i];
		}
		else
			// Stick here if faster...
			aClone.push.apply( aClone, this );
		
		return aClone;
	};
	
	/**
	 *	Extend the base array
	 *	This class is used to store virtual functions in their specific inheritance order
	 *	to allow parental calling
	 *	
	 *	@param sName The name of this function (Used to check whether this function was overridden by the inherited class or not)
	 *	@param pFirst The first function to be added
	 *	@param aCopy A MethodChain object that shall be copied (if this function has already been overridden)
	 */
	MethodChain							= function( sName, pFirst, aCopy ) {
		//console.log( "Creating MethodChain: ", sName, pFirst, aCopy );
		this.sName	= sName;
		this.aCalls	= [];
		
		if( aCopy )
			this.push.apply( this, aCopy );
		
		this.push( pFirst );
	};
	MethodChain.prototype				= [];
	MethodChain.prototype.iCallIndex	= null;
	MethodChain.prototype.sName			= null;
	MethodChain.prototype.aCalls		= null;
	/**
	 *	Call the base function
	 *	First parameter must be the current object
	 *	All following parameters will be passed to the base function
	 *	Use .apply / .applyEx whereever possible
	 */
	MethodChain.prototype.call			= function() {
		var pObject		= arguments[0];
		var aArguments	= [];
		aArguments.push.apply( aArguments, arguments );
		
		return this.apply( pObject, aArguments );
	};
	/**
	 *	This function covers a special case when the lower function calls the upper function again with different arguments
	 *	(i.e. recursion)
	 *	
	 *	@param pObject The object to execute the function for, usually called using "this"
	 *	@param aArguments Additional arguments that shall be passed to the base function
	 *	@param pClass The class from which you are calling
	 */
	MethodChain.prototype.applyEx		= function( pObject, aArguments, pClass ) {
		// Check whether the index shall be resetted
		var bReset	= pObject[this.sName]===pClass.prototype[this.sName];
		var iNextCallIndex;
		if( bReset ) {
			iNextCallIndex	= this.length;
			// Even if the function has not been overridden, it will still be a part of the object
			// In this case we're simply going one inheritance layer up:
			if( this[iNextCallIndex-1]==pObject[this.sName] ) {
				iNextCallIndex--;
			}
			
			this.aCalls.push( iNextCallIndex );
		}
		else
			iNextCallIndex	= this.aCalls[ this.aCalls.length-1 ];
		
		// Go up
		this.aCalls[ this.aCalls.length-1 ]	=
		iNextCallIndex						= iNextCallIndex-1;
		if( iNextCallIndex<0 )
			return;
		
		// Actual call
		var mResult	= this[iNextCallIndex].apply( pObject, aArguments );
		
		// Reset, if applicable
		if( bReset )
			this.aCalls.pop();
		
		return mResult;
	};
	/**
	 *	Call the base function
	 *	
	 *	@param pObject The object to execute the function for, usually called using "this"
	 *	@param aArguments Additional arguments that shall be passed to the base function
	 */
	MethodChain.prototype.apply			= function( pObject, aArguments ) {
		// Check whether the index shall be resetted
		var bReset	= this.iCallIndex===null;
		if( bReset ) {
			this.iCallIndex	= this.length;
			// Even if the function has not been overridden, it will still be a part of the object
			// In this case we're simply going one inheritance layer up:
			if( this[this.iCallIndex-1]==pObject[this.sName] ) {
				this.iCallIndex--;
			}
		}
		
		// Go up
		this.iCallIndex--;
		if( this.iCallIndex<0 )
			return;
		
		// Actual call
		var mResult	= this[this.iCallIndex].apply( pObject, aArguments );
		
		// Reset, if applicable
		if( bReset )
			this.iCallIndex	= null;
		
		return mResult;
	};
	
	/**
	 *	The base class every unparented class shall inherit from
	 *	Don't use this class/function directly.
	 *	Instead define classes like: createClass( "MyClassName", "Class" );
	 *	
	 *	Constructors may be defined by giving the function a prototype of it's own name like:
	 *	
	 *	createClass( "MyClassName", "Class" );
	 *	MyClassName.prototype.MyClassName	= function( arg1, arg2, ... ) {
	 *		MyClassName.Class();	// Not even necessary for the base class
	 *		...
	 *	}
	 *	
	 *	!!! Never forget to call the parent's constructor !!!
	 *	
	 *	Destructors may be defined by giving the function a prototype of it's own name with a leading dollar-sign prepended like:
	 *	
	 *	MyClassName.$MyClassName	= function() {
	 *		...
	 *	}
	 *		
	 *	!!! You must call .destroy() so that the destructors will be executed properly !!!
	 */
	root.Class					= function() {};
	// No naming conventions, since this could break code built upon this base
	Class.prototype.__parent	= null;
	Class.prototype.__parents	= [];
	Class.prototype.__className	= null;
	Class.prototype.Class		= function() {};
	/**
	 *	Check whether this object is an instance of the given function/class
	 */
	Class.prototype.instanceOf	= function(func) {
		if( this instanceof func )
			return true;
		
		// Search tree...
		for( var i=0; i<this.__parents.length; i++ )
			if( this.__parents[i].instanceOf(func) )
				return true;
		
		return false;
	};
	/**
	 *	Base toString() function, displaying the current class name
	 */
	Class.prototype.toString	= function() {
		return "[object "+this.__className+"]";
	};
	/**
	 *	Check for virtual errors, i.e. functions that should have been overridden, but weren't
	 */
	var	checkVirtual			= function() {
		var v	= [];
		for( var i in this )
			if( typeof this[i]=="function" && this[i].__virtual )
				v.push( i );
		
		if( v.length )
			createClass.log( 'error', 'INCOMPLETE CLASS '+this.__className+' HAS AT LEAST ONE PURE VIRTUAL FUNCTION: '+v.join(", ") );
	};
	
	/**
	 *	Base for destructable objects
	 *	
	 *	Please note that this will only work if you call .destroy() on the specific object,
	 *	else the destructor will never be called!
	 */
	root.Destructable				= function() {};
	// Make it work without createClass() using classic JS inheritance
	root.Destructable.prototype		= new Class();
	/**
	 *	Destroy this object
	 *	This will simply call all destructors associated with this object
	 *	
	 *	@param parent Leave empty
	 */
	Destructable.prototype.destroy	= function(parent) {
		if( !parent )
			parent	= this;
		
		// Check whether this class has defined a destructor
		if( "$"+parent.__className in parent )
			this["$"+parent.__className]();
		
		// Go up
		for( var i=0; i<parent.__parents.length; i++ )
			this.destroy( parent.__parents[i] );
	};
	
	/**
	 *	This is the base function of this OOP system.
	 *	When using multiple inheritance please note that the instanceof-operator of JavaScript won't work with the 2nd+ class.
	 *	To avoid errors, you should rather use the .instanceOf function of the object itself.
	 *	You may also pass namespaced definitions like "MyNameSpace.MySubNameSpace.MyClass" for both parameters.
	 *	If a given namespace doesn't exist yet, it will be created as an empty object.
	 *  Take care not to use the same classname twice within an inheritance chain, since this may lead to an endless loop when constructing an object.
	 *	
	 *	@param sFullName The fully namespaced name of the class that shall be created as a string
	 *	@param mBase The base of this class as a string, may be omitted for base classes. If multiple inheritance is wanted, pass an array.
	 *  @param bLazy Whether or not this class is to be lazy-loaded, i.e. a base class may be missing and shall be inherited from later on. In this case you must call createClass.initialize( sFullName ) once before using the class
	 *  @param mFeatures One or more classes/objects to copy all values from (*not only, but mainly it's prototype features*) -> No strings, but instances!
	 */
	root.createClass				= function( sFullName, mBase, bLazy, mFeatures ) {
		//console.log( mBase );
		if( !mBase )
			mBase	= "Class";
		
		var aBase = tools.isArray(mBase) ? mBase : [mBase];
		//console.log( aBase );
		
		if( !mFeatures )
			mFeatures	= [];
		
		if( !tools.isArray(mFeatures) )
			mFeatures	= [mFeatures];
		
		var pBase = createClass.resolveInheritance( aBase );
		
		if( bLazy ) {
			var pClass	= createClass.createAbstract( sFullName );
			var aCopy	= tools.clone( mFeatures );
			//console.log( aCopy, mFeatures, aCopy==mFeatures );
			aCopy.push( pClass );
			createClass.aLazyLoader.push( [ pBase.aMissing, [ sFullName, mBase, false, aCopy ] ] );
			
			return pClass;
		}
		
		if( pBase.aMissing.length ) {
			createClass.log( 'fatal_error', 'Base type definition could not be resolved: '+pBase.aMissing+'. Did you include all namespaces correctly?' );
			
			return null;
		}
		
		return createClass.create( sFullName, pBase, aBase, mFeatures );
	};
	/**
	 *	Instantiate a class by it's full classname (including namespaces)
	 *	
	 *	@param sFullName The name of the class to instantiate
	 *	@param aArguments Up to 8 arguments to be passed to the class' constructor
	 *	@return The newly instantiated object
	 */
	createClass.instantiate			= function( sFullName, aArguments ) {
		var pNameSpace	= this.createNameSpace( sFullName );
		var sClassName	= pNameSpace.sClassName;
		pNameSpace		= pNameSpace.pNameSpace;
		
		// Sadly there's no "apply" for the new-operator, so we currently have a limit of 8 args... Of course, you may extend it as needed...
		if( sClassName in pNameSpace ) {
			var pClass	= pNameSpace[sClassName];
			switch( aArguments.length ) {
				case 8:
					return new pClass( aArguments[0], aArguments[1], aArguments[2], aArguments[3], aArguments[4], aArguments[5], aArguments[6], aArguments[7] );
				case 7:
					return new pClass( aArguments[0], aArguments[1], aArguments[2], aArguments[3], aArguments[4], aArguments[5], aArguments[6] );
				case 6:
					return new pClass( aArguments[0], aArguments[1], aArguments[2], aArguments[3], aArguments[4], aArguments[5] );
				case 5:
					return new pClass( aArguments[0], aArguments[1], aArguments[2], aArguments[3], aArguments[4] );
				case 4:
					return new pClass( aArguments[0], aArguments[1], aArguments[2], aArguments[3] );
				case 3:
					return new pClass( aArguments[0], aArguments[1], aArguments[2] );
				case 2:
					return new pClass( aArguments[0], aArguments[1] );
				case 1:
					return new pClass( aArguments[0] );
				default:
					return new pClass();
			}
		}
		else
			return null;
	};
	/**
	 *	Create the given dot-separated namespace as empty objects if they don't exist already
	 *	
	 *	@param sFullName The namespace to be resolved. Last entry (i.e. the class) will not be created
	 *	@return An object containing a pointer to the class' namespace in pNameSpace and the name of the given class in sClassName
	 */
	createClass.createNameSpace		= function( sFullName ) {
		var aParts		= sFullName.split( "." );
		var pNameSpace	= root;
		
		for( var i=0; i<aParts.length-1; i++ ) {
			if( !(aParts[i] in pNameSpace) )
				pNameSpace[ aParts[i] ]	= {};
			
			pNameSpace		= pNameSpace[ aParts[i] ];
		}
		
		return { pNameSpace:pNameSpace, sClassName:aParts[ aParts.length-1 ] };
	};
	/**
	 *	Get the given class
	 *	
	 *	@param sFullName The full classname, including namespaces, to be resolved
	 *	@return The resolved class, if it exists or NULL if it doesn't exist yet
	 */
	createClass.getClass			= function( sFullName ) {
		var aParts		= sFullName.split( "." );
		var pNameSpace	= root;
		
		for( var i=0; i<aParts.length; i++ ) {
			if( !(aParts[i] in pNameSpace) )
				return null;
			
			pNameSpace		= pNameSpace[ aParts[i] ];
		}
		
		return typeof(pNameSpace)=='function' ? pNameSpace : null;
	};
	/**
	 *	Get the name of the class from the namespace
	 *	
	 *	@param sFullName The dot-separated namespace to be resolved
	 *	@return The name of the class (last entry of given namespace)
	 */
	createClass.resolveClassName	= function( sFullName ) {
		var aParts		= sFullName.split( "." );
		
		return aParts[ aParts.length-1 ];
	};
	/**
	 *	Create an abstract class (will be overridden later). Used for lazy loading
	 *	
	 *	@param sFullName The name of the class including the namespaces
	 *	@return The newly created abstract class
	 */
	createClass.createAbstract		= function( sFullName ) {
		var pNameSpace	= this.createNameSpace( sFullName );
		var sClassName	= pNameSpace.sClassName;
		pNameSpace		= pNameSpace.pNameSpace;
		
		var pResult			= function() { createClass.log( 'fatal_error', 'Instantiation of fully abstract type: "'+sClassName+'". Did you include all namespaces correctly?' ); };
		pResult.prototype	= {};
		
		pResult.prototype.__className	= sClassName;
		pResult.prototypeVirtual		= createClass._prototypeVirtual;
		
		return pNameSpace[ sClassName ]=pResult;
	};
	/**
	 *	Resolve the given parents
	 *	
	 *	@param aBase An array containing the fully namespaced names of the base classes
	 *	@return An object giving pointers to the base classes in aBases, the names of the classes in aBaseNames and the missing classes in aMissing
	 */
	createClass.resolveInheritance  = function( aBase ) {
		var aBases		= [];
		var aBaseNames	= [];
		var aMissing	= [];
		
		// Resolve base classes
		for( var i=0; i<aBase.length; i++ ) {
			var pNameSpace	= root;
			var aParts		= aBase[i].split( "." );
			for( var n=0; n<aParts.length-1; n++ ) {
				if( !(aParts[n] in pNameSpace) ) {
					aMissing.push( aBase[i] );
					pNameSpace		= null;
					break;
				}
				else
					pNameSpace		= pNameSpace[ aParts[n] ];
			}
			
			if( pNameSpace ) {
				aBaseNames.push( aParts[ aParts.length-1 ] );
				if( !(aBaseNames[i] in pNameSpace) ) {
					aBases.push( null );
					aMissing.push( aBase[i] );
				}
				else
					aBases.push( pNameSpace[ aBaseNames[ i ] ] );
			}
			else
				aBaseNames.push( null );
		}
		
		return { aBases:aBases, aBaseNames:aBaseNames, aMissing:aMissing };
	};
	/**
	 *	Initialize the lazy-loaded class
	 *	
	 *	@param sFullName The fully namespaced name of the class to be initialized (i.e. lazy loaded)
	 *	@return (bool) Whether or not the class exists and could be resolved correctly
	 */
	createClass.initialize  = function( sFullName ) {
		for( var i=0; i<createClass.aLazyLoader.length; i++ ) {
			if( createClass.aLazyLoader[i][1][0]==sFullName ) {
				if( createClass.aLazyLoader[i][0].length ) {
					//console.log( createClass.aLazyLoader[i][0] );
					createClass.log( "warn", "Initialization failed: Class "+sFullName+" is missing at least one base class: " + createClass.aLazyLoader[i][0] );
					return false;
				}
				
				var pClass	= createClass.apply( root, createClass.aLazyLoader[i][1] );
				//console.log( sFullName, createClass.aLazyLoader[i][1] );
				
				createClass.aLazyLoader.splice( i, 1 );
				
				return pClass;
			}
		}
		
		// Is the class even known?
		var pNameSpace	= this.createNameSpace( sFullName );
		var sClassName	= pNameSpace.sClassName;
		pNameSpace		= pNameSpace.pNameSpace;
		
		return !!pNameSpace[ sClassName ];
	};
	/**
	 *	Finally create the given class. This is used internally by a call to createClass() or createClass.initialize()
	 *	
	 *	@param sFullName The fully namespaced name of the class to be created
	 *	@param pBase The object describing the base classes, as given by a call to createClass.resolveInheritance
	 *	@param aBase An array containing the full names of all base classes
	 *	@param aFeatures An array of objects to be copied into the prototype of the newly created class
	 *	@return The newly created class
	 */
	createClass.create		= function( sFullName, pBase, aBase, aFeatures ) {
		var aBases		= pBase.aBases;
		var aBaseNames	= pBase.aBaseNames;
		
		var inheriting		= createClass.inheriting==false;
		
		if( inheriting )
			createClass.inheriting				= true;
		
		var pParent		= new aBases[0]();
		var aParents	= [];
		var i_prot		= {};
		for( var n=0; n<aBases.length; n++ ) {
			var prot	= new aBases[n]();
			prot.__className	= aBaseNames[n];
			aParents.push( prot );
			for( var i in prot ) {
				if( typeof prot[i]=="function" && !prot[i].__virtual ) {
					var p			= prot.__parent;
					var fa			= null;
					while( p ) {
						if( i in p ) {
							fa	= p[i];
							break;
						}
						p	= p.__parent;
					}
					if( !fa || fa[fa.length-1]!=prot[i] )
						fa				= new MethodChain( i, prot[i], fa );
					
					i_prot[i]		= fa;
				}
				//console.log( "Assigning "+i+" to "+sFullName, prot[i] );
				pParent[i]	= prot[i];
			}
			
			//console.log( "Prototype for class "+sFullName+" is ", i_prot, prot, pParent );
		}
		
		if( inheriting )
			createClass.inheriting				= false;
		
		
		var pNameSpace	= this.createNameSpace( sFullName );
		var sClassName	= pNameSpace.sClassName;
		pNameSpace		= pNameSpace.pNameSpace;
		
		var Class		= function() {
			if( !createClass.inheriting ) {
				//console.log( this, this.__className, arguments, (this.__className in this) );
				this[this.__className].apply( this, arguments );
			}
		};
		
		Class.prototype				= pParent;
		Class.prototype[sClassName]	= function() {
			checkVirtual.apply( this, [] );
			
			for( i=0; i<aBase.length; i++ )
				if( aBaseNames[i] in aBases[i].prototype )
					this[ aBaseNames[i] ].apply( this, arguments );
		};
		
		Class.prototype.__parent		= i_prot;
		Class.prototype.__parents		= aParents;
		Class.prototype.__className	= sClassName;
		Class.prototypeVirtual		= createClass._prototypeVirtual;
		/*if( sClassName=="EditorPuzzleField" || sClassName=="EditorPuzzleFieldBase" )
			console.log( Class.prototype, aFeatures.length ? aFeatures.prototype : null );*/
		
		if( aFeatures.length ) {
			for( var i=0; i<aFeatures.length; i++ ) {
				var pCopyClass  = aFeatures[i];
				for( var sChild in pCopyClass ) {
					if( sChild!="prototype" && sChild!="prototypeVirtual" ) {
						//console.log( "Adding ", sChild );
						Class[sChild]	= pCopyClass[ sChild ];
					}
				}
				for( var sAttribute in pCopyClass.prototype ) {
					if( sAttribute!="__className" && sAttribute!="__parent" && sAttribute!="__parents" ) {
						//console.log( "Adding ", sAttribute );
						Class.prototype[sAttribute]	= pCopyClass.prototype[ sAttribute ];
					}
				}
			}
		}
		
		pNameSpace[sClassName]	= Class;
		//if( sClassName=="EditorCrosswordPuzzleControllerBase" )console.log( sClassName, func, aBaseNames[0], aParents[0].__className, aBases[0].prototype, aBaseNames[0] in aBases[0].prototype );
		
		for( var i=0; i<createClass.aLazyLoader.length; i++ ) {
			for( var n=0; n<createClass.aLazyLoader[i][0].length; n++ ) {
				if( createClass.aLazyLoader[i][0][n]==sFullName ) {
					createClass.aLazyLoader[i][0].splice( n, 1 );
					break;
				}
			}
		}
		
		//console.log( pNameSpace, sClassName, Class );
		
		return Class;
	};
	createClass._prototypeVirtual	= function( sFuncName ) {
		this.prototype[sFuncName]			= function() {
			createClass.log( 'error', 'Pure virtual function call: '+sFuncName+'!' );
		};
		
		this.prototype[sFuncName].__virtual	= true;
	};
	createClass.aLazyLoader			= [];
	createClass.log					= function( type, message ) {
		if( type=="fatal_error" ) {
			message	= "(fatal) " + message;
			type	= "error";
		}
		
		if( root.console ) {
			if( root.console[type] )
				console[type]( message );
			else
				console.log( type+": "+message );
		}
	};
	createClass.inheriting			= false;
	createClass.Tools				= tools;
	createClass.Root				= root;
	
	
	
	/**
	 *	Declare Enum class (a simple enumeration, counting starts at zero).
	 *	
	 *	Elements may be added using .addElement( name[, index] )
	 *	An index may have multiple names, but a single name must be unique!
	 *	Existence of an element may be checked using .getElementIndex( name )
	 */
	createClass( "Enum" );
	Enum.prototype._iSpacing		= 0;
	Enum.prototype._iNextIndex		= 0;
	Enum.prototype.Enum				= function() {
		var aElements	= arguments;
		if( aElements.length && tools.isArray(aElements[0]) ) {
			if( aElements[1] )
				this._iSpacing	= aElements[1];
			aElements		= aElements[0];
		}
		
		for( var i=0; i<aElements.length; i++ )
			this[ aElements[i] ]	= i*(this._iSpacing+1);
		
		this._iNextIndex	= i*(this._iSpacing+1);
	};
	/**
	 *	Get the last used index of this enum
	 */
	Enum.prototype.getLastIndex		= function() {
		return this._iNextIndex ? this._iNextIndex-this._iSpacing-1 : 0;
	};
	/**
	 *	Add an element to the enum
	 *	
	 *	@param sName The name of the item
	 *	@param iIndex Optional index to assign to this name
	 *	@param iSpacing The spacing that shall be used as an offset to the last item
	 */
	Enum.prototype.addElement		= function( sName, iIndex, iSpacing ) {
		if( iIndex==undefined )
			iIndex	= this._iNextIndex;
		
		if( iSpacing==undefined )
			iSpacing	= this._iSpacing;
		
		iIndex		= iIndex*(iSpacing+1);
		this[sName]	= iIndex;
		
		if( iIndex>=this._iNextIndex )
			this._iNextIndex	= iIndex+1;
	};
	/**
	 *	Get an element's index
	 *	
	 *	@param name The name to search for
	 *	@return The index of the element or -1 on failure (i.e. the element doesn't exist)
	 */
	Enum.prototype.getElementIndex	= function( sName ) {
		return sName in this && this[sName] instanceof Number ? this[sName] : -1;
	};
	
	
	
	/**
	 *	Declare Flags class (Another enumeration class, but values will be powers of two)
	 *	
	 *	Elements may be added using .addFlag( name[, index] )
	 *	An index may have multiple names, but all names must be unique!
	 *	Existence may be checked by calling .getFlag( name )
	 */
	createClass( "Flags" );
	Flags.prototype._iNextIndex		= 0;
	Flags.prototype.Flags	= function() {
		var aFlags		= arguments;
		var bAddAllFlag	= false;
		if( aFlags.length && tools.isArray(aFlags[0]) ) {
			if( aFlags[1] )
				bAddAllFlag	= aFlags[1];
			
			aFlags		= aFlags[0];
		}
		
		for( var i=0; i<aFlags.length; i++ )
			this[ aFlags[i] ]	= i ? 2<<(i-1) : 1;
		
		if( bAddAllFlag )
			this.ALL	= i ? (2<<(i-1))-1 : 0;
		
		this._iNextIndex	= i;
	};
	/**
	 *	Add a new flag to this element
	 *	
	 *	@param sName The name of this flag, usually upper-case
	 *	@param iIndex An optional index that shall be used for this flag, defaults to the next empty index
	 */
	Flags.prototype.addFlag	= function( sName, iIndex ) {
		if( iIndex==undefined )
			iIndex	= this._iNextIndex;
		
		this[sName]	= iIndex ? 2<<(iIndex-1) : 1;
		
		if( iIndex>=this._iNextIndex )
			this._iNextIndex	= iIndex+1;
	};
	/**
	 *	Get a flags value by its name
	 *	
	 *	@param sName The name of the flag
	 */
	Flags.prototype.getFlag	= function( sName ) {
		return sName in this && this[sName] instanceof Number ? this[sName] : 0;
	};
	
	
	
	/**
	 *	A simple class to count the FPS a script/process is running at
	 *	Including smoothing so that updates are still readable at a high frame-rate
	 */
	createClass( "FPSMeter" );
	FPSMeter.prototype._iFrames		= 0;
	FPSMeter.prototype.fLast		= 0.0;
	FPSMeter.prototype.fNow			= 0.0;
	FPSMeter.prototype.fDelta		= 0.0;
	FPSMeter.prototype.fSmoothness	= 2;
	FPSMeter.prototype.fNiceDelta	= 0.0;
	FPSMeter.prototype.sFPS			= "0.0";
	FPSMeter.prototype.sNiceFPS		= "0.0";
	FPSMeter.prototype.iFrames		= 0;
	/**
	 *	Create a FPS counter
	 *
	 *	@param fSmoothness The smoothness factor, set to 1 to disable smoothing.
	 */
	FPSMeter.prototype.FPSMeter		= function( fSmoothness ) {
		this.fLast	=
		this.fNow	= (new Date()).getTime()/1000;
		
		if( fSmoothness )
			this.fSmoothness	= fSmoothness;
	};
	/**
	 *	A new frame begun -> Update FPS
	 *	
	 *	@param iTime (optional) The current timestamp
	 *	@return NULL
	 */
	FPSMeter.prototype.addFrame		= function( iTime ) {
		this.iFrames++;
		this.fLast		= this.fNow;
		this.fNow		= iTime ? iTime : (new Date()).getTime()/1000;
		this.fDelta		= this.fNow - this.fLast;
		this.sFPS		= (1000 / this.fDelta).toFixed( 1 );
		
		this.fNiceDelta	+= (this.fDelta - this.fNiceDelta) / this.fSmoothness;
		this.sNiceFPS	= (1000 / this.fNiceDelta).toFixed( 1 );
	};
	
	
	
	createClass( "ITicker" );
	ITicker.prototypeVirtual( "tick" );	// ( fDelta:float )
	
	createClass( "Timer", "FPSMeter" );
	Timer.prototype._aCall			= [];
	Timer.prototype._iCalls			= 0;
	Timer.prototype._iInterval		= 33;
	Timer.prototype._pInterval		= null;
	Timer.prototype.bOptimize		= false;
	Timer.prototype.pCurrentTicker	= null;
	/**
	 *	Construct a new Timer. You should probably use the static function Timer.add() instead.
	 *	
	 *	@param iInterval The interval to update the listeners
	 *	@param bOptimize Whether or not the calls should be optimized (i.e. inline code should be created)
	 *	@param fSmoothness See FPSMeter
	 */
	Timer.prototype.Timer			= function( iInterval, bOptimize, fSmoothness ) {
		this.FPSMeter( fSmoothness );
		
		this._iInterval		= iInterval;
		this.bOptimize		= bOptimize;
		this.setInterval( iInterval );
	};
	/**
	 *	(Re-)set the interval of this timer
	 *	
	 *	@param iInterval The new interval of the timer. Usually called by Timer.add().
	 *	@return NULL
	 */
	Timer.prototype.setInterval	= function( iInterval ) {
		if( this._pInterval ) {
			delete Timer.pInstances[this._iInterval];
			clearInterval( this._pInterval );
		}
		
		var fChange		= this._iInterval / iInterval;
		this._iCalls	*= fChange;
		var sBody		= "";
		for( var i=0; i<this._aCall.length; i++ ) {
			this._aCall[i].each	*= fChange;
			var sCall			= "this.pCurrentTicker=this._aCall["+i+"]; " + (this._aCall[i].func ? "this.pCurrentTicker.func.call( this.pCurrentTicker.object, " : "this.pCurrentTicker.object.tick( ");
			if( this._aCall[i].each==1 )
				sBody				+=  sCall+"this.fDelta ); if( !this.pCurrentTicker ) this.pCurrentTicker.last=this.fNow; ";
			else
				sBody				+= "if( !(this._iCalls%"+this._aCall[i].each+") ) { "+sCall+" this.fNow-this.pCurrentTicker.last ); if( !this.pCurrentTicker ) this.pCurrentTicker.last=this.fNow; } ";
		}
		
		//console.log( "My body is ", sBody );
		if( this.bOptimize )
			eval( "this.tick		= function() { this.addFrame(); "+sBody+" this._iCalls++; };" );
		else
			this.tick				= Timer.prototype.tick;
		
		this._pInterval			= setInterval( "Timer.pInstances["+this._iInterval+"].tick()", this._iInterval );
		Timer.pInstances[this._iInterval]	= this;
	};
	/**
	 *	The timer ticks! May be overridden if bOptimize was set to true.
	 *	
	 *	@return NULL
	 */
	Timer.prototype.tick		= function() {
		//console.log( ">" );
		
		this.addFrame();
		for( var i=0; i<this._aCall.length; i++ ) {
			var pCall				=
				this.pCurrentTicker	= this._aCall[i];
			if( !(this._iCalls%pCall.each) ) {
				if( pCall.func )
					pCall.func.call( pCall.object, this.fNow-pCall.last );
				else
					pCall.object.tick( this.fNow-pCall.last );
				if( pCall )
					pCall.last	= this.fNow;
			}
		}
		
		this._iCalls++;
	};
	/**
	 *	Add a new function to be called at the given interval using this specific timer
	 *	
	 *	@param iInterval The interval at which the function should be called
	 *	@param pObject The object the given function belongs to (if any)
	 *	@param pFunction The function to be called each *interval* miliseconds
	 *	@return NULL
	 */
	Timer.prototype.add			= function( iInterval, pObject, pFunction ) {
		var each	= iInterval/this._iInterval;
		//console.log( each );
		this._aCall.push( { each:each, object:pObject, func:pFunction, last:(new Date()).getTime()/1000 } );
		
		if( this.bOptimize || !this._aCall.length )
			this.setInterval( this._iInterval );
	};
	/**
	 *	Remove the given object from the listeners
	 *	
	 *	@param pObject The object that doesn't want to receive ticks anylonger
	 *	@return NULL
	 */
	Timer.prototype.remove		= function( pObject ) {
		if( this.pCurrentTicker==pObject )
			this.pCurrentTicker	= null;
		for( var i=0; i<this._aCall.length; i++ )
			if( this._aCall[i].object==pObject ) {
				this._aCall.splice( i, 1 );
				if( this.bOptimize )
					this.setInterval( this._iInterval );
			}
	};
	
	// Build a factory for performance optimization...
	Timer.pInstances		= {};
	Timer.bOptimize			= true;
	/**
	 *	Add a new listener to the timer factory using optimization for similar (i.e. multiples of another) intervals.
	 *	
	 *	@param iInterval The interval at which the function should be called
	 *	@param pObject The object to which the function belongs
	 *	@param pFunction A pointer to the function to be called each *interval* miliseconds. Defaults to *pObject*.tick()
	 *	@return NULL
	 */
	Timer.add				= function( iInterval, pObject, pFunction ) {
		var pTimer;
		for( var i in Timer.pInstances ) {
			var iGCD	= Math.getGCD( [ i, iInterval ] );
			pTimer		= Timer.pInstances[i];
			if( iGCD==i ) {
				pTimer.add( iInterval, pObject, pFunction );
				return;
			}
			else if( iGCD==iInterval ) {
				pTimer.setInterval( iInterval );
				pTimer.add( iInterval, pObject, pFunction );
				return;
			}
		}
		
		pTimer	= new Timer( iInterval, Timer.bOptimize );
		pTimer.add( iInterval, pObject, pFunction );
	};
	/**
	 *	Remove the given object from the Timer
	 *	
	 *	@param pObject The object that doesn't want to receive anymore tick-calls
	 *	@return NULL
	 */
	Timer.remove			= function( pObject ) {
		for( var i in Timer.pInstances )
			Timer.pInstances[i].remove( pObject );
	};
	
	
	
	/**
	 *	The event emitter class acts much like the event emitter of nodeJS with some extended features (see below)
	 */
	createClass( "createClass.EventEmitter" );
	createClass.EventEmitter.prototype._iMaxListeners		= 10;	// Max number of allowed listeners per event
	createClass.EventEmitter.prototype._pListeners			= null;	// All listeners, grouped by event name
	/**
	 *	Create a new event emitter
	 *	
	 *	@param iMaxListeners Max number of allowed listeners per event, if limited. Defaults to 10
	 */
	createClass.EventEmitter.prototype.EventEmitter			= function( iMaxListeners ) {
		
		this._pListeners	= {};
		
		if( iMaxListeners!==undefined )
			this._iMaxListeners	= iMaxListeners;
		
	};
	/**
	 *	Add a new listener
	 *	
	 *	@param sEvent The name of the event to listen to
	 *	@param pCallback The function to be called whenever the event fires. The callback may optionally have an iListenerWeight attribute defining the callback's importance (the lower the weight the earlier it gets called)
	 *	@param (optional) pObject The object that the callback belongs to, if any. Defaults to the event emitter
	 *	@param (optional) bOnce Whether or not the callback shall be fired only once and then be removed. Defaults to FALSE
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.addListener			= function( sEvent, pCallback, pObject, bOnce ) {
		if( !(sEvent in this._pListeners) )
			this._pListeners[sEvent]	= [];
		
		if( !pCallback.iListenerWeight )
			pCallback.iListenerWeight	= 0;
		
		var iIndex		= 0;
		var aListeners	= this._pListeners[sEvent];
		while( iIndex<aListeners.length && pCallback.iListenerWeight>aListeners[iIndex][0].iListenerWeight )
			iIndex++;
		
		this._pListeners[sEvent].splice( iIndex, 0, [ pCallback, !!bOnce, pObject ] );
	};
	/**
	 *	Synonym .addEventListener()
	 */
	createClass.EventEmitter.prototype.on					= createClass.EventEmitter.prototype.addListener;
	/**
	 *	Shortcut for .addEventListener( ..., ..., ..., TRUE )
	 */
	createClass.EventEmitter.prototype.once					= function( sEvent, pCallback, pObject ) {
		return this.addListener( sEvent, pCallback, pObject, true );
	};
	/**
	 *	Remove the given listener
	 *	
	 *	@param sEvent The name of the event you don't want to listen to anylonger
	 *	@param pCallback The function to be removed
	 *	@param pObject (optional) The object that the function belongs to. Defaults to any
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.removeListener		= function( sEvent, pCallback, pObject ) {
		if( !(sEvent in this._pListeners) )
			return;
		
		var aListeners	= this._pListeners[ sEvent ];
		for( var i=0; i<aListeners.length; )
			if( aListeners[i][0]==pCallback && (!pObject || aListeners[i][2]==pObject) ) {
				aListeners.splice( i, 1 );
			}
			else
				i++;
	};
	/**
	 *	Remove all registered listeners
	 *	
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.removeAllListeners	= function() {
		this._pListeners	= {};
	};
	/**
	 *	Set the number of max listeners allowed for this emitter
	 *	
	 *	@param iMaxListeners The new number of allowed listeners per event
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.setMaxListeners		= function( iMaxListeners ) {
		this._iMaxListeners	= iMaxListeners;
		
		for( var sEvent in this._pListeners ) {
			var aListeners	= this._pListeners[ sEvent ];
			while( aListeners.length>iMaxListeners ) {
				console.error( "Removing event listener ", aListeners[ aListeners.length-1 ][0], " for event " + sEvent );
				aListeners.pop();
			}
		}
	};
	/**
	 *	Get a list of all listeners for the given event
	 *	
	 *	@param sEvent The event to get the listeners for
	 *	@return An array containing all listeners, each as [ pCallback, bOnce, pObject ]
	 */
	createClass.EventEmitter.prototype.getListeners			= function( sEvent ) {
		if( !(sEvent in this._pListeners) )
			return [];
		
		return tools.clone( this._pListeners[ sEvent ] );
	};
	/**
	 *	Emit the given event asynchronously. That means that each listener will receive the
	 *	event name as the first argument and a callback to receive the result as a second argument.
	 *	All other arguments will be passed to the listeners. The given callback will be called
	 *	as soon as all listeners have returned their value.
	 *	
	 *	@param sEvent The name of the event to be triggered
	 *	@param pCallback The function to be called once all listeners have returned
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.emitAsync			= function( sEvent, pCallback ) {
		var iCount		= 0;
		var aResults	= [];
		var aArguments	= [ sEvent, function() {
			var aResult		= [];
			aResult.push.apply( aResult, arguments );
			
			aResults.push( aResult );
			
			if( aResults.length==iCount )
				pCallback( aResults );
			
		} ];
		for( var i=2; i<arguments.length; i++ )
			aArguments.push( arguments[i] );
		
		var aReturn		= this.emit.apply( this, aArguments );
		iCount			= aReturn.length;
		
		for( var i=0; i<aReturn.length; i++ )
			if( aReturn[i]!==undefined )
				aResults.push( aReturn[i] );
		
		// For the case that all returned immediately (including none for no listeners)
		if( aResults.length==iCount )
			pCallback( aResults );
		
		return aReturn;
	};
	/**
	 *	Ask all listeners for allowance. If any FALSE or Error is returned, the callback
	 *	will receive FALSE or the given error. If no listener disagrees, the callback
	 *	will be called with TRUE as an argument. Receivers may return asynchronously.
	 *	
	 *	@param sEvent The event to be fired
	 *	@param pCallback The function to be called as soon as all listeners responded
	 *	@return NULL
	 */
	createClass.EventEmitter.prototype.aksForAllowanceAsync	= function( sEvent, pCallback ) {
		var aArguments	= [ sEvent, function( aResults ) {
			for( var i=0; i<aResults.length; i++ )
				if( aResults[i][0]===false || (aResults[i][0] instanceof Error) )
					return pCallback( aResults[i][0] );
			
			return pCallback( true );
		} ];
		
		for( var i=2; i<arguments.length; i++ )
			aArguments.push( arguments[i] );
		
		this.emitAsync.apply( this, aArguments );
	};
	/**
	 *	Same as .aksForAllowanceAsync(), but synchronously, i.e. without a callback
	 *	
	 *	@return FALSE if one of the listeners disagrees or TRUE in any other event
	 */
	createClass.EventEmitter.prototype.askForAllowance		= function() {
		var aResults	= this.emit.apply( this, arguments );
		
		for( var i=0; i<aResults.length; i++ )
			if( aResults[i]===false || (aResults[i] instanceof Error) )
				return aResults[i];
		
		return true;
	};
	/**
	 *	Trigger the given event. Any arguments passed beside the event name will
	 *	be forwarded to the listeners.
	 *	
	 *	@param sEvent The name of the event to be fired
	 *	@return All results as an array
	 */
	createClass.EventEmitter.prototype.emit					= function( sEvent ) {
		if( !(sEvent in this._pListeners) )
			return [];
		
		var aArguments	= [];
		for( var i=1; i<arguments.length; i++ )
			aArguments.push( arguments[i] );
		
		var aResults	= [];
		var aListeners	= this._pListeners[ sEvent ];
		for( var i=0; i<aListeners.length; ) {
			aResults[i]	= aListeners[i][0].apply( aListeners[i][2] ? aListeners[i][2] : this, aArguments );
			
			if( aListeners[i][1] )
				aListeners.splice( i, 1 );
			else
				i++;
		}
		
		return aResults;
	};
	/**
	 *	Synonym for .emit()
	 */
	createClass.EventEmitter.prototype.trigger				= createClass.EventEmitter.prototype.emit;
	/**
	 *	Emit the given event until once of the listeners returns the given condition. Any arguments
	 *	passed after mBreakCondition will be forwarded to all listeners.
	 *	If mBreakCondition is a function, that function will be called with the returned value of the
	 *	listener to check whether or not it fulfills the break condition.
	 *	
	 *	@param sEvent The name of the event to be triggered
	 *	@param mBreakCondition The condition after which to return. Defaults to FALSE
	 *	@return TRUE of the condition was met or FALSE if not
	 */
	createClass.EventEmitter.prototype.emitUntil			= function( sEvent, mBreakCondition ) {
		if( typeof mBreakCondition=='undefined' )
			mBreakCondition	= false;
		var bIsFunction	= typeof mBreakCondition=='function';
		
		if( !(sEvent in this._pListeners) )
			return;
		
		var aArguments	= [];
		for( var i=2; i<arguments.length; i++ )
			aArguments.push( arguments[i] );
		
		var aResults		= [];
		var aListeners		= this._pListeners[ sEvent ];
		var bConditionMet	= false;
		for( var i=0; i<aListeners.length; ) {
			aResults[i]	= aListeners[i][0].apply( aListeners[i][2] ? aListeners[i][2] : this, aArguments );
			
			if( (bIsFunction && mBreakCondition( aResults[i] )) || aResults[i]===mBreakCondition ) {
				bConditionMet	= true;
			}
			
			if( aListeners[i][1] )
				aListeners.splice( i, 1 );
			else
				i++;
			
			if( bConditionMet )
				break;
		}
		
		return bConditionMet;
	};
	/**
	 *	Emit the given event until once of the listeners returns the given type. Any arguments
	 *	passed after sType will be forwarded to all listeners.
	 *	
	 *	@param sEvent The name of the event to be triggered
	 *	@param sType The listener return type after which to break or '*' for any type except 'undefined'. Defaults to '*'
	 *	@return The first returned value that matched the type or UNDEFINED if none matched.
	 */
	createClass.EventEmitter.prototype.emitUntilType		= function( sEvent, sType ) {
		
		if( !sType )
			sType	= '*';
		
		if( !(sEvent in this._pListeners) )
			return;
		
		var aArguments	= [];
		for( var i=2; i<arguments.length; i++ )
			aArguments.push( arguments[i] );
		
		var aListeners		= this._pListeners[ sEvent ];
		var bConditionMet	= false;
		for( var i=0; i<aListeners.length; ) {
			var mReturned	= aListeners[i][0].apply( aListeners[i][2] ? aListeners[i][2] : this, aArguments );
			
			if( sType=='*' ? typeof(mReturned)!='undefined' : typeof(mReturned)==sType ) {
				bConditionMet	= true;
			}
			
			if( aListeners[i][1] )
				aListeners.splice( i, 1 );
			else
				i++;
			
			if( bConditionMet )
				return mReturned;
		}
		
		return;
	};
	/**
	 *	Get an instance of the given class from one of the listeners
	 *	
	 *	@param sEvent The event to fire
	 *	@param pClass The class to get an instance for
	 *	@return The class instance if one was created or NULL if no listener could create one (or created one of a wrong type)
	 */
	createClass.EventEmitter.prototype.emitFactory			= function( sEvent, pClass ) {
		var pResult		= null;
		
		var aArguments	= arguments;
		aArguments[1]	= function(pCandidate) {
			if( pCandidate && pCandidate instanceof Class && pCandidate.instanceOf( pClass ) ) {
				pResult		= pCandidate;
				return true;
			}
		};
		
		this.emitUntil.apply( this, aArguments );
		
		return pResult;
	};
	
	/**
	 *	A staged event emitter will receive a list of all events (best practice: in the order that they appear).
	 *	Once an event has been triggered it will be flagged as such and if any listener gets assigned after that
	 *	event was fired, it's callback will be immediately called. So if you have the events ["create","init","start",...]
	 *	And you fire "create" and then "init", after which a new listener registers, that listener will immediately
	 *	receive the "create" and "init" events (as well as any events you trigger later of course).
	 *	
	 *	Currently doesn't work with async calls (we didn't find a use case for that).
	 */
	createClass( "StagedEventEmitter", "createClass.EventEmitter" );
	StagedEventEmitter.prototype._pStagedEvents			= null;
	/**
	 *	Construct a new Staged Event Emitter
	 *	
	 *	@param aStagedEvents A list of all staged events in their chronological order
	 */
	StagedEventEmitter.prototype.StagedEventEmitter		= function( aStagedEvents ) {
		this.EventEmitter();
		
		this._pStagedEvents	= {};
		for( var i=0; i<aStagedEvents.length; i++ )
			this._pStagedEvents[ aStagedEvents[i] ]	= false;
	};
	/**
	 *	Overwrite .addListener() to trigger some events immediately.
	 *	
	 *	@see createClass.EventEmitter.addListener
	 */
	StagedEventEmitter.prototype.addListener			= function( sEvent, pCallback, pObject, bOnce ) {
		if( (sEvent in this._pStagedEvents) && this._pStagedEvents[sEvent] ) {
			pCallback.apply( pObject ? pObject : this, [] );
			if( bOnce )
				return;
		}
		
		this.__parent.addListener.apply( this, arguments );
	};
	/**
	 *	Overwrite .emit() to save the state of staged events.
	 *	
	 *	@see ss.EventEmitter.emit
	 */
	StagedEventEmitter.prototype.emit					= function( sEvent ) {
		if( sEvent in this._pStagedEvents )
			this._pStagedEvents[ sEvent ]	= true;
		
		this.__parent.emit.apply( this, arguments );
	};
	
})();