<?php
/**
 * @file
 * feature_erpal_layout.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function feature_erpal_layout_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'erpal_panel_layout';
  $layout->admin_title = 'Erpal panel layout';
  $layout->admin_description = '';
  $layout->category = '';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 1,
          2 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_region',
          1 => 'center',
          2 => 'right_region',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'left_region' => array(
        'type' => 'region',
        'title' => 'Left-region',
        'width' => 100,
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'left-region',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tabs_region',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_region',
        ),
        'parent' => 'main',
        'class' => 'tabs-region',
      ),
      'tabs_region' => array(
        'type' => 'region',
        'title' => 'Tabs-region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'tabs-region',
      ),
      'top_region' => array(
        'type' => 'region',
        'title' => 'Top-region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'top-region',
      ),
      'right_region' => array(
        'type' => 'region',
        'title' => 'Right-region',
        'width' => 100,
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'right-region',
      ),
    ),
  );
  $export['erpal_panel_layout'] = $layout;

  return $export;
}
