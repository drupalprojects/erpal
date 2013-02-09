<?php

/**
 * @file
 * Entity hooks and callbacks for date_items.
 */

/**
 * Implements hook_entity_info().
 */
function date_item_entity_info() {
  $entities = array(
    'date_item' => array(
      'label' => t('date item'),
      'plural label' => t('date items'),
      'controller class' => 'EntityAPIController',
      'entity class' => 'DateItem',
      'metadata controller class' => 'DateItemMetadataController',
      'base table' => 'date_item',
      'fieldable' => TRUE,
      'entity keys' => array(
        'id' => 'date_item_id',
        'bundle' => 'type',
      ),
      'access callback' => 'date_item_access',
      'bundle keys' => array(
        'bundle' => 'name',
      ),
      'bundles' => array(),
      'view modes' => array(
        'full' => array(
          'label' => t('Full date_item'),
          'custom settings' => FALSE,
        ),
      ),
      'uri callback' => 'entity_class_uri',
      //'token type' => 'date_item',
      'module' => 'date_item',
      'label callback' => 'entity_class_label'
    ),
    'date_item_type' => array(
      'label' => t('date item type'),
      'entity class' => 'DateItemType',
      'controller class' => 'EntityAPIControllerExportable',
      'base table' => 'date_item_type',
      'fieldable' => FALSE,
      'bundle of' => 'date_item',
      'exportable' => TRUE,
      'entity keys' => array(
        'id' => 'id',
        'name' => 'name',
        'label' => 'label',
      ),
      'access callback' => 'date_item_type_access',
      'module' => 'date_item',
      // Enable the entity API's admin UI.
      'admin ui' => array(
        'path' => 'admin/structure/date_item/date_item_types',
        'file' => 'date_item_type.admin.inc',
        'file path' => drupal_get_path('module', 'date_item') . '/includes',
        'controller class' => 'DateItemTypeUIController',
      ),
    ),        
  );

  // Support entity cache module.
  if (module_exists('entitycache')) {
    $return['date_item']['field cache'] = FALSE;
    $return['date_item']['entity cache'] = TRUE;
  }

  return $entities;
}

/**
 * Implements hook_entity_info_alter().
 */
function date_item_entity_info_alter(&$entity_info) {
  // @todo: we're testing to ensure the schema exists; needed because running gui
  // install profile was hitting this BEFORE the schema was installed.
  if (drupal_get_schema('date_item')) {
    // We are adding the info about the date_item types via a hook to avoid a
    // recursion issue as loading the types requires the entity info as well.
    foreach (date_item_get_types() as $type => $info) {
      
      $entity_info['date_item']['bundles'][$type] = array(
        'label' => $info->label,
        'admin' => array(
          'path' => 'admin/structure/date_item/date_item_types/manage/%date_item_type',
          'real path' => 'admin/structure/date_item/date_item_types/manage/' . $type,
          'bundle argument' => 5,
          'access arguments' => array('administer date_item types'),
        ),
      );
    }
  }
}

/**
 * Main class for date_item entities.
 */
class DateItem extends Entity {

