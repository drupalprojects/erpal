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

  if (date('Y-m-d', $last_run) == date('Y-m-d') && _erpal_employee_helper_employee_report_run_only_once_a_day())
    return false;

  //get all user IDs
  $uids = _erpal_profile_helper_get_users(); //loads only active users
  
  //loop through all users
  foreach ($uids as $uid) {      
    
    //get all invalid month working times (dirty==1) and get the one with the lowest year and month.
    $dirty_working_times = _erpal_employee_helper_get_dirty_working_times($uid, 'month');
    
    $from_month = false;
    $from_year = false;
    if (!count($dirty_working_times)) {
      //get the earliest contract when we didn't find a working time entity yet. From this point we start recalculating all working_times entities
      $earliest_contract = _erpal_employee_helper_get_earliest_contract();
      //get the date

      $valid_since_unix = isset($earliest_contract->field_valid_since[LANGUAGE_NONE][0]['value']) ? $earliest_contract->field_valid_since[LANGUAGE_NONE][0]['value'] : 0;
      $from_year = date('Y', $valid_since_unix);
      $from_month = date('m', $valid_since_unix);
      
    } else {
      $keys = array_keys($dirty_working_times);
      $first_element_key = $keys[0];
      $first_element = $dirty_working_times[$first_element_key];
      
      $from_year = $first_element->year;
      $from_month = $first_element->month;
    }
    
    if (!$from_year && !$from_month)
      continue;
    
    $current_year = date('Y');    
    $current_month = date('m');
    
    //Performance security: earliest date should not be more than 10 years away!
    if ($current_year - $from_year > 10)
      $from_year = $current_year -10;  //set at maximum 10 years before
    
    //if the user has never had an employee contract
    $contract_data = _erpal_profile_helper_user_contracts($uid, 'full_employee');
    if (!$contract_data)
      continue;

    //now recalculate the months from "from" to current
    $recalculate_years = _erpal_employee_helper_recalculate_month($uid, $from_year, $current_year, $from_month, $current_month);
    
    //now recalculate the years in the result array, using the data from the calculated month
    sort($recalculate_years);
    foreach ($recalculate_years as $recalculate_year) {
      _erpal_employee_helper_recalculate_year($uid, $recalculate_year);
    }
  }

  //set the time of last run
  _erpal_employee_helper_set_last_run();

}

/**
* recalculates a complete year, no matter if it is dirty or not. Just SUM the month working_times entities values
*/
function _erpal_employee_helper_recalculate_year($uid, $year) {
  $working_times = working_times_load_by_user('month', $uid, $year);
  
  //get the working_times entity for the year. If there is none, create one.
  $working_times_year = working_times_load_by_user('year', $uid, $year);
  if (!count($working_times_year)) {
    //create a new one
    $values = array('type' => 'year', 'uid' => $uid, 'year' => $year, 'month' => 0);
    $working_times_year = working_times_create($values);
  } else {
    $working_times_year = array_shift($working_times_year);
  }
  
  
  //initialise variables
  $overtime = 0;
  $ill_days = 0;
  $holidays_used = 0;
  $holidays_used_from_before = 0;
  $total_hours = 0;
  $booked_working_hours = 0;
  $project_time = 0;
  $overtime_reduce = 0;  
  foreach ($working_times as $working_time) {    
    $holidays_available = $working_time->holidays_available;  //yes, this will be updated every foreach run because we need the value of the latest month
    $holidays_available_till = $working_time->holidays_available_till;
    
    $overtime += $working_time->overtime;
    $ill_days += $working_time->ill_days;
    $holidays_used += $working_time->holidays_used;
    $overtime_reduce += $working_time->overtime_reduce;
    $holidays_used_from_before += $working_time->holidays_used_from_before;
    $total_hours += $working_time->total_hours;
    $booked_working_hours += $working_time->booked_working_hours;
    $project_time += $working_time->project_time;
  }
  
  //save summed values to entity
  $working_times_year->overtime = $overtime;
  $working_times_year->ill_days = $ill_days;
  $working_times_year->holidays_used = $holidays_used;
  $working_times_year->overtime_reduce = $overtime_reduce;
  $working_times_year->holidays_used_from_before = $holidays_used_from_before;
  $working_times_year->total_hours = $total_hours;
  $working_times_year->booked_working_hours = $booked_working_hours;
  $working_times_year->project_time = $project_time;
  $working_times_year->holidays_available = $holidays_available;
  $working_times_year->holidays_available_till = $holidays_available_till;
  
  $working_times_year->save();
}

