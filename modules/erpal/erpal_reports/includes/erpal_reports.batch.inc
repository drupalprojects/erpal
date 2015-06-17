<?php

/**
* @file provide batch functionality for report generation
*/

/**
 * Batch start function callback
 */
function erpal_reports_batch_start($variables) {
  $_SESSION['erpal_reports']['had_batch'] = TRUE;  
  $batch = _erpal_reports_batch_info($variables);
  batch_set($batch);
  batch_process();  
}

/**
* Restore form post data
*/
function erpal_report_restore_form_post_data(&$form_state) {
  if (!empty($_SESSION['erpal_reports']['had_batch'])) {       
    $form_state['values'] = !empty($_SESSION['erpal_reports']['values']) ? $_SESSION['erpal_reports']['values'] : array();

    //correct some values for date_popup...
    if (!empty($form_state['values']['date_from'])) {
      $form_state['values']['date_from'] = array('date' => date('d.m.Y', strtotime($form_state['values']['date_from'])));       
    }
    
    if (!empty($form_state['values']['date_to'])) {
      $form_state['values']['date_to'] = array('date' => date('d.m.Y', strtotime($form_state['values']['date_to'])));  
    }

    //values that are set to 0 should be set to FALSE
    foreach ($form_state['values'] as $name => $value) {
      if (is_numeric($value) && !$value) {
        $form_state['values'][$name] = FALSE;
      }
    }
    
    $form_state['input'] = $form_state['values'];
    unset($_SESSION['erpal_reports']);   
  }
}

/**
 * Build batch info
 */
function _erpal_reports_batch_info($variables) {
  
  $batch = array(
    'title' => t('Create report'),
    'operations' => array(
      array('erpal_reports_create_report_batch', array('variables' => $variables)),
    ),
    'progress_message' => t('Creating reports. Operation @current out of @total.'),
    'error_message' => t('Error!'),
    'finished' => 'erpal_reports_batch_finished',
  );
  watchdog('erpal_reports', t('Started batch for creating reports.'));

  return $batch;
}


/**
 * Batch operation
 */
function erpal_reports_create_report_batch($variables, &$context) {
  $class = $variables['class'];
  $callback = $variables['process_callback'];  
  
  $limit = 100;
  // prepare variables
  if (empty($context['sandbox']['progress'])) {
    // select users with range
    $id_count = count($variables['ids']);
    $context['sandbox']['progress'] = 0;
    // Get count of progress
    $context['sandbox']['max'] = $id_count;
    $context['results']['total_count'] = $id_count;
    // settings
    $context['sandbox']['variables'] = $variables;
    
    if (!$id_count)
      return;
  }
  
  // Check for the end of cycle
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {    
    // get next list of users
    $start = $context['sandbox']['progress'];
    $length = $start + $limit;
    $context['start'] = $start;
    $context['length'] = $length;
    
    call_user_func($class .'::'.$callback, $context);
    
    // Update Progress
    $context['sandbox']['progress'] += $limit;

    // Message
    $context['message'] = t('Now processing item %progress of %count', array(
      '%progress' => $context['sandbox']['progress'],
      '%count' => $context['sandbox']['max'],
      ));
    $context['results']['processed'] = $context['sandbox']['progress'];
    $context['results']['finish_callback'] = $variables['finish_callback'];
    $context['results']['class'] = $variables['class'];
    $context['results']['variables'] = $context['sandbox']['variables'];

  }
    
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  } else {
    $context['finished'] = false;
  }
}


/**
 * Batch finished
 */
function erpal_reports_batch_finished($success, $results, $operations) {

  //call the finish callback
  $class = $results['class'];
  $callback = $results['finish_callback'];
  $variables = $results['variables'];
  $extended = !empty($variables['extended']) ? $variables['extended'] : FALSE;
  call_user_func($class .'::'.$callback, $variables['options'], $variables['data'], $variables['details'], $extended);

  // Success message
  $message = t('Report was created successfully.');

  $_SESSION['erpal_reports']['had_batch'] = TRUE;
  watchdog('erpal_reports', $message);
  drupal_set_message($message);
}