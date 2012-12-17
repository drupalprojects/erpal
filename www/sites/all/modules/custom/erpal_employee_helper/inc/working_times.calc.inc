<?php

/**
* @file provides all functions to calculate working_times entities from employee working time nodes.
*/

/**
* Calculates all entities for month and year employee reporting
*/
function _erpal_employee_helper_calculate_working_times() {
  global $user;
  
  //check in variables if the last run of this function was today, if so, return, otherwise process
  $last_run = _erpal_employee_helper_get_last_run();

  //@TODO uncomment again
  //if (date('Y-m-d', $last_run) == date('Y-m-d'))
    //return false;
    
  //get all user IDs
  $uids = _erpal_profile_helper_get_users();
  
  //loop through all users
  foreach ($uids as $uid) {      
    
    //get the contract data for each user with data that is valid for the current date.
    $contract_data = _erpal_profile_helper_get_current_contract($uid);

    if ($contract_data['member_type'] != 'full_employee')
      continue;
    
    //get all invalid month working times (dirty==1) and get the one with the lowest year and month.
    $dirty_working_times = _erpal_employee_helper_get_dirty_working_times($uid, 'month');
    if (!count($dirty_working_times))
      continue;
    
    $keys = array_keys($dirty_working_times);
    $first_element_key = $keys[0];
    $first_element = $dirty_working_times[$first_element_key];
    
    $recalculate_years = array();
    $from_year = $first_element->year;
    $from_month = $first_element->month;
    
    $current_year = date('Y');    
    $current_month = date('m');
    
    //now recalculate the months
    $years = _erpal_employee_helper_recalculate_month($uid, $from_year, $current_year, $from_month, $current_month);
    
    //@TODO: now recalculate the years in the result array, using the data from the calculated month
  }

  
  die();
 
 
  //If we have holidays or illdays given as a period, we only count these days if they are regular working days. And when we have a range, only use the days in the range that match the current month that is calculated
 
  //calculate: The real working time in seconds according to the working time nodes with type "working_time" of the user, we just sum the duration field, no need to repsect pause times in calculation. 
  
  //calculate: ill days and holidays in seconds, they are added to the total real working time to be compared with the needed working time (see below)
  
  //@TODO: we need a setting "working days" in the employee settings where we can set the general working days (mo-fr for example, but could be different)
  //calculate: Calculate the "must working days" of the current month. This is every day set in the "working days" settings of the module. erpal_date nodes with type "holiday" are not working days and excluded from this calculation
  
  //calculate: the needed Working Time in seconds according to the contract data of the user. If user started in the middle of a month or a week, this is respected in the needed working time because we add the beginning of the contract to the function that calculates the needed working time.
  //@see _bsi_filter_get_days_in_range in bsi_controling module
  //@see bs_ldom to get last day of month in old intranet
  
  
  //calculate: The working time tracked on projects with timetracking nodes
  
  //Calculate: ill_days off the user
  
  //calculate holidays of the user: Respect to when the user started in the first year, he only has holidays relative to his days in the year. 
  //if user has holidays from year before and it is still valid according to the property holidays_available_till we reduce them first. If he hasn't we reduce holidays available of the current year.
  //The function returns the rest holidays in the current year, in the year before and the used holidays in the month.
  
 
  
  
  
  //calculate: overhour reduce of the user
  
  //
  
  
  
  //if next year is another than the year we processed before, calculate the year working_time entites as sum of the month working_time entities
  
  //set the time of last run
  _erpal_employee_helper_set_last_run();

}

/**
* Recalculate the month working_times in the given range
* @return an array with years to recalculate
*/
function _erpal_employee_helper_recalculate_month($uid, $from_year, $to_year, $from_month, $to_month) {
  if (!$from_year && !$from_month)
    continue;
  if (!$from_month)
    $from_month = 1;
  
  //now loop through years and month till the current date and recalculate them. If the year changes recalculate the year from the working_times month entites in this year
  for ($year=$from_year; $year<=$to_year; $year++) {
          
    if ($year == $from_year) {
      //for the first year start at from_month
      $start_month = $from_month;
      $end_month = 12;        
    } 
    elseif ($year == $to_year) {
      //for the last year, loop only to current month
      $start_month = 1;
      $end_month = $to_month;
    }
    else {
      //not the start nor the end month, start with 1 and go to 12
      $start_month = 1;
      $end_month = 12;
    }
    
    for ($month=$start_month; $month<=$end_month; $month++) {
      //get the time the user must work according to his contract
      $must_working_time_sec = _erpal_employee_helper_get_must_working_time($uid, $year, $month);
      
    }
  }
}

