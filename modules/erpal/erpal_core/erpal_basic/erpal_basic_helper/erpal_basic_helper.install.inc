<?php

/**
* @file include all functions used during update process
*/

/**
* Migrate all comment history from cne to comment alter
*/
function _erpal_basic_helper_install_migrate_comment_diff(&$sandbox) {

  //LOOP through all activity and task comments in a batch operation!
  //load the values from the field_comment_diff and just transfer the values that are changable 
  //in the new comment_alter settings @see cne module about how to read the data
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'comment')
  ->addMetaData('account', user_load(1)); // run the query as user 1

  $steps = 50; //we can process 50 as no ressource consuming node load or save operations and other things are done here
  $sandbox['#finished'] = 0;
  // Multi-part update.
  if (!isset($sandbox['comment_from'])) {
    $sandbox['comment_from'] = 0;
    $sandbox['comment_count'] = $query->count()->execute();
  }
  else {
    $sandbox['#finished'] = $sandbox['comment_from'] / $sandbox['comment_count'];
    
    //update;
    $query->range($sandbox['comment_from'], $steps);
    $result = $query->execute();

    $sandbox['comment_from'] += $steps;
    _erpal_basic_helper_install_migrate_comment_diff_result($result);

    if ($sandbox['comment_from'] >= $sandbox['comment_count']) {
      $sandbox['#finished'] = 1;
      
      return t('Comment change records history migrated and removed field instances');
    }
  }
}

/**
* This is will migrate comments from a resultset of the query for comments
*/
function _erpal_basic_helper_install_migrate_comment_diff_result($result) {
  if (isset($result['comment'])) {
    $comment_cids = array_keys($result['comment']);

    foreach ($comment_cids as $cid) {
      $comment = entity_load('comment', array($cid));
      $comment = $comment[$cid];
      //get the node revision to the comment according to the timestamp and also get the previous revision
      $vids = _erpal_basic_helper_install_comment_get_vids($comment);
      
      if (!$vids) {
        continue; //no revisions found so no state change to save
      }

      $comment_alter = array(
        'old_vid' => $vids['prev'],
        'new_vid' => $vids['current'],
        'cid' => $cid,
      );
      
      try {
        drupal_write_record('comment_alter', $comment_alter);
      } catch (Exception $e) {
        watchdog('MIGRATE Comments Exception', 'Exception: '.print_r($e, true));
      }
    }
  }
}

/**
* Get the revision and the revision before of the node where the comment was added. We find the revision by matching 
* the timestamp
*/
function _erpal_basic_helper_install_comment_get_vids($comment) {
  $result = db_query('SELECT DISTINCT(nr.vid) FROM {node_revision} nr LEFT JOIN {comment} c ON nr.nid=c.nid WHERE nr.timestamp=:changed AND nr.nid=:nid', array(':changed' => $comment->changed, ':nid' => $comment->nid))->fetchAll();
  
  //we can take only the first.
  if (count($result)) {
    $revision_obj = reset($result);
    $vid = $revision_obj->vid;
    
    //for this node get the revision before as for comment alter we need the new revision and the previous one
    $prev_result = db_query('SELECT vid FROM {node_revision} WHERE nid=:nid AND vid < :vid ORDER BY vid DESC LIMIT 1', array(':nid' => $comment->nid, ':vid' => $vid))->fetchAll();
    
    if (count($prev_result)) {
      $prev_vid = reset($prev_result);
      $prev_vid = $prev_vid->vid;
      return array('current' => $vid, 'prev' => $prev_vid);
    }
  }
  
  //if there is no revision, we cannot migrate the state changes.
  return false;
}