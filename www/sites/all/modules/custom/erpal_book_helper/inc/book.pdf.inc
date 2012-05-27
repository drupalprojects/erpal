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

  //Put all the time options in a fieldset
  $form['estimations'] = array(
    '#type' => 'fieldset',
    '#title' => t('Estimations'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
  
  $estimation_options = array('page' => t('From pages'), 'task' => t('From tasks'));
  $form['estimations']['export_estimations'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Include detailed time estimations'),
    '#options' =>  $estimation_options,
  );
  
  $total_options = array('page' => t('From pages'), 'task' => t('From tasks'));
  $form['estimations']['total_estimation'] = array(
    '#type' => 'radios',
    '#default_value' => 'page',
    '#title' => t('Include total estimations'),
    '#options' =>  $total_options,
    '#description' => t('You can use tokens in you pages to replace the calculated total estimation.'),
  );
  
  $form['pdf_create_method'] = array(
    '#type' => 'radios',
    '#title' => t('PDF file handling'),
    '#options' => array(
      'attach' => t('Attach created PDF to book node'),
      'download' => t('Send the created PDF as download only'),
    ),
    '#default_value' => 'attach',
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
  
  $file_node = _erpal_book_helper_create_pdf($book_node, $root_node, $options);
  
  if (is_object($file_node)) {
    drupal_set_message(t('Your pdf has been created successfully!'));
    drupal_goto('node/'.$file_node->nid);
  }else
    drupal_set_message(t('Sorry, but there was an error while creating your pdf.'), 'error');
  
  drupal_goto('node/'.$root_node->nid);
}

/**
* Creates a PDF of the tree structure under a given root node and returns the fileobject
* @TODO: create pdf by batch process. Caclulate all processed nodes by field query and process each node in batch process steps while
* collection the global HTML in context variable of batch
*/
function _erpal_book_helper_create_pdf($book_node, $root_node, $options) {
  global $user;
  $params = array(
    'title' => $root_node->title,
    'author' => _erpal_print_get_author($root_node),
  );
  
  $pdf_object = erpal_print_prepare_tcpdf($params);
  
  if (!$pdf_object)
    return false;
  
  $html = _erpal_book_helper_get_child_html($pdf_object, $book_node, $root_node, $options); 

  $total_estimation = $html['total_estimation'];
  $html = $html['html'];
  
  //now replace the estimation token in the html
  $data = array('total_estimation' => $total_estimation);
  $html = token_replace($html, $data);

  //now put HTML content to PDF rendering
  
  $pdf_method = $options['pdf_create_method'];

  if ($pdf_method == 'attach') {    
    $doc_uri = _erpal_docs_folder_uri();    
  } elseif ($pdf_method == 'download') {
    $doc_uri = false;
  }
  
  $basename = _erpal_docs_make_filename($root_node->title, 'pdf');
  
  $doc_file = _erpal_print_html_as_pdf($html, $doc_uri, $basename, $params, $pdf_object, true);
  
  if (!$doc_file) {
    drupal_set_message(t('There has been an error while creating you pdf. PDF not created.'), 'error');
    drupal_goto('node/'.$root_node);
  }
 
  //now attach the file to the book_node
  $file_node = false;
  if (isset($book_node->field_asset_files[LANGUAGE_NONE][0]['nid'])) {
    $file_nid = $book_node->field_asset_files[LANGUAGE_NONE][0]['nid'];  //if exists, this node will be updated with its file
    $file_node = node_load($file_nid);
  }

  _erpal_docs_attach_file($book_node, $doc_file, $file_node, false, true);
  
  return $file_node;
}

/**
* Recursive function to get HTML of all Child nodes
*/
function _erpal_book_helper_get_child_html($pdf_object, $book_node, $root_node, $options) {
  
  //prepare fields so they can be included in entitiy field query easily
  
  $child_nodes = _erpal_book_helper_get_children($book_node, $root_node, $options);
  $theme_options = array(
    'estimations' => array(
      'task' => $options['export_estimations']['task'],
      'page' => $options['export_estimations']['page'],
      'total' => $options['total_estimation'],
    )
  );
  
  //save the body, if we dont do that, the content token will be replaced in the real node body....dont know why...??!
  $body = '';
  if (isset($root_node->body[LANGUAGE_NONE][0]['value'])) {
    $body = $root_node->body[LANGUAGE_NONE][0]['value'];
    _erpal_book_helper_replace_tokens($root_node); //replace all tokens
  }
  
  $this_html = theme('erpal_books_book_pdf_html', array('node' => $root_node, 'pdf_object' => $pdf_object, 'options' => $theme_options));

  $root_node->body[LANGUAGE_NONE][0]['value'] = $body; // set the body back again!
  
  $total_options[$theme_options['estimations']['total']] = 1;
  $estimation = _erpal_book_helper_get_estimation($root_node, $total_options);
  
  //recursion anchor, no more children!
  if (count($child_nodes) == 0) {    
    return array(
      'html' => $this_html,
      'total_estimation' => $estimation,
    );
  }
  
  //next step recursion
  $html = '';
  foreach ($child_nodes as $child_node) {
    //get recusive HTML of children
    $child_html = _erpal_book_helper_get_child_html($pdf_object, $book_node, $child_node, $options);

    $estimation += $child_html['total_estimation'];
    $child_html = $child_html['html'];
    $html .= $child_html;
  }

  $html = $this_html . theme('erpal_books_children_html', array('parent_node' => $root_node, 'html' => $html));
  
  return array(
    'html' => $html,
    'total_estimation' => $estimation,
  );
}

/**
* Returns the estimation from a book_page node or a task node
*/
function _erpal_book_helper_get_estimation($node, $options=false) {

  $duration = 0;
  if ($node->type == 'erpal_task') {
    if ($options && isset($options['task']) && $options['task'])
      if (isset($node->field_estimated_time[LANGUAGE_NONE][0]['value']))
        $duration = $node->field_estimated_time[LANGUAGE_NONE][0]['value'];
  } elseif ($node->type == 'erpal_book_page') {
    if ($options && isset($options['page']) && $options['page'])
      if (isset($node->field_estimated_duration[LANGUAGE_NONE][0]['value']))
        $duration = $node->field_estimated_duration[LANGUAGE_NONE][0]['value'];
  }

  return $duration;
}

/**
* Preprocessing Variables for rendering a node as a page in pdf
*/
function _erpal_book_helper_preprocess_erpal_books_book_pdf_html(&$variables) {
  $node = $variables['node'];
  $title = $node->title;
  
  $body  = '';
  if (isset($node->body[LANGUAGE_NONE][0]['value']))
    $body = $node->body[LANGUAGE_NONE][0]['value'];   
  
  $estimations = $variables['options']['estimations'];
  
  $duration = _erpal_book_helper_get_estimation($node, $estimations);
  
  $variables['body'] = $body;
  $variables['title'] = $title;
  $variables['duration'] = $duration;
  $variables['nid'] = $node->nid;
}
