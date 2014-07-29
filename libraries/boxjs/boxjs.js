/*
 * BoxJS (v 0.1.0)
 * Copyright (c) 2012 Thiemo Müller
 * MORPOL Softwareentwicklung (boxjs@morpol.de, www.morpol.de)
 * 
 * BoxJS is a simple JavaScript web framework allowing you to
 * easily manage and display small content boxes shown above
 * your actual webpage, e.g. background file upload handlers,
 * progress boxes or small forms. Requires createClass as well
 * as jQuery. Will use Inter Tab JS to sync boxes between
 * tabs/windows if available and configured.
 * If you have any questions, bug reports or feature requests please
 * contact boxjs@morpol.de
 * 
 * https://github.com/MORPOL/boxjs
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
	
	createClass( "BoxJS", "createClass.EventEmitter" );
	BoxJS.pTranslations						= {
		'en'									: {
			box										: {
				action_minimize							: 'Minimize',
				action_restore							: 'Restore',
				action_maximize							: 'Maximize',
				action_close							: 'Close',
				dialog_button_cancel					: 'Cancel',
				dialog_button_close						: 'Close',
				dialog_button_ok						: 'OK',
				dialog_button_no						: 'No',
				dialog_button_yes						: 'Yes',
			},
			control_box								: {
				halign_left								: 'Left',
				halign_right							: 'Right',
				valign_top								: 'Top',
				valign_bottom							: 'Bottom',
				orientation_horizontal					: 'Horizontal',
				orientation_vertical					: 'Vertical',
				minimize_all							: 'Minimize All',
				close_all								: 'Close All'
			}
		}
	};
	BoxJS.INSTANCES								= {};
	BoxJS.INSTANCE_ID							= 1;
	BoxJS.prototype.sFrameURL					= null;
	BoxJS.prototype.pHandlers					= null;
	BoxJS.prototype.pMaximizedBox				= null;
	BoxJS.prototype.aRestoreBoxes				= null;
	BoxJS.prototype.aBoxes						= null;
	BoxJS.prototype.aInPageBoxes				= null;
	BoxJS.prototype.sVerticalAlign				= null;
	BoxJS.prototype.sHorizontalAlign			= null;
	BoxJS.prototype.sOrientation				= null;
	BoxJS.prototype.bSortable					= false;
	BoxJS.prototype.iMargin						= 0;
	BoxJS.prototype.pPageElement				= null;
	BoxJS.prototype.pBackgroundElement			= null;
	BoxJS.prototype.iInstanceIndex				= 0;
	BoxJS.prototype.bChanged					= false;
	BoxJS.prototype.iUpdateCount				= 0;
	BoxJS.prototype.pInterTabJSHandler			= 0;
	BoxJS.prototype.sBox						= null;
	BoxJS.prototype.iParentFrameSessionID		= 0;
	BoxJS.prototype.pBox						= null;
	BoxJS.prototype.pDraggingBox				= null;
	BoxJS.prototype.iLastDragSort				= 0;
	BoxJS.prototype.iDraggedBoxOriginalIndex	= 0;
	BoxJS.prototype.fMaximizeAnimationLength	= .5;
	BoxJS.prototype.fMinimizeAnimationLength	= .33;
	BoxJS.prototype.bIniting					= true;
	BoxJS.prototype.pControlBox					= false;
	BoxJS.prototype.BoxJS						= function( pConfig, pInterTabJS, pPageElement ) {
		
		this.EventEmitter();
		
		var sVerticalAlign			= pConfig.vertical_align;
		var sHorizontalAlign		= pConfig.horizontal_align;
		var sOrientation			= pConfig.orientation;
		var bSortable				= pConfig.sortable;
		var iMargin					= pConfig.margin;
		var sBox					= pConfig.box;
		var sFrameURL				= pConfig.frame_url;
		var iParentFrameSessionID	= pConfig.parent;
		
		this.pHandlers				= {};
		this.aBoxes					= [];
		this.aInPageBoxes			= [];
		
		this.sVerticalAlign			= sVerticalAlign ? sVerticalAlign : "bottom";
		this.sHorizontalAlign		= sHorizontalAlign ? sHorizontalAlign : "right";
		this.sOrientation			= sOrientation ? sOrientation : "horizontal";
		
		this.bSortable				= !!bSortable;
		this.pPageElement			= pPageElement ? pPageElement : $('body');
		this.iMargin				= typeof iMargin!='undefined' ? iMargin : 10;
		
		this.sBox					= sBox;
		this.sFrameURL				= sFrameURL;
		this.iParentFrameSessionID	= iParentFrameSessionID;
		
		this.pBackgroundElement	= $('<div id="boxjs-background"><div id="boxjs-background-inner"></div></div>')
			.css( { position:"fixed" } )
			.appendTo( this.pPageElement );
		
		var pBoxJS				= this;
		$(window).resize( function(e) {
			
			pBoxJS.reorderInPageBoxes();
			
		} );
		
		if( pConfig.control_box && !this.sBox )
			this.pControlBox	= new BoxJS.ControlBox( this, {sID:'boxjs-control-box',bSync:false,sClass:'BoxJS.ControlBox'}, BoxJS.Box.FRAME_MODES.NONE );
		
		this.iInstanceIndex	= BoxJS.INSTANCE_ID++;
		BoxJS.INSTANCES[this.iInstanceIndex]	= this;
		
		if( pInterTabJS ) {
			this.pInterTabJSHandler	= pInterTabJS.addHandler( "boxjs", {pBoxJS:this}, true );
			
			this.pInterTabJSHandler.pManager.initHandler( this.pInterTabJSHandler );
		}
		
		this.pPageElement.trigger( 'boxjs' );
		
		this.bIniting	= false;
		
	};
	BoxJS.prototype.setVerticalAlign		= function( sValue, bDontSync ) {
		this.sVerticalAlign		= sValue;
		this.emit( 'vertical_align_changed' );
		
		this.reorderInPageBoxes();
		
		if( !bDontSync )
			this.sync();
	};
	BoxJS.prototype.setHorizontalAlign		= function( sValue, bDontSync ) {
		this.sHorizontalAlign	= sValue;
		this.emit( 'horizontal_align_changed' );
		
		this.reorderInPageBoxes();
		
		if( !bDontSync )
			this.sync();
	};
	BoxJS.prototype.setOrientation			= function( sValue, bDontSync ) {
		this.sOrientation		= sValue;
		this.emit( 'orientation_changed' );
		
		this.reorderInPageBoxes();
		
		if( !bDontSync )
			this.sync();
	};
	BoxJS.prototype.translate				= function( sNameSpace, sKey, pTokens ) {
		var sMessage	= BoxJS.pTranslations['en'][sNameSpace][sKey];
		
		if( pTokens ) {
			for( var sName in pTokens )
				sMessage	= sMessage.replace( new RegExp( '\\['+sName+'\\]', 'g' ), pTokens[sName] );
		}
		
		return sMessage;
	};
	BoxJS.prototype.getFrameURL				= function( sBox ) {
		return BoxJS.replaceTokens( this.sFrameURL, { box:sBox } );
	};
	BoxJS.prototype.getBoxByID				= function( sID ) {
		for( var i=0; i<this.aBoxes.length; i++ ) {
			if( this.aBoxes[i].sID==sID ) {
				return this.aBoxes[i];
			}
		}
	};
	BoxJS.prototype.closeBox				= function( sID ) {
		
		var pBox	= this.getBoxByID( sID );
		//pBox.bSync	= false;
		if( pBox )
			pBox.handleAction( 'close', null, true );
		
	};
	BoxJS.prototype.createBox				= function( pBoxData, sType ) {
		if( !sType )
			sType	= 'simple';
		
		if( !pBoxData )
			pBoxData		= {};
		
		if( !pBoxData.sID ) {
			if( pBoxData.pConfig && pBoxData.pConfig.id ) {
				pBoxData.sID	= pBoxData.pConfig.id;
			}
			else {
				var iID	= 1;
				while( this.getBoxByID( pBoxData.sID=sType+'-'+iID ) )
					iID++;
			}
		}
		
		var iFrameMode	= pBoxData.sID==this.sBox ? BoxJS.Box.FRAME_MODES.IFRAME : BoxJS.Box.FRAME_MODES.NONE;
		var pBox		= pBoxData.sClass ? createClass.instantiate( pBoxData.sClass, [ this, pBoxData, iFrameMode ] ) : new BoxJS.pBoxTypes[sType]( this, pBoxData, iFrameMode );
		
		if( this.pMaximizedBox ) {
			this.aRestoreBoxes.push( pBox );
			pBox.handleAction( 'minimize' );
		}
		
		return pBox;
	};
	BoxJS.prototype.updateBox				= function( sID, pBoxData ) {
		
		var pBox	= this.getBoxByID( sID );
		if( pBox )
			return pBox.setSyncData( pBoxData );
		
		if( !pBoxData.sID )
			pBoxData.sID	= sID;
		
		if( !this.sBox || this.sBox==sID ) {
			var pBox	= createClass.instantiate( pBoxData.sClass, [ this, pBoxData, (this.sBox==sID?BoxJS.Box.FRAME_MODES.IFRAME:BoxJS.Box.FRAME_MODES.NONE) ] );
			if( this.sBox )
				this.pBox	= pBox;
		}
	};
	BoxJS.prototype.insertBoxAt				= function( pBox, iLeft, iTop, bFinal, bReset ) {
		var iNow	= (new Date()).getTime();
		if( !bFinal && this.iLastDragSort+500>iNow )
			return;
		
		var iIndex	= $.inArray( pBox, this.aInPageBoxes );
		
		if( bFinal ) {
			this.pDraggingBox	= null;
			if( bReset ) {
				this.aInPageBoxes.splice( iIndex, 1 );
				this.aInPageBoxes.splice( this.iDraggedBoxOriginalIndex, 0, pBox );
			}
			
			this.reorderInPageBoxes();
			return;
		}
		else if( !this.pDraggingBox ) {
			this.iDraggedBoxOriginalIndex	= $.inArray( pBox, this.aInPageBoxes );
			this.pDraggingBox				= pBox;
		}
		
		var bTopAligned		= this.sVerticalAlign=="top";
		var bLeftAligned	= this.sHorizontalAlign=="left";
		var bVertical		= this.sOrientation=="vertical";
		
		var i		= 0;
		var pItem;
		if( bVertical ) {
			if( bLeftAligned )
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().left+(pItem.iContainerWidth!==null?pItem.iContainerWidth:pItem.pContainer.outerWidth())*2/3<iLeft )
					i++;
			else
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().left-(pItem.iContainerWidth!==null?pItem.iContainerWidth:pItem.pContainer.outerWidth())/3>iLeft )
					i++;
			
			if( bTopAligned )
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().top+(pItem.iContainerHeight!==null?pItem.iContainerHeight:pItem.pContainer.outerHeight())<iTop )
					i++;
			else
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().top>iTop )
					i++;
		}
		else {
			if( bTopAligned )
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().top+(pItem.iContainerHeight!==null?pItem.iContainerHeight:pItem.pContainer.outerHeight())*2/3<iTop )
					i++;
			else
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().top-(pItem.iContainerHeight!==null?pItem.iContainerHeight:pItem.pContainer.outerHeight())/3>iTop )
					i++;
			
			if( bLeftAligned )
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().left+(pItem.iContainerWidth!==null?pItem.iContainerWidth:pItem.pContainer.outerWidth())<iLeft )
					i++;
			else
				while( (pItem=this.aInPageBoxes[ i ]) && pItem.pContainer.offset().left>iLeft )
					i++;
		}
		
		if( iIndex!=i ) {
			this.aInPageBoxes.splice( iIndex, 1 );
			this.aInPageBoxes.splice( i, 0, pBox );
			
			this.iLastDragSort	= iNow;
			
			this.reorderInPageBoxes();
		}
	};
	BoxJS.prototype.getSessionID			= function() {
		
		return this.pInterTabJSHandler ? this.pInterTabJSHandler.pManager.iSessionID : null;
		
	};
	BoxJS.prototype.sync					= function() {
		
		if( !this.pInterTabJSHandler )
			return;
		
		var pData	= this.pInterTabJSHandler.getData();
		var pBoxes	= pData.pBoxes;
		
		for( var i=0; i<this.aBoxes.length; i++ ) {
			
			var pBox	= this.aBoxes[i];
			if( pBox.bSync ) {
				
				pBoxes[ pBox.sID ]	= pBox.getSyncData();
				
			}
			
		}
		
		pData.sVerticalAlign	= this.sVerticalAlign;
		pData.sHorizontalAlign	= this.sHorizontalAlign;
		pData.sOrientation		= this.sOrientation;
		
		this.pInterTabJSHandler.setData( pData );
		
	};
	BoxJS.prototype.reorderInPageBoxes  	= function() {
		if( this.sBox )
			return;
		
		if( this.aInPageBoxes.length==( this.pControlBox ? 1 : 0 ) ) {
			if( !this.pPageElement.hasClass('boxjs-no-boxes') )
				this.pPageElement.addClass('boxjs-no-boxes')
		}
		else {
			this.pPageElement.removeClass('boxjs-no-boxes');
		}
		
		//console.error( this.getSessionID(), 'disorder', this.aInPageBoxes.length?this.aInPageBoxes[0].iContainerHeight:undefined, this.aInPageBoxes.length?this.aInPageBoxes[0].iRContainerHeight:undefined );
		var iMargin			= this.iMargin;
		
		var bTopAligned		= this.sVerticalAlign=="top";
		var bLeftAligned	= this.sHorizontalAlign=="left";
		
		var bVertical		= this.sOrientation=="vertical";
		var iDown			= !bVertical ? 0 : ( bTopAligned ? 1 : -1 );
		var iRight			= bVertical ? 0 : ( bLeftAligned ? 1 : -1 );
		
		var bFixedParent	= this.pPageElement.css('position')=='fixed';
		var iPageHeight		= bFixedParent ? this.pPageElement.innerHeight() : $(window).height();
		var iPageWidth		= bFixedParent ? this.pPageElement.innerWidth() : $(window).width();
		iPageHeight			-= this.pPageElement.outerHeight(true) - this.pPageElement.outerHeight();
		iPageWidth			-= this.pPageElement.outerWidth(true) - this.pPageElement.outerWidth();
		
		var pOffset			= this.pPageElement.offset();
		var iPageLeft		= pOffset.left;
		var iPageTop		= pOffset.top;
		var iLeft			= bLeftAligned ? iMargin : iPageWidth;
		var iTop			= bTopAligned ? iMargin : iPageHeight;
		
		if( iDown && !bLeftAligned )
			iLeft	-= iMargin;
		if( iRight && !bTopAligned )
			iTop	-= iMargin;
		
		var iStartLeft		= iLeft;
		var iStartTop		= iTop;
		
		var aInPageBoxes	= this.aInPageBoxes;
		var bChanged		= false;
		
		var iMaxHeight		= 0;
		var iMaxWidth		= 0;
		
		
		var bContinued		= true;
		var iMaxLineSize	= null;
		
		for( var i=0; i<aInPageBoxes.length; i++ ) {
			/*aInPageBoxes[i].pContainer
				.appendTo( this.pPageElement );*/
			
			var pBox	= aInPageBoxes[i];
			
			if( this.sBox || this.pMaximizedBox==pBox )
				continue;
			
			var iElementTop		= iTop;
			var iElementLeft	= iLeft;
			
			var iHeight			= pBox.iContainerHeight!==null ? pBox.iContainerHeight : pBox.pContainer.outerHeight();
			var iWidth			= pBox.iContainerWidth!==null ? pBox.iContainerWidth : pBox.pContainer.outerWidth();
			
			if( iDown<0 ) {
				iElementTop		= (iTop -= iHeight + iMargin);
				if( iTop<0 && !bContinued ) {
					if( iMaxLineSize===null || iElementTop<iMaxLineSize )
						iMaxLineSize	= iElementTop;
					iElementTop		= 
					iTop			= iStartTop;
					iElementLeft	= (iLeft += (bLeftAligned ? 1 : -1) * (iMaxWidth + iMargin));
					bContinued		= true;
					--i;
					continue;
				}
			}
			else if( iDown==0 ) {
				if( !bTopAligned )
					iElementTop		-= iHeight;
			}
			else {
				if( iElementTop+iHeight>iPageHeight && !bContinued ) {
					if( iMaxLineSize===null || iElementTop>iMaxLineSize )
						iMaxLineSize	= iElementTop;
					iElementTop		= 
					iTop			= iStartTop;
					iElementLeft	= (iLeft += (bLeftAligned ? 1 : -1) * (iMaxWidth + iMargin));
					bContinued		= true;
					--i;
					continue;
				}
			}
			
			if( iRight<0 ) {
				iElementLeft	= (iLeft -= iWidth + iMargin);
				if( iLeft<0 && !bContinued ) {
					if( iMaxLineSize===null || iElementLeft<iMaxLineSize )
						iMaxLineSize	= iElementLeft;
					iElementLeft	= 
					iLeft			= iStartLeft;
					iElementTop		= (iTop += (bTopAligned ? 1 : -1) * (iMaxHeight + iMargin));
					bContinued		= true;
					--i;
					continue;
				}
			}
			else if( iRight==0 ) {
				if( !bLeftAligned )
					iElementLeft	-= iWidth;
			}
			else {
				if( iElementLeft+iWidth>iPageWidth && !bContinued ) {
					if( iMaxLineSize===null || iElementLeft>iMaxLineSize )
						iMaxLineSize	= iElementLeft;
					iElementLeft	= 
					iLeft			= iStartLeft;
					iElementTop		= (iTop += (bTopAligned ? 1 : -1) * (iMaxHeight + iMargin));
					bContinued		= true;
					--i;
					continue;
				}
			}
			
			if( iHeight>iMaxHeight || bContinued )
				iMaxHeight	= iHeight;
			if( iWidth>iMaxWidth || bContinued )
				iMaxWidth	= iWidth;
			
			var sLeft			= pBox.pContainer.css( 'left' );
			var sTop			= pBox.pContainer.css( 'top' );
			if( (sLeft!=iElementLeft+'px' || sTop!=iElementTop+'px') /*&& this.pDraggingBox!=pBox*/ ) {
				bChanged			= true;
				var bFadeIn			= !sLeft || !sTop || sLeft=='auto' || sTop=='auto';
				var pCSS			= {
					position	: 'fixed',
					zIndex		: i+100,
					width		: '',
					height		: ''
				};
				var pTransition		= {
					left		: iElementLeft+iPageLeft + 'px',
					top			: iElementTop+iPageTop + 'px',
					queue		: false
				};
				if( bFadeIn ) {
					pCSS.opacity		= 0;
					pTransition.opacity	= 1;
				}
				
				pBox.pContainer
					.css( pCSS );
				if( this.bIniting )
					pBox.pContainer.css( pTransition );
				else
					pBox.pContainer.transition( pTransition );
				
				if( bFadeIn )
					pBox.pContainer.transition( { opacity:'' }, 0 );
				
			}
			
			if( iDown>0 )
				iTop	+= iHeight + iMargin;
			if( iRight>0 )
				iLeft	+= iWidth + iMargin;
			
			bContinued	= false;
		}
		
		if( bChanged ) {
			iStartLeft	+= (bLeftAligned ? -1  : 1) * iMargin;
		}
		if( bChanged ) {
			iStartTop	+= (bTopAligned ? -1  : 1) * iMargin;
		}
		
		if( iDown<0 )
			iTop      -= iMargin;
		if( iRight<0 )
			iLeft     -= iMargin;
		
		iLeft	+= bVertical ? (bLeftAligned?1:-1) * (iMaxWidth+iMargin) : 0;
		iTop	+= !bVertical ? (bTopAligned?1:-1) * (iMaxHeight+iMargin) : 0;
		
		if( this.pMaximizedBox ) {
			iStartLeft	+= (bLeftAligned ? -1  : 1) * iMargin;
			iStartTop	+= (bTopAligned ? -1  : 1) * iMargin;
			
			this.pBackgroundElement
				.css( {
					left    : "0px",
					top     : "0px",
					width   : "100%",
					height  : "100%"
				} );
			
			var iSizeH	= Math.abs( iLeft-iStartLeft );
			var iSizeV	= Math.abs( iTop-iStartTop );
			if( bVertical ) {
				iLeft	= bLeftAligned ? iSizeH : iMargin;
				iTop	= iMargin;
				iWidth	= iPageWidth - iSizeH - 2*iMargin;
				iHeight	= iPageHeight - 3*iMargin;
			}
			else {
				iLeft	= iMargin;
				iTop	= bTopAligned ? iSizeV : iMargin;
				iWidth	= iPageWidth - 2*iMargin;
				iHeight	= iPageHeight - iSizeV - 2*iMargin;
			}
			
			this.pMaximizedBox.pContainer
				.css( {
					zIndex		: '1000'
				} )
				.transition( {
					left		: iPageLeft+iLeft,
					top			: iPageTop+iTop,
					width		: iWidth,
					height		: iHeight,
					queue		: false
				} );
			//return;
		}
		else {
			this.pBackgroundElement
				.css( {
					left    : iPageLeft+(iLeft<iStartLeft ? iLeft : iStartLeft) + "px",
					top     : iPageTop+(iTop<iStartTop ? iTop : iStartTop) + "px",
					width   : iMaxLineSize!==null && !bVertical ? iMaxLineSize+"px" : Math.abs( iLeft-iStartLeft ) + "px",
					height  : iMaxLineSize!==null && bVertical ? iMaxLineSize+"px" : Math.abs( iTop-iStartTop ) + "px"
				} );
		}
		
		return bChanged;
		
	};
	BoxJS.prototype.unmaximizeBox			= function( pHandler ) {
		this.pPageElement.removeClass( 'boxjs-maximized-box' );
		
		var aRestoreBoxes	= this.aRestoreBoxes;
		this.aRestoreBoxes	= null;
		
		if( aRestoreBoxes )
			for( var i=0; pBox=aRestoreBoxes[i]; i++ ) {
				pBox.handleAction( 'restore' );
			}
		
		this.pMaximizedBox	= null;
		this.reorderInPageBoxes();
		
		return true;
	};
	BoxJS.prototype.maximizeBox       		= function( pHandler ) {
		if( this.pMaximizedBox ) {
			this.pMaximizedBox.handleAction( 'restore' );
		}
		
		this.pPageElement.addClass( 'boxjs-maximized-box' );
		
		this.aRestoreBoxes	= [];
		
		for( var i=0; pBox=this.aInPageBoxes[i]; i++ ) {
			if( pBox==pHandler )
				continue;
			
			if( !pBox.pStates.minimized.state ) {
				pBox.handleAction( 'minimize' );
				this.aRestoreBoxes.push( pBox );
			}
		}
		
		this.pMaximizedBox	= pHandler;
		this.reorderInPageBoxes();
		
		return true;
	};
	BoxJS.prototype.minimizeAll       		= function( aExcept ) {
		for( var i=0; pBox=this.aInPageBoxes[i]; i++ ) {
			if( $.inArray(pBox,aExcept)>=0 )
				continue;
			
			if( !pBox.pStates.minimized.state )
				pBox.handleAction( 'minimize' );
		}
	};
	BoxJS.prototype.closeAll       			= function( aExcept ) {
		for( var i=0; pBox=this.aInPageBoxes[i]; i++ ) {
			if( $.inArray(pBox,aExcept)>=0 )
				continue;
			
			pBox.handleAction( 'close' );
			i--;
		}
	};
	BoxJS.prototype.registerHandler			= function( pHandler ) {
		this.pHandlers[ pHandler.sName ] = pHandler;
	};
	BoxJS.prototype.addBox					= function( pBox, pReplace )  {
		var iIndex	= pReplace ? $.inArray( pReplace, this.aBoxes ) : this.aBoxes.length;
		
		this.aBoxes.splice( iIndex, 1, pBox );
		if( pBox.iFrameMode==BoxJS.Box.FRAME_MODES.NONE ) {
			iIndex	= pReplace ? $.inArray( pReplace, this.aInPageBoxes ) : this.aInPageBoxes.length;
			this.aInPageBoxes.splice( iIndex, 1, pBox );
		}
		
		pBox.pContainer.appendTo( this.pPageElement );
		
		this.reorderInPageBoxes();
		
		if( this.pInterTabJSHandler ) {
			
			var pData	= this.pInterTabJSHandler.getData();
			if( pBox.sID in pData.pClosed )
				delete pData.pClosed[ pBox.sID ];
			
			this.sync();
		}
	};
	BoxJS.prototype.removeBox				= function( pBox ) {
		createClass.Tools.findAndRemove( this.aBoxes, pBox );
		createClass.Tools.findAndRemove( this.aInPageBoxes, pBox );
		
		pBox.pContainer.detach();
		
		if( pBox.bSync && this.pInterTabJSHandler ) {
			var pData	= this.pInterTabJSHandler.getData();
			
			if( pBox.sID in pData.pBoxes )
				delete pData.pBoxes[ pBox.sID ];
			
			if( !(pBox.sID in pData.pClosed) ) {
				pData.pClosed[ pBox.sID ]	= InterTabJS.getTimeStamp();
			
				//console.error( pBox, pData.pBoxes[ pBox.sID ], pData.pClosed[ pBox.sID ] );
				
				this.sync();
				
				//console.error( pBox, pData.pBoxes[ pBox.sID ], pData.pClosed[ pBox.sID ] );
			}
		}
		
		this.reorderInPageBoxes();
	};
	BoxJS.pBoxTypes							= {};
	
	
	
	if( window.InterTabJS ) {
		createClass( "InterTabJS.Handler.BoxJS", "InterTabJS.Handler" );
		InterTabJS.Handler.pTypes.boxjs						= InterTabJS.Handler.BoxJS;
		InterTabJS.Handler.BoxJS.prototype.sKey				= "boxjs";
		InterTabJS.Handler.BoxJS.prototype.pBoxJS			= null;
		InterTabJS.Handler.BoxJS.prototype.pData			= null;
		InterTabJS.Handler.BoxJS.prototype.iLastUpdate		= 0;
		InterTabJS.Handler.BoxJS.prototype.bUpdating		= false;
		InterTabJS.Handler.BoxJS.prototype.BoxJS			= function( pManager, pConfig ) {	
			this.Handler( pManager );
			
			this.pBoxJS			= pConfig.pBoxJS;
		};
		InterTabJS.Handler.BoxJS.prototype.getData			= function() {
			
			if( !this.pData || !this.pData.pBoxes || !this.pData.pClosed ) {
				this.pData	= { pBoxes:{}, pClosed:{} };
			}
			else {
				var iNow	= InterTabJS.getTimeStamp();
				for( var sID in this.pData.pClosed )
					if( this.pData.pClosed[sID]+INTER_TAB_JS.CACHE_TIME<iNow )
						delete this.pData.pClosed[ sID ];
			}
			
			return this.pData;
			
		};
		InterTabJS.Handler.BoxJS.prototype.setData			= function( pData ) {
			
			this.pManager.update( this.sKey, pData );
			
			this.iLastUpdate	= InterTabJS.getTimeStamp();
			
		};
		InterTabJS.Handler.BoxJS.prototype.init				= function( mData, iLastUpdate, iSessionID ) {
			
			this.pData	= mData;
			this.changed( this.getData(), iLastUpdate, iSessionID );
			
		};
		InterTabJS.Handler.BoxJS.prototype.changed			= function( mData, iChanged, iSessionID, sRawValue, sOldRawValue ) {
			
			if( this.bUpdating )
				return;
			
			this.bUpdating	= true;
			
			if( mData.sVerticalAlign!=this.pBoxJS.sVerticalAlign )
				this.pBoxJS.setVerticalAlign( mData.sVerticalAlign, true );
			
			if( mData.sHorizontalAlign!=this.pBoxJS.sHorizontalAlign )
				this.pBoxJS.setHorizontalAlign( mData.sHorizontalAlign, true );
			
			if( mData.sOrientation!=this.pBoxJS.sOrientation )
				this.pBoxJS.setOrientation( mData.sOrientation, true );
			
			this.pData			= mData;
			var pBoxes			= mData.pBoxes;
			var iLastUpdate		= this.iLastUpdate;
			//this.iLastUpdate	= InterTabJS.getTimeStamp();
			
			for( var sName in pBoxes ) {
				
				//console.log( sName );
				if( pBoxes[sName].iChanged>=iLastUpdate ) {
					this.pBoxJS.updateBox( sName, pBoxes[sName] );
				}
				
			}
			
			var pClosed			= mData.pClosed;
			for( var sID in pClosed ) {
				this.pBoxJS.closeBox( sID );
			}
			
			this.bUpdating		= false;
			
		};
	}
	
	
	
	BoxJS.replaceTokens                   = function( sURL, pTokens ) {
		for( var sKey in pTokens )
			sURL  = sURL.replace( new RegExp( "\\["+sKey+"\\]", "g" ), pTokens[ sKey ] );
		
		return sURL;
	};
	
	
	
	createClass( "BoxJS.Box", ["Destructable","createClass.EventEmitter"] );
	BoxJS.Box.FRAME_MODES						= new Enum( 'NONE', 'WINDOW', 'IFRAME' );
	BoxJS.Box.prototype.pContainer				= null;
	BoxJS.Box.prototype.pBoxJS					= null;
	BoxJS.Box.prototype.iFrameMode				= false;
	BoxJS.Box.prototype.bSync					= false;
	BoxJS.Box.prototype.iSessionID				= 0;
	BoxJS.Box.prototype.sID						= 0;
	BoxJS.Box.prototype.iChanged				= 0;
	BoxJS.Box.prototype.pDropTargets			= null;
	BoxJS.Box.prototype.mDropTargets			= null;
	BoxJS.Box.prototype.pActions				= null;
	BoxJS.Box.prototype.pStates					= null;
	BoxJS.Box.prototype.pRuntimeStates			= null;
	BoxJS.Box.prototype.iContainerHeight		= null;
	BoxJS.Box.prototype.iContainerWidth			= null;
	BoxJS.Box.prototype.sDraggable				= null;
	BoxJS.Box.prototype.pDraggableHelper		= null;
	BoxJS.Box.prototype.iChildFrameSessionID	= null;
	BoxJS.Box.prototype.Box						= function( pBoxJS, pBoxData, iFrameMode ) {
		this.EventEmitter();
		
		this.pBoxJS			= pBoxJS;
		this.iFrameMode		= iFrameMode ? iFrameMode : BoxJS.Box.FRAME_MODES.NONE;
		this.bSync			= pBoxData.bSync;
		this.sID			= pBoxData.sID;
		this.iSessionID		= pBoxData.iSessionID ? pBoxData.iSessionID : this.pBoxJS.getSessionID();
		this.iChanged		= pBoxData.iChanged ? pBoxData.iChanged : (window.InterTabJS ? InterTabJS.getTimeStamp() : null);
		this.mDropTargets	= pBoxData.mDropTargets ? pBoxData.mDropTargets : null;
		
		this.pContainer		= (pBoxData.pReplace ? pBoxData.pReplace.pContainer.attr('class','').html('') : $('<div />'))
			.addClass( 'boxjs-box' )
			.attr( 'id', 'boxjs-box-'+this.sID.replace( /([^a-z0-9\-])/g, "-" ) )
			.data( 'box', this );
		
		this.pContainer.addClass( this.iFrameMode ? 'boxjs-framed-box' : 'boxjs-unframed-box' );
		
		
		if( !this.pActions )
			this.pActions			= {};
		this.registerActions();
		
		
		if( !this.pStates )
			this.pStates			= {};
		if( !this.pRuntimeStates )
			this.pRuntimeStates		= {};
		this.registerStates();
		for( var sName in this.pStates ) {
			this.setState( sName, this.pStates[sName].state, true );
		}
		
		
		var pBox	= this;
		if( this.iFrameMode==BoxJS.Box.FRAME_MODES.WINDOW ) {
			window.onclose	= function() {
				pBox.handleAction( 'close' );
			};
		}
		
		if( (this.mDropTargets || this.pBoxJS.bSortable) && !this.iFrameMode ) {
			this.installDraggable();
		}
		
		if( pBoxData.pRuntime )
			for( var sName in pBoxData.pRuntime ) {
				if( this.pStates[ sName ].state!=pBoxData.pRuntime[sName] ) {
					//if( this.pStates[sName].actions )
					//	this.handleAction( this.pStates[sName].actions[ this.pStates[sName].state ], null, true );
					//else
						this.setState( sName, pBoxData.pRuntime[sName], true );
				}
			}
		
		this.pBoxJS.addBox( this, pBoxData.pReplace );
	};
	BoxJS.Box.prototype.$Box				= function() {
		this.pBoxJS.removeBox( this );
	};
	BoxJS.Box.prototype.highlightBox		= function() {
		var sDeg	= this.pStates.maximized.state ? '1deg' : '5deg';
		
		this.pContainer
			.transition( {
				scale	: 1.1,
				rotate	: sDeg
			}, 200 );
		
		for( var i=0; i<=10; i++ )
			this.pContainer
			.transition( {
				rotate	: i%2 ? sDeg : '-'+sDeg
			}, 50 );
		
		this.pContainer
			.transition( {
				scale	: 1,
				rotate	: '0deg'
			}, 200 );
	};
	BoxJS.Box.prototype.installDraggable	= function() {
		if( this.pContainer.hasClass('ui-draggable') )
			return;
		
		var pBox	= this;
		this.pContainer.draggable( {
			handle	: this.sDraggable,
			helper	: function() {
				return pBox.pDraggableHelper=pBox.createDragElement().addClass('boxjs-drag-handle').css( { zIndex:1001 } );
			},
			start	: function( e, ui ) {
				if( pBox.pStates.maximized.state ) {
					return false;
				}
				if( pBox.mDropTargets ) {
					pBox.pDropTargets	= typeof pBox.mDropTargets=='string' ? $(pBox.mDropTargets) : pBox.mDropTargets;
				}
				else
					pBox.pDropTargets	= $();
				
				pBox.emit( 'drag_start' );
				pBox.pContainer.trigger( 'box_drag_start', [ pBox ] );
				
				pBox.pDropTargets.addClass( 'boxjs-possible-drop-target' );
				
				pBox.pContainer.addClass( 'boxjs-dragging' );
				
				pBox.pContainer.css( { /*transition:'none',*/ zIndex:'999' } );
			},
			drag	: function( e, ui ) {
				pBox.handleDrag( ui.offset.left, ui.offset.top );
			},
			stop	: function( e, ui ) {
				
				pBox.emit( 'drag_stop' );
				pBox.pContainer.trigger( 'box_drag_stop', [ pBox ] );
				
				pBox.pDropTargets.removeClass( 'boxjs-possible-drop-target' );
				
				pBox.pContainer.removeClass( 'boxjs-dragging' );
				
				pBox.handleDrop( ui.offset.left, ui.offset.top );
				
				pBox.pDropTargets	= null;
			}
		} ).addClass('ui-draggable');
	};
	BoxJS.Box.prototype.createDragElement	= function() {
		return this.pContainer.clone();
	};
	BoxJS.Box.prototype.getDropTarget		= function( iLeft, iTop ) {
		var pElements	= this.pDropTargets;
		
		if( !pElements )
			return null;
		
		var iBoxWidth	= this.pDraggableHelper.outerWidth();
		var iBoxHeight	= this.pDraggableHelper.outerHeight();
		
		for( var i=0; i<pElements.length; i++ ) {
			var pElement	= $( pElements[i] );
			var pOffset		= pElement.offset();
			var iWidth		= pElement.outerWidth();
			var iHeight		= pElement.outerHeight();
			
			if( iLeft+iBoxWidth>=pOffset.left && iLeft<=pOffset.left+iWidth && iTop+iBoxHeight>=pOffset.top && iTop<=pOffset.top+iHeight ) {
				return pElement;
			}
		}
		
		return null;
	};
	BoxJS.Box.prototype.handleDrag			= function( iLeft, iTop ) {
		var pTarget	= this.getDropTarget( iLeft, iTop );
		$('.boxjs-active-drop-target').removeClass( 'boxjs-active-drop-target' );
		
		if( pTarget && !pTarget.hasClass('boxjs-active-drop-target') )
			pTarget.addClass('boxjs-active-drop-target');
		
    if( this.pBoxJS.bSortable )
      this.pBoxJS.insertBoxAt( this, iLeft, iTop );		
	};
	BoxJS.Box.prototype.handleDrop			= function( iLeft, iTop ) {
		var pTarget	= this.getDropTarget( iLeft, iTop );
		$('.boxjs-active-drop-target').removeClass( 'boxjs-active-drop-target' );
		
		if( this.pBoxJS.bSortable )
			this.pBoxJS.insertBoxAt( this, iLeft, iTop, true, !!pTarget );
		
		if( pTarget ) {
			this.emit( 'drop', pTarget );
			pTarget.trigger( 'box_drop', [this] );
		}
		
		this.pBoxJS.reorderInPageBoxes();
	};
	BoxJS.Box.prototype.sync				= function() {
		this.iChanged	= (new Date()).getTime();
		this.pBoxJS.sync();
	};
	BoxJS.Box.prototype.setState			= function( sName, mState, bDontSync ) {
		var pState		= this.pStates[ sName ];
		var mOldState	= pState.state;
		pState.state	= Number( mState );
		if( !pState.dont_sync )
			this.pRuntimeStates[sName]	= pState.state;
		
		for( var i=0; i<pState.classes.length; i++ )
			this.pContainer.removeClass( pState.classes[i] );
		
		this.pContainer.addClass( pState.classes[ pState.state ] );
		
		if( pState.attribute )
			this[ pState.attribute ]	= mState;
		
		if( !bDontSync && this.bSync && !pState.dont_sync && mState!=mOldState )
			this.sync();
	};
	BoxJS.Box.prototype.registerStates		= function() {
		this.pStates.frame_mode	= {
			dont_sync				: true,
			state					: this.iFrameMode,
			classes					: [ 'boxjs-unframed-box', 'boxjs-windowed-box', 'boxjs-framed-box' ]
		};
		this.pStates.minimized	= {
			state					: false,
			classes					: [ 'boxjs-not-minimized', 'boxjs-minimized' ],
			actions					: [ 'minimize', 'restore' ]
		};
		this.pStates.maximized	= {
			state					: false,
			classes					: [ 'boxjs-not-maximized', 'boxjs-maximized' ],
			actions					: [ 'maximize', 'restore' ]
		};
	};
	BoxJS.Box.prototype.registerActions		= function() {
		this.pActions.minimize	= {
			caption					: this.pBoxJS.translate( 'box', 'action_minimize' )
		};
		this.pActions.restore	= {
			caption					: this.pBoxJS.translate( 'box', 'action_restore' )
		};
		
		this.pActions.maximize	= {
			caption					: this.pBoxJS.translate( 'box', 'action_maximize' )
		};
		
		this.pActions.close		= {
			caption					: this.pBoxJS.translate( 'box', 'action_close' )
		};
	};
	BoxJS.Box.prototype.getSyncData			= function() {
		var pData	= {
			sID			: this.sID,
			iSessionID	: this.iSessionID,
			iChanged	: this.iChanged,
			bSync		: this.bSync,
			pRuntime	: this.pRuntimeStates,
			mDropTargets: this.mDropTargets
		};
		
		return pData;
	};
	BoxJS.Box.prototype.setSyncData			= function( pData ) {
		this.iSessionID	= pData.iSessionID;
		this.iChanged	= pData.iChanged;
		this.sID		= pData.sID;
		this.bSync		= pData.bSync;
		this.mDropTargets= pData.mDropTargets;
		
		for( var sName in pData.pRuntime ) {
			if( this.pStates[ sName ].state!=pData.pRuntime[sName] ) {
				if( this.pStates[sName].actions )
					this.handleAction( this.pStates[sName].actions[ this.pStates[sName].state ], null, true );
				else
					this.setState( sName, pData.pRuntime[sName], true );
			}
		}
	};
	BoxJS.Box.prototype.handleAction		= function( sAction, pContainer, bDontSync ) {
		if( sAction=='restore' ) {
			if( this.pStates.maximized.state ) {
				this.pBoxJS.unmaximizeBox( this );
				this.setState( 'maximized', false, bDontSync );
				
				this.pBoxJS.reorderInPageBoxes();
			}
			else if( this.pStates.minimized.state ) {
				this.setState( 'minimized', false, bDontSync );
				
				this.pBoxJS.reorderInPageBoxes();
			}
			
			return true;
		}
		else if( sAction=='maximize' ) {
			if( this.pBoxJS.maximizeBox( this ) ) {
				this.setState( 'minimized', false, true );
				this.setState( 'maximized', true, bDontSync );
				
				this.pBoxJS.reorderInPageBoxes();
			}
			
			return true;
		}
		else if( sAction=='minimize' ) {
			if( this.pStates.maximized.state ) {
				this.pBoxJS.unmaximizeBox( this );
				this.setState( 'maximized', false, true );
			}
			
			this.setState( 'minimized', true, bDontSync );
			
			this.pBoxJS.reorderInPageBoxes();
			
			return true;
		}
		else if( sAction=='close' ) {
			if( this.pStates.maximized.state ) {
				this.pBoxJS.unmaximizeBox( this );
				this.setState( 'maximized', false, true );
			}
			
			this.destroy();
			
			return true;
		}
		
		return false;
	};
	
	
	
	createClass( "BoxJS.ControlBox", "BoxJS.Box" );
	BoxJS.pBoxTypes.control							= BoxJS.ControlBox;
	BoxJS.ControlBox.prototype.pElements			= null;
	BoxJS.ControlBox.prototype.ControlBox			= function( pBoxJS, pBoxData, iFrameMode ) {
		this.Box( pBoxJS, pBoxData, iFrameMode );
		
		this.pContainer.addClass( 'boxjs-box-actions boxjs-control-box' );
		this.pElements	= {};
		
		this.createElements();
	};
	BoxJS.ControlBox.prototype.createSwitchButton	= function( sName, pValues, sDefault, pCallback, bStateLess ) {
		var pContainer	= $('<div class="boxjs-box-action switch-button switch-'+sName+'" />');
		
		for( var sKey in pValues ) {
			(function(sKey,sCaption){
				$('<span class="switch-option switch-'+sName+'-to-'+sKey+''+(sDefault==sKey?' active-option':'')+'"></span>')
					.attr( "title", sCaption )
					.append( $('<span class="icon"></span>') )
					.append( $('<span class="caption"></span>').text( sCaption ) )
					.appendTo( pContainer )
					.click( function(e) {
						if( !bStateLess )
							$(this)
								.addClass( 'active-option' )
								.siblings()
								.removeClass( 'active-option' );
						
						pCallback( sKey );
					} );
			})(sKey,pValues[sKey]);
		}
		
		return pContainer;
	};
	BoxJS.ControlBox.prototype.createElements		= function() {
		var pBox	= this;
		
		this.pBoxJS.on( 'horizontal_align_changed', function() {
			this.pElements.pHAlign.find( '.switch-option' ).removeClass( 'active-option' ).filter( '.switch-halign-to-'+this.pBoxJS.sHorizontalAlign ).addClass( 'active-option' );
		}, this );
		
		this.pBoxJS.on( 'vertical_align_changed', function() {
			this.pElements.pVAlign.find( '.switch-option' ).removeClass( 'active-option' ).filter( '.switch-valign-to-'+this.pBoxJS.sVerticalAlign ).addClass( 'active-option' );
		}, this );
		
		this.pBoxJS.on( 'orientation_changed', function() {
			this.pElements.pOrientation.find( '.switch-option' ).removeClass( 'active-option' ).filter( '.switch-orientation-to-'+this.pBoxJS.sOrientation ).addClass( 'active-option' );
		}, this );
		
		this.pElements.pHAlign		= this.createSwitchButton( 'halign', { left:this.pBoxJS.translate('control_box','halign_left'), right:this.pBoxJS.translate('control_box','halign_right') }, this.pBoxJS.sHorizontalAlign, function( sValue ) {
			pBox.pBoxJS.setHorizontalAlign( sValue );
		} ).appendTo( this.pContainer );
		
		this.pElements.pVAlign		= this.createSwitchButton( 'valign', { top:this.pBoxJS.translate('control_box','valign_top'), bottom:this.pBoxJS.translate('control_box','valign_bottom') }, this.pBoxJS.sVerticalAlign, function( sValue ) {
			pBox.pBoxJS.setVerticalAlign( sValue );
		} ).appendTo( this.pContainer );
		
		this.pElements.pOrientation	= this.createSwitchButton( 'orientation', { horizontal:this.pBoxJS.translate('control_box','orientation_horizontal'), vertical:this.pBoxJS.translate('control_box','orientation_vertical') }, this.pBoxJS.sOrientation, function( sValue ) {
			pBox.pBoxJS.setOrientation( sValue );
		} ).appendTo( this.pContainer );
		
		this.pElements.pActions		= this.createSwitchButton( 'actions', { minimizeAll:this.pBoxJS.translate('control_box','minimize_all'), closeAll:this.pBoxJS.translate('control_box','close_all') }, '', function( sValue ) {
			pBox.pBoxJS[sValue]( [pBox] );
		}, true ).appendTo( this.pContainer );
		
		/*this.pElements.pCloseAll	= $('<div class="boxjs-box-action boxjs-box-action-close-all" />')
			.text( this.pBoxJS.translate('control_box','close_all') )
			.click( function(e) {
				pBox.pBoxJS.closeAll( [pBox] );
			} )
			.appendTo( this.pContainer );
		
		this.pElements.pMinimizeAll	= $('<div class="boxjs-box-action boxjs-box-action-minimize-all" />')
			.text( this.pBoxJS.translate('control_box','minimize_all') )
			.click( function(e) {
				pBox.pBoxJS.minimizeAll( [pBox] );
			} )
			.appendTo( this.pContainer );*/
		
		this.pBoxJS.reorderInPageBoxes();
	};
	
	
	
	createClass( "BoxJS.SimpleBox", "BoxJS.Box" );
	BoxJS.pBoxTypes.simple						= BoxJS.SimpleBox;
	BoxJS.SimpleBox.prototype.pConfig			= null;
	BoxJS.SimpleBox.prototype.iSessionID		= 0;
	BoxJS.SimpleBox.prototype.pElements			= null;
	BoxJS.SimpleBox.prototype.sClassName		= 'BoxJS.SimpleBox';
	BoxJS.SimpleBox.prototype.iRContainerHeight	= null;
	BoxJS.SimpleBox.prototype.SimpleBox			= function( pBoxJS, pBoxData, iFrameMode ) {
		pBoxData	= this.ensureBoxData( pBoxJS, pBoxData, [ 'minimize', 'restore', 'maximize', 'close' ] );
		
		pBoxData.bSync			= !!this.pConfig.sync;
		if( !pBoxData.mDropTargets )
			pBoxData.mDropTargets	= this.pConfig.drop_targets;
		
		this.Box( pBoxJS, pBoxData, iFrameMode );
		
		this.pContainer.addClass( 'boxjs-simple-box' );
		
		this.createElements();
	};
	BoxJS.SimpleBox.prototype.createDragElement	= function() {
		return this.pElements.pCaption.clone();
	};
	BoxJS.SimpleBox.prototype.installDraggable	= function() {
		if( !this.sDraggable )
			return;
		
		this.__parent.installDraggable.apply( this, arguments );
	};
	BoxJS.SimpleBox.prototype.ensureBoxData		= function( pBoxJS, pBoxData, aDefaultActions ) {
		var pConfig	= pBoxData.pConfig;
		if( !pBoxData.sID ) {
			pConfig		= pBoxData;
			pBoxData	= {
				pConfig		: pConfig,
				sID			: pConfig.id
			};
		}
		/*else if( pBoxData.sClass ) {
			this.sClassName	= pBoxData.sClass;
		}*/
		
		this.pConfig								= pConfig;
		
		if( !this.pConfig.actions )
			this.pConfig.actions	= aDefaultActions;
		
		pBoxData.pReplace	= pBoxJS.getBoxByID( pBoxData.sID );
		
		return pBoxData;
	};
	BoxJS.SimpleBox.prototype.setState			= function( sName, mState, bDontSync ) {
		this.__parent.setState.apply( this, [sName,mState,true] );
		
		if( this.pConfig.height && this.pElements )
			this.updateHeight(true);
		
		if( this.bSync && !bDontSync )
			this.sync();
	};
	BoxJS.SimpleBox.prototype.updateHeight		= function( bDontSync ) {
		if( this.iFrameMode )
			this.pConfig.height		= this.pStates.maximized.state ? '100%' : this.pElements.pBody.outerHeight()+'px';
		else if( this.iRContainerHeight===null )
			this.iContainerHeight	= this.pContainer.outerHeight();
		
		/*else
			this.iRContainerHeight	= (this.pContainer.outerHeight()-) + this.pElements.pContents.outerHeight();*/
		
		if( !bDontSync && this.bSync )
			this.sync();
	};
	BoxJS.SimpleBox.prototype.registerActions	= function() {
		this.__parent.registerActions.apply( this, [] );
		
		this.pActions.minimize.container	= 'pHeadActions';
		this.pActions.restore.container		= 'pHeadActions';
		this.pActions.maximize.container	= 'pHeadActions';
		this.pActions.close.container		= 'pHeadActions';
	};
	BoxJS.SimpleBox.prototype.createElements	= function() {
		if( !this.pElements )
			this.pElements	= {};
		
		if( this.iFrameMode ) {
			this.pElements.pHead	= $('head');
			this.pElements.pCaption	= $('title');
		}
		else {
			this.pElements.pHead						= $('<div />')
				.addClass( 'boxjs-box-head' )
				.appendTo( this.pContainer );
			this.pElements.pCaption						= $('<h1 />')
				.text( this.pConfig.caption )
				.appendTo( this.pElements.pHead );
			this.pElements.pHeadActions					= $('<span />')
				.addClass( 'boxjs-box-actions' )
				.appendTo( this.iFrameMode ? this.pElements.pBody : this.pElements.pHead );
			
			$('<div />')
				.addClass( 'boxjs-box-head-closure' )
				.appendTo( this.pElements.pHead );
			
			this.sDraggable	= '>.boxjs-box-head';
		}
		
		this.pElements.pBody							= $('<div />')
			.addClass( 'boxjs-box-body' )
			.appendTo( this.pContainer );
		this.pElements.pBodyActions						= $('<span />')
			.addClass( 'boxjs-box-actions' )
			.appendTo( this.pElements.pBody );
		
		this.updateContents( this.pConfig, true );
		
		this.updateActions( this.pConfig.actions );
		
		if( (this.mDropTargets || this.pBoxJS.bSortable) && !this.iFrameMode ) {
			this.installDraggable();
		}
		
		this.pBoxJS.reorderInPageBoxes();
	};
	BoxJS.SimpleBox.prototype._aActionContainer	= null;
	BoxJS.SimpleBox.prototype.updateActions		= function( aActions ) {
		
		if( !this._aActionContainer )
			this._aActionContainer	= [];
		
		for( var i=0, sName; sName=aActions[i]; i++ ) {
			
			var pAction		= this.pActions[ sName ];
			if( !pAction ) {
				console.error( sName, this.pActions );
				continue;
			}
			
			var pContainer	= this.pElements.pContents ? this.pElements.pContents.find( pAction.container ) : $();
			if( !pContainer.size() ) {
				pContainer	= this.pElements[ pAction.container ];
				if( !pContainer ) {
					continue;
				}
			}
			else {
				this.pElements[pAction.container]	= pContainer;
			}
			
			if( $.inArray( pAction.container, this._aActionContainer )<0 )
				this._aActionContainer.push( pAction.container );
			
			var pBox	= this;
			pContainer.each( function() {
				var pInstance	= $(this);
				
				if( !pInstance.find('>.boxjs-box-action-'+sName).size() )
					pBox.addAction( sName, pAction, pInstance );
			} );
		}
		
		for( var i=0, sName; sName=this._aActionContainer[i]; i++ ) {
			var pContainer	= this.pElements[ sName ];
			if( !pContainer )
				continue;
			
			pContainer.children().each( function() {
				
				var pElement	= $(this);
				var sAction		= pElement.data( 'action' );
				if( !sAction )
					return;
				
				if( $.inArray( sAction, aActions )<0 )
					pElement.remove();
				
			} );
		}
		
	};
	BoxJS.SimpleBox.prototype.addAction			= function( sName, pAction, pContainer ) {
		
		var pLink	= $('<a href="#"></a>')
			.addClass( 'boxjs-box-action boxjs-box-action-'+sName.replace( /[^a-z0-9_\-]/g, "-" ) )
			.appendTo( pContainer )
			.data( 'action', sName )
			.bind( 'click', {sAction:sName,pBox:this,pContainer:pContainer}, BoxJS.SimpleBox.onActionClick );
    
		$('<span class="icon" />')
			.appendTo( pLink );
		
		$('<span class="caption" />')
			.text( pAction.caption )
			.appendTo( pLink );
		
		return pLink;
		
	};
	BoxJS.SimpleBox.prototype.openDialog		= function( sBody, pActions, sKey ) {
		this.pElements.pDialog	= $('<div class="boxjs-dialog" />')
			.appendTo( this.pElements.pContents );
		
		$('<div class="boxjs-dialog-message" />')
			.appendTo( this.pElements.pDialog )
			.text( sBody );
		
		var pButtons	= $('<div class="boxjs-dialog-buttons" />')
			.appendTo( this.pElements.pDialog );
		
		for( var sName in pActions )
			this.addAction( (sKey?sKey+':':'')+sName, {caption:pActions[sName]}, pButtons );
	};
	BoxJS.SimpleBox.prototype.updateContents	= function( pConfig, bForce ) {
		if( pConfig.url && !this.iFrameMode ) {
			var sURL						= BoxJS.replaceTokens( pConfig.url, { parent:this.pBoxJS.getSessionID() } );
			
			if( this.pElements.pContents ) {
				if( this.pElements.pContents.is('iframe') ) {
					if( this.pElements.pContents.attr('src')!=sURL )
						this.pElements.pContents
							.attr( "src", sURL )
							.css( "height", "100%" );
					
					return;
				}
				
				this.pElements.pContents.remove();
				this.pElements.pContents	= null;
			}
			
			this.pElements.pContents		= $('<iframe frameborder="0" style="height:100%;">'+(pConfig.html?pConfig.html:(pConfig.text?pConfig.text:''))+'</iframe>')
				.attr( "src", sURL )
				.addClass( 'boxjs-box-iframe' )
				.appendTo( this.pElements.pBody );
			
			var pBox	= this;
			var pWindow	= this.pElements.pContents[0].contentWindow;
			$( pWindow ).load( function(e) {
				
				if( pWindow!=pBox.pElements.pContents[0].contentWindow )
					return;
				
				var pBoxContainer			= pWindow.jQuery( '#'+pBox.pContainer.attr('id') );
				pBox.iChildFrameSessionID	= pBoxContainer.data( 'box' ).pBoxJS.getSessionID();
				
			} );
		}
		else if( pConfig.element && $(pConfig.element).size() ) {
			if( this.pElements.pContents ) {
				if( this.pElements.pContents.is(pConfig.element) ) {
					return;
				}
				
				this.pElements.pContents.remove();
				this.pElements.pContents	= null;
			}
			this.pElements.pContents	= $(pConfig.element)
				.addClass( 'boxjs-box-element' )
				.appendTo( this.pElements.pBody );
		}
		else {
			if( this.pElements.pContents ) {
				if( this.pElements.pContents.is('div') ) {
					if( !bForce && (this.pConfig.html==pConfig.html && (pConfig.html || this.pConfig.text==pConfig.text)) )
						return;
					
					this.pElements.pContents.attr( 'class', '' );
				}
				else {
					this.pElements.pContents.remove();
					this.pElements.pContents	= null;
				}
			}
			
			if( pConfig.html ) {
				this.pElements.pContents						= (this.pElements.pContents ? this.pElements.pContents : $('<div />'))
					.html( pConfig.html )
					.addClass( 'boxjs-box-html' )
					.appendTo( this.pElements.pBody );
				
				this.updateHeight();
			}
			else if( pConfig.text ) {
				this.pElements.pContents						= (this.pElements.pContents ? this.pElements.pContents : $('<div />'))
					.text( pConfig.text )
					.addClass( 'boxjs-box-text' )
					.appendTo( this.pElements.pBody );
				
				this.updateHeight();
			}
			else if( this.pElements.pContents ) {
				this.pElements.pContents.remove();
				this.pElements.pContents	= null;
			}
		}
	};
	BoxJS.SimpleBox.prototype.getSyncData		= function() {
		var pData		= this.__parent.getSyncData.apply( this, [] );
		var pConfig		= {};
		pData.pConfig	= pConfig;
		
		for( var sName in this.pStates ) {
			var pState	= this.pStates[ sName ];
			if( pState.config_name )
				pConfig[ pState.config_name ]	= this.pConfig[ pState.config_name ];
		}
		
		pConfig.caption			= this.pConfig.caption;
		pConfig.actions			= this.pConfig.actions;
		pConfig.element			= this.pConfig.element;
		pConfig.url				= this.pConfig.url;
		pConfig.html			= this.pConfig.html;
		pConfig.text			= this.pConfig.text;
		pConfig.sync			= this.pConfig.sync;
		pConfig.height			= this.pConfig.height;
		pConfig.drop_targets	= this.pConfig.drop_targets;
		
		pData.sClass	= this.sClassName;
		
		return pData;
	};
	BoxJS.SimpleBox.prototype.setSyncData		= function( pData ) {
		this.__parent.setSyncData.apply( this, arguments );
		
		var pConfig	= pData.pConfig;
		
		for( var sName in pConfig )
			this.pConfig[sName]	= pConfig[sName];
		
		this.pElements.pCaption
			.text( pConfig.caption );
		
		this.updateActions( pConfig.actions );
		
		this.updateContents( pConfig );
		
		if( pConfig.height && pConfig.url && !this.iFrameMode ) {
			this.pElements.pContents.css( "height", pConfig.height );
			
			this.updateHeight(true);
			
			this.pBoxJS.reorderInPageBoxes();
		}
	};
	BoxJS.SimpleBox.onActionClick				= function(e) {
		
		return !e.data.pBox.handleAction( e.data.sAction, e.data.pContainer );
		
	};
	BoxJS.SimpleBox.prototype.handleAction		= function( sAction, pContainer, bDontSync ) {
		if( sAction=='dialog_close' ) {
			if( this.pElements.pDialog ) {
				this.pElements.pDialog.remove();
				delete this.pElements.pDialog;
			}
			
			return true;
		}
		else if( sAction=='restore' ) {
			if( this.pStates.maximized.state || this.pStates.minimized.state ) {
				var bResult				= this.__parent.handleAction.applyEx( this, arguments, BoxJS.SimpleBox );
				
				this.iContainerWidth	= this.iRContainerWidth;
				this.iContainerHeight	= this.iRContainerHeight;
				
				this.iRContainerHeight	= null;
				
				this.pBoxJS.reorderInPageBoxes();
				return bResult;
			}
		}
		else if( sAction=='maximize' || sAction=='minimize' ) {
			if( !this.pStates.maximized.state && !this.pStates.minimized.state ) {
				this.iRContainerWidth	= this.pContainer.outerWidth();
				this.iRContainerHeight	= this.pContainer.outerHeight();
				this.iContainerHeight	= this.iRContainerHeight - this.pElements.pBody.outerHeight();
				
				//var bResult				= this.__parent.handleAction.apply( this, arguments );
				//return bResult;
			}
		}
		
		return this.__parent.handleAction.applyEx( this, arguments, BoxJS.SimpleBox );
	};
	
	
	
	
	
	createClass( "BoxJS.Handler" );
	BoxJS.Handler.prototype.sName           = null;
	BoxJS.Handler.prototype.pBoxJS          = null;
	BoxJS.Handler.prototype.Handler         = function( pBoxJS ) {
		this.pBoxJS = pBoxJS;
		
		this.pBoxJS.registerHandler( this );
	};
	
	
	$.fn.boxjs	= function() {
		
		var pBoxJS	= this.data( 'boxjs' );
		if( !pBoxJS ) {
			if( arguments[0] && arguments[0].box===true ) {
				var pElement	= this;
				var pConfig		= arguments[0];
				
				this.parents().each( function() {
					var pSelf	= $(this);
					if( pBoxJS=pSelf.data('boxjs') ) {
						var pBox	= new BoxJS.SimpleBox( pBoxJS, {id:pConfig.id?pConfig.id:pElement.attr('id'),sync:pConfig.sync,caption:pConfig.caption,actions:pConfig.actions,element:'#'+pElement.attr('id')} );
						return false;
					}
				} );
				
				return;
			}
			
			var pConfig	= $.extend( {}, $.fn.boxjs.defaults, arguments[0] );
			
			var pInterTabJS	= null;
			if( window.INTER_TAB_JS ) {
				INTER_TAB_JS.init();
				pInterTabJS	= pConfig.inter_tab_js ? INTER_TAB_JS.findInstanceByPrefix( pConfig.inter_tab_js ) : pConfig.inter_tab_js;
				if( !pInterTabJS )
					pInterTabJS		= INTER_TAB_JS.instance;
			}
			
			this.addClass('boxjs').data( 'boxjs', pBoxJS=createClass.instantiate( pConfig.classname, [ pConfig, pInterTabJS, this ] ) );
			
			if( pBoxJS.sBox )
				$('html').addClass('boxjs-frame');
		}
		
		if( arguments[0]=='instance' )
			return pBoxJS;
		else if( arguments[0]=='valign' ) {
			if( arguments[1] )
				pBoxJS.setVerticalAlign( arguments[1] );
			else
				return pBoxJS.sVerticalAlign;
		}
		else if( arguments[0]=='halign' ) {
			if( arguments[1] )
				pBoxJS.setHorizontalAlign( arguments[1] );
			else
				return pBoxJS.sHorizontalAlign;
		}
		else if( arguments[0]=='orientation' ) {
			if( arguments[1] )
				pBoxJS.setOrientation( arguments[1] );
			else
				return pBoxJS.sOrientation;
		}
		else if( arguments[0]=='create' && arguments[1] ) {
			var pBoxData	= arguments[1];
			var sType		= arguments[2];
			if( typeof pBoxData=='string' ) {
				pBoxData	= arguments[2];
				sType		= arguments[1];
			}
			
			if( pBoxData && !pBoxData.sID && !pBoxData.sClass )
				pBoxData		= {
					pConfig			: pBoxData
				};
			
			return pBoxJS.createBox( pBoxData, sType );
		}
		
		return this;
		
	};
	$.fn.boxjs.defaults	= {
		vertical_align		: 'bottom',
		horizontal_align	: 'right',
		orientation			: 'vertical',
		sortable			: true,
		margin				: 20,
		frame_url			: 'index.html#box=[box]&parent=[parent]',
		classname			: 'BoxJS',
		control_box			: true
	};
	
	
	
})(jQuery);