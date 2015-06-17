<?php

/**
* @file contains a class to calculate the forecast
*/

class ErpalCrmReportsForcastPlan {
  
  /**
  * Method created orcast calculation for all customer forecast nodes that exist.
  */
  public static function create() {
    $customer_forecast_nids = _erpal_crm_reports_get_customer_forecasts();
    
    $unplanned_customer_node = _erpal_crm_reports_get_unplanned_contact_node();
    $unplanned_customer_nid = $unplanned_customer_node->nid;
    
    $years_to_check = 2; //may be make this dynamic but as it is a forecast we should not look back to many years but foreward!
    
    //get current sales volume
    //get the years
    $years = array();
    for ($i = 0; $i<$years_to_check; $i++) {
      $years[] = date('Y') - $i;
    }
    $planned_contact_nids = _erpal_crm_reports_get_planned_sales_contacts_by_year($years);
    
    $sales_volumes = _erpal_crm_reports_get_sales_volume($years_to_check, $planned_contact_nids);    
    if (!isset($sales_volumes['customers'])) {
      $sales_volumes['customers'] = array();
    }
    
    $details = $sales_volumes['details'];

    $service_categories = $sales_volumes['service_categories'];
    //get forecast volume
    $forecast_volumes = _erpal_crm_reports_get_sales_forecast($years_to_check);    
    $forecast_categories = $forecast_volumes['categories'];    
    
    $planned_per_year = array(); //this is the array where we sum up all revenue that was booked to forecasts. So we can calculate the unplanned revenue
    $unplanned_forcast_nid = FALSE;
    foreach ($customer_forecast_nids as $forecast_nid) {
      $forecast_node = node_load($forecast_nid);
      $customer_nid = $forecast_node->field_contact_ref[LANGUAGE_NONE][0]['target_id'];
      
      //prepare data of unplanned sales volume to add it this sales forecast
     /* if ($customer_nid == $unplanned_customer_nid && $unplanned_customer_nid) {
        //extend sales forecast to separate sales volume that has not been planned
        die(print_r($sales_volumes));
      }
    */
    
      $customer_sales = $sales_volumes['customers'];
      $customer_forecast = $forecast_volumes['customers'];
      $sales_data = !empty($customer_sales[$customer_nid]) ? $customer_sales[$customer_nid] : array();
      $forecast_data = !empty($customer_forecast[$customer_nid]) ? $customer_forecast[$customer_nid] : array();

      $sales_details = !empty($sales_data['details']) ? $sales_data['details'] : array();
      $forecast_details = !empty($forecast_data['details']) ? $forecast_data['details'] : array();
      //update the sales forecast field collection with each category as well as the years total!
      $forcast_elements = !empty($forecast_node->field_forecast_elements[LANGUAGE_NONE]) ? $forecast_node->field_forecast_elements[LANGUAGE_NONE] : array();

      $cat_strings_for_details = array();
      $cat_strings_for_details_forecast = array();
      foreach ($forcast_elements as $delta => $forecast_element) {
        $element_collection = entity_load('field_collection_item', array($forecast_element['value']));
        $element_collection = $element_collection[$forecast_element['value']];
        $element_collection_w = entity_metadata_wrapper('field_collection_item', $element_collection); 

        //get the year of the forecast, this is the only unit, no range with dates and other stuff
        $forecast_year = date('Y', $element_collection->field_forecast_date[LANGUAGE_NONE][0]['value']); 
        
        //calculate the total this year
        $total_sales_this_year = 0;
        $total_forecast_this_year = 0;
        $total_expected_this_year = 0;
        $total_dynamic_this_year = 0;
        $details_by_year_sales = !empty($sales_details[$forecast_year]) ? $sales_details[$forecast_year] : array();
        $details_by_year_forecast = !empty($forecast_details[$forecast_year]) ? $forecast_details[$forecast_year] : array();

        //calculate the sales and forecast items for every service category
        $vocabulary = taxonomy_vocabulary_machine_name_load('service_category_terms');
        $service_category_terms = taxonomy_get_tree($vocabulary->vid);
        $service_category_tids = array(0); //add "no service category" category also
        foreach ($service_category_terms as $service_category_term) {
          $service_category_tids[] = $service_category_term->tid;
        }
        foreach ($service_category_tids as $category_tid) {
          $cat_string = self::getCategoryStringByServiceCategory($service_categories, $customer_nid, $category_tid);                  
          $cat_strings_for_details[$cat_string] = $cat_string;
          
          $cat_string_forecast = self::getCategoryStringByServiceCategory($forecast_categories, $customer_nid, $category_tid);
          $cat_strings_for_details_forecast[$cat_string_forecast] = $cat_string_forecast;
          
          $category_sales_volume = !empty($details_by_year_sales[$category_tid]) ? $details_by_year_sales[$category_tid] : 0;
          $total_sales_this_year += $category_sales_volume;

          //check if there is also a forcast volume for this category and year
          $category_forecast_volume = !empty($details_by_year_forecast[$category_tid]) ? $details_by_year_forecast[$category_tid] : 0;
     
          $total_forecast_this_year += $category_forecast_volume;
          
          //update the volumes for each category
          $category_volumes = !empty($element_collection->field_forecast_volumes[LANGUAGE_NONE]) ? $element_collection->field_forecast_volumes[LANGUAGE_NONE] : array();
          foreach ($category_volumes as $delta => $forecast_category_volume) {
            $volume_collection = entity_load('field_collection_item', array($forecast_category_volume['value']));
            $volume_collection = $volume_collection[$forecast_category_volume['value']];

            $volume_category_tid = !empty($volume_collection->field_service_category_term[LANGUAGE_NONE][0]) ? $volume_collection->field_service_category_term[LANGUAGE_NONE][0]['tid'] : false;

            if ($volume_category_tid && $volume_category_tid == $category_tid) {
              //update the current sales volume by this service category
              $volume_collection->field_current_volume[LANGUAGE_NONE][0]['value'] = round($category_sales_volume, 2);  //this was already billed!           
              
              //update the current forcast values
              $volume_collection->field_forecast_calculated[LANGUAGE_NONE][0]['value'] = round($category_forecast_volume, 2);
              $volume_collection->skip_calculate_volumes = true; //not to recalculate the user input estimations again
              $volume_collection->save(true);
              
              //add expected and dynamic volumes to total values for expected and dynamic volume in the given year.
              $total_expected_this_year += !empty($volume_collection->field_forecast_estimated[LANGUAGE_NONE][0]['value']) ? $volume_collection->field_forecast_estimated[LANGUAGE_NONE][0]['value'] : 0;
              $total_dynamic_this_year += !empty($volume_collection->field_forecast_dynamic[LANGUAGE_NONE][0]['value']) ? $volume_collection->field_forecast_dynamic[LANGUAGE_NONE][0]['value'] : 0;
            }   
          }
        }

        $element_collection->field_current_volume[LANGUAGE_NONE][0]['value'] = $total_sales_this_year; //the total sales volume for this year!
        $element_collection->field_forecast_calculated[LANGUAGE_NONE][0]['value'] = $total_forecast_this_year; //the total forecast volume for this year!
        $element_collection->field_expected_volume[LANGUAGE_NONE][0]['value'] = round($total_expected_this_year, 2);  //this is the sum of all estimated volumes!
        $element_collection->field_dynamic_volume[LANGUAGE_NONE][0]['value'] = round($total_dynamic_this_year, 2);  //this is the sum of all dynamic volumes!   

        if (empty($planned_per_year[$forecast_year]))
          $planned_per_year[$forecast_year] = 0;
          
        $planned_per_year[$forecast_year] += $total_sales_this_year;
        
        //trigger a rules event to notify the user about the values        
        if (module_exists('rules')) {    
          $total_dynamic_this_year = $total_dynamic_this_year ? $total_dynamic_this_year : $total_expected_this_year;
          if ($total_dynamic_this_year)            
            $sales_percent_dynamic = round(($total_sales_this_year / $total_dynamic_this_year) * 100, 2);
          else
            $sales_percent_dynamic = 0;
          
          if ($total_expected_this_year)
            $sales_percent = round(($total_sales_this_year / $total_expected_this_year) * 100, 2);
          else
            $sales_percent = 0;
   
          rules_invoke_event('sales_plan_recalculation', $forecast_node, $forecast_year, $total_expected_this_year, $total_dynamic_this_year, $total_sales_this_year, $sales_percent, $sales_percent_dynamic);
        }
 
        //add the report details for trill down
        //get the details for all cat strings
        $final_details = array();
        foreach ($cat_strings_for_details as $cat_string) {
          if (!empty($details[$cat_string][$forecast_year])) {
            $new_values = $details[$cat_string][$forecast_year];
            foreach ($new_values as $new_val) {
              $final_details[] = $new_val;
            }            
          }
        }
        
        foreach ($cat_strings_for_details_forecast as $cat_string) {
          if (!empty($forecast_volumes['details'][$cat_string][$forecast_year])) {
            $new_values = $forecast_volumes['details'][$cat_string][$forecast_year];
            foreach ($new_values as $new_val) {
              $final_details[] = $new_val;
            }            
          }
        }

        $details_string = json_encode(array($final_details));
        $element_collection_w->field_report_details->set($details_string);
        
        $element_collection->save(true); //save without host entity
      }
      
    }
  }
  
  /**
  * Return a category string for the service category
  */
  public static function getCategoryStringByServiceCategory($category_strings, $customer_nid, $service_category_id) {
    
    foreach ($category_strings as $cat_string => $cat_arr) {      
      foreach ($cat_arr as $a_cat_arr) {
        $cat_id = isset($a_cat_arr['id']) ? $a_cat_arr['id'] : FALSE;
        if (!empty($a_cat_arr['customer_nid'])) {
          if ($cat_id == $service_category_id && $a_cat_arr['customer_nid'] == $customer_nid) {                   
            return $cat_string;
          }
        }
      }
    }
    
    return false;
  }
}