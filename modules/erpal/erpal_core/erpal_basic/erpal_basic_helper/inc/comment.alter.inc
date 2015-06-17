<?php

/**
* Functions to change comment alters behavior
*/

/**
* Theming function for the comment alter output
* @see comment_alter_get_changed_fields
*/
function _erpal_basic_helper_comment_alter_diff_theme(&$variables) {
  $rows = array();
  
  $variables['changed_fields'] = _erpal_basic_helper_get_changed_fields($variables['comment'], $variables['langcode']);//this is douplicate work but neccessary as we want the changed fields to be rendered in our own way.

  $items = array();
  foreach ($variables['changed_fields'] as $field) {
    foreach ($field as $value) {
      $items[] = $value['old'].'&raquo;'.$value['new'];
    }
  }
  
  return theme('item_list', array(
    'items' => $items,
    //'attributes' => array('class' => array('pager', 'pagination')),
    //'wrapper_attributes' => array('id' => 'pagination-wrapper', 'class' => array('class1', 'class2')),
  ));
  
  drupal_add_css(drupal_get_path('module', 'comment_alter') . '/comment_alter.css');
  return  theme('table', array(
    '#theme' => 'table__comment_alter__diff',
    '#rows' => $rows,
    '#attributes' => array('class' => array('comment-alter-diff')),
    '#sticky' => FALSE,
  ));
}

