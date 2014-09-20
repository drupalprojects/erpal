<?php


/**
 * BatchAPI callback
 * creates Taxonomy
 */
function _erpal_taxonomy_prepare_directory(&$context){
  $context['message'] = st('Prepared to create taxonomies'); 
  $directory = 'public://term_images/';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
}

function _erpal_taxonomy_get_date_item_vocabulary(){

  $date_item_vocabulary = new stdClass();
  $date_item_vocabulary->name = 'Date item tags';
  $date_item_vocabulary->machine_name = 'date_item_tags';
  $date_item_terms = array(
    'crm' => array('name' => 'crm',),
    'contact date' => array('name' => 'contact date',),
    'contact customer' => array('name' => 'contact customer',),
    'contact agency' => array('name' => 'contact agency',), 
    'appointment' => array('name' => 'appointment',), 
    'project' => array('name' => 'project',),
    'task' => array('name' => 'task',), 
  );
  return array($date_item_vocabulary, $date_item_terms);
}

function _erpal_taxonomy_get_number_type_vocabulary(){
  $number_type_vocabulary = new stdClass();
  $number_type_vocabulary->name = 'Number types';
  $number_type_vocabulary->machine_name = 'number_types';
  $number_type_terms = array(
    'private' => array(
        'name' => 'private',
        'is_default' => 0,
    ),
    'mobile' => array(
        'name' => 'mobile',
        'is_default' => 0,
    ),
    'office' => array(
        'name' => 'office',
        'is_default' => 1,
    ),
  );
  return array($number_type_vocabulary, $number_type_terms);
}

function _erpal_taxonomy_get_address_type_vocabulary(){
  $address_type_vocabulary = new stdClass();
  $address_type_vocabulary->name = 'Address types';
  $address_type_vocabulary->machine_name = 'address_types';
  $address_type_terms = array(
	  'invoice' => array(
	    'name' => 'invoice',
	    'is_default' => 0,
	  ),
	  'private' => array(
	    'name' => 'private',
	    'is_default' => 0,
	  ),
	  'office' => array(
	    'name' => 'office',
	    'is_default' => 1,
	  ),
	   
  );
  return array($address_type_vocabulary, $address_type_terms);
}


function _erpal_taxonomy_get_activity_origin_vocabulary(){
  $activity_origin_vocabulary = new stdClass();
  $activity_origin_vocabulary->name = 'Activity origin';
  $activity_origin_vocabulary->machine_name = 'activity_origin';
  $activity_origin_terms = array(
    'Called us' => array(
      'name' => 'Called us',
      'is_default' => 1,
    ),
    'Personal contacted' => array(
      'name' => 'Personal contacted',
      'is_default' => 0,
    ),
    'Cold call' => array(
      'name' => 'Cold call',
      'is_default' => 0,
    ),
    'Event' => array(
      'name' => 'Event',
      'is_default' => 0,
    ),
    'Email' => array(
      'name' => 'Email',
      'is_default' => 0,
    ),
    'Website' => array(
      'name' => 'Website',
      'is_default' => 0,
    ),
  );
  return array($activity_origin_vocabulary, $activity_origin_terms);
}

/**
* Create some default terms for the target audience vocabulary
*/
function _erpal_taxonomy_get_target_audience_vocabulary() {
  $target_audience_vocabulary = new stdClass();
  $target_audience_vocabulary->name = 'Target audience terms';
  $target_audience_vocabulary->machine_name = 'target_audience_terms';
  $target_audience_terms = array(
    'Manufactoring company' => array(
      'name' => 'Manufactoring company',
    ),
    'Service provider' => array(
      'name' => 'Personal contacted',
    ),
    'Drupal shop' => array(
      'name' => 'Drupal shop',
    ),
    'Government' => array(
      'name' => 'Government',
    ),
  );
  return array($target_audience_vocabulary, $target_audience_terms);
}

/**
* Create some default terms for the activity lost reasons
*/
function _erpal_taxonomy_get_activity_lost_reasons_vocabulary() {
  $activity_lost_reasons_vocabulary = new stdClass();
  $activity_lost_reasons_vocabulary->name = 'Activity lost reasons';
  $activity_lost_reasons_vocabulary->machine_name = 'activity_lost_reasons';
  $activity_lost_reasons_terms = array(
    'Price to high' => array(
      'name' => 'Price to high',
    ),
    'Not enough experience' => array(
      'name' => 'Not enough experience',
    ),
    'Not enough references' => array(
      'name' => 'Not enough references',
    ),
    'No resources' => array(
      'name' => 'No resources',
    ),
  );
  return array($activity_lost_reasons_vocabulary, $activity_lost_reasons_terms);
}

