<?php

/**
 * This script migrates previous ERPAL versions to the newest ERPAL based on a clean installation profile
 */

define('MIGRATE_VERSION', 'erpal_migrated_10');
ini_set('memory_limit', -1);
define('DRUPAL_ROOT', define_drupal_root());
chdir(DRUPAL_ROOT);
//print "DRUPAL_ROOT is " . DRUPAL_ROOT . ".<br/>\n";
define('MAINTENANCE_MODE', 'update');

global $_SERVER;
$_SERVER['REMOTE_ADDR'] = 'nothing';

global $include_dir;
$include_dir = DRUPAL_ROOT . '/includes';
$module_dir = DRUPAL_ROOT . '/modules';
$contrib_dir = DRUPAL_ROOT . '/profiles/erpal/modules/contrib';
// Use core directory if it exists.
if (file_exists(DRUPAL_ROOT . '/core/includes/bootstrap.inc')) {
  $include_dir = DRUPAL_ROOT . '/core/includes';
  $module_dir = DRUPAL_ROOT . '/core/modules';
}

$includes = array(
  $include_dir . '/bootstrap.inc',
  $include_dir . '/common.inc',
  $include_dir . '/entity.inc',
  $module_dir . '/entity/entity.module',
  $module_dir . '/entity/entity.controller.inc',
  $module_dir . '/system/system.module',
  $include_dir . '/database/query.inc',
  $include_dir . '/database/select.inc',
  $module_dir . '/entity/entity.module',
  $include_dir . '/registry.inc',
  $include_dir . '/module.inc',
  $include_dir . '/lock.inc',
  $include_dir . '/theme.inc',
  $contrib_dir . '/features/features.export.inc',
  $contrib_dir . '/features/features.module',
);

foreach ($includes as $include) {
  if (file_exists($include)) {
    require_once($include);
  }
}

drupal_bootstrap(DRUPAL_BOOTSTRAP_SESSION);

if (do_migrate_check_migrated()) {  //check if migration has already been done
  global $user;
  if ($user->uid != 1)
    die('Migration already done!');
}

do_migrate_flush();

print "Bootstrapping to DRUPAL_BOOTSTRAP_SESSION<br/>\n";
drupal_bootstrap(DRUPAL_BOOTSTRAP_SESSION);

//set variable to let drupal know which installation profile to use
variable_set('install_profile', 'erpal');

$modules = migrate_do_get_enabled_modules();

//enable the relation endpoints field, whyever it is disabled...
db_query("UPDATE {field_config} SET active=1 WHERE field_name='endpoints'");

registry_rebuild_rebuild();

//enable the relation endpoints field, whyever it is disabled...
db_query("UPDATE {field_config} SET active=1 WHERE field_name='endpoints'");

$features = migrate_do_reanable_modules($modules);
migrate_do_disable_modules();
do_migrate_flush();
migrate_do_revert_all_features($features);

migrate_do_finish();

function do_migrate_check_migrated() {
  return variable_get(MIGRATE_VERSION, false);
}

function do_migrate_flush() {
  $cache_tables = array('cache', 'cache_block', 'cache_bootstrap', 'cache_field', 'cache_filter', 'cache_form', 'cache_image', 'cache_menu', 'cache_page', 'cache_path', 'cache_token', 'cache_update', 'cache_views', 'cache_views_data');
  foreach ($cache_tables as $table) {
    try {
      cache_clear_all('*', $table, TRUE);
    } catch (Exception $e) {
      echo "Table ".$table." doesn't exist";
    }
  }
}

function migrate_do_disable_modules() {
  //disable some modules not needed 
  db_query("UPDATE {system} SET status=0 WHERE name='rel'");
  db_query("UPDATE {system} SET status=0 WHERE name='rdf'");
 
}

function migrate_do_get_enabled_modules() {
  $modules = array();
  $res = db_query('SELECT name FROM {system} WHERE status=1');
  while ($name = $res->fetchField()) { 
    $new_modules = migrate_do_refactored_modules($name);
    if (count($new_modules))
      $modules = array_merge($modules, $new_modules);
    else
      $modules[] = $name;
  }
  
  return $modules;
}

/**
* Old features where named feature_ and contained core elements and ui elements. No they are separated, so there may be two modules now for one
*/
function migrate_do_refactored_modules($name) {
  switch ($name) {
    case 'feature_erpal_basic':
      return array('erpal_basic', 'erpal_basic_ui');
    case 'feature_erpal_book':
      return array('erpal_book', 'erpal_book_ui');
    case 'feature_erpal_bookmark':
      return array('erpal_bookmark', 'erpal_bookmark_ui');
    case 'feature_erpal_calendar':
      return array('erpal_calendar', 'erpal_calendar_ui');
    case 'feature_erpal_contract':
      return array('erpal_contract', 'erpal_contract_ui');
    case 'feature_erpal_crm':
      return array('erpal_crm', 'erpal_crm_ui');
    case 'feature_erpal_dashboard':
      return array('erpal_dashboard');
    case 'feature_erpal_docs':
      return array('erpal_docs', 'erpal_docs_ui');
    case 'feature_erpal_employee':
      return array('erpal_employee', 'erpal_employee_ui');
    case 'feature_erpal_profile':
      return array('erpal_profile');
    case 'feature_erpal_project':
      return array('erpal_project', 'erpal_project_ui');
  }
  
  return array();
}

