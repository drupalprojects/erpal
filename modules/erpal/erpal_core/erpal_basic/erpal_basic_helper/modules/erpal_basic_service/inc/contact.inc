<?php

/**
 * @file all functions needed to make contacts accessible by services
 * @author Manuel Pistner <pistner@brightsolutions.de>
 * @copyright (c) 2013
 */

/**
 * Create a new contact node by services module request.
 * 
 * @param array $contact    The data delivered by the webservice, $contact['contact'] must be an array.
 * @return object           The response details for the contact node that was created or an error of contact could not be created.
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_basic_service_contact_create($contact) {
 
  global $user;
 
  if (empty($contact)) {
    return services_error('Contact data expected', 400);
  }

  //if we don't have title, take the first 65 chars from body
  $firstname        = isset($contact['firstname']) ? $contact['firstname'] : '';
  $lastname         = isset($contact['name']) ? $contact['name'] : '';
  $company          = isset($contact['company']) ? $contact['company'] : '';
  $email            = isset($contact['mail']) ? $contact['mail'] : '';
  $origin           = isset($contact['origin']) ? $contact['origin'] : false;
  $nid              = isset($contact['nid']) ? $contact['nid'] : false;
  $phone            = isset($contact['phone']) ? $contact['phone'] : false;
  $vat_number       = isset($contact['vat_number']) ? $contact['vat_number'] : false;
  $criteria         = isset($contact['criteria']) ? $contact['criteria'] : array();
  $addresses        = isset($contact['addresses']) ? $contact['addresses'] : array();

  //check if there is already a contact with the given name and emailadress, if so, return this nid 
  $contact_nid = false;
  if (count($criteria))
    $contact_nid = erpal_lib_helper_entity_check_exits($criteria, 'node', 'erpal_contact');

  //create the contact node object, new one if none exists or load the node
  if (!$contact_nid) {
    $contact_node_arr = array('type' => 'erpal_contact');
    $contact_node = (object) $contact_node_arr;
  }
  else {
    $contact_node = node_load($contact_nid);
  }

  $form_id = 'erpal_contact_node_form';
  $form_values = array(
    'language' => LANGUAGE_NONE,
    'name' => $user->name,
    'status' => 1,
    'type' => 'erpal_contact',
    'promote' => 0,
    'sticky' => 0,
  );

  //now add all the fields if they are set
  if ($firstname && !$contact_nid)
    $form_values['field_firstname'] = array(LANGUAGE_NONE => array(0 => array('value' => $firstname)));
  if ($lastname && !$contact_nid)
    $form_values['field_lastname'] = array(LANGUAGE_NONE => array(0 => array('value' => $lastname)));
  if ($company)
    $form_values['field_company_name'] = array(LANGUAGE_NONE => array(0 => array('value' => $lastname)));
  if ($email)
    $form_values['field_email'] = array(LANGUAGE_NONE => array(0 => array('value' => $email)));
  if ($origin) {
    $tid = _erpal_basic_service_check_and_create_term($origin, 'activity_origin');
    $form_values['field_activity_origin'][LANGUAGE_NONE]['value'] = $tid;
  }

  if (false && $contact_tag) {
    //@TODO: add contact tag
    $form_values['field_contact_tags'] = array(LANGUAGE_NONE => array(0 => array('tid' => $contact_tag)));
  }
  //@TODO: handle relations may be company and a person is set, we need to save both
  //@TODO: TEST FROM HERE TEST TEST TEST FROM HERE
  //@TODO: handle field collections and taxonomy terms, create new if not exist 
  //  $addresses = array();
  $phones = array();
  if ($phone) {
    //@TODO: with setting delta=0 the current number with delta = 0 gets lost. So we need to find the correct delta if there are already values set
    $phones[LANGUAGE_NONE][0]['field_phone_number'] = array(LANGUAGE_NONE => array(0 => array('value' => $phone)));
    
    
  }

  //add only new addresses
  $form_values['field_addresses'] = _erpal_basic_service_check_and_add_addresses($addresses, $contact_node);

  if ($vat_number) 
   $form_values['field_vat_number'] = array(LANGUAGE_NONE => array(0 => array('value' => $vat_number)));

  $form_values['field_phone'] = $phones;

  // if there is no contact, create one otherwise it will be updated
  // node module stores form processing functions in a
  // seperate include entitled node.pages.inc
  // so must load that before executing form
  module_load_include('inc', 'node', 'node.pages');
  $form_values['op']    = t('Save');  // this seems to be a required value
  $form_state['values'] = $form_values;
  //we need to set items_count, if we add multiple field entries 

  $addresses_count        = count(isset($contact_node->field_addresses) ? $contact_node->field_addresses : array());
  $new_addresses_count    = count(isset($form_values['field_addresses'][LANGUAGE_NONE]) ? $form_values['field_addresses'][LANGUAGE_NONE] : array());
  $form_state['field']['field_addresses'][LANGUAGE_NONE]['items_count'] = $addresses_count + $new_addresses_count;
  drupal_form_submit($form_id, $form_state, (object) $contact_node);

  $contact_node = $form_state['node'];

  $errors = form_get_errors();

  //return ids of sent addresses, so commerce can tell invoicing which addresses to use
  $contact_node->use_addresses = _erpal_basic_service_id_of_addresses($contact_node, $addresses);

  return _erpal_basic_service_create_service_response($errors, $contact_node);
}

/**
 * updates a given contact node
 * @param int $nid the contact node id to update
 * @param array $data the contact data to update with
 * @return array webservice response
 */