/**
* Return the contract with the earliest valid_since date
*/
function _erpal_employee_helper_get_earliest_contract() {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'field_collection_item')
  ->entityCondition('bundle', 'field_contract_data')
  ->fieldOrderBy('field_valid_since', 'value', 'ASC')
  ->range(0,1)  //only one, the oldest one
  ->addMetaData('account', user_load(1)); // run the query as user 1

  $result = $query->execute();
  
  $contract_data = false;
  if (isset($result['field_collection_item'])) {
    $contract_data_ids = array_keys($result['field_collection_item']);
    //load them
    $contract_data = entity_load('field_collection_item', $contract_data_ids);
    $contract_data = array_shift($contract_data);
  }

  return $contract_data;
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

  $years = array();  //result all years we have calculated
  //now loop through years and month till the current date and recalculate them. If the year changes recalculate the year from the working_times month entites in this year
  for ($year=$from_year; $year<=$to_year; $year++) {
          
    if ($year == $from_year && $year != $to_year) {
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
      $booked_working_h = $worked_time_h;

      //get the ill days of the user and the time that is booked for these holidays (in $holiday_hours) to add them to the worked time of the user
      $ill_hours = 0;
      $user_ill_days = _erpal_employee_helper_user_ill_days($uid, $year, $month, $ill_hours, $working_days_unix);
      $booked_working_h += $ill_hours; //cause ill days count as working time
      
      //get the holidays of the user and the time that is booked for these holidays (in $holiday_hours) to add them to the worked time of the user. Here we have only holidays that are on general working days
      $holiday_hours = 0;
      $user_holidays = _erpal_employee_helper_user_holidays($uid, $year, $month, $holiday_hours, $user_ill_days, $working_days_unix);
      $booked_working_h += $holiday_hours; // cause user holidays count as working time

      //Get the project time a user booked as erpal_timetracking nodes
      $user_project_time_h = _erpal_employee_helper_get_user_project_time($uid, $year, $month);   

      //calculate: overhour reduce of the user, the time that he reduced his over hours because he got them paid
      $reduce_hours = _erpal_employee_helper_get_reduce_hours($uid, $year, $month);
      
      //###########################################################################
      //now load the entity if one exists and update it, otherwise create a new one
      //###########################################################################
      $working_times_entity = working_times_load_by_user('month', $uid, $year, $month);
      $working_times_entity = array_shift($working_times_entity);
      if (!$working_times_entity) {
        //create a new one!
        $values = array('uid' => $uid, 'type' => 'month', 'month' => $month, 'year' => $year);
        $working_times_entity = working_times_create($values);
      }
      
      //now update all the values
      //if it is the current month, its always dirty and will be recalculated
      if ($month == $to_month && $year == $to_year)
        $working_times_entity->dirty = 1; //the working_times in the current month are alway dirty and have to be recalculated
      
      //set ill days
      $working_times_entity->ill_days = count($user_ill_days);
      
      //now get the offset
      $offset = working_times_load_by_user('offset', $uid, $year, $month);      
      $offset = array_shift($offset);
      $holidays_used = count($user_holidays);

      $rest_holiday_to_book = _erpal_employee_helper_book_user_holidays($uid, $holidays_used, $month, $year, $working_times_entity);
      $holidays_used_from_before = $holidays_used - $rest_holiday_to_book;
      
      //save the amount of booked days to the year before to the current entity. Otherwise if the current month will be recreated, the holiday booked on the rest holidays of the year before will be decreased with every run!
      
      $working_times_entity->holidays_used_from_before = $holidays_used_from_before;
      $working_times_entity->holidays_used = $rest_holiday_to_book;      
      
      //get the year / month before
      $monthNull = str_pad($month, 2 ,'0', STR_PAD_LEFT);
      $year_month_str = $year.'-'.$monthNull.'-01 00:00:00';  //we don't have an exact date so take the middle of the month
      $year_month_unix = strtotime($year_month_str);
      $year_month_before_unix = strtotime($year_month_str.' -1 month');
      $year_before = date('Y', $year_month_before_unix);
      $month_before = date('m', $year_month_before_unix);
      
      if ($offset) {
        $current_holidays_available = $offset->holidays_available;
      } else {
        $current_holidays_available = _erpal_employee_get_holidays_available($uid, $year_before, $month_before, 'month', $year_month_unix);
      }
      
      $working_times_entity->holidays_available = $current_holidays_available - $working_times_entity->holidays_used;//this is the total amount of available holidays in the total year of this month where as all other values are absolute values only in the current month.     
 
      $holidays_available_till = _erpal_employee_get_holiday_expire_date_from_offset($uid, $month, $year);
      if (!$holidays_available_till) {
        //holiday is always avalilable from the beginning of the year +1 year + x month set in adminsettings      
        //get the last day of the year
        $last_year_day = $year.'-12-31 23:59:59';
        $holiday_transfer_month = _erpal_employee_get_holiday_month_transfer();
        $holidays_available_till = strtotime($last_year_day.' +'.$holiday_transfer_month.' month');
      }
        
      $working_times_entity->holidays_available_till = $holidays_available_till;
      
      $working_times_entity->total_hours = round($worked_time_h, 2);
      $working_times_entity->booked_working_hours = round($booked_working_h, 2);
      $working_times_entity->project_time = round($user_project_time_h, 2);
      
      $working_times_entity->overtime_reduce = round($reduce_hours, 2);

      //calculate and set overtime
      $overtime = $booked_working_h - $must_working_time_h - $reduce_hours;
      $working_times_entity->overtime = round($overtime, 2);
           
      //if we dont't have a offset, we cannot add anything
      if ($offset) {
        _erpal_employee_helper_add_offset($working_times_entity, $offset);
      }
      
      $working_times_entity->save();
    }
    
    $years[] = $year;
  }
  
  return $years;
}

