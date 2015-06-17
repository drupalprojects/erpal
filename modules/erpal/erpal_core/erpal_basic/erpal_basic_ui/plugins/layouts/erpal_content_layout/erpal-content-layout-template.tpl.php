<div<?php print !empty($css_id) ? " id=\"$css_id\"" : ''; ?> class="<?php print $classes; ?>">
  <div class="erpal-content-top content-inner">
    <?php if (!empty($content['sidebar_first_left'])): ?>
	  <div class="erpal-content-left region region-sidebar-left<?php if (empty($content['sidebar_first_right'])): ?> single-row<?php endif; ?>">
		<?php print render($content['sidebar_first_left']); ?>
	  </div>
    <?php endif; ?>
	<?php if (!empty($content['sidebar_first_right'])): ?>
	  <div class="erpal-content-right region region-sidebar-right">
		<?php print render($content['sidebar_first_right']); ?>
	  </div>
    <?php endif; ?>
  </div>
  <div class="erpal-content-bottom content-inner">
    <?php if (!empty($content['sidebar_second_left'])): ?>
	  <div class="erpal-content-left region region-sidebar-left<?php if (empty($content['sidebar_second_right'])): ?> single-row<?php endif; ?>">
	    <?php print render($content['sidebar_second_left']); ?>
	  </div>
    <?php endif; ?>
	<?php if (!empty($content['sidebar_second_right'])): ?>
	  <div class="erpal-content-right region region-sidebar-right">
		<?php print render($content['sidebar_second_right']); ?>
	  </div>
    <?php endif; ?>
  </div>
</div>