function _erpal_basic_service_contact_update($nid, $data) {

  if (empty($data)) {
    services_error('contact expected', 400);
  }
 
  try {
    $accepted_contact_types = array('person', 'company');
    $accepted_gender_types = array('m', 'f');

    $contact = node_load($nid);
    if (!$contact || ($contact->type !== 'erpal_contact')) {
      services_error('wrong node type. ' . $nid . ' is not a contact', 400);
    }
    $contact_wrapper = entity_metadata_wrapper('node', $contact);
//    dpm($contact_wrapper->getPropertyInfo(), 'contact property infos');

    if (isset($data['type'])) {
      $type = strtolower($data['type']);
      if (!in_array($type, $accepted_contact_types)) {
        services_error('unsupported contact type: ' . $type . ' (expected: ' . implode(',', $accepted_contact_types) . ')', 400);
      }
      $contact_wrapper->field_contact_type->set($type);
    }
    if (isset($data['first_name'])) {
      $contact_wrapper->field_firstname->set($data['first_name']);
    }
    if (isset($data['name'])) {
      $contact_wrapper->field_lastname->set($data['name']);
    }
    if (isset($data['gender'])) {
      $gender = strtolower($data['gender']);
      if (!in_array($gender, $accepted_gender_types)) {
        services_error('unsupported gender type: ' . $gender . '(expected: ' . implode(',', $accepted_gender_types) . ')', 400);
      }
      $contact_wrapper->field_gender->set($gender);
    }
    if (isset($data['company'])) {
      $contact_wrapper->field_company_name->set($data['company']);
    }
    if (isset($data['birthday'])) {
      $birthday_time = strtotime($data['birthday']);
      $contact_wrapper->field_birthday->set($birthday_time);
    }
    if (isset($data['fax']) && is_array($data['fax'])) {
      $fax_numbers = $data['fax'];
      $contact_wrapper->field_fax->set($fax_numbers);
    }
    if (isset($data['email']) && is_array($data['email'])) {
      $emails = $data['email'];
      $contact_wrapper->field_email->set($emails);
    }
    if (isset($data['phones']) && is_array($data['phones'])) {
      $phone_numbers = $data['phones'];
      // discard old phone numbers
      foreach ($contact_wrapper->field_phone->getIterator() as $key => $phone) {
        $entity_id = $contact->field_phone[LANGUAGE_NONE][$key]['value'];
        $fcie = field_collection_item_load($entity_id);
        if ($fcie) {
          $fcie->delete();
        }
        $contact->field_phone[LANGUAGE_NONE] = array();
      }
      // insert given ones
      foreach ($phone_numbers as $p) {
        $number_type_name = $p['number_type'];
        $tid = _erpal_basic_service_check_and_create_term($number_type_name, 'number_types');
        $phone_number = entity_create('field_collection_item', array('field_name' => 'field_phone'));
        $phone_number->setHostEntity('node', $contact);
        $phone_number_wrapper = entity_metadata_wrapper('field_collection_item', $phone_number);
        $phone_number_wrapper->field_phone_number->set($p['number']);
        $phone_number_wrapper->field_number_type_terms->set($tid);
        $phone_number->save(TRUE);
      }
    }
    if (isset($data['social'])) {
      $social = $data['social'];
      if (isset($social['xing'])) {
        $contact_wrapper->field_xing->url->set($social['xing']);
      }
      if (isset($social['facebook'])) {
        $contact_wrapper->field_facebook->url->set($social['facebook']);
      }
      if (isset($social['twitter'])) {
        $contact_wrapper->field_twitter->url->set($social['twitter']);
      }
      if (isset($social['google'])) {
        $contact_wrapper->field_google_plus->url->set($social['google']);
      }
    }
    if (isset($data['addresses'])) {
      $addresses = $data['addresses'];
      // discard old addresses
      foreach ($contact_wrapper->field_addresses->getIterator() as $key => $address) {
        $entity_id = $contact->field_addresses[LANGUAGE_NONE][$key]['value'];
        $fcie = field_collection_item_load($entity_id);
        if ($fcie) {
          $fcie->delete();
        }
        $contact->field_addresses[LANGUAGE_NONE] = array();
      }
      // insert given ones
      if (!empty($addresses)) {
        foreach ($addresses as $address) {
          if (!empty($address)) {
            $address_entity = entity_create('field_collection_item', array('field_name' => 'field_addresses'));
            $address_entity->setHostEntity('node', $contact);
            $address_wrapper = entity_metadata_wrapper('field_collection_item', $address_entity);
            if (isset($address['address_name'])) {
              $address_wrapper->field_address_name->set($address['address_name']);
            }
            if (isset($address['address_type'])) {
              $tid= _erpal_basic_service_check_and_create_term($address['address_type'], 'address_types');
              $address_wrapper->field_address_type_terms->set(
                $tid
              );
            }
            if (isset($address['city'])) {
              $address_wrapper->field_city->set($address['city']);
            }
            if (isset($address['street'])) {
              $address_wrapper->field_street->set($address['street']);
            }
            if (isset($address['zip_code'])) {
              $address_wrapper->field_zip_code->set($address['zip_code']);
            }
            if (isset($address['country'])) {
              $country_tid = _erpal_basic_service_check_and_create_term($address['country'], 'countries');
              $address_wrapper->field_country_term->set($country_tid);
            }
            $address_entity->save(TRUE);
          }
        }
      }
    }

    $contact->changed = time();

    //create new revision
    $contact->revision = 1;
    $contact->log = 'contact updated by web service on ' . date('c') . ' | ' . json_encode($data);

    // save - $contact_wrapper->save();
    node_save($contact);
  } catch (Exception $e) {
    services_error('Failed updating node: ' . $e->getMessage(), 500);
  }

  return (object)array(
    'url' => url(
      services_endpoint_load('erpal_basic_rest')->path . '/contact/' . $contact->nid,
      array('absolute'=>TRUE)
    )
  );
}