/**
* Checks in all offset entities of the given year bevor or in the current month (the latest one counts) what is the holiday_available till date
*/
function _erpal_employee_get_holiday_expire_date_from_offset($uid, $month, $year) {
  $expire_unix = false;
  
  for($i=$month; $i>0; $i--) {
    $offset = working_times_load_by_user('offset', $uid, $year, $i);
    if ($offset) {
      $offset = array_shift($offset);
      $expire_unix = $offset->holidays_available_till;
      return $expire_unix;
    }
  }
  
  return $expire_unix;
}

/**
* Adds the data of an offset entity to a given working times entity
*/
function _erpal_employee_helper_add_offset($working_times, $offset) {
  $working_times->overtime += $offset->overtime;
  $working_times->ill_days += $offset->ill_days;
  $working_times->holidays_used += $offset->holidays_used;

  $working_times->total_hours += $offset->total_hours;
  $working_times->project_time += $offset->project_time;
  $working_times->overtime_reduce += $offset->overtime_reduce;  //this overtime reduce value will not be substracted again, so we think that the user has already substracter from overtime on input
}

/**
* Books the given holidays to a users working times in the given date. First we try to finde some available "old" holiday in the year before if it is not more than the holidays expiration months away. We book it there and return the rest holiday as result of the function
*/
function _erpal_employee_helper_book_user_holidays($uid, $holidays, $month, $year, $working_times_entity_month) {
  
  //get working_times from year before and see if the available holidays there are not yet expired.
  $working_times = working_times_load_by_user('year', $uid, $year-1);
  if (!count($working_times)) {
    //no rest holidays found in the last year
    return $holidays;
  }
  
  $working_times = array_shift($working_times);

  //because in the previous run, we already substracted the holidays from the rest holidays of the last year if there were some. So we add them here again, otherwise, they will be substracted again, which will result in wrong data
  $working_times->holidays_available += $working_times_entity_month->holidays_used_from_before;  
  
  $holidays_available_till = $working_times->holidays_available_till;

  $current_date = erpal_lib_date_ldom($month, $year);  //take the last date of the given month
  $current_date_unix = strtotime($current_date);
  if ($current_date_unix > $holidays_available_till)
    return $holidays;

  //here we have some rest holiday. Book it, save it and return the difference
  $holidays_available = $working_times->holidays_available;
  if ($holidays_available >= $holidays) {
    $holidays_available = $holidays_available - $holidays;
    $rest_days = 0;  //everything could be booked to this working_times entity
  } else {
    $rest_days = $holidays - $holidays_available;
    $holidays_available = 0;   
  }

  //now book the holidays available to the last years working_times entity  
  $working_times->holidays_available = $holidays_available;
  $working_times->save();

  return $rest_days;  
}

