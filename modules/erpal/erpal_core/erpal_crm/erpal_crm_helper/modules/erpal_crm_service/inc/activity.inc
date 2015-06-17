<?php
/**
 * All functions needed to make erpal_crm accessible by services.
 *
 * @file        activity.inc
 * @package     erpal_core\erpal_crm\erpal_crm_helper\erpal_crm_service
 * @author      Manuel Pistner <pistner@brightsolutions.de>  
 * @copyright   2013+ © By Bright Solutions GmbH
 */

/**
 * Create a new crm_activity node by services module request.
 * 
 * @param array $activity the data delivered by the webservice, $activity['crm_activity'] must be an array
 * @return the activity that was created or an error of activity could not be created
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_crm_service_crm_activity_create($activity) {
  
  $returns = array();
  global $user;
 
  if (empty($activity)) {
    return services_error('activity expected', 400);
  }
  
  //if we don't have title, take the first 65 chars from body
  $contacts     = isset($activity['contacts']) ? $activity['contacts'] : array();
  $body         = isset($activity['body']) ? $activity['body'] : '';
  $title        = isset($activity['title']) ? $activity['title'] : substr($body, 1, 65);
  $origin       = isset($activity['origin']) ? $activity['origin'] : '';
  $customer_nid = isset($activity['customer']) ? 
                  _erpal_basic_helper_autocomplete_string_from_nid(
                   _erpal_crm_service_extract_contact_id_from_url(
                      $activity['customer']
                    )): FALSE;

  //Find the term to the origin string
  //@TODO: maybe better escape the origin?
  $origin_term_id = taxonomy_get_term_by_name($origin, 'activity_origin');
  $origin_term_id = reset($origin_term_id);  
  $origin_term_id = $origin_term_id !== FALSE ? $origin_term_id->tid : $origin_term_id;

  //@TODO: set next contact and make it configurable in ERPAL settings

  $form_id = 'erpal_crm_activity_node_form';
  $form_values = array(
    'title' => $title,
    'body' => array(LANGUAGE_NONE => array(0 => array('value' => $body, 'format' => 'filtered_html'))),
    'language' => LANGUAGE_NONE,
    'name' => $user->name,
    'status' => 1,
    'type' => 'erpal_crm_activity',
    'promote' => 0,
    'sticky' => 0,
  );

  if ($origin_term_id) {
    $form_values['field_activity_origin'][LANGUAGE_NONE]['tid'] = $origin_term_id;
  }

  if ($customer_nid !== FALSE) {
    $form_values['field_customer_ref'][LANGUAGE_NONE][0]['target_id'] =  $customer_nid;
  }

  // Assign contacts.
  foreach ($contacts as $contact) {
    
    if (! isset($form_values['field_contacts_ref'][LANGUAGE_NONE])) {
      $form_values['field_contacts_ref']                = array();
      $form_values['field_contacts_ref'][LANGUAGE_NONE] = array();
    }
 
    $form_values['field_contacts_ref'][LANGUAGE_NONE][]['target_id'] = _erpal_basic_helper_autocomplete_string_from_nid(
      _erpal_crm_service_extract_contact_id_from_url(
        $contact
      )
    );
  }

  // node module stores form processing functions in a
  // seperate include entitled node.pages.inc
  // so must load that before executing form
  module_load_include('inc', 'node', 'node.pages');
  $form_values['op'] = t('Save');  // this seems to be a required value
  $form_state['values'] = $form_values;

  $activity_node = (object)array('type' => 'erpal_crm_activity');
  drupal_form_submit($form_id, $form_state, $activity_node);
  $node = $form_state['node'];

  $errors = form_get_errors();
  //die(print_r($form_state['node']));
 
  return _erpal_crm_service_create_service_response($errors, $activity_node);
}

/**
 * Callback for update a single acitivty resource.
 * 
 * @param int $nid the node id of the activity to update
 * @param string $data the json payload to update the activity with
 */
