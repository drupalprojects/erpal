<div class="entry entry-type-<?php print $entry['type']; ?> entry-source-<?php print isset($entry['source'])?$entry['source']:'console'; ?><?php if( $entry['timestamp']>=REQUEST_TIME ) print ' request-message'; ?>">
  <div class="entry-datetime">
    <?php print format_date($entry['timestamp'],'medium') . ' @ ' . (isset($entry['source'])?$entry['source']:'console'); ?>
  </div>
  <div class="entry-message">
    <?php print preg_replace( '@^<p>(.*?)</p>$@', '$1', check_markup( $entry['message'], 'full_html' ) ); ?>
  </div>
</div>