/**
* Renders the output for each field not only in plain text
* @see diff_compare_entities()
*/
function _erpal_basic_helper_get_changed_fields($comment, $langcode) {

  $changed_fields = array();
  if (isset($comment->comment_alter)) {
    $node = node_load($comment->nid);
    module_load_include('inc', 'diff', 'diff.pages');
    $old_node = node_load($comment->nid, $comment->comment_alter['old_vid']);
    $new_node = node_load($comment->nid, $comment->comment_alter['new_vid']);
    $context = array(
      'entity_type' => 'node',
      'states' => array('raw'),
      'view_mode' => 'diff_standard',
      'language' => $langcode,
    );
    $comment_alter_fields = comment_alter_get_alterable_fields($node->type);
    // Because the 'title_field' is 'hidden' on all display modes, the Diff
    // module will skip over it. However, the diff module has special support
    // for the 'title' property, so we swap 'title_field' for 'title'.
    if (($title_field_index = array_search('title_field', $comment_alter_fields)) !== FALSE) {
      $comment_alter_fields[$title_field_index] = 'title';
    }
    
    $diffs = diff_compare_entities($old_node, $new_node, $context);
    
    foreach ($diffs as $field_name => $diff) {
      // Only compare fields that belong to us.
      $field = field_info_field($field_name);
      if (field_access('view', $field, 'node') && in_array($field_name, $comment_alter_fields)) {        
        list ($old, $new) = diff_extract_state($diff, $context['states'][0]);
        
        $unchanged = array_intersect($old, $new);  //to avoid showing changes if the delta only changed
          
        if ($old != $new) {
          $field = field_info_field($field_name);
          $rows = array();
          if (!empty($field['type']) && $field['type'] == 'taxonomy_term_reference') {
            //load the term            
            $allowed_values = $field['settings']['allowed_values'];
            $vocabulary_name = false;
            foreach ($allowed_values as $allowed_value) {
              $vocabulary_name = !empty($allowed_value['vocabulary']) ? $allowed_value['vocabulary'] : false;
            }
            
            $new_term_rendered = false;
            $old_term_rendered = false;
            if ($vocabulary_name) {            
              foreach ($old as $delta=>$old_value) {
                $new_value = $new[$delta];
                
                if (in_array($old_value, $unchanged) || in_array($old_value, $unchanged))
                  continue;
                
                $old_term = taxonomy_get_term_by_name($old_value, $vocabulary_name);
                $new_term = taxonomy_get_term_by_name($new_value, $vocabulary_name);
                $old_term = reset($old_term);
                $new_term = reset($new_term);
                
                //has it an image?                
                if (!empty($old_term->field_term_image[LANGUAGE_NONE])) {
                  $image_uri = isset($old_term->field_term_image[LANGUAGE_NONE][0]['uri']) ? $old_term->field_term_image[LANGUAGE_NONE][0]['uri'] : false;
                  $url = '';
                  if ($image_uri)
                    $url = image_style_url('icon16x16', $image_uri);
           
                  $rendered = '<img src="'.$url.'" title="'.$old_term->name.'" alt="'.$old_term->name.'"/>';
                  $old_term_rendered .= $rendered;//drupal_render(entity_view('taxonomy_term', array($old_term), 'minimal'));
                } elseif (!empty($old_term->name)) {
                  $old_term_rendered .= $old_term->name;
                }
                                
                if (!empty($new_term->field_term_image[LANGUAGE_NONE])) {
                  $image_uri = isset($new_term->field_term_image[LANGUAGE_NONE][0]['uri']) ? $new_term->field_term_image[LANGUAGE_NONE][0]['uri'] : false;
                  $url = '';
                  if ($image_uri)
                    $url = image_style_url('icon16x16', $image_uri);
           
                  $rendered = '<img src="'.$url.'" title="'.$new_term->name.'" alt="'.$new_term->name.'"/>';
                  $new_term_rendered .= $rendered; //drupal_render(entity_view('taxonomy_term', array($new_term), 'minimal'));
                } elseif (!empty($new_term->name)) {                  
                  $new_term_rendered .= $new_term->name;
                }
              }
              
              //render the terms with an image if available, otherwise text only
              if ($old_term_rendered  || $new_term_rendered) {
                $rows[] = array('old' => $old_term_rendered, 'new' => $new_term_rendered);
              }
            }
            
          } elseif (!empty($field['type']) && $field['type'] == 'entityreference' && $field['field_name'] == 'field_asset_files') {
            //handle entity references to link the entity 
            $max_count = max(count($old), count($new));

            for ($delta = 0; $delta < $max_count; $delta++) {
              $old_value = !empty($old[$delta]) ? $old[$delta] : false;
              $new_value = !empty($new[$delta]) ? $new[$delta] : false;
              
              if (in_array($old_value, $unchanged) || in_array($new_value, $unchanged)) {
                continue;
              }
              
              $old_entity_rendered = '';
              if ($old_value) {
                $old_node = _erpal_lib_get_node_by_title($old_value, 'erpal_file');       
                if ($old_node) {                  
                  $old_entity_uri = entity_uri('node', $old_node);
                  $old_file_uri = $old_node->field_docs_file[LANGUAGE_NONE][0]['uri'];
                  $old_entity_rendered = _erpal_basic_helper_render_file_link($old_file_uri, $old_value, $old_entity_uri, true);
                  $old_entity_rendered = $old_entity_rendered['#markup'];
                }
              }

              $new_entity_rendered = '';
              if ($new_value) {
                $new_node = _erpal_lib_get_node_by_title($new_value, 'erpal_file');
                if ($new_node) {
                  $new_entity_uri = entity_uri('node', $new_node);
                  $new_file_uri = $new_node->field_docs_file[LANGUAGE_NONE][0]['uri'];
                  $new_entity_rendered = _erpal_basic_helper_render_file_link($new_file_uri, $new_value, $new_entity_uri, true);                
                  $new_entity_rendered = $new_entity_rendered['#markup'];
                }
              }
                
              if (($old_entity_rendered  || $new_entity_rendered) && ($old_value != $new_value)) {
                $rows[] = array('old' => $old_entity_rendered, 'new' => $new_entity_rendered);
              }
            }
          } else {
            $old_values = implode(',', $old);
            $new_values = implode(',', $new);
            
            $rows[] = array(
              'old' => $old_values,
              'new' => $new_values,
            );

          }
          
          foreach ($rows as $row) {
            $changed_fields[$field_name][] = array(
              'old' => empty($row['old']) ? '' : $row['old'],
              'new' => empty($row['new']) ? '' : $row['new'],
            );
          }    
        }
      }
    }
  } 
  
  return $changed_fields;
}