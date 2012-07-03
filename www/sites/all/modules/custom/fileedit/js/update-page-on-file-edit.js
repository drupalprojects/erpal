/**
 *  (c) 2012 Bright Solutions GmbH
 *
 *  @author Thiemo Müller
 */

(function( $ ) {
  
  var iInterval   = 10000;
  var aObserving  = [];
  var pUpdate     = null;
  window.updatePageOnEditClb  = function() {
    
    var sObserving  = aObserving.join('+');
    
    $.ajax( {
      
      cache   : false,
      error   : function( jqXHR, textStatus, errorThrown ) {
        if( window.console && console.error )
          console.error( 'An error occured in fileedit: ', textStatus, errorThrown, jqXHR );
      },
      success : function( data, textStatus, jqXHR ) {
        if( data=='1' )
          location.reload();
      },
      url     : Drupal.settings.fileedit.updateURL + sObserving
      
    } );
    
  };
  
  $( function() {
    
    $( 'a.fileedit-link' ).live( 'click', function(e) {
      var pLink   = $(e.target);
      
      var aParts  = pLink.attr("href").split( '/' );
      var iFID    = parseInt( aParts[ aParts.length-1 ] );
      
      console.log( iFID, aObserving );
      
      if( $.inArray( iFID, aObserving )<0 ) {
        if( !pUpdate )
          pUpdate   = setInterval( "window.updatePageOnEditClb()", iInterval );
        
        aObserving.push( iFID );
      }
    } );
    
  } );
  
})( jQuery );