<?php

/**
* @file this file handles all functions needed for ajax requests in the module erpal_projects_billable
*/
function _erpal_projects_billable_ajax_pricing_preselect_callback($form, $form_state) {
  return $form['field_pricing'][LANGUAGE_NONE][0];  //form has already been processed, so just return the elements
}

/**
* alter the nodereference _url form element so it works with '#ajax' to alter pricing information
*/
function _erpal_projects_billable_element_alter_nodereference_url(&$type) {

  $type['nodereference_url']['#process'] = array('_erpal_projects_billable_nodereference_url_process');
}

/**
* Our process function to make the nodereference_url widget work with form '#ajax' statements. If we dont do that
* the process function transforms the form field to an hidden type after the ajax request sends a nid!
* @see nodereference_url.module
*/
function _erpal_projects_billable_nodereference_url_process($element, $form_state, $form) {

  //only do that if there is no triggering element
  if (!isset($form_state['triggering_element'])) {
    //do what the nodereference URL widget will do
    $element = _nodereference_url_process($element, $form_state, $form);    
  }
  
  return $element;
}