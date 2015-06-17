<?php

/**
 * callback for invoice to pdf link /invoice/%/pdf
 */
function _erpal_invoice_helper_invoice_pdf_menu_callback($invoice_nid) {
  return drupal_get_form('erpal_invoice_helper_invoice_pdf_form', $invoice_nid);
}

/**
 * Returns all available and selectable documents for invoice creation
 */
function _erpal_invoice_helper_invoice_document_options() {
  return array(
    'invoice' => t('Invoice'),
    'attachment' => t('Detailed attachment'),
  );
}

/**
 * Form for choosing options to export an invoice as pdf
 */
function erpal_invoice_helper_invoice_pdf_form($form, $form_state, $invoice_nid) {
  $form = array();

  $invoice_node = node_load($invoice_nid);

  $documents = _erpal_invoice_helper_invoice_document_options();

  $form['documents'] = array(
    '#type' => 'checkboxes',
    '#options' => $documents,
    '#title' => t('Documents to export as PDF'),
    '#default_value' => array('invoice', 'attachment'),
  );

  $form['attach'] = array(
    '#type' => 'checkbox',
    '#title' => t('Attach export to invoice'),
    '#default_value' => true,
    '#description' => t('If selected, the PDF export will be attached to the invoice.'),
  );

  $is_exported = _erpal_invoice_helper_invoice_is_exported($invoice_node);
  $form['mark_copied'] = array(
    '#type' => 'checkbox',
    '#title' => t('Mark as copy'),
    '#default_value' => $is_exported,
    '#description' => t('If selected, the invoice will be marked as a copy in the pdf.'),
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
  foreach ($documents as $type => $value) {
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
  $mark_copied = $values['mark_copied'];

  $invoice_node = node_load($invoice_nid);
  $invoice = _erpal_invoice_helper_invoice_pdf($invoice_node, $documents, $attach, $mark_copied);
  if ($invoice)
    drupal_set_message(t('The invoice was created successfully and attached to this invoice.'));
  else
    drupal_set_message(t('The invoice PDF could not be created.'), 'error');
  drupal_goto('node/' . $invoice->nid);
}

/**
 * Returns a erpal_file node if one exists at an invoice, otherwise false
 * @param $invoice_node the invoice node where to search the file at
 */
function _erpal_invoice_helper_invoice_file_node($invoice_node, $file_name = false) {
//  if (!isset($invoice_node->field_asset_files[LANGUAGE_NONE][0]['target_id']))
  if (empty($invoice_node->field_asset_files[LANGUAGE_NONE]) || count($invoice_node->field_asset_files[LANGUAGE_NONE]) <= 0)
    return false;

  $file_node=false;
  if (!$file_name) {
//  if we have not given a file name, return the first
    $file_nid = $invoice_node->field_asset_files[LANGUAGE_NONE][0]['target_id'];
    $file_node = node_load($file_nid);
  }
  else {
    //if filename given, return the proper file
    foreach ($invoice_node->field_asset_files[LANGUAGE_NONE] as $file) {
      $file_node_temp = node_load($file['target_id']);
      if($file_node_temp->title == $file_name){
        $file_node = $file_node_temp;
        break;
      }
    }
  }

  return $file_node;
}

/**
 * creates a pdf from an invoice 
 */
function _erpal_invoice_helper_invoice_pdf($invoice_nid, $documents, $attach = false, $mark_copied = false, $skip_save_invoice = false, $print_ci = true) {

  $can_print = erpal_print_prepared();
  if (!$can_print)
    return false;

  //check that the given invoice_nid is of type erpal_invoice
  if (is_object($invoice_nid))
    $invoice = $invoice_nid;
  else
    $invoice = node_load($invoice_nid);

  if ($invoice->type != 'erpal_invoice') {
    drupal_set_message(t('Sorry, but this is not an invoice. Please export only invoices as PDF.'), 'error');
  }

  $html = _erpal_invoice_helper_invoice_html($invoice, $documents, $mark_copied);

  //set invoice as exported!
  $invoice->field_invoice_exported[LANGUAGE_NONE][0]['value'] = 1;

  if (!$skip_save_invoice) {
    //save fields only without saving the node itself!
    field_attach_update('node', $invoice);
  }

  $destination = false;
  if ($attach) {

    //attach the pdf as erpal_file node
    $params = array(
      'title' => $invoice->title,
      'author' => _erpal_print_get_author($invoice),
      'print_ci' => $print_ci,
    );

    $doc_uri = _erpal_docs_folder_uri();
    $invoice_number = $invoice->field_invoice_number[LANGUAGE_NONE][0]['value'];
    $ci_string = (!$print_ci) ? t('-no_ci') : '';
    $basename = _erpal_docs_make_filename(t('Invoice') . "-" . $invoice_number . $ci_string, 'pdf');

    $doc_file = _erpal_print_html_as_pdf($html, $doc_uri, $basename, $params);
    $file_node = _erpal_invoice_helper_invoice_file_node($invoice,$basename);

    _erpal_docs_attach_file($invoice, $doc_file, $file_node, $skip_save_invoice);
  }
  else {

    //send file as Download
    $download_filename = $invoice->title . "_" . time() . ".pdf";
    $params = array(
      'title' => $invoice->title,
      'author' => _erpal_print_get_author($invoice),
    );
    _erpal_print_html_as_pdf($html, false, $download_filename, $params);
  }

  return $invoice;
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
 * 
 */
function _erpal_invoice_helper_invoice_html($invoice, $documents, $mark_copied = false) {

  $attachment_html = '';
  $invoice_html = '';
  $output = '';

  $notes = isset($invoice->field_note[LANGUAGE_NONE][0]['value']) ? $invoice->field_note[LANGUAGE_NONE][0]['value'] : '';  //we save the notes. Otherwise if tokens are replaced, they are also replaced on the invoice object and will be saved. We dont want that because if some variables change in the invoice, the tokeniced values won't change!
  _erpal_invoice_helper_replace_all_tokens($invoice, 'pdf');


  $params = array(
    'mark_copied' => $mark_copied,
  );

  if (isset($documents['invoice']) && $documents['invoice'])
    $invoice_html = theme('invoice_pdf_html', array('invoice' => $invoice, 'params' => $params));

  if (isset($documents['attachment']) && $documents['attachment']) {
    $billables = _erpal_invoice_helper_invoice_attachment_billables($invoice);
    $has_reduced_billables = _erpal_invoice_helper_billables_have_reduced_billables($billables);
    if ($has_reduced_billables)
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

  //finally set the invoice notes the the version without replaced tokens, so if values change, the tokenized values change again!
  if ($notes)
    $invoice->field_note[LANGUAGE_NONE][0]['value'] = $notes;

  return $output;
}

/**
 * Load all reduced billables
 */
function _erpal_invoice_helper_invoice_attachment_load_reduced_billables($billables) {
  foreach ($billables as $billable) {
    foreach ($billable->reduced_billables as $reduced_billable) {
      $billable->reduced_billables[$reduced_billable->billable_id] = billable_load($reduced_billable->billable_id);
    }
  }
  return $billables;
}

/**
 * Check if billables have reduced billables
 */
function _erpal_invoice_helper_billables_have_reduced_billables($billables) {
  foreach ($billables as $billable) {
    if (count($billable->reduced_billables) > 0) {
      return true;
    }
  }

  return false;
}
