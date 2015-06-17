<?php

/**
 * @file contains all functions to export release documents
 */

function _erpal_project_release_release_export_menu_callback($release_node) {

  if ($release_node->type != 'erpal_project_release') {  
    drupal_goto('node/'.$release_node);
  };
  
  
  return drupal_get_form('erpal_project_release_release_export_form', $release_node);
}

/**
 * Config form shown before release export is started
 */
function erpal_project_release_release_export_form($form, $form_state, $node) {
  
  //it doesen't matter if we have to deal with a book node or a book-page node or a task, because traversion
  //all nodes recursively works with the field_parent field only, which is attached to both node types.
  $form = array();
  module_load_include('module', 'erpal_document_export');
  $plugin_list = erpal_document_export_get_plugin_list();
  
  $values = _erpal_project_release_export_form_load_values();
  
  if(!count($plugin_list)){
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
    
    $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $pages_options = array(
      'export_frontpage' => t('Print frontpage'),
      'export_toc' => t('Print table of contents'),
      'export_header' => t('Print document header'),
      'export_footer' => t('Print document footer'),
      'export_comments' => t('Export comments'),
    );
    
    //if there is at least one book attached to the releases project, as if user wants to
    //export these pages, too
    $project_node = node_load($project_nid);

    $book_nid = isset($project_node->field_books_ref[LANGUAGE_NONE][0]) ? $project_node->field_books_ref[LANGUAGE_NONE][0]['target_id'] : false;
    if ($book_nid)    
      $pages_options['export_book_pages'] = t('Print specification');
    
    $form['project_nid'] = array(
      '#type' => 'value',
      '#value' => $project_nid,
    );
    
    
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
        //'page_numbers' => t('Print page numbers (TODO)'),
        'page_breaks' => t('Page break after each book page'),
        'add_nids' => t('View nid of each node'),
        'ignore_exclude' => t('Ignore exclude flags'),
      ),
      '#default_value' =>  ($values && isset($values['options'])) ? $values['options']: array(),
    );
       
    //save nid for later use
    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $node->nid,
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
* Submit handler for exporting a release node
*/
function erpal_project_release_release_export_form_submit($form, $form_state) {
  
  $values = $form_state['values'];
  _erpal_project_release_export_form_save_values($form_state['values']);
  
  $release_nid = $values['nid'];
  $release_node = node_load($release_nid);
 
  //get the project node
  $project_nid = $release_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  if (!$project_nid) {
    drupal_set_message(t('No project found for this release'));
  }
  
  // get data to export
  //first we need all tasks.
  $task_nids = _erpal_project_release_get_tasks($release_nid);
  //die(print_r($task_nids));
  //if the user wants to export the specification, we also need to get the book_pages of tasks untill the top most level
  $export_book_pages = $values['pages']['export_book_pages'];

  if ($export_book_pages) {
    //get the book pages of a task and its parent pages
    $parent_pages = array();
    $book_pages = array();
    $parent_types = array('erpal_task', 'erpal_book_page');
    foreach ($task_nids as $nid) {
      //we also need to get parent tasks, because if we have subtasks in cluded in the release but not the parent task, we will not get
      //the book page that is referenced to the parents task. We will remove it later.      
      $page_nids = erpal_lib_helper_parents_by_children($nid, 'field_parent', $parent_types, true, true); //deep search, flat

      if (is_array($page_nids) && count($page_nids)) {
        $parent_pages[$nid] = $page_nids;
       
        $base_data = erpal_lib_helper_node_base_data($page_nids);
        
        //first get all book pages that are included. If there are some, get the tasks of these pages (to keep the order) 
        //and remove the tasks that are not part of the releas        
        foreach ($parent_pages[$nid] as $key=>$page_nid) {
          $type = $base_data[$page_nid]->type;
          
          if ($type == 'erpal_book_page') {
            $book_pages[] = $page_nid;
          }
        }
      }
    }
    
    //now, the parent pages are in $parent_pages array, in first array dimension the key is the id of the task
    //as substructure we have a nested array. Put the in the right order so we will have books first and then tasks with comments
    $tree_pages = array();
    $child_types = $parent_types;
    if (count($book_pages)) {
      foreach ($book_pages as $nid) {
        $children_tree = erpal_lib_helper_children_by_parent($nid, 'field_parent', $child_types, true, false); 
        $tree_pages[$nid] = $children_tree;
      }        
    }
    
    //now, we have the tree structure. We will recursive traverse it so flat array with the right order of 
    //book pages, tasks (comments will be added after that.
    $flat_pages = array();
    erpal_lib_helper_flatten_array($tree_pages, $flat_pages);
    
    //remove tasks that have been added in parent structure to get all book pages but that are not part of the release
    $base_data = erpal_lib_helper_node_base_data($flat_pages);
    $final_pages = array();
    foreach ($base_data as $nid=>$base_obj) {
      
      if ($base_obj->type != 'erpal_task')
        $final_pages[] = $nid;  //specification, book_page
      elseif ($base_obj->type == 'erpal_task' && in_array($nid, $task_nids))
        $final_pages[] = $nid;  //we add this task nid, because it was initially part of the release
    } 
    
    //now ensure that not only task that have a parent_book page are included but all other tasks included in the release, too
    foreach ($task_nids as $nid) {
      if (!in_array($nid, $final_pages))
        $final_pages[] = $nid;
    }
    
    
  } else {
    //no specifications, just task
    $parent_pages = $task_nids;
    $final_pages = $task_nids;
  }
  
  

  //Now render pages, tasks and comments
  $pages = array();
  foreach ($final_pages as $nid) {
    $node = node_load($nid);
    $wrapper = entity_metadata_wrapper('node', $node);
    $page = array();
    $page['title'] = $wrapper->title->value();
    $page['body'] = (isset($node->body[LANGUAGE_NONE])) ? $wrapper->body->value->raw() : ' ';
    $page['nid'] = $wrapper->nid->value();
    
    $page['add_nids'] = $values['options']['add_nids'];
    
    //render the page
    if ($node->type == 'erpal_book_page')
      $page_rendered = theme('erpal_release_docu_book_page', $page);
    elseif ($node->type == 'erpal_task')
      $page_rendered = theme('erpal_release_docu_task', $page);
    else 
      $page_rendered = '### NO RENDERER FOR TYPE "'.$node->type.'" ####';
    
    $pages[] = $page_rendered;
    
    //add comments
    if (isset($values['pages']['export_comments']) && $values['pages']['export_comments']){
      $comment_cids = comment_get_thread($node, '', 1000);
      foreach ($comment_cids as $cid) {
        $pages[] = _erpal_document_export_get_comment($cid);
      }
    }
  }

  //Prepare export data
  $export_data['pages'] = $pages;
  $export_data['toc'] = $values['pages']['export_toc'];
  $export_data['page_breaks'] = $values['options']['page_breaks'];

  // if "export frontpage" is selected, create frontpage and replace estimation token

  if($values['pages']['export_frontpage']){
    $frontpage = _erpal_project_release_export_get_frontpage($release_node, $values);
    $export_data['frontpage'] = $frontpage;
  } else $export_data['frontpage'] = FALSE;

  // Print header image if "export header" is selected
 
  if($values['pages']['export_header']){
    // Check if release export uses own header and footer
    $header = _erpal_project_release_export_get_header();
    if($header) $export_data['header'] = $header;
  }

  // print footer if "export header" is selected
  if($values['pages']['export_footer']){
    $footer = _erpal_project_release_export_get_footer();
    if($footer) 
      $export_data['footer'] = $footer;    
  }

  // 
  $plugin_name = $values['export_plugin'];
  $plugin_instance = erpal_document_export_get_plugin_instance($plugin_name, $export_data);
  
    
  $filename = _erpal_docs_make_filename($release_node->title, 'docx');
  
  
  if($values['op'] == $values['preview']){
    $plugin_instance->stream($filename);
  } 
  
  elseif ($values['op'] == $values['attach']) {
    $uri = _erpal_docs_folder_uri();
    $doc_file = $plugin_instance->save($uri, $filename);
    //now attach the file to the root node (not to the book node!)
    $file_node = false;
    if (isset($release_node->field_asset_file[LANGUAGE_NONE][0]['target_id'])) {
      $file_nid = $release_node->field_asset_file[LANGUAGE_NONE][0]['target_id'];  //if exists, this node will be updated with its file
      
      $file_node = node_load($file_nid);
    }
    $file_node = _erpal_docs_attach_file($release_node, $doc_file, $file_node, false, 'field_asset_file');  
    
    if (is_object($file_node)) {
      drupal_set_message(t('Your export has been created successfully!'));
      drupal_goto('node/'.$file_node->nid);
    }else
      drupal_set_message(t('Sorry, but there was an error while creating your export.'), 'error');
    
    drupal_goto('node/'.$release_node->nid);
  }
}

