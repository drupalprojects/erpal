<?php

/**
* @file functions to handle budgets on projects and tasks
*/

/**
* Validates pricing field collection so that an entity can only be referenced once
* Validates that a budget entity can only be referenced once in on pricing field collection
* @param $entity the fieldcollection entity that will be saved.
* @return errors if some exists (e.g if a budget entity is already refernced by another entity)
*/
function _erpal_projects_helper_field_pricing_validate($entity) {
  
  $errors = array();
  //put all the old budget entity ids in an array
  $old_budget_ids = array();
  if ($entity->item_id && isset($entity->field_budgets[LANGUAGE_NONE])) {
    
    $budget_ids = array();

    //load the former entity
    $ids = array($entity->item_id);    
    $old_entity = entity_load('field_collection_item', $ids, array(), TRUE);
    $old_entity = $old_entity[$entity->item_id];
    $old_budgets = isset($old_entity->field_budgets[LANGUAGE_NONE]) ? $old_entity->field_budgets[LANGUAGE_NONE] : array();    
    
    foreach ($old_budgets as $old_delta=>$old_budget_id) {
      $old_budget_id = $old_budget_id['target_id'];
      $old_budget_ids[$old_budget_id] = $old_delta;
    }
    $old_budget_ids_backup = $old_budget_ids;
 
    foreach ($entity->field_budgets[LANGUAGE_NONE] as $delta=>$target_id) {
      $target_id = $target_id['target_id'];
      if (trim($target_id)) {
        
        $pricing_fieldcollection_items = _erpal_projects_helper_pricing_entities_with_budget($target_id);
        
        unset($old_budget_ids[$target_id]); // unset the budgets that we actuallay have, so we have all deleted budgets in an array that we can check later.               
     
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
  
  //if pricemode is "budget per hour" and field_budget_time_billing "billable" there must be a price set in price field
  $price_mode = $entity->field_price_mode[LANGUAGE_NONE][0]['value'];
  $budget_time_billing = !empty($entity->field_budget_time_billing[LANGUAGE_NONE][0]['value']) ? $entity->field_budget_time_billing[LANGUAGE_NONE][0]['value'] : false;
  if ($price_mode == 'budget' && $budget_time_billing == 'billable') {
    $price = $entity->field_price[LANGUAGE_NONE][0]['value'];

    if (!$price) {
      $errors['field_price'][LANGUAGE_NONE][0][] = array(
        'error' => 'value',
        'message' => t('If you want each timetracking to be billable, please enter a price.'),
      );
    }
  }

  if (isset($old_budget_ids) && is_array($old_budget_ids)) {
    //check if budgets that actually have been delete, have timetrackings referencing the budget. They are not allowed to remove
    //from the pricing fieldcollection!
    foreach ($old_budget_ids as $budget_id=>$delta) {
      //does budget have timetrackings?
      $timetracking_nids = _erpal_projects_helper_get_timetrackings_by_budget($budget_id);

      if (count($timetracking_nids) > 0) {
        //sorry, but the user cannot remove this budget from the node
        $errors['field_budgets'][LANGUAGE_NONE][$delta][] = array(
          'error' => 'target_id',
          'message' => t('Budgets that already have timetrackings cannot be deleted.'),
        );
      }
    }
  }
  
  return $errors;
}

/**
* Function checks, if timetrackings must be reorganised because a budget has been added to a task or a project
* @param $entity the pricing field collection entity
*/
function _erpal_projects_helper_field_pricing_presave($entity) {
  if ($entity->item_id && isset($entity->field_budgets[LANGUAGE_NONE])) {    
    $budget_ids = array();
  
    //price mode must be budget per hour
    if ($entity->field_price_mode[LANGUAGE_NONE][0]['value'] != 'budget')
      return;  //only, if price mode is budget per hour
      
    //load the former entity
    $ids = array($entity->item_id);    
    $old_entity = entity_load('field_collection_item', $ids, array(), TRUE);
    $old_entity = $old_entity[$entity->item_id];
    $old_budgets = isset($old_entity->field_budgets[LANGUAGE_NONE]) ? $old_entity->field_budgets[LANGUAGE_NONE] : array();
    
    //put all the old budget entity ids in an array
    $old_budget_ids = array();    
    foreach ($old_budgets as $old_delta=>$old_budget_id) {
      $old_budget_id = $old_budget_id['target_id'];
      $old_budget_ids[$old_budget_id] = $old_delta;
    }
 
    //check if there has been a new budget added, compared to the old version
    $new_budget_ids = array();
    foreach ($entity->field_budgets[LANGUAGE_NONE] as $delta=>$target_id) {
      $target_id = $target_id['target_id'];
      if (!isset($old_budget_ids[$target_id]))
        $new_budget_ids[] = $target_id;
    }
    
    if (count($new_budget_ids) > 0) {     
      $budget_host_node = $entity->hostEntity();
      _erpal_projects_helper_reorganize_timetrackings_to_budgets_queue($budget_host_node, $new_budget_ids);
    }
  }
}

/**
* Checks if there are timetrackings at the given host node or its children that match the validity period of the given budgets. For more information @see function _erpal_projects_helper_reorganize_timtrackings_by_single_budget
* @param $host_node the node where the budget was added to
*/
function _erpal_projects_helper_reorganize_timetrackings_to_budgets_queue($host_node, $new_budget_ids) {
  //get all timetrackings and add them to the queue
  $types = array('erpal_task');
  
  if (!isset($host_node->nid))
    return;
  
  $sub_tasks = _erpal_basic_helper_get_all_child_nids_deep_search($host_node->nid, $types);
  
  $child_nids = array($host_node->nid);
  foreach ($sub_tasks as $task_arr) {
    $child_nids[] = $task_arr['child'];
  }
  
  //find out minimum date from and maximum date till off all budgets
  $min_budget_date_from = PHP_INT_MAX;
  $max_budget_date_till = 0;
  foreach ($new_budget_ids as $budget_id) {
    $budget = budget_load($budget_id);
    if ($budget->date_from) {
      if ($budget->date_from < $min_budget_date_from)
        $min_budget_date_from = $budget->date_from;
    } else {
      $min_budget_date_from = 0;
    }
    
    if ($budget->date_till) {
      if ($budget->date_till > $max_budget_date_till)
        $max_budget_date_till = $budget->date_till;
    } else {
      $max_budget_date_till = PHP_INT_MAX;
    }
  }

  //set the max time to last minute of the day so every hour is in it!
  $max_budget_date_till = date('Y-m-d 23:59:59', $max_budget_date_till);
  $max_budget_date_till = strtotime($max_budget_date_till);
  
  //now get all timetracking nodes assigned to these children tasks and to the host node itself  
  $timetracking_nids = _erpal_projects_helper_get_direct_timetrackings_by_date_range($child_nids, $min_budget_date_from, $max_budget_date_till);
  
  //now add these timetrackings to queue for processing later
  $queue = DrupalQueue::get('reorganize_timetrackings');
  //get all queue Items in an array
  
  $queue_items = array();
  while($item = $queue->claimItem(0)) {
    $queue_items[$item->data] = $item;
    
    //delete it and add it again so it is free again for next iteration
    $queue->deleteItem($item);    
  }
  
  //add items to queue again
  foreach ($queue_items as $item) {
    $queue->createItem($item->data);
  }
  
  foreach($timetracking_nids as $nid) {
    
    //add item only if it is not already in the queue
    $nid_in_queue = false;
    $nid_in_queue = isset($queue_items[$nid]);
    
    if (!$nid_in_queue) {
      $queue->createItem($nid);
    }
  }
}

/**
* Warns on page invoice/billables if there are timetrackings in the queue and so some billables may not be correct or missing
*/
function _erpal_projects_helper_warn_items_in_queue_billing() {
  if (arg(0) == 'invoice' && arg(1) == 'billables') {
    $queue = DrupalQueue::get('reorganize_timetrackings');
    $item_count = $queue->numberOfItems();
    if ($item_count)
      drupal_set_message(t('CAUTION! There are !item_count timetrackings in process. Please start cron, to process them und to have all billable items calculated', array('!item_count' => $item_count)), 'warning');
  }
}


/**
* Function that is called if the reorganize_timetrackings queue definied in erpal_projects_helper_cron_queue_info is processed
* @param $nid a nid of a timetracking node that needs to be reorganized
*/
function _erpal_projects_helper_reorganize_timetrackings_queue_run($nid) {  
  //ensure this process is executed as user 1. Otherwise there may be problems executing the timetrackings refactoring because user that executes the queue has noch permissions to view some referenced nodes....
  //the queue api forces anonymous user...but we need the admin to refactore datasets.
  // Prevent session information from being saved while cron is running.
  global $user;
  $original_user = $user;
  $old_state = drupal_save_session();
  drupal_save_session(FALSE);
  $user = user_load(1);
  
  _erpal_projects_helper_process_queue_item_timetracking($nid);  
  
  $user = $original_user;
  drupal_save_session($old_state);
  drupal_save_session(TRUE);
}

/**
* Function to process single queue item to refactore timetrackings and budgets
*/
function _erpal_projects_helper_process_queue_item_timetracking($nid) {
  //delete billables if not billed and save the timetracking again  
  //we dont call this if projects billable module is not enabled
  if (!module_exists('erpal_projects_billable')) 
    return;
  
  $node = node_load($nid, NULL, true); //IMPORTANT to clear node cache, otherwise the subject will be missing!

  if ($node->type != 'erpal_timetracking')
    return;
    
  //now delete the billables of this timetracking node
  $billables = _billable_get_billables_by_subject(array($nid));
  foreach ($billables as $billable_id) {
    $billable = billable_load($billable_id);
    
    //delelte only if not already billed
    if (!$billable->billed)    
      billable_delete($billable);
  }
  
  //now resave the timetracking node
  node_save($node);  
}

/**
* Adds a given budget entity to a project / task node with $destination_nid
*/
function _erpal_projects_helper_add_buget(budget $budget, $destination_nid) {
  $destination_node = node_load($destination_nid);
  $field_pricing_id = $destination_node->field_pricing[LANGUAGE_NONE][0]['value'];
  $pricing_entity = entity_load('field_collection_item', array($field_pricing_id));
  $pricing_entity = $pricing_entity[$field_pricing_id];
  $pricing_entity->field_budgets[LANGUAGE_NONE][] = array('target_id' => $budget->budget_id);
  $pricing_entity->save(true); //save without saving the host entity
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
* Returns the node (id can always only be one!) that references the given budget
*/
function _erpal_projects_helper_get_nodes_referencing_budget($budget_id) {
  
  $pricing_field_collection = _erpal_projects_helper_pricing_entities_with_budget($budget_id);
  if (!isset($pricing_field_collection[0]))
    return false;
    
  $pricing_field_collection_id = $pricing_field_collection[0];
  $pricing_field_collection = entity_load('field_collection_item', array($pricing_field_collection_id));
  $pricing_field_collection = $pricing_field_collection[$pricing_field_collection_id];
  
  //get the host node of the budget
  $budget_host_node = $pricing_field_collection->hostEntity();
  
  return $budget_host_node;
}

/**
* Function returns a total budget amount and all budget entities available
* @param $node the node where to find the budget entity
* @param $date unixtimestamp at which we want to determine the current budget. If false, we return all (no date filter)
* @return array: 'total_hours': Sum of all total hours of all relevant budgets
*                'available_hours': Sum of all available hours of all relevant budgets
*                'budgets': array of all budget entites used to calculate the values
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
   
    if (!$budget)
      continue;
   
    //if $date is given, ensure that the date is in range of each budget
    if ($date) {
      $budget_from = $budget->date_from ? $budget->date_from : 0;
      $budget_till = $budget->date_till ? $budget->date_till : PHP_INT_MAX;
      $in_date_range = ($budget_from <= $date) && ($date <= $budget_till);
      
      if (!$in_date_range)
        continue;  //this budget is not relevant because of wrong date range
    }
    $budgets[] = $budget;    
    $total_hours_sum += $budget->total_hours;
    $available_hours_sum += $budget->available_hours;
    
  }
  
  //get the users to notify and the budget limit
  $notify_users = !empty($pricing_entity->field_users[LANGUAGE_NONE]) ? $pricing_entity->field_users[LANGUAGE_NONE] : array();
  $notify_users_flat = array();
  foreach ($notify_users as $uid_arr) {
    $notify_users_flat[] = $uid_arr['target_id'];
  }
  $low_treshold = !empty($pricing_entity->field_budget_low_limit[LANGUAGE_NONE][0]) ? $pricing_entity->field_budget_low_limit[LANGUAGE_NONE][0]['value'] : false;
  
  krsort($budgets);  //sort with the biggest budget at the top!
  $ret = array(
    'total_hours' => $total_hours_sum,
    'available_hours' => $available_hours_sum,
    'budgets' => $budgets,
    'notify_users' => $notify_users_flat,
    'notify_low' => $low_treshold,
  );
  
  return $ret;
}

/**
* Validate budget entity edit form
*/
function _erpal_projects_helper_budget_validate($form, $form_state) {
  $values = $form_state['values'];
  
  $budget_id = $values['budget_id'];
  $timetracking_nid = _erpal_projects_helper_get_timetrackings_by_budget($budget_id);
  
  if (count($timetracking_nid)) {
    //budgets that already have timetrackings, did the user change the date?
    $budget = $form_state['budget'];
    $date_from = strtotime($values['date_from']);
    $date_till = strtotime($values['date_till']);

    if ($date_from != $budget->date_from || $date_till != $budget->date_till) {      
      form_set_error('budget', t('Sorry, for a budget that has already timetrackings booked, you cannot change the date.'));
    }

  }
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
* Book a timetracking node to budgets at a task, may be timetracking will be split if no budget of the needed sice is available
* if we have the choice we first use the budget that has shortes time limit
* @param $timetracking_node object a timetracking node that is booked
* @param $billable_information billable information, not neccessaryly from the direct subject of the timetracking node
*   but may be from prarent task or project nodes
* @param $allow_negative if true, if there is no more budget available, we reduce the available hours to a negative value
* @return returns a timetracking node if the whole timetracking node could not be booked because there is not enough budget, if the total duration of the timetracking node could be booked to the available budget, return false
*/
function _erpal_projects_billable_book_timetracking_to_budget($timetracking_node, &$billable_information, $allow_negative=false) {
  //get the relevant subject node, we got the billable information from
  $pricing_nid = $billable_information['pricing_nid'];
  $pricing_node = node_load($pricing_nid);

  $booking_date = time();
  if (isset($timetracking_node->field_date_time[LANGUAGE_NONE][0]['value'])) {
    $booking_date = $timetracking_node->field_date_time[LANGUAGE_NONE][0]['value']; //the date when the timetracking node is booked      
  }
  $budgets_arr = _erpal_projects_helper_get_budget($pricing_node, $booking_date);

  //sort budgets: date_till (smallest date at the top), available hours (biggest first)
  $budgets = $budgets_arr['budgets'];
  $tmp_budgets = array();
  //order by date_till first
  if (is_array($budgets)) {
    foreach ($budgets as  $delta=>$budget_entity) {
      //load the budget entity again because we could have made changes above if there was a budget entity referenced before
      $budget_entity_arr = entity_load('budget', array($budget_entity->budget_id)); 
      $budget_entity = $budget_entity_arr[$budget_entity->budget_id];
      $date_till = $budget_entity->date_till;
      $available_hours = $budget_entity->available_hours;
      $tmp_budgets[$date_till][$available_hours][] = $budget_entity;
      ksort($tmp_budgets[$date_till]);  //reverse sort, we want to budget with the closest expire date first to be used.
    }
  }
  krsort($tmp_budgets);

  $budgets = array();
  //now flatten Budgets again
  foreach ($tmp_budgets as $sub_budget_arr) {
    foreach ($sub_budget_arr as $budget_entity_arr) {  //array by date_till
      foreach ($budget_entity_arr as $budget_entity)  //array by available_hours
      $budgets[] = $budget_entity;
    }
  }
  
  //now we have budgets ordered with the biggest budget at the top.
  $billing_duration = $timetracking_node->field_billing_duration[LANGUAGE_NONE][0]['value'];
  
  if (!$billing_duration) {
    $timetracking_node = false;
    return;
  }

  $found_budget = false;
  if (is_array($budgets)) {
    foreach ($budgets as $delta=>$budget_entity) {

      if ($budget_entity->available_hours <= 0 && !$allow_negative)
        continue; //no hours available, check next budget

      $found_budget = true;
      
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
      $budget_entity->skip_refactoring = true; //if we dont set this, the host node will be added to the queue to refactor timetracking nodes and budgets
      $budget_entity->save();
      
      $budget_entity_w = entity_metadata_wrapper('budget', $budget_entity);
      $billable_information['budget_time_billing_budget_direct'] = $budget_entity_w->field_budget_time_billing->value();
      
      _erpal_projects_helper_check_budget_usage($pricing_node, $booking_date, true);

      //save the budget entity reference field of the timetracking node to the chosen budget entity, so we dont need to
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
        //$timetracking_node_new->force_billable = $billable_information['budget_time_billing'] == 'billable';
        $timetracking_node_new->status = 1; //published
        $timetracking_node_new->language = $timetracking_node->language;
        $timetracking_node_new->type = $timetracking_node->type;
        $timetracking_node_new->title = $timetracking_node->title;
        $timetracking_node_new->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'] = $timetracking_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
        $timetracking_node_new->field_date_time[LANGUAGE_NONE][0]['value'] = $timetracking_node->field_date_time[LANGUAGE_NONE][0]['value'];  //no time till because this is not neccessary in the splitted timetracking node
        $timetracking_node_new->field_billing_duration[LANGUAGE_NONE][0]['value'] = $rest_hours;
        $timetracking_node_new->field_timetracking_duration[LANGUAGE_NONE][0]['value'] = -1;  //for statistic reasons we have the total
        //duration at the timtracking node inserted by the user, so here we have no further duration. Only billing_duration 
        //will be split because it is used to calculate budgets and billables. We cannot split the duration because we don't know where to split if duration and billing duration have different values
        node_object_prepare($timetracking_node_new);
        $timetracking_node_new->uid = $timetracking_node->uid;
        node_save($timetracking_node_new);  //start recursion to save this timetracking node to budget...
        return false;
        
      } else
        return false;
    }
  }

  if ($found_budget)
    return false;
  else  
    return $timetracking_node; 
  
}

/**
* Saves the booked budget hours from the timetracking to the referenced budget entity again
*/
function _erpal_projects_helper_restore_timetracking_budget($timetracking_node) {
  //if timetracking node already has a budget entity referenced, add the budgethours again to the budget_entity available_hours.
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
  static $budget_warnings=array();

  $budgets_arr = _erpal_projects_helper_get_budget($node, $booking_date);

  $total_hours = $budgets_arr['total_hours'];
  $available_hours = $budgets_arr['available_hours'];
  
  $usage_percent = abs((($total_hours - $available_hours) / $total_hours) * 100);
  $notify_users = $budgets_arr['notify_users'];
  $notify_low = $budgets_arr['notify_low'];
  $usage_limit = $notify_low ? $notify_low : _erpal_projects_helper_budget_usage_warn(); //if the direct budget has a limit set, we use this, otherwise we take the global one

  $budget_usage = $available_hours.' / '.$total_hours;
  $node_link = l($node->title, 'node/'.$node->nid);

  //close to limit
  if ($usage_percent >= $usage_limit && $usage_percent < 100) {
    $message = t('Budget of !node_link is closed to limit with !budget_usage', 
      array(
        '!node_link' => $node_link,
        '!budget_usage' => $budget_usage,
      )
    );
    if (!isset($budget_warnings[$message])) {
      drupal_set_message($message, 'warning');
      $budget_warnings[$message] = 1;
    }
    
    //call rules event
    if (module_exists('rules')) {
      rules_invoke_event('budget_warning', $node, $available_hours, $total_hours, $notify_users, $notify_low);
    }
    
    //send budget status email
    //@TODO we may do this with rules!
    _erpal_projects_helper_send_budget_status_mail('low', $node, $available_hours, $total_hours, $notify_users);
  }
  
  //reached limit
  if ($usage_percent >= 100) {
    $message = t('Budget of !node_link is completely used with !budget_usage', 
      array(
        '!node_link' => $node_link,
        '!budget_usage' => $budget_usage,
      )
    );
    
    if (!isset($budget_warnings[$message])) {
      drupal_set_message($message, 'error');
      $budget_warnings[$message] = 1;
    }
    
    //call rules event
    if (module_exists('rules')) {
      rules_invoke_event('budget_empty', $node, $available_hours, $total_hours , $notify_users, $notify_low);
    }
    
    //send budget status email
    //@TODO we may do this with rules!
    _erpal_projects_helper_send_budget_status_mail('empty', $node, $available_hours, $total_hours, $notify_users);
  }
  
}

/**
* Return a task or project nodes that reference a given budget_id
* @param $budget_id the budget id that the returned project / task node are referencing
* @param $nid_only if true, only the nid is returned, otherwise the complete node
* @return the node of the project/task referencing the given budget
*/
function _erpal_projects_helper_get_node_by_budget($budget_id, $nid_only=false) {
  $node = false;
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'field_collection_item')
  ->entityCondition('bundle', 'field_pricing')
  ->fieldCondition('field_budgets', 'target_id', $budget_id)
  ->addMetaData('account', user_load(1)); // run the query as user 1 to get all nodes
  
  $result = $query->execute();

  if (isset($result['field_collection_item'])) {
    $ids = array_keys($result['field_collection_item']);   
    $id = $ids[0];
    $field_collection = entity_load('field_collection_item', array($id));
    $field_collection = $field_collection[$id];
    if ($nid_only)
      return $field_collection->hostEntityId();
    else
      return $field_collection->hostEntity();
  }
 
  return $node;
}

/**
* Send email of the budget status is low or empty
* @param $status the status (low or empty) of the budget
* @param $node the node where the budget is added to
* @param $available_hours is the amount of hours the budget has left to use
* @param $total_hours the amount of total hours of the budget
* @param $notify_users the users the should get a notification
*/
function _erpal_projects_helper_send_budget_status_mail($status, $node, $available_hours, $total_hours, $notify_users) {
  
  if (empty($notify_users) || !count($notify_users))
    return; //no users to notify by mail
  
  $project_nid = _erpal_projects_helper_has_project($node);
  $project_node = node_load($project_nid);
  $data['budget'] = array(
    'status' => $status,
    'budget_node' => $node,
    'budget_project' => $project_node,
  );

  if (!$subject = token_replace(_erpal_projects_helper_budget_usage_email_subject(), $data)) {
    $subject = t('ERPAL budget Notification');
  }
  $message_body = token_replace(_erpal_projects_helper_budget_usage_email_body(), $data);
  if ($message_body) {
    $message = array(
      'subject' => $subject,
      'message' => $message_body,
    );
    // email will be added to a cron queue
    _erpal_basic_helper_notify_users($notify_users, $message);
  }
}