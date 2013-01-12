<?php

/**
 * Implementation of hook_views_plugins()
 */
function erpal_vcard_views_plugins() {
  $plugin = array(
    'style' => array(
      'erpal_vcard' => array(
        'title' => t('Erpal Vcard'),
        'help' => t('Display contacts as a Vcard'),
        'handler' => 'erpal_vcard_style',
        'theme' => 'erpal_vcard',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',        
      ),
    ),
    'row' => array(
      'erpal_vcard_row' => array(
        'title' => t('Vcard Row'),
        'help' => t('Displays the fields with an optional template.'),
        'handler' => 'erpal_vcard_style_row',
        'theme' => 'erpal_vcard_style_row',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-row-fields',
      ),
    ),
  );

  return $plugin;
}

