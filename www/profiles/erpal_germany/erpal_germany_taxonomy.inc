<?php

function erpal_germany_create_taxonomy(){
  
  //  Create taxonomy
  $task_type_vocabulary = new stdClass();
  $task_type_vocabulary->name = 'Task type terms';
  $task_type_vocabulary->description = st('The type of the task, such as task, bug or feature.');
  $task_type_vocabulary->machine_name = 'task_type_terms';
  $task_type_vocabulary->help = st('Select the type of the task.');
  $task_type_terms = array(
    array(
      'name' => 'task', 
      'default' => 1,
    ),
    array(
      'name' => 'bug', 
      'default' => 0,  
    ),
    array(
      'name' => 'feature', 
      'default' => 0,
    ), 
  );   
  erpal_germany_taxonomy_add($task_type_vocabulary, $task_type_terms);
    

  $priority_vocabulary = new stdClass();
  $priority_vocabulary->name = 'Priority terms';
  $priority_vocabulary->description = st('The priority of the task');
  $priority_vocabulary->machine_name = 'priority_terms';
  $priority_vocabulary->help = st('Select the priority'); 
  $priority_terms = array(
    array(
      'name' => 'low', 
      'default' => 0,
    ),
    array(
      'name' => 'middle',
      'default' => 1,
    ),
    array(
      'name' => 'high',
      'default' => 0,
    ),
  );
  erpal_germany_taxonomy_add($priority_vocabulary, $priority_terms);
  
  
  
  $project_status_vocabulary = new stdClass();
  $project_status_vocabulary->name = 'Project status terms';
  $project_status_vocabulary->description = st('The status of the project, such as inserted, in progress or completed.');
  $project_status_vocabulary->machine_name =  'project_status_terms';
  $project_status_vocabulary->help = st('Select the status of the project.');
  $project_status_terms = array(
    array(
      'name' => 'inserted',
      'default' => 1,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'on hold',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'in progress',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'aborted',
      'default' => 0,
      'semantic_process' => 'aborted',
    ),
    array(
      'name' => 'completed',
      'default' => 0,
      'semantic_process' => 'completed',
    ),
  );
  erpal_germany_taxonomy_add($project_status_vocabulary, $project_status_terms);



  $task_status_vocabulary = new stdClass();
  $task_status_vocabulary->name = 'Task status terms';
  $task_status_vocabulary->description = st('The status of the task, such as inserted, on hold or completed');
  $task_status_vocabulary->machine_name = 'task_status_terms';
  $task_status_vocabulary->help = st('Select the status of the task');
  $task_status_terms = array(
    array(
      'name' => 'inserted',
      'default' => 1,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'unclear',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'buggy',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'tested',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'ready to test',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'in progress',
      'default' => 0,
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'aborted',
      'default' => 0,
      'semantic_process' => 'aborted',
    ),
    array(
      'name' => 'completed',
      'default' => 0,
      'semantic_process' => 'completed',
    ),
  );
  erpal_germany_taxonomy_add($task_status_vocabulary, $task_status_terms);    
  
  
  $countries_vocabulary = new stdClass();
  $countries_vocabulary->name = 'Countries';
  $countries_vocabulary->machine_name = 'countries';
  $countries_vocabulary->help = t('Select the country');
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
  );
  erpal_germany_taxonomy_add($countries_vocabulary, $countries_terms);
  
  $project_vocabulary = new stdClass();
  $project_vocabulary->name = 'Project Tags';
  $project_vocabulary->description = st('The type of the project');
  $project_vocabulary->machine_name = 'project_tags';
  $project_vocabulary->help = st('Select the type of the project');
  $project_terms = array(
    array('name' => 'Sitebuilding',),
    array('name' => 'Backend development',),
    array('name' => 'Updates',),
    array('name' => 'Security',), 
    array('name' => 'Frontend',), 
    array('name' => 'Concept',),
    array('name' => 'Server',), 
  );
  erpal_germany_taxonomy_add($project_vocabulary, $project_terms);

  $service_category_vocabulary = new stdClass();
  $service_category_vocabulary->name = 'Service category';
  $service_category_vocabulary->machine_name = 'service_category_terms';
  $service_category_terms = array(
    array(
      'name' => 'Beratung',
      'allow_grouping' => TRUE),
    array(
      'name' => 'Backend-Entwicklung',
      'allow_grouping' => TRUE),
    array(
      'name' => 'Reisekosten',
      'allow_grouping' => TRUE),
    array(
      'name' => 'Frontend-Entwicklung',
      'allow_grouping' => TRUE),
    array(
      'name' => 'Schulung',
      'allow_grouping' => TRUE),
  );
  erpal_germany_taxonomy_add($service_category_vocabulary, $service_category_terms);
  

 
  $activity_vocabulary = new stdClass();
  $activity_vocabulary->name = 'Activity status terms'; 
  $activity_vocabulary->description = st('The status of the activity');
  $activity_vocabulary->machine_name = 'activity_status_terms';
  $activity_vocabulary->help = st('Select the status of the activity');
  $activity_terms = array(
    array(
      'name' => 'other',
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'customer request',
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'waiting for feedback',
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'quote submitted',
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'revise quote',
      'semantic_process' => 'in_progress',
    ),
    array(
      'name' => 'quote rejected',
      'semantic_process' => 'aborted',
    ),
    array(
      'name' => 'quote accepted',
      'semantic_process' => 'completed',
    ),
    array(
      'name' => 'aborted',
      'semantic_process' => 'aborted',
    ),
  );
 erpal_germany_taxonomy_add($activity_vocabulary, $activity_terms);
}



