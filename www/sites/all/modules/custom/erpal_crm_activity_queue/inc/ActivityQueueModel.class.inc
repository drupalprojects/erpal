<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	05/04/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * This class contains all functions around querying elements for the approval queue view.
 */

namespace erpal_crm_activity_queue;

class ActivityQueueModel {
  
  const PAGER_DEFAULT_LIMIT = 10;
  
  private $nodeQuery;
  private $commentQuery;
  private $pagerSize;
  
  /*
   * Returns a table header array.
   * @return array 	An array which contains the header of the view table.
   */
  public static function getHeader () {
    
    return array (
      'title'     => array('data' => t('Subject'), 'field' => 'title'),
      'created'   => array('data' => t('Created'), 'field' => 'created'),
      'parent'    => array('data' => t('Parent activity'), 'field' => 'parent'),
      'operation' => array('data' => t('Operation')),
    );
  }
  
  /*
   * Ctor.
   * Configures the internal query objects.
   */
  public function __construct () {
    
    $this->nodeQuery = db_select ('node', 'n');
    $this->nodeQuery->addTag ('erpal_activity_queue_node');
    $this->nodeQuery->condition ('type', 'erpal_crm_activity', '=');
    $this->nodeQuery->fields ('n', array ('title', 'created', 'nid'));
    
    $this->commentQuery = db_select ('comment', 'c');
    $this->commentQuery->addTag ('erpal_activity_queue_comment');
    $this->commentQuery->join ('node', 'n', 'n.nid=c.nid');
    $this->commentQuery->condition ('n.type', 'erpal_crm_activity', '=');
    $this->commentQuery->fields ('c', array ('subject', 'created', 'cid'));
    $this->commentQuery->fields ('n', array ('title', 'nid'));
    
    $this->pagerSize = self::PAGER_DEFAULT_LIMIT; 
    
    return;
  }
  
  /*
   * A query configurator for the date range of the created field.
   * @param	integer		$from		A unix timestamp as start value.
   * @param	integer		$to			A unix timestamp as end value.
   * @return ActivityQueueModel The current object.
   */
  public function dateRange ($from, $to) {
 
    $this->nodeQuery->condition ('n.created', $from, '>=');
    $this->nodeQuery->condition ('n.created', $to, '<=');
    
    $this->commentQuery->condition ('c.created', $from, '>=');
    $this->commentQuery->condition ('c.created', $to, '<=');
    
    return $this;
  }
  
  /*
   * A query configurator for the status field.
   * @param boolean	$status		The status of the activity element.
   * @return ActivityQueueModel The current object.
   */
  public function status ($status) {
    
    $this->nodeQuery->condition ('n.status', (int)$status, '=');
    $this->commentQuery->condition ('c.status', (int)$status, '=');
    
    return $this;
  }
  
  /*
   * A query configurator for the pager size.
   * @param integer	$size	The amount of results of one page. FALSE, if you do not want to use a pager.
   * @return ActivityQueueModel The current object.
   */
  public function pageSize ($size) {
    
    $this->pagerSize = $size;
    
    return $this;
  }
  
  /*
   * Executes the activity elements by previous configurations.
   * @return array	An associative array of results.
   */
  public function load () {
    
    $results = array ();
    
    $result = $this->nodeQuery->execute ();
    
    foreach ($result as $row) {
      $results[$row->nid . 'nid'] = self::prepareNodeRow ($row);
    }
    
    
    $result = $this->commentQuery->execute ();
    
    foreach ($result as $row) {

      $results[$row->cid . 'cid'] = self::prepareCommentRow ($row);
    }
    
    if ($this->pagerSize !== FALSE) {
      $page     = pager_default_initialize(count($results) , $this->pagerSize);
      $results  = array_slice ($results, $page, $this->pagerSize);
    }
    
    return $results;
  }
  
  /*
   * Prepares the data a node row for using with drupal tables.
   * @param 	object 	$row	The row object.
   * @return 	array					The row object as array.
   */
  private static function prepareNodeRow ($row) {
 
    $row->parent     = '-';
    $row->operation  = l(t('View'), self::getNodeAlias ($row->nid));
    $row->created    = format_date ($row->created);
    
    return (array)$row;
  }
  
  /*
   * Prepares the data a comment row for using with drupal tables.
   * @param 	object 	$row	The row object.
   * @return 	array					The row object as array.
   */
  private static function prepareCommentRow ($row) {
    
    $row = (object)self::prepareNodeRow ($row);
    
    $nodePath = self::getNodeAlias ($row->nid);
    
    $row->parent     = l($row->title, $nodePath);
    $row->operation  = l(t('View'), $nodePath, array ('fragment'=> 'comment-' . $row->cid));
    
    $row->title = $row->subject;
    unset ($row->subject);
    
    return (array)$row;
  }
  
  /*
   * Retrieves the alias URL of a node.
   * @param 	integer	$nid	The database ID of a node.
   * @return 	string				The alias path or the original path. 
   */
  private static function getNodeAlias ($nid) {
    
    $defaultPath  = 'node/' . $nid;
    $nodePath     = drupal_lookup_path('alias', $defaultPath);
    
    return $nodePath !== FALSE ? $nodePath : $defaultPath;
  }
  
  /*
   * Approves a list of activity elements (nodes and comments).
   * @param array $elementIDs 	Each element which has the same value as key, will be approved.
   */
  public static function approve (array $activityElements) {
    
    foreach ($activityElements as $activityElement) {
      if ($activityElement !== 0) {
        $id = intval ($activityElement);
        
        if (strstr ($activityElement, 'nid')) {
          return self::approveNode ($id);
        }else{
          return self::approveComment ($id);
        }
      }
    }
    
    return FALSE;
  }
  
  /*
   * Set the status of a specific node to published.
   * @param 	integer $nid	The database ID of a node.
   * @return 	boolean				TRUE on success.
   */
  private static function approveNode ($nid) {
    
    $node = node_load ($nid);
    if ($node === FALSE) {
      return FALSE;
    }
    
    node_publish_action($node);
    node_save ($node);
    
    return TRUE;
  }
  
  /*
   * Set the status of a specific comment to published.
   * @param 	integer $cid	The database ID of a comment.
   * @return 	boolean				TRUE on success.
   */  
  private static function approveComment ($cid) {
    
    $comment = comment_load ($cid);
    if ($comment === FALSE) {
      return FALSE;
    }
    
    comment_publish_action($comment);
    comment_save($comment);
    
    return TRUE;
  }
}
