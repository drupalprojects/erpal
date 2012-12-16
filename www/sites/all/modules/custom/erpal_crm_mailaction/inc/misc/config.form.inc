<?php
/**
 * @author     Marc Sven Kleinboehl
 * @created   01/14/2012
 * @copyright  2012 © Bright Solutions GmbH 
 */

namespace erpal_crm_mailaction\misc\config;

use \erpal_crm_mailaction\misc\Settings as Settings;
use \erpal_crm_mailaction\imap\ImapFetcher as ImapFetcher;

/**
* Form to show all settings to configure ERPAL mail action module.
*/
function form($form, &$form_state){

  $form = array();
 
  $form['erpal_crm_mailaction'] = array (
    '#type'  => 'item',
    '#tree'  => TRUE
  );
  
  _form_section_mailbox_settings ($form, $form_state);
  _form_section_import_settings ($form, $form_state);
  _form_section_referencing_settings($form, $form_state);
  _form_section_test ($form, $form_state);

  $form['#validate'] = array('erpal_crm_mailaction\misc\config\validate');
 
  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save'),
    '#submit' => array ('erpal_crm_mailaction\misc\config\submit')
  );
  
  return $form;
}

/**
 * The validator callback of the config form.
 */
function validate($form, &$form_state) {
 
  $values   = (object)$form_state['values']['erpal_crm_mailaction'];
  $mailBox  = (object)$values->mailbox_settings;
  
  if (intval ($mailBox->port) <= 0) {
    form_set_error ('mailbox[port]', t('Please specify a valid port number (>0).'));
  }   
  
  module_load_include ('inc', 'erpal_crm_mailaction', 'inc/ImapFetcher/ImapFetcher.class');
  
  if (! ImapFetcher::checkHostAccessibility($mailBox->host, $mailBox->port)) {
     form_set_error ('mailbox[host]', t('The given host name is not accessible.'));
  }else{
    drupal_set_message (t('Host is accessible on given port.'));
  }
  
  return;
}

/**
 * The submit callback of the config form.
 */
function submit($form, &$form_state) {
  
  $settings = variable_get ('erpal_crm_mailaction', array ());  
  $values   = $form_state['values']['erpal_crm_mailaction'];

  // If password wasn't set, use old password settings.
  if (empty ($values['mailbox_settings']['password'])) {
    $values['mailbox_settings']['password'] = $settings['mailbox_settings']['password'];
  }  

  $referencing_settings_content_types              = $values['referencing_settings']['content_types'];
  $values['referencing_settings']['content_types'] = array (); 
  foreach ($referencing_settings_content_types as $referencing_settings_content_type) { 
    
    if (! is_numeric($referencing_settings_content_type)) {
      $values['referencing_settings']['content_types'][$referencing_settings_content_type] = $referencing_settings_content_type;
    }
  }
 
  variable_set ('erpal_crm_mailaction', $values);
  
  drupal_set_message (t('Settings successfuly saved.'));
  
  return;
}

/**
 * Creates the "Mailbox settings" section for the config form.
 * 
 * @param array_ref   $form           The form render array.
 * @param array_ref   $form_state     The form state array.
 */
