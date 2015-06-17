<?php

/**
 * @file
 * Defines the View integration with payment entity.
 */

/**
 * Implements hook_views_data().
 */
function payment_views_data() {
  $data = array();

  $data['payment']['table']['group']  = t('Payment');
  $data['payment']['table']['base'] = array(
    'field' => 'pid',
    'title' => t('Payment'),
    'help' => t('Payment.'),
  );
  $data['payment']['table']['entity type'] = 'payment';

  // Expose the Payment ID.
  $data['payment']['pid'] = array(
    'title' => t('Payment ID'),
    'help' => t('The unique internal identifier of the Payment.'),
    'field' => array(
      'handler' => 'payment_handler_field_title',
      'click sortable' => TRUE,
      'path' => drupal_get_path('module', 'payment') . '/views/handlers',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'payment_handler_argument_mid',
      'path' => drupal_get_path('module', 'payment') . '/views/handlers',
    ),
  );

  // Expose the Payment title.
  $data['payment']['subject'] = array(
    'title' => t('Subject'),
    'help' => t('The title of the Payment.'),
    'field' => array(
      'handler' => 'payment_handler_field_title',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  
  // Created field value of Payment.
  $data['payment']['value'] = array(
    'title' => t('Value'),
    'help' => t('Value of payment.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
      'float' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Created field date of Payment.
  $data['payment']['date'] = array(
    'title' => t('Post date'),
    'help' => t('The date the Payment was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );


  // Edit Payment link field.
  $data['payment']['edit_map'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the Payment.'),
      'handler' => 'payment_handler_field_link_edit',
    ),
  );
  

  // Delete Payment link field.
  $data['payment']['delete_map'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the Payment.'),
      'handler' => 'payment_handler_field_link_delete',
    ),
  );
  
  // Payment settings.
  $data['payment']['settings'] = array(
    'field' => array(
      'title' => t('Payment settings'),
      'help' => t('Provide a settings of the Payment.'),
      'handler' => 'payment_handler_field_settings',
    ),
  );

  return $data;
}
