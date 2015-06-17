<?php
/**
 * This file includes all the resource functions for retrieving,
 * creating, updating and deleting relations between contacts.
 * 
 * @package     erpal_basic\erpal_basic_helper\erpal_basic_service
 * @file        contact_relation.inc
 * @author      Marc Sven Kleinböhl
 * @copyright   Bright Solutions GmbH 2013(c)
 */

/**
 * Retrieves all relations or a few of filtered relations.
 * 
 * @param   integer $start          (OPTIONAL) Defines the start offset.
 * @param   integer $count          (OPTIONAL) Defines the amount of relations to load.
 * @param   integer $changed_since  (OPTIONAL) Defines the timestamp of minimum last update.
 * @param   boolean $details        (OPTIONAL) TRUE if the output should be more detailed.
 * @return  array                   The found relations.
 * 
 * Example result:
 * [
 * {
 *  "changed"            : 1374504633,
 *  "created"            : 1374219403,
 *  "revision_id"        : 123,
 *  "url"                : "http://.../contact-relation/123",
 *  "contact"            : "http://.../contact/543",
 *  "works_at"           : "http://.../contact/321",
 *  "tag"                : "QO",
 *  "start_date"         : 1374219621,
 *  "end_date"           : 1374801154
 * },
 * {
 *  "changed"            : 1374504633,
 *  "created"            : 1374219403,
 *  "revision_id"        : 123,
 *  "url"                : "http://.../contact-relation/321",
 *  "contact"            : "http://.../contact/654",
 *  "works_at"           : "http://.../contact/321",
 *  "tag"                : "Chief",
 *  "start_date"         : 1374219621,
 *  "end_date"           : 1374801154
 * },
 * ]
 * 
 */ 
function _erpal_basic_service_contact_relation_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = TRUE) {
  
  $query = new RelationQuery();
  $query->propertyCondition('relation_type', 'works_at');
  $query->propertyCondition('changed', (int)$changed_since, '>');
  $query->range((int)$start, (int)$count);
  $results = $query->execute();
  
  $relations = array();
  $endpoints = erpal_basic_service_default_services_endpoint();  
  $endpoint  = array_shift($endpoints);
    
  foreach ($results as $rid=>$result) {
    
    if ($details) {
      $relations[] = _erpal_basic_service_contact_relation_retrieve($rid);
    }else{
      $relations[] = (object)array(
        'revision_id' => $result->vid,
        'url'         => url(
          $endpoint->path . '/contact-relation/' . $rid, 
          array('absolute'=>TRUE)
        )
      );
    }
  }
 

  return $relations;
}
 
/**
 * Retrieves a specific relation.
 * 
 * @param   integer $rid      The database ID of a single relation.
 * @return  object            A data object on success.
 * 
 * Example result:
 * {
 *  "changed"            : 1374504633,
 *  "created"            : 1374219403,
 *  "revision_id"        : 123,
 *  "url"                : "http://.../contact-relation/123",
 *  "contact"            : "http://.../contact/543",
 *  "works_at"           : "http://.../contact/321",
 *  "tag"                : "QO",
 *  "start_date"         : 1374219621,
 *  "end_date"           : 1374801154
 * }
 */