/**
* Returns the must working time in seconds the user has to work in the given month
*/
function _erpal_employee_helper_get_must_working_time($uid, $year, $month) {
  //get the contract data of the user in every days loop and then recalculate the time with respect to he current date (if a contract starts in the middle of a month, calculate must working days pro rata
  
  //get tid for holiday
  $holiday_term_string = _erpal_employee_helper_field_tag_working_time_type('holiday');

  $holiday_term = taxonomy_get_term_by_name($holiday_term_string, 'date_item_tags');
  $holiday_term = array_shift($holiday_term);

  //get all holidays in the year and month  
  $holidays = erpal_calendar_get_holidays($year, $month, $holiday_term->tid);
  
  //get all general working days
  $working_days = _erpal_employee_get_general_working_days($year, $month);
  
  //get the working time a day, this is hours per week divided by the number of general working days
  $general_working_days = _erpal_employee_helper_general_working_days();
  
  //get the users contract
  $contract_data = _erpal_profile_helper_get_current_contract($uid);

  if (!$contract_data || !is_array($contract_data))
    return 0; //no contract, no "must working hours"!

  $working_time_week = $contract_data['hours'];
  $working_time_day = round($working_time_week / count($general_working_days), 2);
  
  //calculate the time in seconds the user has to work according to his contract profile in this month but not on holidays
  $total_working_hours = 0;
  foreach ($working_days as $day_unix) {
    $day_str = date('ymd', $day_unix);
    //is this a holiday?
    $is_holiday = false;
    foreach ($holidays as $holiday_unix) {
      $holiday_str = date('Ymd', $holiday_unix);
      
      if ($day_str == $holiday_str) {
        $is_holiday = true;
        break;
      }
    }
    
    if (!$is_holiday) {
      $total_working_hours += $working_time_day; //add the working hours for this day
    }
  }
  
  return $total_working_hours;
}

/**
* Get all working general days in the given month and the given year
*/
function  _erpal_employee_get_general_working_days($year, $month) {
  $monthNull = str_pad($month, 2 ,'0', STR_PAD_LEFT);
	$ldom = erpal_calendar_ldom($month, $year);  //last day of month
	$range_from = "$year-$monthNull-01 00:00:00";
	$range_till = "$ldom 23:59:59";
  $date_till_unix = strtotime($range_till);
  
  //now count every day from start to till and check if this is a working day
  $general_working_days = _erpal_employee_helper_general_working_days();
  
  $days = array();
  if (!$year || !$month)
    return $working_days;
    
  $day_count = 0;
  $date_current = strtotime($range_from.' +'.$day_count.' days'); //initalised get day  
  while ($date_current <= $date_till_unix) {        
   
    $current_week_day = date('w', $date_current);
    if (in_array($current_week_day, $general_working_days)) {
      //this is a general working day, add it to the result
      $days[] = strtotime(date('Y-m-d 00:00:00', $date_current));
    }
   
    $day_count++;  //next day
    //get the day
    $date_current = strtotime($range_from.' +'.$day_count.' days');
  }
 
  return array_unique($days);
}

/**
* Returns all working_times entities that are invalid, if set, with respect to the give user
*/
function _erpal_employee_helper_get_dirty_working_times($uid=false, $type=false) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'working_times')
    ->propertyCondition('dirty', 1);
  
  if ($type)
    $query->propertyCondition('type', $type);
  
  if ($uid && false)
    $query->propertyCondition('uid', $uid);
  
  //order by the lowest year and month
  $query->propertyOrderBy('year', 'ASC'); //lowest year first
  $query->propertyOrderBy('month', 'ASC'); //lowest month first
  
  $result = $query->execute();
  
  $working_times = array();
  if (isset($result['working_times'])) {
    $working_times = working_times_load_multiple(array_keys($result['working_times']));
    
  }
    
  return $working_times;
}

/**
* Returns a list of all active users
*/
function _erpal_profile_helper_get_users() {
  $query = db_select('users', 'u');
  $query->fields('u', array('uid'));
  $query->condition('status', 0, '>');
  $result = $query->execute();
  $uids = array();
  while($record = $result->fetchAssoc()) {
    $uids[] = $record['uid'];
  }

  return $uids;
}

/**
* Returns when the last calculation was, because this may be time consuming and so only processed once a day
*/
function _erpal_employee_helper_get_last_run() {
  return variable_get('erpal_employee_report_last_run', false);
}

/**
* Sets the last run of employee report calculation
*/
function _erpal_employee_helper_set_last_run() {
  variable_set('erpal_employee_report_last_run', time());
}