<?php

/**
* This file provides token integration for erpal_book_helper module
*/

/**
 * Implements hook_token_info().
 */
function erpal_book_helper_token_info() {
  $types['erpal_book_export'] = array(
    'name' => t("Erpal book export tokens"),
    'description' => t("Tokens for book export."),
    'needs-data' => 'node',
  );
  
  $pdf['total_estimation'] = array(
    'name' => t("Total estimation for the book"),
    'description' => t("The total estimated time by pages or tasks, will be replaced only in book export"),
  );
  
  $pdf['book_ident'] = array(
    'name' => t("Book identification number"),
    'description' => t("Unique nid/vid to identify the book"),
  );

  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_book_export' => $pdf,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_book_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  if ($type == 'erpal_book_export') {
    if (isset($data['total_estimation'])) {
      $total_estimation = $data['total_estimation'] ?  $data['total_estimation'] : 0;      
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'total_estimation':
            $replacements[$original] = $total_estimation;
          break;          
        }
      }
    }
    
    if (isset($data['book_node'])) {
      $book_ident = _erpal_book_helper_get_book_ident($data['book_node']);
      foreach ($tokens as $name => $original) {
        switch ($name) {          
          case 'book_ident':
            $replacements[$original] = $book_ident;
        }
      }
    }
  }
  
  
  return $replacements;
}