<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	05/04/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * This file contains all function around the approval queue for activities.
 */

function _erpal_crm_activity_queue_view ($form, &$form_state) {
  
  drupal_set_title (t('ERPAL Activity queue'));
  
  module_load_include ('inc', 'erpal_crm_activity_queue', 'inc/ActivityQueueModel.class');
  
  $default_date = array(
    'year'   => date ('Y'), 
    'month'  => date ('n'), 
    'day'    => date ('j'), 
  ); 
  
  $form['filter'] = array (
    '#type'	  => 'fieldset',
    '#title'	=> t('Filter'),
  );
  
  $form['filter']['range_from'] = array (
    '#type'	            => 'date',
    '#title'	          => t('Date from'),
    '#default_value'		=> isset ($_SESSION['range_from']) ? $_SESSION['range_from'] : $default_date
  );
  
  $form['filter']['range_to'] = array (
    '#type'	            => 'date',
    '#title'	          => t('Date to'),
    '#default_value'		=> isset ($_SESSION['range_to']) ? $_SESSION['range_to'] : $default_date
  );
  
  $form['filter']['submit'] = array (
    '#type'	  => 'submit',
    '#value'	=> t('Submit'),
  );
  
  $form['result']  = array(
    '#type'       => 'tableselect',
    '#header'     => erpal_crm_activity_queue\ActivityQueueModel::getHeader(),
    '#options'    => _erpal_crm_activity_queue_view_results (),
    '#empty'      => t('The queue is temporaly empty.'),
    '#multiple'		=> TRUE
  );
  
  $form['pager'] = array (
    '#markup' => theme('pager', array('tags' => array()))  
  );
  
  $form['aprove'] = array (
    '#type'	  => 'submit',
    '#value'	=> t('Approve selected'),
    '#submit' => array ('_erpal_crm_activity_queue_view_approve_submit')
  );
  
  return $form;
}

/*
 * The validate callback of the view form.
 */
function _erpal_crm_activity_queue_view_validate (&$form, &$form_state) {
  
  $values = $form_state['values'];
  
  if (
    _erpal_crm_activity_queue_view_create_timestamp ($values['range_from']) >
    _erpal_crm_activity_queue_view_create_timestamp ($values['range_to']) 
  ) {
    form_set_error ('range_from', t('The start date can not be later than the end date.'));
  }
  
  if (
    _erpal_crm_activity_queue_view_create_timestamp ($values['range_to']) <
    _erpal_crm_activity_queue_view_create_timestamp ($values['range_from']) 
  ) {
    form_set_error ('range_to', t('The end date can not be earlier than the start date.'));
  }
  
  return;
}

/*
 * The submit callback of the view form.
 */
function _erpal_crm_activity_queue_view_submit (&$form, &$form_state) {
  
  $values = $form_state['values'];
  
  $_SESSION['range_from']  = $values['range_from'];
  $_SESSION['range_to']    = $values['range_to'];
  
  return;
}

/*
 * The submit callback of the view form.
 */
function _erpal_crm_activity_queue_view_approve_submit (&$form, &$form_state) {

  if (erpal_crm_activity_queue\ActivityQueueModel::approve($form_state['values']['result'])) {
    drupal_set_message (t('Activity elements has been successfuly approved.'));
  }else{
    drupal_set_message (t('An error occured while trying to approve some activity elements.'));
  }
  
  return;
}

/*
 * @return array 	An array which contains the results of the view.
 */
function _erpal_crm_activity_queue_view_results () {
  
  $model = new erpal_crm_activity_queue\ActivityQueueModel ();  
  
  return $model->dateRange (
    _erpal_crm_activity_queue_view_create_timestamp ($_SESSION['range_from']), 
    _erpal_crm_activity_queue_view_create_timestamp ($_SESSION['range_to'])
  )->status (TRUE)->
  load ();
}

/*
 * Creates a timestamp from a date widget return value.
 * @return integer	A UNIX timestamp.
 */
function _erpal_crm_activity_queue_view_create_timestamp (array $date_widget_values) {
 
  return mktime (
    0, 0, 0,
    $date_widget_values['month'],
    $date_widget_values['day'],
    $date_widget_values['year']
  );
}
