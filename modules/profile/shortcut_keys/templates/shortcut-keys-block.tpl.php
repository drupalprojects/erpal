<div class="shortcut-keys-shortcuts">
  <?php foreach( $shortcuts as $shortcut ): ?>
    <div class="shortcut-keys-shortcut shortcut-keys-shortcut-<?php print str_replace( '_', '-', $shortcut['machine_name'] ); ?>">
      <strong><?php print check_plain( $shortcut['keys'] ); if( $shortcut['press_double'] ) print ' '.t('(double)'); ?></strong>
      -
      <a href="#" onclick="shortcut_keys.execute( shortcut_keys.shortcuts[ '<?php print $shortcut['machine_name']; ?>' ] ); return false;" class="shortcut-keys-execute"><?php print check_plain( $shortcut['name'] ); ?></a>
    </div>
  <?php endforeach; ?>
</div>
<div class="shortcut-keys-appendix">
  <?php print $append; ?>
</div>