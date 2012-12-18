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
  $uids = _erpal_profile_helper_get_users(); //loads only active users
  
  //loop through all users
  foreach ($uids as $uid) {      
    
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
    
    //if the user has never had an employee contract
    $contract_data = _erpal_profile_helper_user_contracts($uid, 'full_employee');
    if (!$contract_data)
      continue;
   
    //now recalculate the months from "from" to current
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
      $working_days_unix = array();  //this will be filled with all days where the user has to work
      $must_working_time_h = _erpal_employee_helper_get_must_working_time($uid, $year, $month, $working_days_unix);

      //get the time the user really worked in hours
      $worked_time_h = _erpal_employee_helper_get_worked_time($uid, $year, $month);

      //get the ill days of the user and the time that is booked for these holidays (in $holiday_hours) to add them to the worked time of the user
      $ill_hours = 0;
      $user_ill_days = _erpal_employee_helper_user_ill_days($uid, $year, $month, $ill_hours, $working_days_unix);
      $worked_time_h += $ill_hours; //cause ill days count as working time
      
      //get the holidays of the user and the time that is booked for these holidays (in $holiday_hours) to add them to the worked time of the user. Here we have only holidays that are on general working days
      $holiday_hours = 0;
      $user_holidays = _erpal_employee_helper_user_holidays($uid, $year, $month, $holiday_hours, $user_ill_days, $working_days_unix);
      $worked_time_h += $holiday_hours; // cause user holidays count as working time

     
   /*      
      dann die projektzeit (auch wieder unter der Berücksichtiung dass er employee war)
    */
    }
  }
}

/**
* Returns the ill days a user had in the given date range but only if he was an employee at the time
* ill days will be only returned if they are on a real working day
* @params $ill_hours this will return the hours that the ill days will add to the working time account of the user
* because ill days count as working time
* @param $working_days_unix is an array of unix timestamps describing all days a user has to work, means it is a general working day (mo-fr etc.) and there is no global holiday
*/
function _erpal_employee_helper_user_ill_days($uid, $year, $month, &$ill_hours, $working_days_unix) {
  $ill_day_nodes = _erpal_employee_helper_get_working_time_nodes_employee_by_type($uid, $year, $month, 'ill');
  
  $ill_days = _erpal_calendar_helper_get_dates_in_range($year, $month, $ill_day_nodes, 'field_date_time', 'field_date_time', array(LANGUAGE_NONE, 0, 'value'), array(LANGUAGE_NONE, 0, 'value2'));

  $ill_days_nodes_on_working_days = array();
  
  foreach ($ill_days as $ill_day_unix) {
    //take the ill days of the user that are on a general working day
    $ill_day_string = date('Ymd', $ill_day_unix);
    $is_ill_day = false;
    foreach ($working_days_unix as $working_day) {
      $working_day_string = date('Ymd', $working_day);

      if ($working_day_string == $ill_day_string) {
        $is_ill_day = true;
        break;
      }
    }
    
    if ($is_ill_day) {
      //get the contract to check ho many hours a day user has to work and these are the hours that are added as working time for a holiday day      
      $hours_to_work = _erpal_profile_helper_get_hours_to_work_a_day($uid, $ill_day_unix);
      $ill_hours += $hours_to_work;
      $ill_days_nodes_on_working_days[] = $ill_day_unix;
    }
  }  
  
  return $ill_days_nodes_on_working_days;
}

/**
* Returns the holidays a user took in the given date range but only if he was an employee at the time
* holidays will be only returned if they are on a real working day
* @param $holiday_hours this will return the hours that the holidays will add to the working time account of the user
* because holidays count as working time
* @param $user_ill_days array with unix timestamps of days the user was ill. We need this because holidays on illdays are not respected!
* @param $working_days_unix all working days that means general working day (mo-fr. etc.) and not a global holiday
*/
function _erpal_employee_helper_user_holidays($uid, $year, $month, &$holiday_hours, $user_ill_days, $working_days_unix) {
  
  $holiday_nodes = _erpal_employee_helper_get_working_time_nodes_employee_by_type($uid, $year, $month, 'holiday');
  
  $holiday_days = _erpal_calendar_helper_get_dates_in_range($year, $month, $holiday_nodes, 'field_date_time', 'field_date_time', array(LANGUAGE_NONE, 0, 'value'), array(LANGUAGE_NONE, 0, 'value2'));

  $holiday_nodes_on_working_days = array();
  
  foreach ($holiday_days as $holiday_unix) {
    $holiday_string = date('Ymd', $holiday_unix);
    //if the holiday is on an ill day, we dont respect the holiday, it is not added to working time and not substracted from available holidays
    $is_ill_day = false;
    foreach ($user_ill_days as $ill_day_unix) {
      $ill_day_string = date('Ymd', $ill_day_unix);
      if ($ill_day_string == $holiday_string) {
        $is_ill_day = true;
        break;
      }
    }
        
    if ($is_ill_day)    
      continue;
    
    //take the holiday days of the user that are on a general working and not on a global holiday day
    $is_working_day = false;
    foreach ($working_days_unix as $working_day) {
      $working_day_string = date('Ymd', $working_day);
      if ($working_day_string == $holiday_string) {
        $is_working_day = true;
        break;
      }
    }
    
    if ($is_working_day) {
      //get the contract to check ho many hours a day user has to work and these are the hours that are added as working time for a holiday day
      $hours_to_work = _erpal_profile_helper_get_hours_to_work_a_day($uid, $holiday_unix);
      $holiday_hours += $hours_to_work;
      $holiday_nodes_on_working_days[] = $holiday_unix;
    }
  }  
  return $holiday_nodes_on_working_days;
  
}

