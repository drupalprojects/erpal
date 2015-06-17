<?php
/**
 * @file
 * erpal_book_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_book_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents';
  $cat_item->name = 'Erpal Documents (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'books',
            'case' => 1,
          ),
          'context' => '1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'pm_arg',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Documents (default)',
    'path' => 'books/%',
    'category' => 'Documents',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-book',
        'path_router' => 'node/add/erpal-book',
        'path_original' => 'node/add/erpal-book',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_is_template' => '0',
        ),
        'path_destination' => TRUE,
        'title' => 'Create a new document',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => TRUE,
        'machine_name' => 'documents',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'templates',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_documents',
    'path_original' => 'books/%pm_arg',
    'path_pattern' => 'books/%',
    'path_query' => array(),
    'path_router' => 'books/%',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -50;
  $export['erpal_documents'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_create_document';
  $cat_item->name = 'Erpal Documents: Create Document';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/add/erpal-book';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '!=',
            'value' => '1',
            'case' => 0,
          ),
          'context' => 'bool',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      'field_is_template' => array(
        'argument_name' => 'bool',
        'argument_type' => 'query',
        'position' => 'field_is_template',
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Documents: Create Document',
    'path' => 'node/add/erpal-book',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
    ),
    'machine_name' => 'erpal_documents_create_document',
    'path_original' => 'node/add/erpal-book?field_is_template=%bool',
    'path_pattern' => 'node/%/%',
    'path_query' => array(
      'field_is_template' => '%bool',
    ),
    'path_router' => 'node/add/erpal-book',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -48;
  $export['erpal_documents_create_document'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_create_template';
  $cat_item->name = 'Erpal Documents: Create Template';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/add/erpal-book';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '1',
            'case' => 0,
          ),
          'context' => 'bool',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      'field_is_template' => array(
        'argument_name' => 'bool',
        'argument_type' => 'query',
        'position' => 'field_is_template',
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Documents: Create Template',
    'path' => 'node/add/erpal-book',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
    ),
    'machine_name' => 'erpal_documents_create_template',
    'path_original' => 'node/add/erpal-book?field_is_template=%bool',
    'path_pattern' => 'node/%/%',
    'path_query' => array(
      'field_is_template' => '%bool',
    ),
    'path_router' => 'node/add/erpal-book',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -47;
  $export['erpal_documents_create_template'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_add_pages_cloned';
  $cat_item->name = 'Erpal Documents: Document / Add pages cloned';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/clonetemplates/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      2 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / Add pages cloned',
    'path' => 'books/clonetemplates/%node',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_document_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_document_add_pages_cloned',
    'path_original' => 'books/clonetemplates/%node',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/clonetemplates/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -36;
  $export['erpal_documents_document_add_pages_cloned'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_aul';
  $cat_item->name = 'Erpal Documents: Document / AUL';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Dashboard';
  $cat_item->path = 'node/%/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / AUL',
    'path' => 'node/%/aul',
    'category' => 'Dashboard',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_document_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_document_aul',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -33;
  $export['erpal_documents_document_aul'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_clone';
  $cat_item->name = 'Erpal Documents: Document / Clone';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%node/clone';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / Clone',
    'path' => 'books/%node/clone',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_document_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_document_clone',
    'path_original' => 'books/%node/clone',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/%/clone',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -38;
  $export['erpal_documents_document_clone'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_create_page';
  $cat_item->name = 'Erpal Documents: Document  / Create page';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Dashboard';
  $cat_item->path = 'node/add/erpal-book-page?field_book_parent=%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      'field_book_parent' => array(
        'argument_name' => 'node',
        'argument_type' => 'query',
        'position' => 'field_book_parent',
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document  / Create page',
    'path' => 'node/add/erpal-book-page?field_book_parent=%node',
    'category' => 'Dashboard',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
    ),
    'machine_name' => 'erpal_documents_document_create_page',
    'path_original' => 'node/add/erpal-book-page?field_book_parent=%node',
    'path_pattern' => 'node/%/%',
    'path_query' => array(
      'field_book_parent' => '%node',
    ),
    'path_router' => 'node/add/erpal-book-page',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -34;
  $export['erpal_documents_document_create_page'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_edit';
  $cat_item->name = 'Erpal Documents: Document / Edi';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Dashboard';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / Edi',
    'path' => 'node/%/edit',
    'category' => 'Dashboard',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_document_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_document_edit',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -35;
  $export['erpal_documents_document_edit'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_export';
  $cat_item->name = 'Erpal Documents: Document / Export';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%node/export';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / Export',
    'path' => 'books/%node/export',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_document_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_document_export',
    'path_original' => 'books/%node/export',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/%/export',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -39;
  $export['erpal_documents_document_export'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_page_view';
  $cat_item->name = 'Erpal Documents: Document Page / View';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book_page' => 'erpal_book_page',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document Page / View',
    'path' => 'node/%node',
    'category' => 'Documents',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-book-page',
        'path_router' => 'node/add/erpal-book-page',
        'path_original' => 'node/add/erpal-book-page',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_book_parent' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add a page',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'books/[node:nid]/export',
        'path_router' => 'books/[node:nid]/export',
        'path_original' => 'books/[node:nid]/export',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Export',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      2 => array(
        'path' => 'books/clonetemplates/[node:nid]',
        'path_router' => 'books/clonetemplates/[node:nid]',
        'path_original' => 'books/clonetemplates/[node:nid]',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Add pages cloned',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'files',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_documents_document_page_view',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -37;
  $export['erpal_documents_document_page_view'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_document_view';
  $cat_item->name = 'Erpal Documents: Document / View';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Document / View',
    'path' => 'node/%node',
    'category' => 'Documents',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-book-page',
        'path_router' => 'node/add/erpal-book-page',
        'path_original' => 'node/add/erpal-book-page',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_book_parent' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add a page',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'books/[node:nid]/export',
        'path_router' => 'books/[node:nid]/export',
        'path_original' => 'books/[node:nid]/export',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Export',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      2 => array(
        'path' => 'books/clonetemplates/[node:nid]',
        'path_router' => 'books/clonetemplates/[node:nid]',
        'path_original' => 'books/clonetemplates/[node:nid]',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Add pages cloned',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      3 => array(
        'path' => 'books/[node:nid]/clone',
        'path_router' => 'books/[node:nid]/clone',
        'path_original' => 'books/[node:nid]/clone',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Clone to new book',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'files',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_documents_document_view',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -37;
  $export['erpal_documents_document_view'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_files';
  $cat_item->name = 'Erpal Documents: Files';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Dashboard';
  $cat_item->path = 'node/%/files';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Files',
    'path' => 'node/%/files',
    'category' => 'Dashboard',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => 'files',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_documents_files',
    'path_original' => 'node/%node/files',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/files',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -32;
  $export['erpal_documents_files'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_add_pages';
  $cat_item->name = 'Erpal Documents: Template / Add pages';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/clonetemplates/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      2 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / Add pages',
    'path' => 'books/clonetemplates/%node',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_templates_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_template_add_pages',
    'path_original' => 'books/clonetemplates/%node',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/clonetemplates/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -41;
  $export['erpal_documents_template_add_pages'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_add_pages_clone';
  $cat_item->name = 'Erpal Documents: Template / Add pages (clone)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%node/clone';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / Add pages (clone)',
    'path' => 'books/%node/clone',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_templates_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_template_add_pages_clone',
    'path_original' => 'books/%node/clone',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/%/clone',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -42;
  $export['erpal_documents_template_add_pages_clone'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_aul';
  $cat_item->name = 'Erpal Documents: Template / AUL';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/%node/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / AUL',
    'path' => 'node/%node/aul',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_templates_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_template_aul',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -45;
  $export['erpal_documents_template_aul'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_create_page';
  $cat_item->name = 'Erpal Documents: Template / Create page';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/add/erpal-book-page';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      'field_book_parent' => array(
        'argument_name' => 'node',
        'argument_type' => 'query',
        'position' => 'field_book_parent',
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / Create page',
    'path' => 'node/add/erpal-book-page',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
    ),
    'machine_name' => 'erpal_documents_template_create_page',
    'path_original' => 'node/add/erpal-book-page?field_book_parent=%node',
    'path_pattern' => 'node/%/%',
    'path_query' => array(
      'field_book_parent' => '%node',
    ),
    'path_router' => 'node/add/erpal-book-page',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -43;
  $export['erpal_documents_template_create_page'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_edit';
  $cat_item->name = 'Erpal Documents: Template / Edit';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/%node/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / Edit',
    'path' => 'node/%node/edit',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_templates_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_template_edit',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -44;
  $export['erpal_documents_template_edit'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_template_export';
  $cat_item->name = 'Erpal Documents: Template / Export';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%node/export';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Template / Export',
    'path' => 'books/%node/export',
    'category' => 'Documents',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents_templates_view|files',
      ),
    ),
    'machine_name' => 'erpal_documents_template_export',
    'path_original' => 'books/%node/export',
    'path_pattern' => 'books/%/%',
    'path_query' => array(),
    'path_router' => 'books/%/export',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -40;
  $export['erpal_documents_template_export'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_templates';
  $cat_item->name = 'Erpal Documents: Templates';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'books/%pm_arg';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'templates',
            'case' => 1,
          ),
          'context' => '1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'pm_arg',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Documents: Templates',
    'path' => 'books/%pm_arg',
    'category' => 'Documents',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-book',
        'path_router' => 'node/add/erpal-book',
        'path_original' => 'node/add/erpal-book',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_is_template' => '1',
        ),
        'path_destination' => TRUE,
        'title' => 'Create a new template',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
    ),
    'machine_name' => 'erpal_documents_templates',
    'path_original' => 'books/%pm_arg',
    'path_pattern' => 'books/%',
    'path_query' => array(),
    'path_router' => 'books/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -49;
  $export['erpal_documents_templates'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_documents_templates_view';
  $cat_item->name = 'Erpal Documents: Templates / View';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Documents';
  $cat_item->path = 'node/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book' => 'erpal_book',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:erpal_book:field_is_template',
          'settings' => array(
            'field_is_template' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_template_value' => '1',
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'books/books',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Documents: Templates / View',
    'path' => 'node/%node',
    'category' => 'Documents',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-book-page',
        'path_router' => 'node/add/erpal-book-page',
        'path_original' => 'node/add/erpal-book-page',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_book_parent' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Add a page',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'books/[node:nid]/export',
        'path_router' => 'books/[node:nid]/export',
        'path_original' => 'books/[node:nid]/export',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Export',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      2 => array(
        'path' => 'books/clonetemplates/[node:nid]',
        'path_router' => 'books/clonetemplates/[node:nid]',
        'path_original' => 'books/clonetemplates/[node:nid]',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Add pages cloned',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      3 => array(
        'path' => 'books/[node:nid]/clone',
        'path_router' => 'books/[node:nid]/clone',
        'path_original' => 'books/[node:nid]/clone',
        'path_pattern' => 'books/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Clone to new book',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'books/books',
        'path_router' => 'books/books',
        'path_original' => 'books/books',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Documents',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|documents',
      ),
      1 => array(
        'path' => 'books/templates',
        'path_router' => 'books/templates',
        'path_original' => 'books/templates',
        'path_pattern' => 'books/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Templates',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_documents|templates',
      ),
      2 => array(
        'path' => 'node/[node:nid]/files',
        'path_router' => 'node/[node:nid]/files',
        'path_original' => 'node/[node:nid]/files',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Files',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'files',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_documents_templates_view',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -46;
  $export['erpal_documents_templates_view'] = $cat_item;

  return $export;
}
