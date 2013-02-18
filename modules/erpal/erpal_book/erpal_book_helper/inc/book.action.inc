<?php

/**
* @file functions for book actions (bulk operations) to clone from books
*/

/**
* Action callback to clone book page
*/
function erpal_book_helper_clone_to_book_action(&$book_pages, &$context) {
  $page_nids = array_keys($book_pages);
  $parent_nid = $context['parent_nid'];
  
  if (!isset($context['clone_tasks']))
    $context['clone_tasks'] = 0;

  $options = _erpal_books_helper_options_for_clone($context); 

  //start cloning batch operation
  _erpal_book_helper_clone_pages_batch($page_nids, $parent_nid, $options);
}

/**
* Callback for configurable form of book clone bulk operation
*/
function erpal_book_helper_clone_to_book_action_form($context, $form_state) {
  $parent_nid = $context['view']->args[0];
  $parent_node = node_load($parent_nid);  //this is the parent 

  if ($parent_node->type != 'erpal_book_page' && $parent_node->type != 'erpal_book') {
    //we clone only book pages
    drupal_set_message(t('You can only clone to books or book pages.'), 'error');
    drupal_goto('node/'.$parent_nid);
  }
 
  //now build the settings form for configurable bulk operation
  $form = array();
  $form['clone_children'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clone children'),
    '#default_value' => true,
    '#weight' => -15,
    '#description' => t('If checked, all children of the selected templates will be cloned, too'),
  );
  
  //call other module to make their option
  $book_node = _erpal_book_helper_get_book($parent_node);
  $book_link = l($book_node->title, 'node/'.$book_node->nid);
  $parent_link = l($parent_node->title, 'node/'.$parent_node->nid);
  $description = "<h2>".t('New clone for !parent_link in !book_link', array('!book_link' => $book_link, '!parent_link' => $parent_link))."</h2>";
  
  $form['description'] = array(
    '#type' => 'item',
    '#markup' => $description,
    '#weight' => -20, //at the top!
  );
  
  $args = array('book_node' => $book_node, 'parent_node' => $parent_node);
  drupal_alter('clone_page_action_form', $form, $form_state, $args);

  //add the parent node and the book node where all cloned nodes will be assigned to
  $form['parent_nid'] = array(
    '#type' => 'value',
    '#value' => $parent_node->nid,
  );
  
  $form['book_nid'] = array(
    '#type' => 'value',
    '#value' => $book_node->nid,
  );
  
  return $form;
}

function erpal_book_helper_clone_to_book_action_validate($form, $form_state) {
  module_invoke_all('erpal_clone_page_validate', $form, $form_state);
}

/**
* Submit handler for book page clone bulk operation
*/
function erpal_book_helper_clone_to_book_action_submit($form, &$form_state) {
  $values = $form_state['values'];
  
  return $values;
}