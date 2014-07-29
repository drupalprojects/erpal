(function($) {
  
  $( function() {
    
    var sConfig = location.hash.substr(1);    
    var pConfig	= { sortable:false, frame_url:Drupal.settings.boxjs.base_path + 'boxjs/frame#box=[box]&parent=[parent]' };
    if( sConfig ) {
      var aParts	= sConfig.split( '&' );
      for( var i=0, sPart; sPart=aParts[i]; i++ ) {
        var aPair	= sPart.split( '=' );
        pConfig[ aPair[0] ]	= aPair[1];
      }
    }
    
    var pSettings = Drupal.settings.boxjs;
    if( pSettings )
      for( var sName in pSettings )
        pConfig[ sName ]  = pSettings[ sName ];
    
    $('body').boxjs( pConfig );
    
  } );
  
})(jQuery);
