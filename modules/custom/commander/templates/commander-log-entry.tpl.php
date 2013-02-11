<div class="entry entry-type-<?php print $entry['type']; ?> entry-source-<?php print isset($entry['source'])?$entry['source']:'console'; ?>">
  <div class="entry-datetime">
    <?php print format_date($entry['timestamp'],'medium') . ' @ ' . (isset($entry['source'])?$entry['source']:'console'); ?>
  </div>
  <div class="entry-message">
    <?php print $entry['message'] ?>
  </div>
</div>