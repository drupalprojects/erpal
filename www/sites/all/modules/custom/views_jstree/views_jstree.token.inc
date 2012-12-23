<?php

/**
 * @file provides token functionallity for views_jstree module
 */

/**
 * Implements hook_token_info().
 */
function views_jstree_token_info() {
  $type_name = t("Tokens for jstree menu");
  $type_desc = t("Tokens for jstree e.g. for use in context menu.");
  $needs_data = 'view';

  $views_jstree = array();
  // List all views.
  $views = views_get_all_views();
  $types = array();
  $tokens = array();

  $type_prefix = 'views_jstree';
  foreach ($views as $view) {
    // Skip disabled views.
    if (!empty($view->disabled)) {
      continue;
    }

    foreach ($view->display as $display) {
      //now add the tokens for this type      
      $fields = views_jstree_get_fields_of_view($view, $display);
      if ($fields && is_array($fields)) {
        //add a type for each display with each field of the display is a token
        $type = $type_prefix . "_" . $view->name . "_" . $display->id;

        $types[$type] = array(
          'name' => $type_name,
          'description' => $type_desc,
          'needs-data' => $needs_data,
        );

        foreach ($fields as $fieldname => $field) {
          $field_label = isset($field['label']) && $field['label'] ? $field['label'] : $field['field'];
          $tokens[$type][$field['id']] = array(
            'name' => $field_label,
            'description' => t('Token for field "!field_label"', array('!field_label' => $field_label)),
          );
        }
      }
    }
  }

  $ret = array(
    'types' => $types,
    'tokens' => $tokens,
  );

  return $ret;
}

/**
 * Implements hook_tokens().
 */
function views_jstree_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;

  $replacements = array();

  $type_prefix = 'views_jstree';

  if (strpos($type, $type_prefix) === false)
    return $replacements;

  if (!isset($data[$type]['view']))
    return $replacements;

  $view = $data[$type]['view'];
  $display = $data[$type]['display'];
  $row = $data[$type]['row'];
  $type_prefix = 'views_jstree';
  $type_expected = $type_prefix . "_" . $view->name . "_" . $display->id;
  if ($type == $type_expected) {
    $fields = views_jstree_get_fields_of_view($view, $display);
    foreach ($tokens as $name => $original) {
      $replacements[$original] = $row->{$name};  //@TODO this only works for nid, other fields not testet and need some work with converting!
    }
  }

  return $replacements;
}