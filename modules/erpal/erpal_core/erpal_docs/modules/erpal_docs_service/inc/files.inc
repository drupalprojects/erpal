<?php

/**
 * @file functions uses for the file ressource
 */
function _erpal_docs_service_file_download($erpal_file_nid) {
  //download the file attached to the current nid
  $file_node = node_load($erpal_file_nid);
  $file = isset($file_node->field_docs_file[LANGUAGE_NONE][0]) ? $file_node->field_docs_file[LANGUAGE_NONE][0] : false;
  if ($file) {

    $fid = $file['fid'];
    $file = file_load($fid);
    $uri = $file->uri;
    $path = file_create_url($uri);
    return array('path' => $path);
  }

  return false;
}

/**
 * Check access for the ressource to download a file (access on a concrete file is checked)
 * with node_access
 */
function _erpal_docs_service_file_download_access($op, $args) {
  $nid = isset($args[0]) ? $args[0] : false;
  if (!$nid)
    return false;
  if (is_numeric($nid))
    $node = node_load($nid);
  else
    $node = $nid;
  return node_access($op, $node);
}

/**
 * Check access for contact node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_docs_service_file_access($op, $args = NULL) {
  return node_access($op, 'erpal_file');
}

/**
 * callback for returning a file
 * 
 * @param int $nid the node id of the file to return
 * @param bool $details whether to return detailed information, defaults to true
 * @param bool $include_children whether or not to include children
 * @return array the formatted file node for output
 */
function _erpal_docs_service_file_retrieve($nid, $details = TRUE, $include_children = FALSE) {
  return _erpal_docs_service_file_out($nid, $details, $include_children);
}

/**
 * callback for returning a list of files
 * 
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether to return detailed information, defaults to true
 * @param bool $include_children whether or not to include children
 * @return array array of files
 */
function _erpal_docs_service_file_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = FALSE, $include_children = FALSE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'erpal_file')
      ->range((int) $start, (int) $count)
      ->propertyCondition('changed', (int) $changed_since, '>=');

  $entities = $query->execute();

  $files_out = array();

  if (!empty($entities['node'])) {
    foreach (array_keys($entities['node']) as $nid) {
      $files_out[] = _erpal_docs_service_file_out($nid, $details, $include_children);
    }
  }

  return $files_out;
}

/**
 * retrieves a file node and generates corresponding response output
 * @param int $nid the node id of the file to return
 * @param bool $details whether to return detailed information, defaults to true
 * @param bool $include_children whether or not to include children
 * @return array the formatted file node for output
 */
function _erpal_docs_service_file_out($nid, $details = TRUE, $include_children = FALSE) {

  // load contact node
  $file = node_load($nid);
  
  // if given node id is not a contact, return error
  if ($file->type !== 'erpal_file') {
    return services_error('failed loading node. nid ' . $nid . ' is not a file', 400);
  }

  // load wrapper
  $file_wrapper = entity_metadata_wrapper('node', $file);

  // base data
  $files_out = array();
  $files_out['title'] = $file->title;
  $files_out['created'] = (int) $file->created;
  $files_out['changed'] = (int) $file->changed;
  $files_out['url'] = url('rest/erpal_files/erpal_file/' . $file->nid, array('absolute' => TRUE));

  // revision
  $files_out['revision_timestamp'] = (int) $file->revision_timestamp;
  $files_out['revision_id'] = (int) $file->revision_uid;

  // file data
  $file_array = $file_wrapper->field_docs_file->value();
  if (!empty($file_array)) {
    $files_out['filename'] = $file_array['filename'];
    $files_out['mimetype'] = $file_array['filemime'];
    $files_out['filesize'] = (int) $file_array['filesize'];
    $files_out['download_url'] = file_create_url($file_array['uri']);
    $files_out['description'] = ($file_array['description']) ? $file_array['description'] : '';
    $files_out['fid'] = (int) $file_array['fid'];
  }
  
  if ($details) {

    // comments
    $files_out['comments'] = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'comment')
        ->propertyCondition('nid', $nid);
    $entities = $query->execute();
    if (!empty($entities['comment'])) {
      foreach (array_keys($entities['comment']) as $cid) {
        $comment = comment_load($cid);
        if ($comment) {
          $comment_body = $comment->comment_body[LANGUAGE_NONE][0];
          //if (!$include_children || (strtolower($include_children) === 'false')) {
          if ($include_children) {
            $comment_out = array(
              'created' => (int) $comment->created,
              'changed' => (int) $comment->changed,
              'cid' => (int) $comment->cid,
              'subject' => ($comment->subject) ? $comment->subject : '',
              'name' => ($comment->name) ? $comment->name : '',
              'registered_name' => ($comment->registered_name) ? $comment->registered_name : '',
              'comment_body' => $comment_body['value'],
              'comment_format' => $comment_body['format'],
            );
          } else {
            $comment_out = url('rest/basic/erpal_comment/' . $comment->cid, array('absolute' => TRUE));
          }
          array_push($files_out['comments'], $comment_out);
        }
      }
    }
  }

  return $files_out;
}