  public
    $date_item_id,
    $type,
    $date_from,
    $date_till,
    $offset_from,
    $offset_till,
    $timezone,
    $src_type,
    $src_id,
    $src_field_name,
    $removed,
    $data,
    $uid,
    $created,
    $title,
    $date_items_update, //just a flag to provide information if entity is in update process whil saving a host entity with a date field that creates date entites
    $updated;
    
  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);

  }

  /**
   * Specifies the default label, which is picked up by label() by default.
   */
  public function defaultLabel() {
    if ($this->src_id && $this->src_type && $this->src_field_name) {
      $src_entity = $this->src_entity();
      if ($this->title)
        return $this->title;
        
      return t('Date for @title', array(
          '@title' => entity_label($this->src_type, $src_entity)
        )
      );
    }
    return '';
  }

  /**
   * Load source entity of date_item.
   *
   * @return object|bool
   *   An entity, or FALSE if the entity does not exist.
   */
  public function src_entity() {
    return (($this->src_id && !empty($this->src_type)) ? entity_load_single($this->src_type, $this->src_id) : FALSE);
  }

  /**
   * Build content for date_item.
   *
   * @return render array
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    $build = parent::buildContent($view_mode, $langcode);

    $src_entity_type_info = entity_get_info($this->src_type);
    $src_entity = $this->src_entity();
    list(, , $host_entity_bundle) = entity_extract_ids($this->src_type, $src_entity);

    $host_label = entity_label($this->src_type, $src_entity);
    $host_uri = entity_uri($this->src_type, $src_entity);

    // Date from
    $build['date_from'] = array(
      '#prefix' => '<div class="field date_item-date_from"><div class="field-label">' . t('Date from') . '</div>',
      '#markup' => format_date($this->date_from),
      '#suffix' => '</div>',
    );

    //date till
    $build['date_till'] = array(
      '#prefix' => '<div class="field date_item-date_till"><div class="field-label">' . t('Date till') . '</div>',
      '#markup' => format_date($this->date_till),
      '#suffix' => '</div>',
    );
    
    // Link to host entity
    $host_entity_link_label = (isset($src_entity_type_info['bundles'][$host_entity_bundle]['label'])) ? '<div class="field-label">' . $src_entity_type_info['bundles'][$host_entity_bundle]['label'] . '</div>' : '';
    $build['host_entity_link'] = array(
      '#prefix' => '<div class="field date_item-entity-link">' . $host_entity_link_label,
      '#markup' => l($host_label, $host_uri['path']),
      '#suffix' => '</div>',
    );

    // Date created
    $build['created'] = array(
      '#prefix' => '<div class="field date_item-created"><div class="field-label">' . t('Created') . '</div>',
      '#markup' => format_date($this->created),
      '#suffix' => '</div>',
    );

    // Date updated
    $build['updated'] = array(
      '#prefix' => '<div class="field date_item-updated"><div class="field-label">' . t('Updated') . '</div>',
      '#markup' => format_date($this->updated),
      '#suffix' => '</div>',
    );

    // date_item authored by
    $author = user_load($this->uid);
    $author_uri = user_uri($author);

    $build['uid'] = array(
      '#prefix' => '<div class="field date_item-user"><div class="field-label">' . t('User') . '</div>',
      '#markup' => (isset($author_uri['path']) ? l($author->name, $author_uri['path']) : t('Anonymous')),
      '#suffix' => '</div>',
    );
    
    //redirect to source entity after delete
    $build['actions']['delete'] = array(
      '#prefix' => '<div class="delete_link field date_item-entity-link">',
      '#markup' => l(t('delete'), 'date_item/'.$this->date_item_id.'/delete', array('query' => array('destination' => $host_uri['path']))),
      '#suffix' => '</div>',
    );

    return $build;
  }

  /**
   * Save date_item.
   *
   * @return mixed
   */
  public function save() {
    $this->updated = REQUEST_TIME;
    if (!$this->date_item_id) {
      $this->created = REQUEST_TIME;
    }
    return parent::save();
  }
  
  /**
   * Specify URI
   */
  protected function defaultUri() {
    return array('path' => 'date_item/' . $this->internalIdentifier());
  }

}

/**
 * @see hook_entity_property_info()
 */
class DateItemMetadataController extends EntityDefaultMetadataController {
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['created'] = array(
      'label' => t("Created"),
      'description' => t("The date the date_item was created."),
      'type' => 'date',
      'schema field' => 'created',
    );
    $properties['updated'] = array(
      'label' => t("Updated"),
      'description' => t("The date the date_item was updated."),
      'type' => 'date',
      'schema field' => 'updated',
    );
    $properties['date_from'] = array(
      'label' => t("Date from"),
      'description' => t("The start date of the date_item."),
      'type' => 'date',
      'schema field' => 'date_from',
    );
    $properties['date_till'] = array(
      'label' => t("Date till"),
      'description' => t("The end date of the date_item."),
      'type' => 'date',
      'schema field' => 'date_till',
    );    
    $properties['entity'] = array(
      'label' => t('Source'),
      'type' => 'entity',
      'schema field' => 'src_id',
      'description' => t('The source entity the date_item belongs to.'),
      'getter callback' => 'date_item_get_properties',
    );
    $properties['rendered_src'] = array(
      'label' => t('Rendered source'),
      'type' => 'text',      
      'description' => t('The rendered source entity the date_item belongs to.'),
      'computed' => TRUE,
      'sanitized' => TRUE,
      'getter callback' => 'date_item_get_rendered_source',
    );
    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The user that created the date_item."),
      'schema field' => 'uid',
      'getter callback' => 'date_item_get_properties',
    );
    $properties['settings'] = array(
      'label' => t("Settings"),
      'type' => 'array',
      'description' => t("Settings of the field"),
      'schema field' => 'setting',
      'getter callback' => 'date_item_get_properties',
    );
    $properties['date_item_type'] = array(
      'label' => t("Date item type"),
      'type' => 'varchar',
      'description' => t("The type of the date item that should be created"),
      'schema field' => 'setting',
      'getter callback' => 'date_item_get_properties',
    );

    return $info;
  }
  
}

/**
 * Required by date_itemMetadataController for Views integration.
 *
 * @param $entity
 * @param array $options
 * @param $name
 * @param $type
 *
 * @return EntityMetadataWrapper
 */
function date_item_get_properties($entity, array $options, $name, $type) {
  switch ($name) {
    case 'entity':
      return entity_metadata_wrapper($entity->src_type, $entity->src_entity());
      break;
    case 'user':
      $user = user_load($entity->uid);
      return $user;
      break;
    case 'settings':     
      return unserialize($entity->settings);
  }

}


function date_item_get_rendered_source($entity, array $options, $name, $type) {
  $src_entity = $entity->src_entity();
  $src_view = entity_view($entity->src_type, array($src_entity));
  return render($src_view);
}
/**
 * Loads a date_item by ID.
 */
