<?php

/**
* @file provides tokens for files
*/

/**
 * Implements hook_token_info().
 */
function erpal_docs_helper_token_info() {
  $types['erpal_files'] = array(
    'name' => t("Erpal files token"),
    'description' => t("Tokens for file nodes."),
    'needs-data' => 'node',
  );
  

  $files['filename'] = array(
    'name' => t("Filename"),
    'description' => t("The filename of the file"),
  );
  
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_files' => $files,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_docs_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();

  if ($type == 'erpal_files') {
    $node = $data['node']; //erpal_file node
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'filename':          
          if (isset($node->field_docs_file[LANGUAGE_NONE][0]['fid'])) {
            $file = file_load($node->field_docs_file[LANGUAGE_NONE][0]['fid']);
            $replacements[$original] = $file->filename;
          }
        break;                
      }
    }
  }

  return $replacements;
}
