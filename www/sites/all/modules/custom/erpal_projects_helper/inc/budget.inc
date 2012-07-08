<?php

/**
* @file functions to handle budgets on projects and tasks
*/

/**
* Implementes hook_field_attach_validate() 
*/
function erpal_projects_helper_field_attach_validate($entity_type, $entity, &$errors) {

  if ($entity_type == 'field_collection_item' && $entity->field_name == 'field_pricing') {
    $new_errors = _erpal_projects_helper_field_pricing_validate($entity);
    $errors = array_merge($errors, $new_errors);
  }
  
  if ($entity_type == 'profile2') {
    //validate that the referenced contact is not already referenced by another userd profile
    $contact_nid = 0;
    $new_errors = array();
    if (isset($entity->field_contact_ref[LANGUAGE_NONE][0]['target_id'])) {
      $contact_nid = $entity->field_contact_ref[LANGUAGE_NONE][0]['target_id'];
      $referencing_profiles = _erpal_profile_helper_profiles_by_contact($contact_nid);
      
      $current_uid = arg(2);  //@todo: this is not very good, there should be another way to get the uid the entity is attached to.
      if (count($referencing_profiles) > 1) {
        //this contact is referenced by another user, create an error
        foreach ($referencing_profiles as $profile_id) {          
              
          $profile = entity_load('profile2', array($profile_id));
          $profile = $profile[$profile_id];

          if ($profile->uid != $current_uid) {
            $a_user = user_load($profile->uid);
            $contact_node = node_load($contact_nid);
            $errors['field_contact_ref'][LANGUAGE_NONE][0][] = array(
              'error' => 'nid',
              'message' => t('The user !user_link is already linked to the contact !contact_link', array(
                '!user_link' => l($a_user->name, 'user/'.$a_user->uid),
                '!contact_link' => l($contact_node->title, 'node/'.$contact_node->nid)
              )),
            );
          }
          
        }
      }
    }
  }
}

/**
* Validates pricing field collection so that an entity can only be referenced once
* Validates that a budget entity can only be referenced once in on pricing field collection
* @param $entity the fieldcollection entity that will be saved.
* @return errors if some exists (e.g if a budget entity is already refernced by another entity)
*/
function _erpal_projects_helper_field_pricing_validate($entity) {
  
  $errors = array();
  if (isset($entity->field_budgets[LANGUAGE_NONE])) {
    $budget_ids = array();
    foreach ($entity->field_budgets[LANGUAGE_NONE] as $delta=>$target_id) {
      $target_id = $target_id['target_id'];
      if (trim($target_id)) {
        $pricing_fieldcollection_items = _erpal_projects_helper_pricing_entities_with_budget($target_id);
        
        //check if pricing entiy is already referenced at another project / task (pricing field collection entity)
        foreach ($pricing_fieldcollection_items as $collection_id) {
            
          if ($collection_id != $entity->item_id) {
            $budget = budget_load($target_id);
            $errors['field_budgets'][LANGUAGE_NONE][$delta][] = array(
            'error' => 'target_id',
            'message' => t('The budget !budget_title is already in use ad another project or task', array(
              '!budget_title' => $budget->defaultLabel(),
            )),
          );
          }
        }
        
        //validate duplicates in the budget field
        if (isset($budget_ids[$target_id]) && $delta <> $budget_ids[$target_id]) {
          //error this is already refernced
          $budget = budget_load($target_id);
         
          $errors['field_budgets'][LANGUAGE_NONE][$delta][] = array(
            'error' => 'target_id',
            'message' => t('The budget !budget_title can only be referenced once', array(
              '!budget_title' => $budget->defaultLabel(),
            )),
          );
        }      
        $budget_ids[$target_id] = $delta;
      }           
    }
  }
  
  return $errors;
}

/**
* Returns all pricing field collection entities where the given budget entity is refernced at
* @param $budget_id a budget entity ID
*/
function _erpal_projects_helper_pricing_entities_with_budget($budget_id) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'field_collection_item')
  ->entityCondition('bundle', 'field_pricing')
  ->fieldCondition('field_budgets', 'target_id', $budget_id, '=')
  ->addMetaData('account', user_load(1)); // run the query as user 1

  $result = $query->execute();

  $item_nids = array();
  if (isset($result['field_collection_item'])) {
    $item_nids = array_keys($result['field_collection_item']);
  }
  
  return $item_nids;
}

