<?php

/**
* @file handels all functions needed to create a pdf from a book or a book-page
* @TODO: This file is depricated and will be removed some day because we only support ODT export of books
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
  //all nodes recursively works with the field_book_parent field only, which is attached to both node types.
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
  
  $form['add_nids'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add IDs to PDF'),
    '#default_value' => false,    
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
  //@TODO: perhaps we need some validation before creating the pdf....who knows
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
    $book_nid = $root_node->field_book_ref[LANGUAGE_NONE][0]['target_id'];
    $book_node = node_load($book_nid);
  }
  
  $file_node = _erpal_book_helper_create_pdf($book_node, $root_node, $options);

  //update the version of the book node +1
  $new_version = isset($book_node->field_book_version[LANGUAGE_NONE][0]['value']) ? $book_node->field_book_version[LANGUAGE_NONE][0]['value'] +1 : 2;
  $book_node->field_book_version[LANGUAGE_NONE][0]['value'] = $new_version;
  node_save($book_node);
  
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
* @param $book_node the book node at top most level where all children are placed in
* @param $root_node the node the is currently beeing exported with its children
* @param $options some export options filled from export dialog
*/
function _erpal_book_helper_create_pdf($book_node, $root_node, $options) {
  global $user;
  module_load_include('inc', 'erpal_book_helper', 'inc/config');
  $params = array(
    'title' => $root_node->title,
    'author' => _erpal_print_get_author($root_node),
    'skip_pdf_header_frontpage' => _erpal_book_helper_skip_pdf_header_frontpage(),
  );
  
  $pdf_object = erpal_print_prepare_tcpdf($params);
  
  if (!$pdf_object)
    return false;
  
  $html = _erpal_book_helper_get_child_html($pdf_object, $book_node, $root_node, $options); 

  //theme the frontpage as separate page and add it to the frontpages array
  $theme_options = array(
    'estimations' => array(
      'task' => $options['export_estimations']['task'],
      'page' => $options['export_estimations']['page'],
      'total' => $options['total_estimation'],      
    ),
    'skipp_root' => false,
    'set_bookmark' => false,
    'depth' => 1,
    'add_nids' => false, //no nid at frontpage title
  );
  
  _erpal_book_helper_replace_tokens($root_node); //replace all tokens
  $frontpage_html = theme('erpal_books_book_pdf_html', array('node' => $root_node, 'pdf_object' => $pdf_object, 'options' => $theme_options, 'counter' => false));
  //line bracks as <br>
  $frontpage_html = nl2br($frontpage_html);  
   
    
  $total_estimation = $html['total_estimation'];
  $html = $html['html'];
  
  //now replace the estimation token in the html
  $data = array('total_estimation' => $total_estimation);
  $html = token_replace($html, $data);  

  $frontpage_html = token_replace($frontpage_html, $data);  
  
  $frontpages[] = $frontpage_html; 
  //now put HTML content to PDF rendering
  
  $pdf_method = $options['pdf_create_method'];

  if ($pdf_method == 'attach') {    
    $doc_uri = _erpal_docs_folder_uri();    
  } elseif ($pdf_method == 'download') {
    $doc_uri = false;
  }
  
  $version = $book_node->field_book_version[LANGUAGE_NONE][0]['value'] ? $book_node->field_book_version[LANGUAGE_NONE][0]['value'] : 1;
  $basename = _erpal_docs_make_filename($root_node->title."_".$version, 'pdf');
  
  $doc_file = _erpal_print_html_as_pdf($html, $doc_uri, $basename, $params, $pdf_object, true, $frontpages);
  
  if (!$doc_file) {
    drupal_set_message(t('There has been an error while creating you pdf. PDF not created.'), 'error');
    drupal_goto('node/'.$root_node);
  }
 
  //now attach the file to the root node (not to the book node!)
  $file_node = false;
  if (isset($root_node->field_asset_files[LANGUAGE_NONE][0]['target_id'])) {
    $file_nid = $root_node->field_asset_files[LANGUAGE_NONE][0]['target_id'];  //if exists, this node will be updated with its file
    
    $file_node = node_load($file_nid);
  }

  $file_node = _erpal_docs_attach_file($root_node, $doc_file, $file_node, false);
  
  return $file_node;
}

