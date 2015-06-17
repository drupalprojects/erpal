<?php drupal_add_js('misc/collapse.js'); 

//remove some unwanted chars
if ($left == '&nbsp;') $left = false;
if ($right == '&nbsp;') $right = false;

?>
<div class="<?php if(isset($classes)) print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
 
  <?php if ($left): ?><div class="group-form-left<?php print $left_classes; ?>"><?php print $left; ?></div><?php endif; ?>

  <?php if ($right): ?><div class="group-form-right<?php print $right_classes; ?>"><?php print $right; ?></div><?php endif; ?>
 
  <?php if ($advanced || $advancedleft || $advancedright): ?>
    <fieldset class="group-advanced collapsible collapsed<?php print $advanced_classes; ?>">	
		<legend>
			<span class="fieldset-legend">Advanced</span>
		</legend>
		<div class="fieldset-wrapper">
			<div class="group-form-advanced-onecolumn"><?php if ($advanced != '&nbsp;') : ?><?php print trim($advanced); ?><?php endif; ?></div>
			<?php if ($advancedleft): ?><div class="group-form-advanced-left<?php print $advancedleft_classes; ?>"><?php print $advancedleft; ?></div><?php endif; ?>
			<?php if ($advancedright): ?><div class="group-form-advanced-right<?php print $advancedright_classes; ?>"><?php print $advancedright; ?></div><?php endif; ?>
		</div>
    </fieldset>
  <?php endif; ?>
  <?php
    // Print the rest of the form.
    print drupal_render_children($form);
  ?>
</div>