/**
* Create some default salutation terms
*/
function _erpal_taxonomy_get_salutation_terms_vocabulary() {
  $target_audience_vocabulary = new stdClass();
  $target_audience_vocabulary->name = 'Salutation terms';
  $target_audience_vocabulary->machine_name = 'salutation_terms';
  $target_audience_terms = array(
    'Mr.' => array(
      'name' => 'Mr.',
    ),
    'Ms.' => array(
      'name' => 'Ms.',
    ),
    'Mrs.' => array(
      'name' => 'Mrs.',
    ),
    'Dr.' => array(
      'name' => 'Dr.',
    ),
    'Prof.' => array(
      'name' => 'Prof.',
    ),
  );
  return array($target_audience_vocabulary, $target_audience_terms);
}


/**
* Create some default salutation terms
*/
function _erpal_taxonomy_get_project_role_tags_vocabulary() {
  $project_role_tags_vocabulary = new stdClass();
  $project_role_tags_vocabulary->name = 'Project role tags';
  $project_role_tags_vocabulary->machine_name = 'project_role_tags';
  $project_role_terms = array(
    'project manager' => array(
      'name' => 'project manager',
    ),
    'team lead' => array(
      'name' => 'team lead',
    ),
    'customer' => array(
      'name' => 'customer',
    ),
    'project controler' => array(
      'name' => 'project controler',
    ),    
  );
  return array($project_role_tags_vocabulary, $project_role_terms);
}
 
function _erpal_taxonomy_get_task_type_vocabulary(){ 
  //  Create taxonomy 
  $task_type_vocabulary = new stdClass();
  $task_type_vocabulary->name = 'Task type terms';
  $task_type_vocabulary->machine_name = 'task_type_terms';
  $task_type_terms = array(
    'task' => array(
      'name' => 'task', 
      'is_default' => 1,
      'term_image' => 'erpal_task_icons/type_task.png',
    ),
    'bug' => array(
      'name' => 'bug', 
      'is_default' => 0,  
      'term_image' => 'erpal_task_icons/type_bug.png',
    ),
    'feature' => array(
      'name' => 'feature', 
      'is_default' => 0,
      'term_image' => 'erpal_task_icons/type_feature.png',
    ),  
  );   
  return array($task_type_vocabulary, $task_type_terms);
}

function _erpal_taxonomy_get_priority_vocabulary(){
  
  $priority_vocabulary = new stdClass();
  $priority_vocabulary->name = 'Priority terms';
  $priority_vocabulary->machine_name = 'priority_terms';
  $priority_terms = array(
    'low' => array(
      'name' => 'low', 
      'is_default' => 0,
      'term_image' => 'erpal_task_icons/priority_low.png',
    ),
    'middle' => array(
      'name' => 'middle',
      'is_default' => 1,
      'term_image' => 'erpal_task_icons/priority_medium.png',
    ),
    'high' => array(
      'name' => 'high',
      'is_default' => 0,
      'term_image' => 'erpal_task_icons/priority_high.png',
    ),
  );
  return array($priority_vocabulary, $priority_terms);
}
  
