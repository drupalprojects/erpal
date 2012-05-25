<?php
/**
 * @file
 * feature_erpal_invoice.rel.inc
 */

/**
 * Implements hook_rel_build_info().
 */
function feature_erpal_invoice_rel_build_info() {
  $export = array();

  $rel = new stdClass();
  $rel->api_version = 1;
  $rel->build_id = 'erpal_invoice_node_form';
  $rel->label = 'erpal_invoice_node_form';
  $rel->entity_type = 'node';
  $rel->bundle = 'erpal_invoice';
  $rel->view_mode = 'form';
  $rel->context = 'form';
  $rel->path = 'admin/structure/types/manage/erpal-invoice/fields';
  $rel->elements = array(
    'additional_settings' => array(
      'owner' => 'rel',
      'label' => 'Additional settings',
      'parent' => '',
      'group_info' => array(
        'format_type' => 'tabs',
        'format_settings' => array(),
        'label' => 'Vertical tabs group',
        'description' => 'This fieldgroup renders child groups in its own vertical tabs wrapper.',
        'instance_settings' => array(
          'classes' => '',
        ),
      ),
      'weight' => 99,
      'element_type' => 'vertical_tabs',
    ),
    'revision_information' => array(
      'owner' => 'rel',
      'label' => 'Revision information',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'node-form-revision-information',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => 20,
      'element_type' => 'fieldset',
    ),
    'revision' => array(
      'owner' => 'rel',
      'label' => 'Create new revision',
      'parent' => 'revision_information',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'checkbox',
    ),
    'log' => array(
      'owner' => 'rel',
      'label' => 'Revision log message',
      'parent' => 'revision_information',
      'group_info' => FALSE,
      'weight' => 1,
      'element_type' => 'textarea',
    ),
    'author' => array(
      'owner' => 'rel',
      'label' => 'Authoring information',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'node-form-author',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => 90,
      'element_type' => 'fieldset',
    ),
    'name' => array(
      'owner' => 'rel',
      'label' => 'Authored by',
      'parent' => 'author',
      'group_info' => FALSE,
      'weight' => -1,
      'element_type' => 'textfield',
    ),
    'date' => array(
      'owner' => 'rel',
      'label' => 'Authored on',
      'parent' => 'author',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'textfield',
    ),
    'options' => array(
      'owner' => 'rel',
      'label' => 'Publishing options',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'node-form-options',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => 95,
      'element_type' => 'fieldset',
    ),
    'status' => array(
      'owner' => 'rel',
      'label' => 'Published',
      'parent' => 'options',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'checkbox',
    ),
    'promote' => array(
      'owner' => 'rel',
      'label' => 'Promoted to front page',
      'parent' => 'options',
      'group_info' => FALSE,
      'weight' => 1,
      'element_type' => 'checkbox',
    ),
    'sticky' => array(
      'owner' => 'rel',
      'label' => 'Sticky at top of lists',
      'parent' => 'options',
      'group_info' => FALSE,
      'weight' => 2,
      'element_type' => 'checkbox',
    ),
    'actions' => array(
      'owner' => 'rel',
      'label' => 'Actions',
      'parent' => '',
      'group_info' => array(
        'format_type' => 'div',
        'format_settings' => array(
          'formatter' => 'open',
          'instance_settings' => array(
            'show_label' => FALSE,
          ),
        ),
        'label' => 'Div',
        'description' => 'This fieldgroup renders the inner content in a simple div with the titel as legend.',
        'format_types' => array(
          0 => 'open',
          1 => 'collapsible',
          2 => 'collapsed',
        ),
        'instance_settings' => array(
          'description' => '',
          'show_label' => 1,
          'label_element' => 'h3',
          'effect' => 'none',
          'speed' => 'fast',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'open',
      ),
      'weight' => 100,
      'element_type' => 'actions',
    ),
    'submit' => array(
      'owner' => 'rel',
      'label' => 'Save',
      'parent' => 'actions',
      'group_info' => FALSE,
      'weight' => 5,
      'element_type' => 'submit',
    ),
    'preview' => array(
      'owner' => 'rel',
      'label' => 'Preview',
      'parent' => 'actions',
      'group_info' => FALSE,
      'weight' => 10,
      'element_type' => 'submit',
    ),
    'delete' => array(
      'owner' => 'rel',
      'label' => 'Delete',
      'parent' => 'actions',
      'group_info' => FALSE,
      'weight' => 15,
      'element_type' => 'submit',
    ),
    'field_auto_note' => array(
      'owner' => 'drupal',
      'label' => 'Field auto note',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '18',
      'element_type' => 'container',
    ),
    'field_billables_ref' => array(
      'owner' => 'drupal',
      'label' => 'Field billables ref',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '4',
      'element_type' => 'container',
    ),
    'field_contractor_ref' => array(
      'owner' => 'drupal',
      'label' => 'Field contractor ref',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '3',
      'element_type' => 'container',
    ),
    'field_credit_period' => array(
      'owner' => 'drupal',
      'label' => 'Field credit period',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '12',
      'element_type' => 'container',
    ),
    'field_currency' => array(
      'owner' => 'drupal',
      'label' => 'Field currency',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '5',
      'element_type' => 'container',
    ),
    'field_customer_ref' => array(
      'owner' => 'drupal',
      'label' => 'Field customer ref',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '1',
      'element_type' => 'container',
    ),
    'field_invoice_address_id' => array(
      'owner' => 'drupal',
      'label' => 'Field invoice address id',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '2',
      'element_type' => 'container',
    ),
    'field_invoice_date' => array(
      'owner' => 'drupal',
      'label' => 'Field invoice date',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '8',
      'element_type' => 'container',
    ),
    'field_invoice_number' => array(
      'owner' => 'drupal',
      'label' => 'Field invoice number',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => 1,
      'element_type' => '',
    ),
    'field_note' => array(
      'owner' => 'drupal',
      'label' => 'Field note',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '17',
      'element_type' => 'container',
    ),
    'token_tree' => array(
      'owner' => 'rel',
      'label' => 'Token tree',
      'parent' => 'field_note',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => '',
    ),
    'field_order_number_extern' => array(
      'owner' => 'drupal',
      'label' => 'Field order number extern',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '7',
      'element_type' => 'container',
    ),
    'field_order_number_intern' => array(
      'owner' => 'drupal',
      'label' => 'Field order number intern',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '8',
      'element_type' => 'container',
    ),
    'field_payed' => array(
      'owner' => 'drupal',
      'label' => 'Field payed',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '14',
      'element_type' => 'container',
    ),
    'field_skonto' => array(
      'owner' => 'drupal',
      'label' => 'Field skonto',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '13',
      'element_type' => 'container',
    ),
    'comment_settings' => array(
      'owner' => 'rel',
      'label' => 'Comment settings',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'comment-node-settings-form',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => 30,
      'element_type' => 'fieldset',
    ),
    'comment' => array(
      'owner' => 'rel',
      'label' => 'Comments',
      'parent' => 'comment_settings',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'radios',
    ),
    'order_numbers_token_tree' => array(
      'owner' => 'rel',
      'label' => 'Order numbers token tree',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => 10,
      'element_type' => '',
    ),
    'menu' => array(
      'owner' => 'rel',
      'label' => 'Menu settings',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'menu-link-form',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => -2,
      'element_type' => 'fieldset',
    ),
    'enabled' => array(
      'owner' => 'rel',
      'label' => 'Provide a menu link',
      'parent' => 'menu',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'checkbox',
    ),
    'link' => array(
      'owner' => 'rel',
      'label' => 'Link',
      'parent' => 'menu',
      'group_info' => array(
        'format_type' => 'div',
        'format_settings' => array(
          'formatter' => 'open',
          'instance_settings' => array(
            'show_label' => FALSE,
            'id' => 'edit-menu--2',
            'classes' => 'form-wrapper',
          ),
        ),
        'label' => 'Div',
        'description' => 'This fieldgroup renders the inner content in a simple div with the titel as legend.',
        'format_types' => array(
          0 => 'open',
          1 => 'collapsible',
          2 => 'collapsed',
        ),
        'instance_settings' => array(
          'description' => '',
          'show_label' => 1,
          'label_element' => 'h3',
          'effect' => 'none',
          'speed' => 'fast',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'open',
      ),
      'weight' => 1,
      'element_type' => 'container',
    ),
    'link_title' => array(
      'owner' => 'rel',
      'label' => 'Menu link title',
      'parent' => 'link',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'textfield',
    ),
    'description' => array(
      'owner' => 'rel',
      'label' => 'Description',
      'parent' => 'link',
      'group_info' => FALSE,
      'weight' => 1,
      'element_type' => 'textarea',
    ),
    'parent' => array(
      'owner' => 'rel',
      'label' => 'Parent item',
      'parent' => 'link',
      'group_info' => FALSE,
      'weight' => 2,
      'element_type' => 'select',
    ),
    'weight' => array(
      'owner' => 'rel',
      'label' => 'Weight',
      'parent' => 'link',
      'group_info' => FALSE,
      'weight' => 3,
      'element_type' => 'weight',
    ),
    'path' => array(
      'owner' => 'rel',
      'label' => 'URL path settings',
      'parent' => 'additional_settings',
      'group_info' => array(
        'format_type' => 'tab',
        'format_settings' => array(
          'instance_settings' => array(
            'classes' => 'path-form',
          ),
          'formatter' => 'collapsed',
        ),
        'label' => 'Vertical tab',
        'description' => 'This fieldgroup renders the content in a fieldset, part of vertical tabs group.',
        'format_types' => array(
          0 => 'open',
          1 => 'closed',
        ),
        'instance_settings' => array(
          'description' => '',
          'classes' => '',
          'required_fields' => 1,
        ),
        'default_formatter' => 'closed',
      ),
      'weight' => 30,
      'element_type' => 'fieldset',
    ),
    'alias' => array(
      'owner' => 'rel',
      'label' => 'URL alias',
      'parent' => 'path',
      'group_info' => FALSE,
      'weight' => 0,
      'element_type' => 'textfield',
    ),
  );
  $rel->duplicate = array();
  $export['erpal_invoice_node_form'] = $rel;

  return $export;
}
