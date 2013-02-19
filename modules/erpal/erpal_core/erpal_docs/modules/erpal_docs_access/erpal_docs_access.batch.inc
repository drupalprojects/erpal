<?php

/**
 * Implements hook_cron()
 */
function erpal_docs_access_cron() {
  if (variable_get('erpal_docs_access_cron')) {
    watchdog('erpal_docs_access', 'cron runs batch for building child nodes permissions');
    $batch = _erpal_docs_access_batch_info();
    batch_set($batch);
    // Run batch in background
    batch_process('');
  }
}

/**
 * Batch start function callback
 */
function erpal_docs_access_batch_start() {
  $batch = _erpal_docs_access_batch_info();
  batch_set($batch);
}

/**
 * Build batch info
 */
function _erpal_docs_access_batch_info() {
  $batch = array(
    'title' => t('Build child nodes permissions'),
    'operations' => array(
      array('erpal_docs_access_batch', array()),
    ),
    'progress_message' => t('Building child nodes permissions. Operation @current out of @total.'),
    'error_message' => t('Error!'),
    'finished' => 'erpal_docs_access_batch_finished',
  );
  watchdog('erpal_docs_access', 'Started batch for building child nodes permissions');

  return $batch;
}

/**
 * Build child nodes permissions
 */
function erpal_docs_access_batch(&$context) {
  // Count of operation in one butch step
  $limit = variable_get('erpal_docs_access_users_count', 30);

  // Collect info for Butch delete operation
  if (empty($context['results'])) {
    $context['results']['users'] = array(
      'created' => array(),
      'edited' => array(),
      'errors' => array(),
    );
  }

  // prepare variables
  if (empty($context['sandbox']['progress'])) {
    // select users with range
    $users_count = _erpal_docs_access_get_users_count();
    $context['sandbox']['progress'] = 0;
    // Get count of progress
    $context['sandbox']['max'] = $users_count;
    $context['results']['total_count'] = $context['sandbox']['max'];
    // settings
    $context['sandbox']['settings'] = variable_get('erpal_docs_access_fields', array());
    // get childs from queue
    $context['sandbox']['child_ids'] = _erpal_docs_access_read_queue_by_name('erpal_docs_access_update');
    if(!count($context['sandbox']['child_ids']))
      return;
    $context['results']['total_children'] = count($context['sandbox']['child_ids']);
  }
  
  // Create Iteration variable
  if (empty($context['sandbox']['iteration'])) {
    $context['sandbox']['iteration'] = 0;
  }

  // Check for the end of cycle
  if ($context['sandbox']['iteration'] < $context['sandbox']['max']) {
    // Counts completed operations in one butch step
    if ($context['sandbox']['progress'] != 0) {
      $context['sandbox']['iteration'] = $context['sandbox']['iteration'] + $limit;
    }

    // get next list of users
    $start = $context['sandbox']['iteration'];
    $length = $start + $limit;
    $users = _erpal_docs_access_get_users($start, $length);

    $counter = 0;
    // Batch body. Loop all users
    for ($i = $context['sandbox']['iteration']; $i < $context['sandbox']['max'] && $counter < $limit; $i++) {

      // Check product
      $uid = '';
      if (isset($users[$counter])) {
        $uid = $users[$counter];
        $child_ids = $context['sandbox']['child_ids'];
        $settings = $context['sandbox']['settings'];
        _erpal_docs_access_handle_user($uid, $child_ids, $settings);
      }
      // Update Progress
      $context['sandbox']['progress']++;
      $counter++;
      // Message
      $context['message'] = t('Now processing user %name. User %progress of %count', array(
        '%name' => $uid,
        '%progress' => $context['sandbox']['progress'],
        '%count' => $context['sandbox']['max'],
        ));
      $context['results']['processed'] = $context['sandbox']['progress'];
    }
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function erpal_docs_access_batch_finished($success, $results, $operations) {
  variable_set('erpal_docs_access_cron', FALSE);

  // Succes message
  $message = t(
    '@users users and @nodes nodes have been processed.', array(
    '@users' => $results['total_count'],
    '@nodes' => $results['total_children'],
    )
  );

  watchdog('erpal_docs_access', $message);
  drupal_set_message($message);
}