/**
 * 
 * This function adds a new vocabulary and fills it with terms
 * @param 
 *  $vocabulary: array with information about the vocabulary
 *  $names: list of arrays with information about the terms to create.
 *      
 */
function erpal_germany_taxonomy_add($vocabulary, $names){
  // check if vocabulray already exists 
  if(($existing_vocabulary = erpal_germany_get_vocabulary_by_name($vocabulary->name)) == NULL){
    taxonomy_vocabulary_save($vocabulary);
    $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary->machine_name);
  }else{ 
    // If vocabulary already exists, use existing one
    $vocabulary = $existing_vocabulary;
  }
  
  $semantic_process = array_key_exists('semantic_process', reset($names));
  $default = array_key_exists('default', reset($names));
  $vat_rates = array_key_exists('vat_rates', reset($names));
  $allow_grouping = array_key_exists('allow_grouping', reset($names));
  
  foreach($names as $name){
      $term = new stdClass();
      $term->name = $name['name'];
      $term->vid = $vocabulary->vid;
      if($semantic_process)
        $term->field_simple_process_status = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['semantic_process'])
          )
        );
      if($default)
        $term->field_is_default_term = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['default'])
          )
        );
      if($vat_rates)
        $term->field_vat_rate = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['vat_rates'])
          )
        );
      if($allow_grouping)
        $term->field_allow_grouping = array(
          LANGUAGE_NONE => array(
            0 => array('value' => $name['allow_grouping'])
          )
        );
        
      taxonomy_term_save($term);
    }
}

/**
 * This function will return a vocabulary object which matches the
 * given name. Will return null if no such vocabulary exists.
 *
 * @param String $vocabulary_name
 *   This is the name of the section which is required
 * @return Object
 *   This is the vocabulary object with the name
 *   or null if no such vocabulary exists
 */
function erpal_germany_get_vocabulary_by_name($vocabulary_name) {
  $vocabs = taxonomy_get_vocabularies(NULL);
  foreach ($vocabs as $vocab_object) { 
    if ($vocab_object->name == $vocabulary_name) {
      return $vocab_object;
    }
  }
  return NULL;
}


