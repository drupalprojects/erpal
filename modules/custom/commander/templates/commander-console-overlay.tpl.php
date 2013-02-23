  <div id="commander-console">
    <div id="commander-console-content">
      <div id="commander-console-log">
        <?php
          $entries  = commander_get_log();
          foreach( $entries as $entry )
            print theme( 'commander_log_entry', array('entry'=>$entry) );
        ?>
      </div>
      <div id="commander-console-history">
        <h4><?php print t('History'); ?></h4>
        <div class="items"></div>
      </div>
      <div id="commander-console-shortcuts">
        <h4><?php print t('Shortcuts'); ?></h4>
        <div class="items"></div>
      </div>
    </div>
    <div id="commander-console-input">
      <?php
        print _commander_execute_form( 'commander_console_overlay', $environment );
      ?>
    </div>
  </div>