function _erpal_crm_service_crm_activity_update($nid, $data) {

  if (empty($data)) {
    services_error('activity expected', 400);
  }
 

  $activity = node_load($nid);
  if (!$activity) {
    services_error('invalid nid: ' . $nid, 400);
  }
  if ($activity->type !== 'erpal_crm_activity') {
    services_error('wrong node type. ' . $nid . ' is not an activity', 400);
  }
  $activity_wrapper = entity_metadata_wrapper('node', $activity);

  try {
    if (isset($data['title'])) {
      $activity->title = $data['title'];
    }
    if (isset($data['body'])) {
      $activity_wrapper->body->value->set($data['body']);
      $activity_wrapper->save();
    }
    if (isset($data['customer']) && is_numeric($data['customer'])) {
      $customer_id = $data['customer'];
      $contact_node = node_load($customer_id);
      if (!$contact_node || $contact_node->type !== 'erpal_contact') {
        services_error('invalid customer id: ' . $customer_id, 400);
      }
      $activity_wrapper->field_customer_ref->set($data['customer']);
      $activity_wrapper->save();
    }
    if (isset($data['contacts']) && is_array($data['contacts'])) {
      $contact_urls = $data['contacts'];
      $contact_ids  = array();
      foreach ($contact_urls as $contact_url) {
        $cid          = _erpal_crm_service_extract_contact_id_from_url($contact_url);
        $contact_node = node_load($cid);
        if (!$contact_node || $contact_node->type !== 'erpal_contact') {
          services_error('invalid contact id: ' . $cid, 400);
          break;
        }
        
        $contact_ids[] = $cid;
      }
      $activity_wrapper->field_contacts_ref->set($contact_ids);
      $activity_wrapper->save();
    }

    $activity->changed = (int) time();
    node_save($activity);
  } catch (Exception $e) {
    services_error('failed updating activity: ' . $e->getMessage(), 500, $e->getTraceAsString());
  }

  drupal_load('module', 'erpal_basic_service');
 
  $basic_service_endpoint = erpal_crm_service_default_services_endpoint(); 
  $basic_service_endpoint = array_shift($basic_service_endpoint);

  $result = array();
  $result['success']          = true;
  $result['url']              = url('rest/activity/crm_activity/' . $nid, array('absolute' => TRUE));
  $result['comments']         = url(
    $basic_service_endpoint->path . '/erpal_comment/' . $nid,
    array('absolute'=>TRUE)
  );
  
  return $result;
}

/**
 * Callback for retrieving a single activity resource.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_crm_service_crm_activity_retrieve($id, $details = TRUE, $include_children = false) {
  $contact_node = _erpal_crm_service_crm_activity_out((int) $id, $details, $include_children);
  return $contact_node;
}

/**
 * Callback for returning a list of activities respecting given filters.
 * 
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether tasks will be returned with details , defaults to false
 * @param bool $include_children wheter or not to include children
 * @return array array of tasks, prepared for output
 */
function _erpal_crm_service_crm_activity_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $include_children = false) {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'erpal_crm_activity')
      ->range((int) $start, (int) $count)
      ->propertyCondition('changed', (int) $changed_since, '>=');

  $entities = $query->execute();

  $activities_out = array();

  if (!empty($entities['node'])) {
    foreach (array_keys($entities['node']) as $nid) {
      $activities_out[] = _erpal_crm_service_crm_activity_out($nid, $details, $include_children);
    }
  }

  return $activities_out;
}

/**
 * Retrieves an activity node and returns only simple data.
 * 
 * @param int $nid the node id of the project to return
 * @param bool $details whether or not to return the project with details
 * @param bool $include_children wheter or not no include children
 * @return array the project prepared for output
 */
