<?php

/**
 * Implements of hook_views_data().
 */
function erpal_book_helper_views_data() {
  return array(
    'node' => array(
      'erpal_subpages' => array(
        'group' => t('Book Page'),
        'title' => t('Page subpages'),
        'help' => t('Choses pages and subpages nids'),
        'argument' => array(
          'handler' => 'erpal_book_helper_handler_argument_erpal_book',
        ),
        'filter' => array(
          'handler' => 'erpal_book_helper_handler_filter_erpal_book',
        )
      ),      
    )
  );
}
