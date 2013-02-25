<?php
/**
 * @author    Marc Sven Kleinboehl
 * @created   07/12/2012
 * @copyright 2012 © Bright Solutions GmbH
 * 
 * The API for extending the erpal_mailaction module.
 */

/**
 * Implements hook_erpal_crm_mailaction_incoming. 
 */
function hook_erpal_crm_mailaction_incoming ($to, $from, $subject, $body, $attachments) {
 
  // Do whatever you want to do at this action.
  
  return;
}