/**
 * find the addresses (given in array) that are attached to node
 * @param stdClass $contact_node contact node object
 * @param array $addresses array of addresses
 * @return array with shipping and billing address
 */
function _erpal_basic_service_id_of_addresses($contact_node, $addresses) {
  $out = array();
  $sent_addresses = array();
  foreach ($addresses as $address) {
    //need to normalize, so serialize works even if order of array is wrong
    $sent_address['address_name']         = (string)$address['address_name'];
    $sent_address['addition_to_address']  = (string)$address['addition_to_address'];
    $sent_address['street']               = (string)$address['street'];
    $sent_address['zip']                  = (string)$address['zip_code'];
    $sent_address['city']                 = (string)$address['city'];
    $sent_address['address_type']         = $address['address_type'];
    $sent_address['country']              = $address['country'];
    $sent_addresses[]                     = serialize($address);
  }


  $existing_addresses = field_get_items('node', $contact_node, 'field_addresses');
  foreach ($existing_addresses as $existing_address_id) {
    $collection = entity_load_single('field_collection_item', $existing_address_id['value']);

    $address_name = field_get_items('field_collection_item', $collection, 'field_address_name');
    $existing_address['address_name'] = (string)$address_name[0]['value'];
    $addition = field_get_items('field_collection_item', $collection, 'field_addition_to_address');
    $existing_address['addition_to_address'] = (string)$addition[0]['value'];
    $street = field_get_items('field_collection_item', $collection, 'field_street');
    $existing_address['street'] = (string)$street[0]['value'];
    $zip = field_get_items('field_collection_item', $collection, 'field_zip_code');
    $existing_address['zip'] = (string)$zip[0]['value'];
    $city = field_get_items('field_collection_item', $collection, 'field_city');
    $existing_address['city'] = (string)$city[0]['value'];
    $type = field_get_items('field_collection_item', $collection, 'field_address_type_terms');
    $existing_address['address_type'] = taxonomy_term_load($type[0]['tid'])->name;
    $country = field_get_items('field_collection_item', $collection, 'field_country_term');
    $existing_address['country'] = taxonomy_term_load($country[0]['tid'])->field_country_code[LANGUAGE_NONE][0]['value'];

    if (in_array(serialize($existing_address), $sent_addresses)) {
      if ($existing_address['address_type'] == 'commerce shipping') {
        $out['shipping'] = $existing_address_id['value'];
      }
      if ($existing_address['address_type'] == 'commerce billing') {
        $out['billing'] = $existing_address_id['value'];
      }
    }
  }

  return $out;
}

