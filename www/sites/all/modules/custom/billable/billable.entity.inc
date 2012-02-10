<?php


/**
 * Fetch a billable object. Make sure that the wildcard you choose 
 * in the billable entity definition fits the function name here.
 *
 * @param $billable_id
 *   Integer specifying the billable id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $billable object or FALSE if it cannot be loaded.
 *
 * @see billable_load_multiple()
 */
function billable_load($billable_id, $reset = FALSE) {
  $billables = billable_load_multiple(array($billable_id), array(), $reset);
  return reset($billables);
}


/**
 * Load multiple billables based on certain conditions.
 *
 * @param $billable_ids
 *   An array of billable IDs.
 * @param $conditions
 *   An array of conditions to match against the {billable} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of billable objects, indexed by billable_id.
 *
 * @see entity_load()
 * @see billable_load()
 */
function billable_load_multiple($billable_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('billable', $billable_ids, $conditions, $reset);
}


/**
 * Deletes a billable.
 */
function billable_delete(Billable $billable) {
  $billable->delete();
}


/**
 * Delete multiple billables.
 *
 * @param $billable_ids
 *   An array of billable IDs.
 */
function billable_delete_multiple(array $billable_ids) {
  entity_get_controller('billable')->delete($billable_ids);
}


/**
 * Create a billable object.
 */
function billable_create($values = array()) {
  return entity_get_controller('billable')->create($values);
}


/**
 * Saves a billable to the database.
 *
 * @param $billable
 *   The billable object.
 */
function billable_save(Billable $billable) {
  return $billable->save();
}


/**
 * Saves a billable type to the db.
 */
function billable_type_save(BillableType $type) {
  $type->save();
}


/**
 * Deletes a billable type from the db.
 */
function billable_type_delete(BillableType $type) {
  $type->delete();
}


/**
 * URI callback for billables
 */
function billable_uri(Billable $billable){
  return array(
    'path' => 'billable/' . $billable->billable_id,
  );
}


/**
 * Menu title callback for showing individual entities
 */
function billable_page_title(Billable $billable){
  return $billable->subject;
}


/**
 * Sets up content to show an individual billable
 * @todo - get rid of drupal_set_title();
 */
function billable_page_view($billable, $view_mode = 'full') {    
  $controller = entity_get_controller('billable');  
  $content = $controller->view(array($billable->billable_id => $billable));
  drupal_set_title($billable->subject);
  return $content;
}


/**
 * Implements hook_views_api().
 */
function billable_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'billable') . '/views',
  );
}

/**
* @return
*   Themes of our billable entity
*/
function _billable_entity_theme() {
  
  return array(
    'billable_add_list' => array(
      'variables' => array('content' => array()),
      'file' => 'inc/billable.admin.inc',
    ),
    'billable' => array(
      'render element' => 'elements',
      'template' => 'billable',
    ),
  );
}




/**
 * The class used for billable entities
 */
class Billable extends Entity {
  
  public function __construct($values = array()) {
    parent::__construct($values, 'billable');
  }

  protected function defaultLabel() {
    return $this->subject;
  }

  protected function defaultUri() {
    return array('path' => 'billable/' . $this->billable_id);
  }
  
  
}



/**
 * The Controller for Billable entities
 */
class BillableController extends EntityAPIController {
  public function __construct($entityType) {
    parent::__construct($entityType);
  }


  /**
   * Create a billable - we first set up the values that are specific
   * to our billable schema but then also go through the EntityAPIController
   * function.
   * 
   * @param $type
   *   The machine-readable type of the billable.
   *
   * @return
   *   A billable object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our Billable
    $values += array( 
      'billable_id' => '',
      'is_new' => TRUE,
      'title' => '',
      'created' => time(),
      'changed' => time(),
      'data' => '',
    );
    
    $billable = parent::create($values);
    return $billable;
  }
  
  /**
   * Overriding the buldContent function to add entity specific fields
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content = parent::buildContent($entity, $view_mode, $langcode, $content);
    $content['billable_sample_data'] =  array(
      '#markup' => theme('billable_sample_data', array('billable_sample_data' => check_plain($entity->data['sample_data']), 'billable' => $entity)),
    );

    return $content;
  }
  
}