/**
* Returns the available holidays for a user in the given month. So we return just the holidays_available of the working_times entity from the month / year.
* if there is no entity, we take the total holidays of the user and calculate the available holidays relative to the valid_since date of the contract if this date is int the same year as the given year. Otherwise, if the valid_since year of the contract is not in the current year, we return the full holidays
* @param $valid_till_unix a unix_timestamp that sets a time until the holidays returned should not expire. This is the offset when we fetch the contract data and calculate the holidays from contract
*/
function _erpal_employee_get_holidays_available($uid, $year, $month, $type, $valid_till_unix=false) {
  $working_times = working_times_load_by_user($type, $uid, $year, $month);
  if (count($working_times)) {
    
    //there is a working_times entity
    $working_times = array_shift($working_times);
    //we only return the available holidays if they are not expired (holidays_available_till)
    if ($valid_till_unix) {
      if ($working_times->holidays_available_till < $valid_till_unix)
        return 0; //holidays already expired!
    }
    return $working_times->holidays_available;
  } else {
    //get the contract and take the holidays relative to the current month because holidays are for one complete year, but if users contract started in the middle of the year, he only should have a part (half in this case) of that total holidays
    $contract_data = _erpal_profile_helper_get_current_contract($uid, array(), $valid_till_unix, 'full_employee');
    $total_holidays = $contract_data['holiday_per_year'];

    $valid_since_unix = $contract_data['valid_since'];
    $valid_since_str = date('Y-m-d', $valid_since_unix);
    //check if this is the month where the users contract started
    if (date('Y', $valid_since_unix) == date('Y', $valid_till_unix)) {
      $valid_since_day_in_year = date('z', $valid_since_unix);      
      $available_holidays = ceil(($total_holidays / 365) * (365 - $valid_since_day_in_year)); //rounding (ceil) with positive effekt to the employee
      return $available_holidays;
    } else {
      //not the year where the users contract started, so return all holidays
      return $total_holidays;
    }
  }
  
  return 0;
}

