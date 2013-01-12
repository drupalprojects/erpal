<?php
/**
 * @author    Oskar Bechtold
 * @created   12/20/2012
 * @copyright 2012 © Bright Solutions GmbH
 */

/**
 * Implements hook_action_info().
 */
function erpal_mail_action_info() {
  return array(
    'email_reference_action' => array(
      'type' => 'node', 
      'label' => t('reference email'), 
      'configurable' => TRUE, 
      'hooks' => array(),
    ), 
  );
}

/**
*  Form to select the referencing node
*/
function email_reference_action_form($context) {
  $form = array();
  
  $form['node_to_reference'] = array(
    '#type' => 'textfield',
    '#title' => t('Node to reference'),
    '#description' => t('The node that will get a reference to the selected emails'),
    '#autocomplete_path' => 'finder_autocomplete/autocomplete/erpal_task_or_activity_finder/find_tasks_and_activities',
  );
  
  return $form;
  
}
/**
* Submithandler of reduce action config form
*/
function email_reference_action_submit($form, $form_state) {
  $values = $form_state['values'];
  return $values;
}
/**
 * set the references from the chosen node to the selected emails
 */
function email_reference_action(&$entity, $context = array()) {
  $nodestring = $context['node_to_reference'];
  $nid = _erpal_basic_helper_get_nid_from_autocomplete_string($nodestring);
  $node = node_load($nid);
  if(!_has_reference($node,$entity->nid)){
    $node->field_mails[LANGUAGE_NONE][]['target_id'] = $entity->nid;
    node_save($node);
  
    $email = node_load($entity->nid);
    $email->status = NODE_PUBLISHED;
    node_save($email);
  }

}
/**
 * check if the given node has a reference to the given nid
 * @param stdObject $node
 *  the node to search in
 * @param int $nid
 *  the node id to look for
 * @return boolean
 *  true if the reference exists, false otherwise
 */
function _has_reference(&$node,$nid){
  if(isset($node->field_mails[LANGUAGE_NONE]) && in_array(array('target_id'=>$nid),$node->field_mails[LANGUAGE_NONE])){
    return true;
  }
  return false;
}