/**
 * callback for retrieving a single contact resource.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @param bool $details whether contact will be returned with details , defaults to true
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_basic_service_contact_retrieve($id, $details = TRUE, $include_children = FALSE) {
  $contact_node = _erpal_basic_service_contact_out((int) $id, $details, $include_children);
  return $contact_node;
}

/**
 * Callback for returning a list of contacts respecting given filters
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether tasks will be returned with details , defaults to false
 * @param bool $include_children whether or not to include children
 * @return array array of tasks, prepared for output
 */
function _erpal_basic_service_contact_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $include_children = false) {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'erpal_contact')
      ->range((int) $start, (int) $count)
      ->propertyCondition('changed', (int) $changed_since, '>=');

  $entities = $query->execute();

  $contacts_out = array();

  if (!empty($entities['node'])) {
    foreach (array_keys($entities['node']) as $nid) {
      $contacts_out[] = _erpal_basic_service_contact_out($nid, $details, $include_children);
    }
  }

  return $contacts_out;
}

/**
 * retrieves a contact node and returns only simple data
 * @param int $nid the node id of the project to return
 * @param bool $details whether or not to return the project with details
 * @param bool $include_children whether or not to include children
 * @return array the project prepared for output
 */
function _erpal_basic_service_contact_out($nid, $details = TRUE, $include_children = false) {

  // load contact node
  $contact = node_load($nid);

  // if given node id is not a contact, return error
  if ($contact->type !== 'erpal_contact') {
    return services_error('failed loading node. nid ' . $nid . ' is not a contact', 400);
  }

  // load wrapper
  $contact_wrapper = entity_metadata_wrapper('node', $contact);

  // construct response
  $contact_out = array();

  // base data
  $contact_out['created'] = (int) $contact->created;
  $contact_out['changed'] = (int) $contact->changed;
  $contact_out['url'] = url('rest/basic/contact/' . $contact->nid, array('absolute' => TRUE));

  // revision
  $contact_out['revision_timestamp'] = (int) $contact->revision_timestamp;
  $contact_out['revision_id'] = (int) $contact->revision_uid;

  // contact type
  $contact_type = $contact_wrapper->field_contact_type->value();
  $contact_out['type'] = $contact_type;

  // name
  if ($contact_type == 'person') {
    $contact_out['first_name'] = $contact_wrapper->field_firstname->value();
    $contact_out['name'] = $contact_wrapper->field_lastname->value();
    $contact_out['gender'] = $contact_wrapper->field_gender->value();
  }
  else if ($contact_type == 'company') {
    $contact_out['company'] = $contact_wrapper->field_company_name->value();
  }

  if ($details) {

    // addresses
    if (!empty($contact->field_addresses)) {
      try {
        $contact_out['addresses'] = array();
        foreach ($contact_wrapper->field_addresses->getIterator() as $key => $address) {
          $a_name = $address->field_address_name->value();
          $a_city = $address->field_city->value();
          $a_street = $address->field_street->value();
          $a_zip_code = $address->field_zip_code->value();
          $a_country = $address->field_country_term->name->value();
          array_push($contact_out['addresses'], array(
            'name' => $a_name ? $a_name : '',
            'city' => $a_city ? $a_city : '',
            'street' => $a_street ? $a_street : '',
            'zip_code' => $a_zip_code ? $a_zip_code : '',
            'country' => $a_country ? $a_country : '',
          ));
        }
      } catch (Exception $e) {
        
      }
    }
    // image
    if (!empty($contact->field_contact_image)) {
      $image_array = $contact_wrapper->field_contact_image->value();
      $contact_out['image'] = url('sites/default/files/' . $image_array['filename'], array('absolute' => TRUE));
    }
    // phones
    if (!empty($contact->field_phone) && !empty($contact->field_phone[LANGUAGE_NONE]) && !empty($contact->field_phone[LANGUAGE_NONE][0])) {
      $contact_out['phones'] = array();
      foreach ($contact_wrapper->field_phone->getIterator() as $key => $phone) {
        $phone_type = ''; //$phone->field_number_type_terms->name->value(), // FIXME this does not work for no apparent reason!!
        $entity_id = $contact->field_phone[LANGUAGE_NONE][$key]['value'];
        $fc = field_collection_item_load($entity_id);
        if (isset($fc) && !empty($fc->field_number_type_terms) && !empty($fc->field_number_type_terms[LANGUAGE_NONE])) {
          $tid = $fc->field_number_type_terms[LANGUAGE_NONE][0]['tid'];
          $term = taxonomy_term_load($tid);
          if ($term) {
            $phone_type = $term->name;
          }
        }
        try {
          $phone_number = $phone->field_phone_number->value();
        } catch (Exception $e) {
          
        }
        array_push($contact_out['phones'], array(
          'type' => $phone_type ? $phone_type : '',
          'number' => $phone_number ? $phone_number : '',
        ));
      }
    }
    // faxes
    if (!empty($contact->field_fax)) {
      $contact_out['fax'] = $contact_wrapper->field_fax->value();
    }
    // emails
    if (!empty($contact->field_email)) {
      $contact_out['mail'] = $contact_wrapper->field_email->value();
    }
    // websites
    if (!empty($contact->field_website)) {
      $contact_out['websites'] = array();
      foreach ($contact_wrapper->field_website->getIterator() as $key => $website) {
        array_push($contact_out['websites'], $website->url->value());
      }
    }

    // relations
    $contact_out['employees'] = _erpal_basic_service_get_employees_relations($contact, $include_children);
    $contact_out['works_at'] = _erpal_basic_service_get_works_at_relations($contact, $include_children);

    // files
    $contact_out['files'] = array();
    foreach ($contact_wrapper->field_asset_files->getIterator() as $key => $file) {
      $file_array = $file->field_docs_file->value();
      if (!empty($file_array)) {
        array_push($contact_out['files'], array(
          'filename' => $file_array['filename'],
          'mimetype' => $file_array['filemime'],
          'filesize' => (int) $file_array['filesize'],
          'url' => file_create_url($file_array['uri']),
          'description' => ($file_array['description']) ? $file_array['description'] : '',
          'fid' => (int) $file_array['fid'],
        ));
      }
    }
    // birthday
    if (!empty($contact->field_birthday)) {
      $contact_out['birthday'] = substr($contact->field_birthday[LANGUAGE_NONE][0]['value'], 0, 10); // $contact_wrapper->field_birthday->raw();
    }
    // social
    $contact_out['social'] = array();
    if ($contact->field_xing) {
      $contact_out['social']['xing'] = $contact_wrapper->field_xing->url->value();
    }
    if ($contact->field_facebook) {
      $contact_out['social']['facebook'] = $contact_wrapper->field_facebook->url->value();
    }
    if ($contact->field_twitter) {
      $contact_out['social']['twitter'] = $contact_wrapper->field_twitter->url->value();
    }
    if ($contact->field_google_plus) {
      $contact_out['social']['google'] = $contact_wrapper->field_google_plus->url->value();
    }
    // comments
    $contact_out['comments'] = url('rest/basic/erpal_comment/' . $nid, array('absolute' => TRUE));
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'comment')
        ->propertyCondition('nid', $nid);
    $entities = $query->execute();
    if ($include_children && !empty($entities['comment'])) {
      $contact_out['comments'] = array();
      foreach (array_keys($entities['comment']) as $cid) {
        $comment = comment_load($cid);
        if ($comment) {
          $comment_body = $comment->comment_body[LANGUAGE_NONE][0];
          $comment_out = array(
            'created'           => (int) $comment->created,
            'changed'           => (int) $comment->changed,
            'cid'               => (int) $comment->cid,
            'subject'           => ($comment->subject) ? $comment->subject : '',
            'name'              => ($comment->name) ? $comment->name : '',
            'registered_name'   => ($comment->registered_name) ? $comment->registered_name : '',
            'comment_body'      => $comment_body['value'],
            'comment_format'    => $comment_body['format'],
            'author_url'        => url('rest/basic/erpal_user/' . $comment->uid, array('absolute' => TRUE)),
          );
          array_push($contact_out['comments'], $comment_out);
        }
      }
    }
  }

  return $contact_out;
}