/**
* Returns working time nodes of a user in a given date range with respecting if the user was an employee at the given time
*/
function _erpal_employee_helper_get_working_time_nodes_employee_by_type($uid, $year, $month, $type) {
  $monthNull = str_pad($month, 2 ,'0', STR_PAD_LEFT);
	$ldom = erpal_calendar_ldom($month, $year);  //last day of month
	$range_from = "$year-$monthNull-01 00:00:00";
	$range_till = "$ldom 23:59:59";
  $date_till_unix = strtotime($range_till);
  $date_from_unix = strtotime($range_from);
  
  //get all working time of the user and always check if he is employee at the time of the working time node entry
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_working_time')
    ->propertyCondition('status', 1)
    ->propertyCondition('uid', $uid)
    ->fieldCondition('field_date_time', 'value', $date_from_unix, '>=')
    ->fieldCondition('field_date_time', 'value', $date_till_unix, '<=')
    ->fieldCondition('field_working_time_type', 'value', $type)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $working_time_nodes = array();
  if (isset($result['node'])) {
    $working_time_nids = array_keys($result['node']);
    $working_time_nodes = entity_load('node', $working_time_nids);
  }
  
  //now filter the nodes and keep only the once at the time when user was employee
  $nodes = array();
  foreach ($working_time_nodes as $working_time_node) {
    $booking_time_from = $working_time_node->field_date_time[LANGUAGE_NONE][0]['value2'];  //use value2 because this is the latest day the contract could be committed to be valid for this date.
    
    //add this only, if user is emplyee at the time of the timetracking entity.
    $contract_data = _erpal_profile_helper_get_current_contract($uid, array(), $booking_time_from);
    if (!$contract_data || !is_array($contract_data) || $contract_data['member_type'] != 'full_employee')
      continue; //no contract or no full employee, no "must working hours" this day (may be he has a contract later)!!  

    $nodes[] = $working_time_node;
  }
  
  return $nodes;
}

/**
* Returns the worked time in hours of a user while he is employee in the given month. We only add the time if the user had an employee contract at this time
*/
function _erpal_employee_helper_get_worked_time($uid, $year, $month) {
   
  $working_time_nodes = _erpal_employee_helper_get_working_time_nodes_employee_by_type($uid, $year, $month, 'work');

  $total_worked_time_h = 0;
  foreach ($working_time_nodes as $working_time_node) {
    $duration = isset($working_time_node->field_duration_calc[LANGUAGE_NONE][0]['value']) ? $working_time_node->field_duration_calc[LANGUAGE_NONE][0]['value'] : 0;    
    $total_worked_time_h += $duration;
  }
  
  return $total_worked_time_h;
}

/**
* Returns the must working time in hours the user has to work in the given month
* @param $must_working_days_arr is filled as array with all days that are working days, no global_non_working_day and n global holiday
*/
function _erpal_employee_helper_get_must_working_time($uid, $year, $month, &$must_working_days_arr) {
  //get the contract data of the user in every days loop and then recalculate the time with respect to he current date (if a contract starts in the middle of a month, calculate must working days pro rata
  
  //get tid for holiday
  $holiday_term_string = _erpal_employee_helper_field_tag_working_time_type('holiday');

  $holiday_term = taxonomy_get_term_by_name($holiday_term_string, 'date_item_tags');
  $holiday_term = array_shift($holiday_term);

  //get all holidays in the year and month  
  $holidays = erpal_calendar_get_holidays($year, $month, $holiday_term->tid);
  
  //get all general working days
  $working_days = _erpal_employee_get_general_working_days($year, $month);
 
  //calculate the time in seconds the user has to work according to his contract profile in this month but not on holidays
  //but respect the start date in the contract as offset!
  $total_working_hours = 0;

  foreach ($working_days as $day_unix) {
    
    //get the users contract
    $contract_data = _erpal_profile_helper_get_current_contract($uid, array(), $day_unix);
    if (!$contract_data || !is_array($contract_data) || $contract_data['member_type'] != 'full_employee')
      continue; //no contract or no full employee, no "must working hours" this day (may be he has a contract later)!!
    
    $working_time_day = _erpal_profile_helper_get_hours_to_work_a_day($uid, $day_unix, $contract_data);
    
    $day_str = date('Ymd', $day_unix);
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
      $must_working_days_arr[] = $day_unix;      
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