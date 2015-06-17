<?php

/**
 * Implements hook_token_info().
 */
function erpal_employee_helper_token_info() {
  $types['working_time_tokens'] = array(
    'name' => t("Erpal working time tokens"),
    'description' => t("Tokens for special fields on working time nodes"),
    //'needs-data' => 'erpal_working_time',
  );

  $working_time_tokens['date_time_from'] = array(
    'name' => t("Date time from value formatted"),
    'description' => t("The date time from value formatted"),
  );
  $working_time_tokens['date_time_till'] = array(
    'name' => t("Date time till value formatted"),
    'description' => t("The date time till value formatted"),
  );
  $working_time_tokens['date_from'] = array(
    'name' => t("Date from value formatted"),
    'description' => t("The date from value formatted"),
  );
  $working_time_tokens['date_till'] = array(
    'name' => t("Date till value formatted"),
    'description' => t("The date till value formatted"),
  );
  
  return array(
    'types' => $types,
    'tokens' => array(
      'working_time_tokens' => $working_time_tokens,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_employee_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  
  if ($type == 'working_time_tokens') {
    $content_entity = isset($data['node']) ? $data['node'] : '';        
    foreach ($tokens as $name => $original) {
      $value_field = false;
      switch ($name) {
        case 'date_time_from':          
          $with_time = true;
          $value_field = 'value';
        break;
        case 'date_time_till':
          $with_time = true;
          $value_field = 'value2';
        break;
        case 'date_from':          
          $with_time = false;
          $value_field = 'value';
        break;
        case 'date_till':
          $with_time = false;
          $value_field = 'value2';
        break;
        
      }
      
      if ($value_field) {
        $unix_time = isset($content_entity->field_date_time[LANGUAGE_NONE][0][$value_field]) ? $content_entity->field_date_time[LANGUAGE_NONE][0][$value_field] : 0;
        $format = erpal_lib_get_date_format($with_time);
        $date_str = date($format, $unix_time);
        $replacements[$original] = $date_str;
      }
    }
  }

  return $replacements;
}
