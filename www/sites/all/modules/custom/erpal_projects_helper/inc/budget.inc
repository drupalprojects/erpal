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