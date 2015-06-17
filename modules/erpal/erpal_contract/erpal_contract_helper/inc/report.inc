<?php

/**
* @file some statistic for contracts
*/

/**
* return the volume of active contracts splitted by customer, by passed duration and by service category as well as by total duration
*/
function _erpal_contract_helper_get_contract_reports() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_contract')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
    
  //$query->fieldCondition('field_date', 'value2', 'NULL'); //only contracts that are not canceled will be added positive
  //@TODO: this is not working as we cannot compare two field values and the date value2 is equale to value and not NULL 
  
  $result = $query->execute();
  $contract_data_arr = array('total' => 0);
  if (isset($result['node'])) {
    $contract_nids = array_keys($result['node']);
    foreach ($contract_nids as $contract_nid) {
      $contract_node = node_load($contract_nid);
      //if the ontract is already canceled we don't respect it. 
      $start_date = !empty($contract_node->field_date[LANGUAGE_NONE][0]['value']) ? $contract_node->field_date[LANGUAGE_NONE][0]['value'] : false;
      $end_date = !empty($contract_node->field_date[LANGUAGE_NONE][0]['value2']) ? $contract_node->field_date[LANGUAGE_NONE][0]['value2'] : false;
      
      $is_canceled = $end_date && $start_date != $end_date;
      if ($is_canceled) {
        continue;
      }
     
     
      //get the monthly volume and the duration as well as the service category and make the calculations
      //load some contract field collections
      $contract_data_id = $contract_node->field_contract_payment[LANGUAGE_NONE][0]['value'];
      $contract_data = entity_load('field_collection_item', array($contract_data_id));
      $contract_data = $contract_data[$contract_data_id];
      $customer_nid = $contract_data->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
      $service_category_id = !empty($contract_data->field_service_category_term[LANGUAGE_NONE][0]['tid']) ? $contract_data->field_service_category_term[LANGUAGE_NONE][0]['tid'] : 0;
      $volume = $contract_data->field_price[LANGUAGE_NONE][0]['value'];

      $duration_month = $contract_node->field_contract_duration[LANGUAGE_NONE][0]['value'];
      $volume_over_time = $volume * $duration_month;
      if (empty($contract_data_arr['customers'][$customer_nid]['total']))
        $contract_data_arr['customers'][$customer_nid]['total'] = $volume_over_time;
      else
        $contract_data_arr['customers'][$customer_nid]['total'] += $volume_over_time;
      
      
      if (empty($contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['duration'])) {
        $contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['duration'] = $duration_month;
      } else {
        $contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['duration'] += $duration_month;
      }
      
      if (empty($contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['volume'])) {
        $contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['volume'] = $volume_over_time;
      } else {
        $contract_data_arr['customers'][$customer_nid]['details'][$service_category_id]['volume'] += $volume_over_time;
      }

      $contract_data_arr['total'] += $volume_over_time;
      
    }
  }

  return $contract_data_arr;
}