<?php

/**
* @files provides tokens for contact node
*/


/**
 * Implements hook_token_info().
 */
function erpal_basic_helper_token_info() {
  $types['erpal_contact'] = array(
    'name' => t("Erpal contact tokens"),
    'description' => t("Tokens for contact nodes."),
  );
  
  $contact['name'] = array(
    'name' => t("Contact name"),
    'description' => t("The name of the contact"),
  );
  
  $contact['street'] = array(
    'name' => t("Contact street"),
    'description' => t("The street of the selected address"),
  );
  
  $contact['zip_code'] = array(
    'name' => t("Contact ZIP code"),
    'description' => t("The ZIP code selected address"),
  );
  
  $contact['city'] = array(
    'name' => t("Contact city"),
    'description' => t("The city of the selected address"),
  );
  
  $contact['country'] = array(
    'name' => t("Contact country"),
    'description' => t("The country of the selected address"),
  );
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_contact' => $contact,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_basic_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  if ($type == 'erpal_contact') {
    $book_node = $data['erpal_book'];
    
    //get the contact and the selected address of the contact
    if (!isset($book_node->field_contact_ref[LANGUAGE_NONE][0]['nid']))
      return $replacements;
      
    $contact_nid = $book_node->field_contact_ref[LANGUAGE_NONE][0]['nid'];
    $contact_node = node_load($contact_nid);
    
    $address_id = false;
    $address_entity = false;
    if (isset($book_node->field_address_id[LANGUAGE_NONE][0]['value'])) {
      $address_id = $book_node->field_address_id[LANGUAGE_NONE][0]['value'];
      $address_entity = entity_load('field_collection_item', array($address_id));
      $address_entity = $address_entity[$address_id];
    }

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'name':
          $replacements[$original] = $contact_node->title;
        break;
        case 'street':
          $street = '';
          if (isset($address_entity->field_street[LANGUAGE_NONE][0]['value']))
            $street = $address_entity->field_street[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $street;
        break;
        case 'zip_code':
          $zip_code = '';
          if (isset($address_entity->field_zip_code[LANGUAGE_NONE][0]['value']))
            $zip_code = $address_entity->field_zip_code[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $zip_code;
        break;
        case 'city':
          $city = '';
          if (isset($address_entity->field_city[LANGUAGE_NONE][0]['value']))
            $city = $address_entity->field_city[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $city;
        break;
        case 'country':
          $country = '';
          if (isset($address_entity->field_country[LANGUAGE_NONE][0]['value']))
            $country = $address_entity->field_country[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $country;
        break;
        
      }
    }
  }

  
  return $replacements;
}