function migrate_do_finish() {
  print "Flushing all caches<br/>\n";

  //drupal_flush_all_caches();
  cache_clear_all();

  //set variable to let drupal know which installation profile to use
  variable_set('install_profile', 'erpal');
  print "Ready to go!";
  
  variable_set(MIGRATE_VERSION, time());
}

function migrate_do_revert_all_features($modules) {
  
  features_include();
  foreach ($modules as $module) {
    $components = array();
    if (($feature = feature_load($module, TRUE)) && module_exists($module)) {      
      // Forcefully revert all components of a feature.
      foreach (array_keys($feature->info['features']) as $component) {
        if (features_hook($component, 'features_revert')) {
          $components[] = $component;
        }
      }
    } else {
      echo "Module ".$module." does not exist<br/>";
    }
    foreach ($components as $component) {
      features_revert(array($module => array($component)));
    }
  }
}

/**
* Re-enable all modules from erpal installation profile
*/
function migrate_do_reanable_modules($modules) {

  $features = array();
  foreach ($modules as $module) {
    if (strpos($module, 'feature_') === 0) {
      $features[] = $module;    
    }
    
    //not install again, only set enabled in the datebase
    db_update('system')
      ->fields(array('status' => 1))
      ->condition('type', 'module')
      ->condition('name', $module)
      ->execute();
  }
  
  //enable new modules
  $new_modules = array('erpal_layout', 'erpal_project_ui', 'erpal_invoice_ui', 'erpal_employee_ui', 'erpal_docs_ui', 'erpal_dashboard', 'erpal_crm_ui', 'erpal_contract_ui', 'erpal_calendar_ui', 'erpal_bookmark_ui', 'erpal_book_ui', 'erpal_basic_ui', 'content_access_view');
  module_enable($new_modules);
  
  return $features;
}

/**
 * Find the drupal root directory by looking in parent directories.
 * If unable to discover it, fail and exit.
 */
function define_drupal_root() {
  // This is the smallest number of directories to go up: from /sites/all/modules/registry_rebuild.
  $parent_count = 1;
  // 8 seems reasonably far to go looking up.
  while ($parent_count < 8) {
    $dir = realpath(getcwd() . str_repeat('/..', $parent_count));
    if (file_exists($dir . '/index.php')) {
      return $dir;
    }
    $parent_count++;
  }
  print "Failure: Unable to discover DRUPAL_ROOT. You may want to explicitly define it near the top of registry_rebuild.php";
  exit(1);
}

/**
 * Before calling this we need to be bootstrapped to DRUPAL_BOOTSTRAP_DATABASE.
 */
function registry_rebuild_rebuild() {
  // This section is not functionally important. It's just getting the
  // registry_parsed_files() so that it can report the change.
  $connection_info = Database::getConnectionInfo();
  $driver = $connection_info['default']['driver'];
  global $include_dir;
  require_once $include_dir . '/database/' . $driver . '/query.inc';

  $parsed_before = registry_get_parsed_files();

  cache_clear_all('lookup_cache', 'cache_bootstrap');
  cache_clear_all('variables', 'cache_bootstrap');
  cache_clear_all('module_implements', 'cache_bootstrap');

  print "Doing registry_rebuild() in DRUPAL_BOOTSTRAP_SESSION<br/>\n";
  registry_rebuild(); // At lower level

  print "Bootstrapping to DRUPAL_BOOTSTRAP_FULL<br/>\n";
  drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
  print "Doing registry_rebuild() in DRUPAL_BOOTSTRAP_FULL<br/>\n";
  db_truncate('cache');
  registry_rebuild();
  $parsed_after = registry_get_parsed_files();

  // Remove files which don't exist anymore.
  $filenames = array();
  foreach ($parsed_after as $filename => $file) {
    if (!file_exists($filename)) {
      $filenames[] = $filename;
    }
  }

  if (!empty($filenames)) {
    db_delete('registry_file')
      ->condition('filename', $filenames)
      ->execute();
    db_delete('registry')
      ->condition('filename', $filenames)
      ->execute();
    print("Deleted " . count($filenames) . ' stale files from registry manually.');
  }

  $parsed_after = registry_get_parsed_files();

  //print "Flushing all caches<br/>\n";
  //drupal_flush_all_caches();

  //print "There were " . count($parsed_before) . " files in the registry before and " . count($parsed_after) . " files now.<br/>\n";
  //print "If you don't see any crazy fatal errors, your registry has been rebuilt.<br/>\n";
}
