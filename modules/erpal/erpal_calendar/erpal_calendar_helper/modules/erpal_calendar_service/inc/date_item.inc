<?php

/**
 * @file functions needed to make date_item's accessible by services
 * @author Lavong Soysavanh <ls@brightsolutions.de>
 */

/**
 * Create a new date_item node by services module request
 * @param array $date_item the data delivered by the webservice, $date_item['date_item'] must be an array
 * @return the date_item node that was created or an error of date_item could not be created
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_calendar_service_date_item_create($date_item) {
  return services_error('date_item#create not implemented yet', 501);
}

/**
 * callback for retrieving a single date_item resource.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_calendar_service_date_item_retrieve($id, $details = TRUE, $include_children = FALSE, $entity_type = 'date_item', $bundle = '') {
  $date_item_node = _erpal_calendar_service_date_item_out(array($id), $details, $include_children, $entity_type = 'date_item', $bundle = '');
  return $date_item_node;
}

/**
 * Callback for returning a list of date_items respecting given filters
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether tasks will be returned with details , defaults to false
 * @param string $entity_type the entity_type to filter for
 * @param string $bundle the bundle to filter for
 * @return array array of tasks, prepared for output
 */
function _erpal_calendar_service_date_item_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $include_children = false, $entity_type = 'date_item', $bundle = '') {

  // check for entity_type param
  if (!isset($entity_type) || empty($entity_type)) {
    return services_error('entity type expected', 400);
  }

  // query entities
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
      ->range((int) $start, (int) $count)
      ->propertyCondition('updated', (int) $changed_since, '>=');
  $entities = $query->execute();

  // gather output
  $date_items_out = array();
  if (!empty($entities[$entity_type])) {
    $date_items_out = _erpal_calendar_service_date_item_out(array_keys($entities[$entity_type]), $details, $include_children, $entity_type, $bundle);
  }
  return $date_items_out;
}

/**
 * retrieves a date_item node and returns only simple data
 * @param array $ids array of entity id's to return
 * @param bool $details whether or not to return date_item with details
 * @param bool $include_children whether or not to return included children
 * @param string $entity_type the entity_type to filter for
 * @param string $bundle the bundle to filter for
 * @return array the project prepared for output
 */
function _erpal_calendar_service_date_item_out($ids, $details = TRUE, $include_children = FALSE, $entity_type = 'date_item', $bundle = '') {

  // check for entity_type param
  if (!isset($entity_type) || empty($entity_type)) {
    return services_error('entity type expected', 400);
  }

  // load date_item's
  $date_items = entity_load($entity_type, $ids);

  $date_items_out = array();

  foreach ($date_items as $key => $date_item) {
    $date_item_out = array();

    // base data
    $date_item_out['url'] = url('rest/calendar/date_item/' . $date_item->date_item_id, array('absolute' => TRUE));
    $date_item_out['created'] = (int) $date_item->created;
    $date_item_out['changed'] = (int) $date_item->updated;
    $date_item_out['start_date'] = (int) $date_item->date_from;
    $date_item_out['end_date'] = (int) $date_item->date_till;

    // load date item source
    $date_item_src = $date_item->src_entity();
    if ($date_item_src) {

      // title
      $date_item_out['title'] = $date_item_src->title;

      if ($details) {

        // body
        $date_item_src_wrapper = entity_metadata_wrapper('node', $date_item_src);
        if (!empty($date_item_src->body) && !empty($date_item_src->body[LANGUAGE_NONE]) && !empty($date_item_src->body[LANGUAGE_NONE][0])) {
          $date_item_out['body'] = $date_item_src_wrapper->body->value->value();
          $date_item_out['body_format'] = $date_item_src_wrapper->body->format->value();
        }

        // field date type
        if (!empty($date_item_src->field_date_type) && !empty($date_item_src->field_date_type[LANGUAGE_NONE]) && !empty($date_item_src->field_date_type[LANGUAGE_NONE][0])) {
          $date_item_out['date_type'] = $date_item_src->field_date_type[LANGUAGE_NONE][0]['value'];
        }

        // contacts
        $date_item_out['contacts'] = array();
        if (!empty($date_item_src->field_contacts_ref)) {
          foreach ($date_item_src->field_contacts_ref[LANGUAGE_NONE] as $key => $value) {
            if (!empty($value)) {
              if ($include_children) {
                $contact_id = $value['target_id'];
                $contact = node_load($contact_id);
                if ($contact) {
                  $contact_wrapper = entity_metadata_wrapper('node', $contact);
                  $contact_out = array();
                  $contact_out['created'] = (int) $contact->created;
                  $contact_out['changed'] = (int) $contact->changed;
                  $contact_out['url'] = url('rest/basic/contact/' . $contact->nid, array('absolute' => TRUE));
                  $contact_out['revision_timestamp'] = (int) $contact->revision_timestamp;
                  $contact_out['revision_id'] = (int) $contact->revision_uid;
                  $contact_type = $contact_wrapper->field_contact_type->value();
                  $contact_out['type'] = $contact_type;
                  if ($contact_type == 'person') {
                    $contact_out['first_name'] = $contact_wrapper->field_firstname->value();
                    $contact_out['name'] = $contact_wrapper->field_lastname->value();
                    $contact_out['gender'] = $contact_wrapper->field_gender->value();
                  }
                  else if ($contact_type == 'company') {
                    $contact_out['company'] = $contact_wrapper->field_company_name->value();
                  }
                  array_push($date_item_out['contacts'], $contact_out);
                }
              }
              else {
                $contact_id = $value['target_id'];
                $contact_url = url('rest/basic/contact/' . $contact_id, array('absolute' => TRUE));
                array_push($date_item_out['contacts'], $contact_url);
              }
            }
          }
        }

        // users
        $date_item_out['users'] = array();
        if (!empty($date_item_src->field_users) && !empty($date_item_src->field_users[LANGUAGE_NONE])) {
          foreach ($date_item_src->field_users[LANGUAGE_NONE] as $key => $value) {
            if (!empty($value)) {
              $user_id = $value['target_id'];
              $user = user_load($user_id);
              if ($user) {
                if ($include_children) {
                  $user_out = array();
                  $user_out['uid'] = $user_id;
                  $user_out['name'] = $user->name;
                  $user_out['mail'] = $user->mail;
                }
                else {
                  $user_out = url('rest/basic/erpal_user/' . $user_id, array('absolute' => TRUE));
                }
              }
              array_push($date_item_out['users'], $user_out);
            }
          }
        }
      }
    }
    array_push($date_items_out, $date_item_out);
  }

  return $date_items_out;
}

/**
 * Check access for date_item node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_calendar_service_date_item_access($op, $args = NULL) {
  return node_access($op, 'date_item');
}