function _erpal_basic_service_contact_relation_retrieve($rid) {

  $relation = relation_load($rid);
  if ($relation === FALSE) {
    services_error(
      'Invalid relation ID.',
      404
    );
    return;
  }
  
  $endpoints  = erpal_basic_service_default_services_endpoint();  
  $endpoint   = array_shift($endpoints);
  $tag        = '';
  
  if (isset($relation->field_work_at_rel_tags[LANGUAGE_NONE])) {
    
    $term = taxonomy_term_load(
      $relation->field_work_at_rel_tags[LANGUAGE_NONE][0]['tid']
    );

    if ($term !== FALSE) {
      $tag = $term->name;
    }
  }
 
  if (isset($relation->field_date)) {
    $start_date = (int)strtotime ($relation->field_date[LANGUAGE_NONE][0]['value']);
    $end_date   = isset($relation->field_date[LANGUAGE_NONE][0]['value2']) ?
                  (int)strtotime ($relation->field_date[LANGUAGE_NONE][0]['value2']) :
                  NULL;
  }else{
    $start_date = NULL;
    $end_date   = NULL;
  }
 
  $relation_endpoints = $relation->endpoints[LANGUAGE_NONE];
  
  $output = (object)array(
    'changed'             => (int)$relation->changed,
    'created'             => (int)$relation->created,
    'revision_id'         => (int)$relation->vid,
    'url'                 => url(
      $endpoint->path . '/contact-relation/' . $rid, 
      array('absolute'=>TRUE)
    ),
    'contact'             => url(
      $endpoint->path . '/contact/' . $relation_endpoints[0]['entity_id'] , 
      array('absolute'=>TRUE)
    ),
    'works_at'            => url(
      $endpoint->path . '/contact/' . $relation_endpoints[1]['entity_id'] , 
      array('absolute'=>TRUE)
    ),
    'tag'                 => $tag,
  );
  
  if ($start_date != 0) {
    $output->start_date = $start_date;
    $output->end_date   = $end_date;
  }
  
  return $output;
}

/**
 * Creates a relation between to contacts.
 * 
 * @param   array $data     An array of relation data.
 *                          {
 *                            "contact": "http://.../contact/60",
 *                            "works_at": "http://../contact/57",
 *                            "tag": "tag1",
 *                            "start_date": 1374752734,
 *                            "end_date": 1374752735
 *                          }
 * @return  array           An array which contains an URL to the relation 
 *                          resource object on success.
 *                          {
 *                            "url": "http://.../content-relation/100"
 *                          }
 * @throws                  HTTP status codes on errors:
 *                          - 400
 *                          - 409
 *                          - 500
 */
function _erpal_basic_service_contact_relation_create($data) {
  
  $data = (object)$data;
  
  if (empty($data)) {
    services_error(
      'Missing data.',
      400
    );
  }
 
  if (! (isset($data->contact) && isset($data->works_at))) {
    services_error(
      'Missing data field(s).',
      400
    );
  }

  $contact_rid  = _erpal_basic_service_contact_relation_get_id_from_url($data->contact);
  $works_at_rid = _erpal_basic_service_contact_relation_get_id_from_url($data->works_at);
  
  if ($contact_rid ==0) {
    services_error(
      'Unknown contact.',
      400
    );
    return;
  }
  
  if ($works_at_rid ==0) {
    services_error(
      'Unknown "works at" contact.',
      400
    );
    return;
  }
  
  $relation_endpoints = array(
    array('entity_type'=>'node', 'entity_id'=>$contact_rid),
    array('entity_type'=>'node', 'entity_id'=>$works_at_rid),
  );

  if (relation_relation_exists($relation_endpoints , 'works_at')) {
    services_error(
      'Relation already exists.',
      409
    );
    return;
  }

  $relation = relation_create(
    'works_at', 
    $relation_endpoints
  );

  $tags = array();
  
  if (isset ($data->tag) && ! empty($data->tag)) {
 
    $tags[0] = array(
      'tid'=>_erpal_basic_service_contact_relation_retrieve_company_relation_tag_term($data->tag)->tid
    );
  } 

  if (! isset($data->end_date)) {
    $data->end_date = NULL;
  }
 
  $relation->field_work_at_rel_tags = ! empty($tags) ? array(LANGUAGE_NONE=>$tags) : array();
  
  if (isset($data->start_date)) {
    $relation->field_date = array(
      LANGUAGE_NONE=>array(
        array(
          'value'         => date('Y-m-d H:i:s', $data->start_date),
          'value2'        => date('Y-m-d H:i:s', $data->end_date),
          'timezone'      => $GLOBALS['user']->timezone,
          'timezone_db'   => date_default_timezone(FALSE)
        )
      )
    );
  }
 
  if (relation_save($relation) === FALSE) {
    services_error(
      'Couldn\'t save relation.',
      500
    );
    return;
  }
 
  $endpoints  = erpal_basic_service_default_services_endpoint();  
  $endpoint   = array_shift($endpoints);
  
  return array(
    'url' => url(
      $endpoint->path . '/contact-relation/' . $relation->rid, 
      array('absolute'=>TRUE)
    )
  );
}