/**
 * Creates an array as the response of a webservice request
 */
function _erpal_basic_service_create_service_response($errors, $contact_node) {
  
  if (!empty($errors)) {
    
    $returns['error'] = TRUE;
    $returns['node']  = false;
    
    foreach ($errors as $key => $value) {
      $error_string .= $key . ": " . $value . "<br/>";
    }
 
    watchdog('erpal_basic_service', 'Contact could not be created because of some errors:@errors', array(
      '@errors' => '<br />' . $error_string
    ));
    services_error($returns['message'], 400);
    return;
  }

  return (object)array(
    'url' => url(
      services_endpoint_load('erpal_basic_rest')->path . '/contact/' . $contact_node->nid,
      array('absolute'=>TRUE)
    )
  );
}

/**
 * Check access for contact node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_basic_service_contact_access($op, $args = NULL) {
  return node_access($op, 'erpal_contact');
}

/**
 * Check if the given addresses exist in the given node, if not return form string
 * all keys must be given
 * @param array $addresses array('address_name'->'','addition_to_address'->'','street'->'','zip'->'','city'->'','address_type','country'->'')
 * @param node object $contact_node
 */
function _erpal_basic_service_check_and_add_addresses($addresses, $contact_node) {
  //loop through given node and add all save addresses(serailized) in the needed format to an array
  $existing_addresses = array();
  $last_key = -1;
  if (!empty($contact_node->field_addresses[LANGUAGE_NONE])) {
    foreach ($contact_node->field_addresses[LANGUAGE_NONE] as $key => $address) {
      $test                                     = entity_load('field_collection_item', array($address['value']));
      $existing_address                         = array();
      $existing_address['address_name']         = (string) $test[$address['value']]->field_address_name[LANGUAGE_NONE][0]['value'];
      $existing_address['addition_to_address']  = (string) $test[$address['value']]->field_addition_to_address[LANGUAGE_NONE][0]['value'];
      $existing_address['street']               = (string) $test[$address['value']]->field_street[LANGUAGE_NONE][0]['value'];
      $existing_address['zip']                  = (string) $test[$address['value']]->field_zip_code[LANGUAGE_NONE][0]['value'];
      $existing_address['city']                 = (string) $test[$address['value']]->field_city[LANGUAGE_NONE][0]['value'];
      $existing_address['address_type']         = (string) taxonomy_term_load($test[$address['value']]->field_address_type_terms[LANGUAGE_NONE][0]['tid'])->name;
      $existing_address['country']              = (string) taxonomy_term_load($test[$address['value']]->field_country_term[LANGUAGE_NONE][0]['tid'])->field_country_code[LANGUAGE_NONE][0]['value'];
      $existing_addresses[]                     = serialize($existing_address);
      $last_key                                 = $key;
    }
  }
  $new_addresses = array();
  foreach ($addresses as $address) {
    //normalize the sent address, so its equal in structure to the serialized existing addresses
    $address_to_test                            = array();
    $address_to_test['address_name']            = (string) $address['address_name'];
    $address_to_test['addition_to_address']     = (string) isset($address['addition_to_address']) ? $address['addition_to_address'] : '';
    $address_to_test['street']                  = (string) $address['street'];
    $address_to_test['zip']                     = (string) $address['zip_code'];
    $address_to_test['city']                    = (string) $address['city'];
    $address_to_test['address_type']            = (string) $address['address_type'];
    $address_to_test['country']                 = (string) $address['country'];
    
    if (!in_array(serialize($address_to_test), $existing_addresses)) {
      $new_addresses[] = $address_to_test;
    }
  }

  $form_values = array();

  if (!empty($new_addresses)) {
    $counter = 1;
    
    foreach ($new_addresses as $address) {
      if (isset($address['address_name']))
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_address_name'] = array(LANGUAGE_NONE => array(0 => array('value' => $address['address_name'])));
      if (isset($address['addition_to_address']))
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_addition_to_address'] = array(LANGUAGE_NONE => array(0 => array('value' => $address['addition_to_address'])));
      if (isset($address['street']))
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_street'] = array(LANGUAGE_NONE => array(0 => array('value' => $address['street'])));
      if (isset($address['zip']))
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_zip_code'] = array(LANGUAGE_NONE => array(0 => array('value' => $address['zip'])));
      if (isset($address['city']))
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_city'] = array(LANGUAGE_NONE => array(0 => array('value' => $address['city'])));
      if (!empty($address['address_type'])) {
        $tid = _erpal_basic_service_check_and_create_term($address['address_type'], 'address_types');
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_address_type_terms'] = array(LANGUAGE_NONE => array('tid' => $tid));
      }
      if (!empty($address['country'])) {
        $tid = _erpal_basic_service_check_and_create_country($address['country']);
        $form_values[LANGUAGE_NONE][$last_key + $counter]['field_country_term'] = array(LANGUAGE_NONE => array('tid' => $tid));
      }

      $counter++;
    }
  }
  return $form_values;
}

