<?php

/**
 * @file functions needed to make comments accessible by services
 * @author Lavong Soysavanh <ls@brightsolutions.de>
 */

/**
 * callback for creating a single comment
 *
 * @param int $id the id of the node to comment on
 * @param array $data the comment itself
 * @return array
 */
function _erpal_basic_service_comment_create($nid, $data) {

  if (!$data || empty($data)) {
    return services_error('comment(s) expected', 400);
  }

  $comment_ids = array();
  if (!empty($data['comments'])) {
    foreach ($data['comments'] as $value) {
      try {
        $cid = _erpal_basic_service_comment_create_single($nid, $value);
        $comment_ids[] = url('rest/basic/erpal_comment/' . $nid . '/' . $cid, array('absolute' => TRUE));
      } catch (Exception $e) {
        return services_error($e->getMessage(), 500);
      }
    }
  }
  else {
    _erpal_basic_service_comment_create_single($nid, $data);
  }

  $result = array();
  $result['success'] = true;
  $result['url'] = url('rest/basic/erpal_comment/' . $nid, array('absolute' => TRUE));
  $result['cids'] = $comment_ids;
  return $result;
}

/**
 * saves a single comment
 *
 * @param int $id the id of the node to comment on
 * @param array $data the comment itself
 * @return int comment id
 */
function _erpal_basic_service_comment_create_single($nid, $data) {

  global $user;

  if (!$data || empty($data) || empty($data['comment_body'])) {
    return services_error('comment expected', 400);
  }

  $accepted_node_types = array('erpal_contact', 'erpal_crm_activity', 'erpal_file');

  // load and check node whose comments to create
  $node = node_load($nid);
  if (!$node || !is_object($node)) {
    return services_error('failed loading node with id: ' . $nid, 400);
  }
  if (!in_array($node->type, $accepted_node_types)) {
    return services_error('unsupported node type for nid: ' . $nid . ' (' . $node->type . ')', 400);
  }

  // comment
  $comment = new stdClass();
  $comment->nid = $node->nid;
  $comment->cid = 0;
  $comment->pid = (isset($data['pid'])) ? $data['pid'] : 0;
  $comment->uid = $user->uid;
  $comment->mail = $user->mail;
  $comment->name = $user->name;
  //$comment->thread = '01/';
  $comment->hostname = $user->hostname;
  $comment->created = isset($data['created']) ? $data['created'] : time();
  $comment->is_anonymous = 0;
  $comment->homepage = '';
  $comment->status = COMMENT_PUBLISHED;
  $comment->language = LANGUAGE_NONE;
  $comment->subject = isset($data['subject']) ? $data['subject'] : '';
  $comment->comment_body[$comment->language][0]['value'] = isset($data['comment_body']) ? $data['comment_body'] : '';
  $comment->comment_body[$comment->language][0]['format'] = isset($data['comment_format']) ? $data['comment_format'] : 'filtered_html';
  try {
    comment_submit($comment);
    comment_save($comment);
  } catch (Exception $e) {
    return services_error('failed saving comment', 500);
  }

  return $comment->cid;
}

/**
 * saves a single comment
 *
 * @param int $nid the id of the node whose comment to update
 * @param int $cid the id of the comment to update
 * @param array $data the updated comment
 * @return array
 */
function _erpal_basic_service_comment_update($nid, $cid, $data) {

  global $user;

  if (!$data || empty($data) || empty($data['comment']) || empty($data['comment']['comment_body'])) {
    return services_error('comment expected', 400);
  }

  $comment = comment_load($cid);

  if (!$comment || empty($comment)) {
    return services_error('failed loading comment with id: ' . $cid, 400);
  }

  $accepted_node_types = array('erpal_contact', 'erpal_crm_activity', 'erpal_file');
  $node = node_load($comment->nid);
  if (!$node || !is_object($node)) {
    return services_error('failed checking node', 500);
  }
  if (!in_array($node->type, $accepted_node_types)) {
    return services_error('unsupported node type for nid: ' . $comment->nid . ' (' . $node->type . ')', 400);
  }

  if (isset($data['comment']['subject']))
    $comment->subject = $data['comment']['subject'];
  if (isset($data['comment']['comment_body']))
    $comment->comment_body[$comment->language][0]['value'] = $data['comment']['comment_body'];
  if (isset($data['comment']['comment_format']))
    $comment->comment_body[$comment->language][0]['format'] = $data['comment']['comment_format'];
  if (isset($data['comment']['pid']))
    $comment->comment_body[$comment->language][0]['pid'] = $data['comment']['pid'];
  try {
    comment_submit($comment);
    comment_save($comment);
  } catch (Exception $e) {
    return services_error('failed saving comment', 500);
  }

  $result = array();
  $result['success'] = true;
  $result['url'] = url('rest/basic/erpal_comment/' . $nid . '/' . $cid, array('absolute' => TRUE));
  return $result;
}

/**
 * callback for retrieving all comments for all supported entity types
 *
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether comments will be returned with details, defaults to true
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return array
 */
function _erpal_basic_service_comment_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = TRUE, $include_children = FALSE) {

  $accepted_node_types = array('erpal_contact', 'erpal_crm_activity', 'erpal_file');

  $comments_out = array();
  foreach ($accepted_node_types as $node_type) {
    $comments_for_node_type = _erpal_basic_service_comment_out($node_type, 0, $start, $count, $changed_since, $details, $include_children);

    if (!empty($comments_for_node_type)) {
      foreach ($comments_for_node_type as $value) {
        if ($value && !empty($value['comments'])) {
          array_push($comments_out, $value);
        }
      }
    }
  }
  return $comments_out;
}

