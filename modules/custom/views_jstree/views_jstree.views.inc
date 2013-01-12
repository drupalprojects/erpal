<?php

/**
 * Implementation of hook_views_plugins()
 */
function views_jstree_views_plugins() {
  $plugin = array(
    'style' => array(
      'jstree' => array(
        'title' => t('JS Tree'),
        'help' => t('Display the results as a js tree'),
        'handler' => 'views_jstree_plugin_style_tree',
        'theme' => 'views_jstree',
        'uses options' => TRUE,
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => FALSE,
        'type' => 'normal',
        'parent' => 'list',        
      ),
    ),
  );

  return $plugin;
}

