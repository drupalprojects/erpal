<?php
/**
 * @file
 * Contains Batch API callbacks used during installation.
 */
 

require_once('erpal_taxonomy.inc');
require_once('erpal_relations.inc');
require_once('erpal_roles_permissions.inc');


/**
 * BatchAPI callback
 * enables the display of warnings in erpal_basic_helper
 */
function _erpal_config_finish(&$context){
  $context['message'] = st('Erpal installation completed');
  variable_set('erpal_basic_helper_display_warnings', TRUE);
}


/**
 * BatchAPI callback
 * configures panels and panels everywhere
 */
function _erpal_configure_layout(&$context){
  $context['message'] = st('Configured Panels layout');
  variable_set('site_frontpage', 'user/login');
  variable_set('panels_everywhere_site_template_enabled', TRUE);
  variable_set('front_page_enable', TRUE);
  
  ///set front page dashboard of front page module
  //get rid for authenticated user
  $query = db_select('role', 'r')
    ->fields('r', array('rid'))
    ->condition('r.name', 'authenticated user')
    ->execute();
  $rid = $query->fetchAssoc();
  $rid = $rid['rid'];
             
  db_merge('front_page')
    ->key(array('rid' => $rid))
    ->fields(array(
      'mode' => 'alias',
      'data' => 'dashboard',
      'filter_format' => '',
    ))
    ->execute();
}

/**
 * BatchAPI callback
 * configures the pathauto module
 */
function _erpal_configure_pathauto(&$context){
    
  //From erpal basic feature
  variable_set('pathauto_node_erpal_contact_pattern', 'crm/contact/[node:nid]'); 
  variable_set('pathauto_taxonomy_term_address_types_pattern', 'crm/address-type/[term:name]');
  variable_set('pathauto_taxonomy_term_company_relation_tags_pattern','crm/company-relation/[term:name]');
  variable_set('pathauto_taxonomy_term_contact_tags_pattern','crm/contact-type/[term:name]');
  variable_set('pathauto_taxonomy_term_number_types_pattern','crm/number-type/[term:name]');
  
  //From erpal book feature
  variable_set('pathauto_node_erpal_book_page_pattern', 'books/book/book-page/[node:nid]');
  variable_set('pathauto_node_erpal_book_pattern', 'books/book/[node:nid]');
  variable_set('pathauto_taxonomy_term_book_tags_pattern', 'books/book-term/[term:name]');
  
  // from erpal contract feature
  variable_set('pathauto_node_erpal_contract_pattern', 'contracts/contract/[node:nid]');
  variable_set('pathauto_taxonomy_term_contract_types_pattern', 'contracts/contract-type/[term:name]');
  
  // from crm feature
  variable_set('pathauto_node_erpal_crm_activity_pattern', 'crm/activity/[node:nid]');
  variable_set('pathauto_taxonomy_term_activity_status_terms_pattern', 'crm/status/[term:name]');
  
  // from erpal docs feature
  variable_set('pathauto_node_erpal_file_pattern', 'documents/file/[node:nid]');
  variable_set('pathauto_taxonomy_term_file_tags_pattern', 'documents/file-type/[term:name]');
  
  // from erpal invoice feature
  variable_set('pathauto_node_erpal_invoice_pattern', 'invoices/invoice/[node:nid]');
  
  // from erpal project basic feature
  variable_set('pathauto_node_erpal_project_pattern', 'projects/project/[node:nid]');
  variable_set('pathauto_node_erpal_task_pattern', 'projects/project/task/[node:nid]');
  variable_set('pathauto_node_erpal_timetracking_pattern', 'projects/project/timetracking/[node:nid]');
  variable_set('pathauto_taxonomy_term_priority_terms_pattern', 'projects/priority/[term:name]');
  variable_set('pathauto_taxonomy_term_project_role_tags_pattern', 'projects/project-role/[term:name]');
  variable_set('pathauto_taxonomy_term_project_status_terms_pattern ', 'projects/project-status/[term:name]');
  variable_set('pathauto_taxonomy_term_project_tags_pattern ', 'projects/project-terms/[term:name]');
  variable_set('pathauto_taxonomy_term_task_status_terms_pattern ', 'projects/task-status/[term:name]');
  variable_set('pathauto_taxonomy_term_task_type_terms_pattern', 'projects/task-type/[term:name]');

  $context['message'] = st('Configured Pathouto');
}


/**
 * BatchAPI callback
 * creates userroles and permissions
 * 
 */
function _erpal_create_roles_and_permissions(&$context){
  $context['message'] = st('Created user-roles and preconfigured permissions');
  erpal_save_roles_and_configure_permissions();
}

/**
 * BatchAPI callback
 * reverts all features
 */ 
function _erpal_revert_features(&$context){
  $context['message'] = st('Reverted all features');
  features_revert();
}
 
/**
 * BatchAPI callback
 * rebuilds content access 
 */
function _erpal_rebuild_content_access(&$context){
  $context['message'] = st('Rebuilt content access permissions');
  node_access_rebuild(); 
}

/**
 * BatchAPI callback
 * creates Taxonomy
 */
function _erpal_create_taxonomy(&$context){
  $context['message'] = st('Created taxonomy terms');
  erpal_create_taxonomy();
}

/**
 * BatchAPI callback
 */
function _erpal_create_relations(&$context){
  $context['message'] = st('Created relation types');
  erpal_create_relations();
}

/**
 * BatchAPI callback
 * 
 */
function _erpal_various_settings(&$context){
  $context['message'] = st('Configured ERPAL');
  
  module_load_include('install', 'erpal_basic_helper', 'erpal_basic_helper');
  
  //insert date and time format if they dont exist
  _erpal_basic_helper_ensure_format('d.m.Y');
  _erpal_basic_helper_ensure_format('d.m.Y - H:i');
  
  //now add these formats to the format types that we need
  _erpal_basic_helper_ensure_format_type('ERPAL date', 'erpal_date', 'd.m.Y');
  _erpal_basic_helper_ensure_format_type('ERPAL date time', 'erpal_date_time', 'd.m.Y - H:i');
  
  variable_set('date_format_erpal_date', 'd.m.Y');
  variable_set('date_format_erpal_date_time', 'd.m.Y - H:i');
  
  variable_set('erpal_docs_doc_file_extensions', 'txt pdf doc docx xls xlsx csv bmp jpg jpeg gif png mm ppt pptx bmml');
}

/**
 * BatchAPI callback
 * configures erpal projects
 */
function _erpal_projects_config(&$context){
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
function _erpal_calendar_config(&$context){ 
  $context['message'] = st('Configured ERPAL-Calendar');
  module_load_include('inc', 'erpal_calendar_helper', 'inc/config');
  _erpal_calendar_helper_field_tag('node', 'erpal_crm_activity', 'field_next_contact', 'crm');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_date', 'contact  date');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_cancelation_period', 'contact customer');
  _erpal_calendar_helper_field_tag('node', 'erpal_contract', 'field_cancelation_period_con', 'contact agency');
  _erpal_calendar_helper_field_tag('node', 'erpal_date', 'field_date_repeat', 'appointment');  
  _erpal_calendar_helper_field_tag('node', 'erpal_project', 'field_date', 'project');
  _erpal_calendar_helper_field_tag('node', 'erpal_task', 'field_date', 'task');
}
 

/**
 * BatchAPI callback
 * configures erpal invoice
 */
function _erpal_invoice_config(&$context){
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
