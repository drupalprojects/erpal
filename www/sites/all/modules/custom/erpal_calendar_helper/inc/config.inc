<?php

/**
* Returns all the menu path for config of invoice feature
*/
function _erpal_calendar_helper_config_menu(){
  
  $items['admin/erpal/calendar'] = array(
    'title' => 'ERPAL Calendar',
    'page callback' => '_erpal_calendar_helper_config_basic',    
    'access arguments' => array('config erpal calendar'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_calendar_helper_config_basic(){
  $form = drupal_get_form('erpal_calendar_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL invoice
*/
function erpal_calendar_helper_config_form($form, &$form_state){

  $form = array();
  $form['#tree'] = true;
  
  $form['date_item_tags'] = array(
    '#type' => 'fieldset',
    '#title' => t('Date categories'),
    '#collapsible' => true,
    '#collapsed' => false,
  );
  
  $instances = field_info_instances();
  //for each field with setting to create date item, add a textfield to enter a term
  foreach ($instances as $entity_type => $bundles) {
    $entity_info = entity_get_info($entity_type);

    foreach ($bundles as $bundle_name => $fields) {      
      foreach ($fields as $field_name=>$field) {
        if (isset($field['date_item']) && $field['date_item']['create_date_item']) {
          //may be add a fieldset first
          if (!isset($form['date_item_tags'][$entity_type])) {            
            $form['date_item_tags'][$entity_type] = array(
              '#type' => 'fieldset',
              '#title' => t('!entity_type tags', array('!entity_type' => $entity_info['label'])),
              '#collapsible' => true,
              '#collapsed' => false,
            );
          }
          
          if ($bundle_name && !isset($form['date_item_tags'][$entity_type][$bundle_name])) {            
            $form['date_item_tags'][$entity_type][$bundle_name] = array(
              '#type' => 'fieldset',
              '#title' => t('!bundle_name tags', array('!bundle_name' => $bundle_name)),  //@TODO later use entity_bundle_label
              '#collapsible' => true,
              '#collapsed' => false,
            );
          }
          
          //now add the field
          //$id = 'date_item_tag_'.$entity_type.'_'.$bundle_name.'_'.$field_name;
          $form['date_item_tags'][$entity_type][$bundle_name][$field_name] = array(
            '#type' => 'textfield',
            '#title' => t('Tags for field !field_name', array('!field_name' => $field_name)),
            '#description' => t('This tag will be added as category to entities with this field'),
            '#default_value' => _erpal_calendar_helper_field_tag($entity_type, $bundle_name, $field_name),
          );
         
        }
          
      }
    }
  }
  
  //special tags
  $form['date_item_tags_special'] = array(
    '#type' => 'fieldset',
    '#title' => t('Employee holiday tag'),
    '#collapsible' => true,
    '#collapsed' => false,
  );
  
  $form['date_item_tags_special']['erpal_calendar_user_holiday_tag_string'] = array(
    '#type' => 'textfield',
    '#title' => t('Tags for holiday date nodes'),
    '#description' => t('This tag will be added as category to date nodes of category "holiday"'),
    '#default_value' => _erpal_calendar_helper_field_tag_holiday_date(),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => array('_erpal_calendar_helper_config_form_submit'),
  );
  
  return $form;
}

/**
* Returns the tag as string that should be set to all date item entites in the given field of the given bundle
* @param $value if set, this value will be updated
*/
function _erpal_calendar_helper_field_tag($entity_type, $bundle_name, $field_name, $value = false) {
  
  $id = 'date_item_tag_'.$entity_type.'_'.$bundle_name.'_'.$field_name;
  $current_tag = variable_get($id, false);
  
  if ($value)
    variable_set($id, $value);

  return $current_tag;
}


/**
* submit handler of erpal calendar config form
*/
function _erpal_calendar_helper_config_form_submit($form, $form_state){

  $values = $form_state['input'];
 
  $date_item_tags = $values['date_item_tags'];
  foreach ($date_item_tags as $entity_type=>$bundles) {
    foreach ($bundles as $bundle_name=>$fields) {
      foreach ($fields as $field_name=>$tag) {
        _erpal_calendar_helper_field_tag($entity_type, $bundle_name, $field_name, $tag);
      }
    }
  }

  //now set the special tags
  $user_holiday_tag_string = $values['date_item_tags_special']['erpal_calendar_user_holiday_tag_string'];
  variable_set('erpal_calendar_user_holiday_tag_string', $user_holiday_tag_string);
  
}