/**
 * Updates a relation with new data.
 * 
 * @param  integer  $relation_id  The database ID of the related relation.
 * @param  array    $data         The data object.
 * @return array              
 */
function _erpal_basic_service_contact_relation_update($relation_id, $data) {
  
  $data = (object)$data;
  
  if (empty($data)) {
    services_error(
      'Missing data.',
      400
    );
    return;
  }
  
  if (intval($relation_id) === 0) {
    services_error(
      'Missing relation ID.',
      400
    );
    return;
  }
   
  // Load the relation object from dataset.
  $relation = relation_load($relation_id);
  if ($relation === FALSE) {
    services_error(
      'Couldn\'t load relation object from database.',
      500
    );
    return;
  }
  
  // Relation terms. Update only if set.
  if (isset ($data->tag) && ! empty($data->tag)) {
    $tags    = array();
    $tags[0] = array(
      'tid'=>_erpal_basic_service_contact_relation_retrieve_company_relation_tag_term($data->tag)->tid
    );
    
    $relation->field_work_at_rel_tags = array(LANGUAGE_NONE=>$tags);
  } 
 
  // Relation start and end time. Update only if set.
  if (isset($data->start_date)) {
    
  
    if (! isset($data->end_date)) {
      $data->end_date = NULL;
    }
      
    $relation->field_date = array(
      LANGUAGE_NONE=>array(
        array(
          'value'         => date('Y-m-d H:i:s', $data->start_date),
          'value2'        => date('Y-m-d H:i:s', $data->end_date),
          'timezone'      => $GLOBALS['user']->timezone,
          'timezone_db'   => date_default_timezone(FALSE)
        )
      )
    ); 
  }

  if (relation_save($relation) === FALSE) {
    services_error(
      'Couldn\'t save relation.',
      500
    );
    return;
  }
 
  $endpoints  = erpal_basic_service_default_services_endpoint();  
  $endpoint   = array_shift($endpoints);
  
  return array(
    'url' => url(
      $endpoint->path . '/contact-relation/' . $relation_id, 
      array('absolute'=>TRUE)
    )
  );
}

/**
 * Removes a single relation.
 * 
 * @param integer       The database ID of a relation.
 */
function _erpal_basic_service_contact_relation_delete($relation_id) {

  relation_delete((int)$relation_id);
  
  return;
}

/**
 * Retrieves a relation ID from a contact-relation URL.
 * 
 * @param   string    $url        The URL.
 * @return  integer               The relation ID on success. Otherwise 0. 
 */
function _erpal_basic_service_contact_relation_get_id_from_url($url) {

  $matches = array();
  if (preg_match('/\/(\d+)$/', $url, $matches) < 1) {
    return 0;
  }
  
  return $matches[1];
}

/**
 * Checks whether the current user is permitted to create, load, update or delete
 * a contact relation.
 * 
 * @param   string $access_type     The name of the access type.
 * @return  boolean                 TRUE on success.
 */
function _erpal_basic_service_contact_relation_access($access_type) {
 
  return node_access($access_type, 'erpal_contact');
}

/**
 * Creates or retrieves a term object for a specific tag.
 * If the related term doesn't exist, it will be created.
 * 
 * @param   string $tag   The tag name.
 * @return  Term          The term object.
 */
function _erpal_basic_service_contact_relation_retrieve_company_relation_tag_term($tag) {
  
  static $terms = array();
  static $vocabulary_name = FALSE;
  
  if ($vocabulary_name === FALSE) {
    
    $field_info      = field_info_field('field_work_at_rel_tags');
    $vocabulary_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
  }
  
  if (isset($terms[$tag])) {
    return $terms[$tag];
  }

  $term = taxonomy_get_term_by_name($tag);
  if (! empty($term)) {
    $term = array_shift($term);
 
    if ($term->vocabulary_machine_name == $vocabulary_name) {
      
      $terms[$tag] = $term;
      return $term;
    }
  }
 
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
  $term       = (object)array(
    'vid'                     => $vocabulary->vid,
    'name'                    => $tag,
    'vocabulary_machine_name' => $vocabulary_name
  );
  taxonomy_term_save($term);

  return $term;
}
