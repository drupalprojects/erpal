<div id="commander-execute-block">
  <?php if( $allow_fullscreen ): ?>
    <?php print l( t('Show fullscreen'), 'commander/ajax/console/nojs', array( 'query'=>array( 'environment'=>array( 'q'=>$_GET['q'] ) ), 'attributes'=>array( 'class'=>array('ctools-use-modal') ) ) ); ?>
    <!--<a href="#" onclick="commander.toggle_console(); return false;"><?php print t( 'Show fullscreen' ); ?></a>-->
  <?php endif; ?>
  <div id="commander-execute-block-log">
    <?php foreach( $messages as $entry ) print theme( 'commander_log_entry', array('entry'=>$entry) ); ?>
  </div>
  <?php print isset($form) ? drupal_render($form) : _commander_execute_form( 'commander_execute_block', array( 'q'=>$_GET['q'] ), $allow_fullscreen ); ?>
</div>