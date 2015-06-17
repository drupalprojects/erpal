<?php

/**
 * Implements of hook_views_data().
 */
function erpal_crm_helper_views_data() {
  return array(
    'node' => array(
      'erpal_contact_activities' => array(
        'group' => t('Contact'),
        'title' => t('Contact activities'),
        'help' => t('Choses activities nids'),
        'argument' => array(
          'handler' => 'erpal_crm_helper_handler_argument_contact_activities',
        ),
      ),   
    )
  );
}
