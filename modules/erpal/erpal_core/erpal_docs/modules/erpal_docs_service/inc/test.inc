<?php

/**
* @file these are only developer test to check if the service works.
* these are NOT SIMPLE TEST CASES
*/

/**
* Implements hook_menu
*/
function erpal_docs_service_menu() {
  $items = array();
  
  //ONLY FOR DEBUGGING
  $items['erpal/docs/service/test'] = array(
    'page callback' => '_erpal_docs_service_test',    
    'access arguments' => array('non_existing permission'),
  );
  
  return $items;
}


//DEBUG DEBUG DEBUG
function _erpal_docs_service_test() {  
  
  $base_url_docs = 'http://local.erpal.brightsolutions.de/rest/erpal_files';

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
    'data' => $data,
  );

  //LOG IN FIRST
  $response = drupal_http_request($base_url_docs . '/user/login', $options);
  $data = json_decode($response->data);

  // Check if login was successful
  if ($response->code == 200) {
    // Now recycle the login cookie we recieved in the first request
    $options['headers']['Cookie'] = $data->session_name . '=' . $data->sessid;
  } else {
    //server error, at least no 200 response
    return false;
  }
  
  $file_nid = 6081;

  $options['data'] = '';
  $options['method'] = 'POST';
  $response = drupal_http_request($base_url_docs . '/erpal_file/download/'.$file_nid, $options);

  $data = json_decode($response->data);
  $path = $data->path;

  return $path;
}