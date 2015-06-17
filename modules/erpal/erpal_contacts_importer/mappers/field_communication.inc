<?php
/**
 * @file:
 *   Contains code for the field_communication field collection mapper
 */


/**
 * Form callback for the field_communication target
 * @param $mapping
 * @param $target
 * @param $form
 * @param $form_state
 * @return array
 */
function erpal_contacts_importer_feeds_field_communication_form_callback($mapping, $target, $form, $form_state) {

  if($mapping['target'] == 'erpal_contacts_importer_field_communication'){
    return array(
      'field_communication_type' => array(
        '#title' => t('Type'),
        '#type' => 'select',
        '#options' => erpal_contacts_importer_get_communication_types(),
        '#default_value' => !empty($mapping['field_communication_type'])
            ? $mapping['field_communication_type'] : ''
      ),
      'field_communication_category' => array(
        '#type' => 'textfield',
        '#title' => t('Category'),
        '#autocomplete_path' => 'taxonomy/autocomplete/field_communication_category',
        '#default_value' => !empty($mapping['field_communication_category'])
            ? $mapping['field_communication_category'] : ''
      ),
    );
  }
}
/**
 * Returns array of options for the field_communication_type
 * @return mixed
 */
function erpal_contacts_importer_get_communication_types(){
  $field = field_info_field('field_communication_type');
  return $field['settings']['allowed_values'];
}
/**
 * Summary callback for the field_communication target
 * @param $mapping
 * @param $target
 * @param $form
 * @param $form_state
 * @return null|string
 */
function erpal_contacts_importer_feeds_field_communication_summary_callback($mapping, $target, $form, $form_state) {
  if (empty($mapping['field_communication_type']) && empty($mapping['field_communication_category'])) {
    return t('Not configured yet');
  }
  else {
    $summary = '';
    if(!empty($mapping['field_communication_type'])){
      $types = erpal_contacts_importer_get_communication_types();
      $summary .= t('Type: <strong>@type</strong>; ', array(
        '@type' => $types[$mapping['field_communication_type']]
      ));
    }
    if(!empty($mapping['field_communication_category'])){
      $summary .=  t('Category: <strong>@cat</strong>;', array(
        '@cat' => $mapping['field_communication_category']
      ));
    }
    return $summary;
  }
}
/**
 * Maps the field_communication field_collection
 * @param $source
 * @param $entity
 * @param $target
 * @param $values
 * @param array $mapping
 */
function erpal_contacts_importer_feeds_processor_field_communication_target($source, &$entity, $target, $values, $mapping = array()){

  if(empty($mapping['field_communication_type'])){
    return;
  }

  $field_ct = $mapping['field_communication_type'];
  $field_cc = isset($mapping['field_communication_category'])
    ? $mapping['field_communication_category'] : '';

  if (!is_array($values)) {
    $values = array($values);
  }

  foreach($values as $value){
// If no value is set, return
    if(empty($value)){
      continue;
    }

    $exist = false;
// Try to find existing field collection first.
    if(isset($entity->field_communication[LANGUAGE_NONE])){
      foreach( $entity->field_communication[LANGUAGE_NONE] as $key => $field ){
        $fc = field_collection_item_load($field['value'], true);
        if(!$fc){
          continue;
        }
        if(isset($fc->field_communication_address[LANGUAGE_NONE])
          && $fc->field_communication_address[LANGUAGE_NONE][0]['value'] == $value
          && _erpal_contacts_importer_compare_field($fc, 'text', 'field_communication_type', $field_ct)
          && (!isset($mapping['field_communication_category'])
            || _erpal_contacts_importer_compare_field($fc, 'term', 'field_communication_category', $field_cc)))
        {
          $exist = true;
        }
      }
    }

    if($exist){
      continue;
    }

    $fc_item = entity_create('field_collection_item', array('field_name' => 'field_communication'));

    $fc_item->field_communication_type[LANGUAGE_NONE][0]['value'] = $mapping['field_communication_type'];

    if(!empty($mapping['field_communication_category'])) {
      $term = _erpal_contacts_importer_make_sure_term_exists($mapping['field_communication_category'], 'communication_categories');
      $fc_item->field_communication_category[LANGUAGE_NONE][0]['tid'] = $term->tid;
    }

    $fc_item->field_communication_address[LANGUAGE_NONE][0]['value'] = $value;

    $fc_item->setHostEntity('node', $entity);
    $fc_item->save();
  }
}

