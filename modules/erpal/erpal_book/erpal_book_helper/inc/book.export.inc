<?php

/**
* @file handels all functions needed to export a book or a book-page
*/

/**
* Menu Callback for url to export a book or a book page
*/
function _erpal_book_helper_book_export_menu_callback($node) {
  return drupal_get_form('erpal_book_helper_export_form', $node);
}

/**
* Form to select options to export a book or a book-page
*/
function erpal_book_helper_export_form($form, $form_state, $node) {
  //it doesn't matter if we have to deal with a book node or a book-page node, because iteration
  //all nodes recursively works with the field_book_parent field only, which is attached to both node types.
  $form = array();
  module_load_include('module', 'erpal_document_export');
  $plugin_list = erpal_document_export_get_plugin_list();
  
  $values = _erpal_book_helper_export_form_load_values();
  
  if(count($plugin_list)==0){
    $form['export_plugin'] = array(
      '#markup' => t('No document export plugins available'),
    );
  } else {
    $form['export_plugin'] = array(
      '#type' => 'select',
      '#title' => t('Export as'),
      '#options' => $plugin_list,
      '#default_value' => 'document_ooxml_export',
    );
    
    
    $pages_options = array(
      'export_frontpage' => t('Export frontpage'),
      'export_book_node' => t('Export book node'),
      'export_toc' => t('Export table of contents'),
      'export_comments' => t('Export comments'),
    );
    
    // Check if there is a project attached to 
    // the node and add options to export tasks
    $book_node = _erpal_book_helper_export_get_book_node($node);
    if($book_node){
      $projects = _erpal_book_helper_get_referencing_project($book_node->nid);
      if($projects !== NULL){
        $pages_options['export_tasks'] = t('Export attached tasks');
        $pages_options['export_all_tasks'] = t('Export all tasks of the referencing project');
        // Attach nid for later use in submit function
        $form['project_nid'] = array(
          '#type' => 'value',
          '#value' => $projects[0],
        );
      }
    }
    
    $form['pages'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Pages to export'),
      '#options' => $pages_options,
      '#default_value' => ($values) ? $values['pages'] : array(),
    );
    
    $form['options'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Export options'),
      '#options' => array(
        'title_count' => t('Automatically nummerize titles'),
        'page_breaks' => t('Page break after each book page'),
        'add_nids' => t('View nid of each node'),
        'ignore_exclude' => t('Ignore exclude flags'),
      ),
      '#default_value' =>  ($values && isset($values['options'])) ? $values['options']: array(),
    );
       
    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $node->nid,
    );
    
      //Put all the time options in a fieldset
  $form['estimations'] = array(
    '#type' => 'fieldset',
    '#title' => t('Estimations'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
    
    $estimation_options = array('page' => t('To pages'), 'task' => t('To tasks'));
    $form['estimations']['export_estimations'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Attach estimations'),
      '#options' =>  $estimation_options,
      '#default_value' =>  ($values && isset($values['export_estimations'])) 
        ? $values['export_estimations'] : array(),
    );
    
    $total_estimation = array('page' => t('From pages'), 'task' => t('From tasks'));
    $form['estimations']['total_estimation'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Calculate total estimation token'),
      '#options' =>  $total_estimation,
      '#default_value' =>  ($values && isset($values['total_estimation'])) 
        ? $values['total_estimation'] : array(),
    );
        
    $form['preview'] = array(
      '#type' => 'submit',
      '#value' => t('Download document'),
    );
    
    $form['attach'] = array(
      '#type' => 'submit',
      '#value' => t('Save and attach to node'),
    );
    
  }
  return $form;
}


/**
* Submit handler for exporting a book or a book-page
*/
function erpal_book_helper_export_form_submit($form, $form_state) {
  
  $values = $form_state['values'];
  _erpal_book_helper_export_form_save_values($form_state['values']);
  
  $root_nid = $values['nid'];
  $root_node = node_load($root_nid);
   
  //get the book node
  $book_node = _erpal_book_helper_export_get_book_node($root_node);

  // get data to export
  $pages_array = _erpal_book_helper_export_get_pages($book_node, $root_node, $values);
  // print all tasks that are not children of a book page
  if(isset($values['pages']['export_all_tasks']) 
      && $values['pages']['export_all_tasks']){
    $project_node = node_load($values['project_nid']);
    $tasks = _erpal_projects_helper_get_tasks_of_project_having_no_parent($project_node); 
    foreach ($tasks as $nid) {
      $task = node_load($nid);      
      $task_export = _erpal_book_helper_export_get_pages($book_node, $task, $values);
      
      $pages_array['estimation']['task'] += $task_export['estimation']['task'];
      $pages_array['estimation']['page'] += $task_export['estimation']['page'];
      $pages_array['pages'] = array_merge($pages_array['pages'], $task_export['pages']);
    }
  } 

  // Replace estimation token on all pages
  $pages = array();
  $total_estimation = _erpal_book_helper_export_calculate_estimation($pages_array['estimation'], $values);
  $tokens = array('total_estimation' => $total_estimation);
  foreach ($pages_array['pages'] as $page) {
    if(is_array($page)) {
      $page['body'] = token_replace($page['body'], $tokens);
      $pages[] = $page;
    }
    else {
      $pages[] = token_replace($page, $tokens);
    }

  }
    
  // if "export book node" is selected, create html for book node and replace estimation token
  if($values['pages']['export_book_node']){
    $new_values = $values;
    $new_values['options']['add_nids'] = FALSE;
    $book_node_html =_erpal_book_helper_export_get_page($book_node, $new_values, 1);
    if(is_array($book_node_html)) {
      $book_node_html['body'] = token_replace($book_node_html['body'], $tokens);
    }
    else {
      $book_node_html = token_replace($book_node_html, $tokens);
    }
    array_unshift($pages, $book_node_html);
  } 

  //Prepare export data
  $export_data['pages'] = $pages;
  $export_data['toc'] = $values['pages']['export_toc'];
  $export_data['page_breaks'] = $values['options']['page_breaks'];
  $export_data['options'] = $values['options'];

  if(isset($values['pages']['export_frontpage']) && $values['pages']['export_frontpage']){   
    $frontpage = _erpal_book_helper_export_get_frontpage($book_node, $values);   
    $export_data['frontpage'] = $frontpage;
  } else { 
    $export_data['frontpage'] = FALSE;
  }
  
  $plugin_name = $values['export_plugin'];
  
  $plugin_instance = erpal_document_export_get_plugin_instance($plugin_name, $export_data);
  
  if(!$plugin_instance){
  	drupal_set_message(t('Plugin !plugin_name for export could not found', array('!plugin_name' => $plugin_name)), 'error');
    return;
  }

  $version = $book_node->field_book_version[LANGUAGE_NONE][0]['value'] 
    ? $book_node->field_book_version[LANGUAGE_NONE][0]['value'] : 1;
    
  $filename = _erpal_docs_make_filename($root_node->title."_".$version, $plugin_instance->fileExtension());
  
  
  if($values['op'] == $values['preview']){
    $plugin_instance->stream($filename);
  } 
  
  elseif ($values['op'] == $values['attach']) {
    $uri = _erpal_docs_folder_uri();
    
    $doc_file = $plugin_instance->save($uri, $filename);
    //now attach the file to the root node (not to the book node!)
    $file_node = false;
    if (isset($root_node->field_asset_files[LANGUAGE_NONE][0]['target_id'])) {
      $file_nid = $root_node->field_asset_files[LANGUAGE_NONE][0]['target_id'];  //if exists, this node will be updated with its file
      
      $file_node = node_load($file_nid);
    }
    $file_node = _erpal_docs_attach_file($root_node, $doc_file, $file_node, false);
    
    
    // update the version of the book node +1
    $new_version = isset($book_node->field_book_version[LANGUAGE_NONE][0]['value']) ? $book_node->field_book_version[LANGUAGE_NONE][0]['value'] +1 : 2;
    $book_node->field_book_version[LANGUAGE_NONE][0]['value'] = $new_version;
    node_save($book_node);
    
    if (is_object($file_node)) {
      drupal_set_message(t('Your export has been created successfully!'));
      drupal_goto('node/'.$file_node->nid);
    }else
      drupal_set_message(t('Sorry, but there was an error while creating your export.'), 'error');
    
    drupal_goto('node/'.$root_node->nid);
  }
}

/**
 * Returns the book_node of a book page
 */ 
function _erpal_book_helper_export_get_book_node($root_node){
  $book_node = false;  
  if ($root_node->type == 'erpal_book') {
    $book_node = $root_node;
  } elseif ($root_node->type == 'erpal_book_page') {
    $book_nid = $root_node->field_book_ref[LANGUAGE_NONE][0]['target_id'];
    $book_node = node_load($book_nid);
  }
  return $book_node;
}



function _erpal_book_helper_export_calculate_estimation($estimations, $values){
  $estimation = 0;
  if($values['total_estimation']['page']) $estimation += $estimations['page'];
  if($values['total_estimation']['task']) $estimation += $estimations['task'];
  return $estimation;
}

function _erpal_book_helper_export_get_header(){

    // set header image
    $logo_fid = variable_get('my_document_logo', FALSE);
    $logo = ($logo_fid) ? file_load($logo_fid) : FALSE;
    
    if($logo){
      $path = file_create_url($logo->uri);
      $info = image_get_info($logo->uri);
      $size = array(
        'width' => $info['width'],
        'height' => $info['height'],
      );
      //$path = substr($path, strlen($GLOBALS['base_url']));
      $html = theme('erpal_document_export_header', array('logo' => $path));
      return array(
        'html' => $html,
        'size' => $size,
      );
    }
    return FALSE;
}

/**
 * Function to save some of the configs of the export form in the database
 */
function _erpal_book_helper_export_form_save_values($values){
  $save['pages'] = $values['pages'];
  $save['options'] = $values['options'];
  $save['export_estimations'] = $values['export_estimations'];
  $save['total_estimation'] = $values['total_estimation'];
  variable_set('erpal_book_helper_export_form_config', serialize($save));
}

/**
 * Function to get the configuration of the export form
 */
function _erpal_book_helper_export_form_load_values(){
  $values = unserialize(variable_get('erpal_book_helper_export_form_config', FALSE));
  return (is_array($values))? $values : FALSE;
}




/**
* Recursive function to get HTML of all Child nodes
* @param depth_counter is the counter to create the enumeration for each page
* @param $skipp_root this is the signal that the given $root_node page will not be exported
*/
function _erpal_book_helper_export_get_pages($book_node, $root_node, $options, $depth = 0, $prefix = ''){
  // Get estimation from current node
  $estimation = _erpal_book_helper_export_get_estimation($root_node);
  
  // Get current page  
  if ($root_node->type == 'erpal_book_page'){
    $pages = array(
      _erpal_book_helper_export_get_page($root_node, $options, $depth, $estimation['page'], $prefix),
    );
  } else if ($root_node->type == 'erpal_task'){
    $pages = array(
      _erpal_book_helper_export_get_page($root_node, $options, $depth, $estimation['task'], $prefix),
    );
  } else $pages = array();
 
  // export comments
  if(isset($options['pages']['export_comments']) 
      && $options['pages']['export_comments']){
    $comment_cids = comment_get_thread($root_node, '', 1000);
    foreach ($comment_cids as $cid) {
      $pages[] = _erpal_document_export_get_comment($cid, $options);
    }
  }
    
  // Get child nodes
  $child_nodes = _erpal_book_helper_get_children($book_node, $root_node, $options);

  // Recursion anchor: If no child nodes return $estimation and $pages
  if (count($child_nodes) == 0) {
    
    return array(
      'pages' => $pages,
      'estimation' => $estimation,
    );
    
  } else {
    $count = 0;
    foreach ($child_nodes as $child_node) {
      $count++;
      $new_prefix = $prefix . $count . '.';    
      // Go into the recursion to get content of child nodes
      $return = _erpal_book_helper_export_get_pages($book_node, $child_node, $options, $depth+1, $new_prefix);
      
      // Add own pages to the result
      $pages = array_merge($pages, $return['pages']);
      // Add estimation from child nodes to $return['estimation']
      $estimation['task'] += $return['estimation']['task'];
      $estimation['page'] += $return['estimation']['page'];
    }
    
    return array(
      'pages' => $pages,
      'estimation' => $estimation,
    );
  }
}

function _erpal_book_helper_export_get_page($book_node, $options, $depth, $estimation = 0, $prefix = ''){
  // save the body, if we dont do that, the content token will be 
  // replaced in the real node body....dont know why...??!
  // ######### Important order of code!###############  
  $body = '';
  if (isset($book_node->body[LANGUAGE_NONE][0]['value'])) {
    $body = $book_node->body[LANGUAGE_NONE][0]['value'];
    _erpal_book_helper_replace_tokens($book_node); //replace all tokens
  }
  
  if(($book_node->type == 'erpal_book_page') && $options['export_estimations']['page']){
    $page['estimation'] = $estimation;
  } else if(($book_node->type == 'erpal_task') && $options['export_estimations']['task']){
    $page['estimation'] = $estimation;
  }
  
  $wrapper = entity_metadata_wrapper('node', $book_node);
  
  // Add/generate page title.
  $page['title'] = $wrapper->title->value();
  if (!empty($options['options']['title_count']) && !empty($prefix) && $options['export_plugin'] != 'document_odt_export') {
    $page['title'] = $prefix . ' ' . $wrapper->title->value();
  }
  
  //  get with raw because otherwise the the safe value is printed and tokens are not replaced
  $page['body'] = (isset($book_node->body[LANGUAGE_NONE])) 
    ? $wrapper->body->value->raw() : ' ';
  $page['nid'] = $wrapper->nid->value();
  $page['add_nids'] = $options['options']['add_nids'];
  
  $page['depth'] = $depth;
  
  $book_node->body[LANGUAGE_NONE][0]['value'] = $body; // set the body back again!
  //######## End ############################
  if ($options['export_plugin'] == 'document_odt_export') {
    return $page;
  }
  
  return theme('erpal_document_export_page', $page);
}


function _erpal_book_helper_export_get_frontpage($book_node, $options){           
  $wrapper = entity_metadata_wrapper('node', $book_node);
    
  $page['title'] = $wrapper->title->value();
  $page['date'] = erpal_date_formatted($wrapper->changed->value());
  
  // set header image
  $logo_fid = variable_get('erpal_book_helper_frontpage_logo', FALSE);
  $logo = ($logo_fid) ? file_load($logo_fid) : FALSE;
  
  if($logo){
    $page['logo'] = file_create_url($logo->uri);
  }
  
  
  if(!empty($book_node->field_address_id)){
      
    $fid = $wrapper->field_address_id->value();
    $entities = entity_load('field_collection_item', array($fid));
    $field_collection = reset($entities);
    $fc_wrapper = entity_metadata_wrapper('field_collection_item', $field_collection); 
     
    $customer = array();
    $customer['name'] = $fc_wrapper->field_address_name->value();
    if (!$customer['name']) {
      $contact_node = $wrapper->field_contact_ref->value();
      $customer['name'] = $contact_node->title;
    }
    $customer['addition'] = $fc_wrapper->field_addition_to_address->value();
    $customer['street'] = $fc_wrapper->field_street->value();
    $customer['zip'] = $fc_wrapper->field_zip_code->value();
    $customer['city'] = $fc_wrapper->field_city->value();
    $country_term = $fc_wrapper->field_country_term->value();

    if ($country_term) {
      $customer['country'] = $country_term->name;
    }
    
    $page['address'] = $customer; 
  }

  if ($options['export_plugin'] == 'document_odt_export') {
    return $page;
  }

  return theme('erpal_document_export_frontpage', $page);
}



/**
* Returns the estimation from a book_page node or a task node
*/
function _erpal_book_helper_export_get_estimation($node) {

  $duration = array(
    'page' => 0,
    'task' => 0,
  );
  if ($node->type == 'erpal_task') {
      if (isset($node->field_estimated_time[LANGUAGE_NONE][0]['value']))
        $duration['task'] = $node->field_estimated_time[LANGUAGE_NONE][0]['value'];
  } elseif ($node->type == 'erpal_book_page') {
      if (isset($node->field_estimated_duration[LANGUAGE_NONE][0]['value']))
        $duration['page'] = $node->field_estimated_duration[LANGUAGE_NONE][0]['value'];
  }
  return $duration;
}


