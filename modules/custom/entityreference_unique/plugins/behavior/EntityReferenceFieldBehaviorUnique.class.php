<?php

class EntityReferenceFieldBehaviorUnique extends EntityReference_BehaviorHandler_Abstract {

  public function validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {
    $items_values = array();
    // prepare items values in array
    foreach ($items as $item) {
      if ($item['target_id'])
        $items_values[] = $item['target_id'];
    }
    // check if entityreference field contains unique values
    if (count($items_values) > count(array_unique($items_values))) {
      // get field instance settings to get field label
      $field_instance = field_info_instance($entity_type, $field['field_name'], $entity->type);
      // prepare error message
      $error = t('%name field can contain only unique values', array(
        '%name' => $field_instance['label']
        ));
      form_set_error($field['field_name'], $error);
    }
  }

}
