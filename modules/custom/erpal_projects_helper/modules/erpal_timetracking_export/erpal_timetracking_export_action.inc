<?php

/**
 * @file
 * Action for temetracings export.
 */

/**
 * Implements hook_action_info().
 */
function erpal_timetracking_export_action_info() {
  return array(
    'erpal_timetracking_export_basic_action' => array(
      'aggregate' => TRUE,
      'type' => 'node',
      'label' => t('Export timetrackings'),
      'description' => t('Performs Export of timetrackings in file'),
      'configurable' => TRUE,
      'permissions' => array('timeracking export'),
    ),
  );
}

/**
 * Generates settings form for erpal_timetracking_export_basic_action().
 */
function erpal_timetracking_export_basic_action_form($context, $form_state) {
  $export_settings = module_invoke_all('erpal_timetracking_export');
  if (!empty($export_settings)) {
    $options = array();
    $first_key = '';
    $required_pararms = array(
      'title',
      'callback',
    );
    foreach ($export_settings as $key => $export_setting) {
      $error = FALSE;
      foreach ($required_pararms as $required_pararm) {
        if (empty($export_setting[$required_pararm])) {
          $error = TRUE;
        }
      }
      // skip $export_setting if it doesn't have all required parameters
      if ($error){
        continue;
      }
      
      if (empty($first_key)) {
        $first_key = $key;
      }
      $options[$key] = $export_setting['title'];
    }
    // save settings
    $form['export_settings'] = array(
      '#type' => 'value',
      '#value' => $export_settings,
    );

    $form['export_type'] = array(
      '#type' => 'radios',
      '#title' => t('Choose export type'),
      '#options' => $options,
      '#default_value' => $first_key,
      '#required' => TRUE,
    );
  }

  return $form;
}

/**
 * Implements hook_erpal_timetracking_export
 * @return array $export_settings
 *   An associative array of export settings. Each item has settings for 
 *   export type. The keys of the array are the names of the export settings, 
 *   and each corresponding value is an associative array with the following 
 *   key-value pairs:
 *   {Required parameters}
 *   - 'title': string. It's a title of the exported type. Appears in export 
 *     settings form as radio button.
 *   - 'callback': callback function that handles node item in bulk operation.
 *     has parameters:
 *     - $node. returns $row array. I'll be line in exported file.
 *     - $context: array with parameters for this action.
 *   {Non required parameters}
 *   - 'header': array. Contents header of exported file.
 *   - 'filename': name of exported file.
 *   - 'delimiter': string. It's a delimiter of .csv file. Default ';'.
 *   - 'enclosure': string. It's a enclosure of .csv file. Default '"'.
 *   You can add custom parameters and use then is $context variable. But be
 *   very careful and do checks.
 */
function erpal_timetracking_export_erpal_timetracking_export() {
  $export_settings['erpal_timetracking_export'] = array(
    'title' => t('Basic CSV Format (Columns: Description, Duration, Date start, Date start, Date end, User)'),
    'callback' => 'erpal_timetracking_export_handle_entity',
    'header' => array(
      'Description',
      'Duration',
      'Date start',
      'Date end',
      'User',
    ),
    'filename' => 'timetracking_' . date('Y-m-d_h-i'),
    'delimiter' => ';',
    'enclosure' => '"',
  );
  return $export_settings;
}

/**
 * Validates settings form for erpal_timetracking_export_basic_action().
 */
function erpal_timetracking_export_basic_action_validate($form, &$form_state) {
  $empty_export_type = empty($form_state['values']['export_type']);
  $empty_export_settings = empty($form_state['values']['export_settings']);
  if ($empty_export_type || $empty_export_settings) {
    form_set_error('export_type', t('Please choose export type'));
  }
}

/**
 * Submit handler for erpal_timetracking_export_basic_action.
 */
function erpal_timetracking_export_basic_action_submit($form, $form_state) {
  return $form_state['values'];
}

/**
 * Action function for erpal_timetracking_export_basic_action.
 */
function erpal_timetracking_export_basic_action($nodes, $context) {
  $rows = array();
  // head
  $export_settings_array = $context['export_settings'];
  $export_type = $context['export_type'];
  $export_settings = $export_settings_array[$export_type];

  // File header
  if (isset($export_settings['header'])) {
    $rows[] = $export_settings['header'];
  } else {
    $rows[] = array();
  }
  // callback
  $callback = $export_settings['callback'];

  // Create array of file's rows 
  try {
    foreach ($nodes as $node) {
      // handling node item in bulk operation
      $row = $callback($node, $context);
      if (!empty($row)) {
        $rows[] = $row;
      }
    }
  } catch (Exception $e) {
    $rows = array();
    debug('Exception: ' . $e->getMessage());
  }

  // Create new file
  $scheme = 'public';

  // filename
  $filename = 'timetracking_' . date('Y-m-d_h-i') . '.csv';
  if (!empty($export_settings['filename'])) {
    $filename = $export_settings['filename'] . '.csv';
  }
  $destination = $scheme . '://' . $filename;
  $destination = file_destination($destination, FILE_EXISTS_RENAME);

  global $user;
  $exported_file = new stdClass();
  $exported_file->uri = $destination;
  $exported_file->filename = basename($destination);
  $exported_file->filemime = file_get_mimetype($destination);
  $exported_file->uid = $user->uid;
  $exported_file->status = FILE_STATUS_PERMANENT;

  // Genegate .csv file
  $outstream = fopen($destination, 'w');
  // delimiter
  $delimiter = ';';
  if (!empty($export_settings['delimiter'])) {
    $delimiter = $export_settings['delimiter'];
  }
  // enclosure
  $enclosure = '"';
  if (!empty($export_settings['enclosure'])) {
    $enclosure = $export_settings['enclosure'];
  }
  foreach ($rows as $row) {
    fputcsv($outstream, $row, $delimiter, $enclosure);
  }
  fclose($outstream);
  if (file_save($exported_file)) {
    // Download file
    $file_uri = file_create_url($exported_file->uri);
    $url = l('Click here', $file_uri, array('absolute' => TRUE));
    _views_bulk_operations_log(t('Export file has been created. !url to download it.', array('!url' => $url)));
  }
}

/**
 * Callback for handling node item in bulk operation
 * @param object $node
 *    node item in bulk operation
 * @return array 
 *    row item of exported file
 */
function erpal_timetracking_export_handle_entity($node, $context = array()) {
  $node_wrapper = entity_metadata_wrapper($context['entity_type'], $node);
  $row = array();

  // Description
  $row['description'] = utf8_decode($node->title);

  // Duration
  $row['duration'] = $node_wrapper->field_billing_duration->value();
  
  //convert the points to comma, so most excel tools will understand that better
  $row['duration'] = str_replace('.', ',', $row['duration']);

  // Dates
  $date_time = $node_wrapper->field_date_time->value();
  $date_format = _erpal_basic_helper_date_format_date_time();  //get the global time format set in ERPAL settings

  // Date start
  if (!empty($date_time['value'])) {
    $row['date_start'] = date($date_format, $date_time['value']);
  } else {
    $row['date_start'] = '';
  }

  //calculate the end time to make sure it fits with the duration
  $duration_seconds = 3600 * str_replace(',', '.', $row['duration']);
  $date_time['value2'] = $date_time['value'] + $duration_seconds;
   
  // Date end
  if (!empty($date_time['value2'])) {
    $row['date_end'] = date($date_format, $date_time['value2']);
  } else {
    $row['date_end'] = '';
  }
  

  // User
  $row['user'] = $node->name;
  return $row;
}