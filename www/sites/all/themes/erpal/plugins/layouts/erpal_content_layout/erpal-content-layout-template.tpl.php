<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="<?php print $classes; ?>">

 <div class="columns">
    <div class="columns-inner clearfix">
      <div class="content-column" role="main">
        <div class="content-inner">
            <?php if (!empty($content['sidebar_first_left'])): ?>
				<div class="region region-sidebar-left<?php if (empty($content['sidebar_first_right'])): ?> single-row<?php endif; ?>">
				  <?php print render($content['sidebar_first_left']); ?>
				</div>
          <?php endif; ?>
		  <?php if (!empty($content['sidebar_first_right'])): ?>
				<div class="region region-sidebar-right">
				  <?php print render($content['sidebar_first_right']); ?>
				</div>
          <?php endif; ?>
        </div>
		<div class="content-inner">
            <?php if (!empty($content['sidebar_second_left'])): ?>
				<div class="region region-sidebar-left<?php if (empty($content['sidebar_second_right'])): ?> single-row<?php endif; ?>">
				  <?php print render($content['sidebar_second_left']); ?>
				</div>
          <?php endif; ?>
		  <?php if (!empty($content['sidebar_second_right'])): ?>
				<div class="region region-sidebar-right">
				  <?php print render($content['sidebar_second_right']); ?>
				</div>
          <?php endif; ?>
        </div>


      </div>
  </div>
</div>
</div>