/**
 * Returns the footer
 */
function _erpal_project_release_export_get_footer() {
  
  $overwrite = variable_get('erpal_project_release_overwrite_logo_and_footer', FALSE);    
  $footer = $overwrite ? variable_get('erpal_project_release_document_footer', '') : variable_get('erpal_print_document_footer', '');
  
  return $footer;
}

/*
 * return the header used for the export
 */
function _erpal_project_release_export_get_header(){
  $overwrite = variable_get('erpal_project_release_overwrite_logo_and_footer', FALSE);
    
  // set header image
  $logo_fid = ($overwrite) 
    ? variable_get('erpal_project_release_document_logo', FALSE)
    : variable_get('my_document_logo', FALSE);
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
 * Render the Frontpage
 */
function _erpal_project_release_export_get_frontpage($release_node, $options){
    
  // @TODO: save the body, if we dont do that, the content token will 
  // be replaced in the real node body....dont know why...??!
  // ######### Important order of code!###############  
  $body = '';
  if (isset($release_node->body[LANGUAGE_NONE][0]['value'])) {
    $body = $release_node->body[LANGUAGE_NONE][0]['value'];
  }
  
  $wrapper = entity_metadata_wrapper('node', $release_node);
  $page['title'] = $wrapper->title->value();
  // get with raw because otherwise the the safe value is printed and tokens are not replaced
  $page['body'] = (isset($release_node->body[LANGUAGE_NONE])) ? $wrapper->body->value->raw() : ' ';
  $page['nid'] = $wrapper->nid->value();
  $page['add_nids'] = $options['options']['add_nids'];
  
  $release_node->body[LANGUAGE_NONE][0]['value'] = $body; // set the body back again!
  //######## End ############################
  
  return theme('erpal_document_export_frontpage', $page);
}

/**
 * Function to save some of the configs of the export form in the database
 */
function _erpal_project_release_export_form_save_values($values){
  $save['pages'] = $values['pages'];
  $save['options'] = $values['options'];
 
  variable_set('erpal_project_release_export_form_config', serialize($save));
}

/**
 * Function to get the configuration of the export form
 */
function _erpal_project_release_export_form_load_values(){
  $values = unserialize(variable_get('erpal_project_release_export_form_config', FALSE));
  return (is_array($values))? $values : FALSE;
}