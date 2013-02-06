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
    $target_entities = array();
  }

  // Iterate through the fieldable entities again to attach the loaded data.
  foreach ($entities as $id => $entity) {
    $rekey = FALSE;

    foreach ($items[$id] as $delta => $item) {
      // Check whether the referenced entity could be loaded.
      if (isset($target_entities[$item['target_id']])) {
        // Replace the instance value with the term data.
        $items[$id][$delta]['entity'] = $target_entities[$item['target_id']];
        // Check whether the user has access to the referenced entity.
        $items[$id][$delta]['access'] = entity_access('view', $field['settings']['target_type'], $target_entities[$item['target_id']]);
      }
      // Otherwise, unset the instance value, since the entity does not exist.
      else {
        unset($items[$id][$delta]);
        $rekey = TRUE;
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
  $result = array();
  $settings = $display['settings'];

  // Rebuild the items list to contain only those with access.
  foreach ($items as $key => $item) {
    if (empty($item['access'])) {
      unset($items[$key]);
    }
  }

  switch ($display['type']) {
    case 'entityreference_typed_label':
      $handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);

      foreach ($items as $delta => $item) {
        $label = $handler->getLabel($item['entity']);
        // If the link is to be displayed and the entity has a uri, display a link.
        // Note the assignment ($url = ) here is intended to be an assignment.
        if ($display['settings']['link'] && ($uri = entity_uri($field['settings']['target_type'], $item['entity']))) {
          $bundle = _erpal_basic_helper_entity_bundle($entity, $entity_type);
          $reference_class = $entity_type."_".$bundle;
          $result[$delta] = array('#markup' => '<span class="entityreference '.$reference_class.'">'.l($label, $uri['path'], $uri['options']).'</span>');
        }
        else {
          $result[$delta] = array('#markup' => check_plain($label));
        }
      }
      break;
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