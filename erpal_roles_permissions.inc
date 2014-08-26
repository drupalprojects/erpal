<?php
/**
 * @file
 * Creates basic userroles and configures the permissions for the new erpal-installation
 * Code is mostly copied from the permissions-feature
 */
 
 
/**
 * Creates userroles and configures permissions as defined in  _erpal_roles_permissions_get_config()
 */
function erpal_save_roles_and_configure_permissions(){
  
  // Remove all permissions from the database:
  db_delete('role_permission')->execute();
  drupal_static_reset('user_access');
  drupal_static_reset('user_role_permissions');
    
  // Get permission configuration
  $config = _erpal_roles_permissions_get_config();
  
  // set permissions configuration
  _erpal_save_roles_permissions($config);


  module_load_include('module', 'content_access_view');
  if(function_exists('content_access_view_sync')){
    content_access_view_sync();
  }
}

/**
 * Takes the arrays of roles and permissions as they are exported by features and
 * saves them to the database
 * @param $roles: array of userroles as it is exported from features
 * @param $permissions: array of permissions as it is exported from features 
 */
function _erpal_save_roles_permissions($roles){
    
  // special routine for 'authenticated user'  
  if(isset($roles['authenticated user'])){
    $perms = (isset($roles['authenticated user']['permissions']))
      ? $roles['authenticated user']['permissions']
      : array();
    erpal_role_grant_permissions(DRUPAL_AUTHENTICATED_RID, $perms);
    unset($roles['authenticated user']);
  }
  
  // special routine for the 'anonymous user'
  if(isset($roles['anonymous user'])){
    $perms = (isset($roles['anonymous user']['permissions']))
      ? $roles['anonymous user']['permissions']
      : array();
    erpal_role_grant_permissions(DRUPAL_ANONYMOUS_RID, $perms);
    unset($roles['anonymous user']);
  }
  
  // for each userrole
  foreach ($roles as $role_value) {
    // extract permissions from the array
    if (isset($role_value['permissions'])) {
      $perms = $role_value['permissions'];
      unset($role_value['permissions']);
    }else $perms = FALSE; // if no permissions are set, set $perms to false 
    
    $role_object = new stdClass();
    $role_object->name = $role_value['role']['name'];
    $role_object->weight = $role_value['role']['weight'];
    // save actual userrole
    user_role_save($role_object);
    if($perms){
      // if $perms is not false set permissions for the actual userrole
      erpal_role_grant_permissions($role_object->rid, $perms);
    }
  }
}

/**
 * Copied from user module and modified to prevent errors during the installation 
 * profile and skip the configuration of a permission if the related module is not 
 * installed.
 * Maybe the original function can be used again later
 * 
 */
function erpal_role_grant_permissions($rid, array $permissions = array()) {
  $modules = user_permission_get_modules();
  // Grant new permissions for the role.
  foreach ($permissions as $name) {
    
    // skip permission if related module is not installed
    if (!isset($modules[$name])) {
      continue;
    }
    
    db_merge('role_permission')
      ->key(array(
        'rid' => $rid,
        'permission' => $name,
      ))
      ->fields(array(
        'module' => $modules[$name],
      ))
      ->execute();
  }

  // Clear the user access cache.
  drupal_static_reset('user_access');
  drupal_static_reset('user_role_permissions');
  
}

