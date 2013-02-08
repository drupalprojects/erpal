<?php
/**
 * @file
 * erpal_layout.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function erpal_layout_default_panels_layout() {
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
          0 => 3,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '100',
        'width_type' => '%',
        'children' => array(
          0 => 5,
          1 => 1,
          2 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'right_region',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'row-second-left',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'row-second-left',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'row_first_left_',
          1 => 'row_first_right',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'right_region' => array(
        'type' => 'region',
        'title' => 'row-second-right',
        'width' => '250',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'row-second-right',
      ),
      3 => array(
        'type' => 'column',
        'width' => '150',
        'width_type' => 'px',
        'parent' => 'canvas',
        'children' => array(
          0 => 6,
        ),
        'class' => 'left-region',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'tabs_region_',
        ),
        'parent' => 'main',
        'class' => 'tabs-region',
      ),
      'tabs_region_' => array(
        'type' => 'region',
        'title' => 'tabs-region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '5',
        'class' => 'tabs-item',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_region',
        ),
        'parent' => '3',
        'class' => 'left-region',
      ),
      'left_region' => array(
        'type' => 'region',
        'title' => 'left-region',
        'width' => 100,
        'width_type' => 'px',
        'parent' => '6',
        'class' => '',
      ),
      'row_first_left_' => array(
        'type' => 'region',
        'title' => 'row-first-left',
        'width' => '100',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'row-first-left',
      ),
      'row_first_right' => array(
        'type' => 'region',
        'title' => 'row-first-right',
        'width' => '250',
        'width_type' => 'px',
        'parent' => '1',
        'class' => 'row-first-right',
      ),
    ),
  );
  $export['erpal_panel_layout'] = $layout;

  return $export;
}