function _form_section_mailbox_settings (&$form, &$form_state) {
 
  $form['erpal_crm_mailaction']['mailbox_settings'] = array (
    '#type'   => 'fieldset',
    '#title'  => t('Mailbox settings'),
    '#tree'   => TRUE
  );
 
  $form['erpal_crm_mailaction']['mailbox_settings']['host'] = array (
    '#required'       => TRUE,
    '#type'           => 'textfield',
    '#title'          => t('Host'),
    '#default_value'  => Settings::get ('mailbox_settings', 'host', 'localhost'),
    '#size'           => 20
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['port'] = array (
    '#type'           => 'textfield',
    '#required'       => TRUE,
    '#title'          => t('Port'),
    '#default_value'  => Settings::get ('mailbox_settings', 'port', '143'),
    '#size'           => 5
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['inbox'] = array (
    '#type'           => 'textfield',
    '#title'          => t('Inbox folder name'),
    '#default_value'  => Settings::get ('mailbox_settings', 'name', 'INBOX'),
    '#size'           => 20
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['tls'] = array (
    '#type'         => 'radios',
    '#title'        => t('Transport Layer Security'),
    '#options'      => array(
      '/tls'   => t('TLS'),
      '/notls' => t('No TLS'),
    ),
    '#default_value' => Settings::get ('mailbox_settings', 'tls', '/notls'),
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['protocol'] = array (
    '#type'         => 'radios',
    '#title'        => t('Protocol'),
    '#options'      => array(
      '/imap' => t('IMAP'),
      '/pop3' => t('POP3'),
    ),
    '#default_value' => Settings::get ('mailbox_settings', 'protocol', '/imap'),
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['ssl'] = array (
    '#type'           => 'radios',
    '#title'          => t('Secure Sockets Layer'),
    '#options'        => array(
      ''     => t('No SSL'),
      '/ssl' => t('SSL'),
    ),
    '#default_value'  => Settings::get ('mailbox_settings', 'ssl', ''),
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['certificate'] = array (
    '#type'           => 'radios',
    '#title'          => t('Certificate'),
    '#options'        => array(
      '/novalidate-cert' => t('Don\'t validate certificate'),
      '/validate-cert'   => t('Validate certificate'),
    ),
    '#default_value'  => Settings::get ('mailbox_settings', 'certificate', '/novalidate-cert'),
  );
  
  $form['erpal_crm_mailaction']['mailbox_settings']['username'] = array (
    '#required'        => TRUE,
    '#type'            => 'textfield',
    '#title'           => t('Username'),
    '#default_value'   => Settings::get ('mailbox_settings', 'username', ''),
    '#size'            => 20
  );

  $form['erpal_crm_mailaction']['mailbox_settings']['password'] = array (
    '#type'            => 'password_confirm',
    '#size'            => 20,
    '#description'     => t('Leave blank if you want to use the old passwort setting.'),
  );
 
  return;
}

/**
 * Creates the "Import settings" section for the config form.
 * 
 * @param array_ref   $form           The form render array.
 * @param array_ref   $form_state     The form state array.
 */
function _form_section_import_settings (&$form, &$form_state) {
    
  $form['erpal_crm_mailaction']['import_settings'] = array (
    '#type'            => 'fieldset',
    '#title'           => t('Import settings'),
    '#tree'            => TRUE,
    '#collapsible'     => TRUE,
    '#collapsed'       => TRUE
  );
  
  $form['erpal_crm_mailaction']['import_settings']['publish_imports'] = array (
    '#type'            => 'checkbox',
    '#title'           => t('Publish imported content'),
    '#default_value'   => Settings::get ('import_settings', 'publish_imports', FALSE),
  ); 
  
  $form['erpal_crm_mailaction']['import_settings']['publish_attachments'] = array (
    '#type'            => 'checkbox',
    '#title'           => t('Publish imported attachments'),
    '#default_value'   => Settings::get ('import_settings', 'publish_attachments', FALSE),
  ); 
  
  $form['erpal_crm_mailaction']['import_settings']['create_contact_for_unknown_user'] = array (
    '#type'            => 'checkbox',
    '#title'           => t('Create contacts for unknown users. (NOT SECURE!)'),
    '#default_value'   => Settings::get ('import_settings', 'create_contact_for_unknown_user', FALSE),
  ); 
  
  $form['erpal_crm_mailaction']['import_settings']['cc_box'] = array (
    '#type'            => 'textfield',
    '#title'           => t('Reply (cc) box'),
    '#default_value'   => Settings::get ('import_settings', 'cc_box', ''),
    '#description'     => t('It is the email address which will all the mails of a conversion per cc.')
  ); 
  
  return;
}

/**
 * Creates the "Referencing settings" section for the config form.
 * 
 * @param array_ref   $form           The form render array.
 * @param array_ref   $form_state     The form state array.
 */
function _form_section_referencing_settings (&$form, &$form_state) {
  
  $form['erpal_crm_mailaction']['referencing_settings'] = array (
    '#type'            => 'fieldset',
    '#title'           => t('Referencing settings'),
    '#tree'            => TRUE,
    '#collapsible'     => TRUE,
    '#collapsed'       => TRUE
  );
  
  
  

  
  $form['erpal_crm_mailaction']['referencing_settings']['content_types'] = array (
    '#type'            => 'checkboxes',
    '#description'     => t('Choose the content types which has to be enabled for referencing with imported mails.'),
    '#options'         => _get_content_type_options (),
    '#default_value'   => Settings::get ('referencing_settings', 'content_types', array ('erpal_activity'))
  );
  
  return;
}

/**
 * 
 */
function _get_content_type_options () {
    
  $options           = array ();
  $referencingModels = _erpal_crm_mailaction_load_autoloader ()->loadAllNamespaceClasses (
  'erpal_crm_mailaction\aggregating\database\models\referencing');
  
  foreach ($referencingModels as $referencingModel) {
  
    $options[$referencingModel::getRelevantContentTypeMachineName ()] = 
            $referencingModel::getRelevantContentTypeHumanReadableName ();
  }
  
  return $options;
}

/**
 * Creates the "Test" section for the config form.
 * 
 * @param array_ref   $form           The form render array.
 * @param array_ref   $form_state     The form state array.
 */
function _form_section_test (&$form, &$form_state) {
  
  $form['erpal_crm_mailaction']['test'] = array (
    '#type'           => 'fieldset',
    '#title'          => t('Test import'),
    '#collapsible'    => TRUE,
    '#collapsed'      => TRUE,
    '#description'    => t('Same function like with cron job. So, you maybe have to run this function more than one time to import many mails.')
  ); 
  
  $form['erpal_crm_mailaction']['test']['link'] = array (
    '#markup'       => l(t('Start import'), 'admin/erpal/crm-mailaction/run-import'),
  ); 
  
  return;
}