function _erpal_roles_permissions_get_config(){
$export = array(
  'anonymous user' => array(
    'role' => array(
      'name' => 'anonymous user',
      'weight' => '0',
      ),
    'permissions' => array(
      ),
    ),
  'authenticated user' => array(
    'role' => array(
      'name' => 'authenticated user',
      'weight' => '1',
      ),
    'permissions' => array(
      'access bookmarks view',
      'access comments',
      'access content',
      'access documents view',
      'access projects view',
      'access sub tasks and tickets details view',
      'access sub tasks and tickets view',
      'access tasks tree',
      'access tickets details',
      'access tickets view',
      'access user profiles',
      'create erpal_file content',
      'create erpal_task content',
      'delete own erpal_task content',
      'delete own simple_date date_item',
      'delete own timetracking',
      'edit own erpal_file content',
      'edit own erpal_task content',
      'edit own main profile',
      'edit own timetracking',
      'erpal print tasks',
      'field view task advanced',
      'flag bookmark_flag',
      'flag project_subscriptions',
      'flag task_subscriptions',
      'post comments',
      'search content',
      'skip comment approval',
      'unflag bookmark_flag',
      'unflag project_subscriptions',
      'unflag task_subscriptions',
      'use access tokens',
      'use text format filtered_html',
      'view own contract profile',
      'view own erpal_book content',
      'view own erpal_book_page content',
      'view own erpal_contact content',
      'view own erpal_contract content',
      'view own erpal_crm_activity content',
      'view own erpal_date content',
      'view own erpal_file content',
      'view own erpal_invoice content',
      'view own erpal_project content',
      'view own erpal_task content',
      'view own erpal_timetracking content',
      'view own erpal_working_time content',
      'view own main profile',
      'view own simple_date date_item',
      'view revisions',
      'view simple_date date_item',
      'access erpal heartbeat',
      'use any shortcut key',
      'use javascript shortcut type',
      ),
    ),
  'customer' => array(
    'role' => array(
      'name' => 'customer',
      'weight' => '2',
      ),
    'permissions' => array(
      ),
    ),
  'internal developer' => array(
    'role' => array(
      'name' => 'internal developer',
      'weight' => '3',
      ),
    'permissions' => array(
      'access books view',
      'access calendar view',
      'access relations',
      'access sub tasks and tickets tree view',
      'access tasks details',
      'access tasks view',
      'access tickets tree',
      'access timetrackings view',
      'administer relations',
      'bypass tasks view access',
      'bypass tickets view access',
      'create erpal_book content',
      'create erpal_book_page content',
      'create erpal_contact content',
      'create erpal_date content',
      'create erpal_project content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create relations',
      'create simple_date date_item',
      'create timetracking',
      'delete any erpal_file content',
      'delete any erpal_project content',
      'delete any erpal_task content',
      'delete any simple_date date_item',
      'delete own erpal_book content',
      'delete own erpal_book_page content',
      'delete own erpal_contact content',
      'delete own erpal_date content',
      'delete own erpal_file content',
      'delete own erpal_project content',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'delete relations',
      'delete revisions',
      'edit any erpal_contact content',
      'edit any erpal_date content',
      'edit any erpal_file content',
      'edit any erpal_project content',
      'edit any erpal_task content',
      'edit own erpal_book content',
      'edit own erpal_book_page content',
      'edit own erpal_contact content',
      'edit own erpal_date content',
      'edit own erpal_project content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'edit relations',
      'field edit task advanced',
      'field edit timetracking duration',
      'field view timetracking duration',
      'revert revisions',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view any erpal_contact content',
      'view any erpal_file content',
      'view any erpal_project content',
      'view any erpal_project_release content',
      'view any erpal_task content',
      'view any main profile',
      'view any timetracking',
      'view own erpal_contact content',
      'view own erpal_project_release content',
      'view timekeeping',
      ),
    ),
  'external developer' => array(
    'role' => array(
      'name' => 'external developer',
      'weight' => '4',
      ),
    'permissions' => array(
      'access calendar view',
      'access tasks view',
      'access timetrackings view',
      'create erpal_date content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create simple_date date_item',
      'create timetracking',
      'delete any simple_date date_item',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'edit any erpal_task content',
      'edit own erpal_date content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'field edit task advanced',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view timekeeping',
      ),
    ),
  'financial user' => array(
    'role' => array(
      'name' => 'financial user',
      'weight' => '5',
      ),
    'permissions' => array(
      'access activities view',
      'access billables view',
      'access books view',
      'access budgets view',
      'access calendar view',
      'access contact view',
      'access contracts view',
      'access invoices view',
      'access relations',
      'access tasks view',
      'access timetrackings view',
      'administer relations',
      'bypass tasks view access',
      'bypass tickets view access',
      'create budget',
      'create erpal_book content',
      'create erpal_book_page content',
      'create erpal_contact content',
      'create erpal_contract content',
      'create erpal_date content',
      'create erpal_invoice content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create relations',
      'create simple_date date_item',
      'create timetracking',
      'delete any erpal_book content',
      'delete any erpal_book_page content',
      'delete any erpal_contact content',
      'delete any erpal_contract content',
      'delete any erpal_file content',
      'delete any erpal_invoice content',
      'delete any simple_date date_item',
      'delete own erpal_book content',
      'delete own erpal_book_page content',
      'delete own erpal_contact content',
      'delete own erpal_contract content',
      'delete own erpal_date content',
      'delete own erpal_file content',
      'delete own erpal_invoice content',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'delete relations',
      'delete revisions',
      'edit any billable',
      'edit any budget',
      'edit any erpal_book content',
      'edit any erpal_book_page content',
      'edit any erpal_contact content',
      'edit any erpal_contract content',
      'edit any erpal_date content',
      'edit any erpal_file content',
      'edit any erpal_invoice content',
      'edit own erpal_book content',
      'edit own erpal_book_page content',
      'edit own erpal_contact content',
      'edit own erpal_contract content',
      'edit own erpal_date content',
      'edit own erpal_invoice content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'edit relations',
      'field edit pricing',
      'field edit task advanced',
      'field edit timetracking duration',
      'field view pricing',
      'field view timetracking duration',
      'revert revisions',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view any billable',
      'view any budget',
      'view any erpal_book content',
      'view any erpal_book_page content',
      'view any erpal_contact content',
      'view any erpal_contract content',
      'view any erpal_file content',
      'view any erpal_invoice content',
      'view any erpal_project content',
      'view any erpal_timetracking content',
      'view any erpal_working_time content',
      'view any main profile',
      'view any timetracking',
      'view own erpal_contact content',
      'view timekeeping',
      ),
    ),
  'controller' => array(
    'role' => array(
      'name' => 'controller',
      'weight' => '6',
      ),
    'permissions' => array(
      'access activities view',
      'access billables view',
      'access books view',
      'access budgets view',
      'access calendar view',
      'access contact view',
      'access contracts view',
      'access invoices view',
      'access relations',
      'access timetrackings view',
      'bypass tasks view access',
      'bypass tickets view access',
      'create erpal_contract content',
      'create erpal_date content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create simple_date date_item',
      'create timetracking',
      'create working times offset',
      'delete any erpal_date content',
      'delete any erpal_file content',
      'delete any erpal_working_time content',
      'delete any simple_date date_item',
      'delete own erpal_contract content',
      'delete own erpal_date content',
      'delete own erpal_file content',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'delete revisions',
      'delete working times offset',
      'edit any contract profile',
      'edit any erpal_contract content',
      'edit any erpal_date content',
      'edit any erpal_file content',
      'edit any erpal_working_time content',
      'edit any main profile',
      'edit own contract profile',
      'edit own erpal_contract content',
      'edit own erpal_date content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'edit working times offset',
      'field edit task advanced',
      'field edit timetracking duration',
      'field view pricing',
      'field view timetracking duration',
      'revert revisions',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view any contract profile',
      'view any erpal_book content',
      'view any erpal_book_page content',
      'view any erpal_contact content',
      'view any erpal_contract content',
      'view any erpal_file content',
      'view any erpal_invoice content',
      'view any erpal_project content',
      'view any erpal_working_time content',
      'view any main profile',
      'view any timekeeping',
      'view any timetracking',
      'view own erpal_contact content',
      'view timekeeping',
      ),
    ),
  'account manager' => array(
    'role' => array(
      'name' => 'account manager',
      'weight' => '7',
      ),
    'permissions' => array(
      'access activities view',
      'access books view',
      'access budgets view',
      'access calendar view',
      'access contact view',
      'access contracts view',
      'access relations',
      'administer relations',
      'bypass tasks view access',
      'bypass tickets view access',
      'clone complete books',
      'create erpal_book content',
      'create erpal_book_page content',
      'create erpal_contact content',
      'create erpal_contract content',
      'create erpal_crm_activity content',
      'create erpal_date content',
      'create erpal_invoice content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create relations',
      'create simple_date date_item',
      'create timetracking',
      'delete any erpal_contact content',
      'delete any erpal_crm_activity content',
      'delete any erpal_date content',
      'delete any erpal_file content',
      'delete any erpal_invoice content',
      'delete any erpal_working_time content',
      'delete any simple_date date_item',
      'delete own erpal_book content',
      'delete own erpal_book_page content',
      'delete own erpal_contact content',
      'delete own erpal_contract content',
      'delete own erpal_crm_activity content',
      'delete own erpal_date content',
      'delete own erpal_file content',
      'delete own erpal_invoice content',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'delete relations',
      'delete revisions',
      'edit any erpal_book content',
      'edit any erpal_book_page content',
      'edit any erpal_contact content',
      'edit any erpal_contract content',
      'edit any erpal_crm_activity content',
      'edit any erpal_date content',
      'edit any erpal_file content',
      'edit any erpal_invoice content',
      'edit own erpal_book content',
      'edit own erpal_book_page content',
      'edit own erpal_contact content',
      'edit own erpal_contract content',
      'edit own erpal_crm_activity content',
      'edit own erpal_date content',
      'edit own erpal_invoice content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'edit relations',
      'field edit task advanced',
      'field edit timetracking duration',
      'field view timetracking duration',
      'revert revisions',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view any erpal_book content',
      'view any erpal_book_page content',
      'view any erpal_contact content',
      'view any erpal_contract content',
      'view any erpal_crm_activity content',
      'view any erpal_file content',
      'view any erpal_project content',
      'view any erpal_timetracking content',
      'view any erpal_working_time content',
      'view any main profile',
      'view own erpal_contact content',
      'view timekeeping',
      ),
    ),
  'project manager' => array(
    'role' => array(
      'name' => 'project manager',
      'weight' => '8',
      ),
    'permissions' => array(
      'access books view',
      'access budgets view',
      'access calendar view',
      'access contact view',
      'access relations',
      'access sub tasks and tickets tree view',
      'access tasks details',
      'access tasks view',
      'access tickets tree',
      'access timetrackings view',
      'administer relations',
      'administer timetrackings',
      'bypass tasks view access',
      'bypass tickets view access',
      'clone complete books',
      'create budget',
      'create erpal_book content',
      'create erpal_book_page content',
      'create erpal_contact content',
      'create erpal_contract content',
      'create erpal_crm_activity content',
      'create erpal_date content',
      'create erpal_invoice content',
      'create erpal_project content',
      'create erpal_project_release content',
      'create erpal_timetracking content',
      'create erpal_working_time content',
      'create relations',
      'create simple_date date_item',
      'create timetracking',
      'delete any erpal_book content',
      'delete any erpal_book_page content',
      'delete any erpal_crm_activity content',
      'delete any erpal_date content',
      'delete any erpal_file content',
      'delete any erpal_invoice content',
      'delete any erpal_project content',
      'delete any erpal_project_release content',
      'delete any erpal_task content',
      'delete any erpal_timetracking content',
      'delete any erpal_working_time content',
      'delete any simple_date date_item',
      'delete own erpal_book content',
      'delete own erpal_book_page content',
      'delete own erpal_contact content',
      'delete own erpal_contract content',
      'delete own erpal_crm_activity content',
      'delete own erpal_date content',
      'delete own erpal_file content',
      'delete own erpal_invoice content',
      'delete own erpal_project content',
      'delete own erpal_project_release content',
      'delete own erpal_timetracking content',
      'delete own erpal_working_time content',
      'delete relations',
      'delete revisions',
      'edit any budget',
      'edit any erpal_book content',
      'edit any erpal_book_page content',
      'edit any erpal_contact content',
      'edit any erpal_contract content',
      'edit any erpal_crm_activity content',
      'edit any erpal_date content',
      'edit any erpal_file content',
      'edit any erpal_invoice content',
      'edit any erpal_project content',
      'edit any erpal_project_release content',
      'edit any erpal_task content',
      'edit any erpal_timetracking content',
      'edit any erpal_working_time content',
      'edit any timetracking',
      'edit own erpal_book content',
      'edit own erpal_book_page content',
      'edit own erpal_contact content',
      'edit own erpal_contract content',
      'edit own erpal_crm_activity content',
      'edit own erpal_date content',
      'edit own erpal_invoice content',
      'edit own erpal_project content',
      'edit own erpal_project_release content',
      'edit own erpal_timetracking content',
      'edit own erpal_working_time content',
      'edit relations',
      'field edit pricing',
      'field edit task advanced',
      'field edit timetracking duration',
      'field view pricing',
      'field view timetracking duration',
      'revert revisions',
      'update any simple_date date_item',
      'update own simple_date date_item',
      'use quick timetracking',
      'use text format full_html',
      'view any billable',
      'view any budget',
      'view any erpal_book content',
      'view any erpal_book_page content',
      'view any erpal_contact content',
      'view any erpal_crm_activity content',
      'view any erpal_file content',
      'view any erpal_project content',
      'view any erpal_project_release content',
      'view any erpal_task content',
      'view any erpal_timetracking content',
      'view any erpal_working_time content',
      'view any main profile',
      'view any timekeeping',
      'view any timetracking',
      'view own erpal_contact content',
      'view own erpal_project_release content',
      'view timekeeping',
      ),
    ),
  );
  return $export;
}