/**
* Function returns a total budget amount and all budget entities available
* @param $node the node where to find the budget entity
* @param $date unixtimestamp at which we want to determine the current budget. If false, we return all (no date filter)
* @return array: 'total_hours': Sum of all total hours of all relevant budgets
*                'available_hours': Sum of all available hours of all relevant budgets
*                'budgets': array of all budget entites used to calculate the values, ordered with the bigges budget first
*/
function _erpal_projects_helper_get_budget($node, $date) {

  if (!isset($node->field_pricing[LANGUAGE_NONE][0]['value'])) 
    return false; //no pricing available
  
  //get the pricing entity
  $pricing_id = $node->field_pricing[LANGUAGE_NONE][0]['value'];
  $pricing_entity = entity_load('field_collection_item', array($pricing_id));
  $pricing_entity = $pricing_entity[$pricing_id];    
  
  if (!isset($pricing_entity->field_budgets[LANGUAGE_NONE]))
    return false;
  
  $total_hours_sum = 0;
  $available_hours_sum = 0;
  $budgets = array();
  
  foreach ($pricing_entity->field_budgets[LANGUAGE_NONE] as $delta=>$target_id) {
    $budget_id = $target_id['target_id'];
    $budget = budget_load($budget_id);
   
    //if $date is given, ensure that the date is in range of each budget
    if ($date) {
      $budget_from = $budget->date_from ? $budget->date_from : 0;
      $budget_till = $budget->date_till ? $budget->date_till : PHP_INT_MAX;
      $in_date_range = ($budget_from <= $date) && ($date <= $budget_till);
      
      if (!$in_date_range)
        continue;  //this budget is not relevant because of wrong date range
    }
    $budgets[$budget->available_hours] = $budget;    
    $total_hours_sum += $budget->total_hours;
    $available_hours_sum += $budget->available_hours;
    
  }
  krsort($budgets);  //sort with the biggest budget at the top!
  $ret = array(
    'total_hours' => $total_hours_sum,
    'available_hours' => $available_hours_sum,
    'budgets' => $budgets,
  );
  
  return $ret;
}

/**
* Creates fields for use as preprocess fields in display suite to make calculated values available there.
*/
function _erpal_projects_billable_preprocess_for_budget(&$vars) {

  $node = $vars['node'];  
  
  if ($node->type == 'erpal_task' || $node->type == 'erpal_project') {
    //add field to show the total available budget and to add a link for adding budget.
    $budget_arr = _erpal_projects_helper_get_budget($node, time());  //get the budget that is NOW available
    
    if ($budget_arr)    
      $vars['budget_usage'] = theme('erpal_budget_usage', array('budget_arr' => $budget_arr));
  }
  
}

/**
* Book a timetracking node to budgets at a task, may be timetracking will be split if not budget of the needed sice is there
* @param $timetracking_node object a timetracking node that is booked
* @param $billable_information billable information, not neccessaryly from the direct subject of the timetracking node
*   but may be from prarent task or project nodes
* @param $allow_negative if true, if there is no more budget available, we reduce the available hours to a negative value
* @return returns a timetracking node if the whole timetracking node could not be booked because there is not enough budget, if the total duration of the timetracking node could be booked to the available budget, return false
*/
function _erpal_projects_billable_book_timetracking_to_budget($timetracking_node, $billable_information, $allow_negative=false) {
  //get the relevant subject node, we got the billable information from
  $pricing_nid = $billable_information['pricing_nid'];
  $pricing_node = node_load($pricing_nid);
  
  $booking_date = time();
  if (isset($timetracking_node->field_date[LANGUAGE_NONE][0]['value']))
    $booking_date = strtotime($timetracking_node->field_date[LANGUAGE_NONE][0]['value']); //the date when the timetracking node is booked
  
  $budgets_arr = _erpal_projects_helper_get_budget($pricing_node, $booking_date);
  $budgets = $budgets_arr['budgets'];

  //now we have budgets ordered with the biggest budget at the top.
  $billing_duration = $timetracking_node->field_billing_duration[LANGUAGE_NONE][0]['value'];
  
  if (!$billing_duration) {
    $timetracking_node = false;
    continue;
  }

  foreach ($budgets as $delta=>$budget_entity) {
    //load the budget entity again because we could have made changes above if there was a budget entity referenced before
    $budget_entity_arr = entity_load('budget', array($budget_entity->budget_id)); 
    $budget_entity = $budget_entity_arr[$budget_entity->budget_id];

    if ($budget_entity->available_hours <= 0 && !$allow_negative)
      return $timetracking_node; //no budget available

    //if the timetracking doesnt completely fit into the one budget, reduce the blling duration of the current 
    //timetracking node and create a new one with the rest of the billing duration 
    $rest_hours = 0;
    if (($budget_entity->available_hours < $billing_duration) && !$allow_negative) {
      //we cannot book the timetracking to this single budget. So we split it and try to book it to multiple budgets       
      $rest_hours = $billing_duration - $budget_entity->available_hours;
      $billing_duration = $budget_entity->available_hours;        
    }      
    
    //book the complete timetracking node to this budget
    //reduce the budget entity
    $budget_entity->add_hours(-1 * $billing_duration, $allow_negative);
    $budget_entity->save();
    
    _erpal_projects_helper_check_budget_usage($pricing_node, $booking_date, true);

    //save the budget entity reference field of the timetracking node to the chosen budget entity, so we dont neet to
    //save the whole timetracking node again
    //Get the id of your field
    $field_name = 'field_budget';
    $info = field_info_field($field_name);
    $fields = array($info['id']); 

    //Execute the storage function
    $timetracking_node->field_budget[LANGUAGE_NONE][0]['target_id'] = $budget_entity->budget_id;
    field_sql_storage_field_storage_write('node', $timetracking_node, 'update', $fields);
    
    //if billing duration changed, update it at the initial timetracking node! But update only the field itself to avoid 
    //recursion of timetracking node save
    if ($timetracking_node->field_billing_duration[LANGUAGE_NONE][0]['value'] != $billing_duration) {
      $field_name = 'field_billing_duration';
      $info = field_info_field($field_name);
      $fields = array($info['id']); 

      //Execute the storage function
      $timetracking_node->field_billing_duration[LANGUAGE_NONE][0]['value'] = $billing_duration;
      field_sql_storage_field_storage_write('node', $timetracking_node, 'update', $fields);
    }
    
    
    //if we have a rest duration, create a new timetracking and loop again
    if ($rest_hours) {
      $timetracking_node_new = new stdClass();  
      $timetracking_node_new->status = 1; //published
      $timetracking_node_new->language = $timetracking_node->language;
      $timetracking_node_new->type = $timetracking_node->type;
      $timetracking_node_new->title = $timetracking_node->title;
      $timetracking_node_new->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'] = $timetracking_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
      $timetracking_node_new->field_date_time[LANGUAGE_NONE][0]['value'] = $timetracking_node->field_date_time[LANGUAGE_NONE][0]['value'];  //no time till because this is not neccessary in the splitted timetracking node
      $timetracking_node_new->field_billing_duration[LANGUAGE_NONE][0]['value'] = $rest_hours;
      $timetracking_node_new->field_duration[LANGUAGE_NONE][0]['value'] = 0;  //for statistic reasons we have the total
      //duration at the timtracking node inserted by the user, so here we have no further duration. Only billing_duration 
      //will be dplit because it is used to calculate budgets and billables
      node_object_prepare($timetracking_node_new);
      node_save($timetracking_node_new);  //start recursion to save this timetracking node to budget...
      return false;
      
    } else
      return false;
  }

  
  return $timetracking_node; 
  
}

