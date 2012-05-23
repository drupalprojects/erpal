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
    $contact_node = $data['contact_node'];    
    $address_entity = $data['address_entity'];

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

  if ($type == 'node') {
    //little hack to make tokens work on contact node title even if some fields are disabled because of conditional fields
    //otherwise the tokens will not be replaced...don't know why
    /*$contact_node = $data['node'];
    foreach ($tokens as $name => $original) {
      dpm($original);
      switch ($name) {
        case 'field_company_name':
          $company_name = '';
          if (!isset($contact_node->field_company_name[LANGUAGE_NONE][0]['value']))
            $replacements[$original] = $company_name;
        break;
        case 'field_firstname':
          $firstname = '';
          if (!isset($contact_node->field_firstname[LANGUAGE_NONE][0]['value']))
            $replacements[$original] = $company_name;
        break;
        case 'field_lastname':
          $lastname = '';
          if (!isset($contact_node->field_lastname[LANGUAGE_NONE][0]['value']))
            $replacements[$original] = $lastname;
        break;
      }
    }*/
  }
  
  return $replacements;
}
