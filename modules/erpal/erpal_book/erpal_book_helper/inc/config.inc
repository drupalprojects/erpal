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

  $form = array();
  
  $form['book_skip_pdf_header_frontpage'] = array(
    '#type' => 'checkbox',
    '#title' => t('Skip header logo on pdf frontpage'),
    '#description' => t('If checked, the logo of a pdf document will not be shown on pdfs first page (frontpage)'),
    '#default_value' => _erpal_book_helper_skip_pdf_header_frontpage(),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );

  return $form;
}

/**
* Returns if the logo should not be shown on the first page of a pdg document
*/
function _erpal_book_helper_skip_pdf_header_frontpage() {
  return variable_get('erpal_book_skip_pdf_header_frontpage', false);
}

/**
* Validate config form input
*/
function erpal_book_helper_config_form_validate($form, $form_state) {
  $values = $form_state['values'];
  
  //@TODO
}

/**
* submit handler of erpal book config form
*/
function erpal_book_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];
  $book_skip_pdf_header_frontpage = $values['book_skip_pdf_header_frontpage'];
  variable_set('erpal_book_skip_pdf_header_frontpage', $book_skip_pdf_header_frontpage);  //save email address
  
}
