<?php
/**
 * @file
 * Contains Batch API callbacks used during installation.
 */
 
include('erpal_germany_taxonomy.inc');
include('erpal_germany_relations.inc');

/**
 * BatchAPI callback
 * reverts all features
 */ 
function _erpal_germany_revert_features(&$context){
  $context['message'] = st('Reverted all features');
  features_revert();
}
 
/**
 * BatchAPI callback
 * rebuilds content access 
 */
function _erpal_germany_rebuild_content_access(&$context){
  $context['message'] = st('Rebuilt content access permissions');
  node_access_rebuild(); 
}

/**
 * BatchAPI callback
 * creates Taxonomy
 */
function _erpal_germany_create_taxonomy(&$context){
  $context['message'] = st('Created taxonomy terms');
  erpal_germany_create_taxonomy();
}

/**
 * BatchAPI callback
 */
function _erpal_germany_create_relations(&$context){
  $context['message'] = st('Created relation types');
  erpal_germany_create_relations();
}

/**
 * BatchAPI callback
 * 
 */
function _erpal_germany_various_settings(&$context){
  $context['message'] = st('Configured ERPAL');
  variable_set('date_format_erpal_date', 'd.m.Y - H:i');
  variable_set('date_format_erpal_date_time', 'd.m.Y - H:i');  
  variable_set('erpal_docs_doc_file_extensions', 'txt pdf doc docx xls xlsx csv bmp jpg jpeg gif png mm ppt pptx bmml');
}

/**
 * BatchAPI callback
 * configures erpal projects
 */
function _erpal_germany_projects_config(&$context){
  $context['message'] = st('Configured ERPAL-Projects');
  
  // Set Erpal-Project notification message
  $erpal_task_update_subject = 'ERPAL - Notification: [erpal_project_notifications:content_label]';
  $erpal_task_update_message = 
    'Hello,'
    . "\r\n"
    . "\r\n"
    . 'New content available: [erpal_project_notifications:content_label] -> [erpal_project_notifications:content_url]'
    . "\r\n"
    . "\r\n"
    . 'Best regards'
    . "\r\n"
    . "\r\n"
    . 'ERPAL';
  variable_set('erpal_task_update_subject', $erpal_task_update_subject);
  variable_set('erpal_task_update_message', $erpal_task_update_message);
}


/**
 * BatchAPI callback
 * configures erpal-calendar
 */
function _erpal_germany_calendar_config(&$context){ 
  $context['message'] = st('Configured ERPAL-Calendar');
  _erpal_calendar_helper_field_tag('node', 'erpal_crm_activity', 'field_next_contact', 'crm');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_date', 'contact  date');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_cancelation_period', 'contact customer');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_cancelation_period_con', 'contact agency');
  _erpal_calendar_helper_field_tag('node', 'erpal_date', 'field_date_repeat', 'appointment');  
}
 

/**
 * BatchAPI callback
 * configures erpal invoice
 */
function _erpal_germany_invoice_config(&$context){
  $context['message'] = st('Configured ERPAL-Invoice');
  //set default vat-rate for erpal invoice
  $vatRates = '7#7%' . "\r\n" . '19#19%' . "\r\n" . '0#0%#Steuerbefreiung nach §3a Abs. 2 UstG.';
  variable_set('erpal_invoice_vat_rates_string', $vatRates);
  variable_set('erpal_invoice_default_vat_rate', '19'); 
  
  $manualNote = 'Thanks for your order. Please pay the amount of [erpal_invoice:total]'
    . '[erpal_invoice:currency] till [erpal_invoice:invoice_date].'
    . "\r\n" 
    . "\r\n" 
    . 'Best regards';
  variable_set('erpal_invoice_manuall_notes', $manualNote);
  $skontoText = '[erpal_invoice_skonto:skonto_rate]% skonto if you pay within [erpal_invoice_skonto:skonto_period] days.';
  variable_set('erpal_invoice_skonto_text', $skontoText);  
  
}