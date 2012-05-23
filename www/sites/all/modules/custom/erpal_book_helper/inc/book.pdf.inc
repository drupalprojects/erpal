<?php

/**
* @file handels all functions needed to create a pdf from a book or a book-page
*/

/**
* Menu Callback for url to create a pdf from a book
*/
function _erpal_books_helper_book_pdf_menu_callback($node) {
  return drupal_get_form('erpal_books_helper_pdf_form', $node);
}


/**
* Form to select options for creating a pdf from a book or a book-page
*/
function erpal_books_helper_pdf_form($form, $form_state, $node) {
  //it doesen't matter if we have to deal with a book node or a bool-page node, because traversion
  //all nodes recursively works with the field_parent field only, which is attached to both node types.
  $form = array();
  
  $form['nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );
  
  $options = array('pdf' => t('Ignore PDF exclude flag'));  //@TODO read the allowed values of the field_page_exclude_from and use them as options - more flexible!
  $form['ignore_exclude'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Ignore exclude flags'),
    '#options' =>  $options,
  );
  
  $form['pdf_create_method'] = array(
    '#type' => 'radios',
    '#title' => t('PDF file handling'),
    '#options' => array(
      'attach' => t('Attach created PDF to book node'),
      'download' => t('Send the created PDF as download only'),
    ),
    '#default_value' => array('attach'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create PDF'),
  );
  
  return $form;
}

/**
* validation handler for creating a pdf from a book or a book-page
*/
function erpal_books_helper_pdf_form_validate($form, $form_state) {
  //@TODO: perhaps we need some validation bevore creating the pdf....who knows
}

/**
* Submit handler for creating a pdf from a book or a book-page
*/
function erpal_books_helper_pdf_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $root_nid = $values['nid'];
  $root_node = node_load($root_nid);
  
  $options = $values;
  
  //get the book node
  if ($root_node->type == 'erpal_book') {
    $book_node = $root_node;
  } elseif ($root_node->type == 'erpal_book_page') {
    $book_nid = $root_node->field_book_ref[LANGUAGE_NONE][0]['nid'];
    $book_node = node_load($book_nid);
  }
  
  _erpal_book_helper_create_pdf($book_node, $root_node, $options);
  
  drupal_goto('node/'.$root_node->nid);
}

/**
* Creates a PDF of the tree structure under a given root node and returns the fileobject
* @TODO: create pdf by batch process. Caclulate all processed nodes by field query and process each node in batch process steps while
* collection the global HTML in context variable of batch
*/
function _erpal_book_helper_create_pdf($book_node, $root_node, $options) {
  $html = _erpal_book_helper_get_child_html($book_node, $root_node, $options);
  
  dpm($html);
  
  //now put HTML content to PDF rendering
}

/**
* Recursive function to get HTML of all Child nodes
*/
function _erpal_book_helper_get_child_html($book_node, $root_node, $options) {
  
  //prepare fields so they can be included in entitiy field query easily
  
  $child_nodes = _erpal_book_helper_get_children($book_node, $root_node, $options);
  
  $this_html = theme('erpal_books_book_pdf_html', array('node' => $root_node));
  //recursion anchor
  if (count($child_nodes) == 0) {
    return $this_html;
  }
  
  //next step recusrion
  $html = '';

  foreach ($child_nodes as $child_node) {
    //get recusive HTML of children
    $child_html = _erpal_book_helper_get_child_html($book_node, $child_node, $options);
    $html .= $child_html;
  }

  return $this_html . theme('erpal_books_children_html', array('parent_node' => $root_node, 'html' => $html));
}
