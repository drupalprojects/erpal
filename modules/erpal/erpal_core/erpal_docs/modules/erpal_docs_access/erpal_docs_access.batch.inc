<?php

/**
 * Implements hook_cron()
 */
function erpal_docs_access_cron() {
  if (variable_get('erpal_docs_access_cron')) {
    watchdog('erpal_docs_access', 'cron runs batch for building child nodes permissions');
    $batch_info = _erpal_docs_access_batch_info();
    batch_set($batch_info);
    $batch = &batch_get();
    // Run batch in background
    $batch['progressive'] = FALSE;
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
 * Batch operation
 */
function erpal_docs_access_batch(&$context) {
  $child_ids = _erpal_docs_access_read_queue_by_name('erpal_docs_access_update');
  $default_settings = variable_get('erpal_docs_access_fields', array());
  _erpal_docs_access_batch($context, $child_ids, $default_settings);
}

/**
 * Build child nodes permissions
 */
function _erpal_docs_access_batch(&$context, $child_ids, $default_settings) {
  // Count of operation in one butch step
  $limit = 1;

  // prepare variables
  if (empty($context['sandbox']['progress'])) {
    // select users with range
    $users_count = _erpal_docs_access_get_users_count();
    $context['sandbox']['progress'] = 0;
    // Get count of progress
    $context['sandbox']['max'] = $users_count;
    $context['results']['total_count'] = $context['sandbox']['max'];
    // settings
    $context['sandbox']['settings'] = $default_settings;
    // get childs from queue
    $context['sandbox']['child_ids'] = $child_ids;
    if (!count($context['sandbox']['child_ids']))
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

/**
 * Batch start function callback
 */
function erpal_docs_access_rebuild_batch_start() {
  $batch = _erpal_docs_access_rebuild_batch_info();
  batch_set($batch);
}

/**
 * Build batch info
 */
function _erpal_docs_access_rebuild_batch_info() {
  $batch = array(
    'title' => t('Rebuild all files permissions'),
    'operations' => array(
      array('erpal_docs_access_rebuild_batch', array()),
    ),
    'progress_message' => t('Rebuilding all files permissions. Operation @current out of @total.'),
    'error_message' => t('Error!'),
    'finished' => 'erpal_docs_access_batch_finished',
  );
  watchdog('erpal_docs_access', 'Started batch for rebuilding all files permissions');

  return $batch;
}

/**
 * Batch operation
 */
function erpal_docs_access_rebuild_batch(&$context) {

  if (empty($context['sandbox']['progress']) || $context['sandbox']['progress']) {
    if (empty($context['sandbox']['child_ids'])) {
      // select users with range
      $context['sandbox']['progress'] = 0;

      // Users start variables
      // Get count of progress
      if (!$users_count = _erpal_docs_access_get_users_count())
        return;
      
      $context['results']['total_count'] = $users_count;
      // Create Iteration variable
      $context['sandbox']['users_iter'] = 0;

      // Files start variables
      $build = _erpal_docs_access_build_childs_settings();
      if (empty($build['child_ids']) || empty($build['settings']))
        return;
      $context['sandbox']['settings'] = $build['settings']; // settings
      $context['sandbox']['child_ids'] = $build['child_ids']; // get childs
      // childs count
      if (!$childern_count = count($context['sandbox']['child_ids']))
        return;

      $context['results']['total_children'] = $childern_count;

      // Create Iteration variable
      $context['sandbox']['childs_iter'] = 0;
    }
  }

  // added alias for child params
  $childs = $context['sandbox']['child_ids'];
  $settings = $context['sandbox']['settings'];

  // start
  if (empty($context['results']['total_count']))
    return;
  if (empty($childs) || empty($settings))
    return;

  // Count of operation in one butch step
  $users_step = 10;
  $childs_step = 30;

  // get list of users
  if (empty($context['sandbox']['users'])) {
    $current_user = $context['sandbox']['users_iter'];
    $length = $users_step; // $current_user + $users_step;
    $users = _erpal_docs_access_get_users($current_user, $length);
    $context['sandbox']['users'] = $users;
  } else {
    $users = $context['sandbox']['users'];
  }

  // loop users
  for ($i = 0; $i < $users_step; $i++) {

    // Check product
    $uid = '';
    if (isset($users[$i])) {
      $uid = $users[$i];

      $current_child = $context['sandbox']['childs_iter'];
      // loop childs
      $child_ids = array();

      for ($j = $current_child; $j < ($current_child + $childs_step); $j++) {
        if (isset($childs[$j]['id']))
          $child_ids[$childs[$j]['id']] = $childs[$j];
        else
          break;
      }

      // handle user access
      _erpal_docs_access_handle_user($uid, $child_ids, $settings);
    }

    // Message
    $context['message'] = t('Now processing user with id %name. Step %progress of %count', array(
      '%name' => $uid,
      '%progress' => $context['sandbox']['progress'],
      '%count' => $context['results']['total_count'],
      ));
    $context['results']['processed'] = $context['sandbox']['progress'];
  }

  // Increment childs step
  $context['sandbox']['childs_iter'] += $childs_step;
  // Check end of childs array
  if ($context['sandbox']['childs_iter'] >= $context['results']['total_children']) {
    // Increment users step
    $context['sandbox']['childs_iter'] = 0;
    $context['sandbox']['users'] = array();
    $context['sandbox']['users_iter'] += $users_step;

    // Update Progress
    $context['sandbox']['progress'] += $users_step;
  }

  if ($context['sandbox']['progress'] != $context['results']['total_count']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['results']['total_count'];
  }
}

/**
 * Batch finished
 */
function erpal_docs_access_batch_finished($success, $results, $operations) {
  variable_set('erpal_docs_access_cron', FALSE);

  // Succes message
  $message = t(
    '@users users and @nodes nodes have been processed.', array(
    '@users' => isset($results['total_count']) ? $results['total_count'] : 0,
    '@nodes' => isset($results['total_children']) ? $results['total_children'] : 0,
    )
  );

  watchdog('erpal_docs_access', $message);
  drupal_set_message($message);
}