/**
* Recursive function to get HTML of all Child nodes
* @param depth_counter is the counter to create the enumeration for each page
* @param $skipp_root this is the signal that the given $root_node page will not be exported
*/
function _erpal_book_helper_get_child_html($pdf_object, $book_node, $root_node, $options, $depth_prefix='', $depth_counter=0, $iteration_counter=0, $skipp_root=true){
  
  //prepare fields so they can be included in entitiy field query easily
  $child_nodes = _erpal_book_helper_get_children($book_node, $root_node, $options);
  $theme_options = array(
    'estimations' => array(
      'task' => $options['export_estimations']['task'],
      'page' => $options['export_estimations']['page'],
      'total' => $options['total_estimation'],      
    ),
    'skipp_root' => $skipp_root,
    'set_bookmark' => true,
    'depth' => $depth_counter ? $depth_counter : 1,
    'add_nids' => $options['add_nids'],
  );
  
  //save the body, if we dont do that, the content token will be replaced in the real node body....dont know why...??!
  //######### Important order of code!###############
  $body = '';
  if (isset($root_node->body[LANGUAGE_NONE][0]['value'])) {
    $body = $root_node->body[LANGUAGE_NONE][0]['value'];
    _erpal_book_helper_replace_tokens($root_node); //replace all tokens
  }    
  
  $this_html = '';
  if (!$skipp_root) {  
    //prepare the counter for table of contents enumeration
    $node_counter = $depth_prefix;
    if ($node_counter) {
      $node_counter .= '.';
    }
    $node_counter .= $iteration_counter ? $iteration_counter : 1;

    $this_html = theme('erpal_books_book_pdf_html', array('node' => $root_node, 'pdf_object' => $pdf_object, 'options' => $theme_options, 'counter' => $node_counter));
    //line bracks as <br>
    $this_html = nl2br($this_html);
  } else
    $node_counter = '';
  
  $root_node->body[LANGUAGE_NONE][0]['value'] = $body; // set the body back again!
  //######## End ############################
  
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
  $iteration_counter = 0;
  $depth_counter++;
  foreach ($child_nodes as $child_node) {
    //get recusive HTML of children
    $depth_prefix = $node_counter;
    $iteration_counter++;  //next recursion
    $child_html = _erpal_book_helper_get_child_html($pdf_object, $book_node, $child_node, $options, $depth_prefix, $depth_counter, $iteration_counter, false);

    $estimation += $child_html['total_estimation'];
    $child_html = $child_html['html'];
    $html .= $child_html;
  }
  $depth_counter--;

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
  $pdf_object = $variables['pdf_object'];
  
  $node = $variables['node'];
  $title = $node->title;
  $counter = $variables['counter'];
  $depth = $variables['options']['depth'];
  
  $body  = '';
  if (isset($node->body[LANGUAGE_NONE][0]['value']))
    $body = $node->body[LANGUAGE_NONE][0]['value'];   
  
  $estimations = $variables['options']['estimations'];
  
  $duration = _erpal_book_helper_get_estimation($node, $estimations);
  
  $variables['body'] = $body;
  $variables['title'] = $title;
  $variables['duration'] = $duration;
  $variables['nid'] = $node->nid;
  $variables['bookmark'] = false;

  if (isset($variables['options']['set_bookmark']) && $variables['options']['set_bookmark']) {
    
    $title = $counter." ".$title;
    $variables['title'] = $title;
    $depth--; //Start at 0 for tcpdf 
    $params = $pdf_object->serializeTCPDFtagParameters(array($title,$depth,0,'','',array(128,128,0)));  //needed later for table of contents 
    $bookmark = '<tcpdf method="Bookmark" params="'.$params.'" />';
    $variables['bookmark'] = $bookmark;
  }
  
    
}
