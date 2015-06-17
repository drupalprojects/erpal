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
  
  $types['erpal_basic'] = array(
    'name' => t("Erpal basic tokens"),
    'description' => t("Basic ERPAL tokens"),
  );  
  
  $contact['name'] = array(
    'name' => t("Contact name"),
    'description' => t("The name of the contact"),
  );
  
  $contact['company_name'] = array(
    'name' => t("Company name"),
    'description' => t("The name of the company"),
  );
  
  $contact['firstname'] = array(
    'name' => t("First name"),
    'description' => t("The first name of the contact"),
  );
  
  $contact['lastname'] = array(
    'name' => t("Last name"),
    'description' => t("The last name of the contact"),
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
  
  $basic['date_only'] = array(
    'name' => t("Date only date"),
    'description' => t("The current date without time"),
  );
  
  $basic['date_time'] = array(
    'name' => t("Date time date"),
    'description' => t("The current date with current time"),
  );
    
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_contact' => $contact,
      'erpal_basic' => $basic,
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
    $contact_node = isset($data['contact_node']) ? $data['contact_node'] : $data['node'];    
    $address_entity = isset($data['address_entity']) ? $data['address_entity'] : false;

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'name':
          $replacements[$original] = isset($contact_node->title) ? $contact_node->title : '';
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
          $country = _erpal_basic_helper_field_country_term_as_string($address_entity);          
          $replacements[$original] = $country;
        break;
        case 'company_name':
          $company_name = '';
          if (isset($contact_node->field_company_name[LANGUAGE_NONE][0]['value']))
            $company_name = $contact_node->field_company_name[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $company_name;
        break;
        case 'firstname':
          $firstname = '';
          if (isset($contact_node->field_firstname[LANGUAGE_NONE][0]['value']))
            $firstname = $contact_node->field_firstname[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $firstname;
        break;
        case 'lastname':
          $lastname = '';
          if (isset($contact_node->field_lastname[LANGUAGE_NONE][0]['value']))
            $lastname = $contact_node->field_lastname[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $lastname;
        break;        
      }
    }
  }

  if ($type == 'erpal_basic') {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'date_only':          
          $date_format_date = _erpal_basic_helper_date_format_date_only();
          $date = date($date_format_date);
          $replacements[$original] = $date;        
        break;
        case 'date_time':          
          $date_format_date = _erpal_basic_helper_date_format_date_time();
          $date = date($date_format_date);
          $replacements[$original] = $date;        
        break;
      }
    }
  }
    //little hack to make tokens work on contact node title even if some fields are disabled because of conditional fields
    //otherwise the tokens will not be replaced...don't know why
    //$contact_node = $data['contact_node'] ? ;
    /*foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'field_company_name':
          $company_name = '';
          if (!isset($contact_node->field_company_name[LANGUAGE_NONE][0]['value']))
            $company_name = $contact_node->field_company_name[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $company_name;
        break;
        case 'field_firstname':
          $firstname = '';
          if (!isset($contact_node->field_firstname[LANGUAGE_NONE][0]['value']))
            $firstname = $contact_node->field_firstname[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $firstname;
        break;
        case 'field_lastname':
          $lastname = '';
          if (!isset($contact_node->field_lastname[LANGUAGE_NONE][0]['value']))
            $lastname = $contact_node->field_lastname[LANGUAGE_NONE][0]['value'];
          $replacements[$original] = $lastname;
        break;
      }
    }*/
  
  return $replacements;
}
