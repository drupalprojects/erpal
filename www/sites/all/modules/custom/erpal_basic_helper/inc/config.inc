<?php

/**
* Returns all the menu path for config of Basic feature
*/
function _erpal_basic_helper_config_menu(){
  
  $items['admin/erpal'] = array(
    'title' => 'ERPAL',
    'page callback' => '_erpal_basic_helper_config',    
    'access arguments' => array('config erpal'),
    'file' => 'inc/config.inc',
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/erpal/basic'] = array(
    'title' => 'ERPAL BASIC',
    'page callback' => '_erpal_basic_helper_config_basic',    
    'access arguments' => array('config erpal basic'),
    'file' => 'inc/config.inc',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_basic_helper_config_basic(){
  $form = drupal_get_form('erpal_basic_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL Core
*/
function erpal_basic_helper_config_form($form, &$form_state){

  $form = array();
  
  $new_contact_link = _erpal_basic_helper_create_contact_link(false, array(), t('create a new contact'));
  $form['my_company'] = array(
    '#title' => t('My Company'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'crm/contacts/autocomplete',
    '#default_value' => _erpal_basic_helper_get_own_company_nid(true),
    '#description' => t('Select your own company from your contacts or !add_new_contact_link', array('!add_new_contact_link' => $new_contact_link)),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );
  
  return $form;
}

/**
* submit handler of erpal basic config form
*/
function erpal_basic_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];
  $my_company_string = $values['my_company'];
  
  $nid = _erpal_basic_helper_get_nid_from_autocomplete_string($my_company_string);
  variable_set('erpal_config_my_company_nid', $nid);  //speichern
}

/**
* returnd the nid from a string created by _erpal_basic_helper_autocomplete_string_from_nid
*/
function _erpal_basic_helper_get_nid_from_autocomplete_string($autocomplete_string){

  preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $autocomplete_string, $matches);
  $nid = 0;
  if (!empty($matches)) {
    $nid = $matches[2];
  }
  
  return $nid;
}

/**
* Returns the own company of the installation
*/
function _erpal_basic_helper_get_own_company_nid($for_autocomplete){
  
  $contact_nid = variable_get('erpal_config_my_company_nid', false);
  
  if ($for_autocomplete)
    return _erpal_basic_helper_autocomplete_string_from_nid($contact_nid);
  else
    return $contact_nid;
}

/**
* returns a autocomplete compatible String for a nid (title [nid: 12])
*/
function _erpal_basic_helper_autocomplete_string_from_nid($nid){
  if (!$nid)
    return '';
  $node = node_load($nid);
  
  return $node->title . " [nid:" . $nid . "]";
}

/**
* Overview for all the activated ERPAL Features
*/
function _erpal_basic_helper_config(){
  $erpal_config_base = 'admin/erpal';
  $sql = "
    SELECT m.load_functions, m.to_arg_functions, m.access_callback, m.access_arguments, m.page_callback, m.page_arguments, m.delivery_callback, m.title, m.title_callback, m.title_arguments, m.type, m.description, ml.*
    FROM {menu_links} ml LEFT JOIN {menu_router} m ON m.path = ml.router_path
    WHERE ml.router_path = :router_path
    ORDER BY p1 ASC, p2 ASC, p3 ASC, p4 ASC, p5 ASC, p6 ASC, p7 ASC, p8 ASC, p9 ASC";
  $result = db_query($sql, array(':router_path' => $erpal_config_base), array('fetch' => PDO::FETCH_ASSOC));
  $links = array();
  foreach ($result as $item) {
    $links[] = $item;
  }
  
  //here we have MORE THAN the mid if the erpal_config_base path, now we need the children.
  //TODO: we have to display all settings, but first we have to have a concept how the display of nested features and subfeatures config 
  //should look like.
  $tree = menu_tree_data($links);
  $node_links = array();
  menu_tree_collect_node_links($tree, $node_links);
  //dpm($tree);
  // We indicate that a menu administrator is running the menu access check.
  $menu_admin = TRUE;
  menu_tree_check_access($tree, $node_links);
  $menu_admin = FALSE;
  
  return "ERPAL CONFIG";
}