function date_item_load($date_item_id) {
  if (empty($date_item_id)) {
    return FALSE;
  }

  $date_items = date_item_load_multiple(array($date_item_id), array());
  return $date_items ? reset($date_items) : FALSE;
}

/**
 * Loads multiple date_items by ID or based on a set of matching conditions.
 *
 * @see entity_load()
 *
 * @param $date_item_ids
 * @param $conditions
 *   An array of conditions on the {date_item} table in the form
 *     'field' => $value.
 * @param $reset
 *   Whether to reset the internal date_item loading cache.
 *
 * @return
 *   An array of date_item objects indexed by date_item_id.
 */
function date_item_load_multiple($date_item_ids = array(), $conditions = array(), $reset = FALSE) {
  if (empty($date_item_ids) && empty($conditions)) {
    return array();
  }

  return entity_load('date_item', $date_item_ids, $conditions, $reset);
}

/**
 * Deletes multiple date_items by ID.
 *
 * @param $date_item_ids
 *   An array of date_item IDs to delete.
 *
 * @return
 *   TRUE on success, FALSE otherwise.
 */
function date_item_delete_multiple($date_item_ids) {
  return entity_get_controller('date_item')->delete($date_item_ids);
}

/**
 * Saves a date_item.
 *
 * @param $date_item
 *   The full date_item object to save.
 *
 * @return
 *   If the record insert or update failed, returns FALSE. If it succeeded,
 *   returns SAVED_NEW or SAVED_UPDATED, depending on the operation performed.
 */
function date_item_save(dateItem $date_item) {
  return $date_item->save();
}

/**
 * Access callback: Entity API for date_item entities.
 *
 * Checks if a user has permission to execute an operation on a date_item
 * entity.
 *
 * Implements hook_date_item_access(). Modules may return a boolean value,
 * or NULL if they do not care one way or the other.
 *
 * @param string $op
 *   Operation user wishes to perform.
 * @param object $date_item
 *   (optional) A Fully loaded date_item object.
 * @param object $account
 *   (optional) An user object, or omit for logged in user.
 * @param string $entity_type
 *   (optional) Entity type of $date_item. Usually 'date_item'.
 *
 * @return bool
 *
 * @see date_item_entity_info()
 */
function date_item_access($op, $date_item = NULL, $account = NULL, $entity_type) {
  $account = isset($account) ? $account : $GLOBALS['user'];

  // bypass further access checks if user can administer date_item
  if (user_access('administer date_item', $account)) {
    return TRUE;
  }

  //check if user has access for the given operation to the referenced entity
  $src_entity = $date_item->src_entity();
  $src_type = $date_item->src_type;
  $has_access = entity_access($op, $src_type, $src_entity);
  if ($has_access)
    return true;
    
  $account_own = ($date_item->uid && ($date_item->uid == $account->uid));

  // If no access fall back to assigned permissions
  $type = $date_item->type;
  switch ($op) {
    case 'view':
      return ($account_own && user_access("view own $type date_item", $account)) || user_access("view $type date_item", $account);
    case 'update':      
      return ($account_own && user_access("update own $type date_item", $account)) || user_access("update any $type date_item", $account);
    case 'create':
      return (user_access("create $type date_item", $account));
    case 'delete':
      return ($account_own && user_access("delete own $type date_item", $account)) || user_access("delete any $type date_item", $account);
  }
  
}


/**
 * The class used for date item type entities
 */
class DateItemType extends Entity {

  public $name;
  public $label;
  public $locked;

  public function __construct($values = array()) {
    parent::__construct($values, 'date_item_type');
  }
}

/**
 * date_item Type UI controller.
 */
class DateItemTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('Manage date_item entity types, including adding and removing fields and the display of fields.');
    return $items;
  }
}

/**
 * Gets an array of all date_item types, keyed by the name.
 *
 * @param $name
 *   If set, the type with the given name is returned.
 */
function date_item_get_types($name = NULL, $for_options=false) {
  $types = entity_load_multiple_by_name('date_item_type', isset($name) ? array($name) : FALSE);

  if ($for_options) {
    $ret_types = array();
    foreach ($types as $type_key=>$type_value) {
      $ret_types[$type_key] = $type_value->label;
    }

    return $ret_types;
  }
  
  return isset($name) ? reset($types) : $types;
}

/**
* Return all date item types for options
*/
function date_item_get_types_options() {
  return date_item_get_types(NULL, true);
}

/**
 * Menu argument loader; Load a date_item type by string.
 *
 * @param $type
 *   The machine-readable name of a date_item type to load.
 *
 * @return
 *   A date_item type array or FALSE if $type does not exist.
 */
function date_item_type_load($type) {
  return date_item_get_types($type);
}

/**
 * Access callback for the entity API.
 */
function date_item_type_access($op, $entity = NULL, $account = NULL, $entity_type = NULL) {
  return user_access('administer date_item types', $account);
}

/**
 * Saves a model type to the db.
 */
function date_item_type_save(date_itemType $type) {
  $type->save();
}

/**
 * Deletes a model type from the db.
 */
function date_item_type_delete(date_itemType $type) {
  $type->delete();
}

