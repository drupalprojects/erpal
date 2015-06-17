<?php

/**
* @file these are only developer test to check if the service works.
* these are NOT SIMPLE TEST CASES
*/

/**
* Implements hook_menu
*/
function erpal_invoice_service_menu() {
  $items = array();
  
  //ONLY FOR DEBUGGING
  $items['erpal/invoice/service/test'] = array(
    'page callback' => '_erpal_invoice_service_test',    
    'access arguments' => array('non_existing permission'),
  );
  
  return $items;
}


//DEBUG DEBUG DEBUG
function _erpal_invoice_service_test() {  
  
  $base_url_invoice = 'http://local.erpal.brightsolutions.de/rest/invoice';
  //$base_url_contact = 'http://local.erpal.brightsolutions.de/rest/basic';
  $data = array(
    'username' => 'admin',
    'password' => 'admin',
  );
  $data = drupal_json_encode($data);

  $headers = array();
  $options = array(
    'headers' => array(
      'Accept' => 'application/json',
      'Content-Type' => 'application/json',  
    ),
    'method' => 'POST',
    'data' => $data
  );

  //LOG IN FIRST
  $response = drupal_http_request($base_url_invoice . '/user/login', $options);
  $data = json_decode($response->data);

  // Check if login was successful
  if ($response->code == 200) {
    // Now recycle the login cookie we recieved in the first request
    $options['headers']['Cookie'] = $data->session_name . '=' . $data->sessid;
  } else {
    //server error, at least no 200 response
    _erpal_invoice_service_webservice_log($response->status_message);
    return;
  }

  //create a contact first
  $firstname = 'Manueldddd';
  $lastname = 'Pistner1sdsd';
  $email = 'pistner@brightsolutions.desss';
  $data = array(
    'contact' => array(
      'firstname' => $firstname,
      'lastname' => $lastname,
      //'nid' => 5650,
      'email' => $email,
      'criteria' => array(          
        'field_firstname' => array('field' => 'value', 'value' => $firstname),
        'field_lastname' => array('field' => 'value', 'value' => $lastname),
       ), //these are the fields used to check if a contact already exists
       'addresses' => array(
         array(
           'address_name' => 'Office Addresse',
           'addition_to_address' => 'hintere tür',
           'street' => 'Hanauer Landstr. 222',
           'zip' => '64233',
           'city' => 'Hanau',             
         ),
       )
    ),
  );
  
  $options['data'] = drupal_json_encode($data);
  $options['method'] = 'POST';
  $response = drupal_http_request($base_url_invoice . '/contact', $options);

  $data = json_decode($response->data);

  $status_message = $response->status_message;
  $contact_node = $data->node;

  if (isset($response->error) && $response->error) {
    _erpal_invoice_service_webservice_log($response->error);
    return;
  }
  
  
  
  //TEST CREATING AN INVOICE
  $invoice['invoice'] = array(
    //'company' => 'Bright Solutions GmbH und so KG', 
    'contractor_nid' => "1",
    'customer_nid' => $contact_node->nid,
    'invoice_address_id' => 2636, //false to force auto create or thake the default address for customer that already exists
    'invoice_number' => false, //force auto create but mmay be preset here
    'invoice_date' => time(), //invoice date as unix timestamp    
    'paid' => true, //already paid
    'billables' => array(  //array of billable arrays
      array(
        'date_delivery' => time(), //unix timestamp when the product was delivered
        'subject' => 'meine Produktbeschreibung 1',  //product description
        'quantity' => 1, //how many of this product
        'single_price' => 30,
        'tax_type' => 'vat', //"vat" or "sales" @TODO implement in invoice module
        'tax_rate' => '19.000',   
        'service_category' => 131, 
      ),
      array(
        'date_delivery' => time(), //unix timestamp when the product was delivered
        'subject' => 'meine Produktbeschreibung 2',  //product description
        'quantity' => 3, //how many of this product
        'single_price' => 29.95,
        'tax_type' => 'vat', //"vat" or "sales" @TODO implement in invoice module
        'tax_rate' => 7,   
        'service_category' => 131, 
      ),
    ),
    'skonto_period' => 14,
    'skonto_percent' => 3,
    'currency' => 'EUR', //leave empty to use default
    'additional_notes' => 'Danke, das habt Ihr schön eingekauft!',
  );
  
  module_load_include('inc', 'erpal_invoice_service', 'inc/invoice');
  
  $data = drupal_json_encode($invoice);

  //now create the invoice 
  $options['data'] = $data;
  $options['method'] = 'POST';
  $response = drupal_http_request($base_url_invoice . '/invoice', $options);
  die(print_r($response));
  $data = json_decode($response->data);

  if (isset($response->error) && $response->error) {
    _erpal_invoice_service_webservice_log($response->error);
  }
  
  //now get the file!
  $node = $data->node;

  $file_nid = isset($node->field_asset_files->{LANGUAGE_NONE}[0]->target_id) ? $node->field_asset_files->{LANGUAGE_NONE}[0]->target_id : false;
  
  //now get the file URL with REST Service

  $options['data'] = '';
  $options['method'] = 'POST';
  $response = drupal_http_request($base_url_invoice . '/erpal_file/download/'.$file_nid, $options);
  $data = json_decode($response->data);

  $path = $data->path;  //this is the path to the invoice!
  
  
  return $path;
}

/**
* Logs Errors that happened while webservice calls FOR DEBUG DEBUG DEBUG!
*/
function _erpal_invoice_service_webservice_log($message) {
  watchdog('webform to erpal', $message);
}