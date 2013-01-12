<?php

/**
 * Implements hook_token_info().
 */
function erpal_contract_helper_token_info() {
  $types['erpal_contract_billable_subject'] = array(
    'name' => t("Contract billable subject"),
    'description' => t("Tokens for subjects of contract billables."),
    'needs-data' => 'erpal_contract',
  );

  $subjects['contract_title'] = array(
    'name' => t("Contract project"),
    'description' => t("The title of the contract"),
  );
  $subjects['service_category'] = array(
    'name' => t("Service category of contract"),
    'description' => t("The service category assigned to the contract payments"),
  );
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_contract_billable_subject' => $subjects,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_contract_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  
  if ($type == 'erpal_contract_billable_subject') {
    $subject_node = isset($data['subject']) ? $data['subject'] : '';
    $service_category = isset($data['service_category']) ? $data['service_category'] : '';
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'contract_title':
          $title = $subject_node->title;
          $replacements[$original] = $title;
        break;
        case 'service_category':
          $replacements[$original] = $service_category;
        break;
        
      }
    }
  }

  return $replacements;
}

