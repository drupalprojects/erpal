<?php

/**
* callback for invoice to pdf link /invoice/%/pdf
*/
function _erpal_invoice_helper_invoice_pdf_menu_callback($invoice_nid) {
  return drupal_get_form('erpal_invoice_helper_invoice_pdf_form', $invoice_nid);
}

/**
* Form for choosing options to export an invoice as pdf
*/
function erpal_invoice_helper_invoice_pdf_form($form, $form_state, $invoice_nid) {
  $form = array();
  
  $documents = array(
    'invoice' => t('Invoice'),
    'attachment' => t('Detailed attachment'),
  );
  
  $form['documents'] = array(
    '#type' => 'checkboxes',
    '#options' => $documents,
    '#title' => t('Documents to export as PDF'),
  );
  
  $form['attach'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attach export to invoice'),
    '#default_value' => true,
    '#description' => t('If selected, the PDF export will be attached to the invoice.'),
  );
  
  $form['invoice_nid'] = array(
    '#type' => 'value',
    '#value' => $invoice_nid,
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create PDF'),
  );
  
  return $form;
}

/**
* Submit callback of invoice pdf create form
*/
function erpal_invoice_helper_invoice_pdf_form_validate($form, $form_state) {
  $values = $form_state['values'];
  $documents = $values['documents'];
  
  //at least one document must be selected
  $has_set = false;
  foreach ($documents as $type=>$value) {
    if ($value)
      $has_set = true;
  }
  
  if (!$has_set)
    form_set_error('documents', t('Please select at least on document type as content for your PDF.'));
}

/**
* Submit callback of invoice pdf create form
*/
function erpal_invoice_helper_invoice_pdf_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $documents = $values['documents'];
  $invoice_nid = $values['invoice_nid'];
  $attach = $values['attach'];

  _erpal_invoice_helper_invoice_pdf($invoice_nid, $documents, $attach);
  
}

/**
* creates a pdf from an invoice 
*/
function _erpal_invoice_helper_invoice_pdf($invoice_nid, $documents, $attach=false) {
     
  //check that the given invoice_nid is of type erpal_invoice
  $invoice = node_load($invoice_nid);

  if ($invoice->type != 'erpal_invoice') {
    drupal_set_message(t('Sorry, but this is not an invoice. PLease export only invoices as PDF.'), 'error');
  }
  
  $html = _erpal_invoice_helper_invoice_html($invoice, $documents);

  $destination = false;
  if ($attach) {
    //load the field to get the destination of the files
    $fileField = 'field_pdf_file';
    $fields = field_info_fields();
    $field_info = field_info_field($fileField);    
    $field_instance = field_info_instance('node', $fileField, 'erpal_invoice');
    $destination = $field_instance['settings']['file_directory'];
    
    //require file module
    $drupal_file_path_rel = variable_get('file_' . file_default_scheme() . '_path', conf_path() . '/files');
    $drupal_file_path_abs = drupal_realpath(file_default_scheme() . '://');
    $dest_dir_abs = $drupal_file_path_abs."/".$destination;
    $dest_dir_rel = $drupal_file_path_rel."/".$destination;
    $basename = "/invoice-".$invoice->field_invoice_number[LANGUAGE_NONE][0]['value'].".pdf";
    $filename_for_uri = $destination.$basename;
    $dest_filename = $dest_dir_rel.$basename;

    file_prepare_directory($dest_dir_abs, FILE_CREATE_DIRECTORY);

    //create the pdf and save it to the destination
    $dest_filename = _erpal_print_html_as_pdf($html, $dest_filename);
    
    //get the uri    
    $final_uri = file_build_uri($filename_for_uri);
    
    //save the file object!    
    global $user;
    //if there is already a file attached to this invoice node, use this one
    $fid = 0;

    if (isset($invoice->field_pdf_file[LANGUAGE_NONE])) {
      $fid = $invoice->field_pdf_file[LANGUAGE_NONE][0]['fid'];
      $file = file_load($fid);
    } else {
      //perhaps there is already a file with that full identical path?
      $file = _erpal_invoice_get_file_by_path($final_uri);
      if ($file)
        $fid = $file->fid;
    }

    if (!$fid) {
      //keep the file object and with it the file entry in the database, the file has then been overridden by pdf create function
      $file = new stdClass();
      $file->fid = NULL;
      $file->uri = $final_uri;
      $file->filename = drupal_basename($final_uri);
      $file->filemime = file_get_mimetype($file->uri);
      $file->uid      = $user->uid;
      $file->status   = FILE_STATUS_PERMANENT;
    }
 
    //allways save updated information
    if (is_object($file)) {
      $file->filesize = filesize($dest_filename);
      $file = file_save($file); 

    } else {
      drupal_set_message(t('The invoice document could not be created and attached to this invoice.', 'error'));
      drupal_goto('node/'.$invoice->nid);
    }

    //now link the file to the invoice node
    $invoice->field_pdf_file[LANGUAGE_NONE][0] = array(
      'fid' => $file->fid,
      'display' => 1,
      'description' => '',
    );

    node_save($invoice);

  } else {
    $download_filename = $invoice->title.time().".pdf";
    _erpal_print_html_as_pdf($html, false, $download_filename);
  }
    
  drupal_set_message(t('The invoice was created successfully and attached to this invoice.'));
  drupal_goto('node/'.$invoice->nid);
}

function _erpal_invoice_get_file_by_path($uri) {
  $fid = db_select('file_managed', 'f')
    ->condition('f.uri', $uri)
    ->fields('f', array('fid'))
    ->execute()
    ->fetchAssoc();

  if (!$fid)
    return false;
    
  return file_load($fid);
}

/**
* Render one invoice as HTML
*/
function _erpal_invoice_helper_invoice_html($invoice, $documents) {

  $attachment_html = '';
  $invoice_html = '';
  $output = '';
 
  _erpal_invoice_helper_replace_all_tokens($invoice, 'pdf');
 
  if (isset($documents['invoice']) && $documents['invoice'])
    $invoice_html = theme('invoice_pdf_html', array('invoice' => $invoice));
 
  if (isset($documents['attachment']) && $documents['attachment']) {
    $billables = _erpal_invoice_helper_invoice_attachment_billables($invoice);
    $attachment_html = theme('invoice_attachment_pdf_html', array('invoice' => $invoice, 'billables' => $billables));
  }
 
  if ($invoice_html) {
    if ($output)
      $output .= PDF_PAGE_BREAK;
    $output .= $invoice_html;    
  }
  
  if ($attachment_html) {
    if ($output)
      $output .= PDF_PAGE_BREAK;
    $output .= $attachment_html;    
  }
 
  return $output;
}

