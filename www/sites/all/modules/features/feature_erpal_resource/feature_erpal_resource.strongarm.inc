<?php
/**
 * @file
 * feature_erpal_resource.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_resource_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'erpal_resource_content_types';
  $strongarm->value = array(
    'article' => 'article',
    'page' => 'page',
  );
  $export['erpal_resource_content_types'] = $strongarm;

  return $export;
}
