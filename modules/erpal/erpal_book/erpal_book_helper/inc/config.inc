<?php

/**
* Returns all the menu path for config of book feature
*/
function _erpal_book_helper_config_menu(){
  
  $items['admin/erpal/book'] = array(
    'title' => 'ERPAL Book',
    'page callback' => '_erpal_book_helper_config_basic',    
    'access arguments' => array('config erpal book'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL book Feature
*/
function _erpal_book_helper_config_basic(){
  $form = drupal_get_form('erpal_book_helper_config_form');
  return $form;
}

/**
* Form to show all settings to configure ERPAL book feature
*/
function erpal_book_helper_config_form($form, &$form_state){
    
  $allowed_extensions = array('png', 'jpg', 'jpeg', 'gif');
  $form = array();
  
  $form['frontpage'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings for the document frontpage'),
    
  );
  
  $frontpage_logo_fid = variable_get('erpal_book_helper_frontpage_logo', false);  
  $frontpage_logo_file = ($frontpage_logo_fid) ? file_load($frontpage_logo_fid) : FALSE;
  
  $form['frontpage']['frontpage_logo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Logo for the frontpage'),
    '#description' => t('Upload your logo that will be used at the frontpage of your document exports. Allowed file extensions: !extensions', array('!extensions' => implode(',', $allowed_extensions))),
    '#upload_validators' => array('file_validate_extensions' => array(implode(' ', $allowed_extensions))),
    '#upload_location' => _erpal_book_helper_logo_documents_upload_dir(),
    '#default_value' => $frontpage_logo_file ? $frontpage_logo_file->fid : false,
  );
 
  $types = array('erpal_basic');
  $tokens = theme('token_tree', array('global_types' => FALSE, 'token_types' => $types));
  $form['header_footer']['document_footer']['#suffix'] = $tokens;
  
  $form['submit'] = array(
    '#value' => t('Save'),
    '#type' => 'submit',
  );

  return $form;
}

/**
* submit handler of erpal book config form
*/
function erpal_book_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];
  
  $frontpage_logo_fid = $values['frontpage_logo'];
  variable_set('erpal_book_helper_frontpage_logo', $frontpage_logo_fid);
  if ($frontpage_logo_fid){  
    //finalise the file!
    $file = file_load($frontpage_logo_fid);
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'erpal_book_helper', 'config', $file->fid); 
  }
}

function _erpal_book_helper_logo_documents_upload_dir(){
  
  $uri = "public://erpal_res";
  
  //prepare the folder
  file_prepare_directory($uri,  FILE_CREATE_DIRECTORY);
  return $uri;
}
