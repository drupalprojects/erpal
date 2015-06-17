<?php

/**
* @file all functions handling with field formatters
*/


/**
 * Implements hook_field_formatter_info().
 */
function erpal_basic_helper_field_formatter_info() {
  return array(
    'entityreference_typed_label' => array(
      'label' => t('Typed label'),
      'description' => t('Display the label of the referenced entities and add the entity type and bundle as css class.'),
      'field types' => array('entityreference'),
      'settings' => array(
        'link' => FALSE,
      ),
    ),
    'relation_endpoint_simple_table' => array(
      'label' => t('Endpoints simple table'),
      'field types' => array('relation_endpoint'),
    ),
    'entityreference_file_node' => array(
      'label' => t('File node file link'),
      'description' => t('Display the title of a file node and click downloads the file'),
      'field types' => array('entityreference'),     
    ),
  );
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function erpal_basic_helper_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  if ($display['type'] == 'entityreference_typed_label') {
    $element['link'] = array(
      '#title' => t('Link label to the referenced entity'),
      '#type' => 'checkbox',
      '#default_value' => $settings['link'],
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function erpal_basic_helper_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $summary = array();

  if ($display['type'] == 'entityreference_typed_label') {
    $summary[] = $settings['link'] ? t('Link to the referenced entity') : t('No link');
  }

  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function erpal_basic_helper_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  $target_ids = array();

  // Collect every possible entity attached to any of the entities.
  foreach ($entities as $id => $entity) {
    
    //check display of each entity    
    
      foreach ($items[$id] as $delta => $item) {
        if (isset($item['target_id'])) {
          $target_ids[] = $item['target_id'];
        }
      }
      
    
  }

  if ($target_ids) {
    $target_entities = entity_load($field['settings']['target_type'], $target_ids);
  }
  else {
    $target_entities = array(); //no entites, no data returned
  }

  // Iterate through the fieldable entities again to attach the loaded data.
  foreach ($entities as $id => $entity) {
    $rekey = FALSE;
    
    foreach ($items[$id] as $delta => $item) {
      // Check whether the referenced entity could be loaded.
      if (isset($item['target_id']) && isset($target_entities[$item['target_id']])) {
        // Replace the instance value with the term data.
        $items[$id][$delta]['entity'] = $target_entities[$item['target_id']];
        // Check whether the user has access to the referenced entity.
        $items[$id][$delta]['access'] = entity_access('view', $field['settings']['target_type'], $target_entities[$item['target_id']]);
      }
      // Otherwise, unset the instance value, since the entity does not exist.
      else {
        if ($displays[$id] == 'relation_endpoint_simple_table') {
          unset($items[$id][$delta]);
          $rekey = TRUE;
        }
      }
    }

    if ($rekey) {
      // Rekey the items array.
      $items[$id] = array_values($items[$id]);
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */

function erpal_basic_helper_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $display_type = $display['type'];
  
  if ($display_type == 'relation_endpoint_simple_table') {
    return _erpal_basic_helper_formatter_view_relation_endpoint_simple_table($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  } elseif ($display_type == 'entityreference_typed_label') {
    return _erpal_basic_helper_formatter_view_entityreference_typed_label($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  } elseif ($display_type == 'entityreference_file_node') {
    return _erpal_basic_helper_formatter_view_entityreference_file_node($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  }
}

/**
* Callback used in hook_field_formatter_info to view entityreference_file_node with link to the direct file and to the node
*/
function _erpal_basic_helper_formatter_view_entityreference_file_node($entity_type, $entity, $field, $instance, $langcode, $items, $display) {  
  
  $result = array();
  $settings = $display['settings'];

  // Rebuild the items list to contain only those with access.
  foreach ($items as $key => $item) {
    if (empty($item['access'])) {
      unset($items[$key]);
    }
  }

  $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

  foreach ($items as $delta => $item) {
    $label = $handler->getLabel($item['entity']);
    // If the link is to be displayed and the entity has a uri, display a link.
    // Note the assignment ($url = ) here is intended to be an assignment.

    if ($uri = entity_uri($field['settings']['target_type'], $item['entity'])) {      
      $download_uri = $item['entity']->field_docs_file[LANGUAGE_NONE][0]['uri'];
      $result[$delta] = _erpal_basic_helper_render_file_link($download_uri, $item['entity']->title, $uri);
    }
    else {
      $result[$delta] = array('#markup' => check_plain($label));
    }
  }

  return $result;
}

/**
* Renders the output of a file node entity reference
*/
function _erpal_basic_helper_render_file_link($file_uri, $title, $entity_uri, $inline=false) {
  $download_url = file_create_url($file_uri);
  $inline = $inline ? 'inline' : '';
  $reference_class = "node_erpal_file";
  $span_class = 'file_download_link';
  if ($inline) {
    $span_class .= ' '.$inline;
    $reference_class .= ' '.$inline;
  }
  
  $link = '<span class="'.$span_class.'"><a href="'.$download_url.'">'.$title.'</a></span><span class="file_node_link">'.l(t('view'), $entity_uri['path'], $entity_uri['options']).'</span>';
  
  return array('#markup' => '<span class="entityreference '.$reference_class.'">'.$link.'</span>');
}

/**
* Callback used in hook_field_formatter_info to view entityreferences with entity type and bundle class
*/
function _erpal_basic_helper_formatter_view_entityreference_typed_label($entity_type, $entity, $field, $instance, $langcode, $items, $display) {  
  
  $result = array();
  $settings = $display['settings'];

  // Rebuild the items list to contain only those with access.
  foreach ($items as $key => $item) {
    if (empty($item['access'])) {
      unset($items[$key]);
    }
  }

  $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

  foreach ($items as $delta => $item) {
    $label = $handler->getLabel($item['entity']);
    // If the link is to be displayed and the entity has a uri, display a link.
    // Note the assignment ($url = ) here is intended to be an assignment.

    if ($display['settings']['link'] && ($uri = entity_uri($field['settings']['target_type'], $item['entity']))) {
      $bundle = _erpal_basic_helper_entity_bundle($item['entity'], $field['settings']['target_type']);
      $reference_class = $entity_type."_".$bundle;
      $result[$delta] = array('#markup' => '<span class="entityreference '.$reference_class.'">'.l($label, $uri['path'], $uri['options']).'</span>');
    }
    else {
      $result[$delta] = array('#markup' => check_plain($label));
    }
  }

  return $result;
}

/**
* returns the bundle name of an entity
*/
function _erpal_basic_helper_entity_bundle($entity, $entity_type) {
  $entity_info = entity_get_info($entity_type);
  
  if (isset($entity_info['bundle keys']['bundle']) && isset($entity->{$entity_info['bundle keys']['bundle']}))
    $type = $entity->{$entity_info['bundle keys']['bundle']};
  else
    return false; 
    
  return $type;
}