function _erpal_taxonomy_get_project_status_vocabulary(){
   
  $project_status_vocabulary = new stdClass();
  $project_status_vocabulary->name = 'Project status terms';
  $project_status_vocabulary->machine_name =  'project_status_terms';
  $project_status_terms = array(
    'inserted' => array(
      'name' => 'inserted',
      'is_default' => 1,
      'semantic_process' => 'in_progress',
    ),
    'on hold' => array(
      'name' => 'on hold',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    'in progress' => array(
      'name' => 'in progress',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    'aborted' => array(
      'name' => 'aborted',
      'is_default' => 0,
      'semantic_process' => 'aborted',
    ),
    'completed' => array(
      'name' => 'completed',
      'is_default' => 0,
      'semantic_process' => 'completed',
    ),
  );
  return array($project_status_vocabulary, $project_status_terms);
}

function _erpal_taxonomy_get_task_status_vocabulary(){
  
  $task_status_vocabulary = new stdClass();
  $task_status_vocabulary->name = 'Task status terms';
  $task_status_vocabulary->machine_name = 'task_status_terms';
  $task_status_terms = array(
    'inserted' => array(
      'name' => 'inserted',
      'is_default' => 1,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_new.png',
    ),
    'unclear' => array(
      'name' => 'unclear',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_question.png',      
    ),
    'buggy' => array(
      'name' => 'buggy',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_buggy.png',
    ),
    'tested' => array(
      'name' => 'tested',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_resolved.png',
    ),
    'ready to test' => array(
      'name' => 'ready to test',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_needsreview.png',
    ),
    'in progress' => array(
      'name' => 'in progress',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
      'term_image' => 'erpal_task_icons/status_inprogress.png',
    ),
    'aborted' => array(
      'name' => 'aborted',
      'is_default' => 0,
      'semantic_process' => 'aborted',
      'term_image' => 'erpal_task_icons/status_aborted.png',
    ),
    'completed' => array(
      'name' => 'completed',
      'is_default' => 0,
      'semantic_process' => 'completed',
      'term_image' => 'erpal_task_icons/status_closed.png',
    ),
  );
  return array($task_status_vocabulary, $task_status_terms);    
}

function _erpal_taxonomy_get_countries_vocabulary(){
  
  require_once(DRUPAL_ROOT . '/includes/iso.inc');
      
  $countries = _country_get_predefined_list();
  $countries_terms = array();
  
  foreach ($countries as $country_code => $country){
    $countries_terms[$country] = array(
      'name' => $country,
      'field_country_code' => $country_code,
    );
  }
  
  $countries_vocabulary = new stdClass();
  $countries_vocabulary->name = 'Countries';
  $countries_vocabulary->machine_name = 'countries';
  
  return array($countries_vocabulary, $countries_terms);
}

function _erpal_taxonomy_get_project_tags_vocabulary(){

  $project_vocabulary = new stdClass();
  $project_vocabulary->name = 'Project Tags';
  $project_vocabulary->machine_name = 'project_tags';
  $project_terms = array(
    'Sitebuilding' => array('name' => 'Sitebuilding',),
    'Backend development' => array('name' => 'Backend development',),
    'Updates' => array('name' => 'Updates',),
    'Security' => array('name' => 'Security',), 
    'Frontend' => array('name' => 'Frontend',), 
    'Concept' => array('name' => 'Concept',),
    'Server' => array('name' => 'Server',), 
  );
  return array($project_vocabulary, $project_terms);
}

function _erpal_taxonomy_get_service_category_vocabulary(){
    
  $service_category_vocabulary = new stdClass();
  $service_category_vocabulary->name = 'Service category terms';
  $service_category_vocabulary->machine_name = 'service_category_terms';
  $service_category_terms = array(
    'Consulting' => array(
      'name' => 'Consulting',
      'allow_grouping' => TRUE,
    ),
    'Backend development' => array(
      'name' => 'Backend development',
      'allow_grouping' => TRUE,
    ),
    'Travel costs' => array(
      'name' => 'Travel costs',
      'allow_grouping' => TRUE,
    ),
    'Frontend development' => array(
      'name' => 'Frontend development',
      'allow_grouping' => TRUE,
    ),
    'Training' => array(
      'name' => 'Training',
      'allow_grouping' => TRUE,
    ),
  );
  return array($service_category_vocabulary, $service_category_terms);

}

function _erpal_taxonomy_get_activity_status_vocabulary(){
 
  $activity_vocabulary = new stdClass();
  $activity_vocabulary->name = 'Activity status terms'; 
  $activity_vocabulary->machine_name = 'activity_status_terms';
  $activity_terms = array(
    'other' => array(
      'name' => 'other',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    'customer request' => array(
      'name' => 'customer request',
      'semantic_process' => 'in_progress',
      'is_default' => 1,
    ),
    'waiting for feedback' => array(
      'name' => 'waiting for feedback',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    'quote submitted' => array(
      'name' => 'quote submitted',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    'revise quote' => array(
      'name' => 'revise quote',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    'quote rejected' => array(
      'name' => 'quote rejected',
      'semantic_process' => 'aborted',
      'is_default' => 0,
    ),
    'quote accepted' => array(
      'name' => 'quote accepted',
      'semantic_process' => 'completed',
      'is_default' => 0,
    ),
    'aborted' => array(
      'name' => 'aborted',
      'semantic_process' => 'aborted',
      'is_default' => 0,
    ),
  );
  return array($activity_vocabulary, $activity_terms);
}

/**
* Only copy the images for all terms
*/
function _erpal_taxonomy_copy_images() {
  //copy default term images to public://term_images/
  $src = 'profiles/erpal/files/erpal_task_icons';
  $dir = opendir($src); 
  
  $dst = drupal_realpath('public://term_images');  
  @mkdir($dst, 0775, true); //create recursive directory if needed
  while(false !== ( $file = readdir($dir)) ) { 
    if (( $file != '.' ) && ( $file != '..' )) { 
      copy($src . '/' . $file,$dst . '/' . $file);    
    } 
  } 
  closedir($dir); 
  
  //copy default images for contacts to public://contact_default_image.png    
  $src = 'profiles/erpal/files/graphics';
  $file = 'contact_default_image.png';
  $dst = drupal_realpath('public://');
  @mkdir($dst, 0775, true);  
  copy($src . '/' . $file,$dst . '/' . $file);
}

/**
* Only copy the images for all terms
*/
function _erpal_copy_demo_files() {
  //first copy private files
  
  $src = 'profiles/erpal/files/demo_files/private';  
  $dst = drupal_realpath('private://');
  if (!$dst)  {
    $dst = drupal_realpath('public://private');  
  }
  
  @mkdir($dst, 0775, true); //create recursive directory if needed
  
  _erpal_recurse_copy($src, $dst);  
    
  //now copy public files
  $src = 'profiles/erpal/files/demo_files/public';  
  
  $dst = drupal_realpath('public://');  
  @mkdir($dst, 0775, true); //create recursive directory if needed
  _erpal_recurse_copy($src, $dst);
  
}

/**
* Copy folders recursive
*/
function _erpal_recurse_copy($src,$dst) { 
  $dir = opendir($src); 
  @mkdir($dst, 0775, true); 
  while(false !== ( $file = readdir($dir)) ) { 
    if (( $file != '.' ) && ( $file != '..' )) { 
      if ( is_dir($src . '/' . $file) ) { 
        _erpal_recurse_copy($src . '/' . $file,$dst . '/' . $file); 
      } 
      else { 
        copy($src . '/' . $file,$dst . '/' . $file);            
      } 
    } 
  } 
  closedir($dir); 
} 


/**
 * 
 * BatchAPI callback
 * This function adds a new vocabulary and fills it with terms
 * @param 
 *  $vocabulary: array with information about the vocabulary
 *  $names: list of arrays with information about the terms to create.
 *  $parts: number of chunks the actual taxonomy is divided to
 *  $index: number of the actual chunk
 *      
 */
//function erpal_taxonomy_add($vocabulary, $names){
function erpal_taxonomy_add($vocabulary, $names, $parts, $index, &$context){

  $name = $vocabulary->name;
  
  $context['message'] = st("Added '$vocabulary->name' (Part $index of $parts)");

  // check if vocabulray already exists 
  if(($existing_vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary->machine_name)) == NULL){
    taxonomy_vocabulary_save($vocabulary);
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary->machine_name);
  }else{ 
    // If vocabulary already exists, use existing one
    $vocabulary = $existing_vocabulary;
  }
  
  $semantic_process = array_key_exists('semantic_process', reset($names));
  $is_default = array_key_exists('is_default', reset($names));
  $vat_rates = array_key_exists('vat_rates', reset($names));
  $allow_grouping = array_key_exists('allow_grouping', reset($names));
  $term_image = array_key_exists('term_image', reset($names));
  $country_code = array_key_exists('field_country_code', reset($names));
  
  foreach($names as $name => $fields){
  	
	  $term = new stdClass();
	  $term->name = $name;
	  $term->vid = $vocabulary->vid;
	  if($term_image){
	    // Upload image to drupal files dir
	    $path = drupal_get_path('profile', 'erpal') 
	      . '/files/' . $fields['term_image'];  
	    $file = file_get_contents($path);
	    $filename = 'public://term_images/' . basename($path);
	    $file = file_save_data($file, $filename, FILE_EXISTS_REPLACE);
	    
	    // 
	    $term->field_term_image[LANGUAGE_NONE][0] = (array) $file;
	  }
    
    if($country_code){
      $term->field_country_code[LANGUAGE_NONE][0] = array(
        'value' => $fields['field_country_code'],
      );
    }
	  
	  if($semantic_process){
	    $term->field_simple_process_status[LANGUAGE_NONE][0] = array(
	      'value' => $fields['semantic_process'],
	    );
	  }
	    
	  if($is_default){
	    $term->field_is_default_term = array(
	      LANGUAGE_NONE => array(
	        0 => array('value' => $fields['is_default'])
	      )
	    );
	  }
	    
	  if($vat_rates){
	    $term->field_vat_rate = array(
	      LANGUAGE_NONE => array(
	        0 => array('value' => $fields['vat_rates'])
	      )
	    );
	  }
	    
	  if($allow_grouping){
	    $term->field_allow_grouping = array(
	      LANGUAGE_NONE => array(
	        0 => array('value' => $fields['allow_grouping'])
	      )
	    );        
	  }
	  taxonomy_term_save($term);
	}
}