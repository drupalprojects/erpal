<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Erpal Search Pane'), 
  'category' => t('Erpal'), 
  'edit form' => 'erpal_search_pane_edit_form', 
  'render callback' => 'erpal_search_pane_render', 
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function erpal_search_pane_edit_form($form, &$form_state) {
  return $form;
}


/**
 * Run-time rendering of the body of the block (content type)
 */
function erpal_search_pane_render($subtype, $conf, $args, $contexts) {

$block = new stdClass();
  if(module_exists('erpal_search_api_solr')) {
    $block->title = t('');   
    $block->content = drupal_get_form('erpal_search_pane_form');
  } else {
    $block->title = t('');   
    $block->content = drupal_get_form('search_block_form');   
  }
return $block;
}

