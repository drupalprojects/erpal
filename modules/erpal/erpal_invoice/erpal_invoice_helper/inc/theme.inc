<?php

/**
* Alter fields and rows in the view table
*/
function erpal_invoice_helper_preprocess_views_calc_table(&$variables) {
  $view = $variables['view'];
  _erpal_invoice_helper_invoices_preprocess($view, $variables['field_classes'], $variables['row_classes']);
}


/**
* Function to preprocess task and project rows in views
*/
function _erpal_invoice_helper_invoices_preprocess(&$view, &$field_classes, &$row_classes) {

  if ($view->name != 'invoices')
    return;

  $status_field_name_views = 'field_field_payed_1';  //the "normal" field is a editable field, here we added a hidden field in the view to get the raw value
  
  $date_field_name_views = 'field_field_payment_date';
 
  $result = $view->result;
  foreach ($result as $delta=>$res_obj) {
    $paid = isset($res_obj->{$status_field_name_views}[0]['raw']['value']) ? $res_obj->{$status_field_name_views}[0]['raw']['value'] : false;    

    $date = isset($res_obj->{$date_field_name_views}[0]['raw']['value']) ? $res_obj->{$date_field_name_views}[0]['raw']['value'] : false;

    $date_unix = erpal_date_as_unix_timestamp($date);
    
    //date and state are set
    $status = ERPAL_STATUS_NONE;
    if (!$paid && time() > $date_unix && $date_unix) {
      $status = ERPAL_STATUS_ALERT;
    }
    
    //only the state is set, NO date end
    if ($paid) {
      $status = ERPAL_STATUS_COMPLETED;
    }

    $row_classes[$delta] = $status;  
  }

}

/**
* Alter the registry of invoice settings and respect the settings in the ERPAL admin area
*/
function _erpal_invoice_helper_alter_invoice_template_path(&$registry) {
  $registry['invoice_pdf_html']['template'] = _erpal_invoice_helper_get_invoice_template('invoice', TRUE);
  $registry['invoice_pdf_html']['theme path'] = dirname($registry['invoice_pdf_html']['template']);
  
  $registry['invoice_attachment_pdf_html']['template'] = _erpal_invoice_helper_get_invoice_template('attachment', TRUE);  
  $registry['invoice_attachment_pdf_html']['theme path'] = $registry['invoice_attachment_pdf_html']['template'];
}

