<?php

/**
* @file provides all functions to calculate working_times entities from employee working time nodes.
*/

/**
* Calculates all entities for month and year employee reporting
*/
function _erpal_employee_helper_calculate_working_times() {
  
  //check in variables if the last run of this function was today, if so, return, otherwise process
  $last_run = _erpal_employee_helper_get_last_run();
  if (date('Y-m-d', $last_run) == date('Y-m-d'))
    return;
  
  
  //get all user IDs that are employees
  
  
  //loop through all users
  
  //get the contract data for each user with data that is valid for the current date.
  
  //get all invalid datasets (dirty==1) and get the one with the lowest year and month.
  
  //now loop through years and month till the current date and recalculate them. If the year changes recalculate the year from the working_times month entites in this year
 
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
* Returns when the last calculation was, because this may be time consuming and so only processed once a day
*/
function _erpal_employee_helper_get_last_run() {
  variable_get('erpal_employee_report_last_run', false);
}

/**
* Sets the last run of employee report calculation
*/
function _erpal_employee_helper_set_last_run() {
  variable_set('erpal_employee_report_last_run', time());
}