/**
* Saves the booked budget from the timetracking to the referenced budget entity again
*/
function _erpal_projects_helper_restore_timetracking_budget($timetracking_node) {
  //if timetracking node already has a budget entity referenced, add the budget again to the budget_entity available_hours.
  //Otherwise we substract the duration multiple times
  if (isset($timetracking_node->field_budget[LANGUAGE_NONE][0]['target_id'])) {
    $budget_entity_id = $timetracking_node->field_budget[LANGUAGE_NONE][0]['target_id'];
    $referenced_budget = entity_load('budget', array($budget_entity_id));
    $referenced_budget = $referenced_budget[$budget_entity_id];    
    $billing_duration = $timetracking_node->field_billing_duration[LANGUAGE_NONE][0]['value'];
    $referenced_budget->add_hours($billing_duration);
    $referenced_budget->save();
  }  
}

/**
* Warn if the budget has reached its usage limit
* @param $node the node where the budgets are attached at
* @param $booking_date the date at which we check the usage
* @param $trigger_warnings if true warnings and triggers are called to warn the user
*/
function _erpal_projects_helper_check_budget_usage($node, $booking_date, $trigger_warnings=false) {
  $budgets_arr = _erpal_projects_helper_get_budget($node, $booking_date);
  
  $total_hours = $budgets_arr['total_hours'];
  $available_hours = $budgets_arr['available_hours'];
  
  $usage_percent = abs((($total_hours - $available_hours) / $total_hours) * 100);

  $usage_limit = _erpal_projects_helper_budget_usage_warn();

  $budget_usage = $available_hours.' / '.$total_hours;
  $node_link = l($node->title, 'node/'.$node->nid);

  //close to limit
  if ($usage_percent >= $usage_limit && $usage_percent < 100) {
    drupal_set_message(t('Budget of !node_link is closed to limit with !budget_usage', 
      array(
        '!node_link' => $node_link,
        '!budget_usage' => $budget_usage,
      )
    ), 'warning');
    
    //call rules event
    if (module_exists('rules')) {
      rules_invoke_event('budget_warning', $node, $available_hours, $total_hours);
    }
  }
  
  //reached limit
  if ($usage_percent >= 100) {
    drupal_set_message(t('Budget of !node_link is completely used with !budget_usage', 
      array(
        '!node_link' => $node_link,
        '!budget_usage' => $budget_usage,
      )
    ), 'error');
    
    //call rules event
    if (module_exists('rules')) {
      rules_invoke_event('budget_empty', $node, $available_hours, $total_hours);
    }
  }
  
}