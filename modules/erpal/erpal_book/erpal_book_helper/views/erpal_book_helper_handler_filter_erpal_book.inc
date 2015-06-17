<?php

/**
 * Provides views filter criteria and contextual filter 
 * "Book page subpages: Choses page and subpages nids".
 * Filter gets nids of pages and it's subpages.
 *
 * Argument can work in pare with filter criteria "Book page subpages"(erpal_subpages)
 * If erpal_subpages value is "NO" returns single direct page nid
 * If erpal_subpages value is "YES" or doesn't exist returns direct page and 
 * subpages
 * 
 * Filter criteria "Book page subpages"(erpal_subpages) doesn't do any logic without
 * contestual filter "Book page subpages"
 */

/**
 * "Book page subpages" contextual filter(argument)
 * Get files of subpages of page
 */
class erpal_book_helper_handler_argument_erpal_book extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query($group_by = FALSE) {

    if (!$nid = $this->argument) // check arg
      return;

    if (!$node = node_load($nid)) // check in node exists
      return;

    // check in node is erpal_project or erpal_task
    if ($node->type != 'erpal_book' && $node->type != 'erpal_book_page')
      return;

    // prepare table
    $this->ensure_my_table();
    $alias = $this->table_alias;
    $this->query->distinct = 1; // distinct condition
    // Get filter criteria value
    // If erpal_subpages value is "NO" get single direct page id
    if (isset($this->view->filter['erpal_subpages']) && empty($this->view->filter['erpal_subpages']->value[0])) {
      $this->query->add_where($alias, "{$alias}.nid", $nid);
    }
    // If erpal_subpages value is "YES" or doesn't exist get direct page and 
    // subpages
    else {
      // Get files of task and it's subtasks tree
      if ($node->type == 'erpal_book_page') {
        $types = array('erpal_book_page');
        $child_nids = _erpal_basic_helper_get_all_child_nids_deep_search($nid, $types);
        
        //extract only the child nid, no parent nid needed
        $nids = array();
        foreach ($child_nids as $nid_arr) {
          $nids[] = $nid_arr['child'];
        }
        $child_nids = $nids;

        //add the current nid from argument
        $child_nids[] = $nid;
        
        $nids = array_unique($child_nids);
        $this->query->add_where($alias, "{$alias}.nid", $nids, "IN");
      } else

      // Get files of book and it's pages tree
      if ($node->type == 'erpal_book') {
        $join_book_ref = new views_join();
        $join_book_ref->construct('field_data_field_book_ref', $alias, 'nid', 'entity_id');
        $joined_table = $this->query->ensure_table('field_data_field_book_ref', $this->relationship, $join_book_ref);

        $expression = "{$alias}.nid = {$nid} OR {$joined_table}.field_book_ref_target_id = {$nid}";
  
        $this->query->add_where_expression(0, $expression);
      }
    }
  }

}

/**
 * "Show files of child pages" erpal_docs_helper filter
 * Get files of books, pages
 */
class erpal_book_helper_handler_filter_erpal_book extends views_handler_filter {

  /**
   * Clear query alter
   */
  function query() {
    
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['expose']['required']['#prefix'] = '<div class="element-invisible">';
    $form['expose']['required']['#value'] = TRUE;
    $form['expose']['required']['#suffix'] = '</div>';
  }

  /**
   * Subfiles checkbox. Provides show/hide choise
   */
  function value_form(&$form, &$form_state) {
    $options = array(
      '0' => 'No',
      '1' => 'Yes',
    );
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Show files of child pages'),
      '#default_value' => isset($this->value) ? $this->value : NULL,
      '#options' => $options,
    );
    return $form;
  }

}