/**
 * callback for retrieving a single comment resource.
 *
 * @param string $id the node id or the node's entity type of the comments to return
 * @param int $cid the id of the comment to return
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether comments will be returned with details, defaults to true
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_basic_service_comment_retrieve($id = '', $cid = 0, $start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = TRUE, $include_children = FALSE) {
  $comment_node = _erpal_basic_service_comment_out($id, $cid, $start, $count, $changed_since, $details, $include_children);
  return $comment_node;
}

/**
 * retrieves and returns comments for a node
 * @param string $id the node id of the comments to return
 * @param int $cid the id of the comment to return
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether comments will be returned with details , defaults to false
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return array the project prepared for output
 */
function _erpal_basic_service_comment_out($id = '', $cid = 0, $start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = true, $include_children = FALSE) {

  $accepted_node_types = array('erpal_contact', 'erpal_crm_activity', 'erpal_file');

  // construct response
  $comments_out = array();

  /*
   * node id given, get comments for that single node
   */
  if (is_numeric($id)) {
    $nid = (int) ($id);

    // load node whose comments to get
    $node = node_load($nid);

    // check node
    if (!$node || !is_object($node)) {
      return services_error('failed loading node with id: ' . $nid, 400);
    }
    if (!in_array($node->type, $accepted_node_types)) {
      return services_error('unsupported node type for nid: ' . $nid . ' (' . $node->type . ')', 400);
    }

    // base data
    $comments_out['created'] = (int) $node->created;
    $comments_out['changed'] = (int) $node->changed;
    $comments_out['url'] = url('rest/basic/erpal_comment/' . $node->nid, array('absolute' => TRUE));
    $comments_out['subject'] = $node->title;
    $comments_out['parent_type'] = $node->type;
    if ($node->type === 'erpal_contact') {
      $comments_out['parent_url'] = url('rest/basic/contact/' . $nid, array('absolute' => TRUE));
    }
    else if ($node->type === 'erpal_crm_activity') {
      $comments_out['parent_url'] = url('rest/activity/crm_activity/' . $nid, array('absolute' => TRUE));
    }
    else if ($node->type === 'erpal_file') {
      $comments_out['parent_url'] = url('rest/erpal_files/erpal_file/' . $nid, array('absolute' => TRUE));
    }

    // revision
    $comments_out['revision_timestamp'] = (int) $node->revision_timestamp;
    $comments_out['revision_id'] = (int) $node->revision_uid;

    $comments_out['comments'] = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'comment')
        ->propertyCondition('changed', (int) $changed_since, '>=')
        ->propertyCondition('nid', $nid);
    if ($cid) {
      $query->propertyCondition('cid', $cid);
    }
    $entities = $query->execute();
    if (!empty($entities['comment'])) {
      foreach (array_keys($entities['comment']) as $comment_id) {
        $comment = comment_load($comment_id);
        if ($comment) {
          $comment_body = $comment->comment_body[LANGUAGE_NONE][0];
          $comment_out = array(
            'created' => (int) $comment->created,
            'changed' => (int) $comment->changed,
            'cid' => (int) $comment->cid,
            'comment_url' => url('rest/basic/erpal_comment/' . $node->nid . '/' . $comment_id, array('absolute' => TRUE)),
            'subject' => ($comment->subject) ? $comment->subject : '',
            'name' => ($comment->name) ? $comment->name : '',
            'registered_name' => ($comment->registered_name) ? $comment->registered_name : '',
            'comment_body' => $comment_body['value'],
            'comment_format' => $comment_body['format'],
            'author_url' => url('rest/basic/erpal_user/' . $comment->uid, array('absolute' => TRUE)),
          );
          // files
          if (!empty($comment->field_asset_files)) {
            $comment_out['attachments'] = array();
            foreach ($comment->field_asset_files[LANGUAGE_NONE] as $key => $value) {
              if (!$include_children || (strtolower($include_children) === 'false')) {
                $comment_out['attachments'][] = url('rest/erpal_files/erpal_file/' . $value['target_id'], array('absolute' => TRUE));
              }
              else {
                $file = node_load($value['target_id']);
                $file_wrapper = entity_metadata_wrapper('node', $file);
                $file_array = $file_wrapper->field_docs_file->value();
                if (!empty($file_array)) {
                  $comment_out['attachments'][] = array(
                    'filename' => $file_array['filename'],
                    'mimetype' => $file_array['filemime'],
                    'filesize' => (int) $file_array['filesize'],
                    'download_url' => file_create_url($file_array['uri']),
                    'description' => ($file_array['description']) ? $file_array['description'] : '',
                    'fid' => (int) $file_array['fid'],
                  );
                }
              }
            }
          }
          array_push($comments_out['comments'], $comment_out);
        }
      }
    }
  }
  /*
   * string were given, treat it as node type and get all comments for all nodes of that type
   */
  else {
    $node_type = (string) $id;
    if (!in_array($node_type, $accepted_node_types)) {
      return services_error('unsupported node type: ' . $node_type, 400);
    }
    $query = new EntityFieldQuery();
    $entities = $query->entityCondition('entity_type', 'node')
        ->propertyCondition('type', $node_type)
        ->range((int) $start, (int) $count)
        ->execute();
    if (!empty($entities['node'])) {
      foreach (array_keys($entities['node']) as $nid) {
        $comments_out[] = _erpal_basic_service_comment_out($nid, $cid, $start, $count, $changed_since, $details, $include_children);
      }
    }
  }

  return $comments_out;
}

/**
 * Check access for comment node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_basic_service_comment_access($op, $args = NULL) {
  return node_access($op, 'erpal_contact');
}