function _erpal_crm_service_crm_activity_out($nid, $details = FALSE, $include_children = false) {

  // load activity node
  $activity = node_load($nid);

  // check if node is an activity
  if ($activity->type !== 'erpal_crm_activity') {
    return services_error('failed loading node. nid ' . $nid . ' is not an activity', 400);
  }

  // load wrapper
  $activity_wrapper = entity_metadata_wrapper('node', $activity);

  // base data
  $activity_out = array();
  $activity_out['created'] = (int) $activity->created;
  $activity_out['changed'] = (int) $activity->changed;
  $activity_out['url'] = url('rest/activity/crm_activity/' . $activity->nid, array('absolute' => TRUE));
  $activity_out['title'] = $activity->title;

  // revision
  $activity_out['revision_timestamp'] = (int) $activity->revision_timestamp;
  $activity_out['revision_id'] = (int) $activity->revision_uid;

  if ($details) {

    // body
    if (!empty($activity->body)) {
      $activity_out['body'] = strip_tags($activity_wrapper->body->value->value());
    }

    // status
    if (!empty($activity->field_activity_status_term)) {
      $activity_out['status'] = $activity_wrapper->field_activity_status_term->name->value();
    }

    // next contact
    if (!empty($activity->field_next_contact)) {
      $activity_out['next_contact'] = (int) $activity_wrapper->field_next_contact->value();
    }

    // customer
    if (!empty($activity->field_customer_ref)) {
      $customer_id = $activity->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
      $activity_out['customer'] = url('rest/basic/contact/' . $customer_id, array('absolute' => TRUE));
    }

    // contacts
    $activity_out['contacts'] = array();
    if (!empty($activity->field_contacts_ref)) {
      foreach ($activity->field_contacts_ref[LANGUAGE_NONE] as $key => $value) {
        $contact_id = $value['target_id'];
        $contact_url = url('rest/basic/contact/' . $contact_id, array('absolute' => TRUE));
        array_push($activity_out['contacts'], $contact_url);
      }
    }

    // files
    $activity_out['files'] = array();
    foreach ($activity_wrapper->field_asset_files->getIterator() as $key => $file) {
      $file_array = $file->field_docs_file->value();
      if (!empty($file_array)) {
        array_push($activity_out['files'], array(
          'filename' => $file_array['filename'],
          'mimetype' => $file_array['filemime'],
          'filesize' => (int) $file_array['filesize'],
          'url' => file_create_url($file_array['uri']),
          'description' => ($file_array['description']) ? $file_array['description'] : '',
          'fid' => (int) $file_array['fid'],
        ));
      }
    }

    // Volume
    if (!empty($activity->field_volume)) {
      $activity_out['volume'] = (float)$activity_wrapper->field_volume->value();
    }
    
    // Chance
    if (!empty($activity->field_chance)) {
      $activity_out['chance'] = (int)$activity_wrapper->field_chance->value();
    }
    
    // Expected date
    if (!empty($activity->field_expected_date)) {
      $activity_out['expected_date'] = (int)$activity_wrapper->field_expected_date->value();
    }
    
    // Internal order number
    if (!empty($activity->field_order_number_intern)) {
      $activity_out['order_number_intern'] = strip_tags($activity_wrapper->field_order_number_intern->value());
    }

    // External order number
    if (!empty($activity->field_order_number_extern)) {
      $activity_out['order_number_extern'] = strip_tags($activity_wrapper->field_order_number_extern->value());
    }
    
    // Account manager
    if (!empty($activity->field_account_manager)) {
      $activity_out['account_manager'] = url(
        'rest/basic/erpal_user/' . $activity_wrapper->field_account_manager->value()->uid, 
        array('absolute' => TRUE)
      );
    }

    // comments
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'comment')
        ->propertyCondition('nid', $nid);
    $entities = $query->execute();
    if (!empty($entities['comment'])) {
      if ($include_children) {
        $activity_out['comments'] = array();
        foreach (array_keys($entities['comment']) as $cid) {
          $comment = comment_load($cid);
          if ($comment) {
            $comment_body = $comment->comment_body[LANGUAGE_NONE][0];
            $comment_out = array(
              'created' => (int) $comment->created,
              'changed' => (int) $comment->changed,
              'cid' => (int) $comment->cid,
              'subject' => ($comment->subject) ? $comment->subject : '',
              'name' => ($comment->name) ? $comment->name : '',
              'registered_name' => ($comment->registered_name) ? $comment->registered_name : '',
              'comment_body' => $comment_body['value'],
              'comment_format' => $comment_body['format'],
              'author_url' => url('rest/basic/erpal_user/' . $comment->uid, array('absolute' => TRUE)),
            );
            array_push($activity_out['comments'], $comment_out);
          }
        }
      }
      else {
        $activity_out['comments'] = url('rest/basic/erpal_comment/' . $nid, array('absolute' => TRUE));
      }
    }
  }

  return $activity_out;
}

/**
 * Check access for creating a crm_activity node
 */
function _erpal_crm_service_crm_activity_access($op, $args) {
  return node_access($op, 'erpal_crm_activity');
}

/**
 * Creates an array as the response of a webservice request
 */
function _erpal_crm_service_create_service_response($errors, $activity_node) {
  
  if (!empty($errors)) {

    $returns['error'] = TRUE;
    $error_string = '';
    foreach ($errors as $key => $value) {
      $error_string .= $key . ": " . $value . "<br/>";
    }
    $returns['message'] = 'Activity could not be created because of some errors: <br/>' . $error_string;
    watchdog('erpal-crm-activity-service', var_export($returns, TRUE));
    services_error(
      'Could\'t save activity.',
      500,
      (object)$returns
    );
    return;
  }
  
  drupal_load('module', 'erpal_crm_service');
 
  $crm_service_endpoint = erpal_crm_service_default_services_endpoint(); 
  $crm_service_endpoint = array_shift($crm_service_endpoint);
  
  drupal_load('module', 'erpal_basic_service');
 
  $basic_service_endpoint = erpal_crm_service_default_services_endpoint(); 
  $basic_service_endpoint = array_shift($basic_service_endpoint);
 
  $returns['error']   = false;
  $returns['message'] = '';
  $returns['url']     = url(
    $crm_service_endpoint->path . '/crm_activity/' . $activity_node->nid,
    array('absolute'=>TRUE)
  );
  $returns['comments'] = url(
    $basic_service_endpoint->path . '/erpal_comment/' . $activity_node->nid,
    array('absolute'=>TRUE)
  );
  
  return (object)$returns;
}

/**
 * Extracts the ID from a contact URL.
 */
function _erpal_crm_service_extract_contact_id_from_url($url) {
  
  $matches = array();
  
  if (preg_match('/contact\\/([0-9]+)/', $url, $matches) < 1) {
    return FALSE;
  }
  
  return $matches[1];
}