/**
 * Get taxonomy term id, if term does not exist, create it.
 * @param type $term_name The name of a term
 * @param type $vocabulary_name the name of a vocabulary
 * @return type the tid of the term that was found and created
 */
function _erpal_basic_service_check_and_create_term($term_name, $vocabulary_name) {
  //check if there is a term for this country, if not, create it
  $term = taxonomy_get_term_by_name($term_name, $vocabulary_name);
  $term = reset($term);

  if ($term && !empty($term->tid)) {
    $tid = $term->tid;
  }
  else {
    //@TODO: make it configurable wether to create a new one or return an error
    $term = new stdClass();
    $term->name = $term_name;
    $vocab = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    $term->vid = $vocab->vid;
    taxonomy_term_save($term);
    $tid = $term->tid;
  }
  return $tid;
}

/**
 * Get taxonomy term id, if term does not exist, create it.
 * @param type $term_name The name of a term
 * @param type $vocabulary_name the name of a vocabulary
 * @return type the tid of the term that was found and created
 */
function _erpal_basic_service_check_and_create_country($country_code) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('countries');
  $tree = taxonomy_get_tree($vocabulary->vid);
  foreach ($tree as $term) {
    $full_term = taxonomy_term_load($term->tid);
    $country = field_get_items('taxonomy_term', $full_term, 'field_country_code');
    if ($country && $country[0]['value'] == $country_code) {
      return $full_term->tid;
    }
  }
