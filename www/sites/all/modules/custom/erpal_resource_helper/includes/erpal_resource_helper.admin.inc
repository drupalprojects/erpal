<?php

/**
 * Returns all the menu path for config of resource feature
 */
function _erpal_resource_helper_config_menu(){
  
  $items['admin/erpal/resource'] = array(
    'title' => 'ERPAL resource',
    'page callback' => '_erpal_resource_helper_config_basic',    
    'access arguments' => array('config erpal resource'),
    'file' => 'includes/erpal_resource_helper.admin.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
 * Settings for the ERPAL resource feature
 */
function _erpal_resource_helper_config_basic(){
  $form = drupal_get_form('erpal_resource_helper_config_form');
  return $form;
}

/**
 * Form to show all settings to configure ERPAL resource
 */
function erpal_resource_helper_config_form($form, &$form_state){

  $form = array();

	// checkboxes for selecting the content types to be a resource
	$form['visibility']['node_type']['types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Make these content types a possible ressource'),
    '#default_value' => variable_get('erpal_resource_content_types', array()),
    '#options' => node_type_get_names(),
    '#description' => t('The checked content types will be available as a bookable resource. If you select no types, there will be no resources available in the system for resource planing.'),
  );
	
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );
  
  return $form;
}

/**
 * Submit handler of erpal resource config form
 */
function erpal_resource_helper_config_form_submit($form, $form_state){
	// store content types being used as a resource
	$content_types = array_filter($form_state['values']['types']);
	variable_set('erpal_resource_content_types', $content_types);
}