/**
* Returns the hours a user booked to reduce his over hours, for example because he got them paid
* They may be on holiday and so on, because the total amount will jus be substracted from his monthly hours, no matter if he was an employee the date is on a holiday, not on a general working time and so on.
*/
function _erpal_employee_helper_get_reduce_hours($uid, $year, $month) {
  $monthNull = str_pad($month, 2 ,'0', STR_PAD_LEFT);
	$ldom = erpal_lib_date_ldom($month, $year);  //last day of month
	$range_from = "$year-$monthNull-01 00:00:00";
	$range_till = "$ldom 23:59:59";
  $date_till_unix = strtotime($range_till);
  $date_from_unix = strtotime($range_from);
  
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_working_time')
    ->propertyCondition('status', 1)
    ->propertyCondition('uid', $uid)
    ->fieldCondition('field_date_time', 'value', $date_from_unix, '>=')
    ->fieldCondition('field_date_time', 'value', $date_till_unix, '<=')
    ->fieldCondition('field_working_time_type', 'value', 'reduce_hours')    
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $timetracking_nodes = array();
  if (isset($result['node'])) {
    $timetracking_nids = array_keys($result['node']);
    $timetracking_nodes = entity_load('node', $timetracking_nids);
  }
  
  //get only the timetrackings that the user booked as employee!
  $timetracking_dates = _erpal_calendar_helper_get_dates_in_range($year, $month, $timetracking_nodes, 'field_date_time', 'field_date_time', array(LANGUAGE_NONE, 0, 'value'), array(LANGUAGE_NONE, 0, 'value'));
  
  //get the sum of all timetrackings (duration, not billing duration)
  $total_duration = 0;
  foreach ($timetracking_nodes as $node) {
    //take only these that are in timetracking_dates!
    $timetracking_date = $node->field_date_time[LANGUAGE_NONE][0]['value'];
    $timetracking_date_str = date('Y-m-d', $timetracking_date);
    $is_valid_date = false;
    foreach ($timetracking_dates as $date) {
      $date_str = date('Y-m-d', $date);    
      if ($date_str == $timetracking_date_str) {        
        $is_valid_date = true;
        break;
      }
    }
    
    if ($is_valid_date) {
      $duration = $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
      $total_duration += $duration;
    }
  }
  
  return $total_duration;

}

/**
* Returns the sum in hours on which a user worked on projects (timetracking nodes on tasks)
*/
function _erpal_employee_helper_get_user_project_time($uid, $year, $month) {
  $monthNull = str_pad($month, 2 ,'0', STR_PAD_LEFT);
	$ldom = erpal_lib_date_ldom($month, $year);  //last day of month
	$range_from = "$year-$monthNull-01 00:00:00";
	$range_till = "$ldom 23:59:59";
  $date_till_unix = strtotime($range_till);
  $date_from_unix = strtotime($range_from);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_timetracking')
    ->propertyCondition('uid', $uid)
    ->fieldCondition('field_date_time', 'value', $date_from_unix, '>=')
    ->fieldCondition('field_date_time', 'value', $date_till_unix, '<=')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $timetracking_nodes = array();
  if (isset($result['node'])) {
    $timetracking_nids = array_keys($result['node']);
    $timetracking_nodes = entity_load('node', $timetracking_nids);
  }
  
  //get only the timetrackings that the user booked as employee!
  $timetracking_dates = _erpal_calendar_helper_get_dates_in_range($year, $month, $timetracking_nodes, 'field_date_time', 'field_date_time', array(LANGUAGE_NONE, 0, 'value'), array(LANGUAGE_NONE, 0, 'value'));
  
  //get the sum of all timetrackings (duration, not billing duration)
  $total_duration = 0;
  foreach ($timetracking_nodes as $node) {
    //take only these that are in timetracking_dates!
    $timetracking_date = $node->field_date_time[LANGUAGE_NONE][0]['value'];
    $timetracking_date_str = date('Y-m-d', $timetracking_date);
    $is_valid_date = false;
    foreach ($timetracking_dates as $date) {
      $date_str = date('Y-m-d', $date);    
      if ($date_str == $timetracking_date_str) {        
        $is_valid_date = true;
        break;
      }
    }
    
    if ($is_valid_date) {
      $duration = $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
      $total_duration += $duration;
    }
  }
  
  return $total_duration;
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
        
    if ($is_ill_day) {   
      continue;
    }
    
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
	$ldom = erpal_lib_date_ldom($month, $year);  //last day of month
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

  //calculate the time in hours the user has to work according to his contract profile in this month but not on holidays
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
	$ldom = erpal_lib_date_ldom($month, $year);  //last day of month
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