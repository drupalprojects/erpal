<?php

/**
* @file contains a class to calculate the expense plan
*/

class ErpalCrmReportsExpensePlan {
  
  /**
  * Method created forecast calculation for all expenses
  */
  public static function create() {
    $expense_forecast_nids = _erpal_crm_reports_get_expense_forecasts();
    
    $years_to_check = 2; //may be make this dynamic but as it is a forecast we should not look back to many years but foreward!
    
    //get current expenses (only billables but not the payments).
    $expenses = _erpal_crm_reports_get_expenses($years_to_check);

    foreach ($expense_forecast_nids as $forecast_nid) {
      $forecast_node = node_load($forecast_nid);
      $expense_categories = $expenses['expense_categories'];
      //get the expense category of this forecast
      $forecast_node_w = entity_metadata_wrapper('node', $forecast_node);
      $expense_category_term = $forecast_node_w->field_expense_category->value();

      //update the expense forecast field collection with each expense
      $forcast_elements = !empty($forecast_node->field_expense_elements[LANGUAGE_NONE]) ? $forecast_node->field_expense_elements[LANGUAGE_NONE] : array();

      foreach ($forcast_elements as $delta => $forecast_element) {
        $element_collection = entity_load('field_collection_item', array($forecast_element['value']));
        $element_collection = $element_collection[$forecast_element['value']];
        $element_collection_w = entity_metadata_wrapper('field_collection_item', $element_collection); 

        //get the year of the forecast, this is the only unit, no range with dates and other stuff
        $forecast_year = date('Y', $element_collection->field_forecast_date[LANGUAGE_NONE][0]['value']); 
        
        //update the current expenses for this expense category in the given year.
        $total_expense_this_year = !empty($expense_categories[$expense_category_term->tid]['details'][$forecast_year]) ? $expense_categories[$expense_category_term->tid]['details'][$forecast_year] : 0;
          
        $cat_string = $expense_categories[$expense_category_term->tid]['cat_string'];
        
        //trigger a rules event to notify the user about the values        
        if (module_exists('rules')) {    
          $planned_expense_value = $element_collection_w->field_forecast_estimated->value();
          $dynamic_planned_expense_value = $element_collection_w->field_forecast_dynamic->value();
          
          if ($dynamic_planned_expense_value)
            $expense_percent = round(($total_expense_this_year / $dynamic_planned_expense_value) * 100, 2);
          else
            $expense_percent = 0;
            
          if ($planned_expense_value)  
            $expense_percent_dynamic = round(($total_expense_this_year / $planned_expense_value) * 100, 2);
          else
            $expense_percent_dynamic = 0;
            
          rules_invoke_event('expense_plan_recalculation', $forecast_node, $forecast_year, $planned_expense_value, $dynamic_planned_expense_value, $total_expense_this_year, $expense_percent, $expense_percent_dynamic);
        }
        
        $element_collection_w->field_current_volume->set($total_expense_this_year);
        
        //add the report details for trill down
        $details = $expenses['details'];

        $details_string = json_encode($details[$cat_string][$forecast_year]);
        
        $element_collection_w->field_report_details->set($details_string);
        
        $element_collection_w->save(TRUE); //skip saving the host entity.
      }
    }
  }
}