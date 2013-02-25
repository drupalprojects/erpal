<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Invoice PDF create link'),
  'description' => t('Shows a link to recreate the invoice pdf'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('ERPAL invoices'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_invoice_helper_invoice_recreate_link_content_type_render($subtype, $conf, $args, $context) {

  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  $pdf_link = l('Recreate PDF', 'invoice/'.$node->nid.'/pdf');

  $module = 'erpal_invoice_helper';
  $block = new stdClass();
  $block->module = $module;
  $block->title = '';
  $block->content = '<div class="invoice_recreate_pdf">'.$pdf_link.'</div>';
  return $block;
}

