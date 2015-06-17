<?php

/**
* @file date time helper functions for ERPAL
*/

/**
* Validates that a given date field at an entity starts and ends at the same date
*/
function erpal_lib_date_field_validate_one_day($entity, $field_name, &$form_state) {
  $date_field = isset($entity->{$field_name}[LANGUAGE_NONE][0]) ? $entity->{$field_name}[LANGUAGE_NONE][0] : false;
  if ($date_field) {
    $date_unix_from = erpal_lib_as_unix_timestamp($date_field['value']);
    $date_unix_till = erpal_lib_as_unix_timestamp($date_field['value2']);
    
    if ($date_unix_from != $date_unix_till) {
      $date_from_str = date('Ymd', $date_unix_from);
      $date_till_str = date('Ymd', $date_unix_till);
      
      if ($date_from_str != $date_till_str) {
        return false;
      }
    }
  }
  
  return true;
}

/**
* Return the last day of a given month in format Y-m-d
*/
function erpal_lib_date_ldom($month = '', $year = '') {
   if (empty($month)) {
    $month = date('m');
   }
   if (empty($year)) {
    $year = date('Y');
   }
   $result = strtotime("{$year}-{$month}-01");
   $result = strtotime('-1 second', strtotime('+1 month', $result));
   return date('Y-m-d', $result);
}

/**
* Return the date always as unix timestamp. But that depends on the field type, so may be convert it
*/
function erpal_lib_as_unix_timestamp($value, $tz_string=NULL) {

  if (!$value)
    return false;

  if(is_numeric($value) && (int)$value == $value) {
    return $value; //then it is already a unix timestamp
  }
  
  if ($tz_string)
    $tz = new DateTimeZone($tz_string);
  else
    $tz = date_default_timezone_object();
    
  $date = new DateObject($value, $tz);
  $date->setTimezone($tz);
  $date_arr = $date->toArray();
  //now convert as unix date!
  $unix_time = mktime($date_arr['hour'], $date_arr['minute'], $date_arr['second'], $date_arr['month'], $date_arr['day'], $date_arr['year']);
  return $unix_time;
}


/**
* So we can make the user change the date format by changing this variable 
*/
function erpal_lib_get_date_format($time = true){
  if (module_exists('erpal_basic_helper')) {
    if (!$time)
      return _erpal_basic_helper_date_format_date_only();
    else
      return _erpal_basic_helper_date_format_date_time();
  } else {  
    if (!$time)
      return variable_get('date_format_short_date_only', 'Y/m/d');
    else
      return variable_get('date_format_short_date_time', 'Y/m/d H:i');
  }
}

/**
 * Checks time values in 'hh:mm', 'hh,mm' and 'hh.mm,' format and convert it into
 * decimal 'hh.hh' representation
 * @param string $duration time value
 * @param string $field form field name. If set form_set_error for this field
 * appears
 * @return string converted duration or origin $duration is it doesn't match
 * time formats
 */
function erpal_lib_time_convert($duration, $field = '') {
  // remove spaces
  if (!$duration)
    return $duration;
    
  $duration = preg_replace('/\s+/', '', $duration);

  // validate string format
  // format: "hh" , "hh." , "hh.hh"
  if (preg_match('/^\d+(\.)?\d*$/', $duration)) {
    return $duration;
  }
  
  // format: hh,
  elseif (preg_match('/^\d+,$/', $duration)) {
    $duration = str_replace(',', '', $duration);
    return;
  }
  // format: hh,hh
  elseif (preg_match('/^\d+,\d+$/', $duration)) {
    $duration = str_replace(',', '.', $duration);
  }

  // format: hh:mm
  elseif (preg_match('/^\d+:\d{2}$/', $duration)) {
    $time = explode(':', $duration);
    $hours = $time[0];
    $minutes = $time[1];
    if ($minutes < 60) {
      $hours_decimal = round($time[1] * 100 / 60);
      if ($hours_decimal < 10) {
        $hours_decimal = '0' . $hours_decimal;
      }
      $duration = $hours . '.' . $hours_decimal;
    } else {
      if ($field) {
        form_set_error($field, t('You cannot write more tham 59 minutes in the "hh:mm" format.'));
      }
    }
    return $duration;
  } else {
    if ($field) {
      form_set_error($field, t('Only time in format "hh:mm", "hh,hh" and "hh.hh" is allowed.'));
    }
    
  }
  return $duration;
}