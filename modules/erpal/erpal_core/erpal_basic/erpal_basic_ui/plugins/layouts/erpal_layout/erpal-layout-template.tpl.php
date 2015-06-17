<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="<?php print $classes; ?>">
  <div class="erpal-container">
    <?php if (!empty($content['sidebar_top'])): ?>
	    <div class="erpal-top">
		<?php print render($content['sidebar_top']); ?>
	  </div>
	<?php endif; ?>
    <div class="erpal-container-item">
	  <?php if (!empty($content['sidebar_left'])): ?>
	    <div class="erpal-region-left panel-col-first">
		  <div class="inside">
		    <?php print render($content['sidebar_left']); ?>
		  </div>
		</div>
	  <?php endif; ?>
	  <div class="erpal-container-content panel-panel panel-col-last">
		<div class="inside">
		  <?php if (!empty($content['sidebar_tabs_row'])): ?>
		    <div class="erpal-region-tabs">
		      <?php print render($content['sidebar_tabs_row']); ?>
		    </div>
		  <?php endif; ?>
		  <?php if (!empty($content['sidebar_content'])): ?>
		    <div class="erpal-region-content">
			  <?php print render($content['sidebar_content']); ?>
		    </div>
		  <?php endif; ?>
		</div>
	  </div>
	  <?php if (!empty($content['footer_row'])): ?>
	    <div class="erpal-footer">
		  <?php print render($content['footer_row']); ?>
	    </div>
	  <?php endif; ?>
	</div>
  </div>
</div>
