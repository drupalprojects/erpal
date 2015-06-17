<?php 
function ds_erpal_forms() {
  return array(
    'label' => t('ERPAL Forms'),
    'regions' => array(
      'left' => t('Left'),
      'right' => t('Right'),
      'advanced' => t('Advanced'),
      'advancedleft' => t('Advanced Left'),
      'advancedright' => t('Advanced Right')
    ),
    // Add this line if there is a default css file.
    'css' => TRUE,
	'form' => TRUE,
  );
}
?>