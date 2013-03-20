<?php

function erpal_create_taxonomy(){
  
  $activity_origin_vocabulary = new stdClass();
  $activity_origin_vocabulary->name = 'Activity origin';
  $activity_origin_vocabulary->machine_name = 'activity_origin';
  $activity_origin_terms = array(
    array(
      'name' => 'Called us',
      'is_default' => 1,
    ),
    array(
      'name' => 'Personal contacted',
      'is_default' => 0,
    ),
    array(
      'name' => 'Cold call',
      'is_default' => 0,
    ),
    array(
      'name' => 'Event',
      'is_default' => 0,
    ),
    array(
      'name' => 'Email',
      'is_default' => 0,
    ),
    array(
      'name' => 'Website',
      'is_default' => 0,
    ),
  );
  erpal_taxonomy_add($activity_origin_vocabulary, $activity_origin_terms);
  
  
  //  Create taxonomy 
  $task_type_vocabulary = new stdClass();
  $task_type_vocabulary->name = 'Task type terms';
  $task_type_vocabulary->machine_name = 'task_type_terms';
  $task_type_terms = array(
    array(
      'name' => 'task', 
      'is_default' => 1,
    ),
    array(
      'name' => 'bug', 
      'is_default' => 0,  
    ),
    array(
      'name' => 'feature', 
      'is_default' => 0,
    ),  
  );   
  erpal_taxonomy_add($task_type_vocabulary, $task_type_terms);
    

  $priority_vocabulary = new stdClass();
  $priority_vocabulary->name = 'Priority terms';
  $priority_vocabulary->machine_name = 'priority_terms';
  $priority_terms = array(
    array(
      'name' => 'low', 
      'is_default' => 0,
    ),
    array(
      'name' => 'middle',
      'is_default' => 1,
    ),
    array(
      'name' => 'high',
      'is_default' => 0,
    ),
  );
  erpal_taxonomy_add($priority_vocabulary, $priority_terms);
  
  
  
  $project_status_vocabulary = new stdClass();
  $project_status_vocabulary->name = 'Project status terms';
  $project_status_vocabulary->machine_name =  'project_status_terms';
  $project_status_terms = array(
    array(
      'name' => 'inserted',
      'is_default' => 1,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'on hold',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'in progress',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'aborted',
      'is_default' => 0,
      'semantic_process' => 'aborted',
    ),
    array(
      'name' => 'completed',
      'is_default' => 0,
      'semantic_process' => 'completed',
    ),
  );
  erpal_taxonomy_add($project_status_vocabulary, $project_status_terms);



  $task_status_vocabulary = new stdClass();
  $task_status_vocabulary->name = 'Task status terms';
  $task_status_vocabulary->machine_name = 'task_status_terms';
  $task_status_terms = array(
    array(
      'name' => 'inserted',
      'is_default' => 1,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'unclear',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'buggy',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'tested',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'ready to test',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'in progress',
      'is_default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'aborted',
      'is_default' => 0,
      'semantic_process' => 'aborted',
    ),
    array(
      'name' => 'completed',
      'is_default' => 0,
      'semantic_process' => 'completed',
    ),
  );
  erpal_taxonomy_add($task_status_vocabulary, $task_status_terms);    
  
  
  $countries_vocabulary = new stdClass();
  $countries_vocabulary->name = 'Countries';
  $countries_vocabulary->machine_name = 'countries';
  $countries_terms = array(
    array(
      'name' => 'Austria',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Belgium',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Bulgaria',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Czeck Republic',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Denmark',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Estonia',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Germany',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Greece',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Spain',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'France',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'India',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Ireland',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Italy',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Cyprus',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Latvia',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Lithuania',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Luxembourg',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Hungary',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Malta',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Netherlands',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Austria',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Poland',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Portugal',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Romania',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Slovenia',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Slovakia',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Swizerland',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Finland',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'Sweden',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'United Kingdom',
      'vat_rates' => '19',
    ),
    array(
      'name' => 'United States',
      'vat_rates' => '19',
    ),
  );
  erpal_taxonomy_add($countries_vocabulary, $countries_terms);
  
  $project_vocabulary = new stdClass();
  $project_vocabulary->name = 'Project Tags';
  $project_vocabulary->machine_name = 'project_tags';
  $project_terms = array(
    array('name' => 'Sitebuilding',),
    array('name' => 'Backend development',),
    array('name' => 'Updates',),
    array('name' => 'Security',), 
    array('name' => 'Frontend',), 
    array('name' => 'Concept',),
    array('name' => 'Server',), 
  );
  erpal_taxonomy_add($project_vocabulary, $project_terms);

  
  $service_category_vocabulary = new stdClass();
  $service_category_vocabulary->name = 'Service category terms';
  $service_category_vocabulary->machine_name = 'service_category_terms';
  $service_category_terms = array(
    array(
      'name' => 'Beratung',
      'allow_grouping' => TRUE,
    ),
    array(
      'name' => 'Backend-Entwicklung',
      'allow_grouping' => TRUE,
    ),
    array(
      'name' => 'Reisekosten',
      'allow_grouping' => TRUE,
    ),
    array(
      'name' => 'Frontend-Entwicklung',
      'allow_grouping' => TRUE,
    ),
    array(
      'name' => 'Schulung',
      'allow_grouping' => TRUE,
    ),
  );
  erpal_taxonomy_add($service_category_vocabulary, $service_category_terms);


 
  $activity_vocabulary = new stdClass();
  $activity_vocabulary->name = 'Activity status terms'; 
  $activity_vocabulary->machine_name = 'activity_status_terms';
  $activity_terms = array(
    array(
      'name' => 'other',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    array(
      'name' => 'customer request',
      'semantic_process' => 'in_progress',
      'is_default' => 1,
    ),
    array(
      'name' => 'waiting for feedback',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    array(
      'name' => 'quote submitted',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    array(
      'name' => 'revise quote',
      'semantic_process' => 'in_progress',
      'is_default' => 0,
    ),
    array(
      'name' => 'quote rejected',
      'semantic_process' => 'aborted',
      'is_default' => 0,
    ),
    array(
      'name' => 'quote accepted',
      'semantic_process' => 'completed',
      'is_default' => 0,
    ),
    array(
      'name' => 'aborted',
      'semantic_process' => 'aborted',
      'is_default' => 0,
    ),
  );
 erpal_taxonomy_add($activity_vocabulary, $activity_terms);
}



/**
 * 
 * This function adds a new vocabulary and fills it with terms
 * @param 
 *  $vocabulary: array with information about the vocabulary
 *  $names: list of arrays with information about the terms to create.
 *      
 */
function erpal_taxonomy_add($vocabulary, $names){
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
  
  foreach($names as $name){
      $term = new stdClass();
      $term->name = $name['name'];
      $term->vid = $vocabulary->vid;
      if($semantic_process){
        $term->field_simple_process_status = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['semantic_process'])
          )
        );
      }
        
      if($is_default){
        $term->field_is_default_term = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['is_default'])
          )
        );
      }
        
      if($vat_rates){
        $term->field_vat_rate = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['vat_rates'])
          )
        );
      }
        
      if($allow_grouping){
        $term->field_allow_grouping = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['allow_grouping'])
          )
        );        
      }
      taxonomy_term_save($term);
    }
}




