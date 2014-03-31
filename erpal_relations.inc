<?php

function erpal_create_relations(){
    
  $relation_works_at = array(
    'relation_type' => 'works_at',
    'label' => 'Works at',
    'reverse_label' => 'employs',
    'directional' => TRUE,
    'transitive' => FALSE,
    'r_unique' => TRUE,
    'min_arity' => 2,
    'max_arity' => 2,
    'source_bundles' => array('node:erpal_contact'),
    'target_bundles' => array('node:erpal_contact'),  
  );
  relation_type_save(relation_type_create($relation_works_at));
} 
