<?php

/**
 * @file
 * Display Suite 2 column stacked form template.
 */
?>
<div class="ds-form-2col-stacked clearfix">
  <?php if ($left): ?>
    <div class="group-left<?php print $left_classes; ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <div class="group-right<?php print $right_classes; ?>">
      <?php print $right; ?>
    </div>
  <?php endif; ?>
 
  <?php if ($advanced): ?>
    <div class="group-advanced<?php print $advanced_classes; ?>">
      <?php print $advanced; ?>
		<?php if ($advancedleft): ?>
			<div class="group-advanced-left<?php print $advancedleft_classes; ?>">
				<?php print $advancedleft; ?>
			</div>
		<?php endif; ?>
		<?php if ($advancedright): ?>
			<div class="group-advanced-right<?php print $advancedright_classes; ?>">
				<?php print $advancedright; ?>
			</div>
		<?php endif; ?>
    </div>
  <?php endif; ?>
</div>

<?php
  // Print the rest of the form.
  print drupal_render_children($form);
?>
