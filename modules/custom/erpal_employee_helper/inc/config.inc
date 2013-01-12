<?php

/**
* Returns all the menu path for config of employee feature
*/
function _erpal_employee_helper_config_menu(){
  
  $items['admin/erpal/employee'] = array(
    'title' => 'ERPAL Employee',
    'page callback' => '_erpal_employee_helper_config_basic',    
    'access arguments' => array('config erpal employee'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL employee Feature
*/
function _erpal_employee_helper_config_basic(){
  $form = drupal_get_form('erpal_employee_helper_config_form');

  return $form;
}

/**
* Alter the config form of calendar module to set tags for working time node
*/
function _erpal_employee_helper_alter_calendar_config_form(&$form, &$form_state) {
  
  $types = _erpal_employee_helper_get_working_time_types_date_item_creating();
  foreach ($types as $type) {
    $form['date_item_tags_special']['erpal_employee_working_time_'.$type] = array(
      '#type' => 'textfield',
      '#title' => t('Tags for working time nodes of type "%type"', array('%type' => $type)),
      '#description' => t('This tag will be added as category to date items for nodes of type "%type"', array('%type' => $type)),
      '#default_value' => _erpal_employee_helper_field_tag_working_time_type($type),
    );
  }
  
  $form['submit']['#submit'][] = '_erpal_empoyee_helper_calendar_config_form_submit';
}

/**
* Return all types that should set a tag and create a date_item entity
*/
function _erpal_employee_helper_get_working_time_types_date_item_creating() {
  return array('holiday', 'day_off', 'ill');
}

/**
* Submit handler of erpal calendar form altered by this module
*/
function _erpal_empoyee_helper_calendar_config_form_submit($form, $form_state) {
  $types = _erpal_employee_helper_get_working_time_types_date_item_creating();
  $values = $form_state['values'];
  foreach ($types as $type) {
    $variable_name = 'erpal_employee_working_time_'.$type;
    variable_set($variable_name, $values['date_item_tags_special'][$variable_name]);
  }
  
}

/**
* Form to show all settings to configure ERPAL employee
*/
function erpal_employee_helper_config_form($form, &$form_state){

  $form = array();
  
  $form['erpal_employee_holiday_month_transfer'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of month to transfer holiday days'),
    '#description' => t('The number of month rest holiday days are are transfered to the next year.'),
    '#default_value' => _erpal_employee_get_holiday_month_transfer(),
  );
  
  $week_days = array(
    1 => t('Monday'),
    2 => t('Tuesday'),
    3 => t('Wednesday'),
    4 => t('Thursday'),
    5 => t('Friday'),
    6 => t('Saturday'),
    7 => t('Sunday'),
  ); //according to date('w') 0 is sunday
  
  $form['erpal_employee_general_working_days'] = array(
    '#title' => t('General working days'),
    '#type' => 'checkboxes',
    '#options' => $week_days,
    '#default_value' => _erpal_employee_helper_general_working_days(),
    '#description' => t('These weekdays are working days in general, according to the country or the individual company'),
  );
  
  $form['employee_reports_only_once_a_day'] = array(
    '#type' => 'checkbox',
    '#title' => t('Run employe times reports only once a day'),
    '#default_value' => _erpal_employee_helper_employee_report_run_only_once_a_day(),
    '#description' => t('If this is not checked, the employee reports will run with every cron run.'),
  );

  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => array('_erpal_employee_helper_config_form_submit'),
  );
  
  return $form;
}

/**
* Returns if the employee times report should run only once a day or with every cron run
*/
function _erpal_employee_helper_employee_report_run_only_once_a_day() {
  return variable_get('employee_reports_only_once_a_day', true);
}

/**
* returns the general working days of a week
*/
function _erpal_employee_helper_general_working_days() {
  $days = unserialize(variable_get('erpal_emplyee_general_working_days', serialize(array(1=>1,2=>2,3=>3,4=>4,5=>5,6=>0,0=>0))));
  
  //only values that are not 0, cause 0 is sunday!
  $ret = array();
  foreach ($days as $key => $day) {
    if ($key == $day && $key && $day) {
      $ret[$key] = $day;
    }
  }

  return $ret;
}

/**
* Submit handler of employee config form
*/
function _erpal_employee_helper_config_form_submit($form, $form_state) {
  $values = $form_state['values'];
  
  $erpal_employee_holiday_month_transfer = $values['erpal_employee_holiday_month_transfer'];
  variable_set('erpal_employee_holiday_month_transfer', intval($erpal_employee_holiday_month_transfer));
  
  //set general working days
  $general_working_days = $values['erpal_employee_general_working_days'];
  $general_working_days = array_unique(($general_working_days));

  variable_set('erpal_emplyee_general_working_days', serialize($general_working_days));
  
  $employee_reports_only_once_a_day = $values['employee_reports_only_once_a_day'];
  variable_set('employee_reports_only_once_a_day', $employee_reports_only_once_a_day);
}

/**
* Returns the amount of months that "not used" holidays will be transfered into the next year.
*/
function _erpal_employee_get_holiday_month_transfer() {
  return variable_get('erpal_employee_holiday_month_transfer', 3);
}