//  if we didn't return, the term must not exist yet
  $term = new stdClass();
  $term->name = $country_code;
  $term->vid = $vocabulary->vid;
  $term->field_country_code[LANGUAGE_NONE][0]['value'] = $country_code;
  taxonomy_term_save($term);
  $tid = $term->tid;
  return $tid;
}

/**
 * returns a list of contacts the given contact 'works_at'. TODO there's got to be a better way.
 * 
 * @param node $contact the contact to extract the relations from
 * @param boolean $include_children flag indicating whether to fetch and include children with details or to return an endpoint url
 * @return array array of string with the endpoint url's of the companies the given contact works_at
 */
function _erpal_basic_service_get_works_at_relations($contact, $include_children = FALSE) {

  $works_at = array();

  $relations_query = new EntityFieldQuery();
  $relations = $relations_query->entityCondition('entity_type', 'relation')->propertyCondition('relation_type', 'works_at')->execute();

  if (!empty($relations)) {
    foreach (array_keys($relations['relation']) as $rid) {
      $relation = relation_load($rid);
      if ($relation && !empty($relation->endpoints) && !empty($relation->endpoints[LANGUAGE_NONE])) {
// assumption: 0=>employee 1=>employer
        $contact_0_nid = $relation->endpoints[LANGUAGE_NONE][0]['entity_id'];
        $contact_1_nid = $relation->endpoints[LANGUAGE_NONE][1]['entity_id'];
        if ($contact_0_nid === $contact->nid) {
          if ($include_children) {
            $works_at[] = _erpal_basic_service_contact_out($contact_1_nid, false, false);
          }
          else {
            $works_at[] = url('rest/basic/contact/' . $contact_1_nid, array('absolute' => TRUE));
          }
        }
      }
    }
  }

//    $works_at = array();
//
//  $relations = relation_query('node', $contact->nid)->propertyCondition('relation_type', 'works_at')->execute();
//  if (!empty($relations)) {
//    foreach (array_keys($relations) as $rid) {
//      $relation = relation_load($rid);
//      $contact_1_nid = $relation->endpoints[LANGUAGE_NONE][0]['entity_id'];
//      $contact_2_nid = $relation->endpoints[LANGUAGE_NONE][1]['entity_id'];
//      if ($include_children) {
//        $works_at[] = array(_erpal_basic_service_contact_out($contact_2_nid, false, false));
//      }
//      else {
//        $works_at[] = url('rest/basic/contact/' . $contact_2_nid, array('absolute' => TRUE));
//      }
//    }
//  }
//
//  return $works_at;


  return $works_at;
}

