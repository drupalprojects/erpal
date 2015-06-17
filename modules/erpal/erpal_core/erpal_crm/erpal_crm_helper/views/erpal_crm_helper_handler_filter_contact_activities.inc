<?php

/**
 * Provides views contextual filter 
 * "Contact activities: Choses activities nids".
 *
 * The contextual filter selects nids of nodes where the argument nid is either 
 * referenced by field_customer_ref or field_contacts_ref
 *
 */

/**
 * "Contact activities" contextual filter(argument)
 */
class erpal_crm_helper_handler_argument_contact_activities extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query($group_by = FALSE) {

    if (!$nid = $this->argument) // check arg
      return;

    if (!$node = node_load($nid)) // check in node exists
      return;

    // check in node is erpal_project or erpal_task
    if ($node->type != 'erpal_contact')
      return;

    // prepare table
    $this->ensure_my_table();
    $alias = $this->table_alias;
    $this->query->distinct = 1; // distinct condition
          
    // Get activities of contact
    $join_contacts_ref = new views_join();
    $join_contacts_ref->construct('field_data_field_contacts_ref', $alias, 'nid', 'entity_id');
    $joined_contacts_table = $this->query->ensure_table('field_data_field_contacts_ref', $this->relationship, $join_contacts_ref);    
    
    $join_customer_ref = new views_join();
    $join_customer_ref->construct('field_data_field_customer_ref', $alias, 'nid', 'entity_id');
    $joined_customer_table = $this->query->ensure_table('field_data_field_customer_ref', $this->relationship, $join_customer_ref);    
    
    $expression = "{$joined_customer_table}.field_customer_ref_target_id = {$nid} OR {$joined_contacts_table}.field_contacts_ref_target_id = {$nid}";
    $this->query->add_where_expression(0, $expression);
       
  }

}