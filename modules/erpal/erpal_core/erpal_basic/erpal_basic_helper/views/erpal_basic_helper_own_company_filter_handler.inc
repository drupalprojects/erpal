<?php

/**
 * @file
 * Definition of erpal_basic_helper_own_company_filter_handler.
 */

/**
 * Adds "Own Company" option to filter settings form and handles query alter.
 */
class erpal_basic_helper_own_company_filter_handler extends views_handler_filter_many_to_one {

  protected $_own_id = 'own';

  /**
   * Child classes should be used to override this function and set the
   * 'value options', unless 'options callback' is defined as a valid function
   * or static public method to generate these values.
   *
   * This can use a guard to be used to reduce database hits as much as
   * possible.
   *
   * @return
   *   Return the stored values in $this->value_options if someone expects it.
   */
  public function get_value_options() {
    $options = parent::get_value_options();

    $options[$this->_own_id] = t('- Own company -');

    $this->value_options = $options;

    return $this->value_options;
  }

  /**
   * Pre query alter. Rebplaces "Own Company" value with real value.
   * For not exposed filters.
   */
  function pre_query() {
    parent::pre_query();

    // Check if filter is exposed.
    if (empty($this->options['exposed'])) {
      // Check if "Own Company" was chosen.
      if (!empty($this->value[$this->_own_id])) {

        // Unset "Own Company" "own" value.
        unset($this->value[$this->_own_id]);

        // Get current "Own Company" id.
        $company_id = _erpal_basic_helper_get_own_company_nid(FALSE);

        // Set current "Own Company" value.
        $this->value[$company_id] = $company_id;
      }
    }
  }

  /**
   * Query alter. Rebplaces "Own Company" where condition with real value.
   * For exposed filters.
   */
  function query() {
    parent::query();

    // Check if filter is exposed.
    if (!empty($this->options['exposed'])) {
      // Get current "Own Company" id.
      $company_id = _erpal_basic_helper_get_own_company_nid(FALSE);

      // Add alias for where
      $this_where = &$this->view->query->where;
      if (empty($this_where)) {
        return;
      }

      // Search where condition with "own" value.
      foreach ($this_where as $where_key => $where) {
        if (empty($where)) {
          continue;
        }

        // Loop conditions
        foreach ($where['conditions'] as $condition_key => $condition) {
          // Check for empty value
          if (empty($condition) || empty($condition['value'])) {
            continue;
          }

          // If multi values
          if (!is_array($condition['value'])) {
            // Check if where condition has "own" value.
            if ($this->_own_id == $condition['value']) {

              // Rebplace "Own Company" where condition with real value.
              $this_where[$where_key]['conditions'][$condition_key]['value'] = $company_id;
            }
          }
          
          // If single value
          else {
            // Check if where condition has "own" value.
            if (in_array($this->_own_id, $condition['value'])) {
              // Loop values.
              foreach ($condition['value'] as $value_key => $value) {
                if (empty($value)) {
                  continue;
                }

                // Check if current where condition has "own" value.
                if ($value == $this->_own_id) {

                  // Rebplace "Own Company" where condition with real value.
                  $this_where[$where_key]['conditions'][$condition_key]['value'][$value_key] = $company_id;
                }
              }
            }
          }
        }
      }
    }
  }

}
