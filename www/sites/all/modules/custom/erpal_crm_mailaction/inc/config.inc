<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */

/**
* Returns all the menu path for config of invoice feature
*/
function _erpal_crm_mailaction_config_menu(){
  
  $items = array ();
  
  $items['admin/erpal/crm-mailaction'] = array(
    'title' => 'ERPAL crm mail action',
    'page callback' => '_erpal_crm_mailaction_config_basic',    
    'access arguments' => array('config erpal crm mailaction'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_crm_mailaction_config_basic(){

  $form = drupal_get_form('_erpal_crm_mailaction_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL mail action module.
*/
function _erpal_crm_mailaction_config_form($form, &$form_state){

  erpal_crm_mailaction_cron ();
  
  $form = array();

 
  $form['erpal_crm_mailaction'] = array (
    '#type'  => 'item',
    '#tree'  => TRUE
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX] = array (
    '#type'   => 'fieldset',
    '#title'  => t(ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX),
    '#tree'	  => TRUE
  );
 
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['host'] = array (
    '#required'			  => TRUE,
    '#type'     	    => 'textfield',
    '#title'	        => t('Host'),
    '#default_value'	=> _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'host', 'localhost'),
    '#size'				    => 20
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['port'] = array (
    '#type'         	=> 'textfield',
    '#required'			  => TRUE,
    '#title'	        => t('Port'),
    '#default_value'	=> _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'port', '143'),
    '#size'				    => 5
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['inbox'] = array (
    '#type'           => 'textfield',
    '#title'	        => t('Inbox folder name'),
    '#default_value'  => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'name', 'INBOX'),
    '#size'			      => 20
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS] = array (
    '#type'            => 'fieldset',
    '#title'	         => t('Mailbox settings'),
    '#tree'            => TRUE,
    '#collapsible'     => TRUE,
    '#collapsed'       => TRUE
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS]['tls'] = array (
    '#type'         => 'radios',
    '#title'    	  => t('Transport Layer Security'),
    '#options'		  => array(
      '/tls'   => t('TLS'),
      '/notls' => t('No TLS'),
    ),
    '#default_value' => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 'tls', '/notls'),
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS]['protocol'] = array (
    '#type'         => 'radios',
    '#title'		    => t('Protocol'),
    '#options'		  => array(
      '/imap' => t('IMAP'),
      '/pop3' => t('POP3'),
    ),
    '#default_value' => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 'protocol', '/imap'),
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS]['ssl'] = array (
    '#type'           => 'radios',
    '#title'		      => t('Secure Sockets Layer'),
    '#options'	      => array(
      ''     => t('No SSL'),
      '/ssl' => t('SSL'),
    ),
    '#default_value'	=> _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 'ssl', ''),
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS]['certificate'] = array (
    '#type'           => 'radios',
    '#title'          => t('Certificate'),
    '#options'	      => array(
      '/novalidate-cert' => t('Don\'t validate certificate'),
      '/validate-cert'   => t('Validate certificate'),
    ),
    '#default_value'	=> _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX_SETTINGS, 'certificate', '/novalidate-cert'),
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['username'] = array (
    '#required'		  => TRUE,
    '#type'         => 'textfield',
    '#title'	      => t('Username'),
    '#default_value'  => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX, 'username', ''),
    '#size'	          => 20
  );

  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['password'] = array (
    '#type'          => 'password_confirm',
    '#size'	         => 20,
    '#description'	 => t('Leave blank if you want to use the old passwort setting.'),
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS] = array (
    '#type'            => 'fieldset',
    '#title'	         => t('Import settings'),
    '#tree'            => TRUE,
    '#collapsible'     => TRUE,
    '#collapsed'       => TRUE
  );
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS]['publish_imports'] = array (
    '#type'            => 'checkbox',
    '#title'	         => t('Publish imported content'),
    '#default_value'	 => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 'publish_imports', FALSE),
  ); 
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS]['publish_attachments'] = array (
    '#type'            => 'checkbox',
    '#title'	         => t('Publish imported attachments'),
    '#default_value'	 => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 'publish_attachments', FALSE),
  ); 
  
  $form['erpal_crm_mailaction'][ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS]['create_contact_for_unknown_user'] = array (
    '#type'            => 'checkbox',
    '#title'	         => t('Create contacts for unknown users. (NOT SECURE!)'),
    '#default_value'	 => _erpal_crm_mailaction_get_settings (ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 'create_contact_for_unknown_user', FALSE),
  ); 
 
  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save')
  );
  
  return $form;
}

/*
 * The validator callback of the config form.
 */
function _erpal_crm_mailaction_config_form_validate($form, &$form_state) {
 
  $values   = (object)$form_state['values']['erpal_crm_mailaction'];
  $mailBox  = (object)$values->mailbox;
  
  if (intval ($mailBox->port) == 0) {
    form_set_error ('mailbox[port]', t('Please specify a valid port number (>0).'));
  }   
  
  module_load_include ('inc', 'erpal_crm_mailaction', 'inc/ImapFetcher/ImapFetcher.class');
  
  if (! erpal_crm_mailaction\ImapFetcher::checkHostAccessibility($mailBox->host, $mailBox->port)) {
     form_set_error ('mailbox[host]', t('The given host name is not accessible.'));
  }else{
    drupal_set_message (t('Host is accessible on given port.'));
  }
  
  return;
}

/*
 * The submit callback of the config form.
 */
function _erpal_crm_mailaction_config_form_submit($form, &$form_state) {
  
  $settings = variable_get ('erpal_crm_mailaction', array ());  
  $values   = $form_state['values']['erpal_crm_mailaction'];

  // If password wasn't set, use old password settings.
  if (empty ($values[ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['password'])) {
    $values[ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['password'] = $settings[ERPAL_CRM_MAILACTION_CONFIG_GROUP_MAILBOX]['password'];
  }  

  variable_set ('erpal_crm_mailaction', $values);
  
  drupal_set_message (t('Settings successfuly saved.'));
  
  return;
}