// Experimental implementation of upload features.
/**
 * Callback for create a single file.
 * 
 * @param array $data  The json payload to create the file with. 
 *                      {
 *                        'tags':       ['[TAG]', '[TAG]', ...],
 *                        'filename':   '[FILENAME]',
 *                        'binary':     '[BASE64 ENCRYPTION OF THE FILE]
 *                      }
 * @return array        A result array on success.
 *                      [
 *                        'success': [BOOLEAN],
 *                        'URL':     [URL TO THE NEW FILE OBJECT]
 *                      ]
 */
function _erpal_docs_service_file_create($data) {
 
  $data = (object)$data;
  
  if (! isset($data->tags)) {
    services_error(
      'Missed tags.'
    );
    return;
  }
  
  if (! isset($data->filename)) {
    services_error(
      'Missed filename.'
    );
    return;
  }
  
  if (! isset($data->binary)) {
    services_error(
      'Missed file binary data.'
    );
    return;
  }
  drupal_load('module', 'erpal_docs_helper');
  $file_uri       = _erpal_docs_service_upload_path($data->filename); 
  $file           = file_save_data(base64_decode($data->binary), $file_uri, FILE_EXISTS_RENAME);
  $file->display  = TRUE;
  $tags           = array();
  
  if (! empty($data->tags)) {
  
    $vocabulary = taxonomy_vocabulary_machine_name_load('tags');
  
    foreach ($data->tags as $tag) {
      
      $term = taxonomy_get_term_by_name($tag);
      if (! empty($term)) {
        $term = array_pop ($term);
      }else{
        $term = (object)array(
          'vid'                     => $vocabulary->vid,
          'name'                    => $tag,
          'vocabulary_machine_name' => 'tags'
        );
        taxonomy_term_save($term);
      }
  
      $tags[] = (array)$term;
    }
  }
  
  $node = (object)array(
    'type'              =>'erpal_file',
    'title'             => $data->filename,
    'field_docs_file'   => array(
      LANGUAGE_NONE => array((array)$file)
    ),
    'field_file_tags'   => array(
      LANGUAGE_NONE => $tags
    )
  );
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  node_save($node);
  if (! isset($node->nid)) {
    services_error(
      'Couldn\'t create file node.'
    );
    return;
  }
 
  return array(
    'success' => true,
    'url'     => url('rest/erpal_files/' . $node->nid, array('absolute' => TRUE))
  );
}
 
/**
 * Callback for create a single file.
 * 
 * @param integer $nid   The database ID of a file node.
 * @param array   $data  The json payload to create the file with. 
 *                        {
 *                          'tags':       ['[TAG]', '[TAG]', ...],
 *                          'filename':   '[FILENAME]',
 *                          'binary':     '[BASE64 ENCRYPTION OF THE FILE]
 *                        }
 *                        Tags are optional like filename an binary. 
 *                        But, if you set filename, you have to set binary, too.
 * @return array          A result array on success.
 *                       [
 *                         'success': [BOOLEAN],
 *                          'URL':     [URL TO THE NEW FILE OBJECT]
 *                       ]
 */
function _erpal_docs_service_file_update($nid, $data) {
 
  $data = (object)$data;
 
  $node = node_load($nid);
  if ($node === FALSE) {
    services_error(
      'Can\'t find node.',
      404
    );
    return;
  }

  if ($node->type != 'erpal_file') {
    services_error(
      'Node isn\'t a erpal_file.',
      400
    );
    return;
  }
  
  if (isset ($data->tags) && ! empty($data->tags)) {

    $tags = array();
  
    $vocabulary = taxonomy_vocabulary_machine_name_load('tags');
  
    foreach ($data->tags as $tag) {
      
      $term = taxonomy_get_term_by_name($tag);
      if (! empty($term)) {
        $term = array_pop($term);
      }else{
        $term = (object)array(
          'vid'                     => $vocabulary->vid,
          'name'                    => $tag,
          'vocabulary_machine_name' => 'tags'
        );
        taxonomy_term_save($term);
      }
  
      $tags[] = (array)$term;
    }
    
 
    $node->field_file_tags = array(
      LANGUAGE_NONE => $tags
    );
  }

  if (isset($data->filename) && isset($data->binary)) {
    
    if (! empty($node->field_docs_file)) {
      file_delete(
        (object)$node->field_docs_file[LANGUAGE_NONE][0],
        TRUE
      );
    }

    drupal_load('module', 'erpal_docs_helper');
    $file_uri       = _erpal_docs_service_upload_path($data->filename);  
    $file           = file_save_data(base64_decode($data->binary), $file_uri, FILE_EXISTS_RENAME);
    $file->display  = TRUE;

    $node->title                             = $data->filename;
    $node->field_docs_file[LANGUAGE_NONE][0] =(array)$file;
  }
 
  node_save($node);
  if (! isset($node->nid)) {
    services_error(
      'Couldn\'t create file node.',
      501
    );
    return;
  }
 
  return array(
    'success' => true,
    'url'     => url('rest/erpal_files/' . $node->nid, array('absolute' => TRUE))
  );
}

/**
 * Make sure the filename gets a URI path to the erpal_docs folder.
 * 
 * @param   string $filename      The filename to prepare.
 * @return  string                The filename with URI path to the docs folder.
 */
function _erpal_docs_service_upload_path($filename) {
  
  $file_path = _erpal_docs_folder_uri();
  if (substr($file_path, -1) != '/') {
    $file_path .= '/';
  }
  
  return $file_path . $filename;
}
