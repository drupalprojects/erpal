<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Powered by'),
  'description' => t('Shows the powered by information'),
  'category' => t('ERPAL'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_layout_helper_powered_by_content_type_render($subtype, $conf, $args, $context) {

  $block = new stdClass();
  $powered_by = '<span class="powered_by_text">'.t('powered by').'</span><span class="drupal_text"> '.l('Drupal', 'http://drupal.org').'</span>';
  $supported_by = '<span class="supported_by_text">'.t('supported and maintained by').'</span><span class="bs_text"> '.l('Bright Solutions GmbH', 'http://www.brightsolutions.de').'</span>';
  $support_powered_by = '<div class="support_powered_by">'.$powered_by.' - '.$supported_by.'</div>';
  $block->module = 'erpal_layout_helper';
  $block->content = '<div class="powered_by_content">'.$support_powered_by.'<div class="bs_powered_by_logo"></div>'.'</div>';
  return $block;
}