/**
 * returns a list of contacts the given contact 'works_at'. TODO there's got to be a better way.
 * 
 * @param node $contact the contact to extract the relations from
 * @param boolean $include_children flag indicating whether to fetch and include children with details or to return an endpoint url
 * @return array array of string with the endpoint url's of the companies the given contact works_at
 */
function _erpal_basic_service_get_employees_relations($contact, $include_children = FALSE) {

  $employees = array();

  $relations_query = new EntityFieldQuery();
  $relations = $relations_query->entityCondition('entity_type', 'relation')->propertyCondition('relation_type', 'works_at')->execute();

  if (!empty($relations)) {
    foreach (array_keys($relations['relation']) as $rid) {
      $relation = relation_load($rid);
      if ($relation && !empty($relation->endpoints) && !empty($relation->endpoints[LANGUAGE_NONE])) {
// assumption: 0=>employee 1=>employer
        $contact_0_nid = $relation->endpoints[LANGUAGE_NONE][0]['entity_id'];
        $contact_1_nid = $relation->endpoints[LANGUAGE_NONE][1]['entity_id'];
        if ($contact_1_nid === $contact->nid) {
          if ($include_children) {
            $employees[] = _erpal_basic_service_contact_out($contact_0_nid, false, false);
          }
          else {
            $employees[] = url('rest/basic/contact/' . $contact_0_nid, array('absolute' => TRUE));
          }
        }
      }
    }
  }

  return $employees;
}

