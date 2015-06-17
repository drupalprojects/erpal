<?php
/**
 * Attachment-Template
 * 
 * availiable variables:
 * $invoice
 * $billables
 * 
 *  
 */
?>
<link rel="stylesheet" type="text/css" href="<?php print drupal_get_path('module', 'erpal_invoice_helper'); ?>/template/common.css">
<br>&nbsp;<br>&nbsp;
<h1><?php print t('Invoice details'); ?></h1>
<br>&nbsp;<br>&nbsp;<br>
<?php



$billables = _erpal_invoice_helper_invoice_attachment_load_reduced_billables($billables);
foreach ($billables as $billable) {
  $billable_vat_rate = _erpal_invoice_helper_format_vat_rate_display($billable->vat_rate);
  if (count($billable->reduced_billables) == 0) {
    continue;
  }
  $data['header'] = array(
      'executed' => array('data' => t("Executed"), "class" => "left executed"),
      'amount' => array('data' => t("Quantity"), "class" => "left amount"),
      'description' => array('data' => t("Billable description"), "class" => "left description"),
      'price' => array('data' => t("Price p.P. (%curr)", array('%curr' => $billable->currency)), "class" => "right price"),
      'total' => array('data' => t("Total (%curr)", array('%curr' => $billable->currency)), "class" => "right total"),
  );


// Billables-Table
  $reduced_billables = &$billable->reduced_billables;
  if (is_array($reduced_billables)) {

    $rows = array();
    foreach ($reduced_billables as $reduced_billable) {      

      $row = array();

      // Executed
      $row[] = array('data' => erpal_date_formatted($reduced_billable->date_delivery),
          "class" => "left");
      // Amount
      $row[] = array('data' => $reduced_billable->quantity,
          "class" => "left");
//       // Article number
//        $row[] = array('data' => $billable['article_nr'],
//                      "class" => "left");
      // Description
      $row[] = array('data' => $reduced_billable->subject,
          "class" => "left");
      // price
      $row[] = array('data' => number_format($reduced_billable->single_price, 2, ',', '.'),
          "class" => "right");
      // total
      $row[] = array('data' => number_format($reduced_billable->total_price_no_vat, 2, ',', '.'),
          "class" => "right");

      // Add the Row to the array:
      $rows[] = $row;
    }


    // Sum without tax
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("Total without tax"), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => number_format($billable->total_price_no_vat, 2, ',', '.') .' '. $billable->currency, 'class' => 'right'),
        ),
        'class' => array('sumrow', 'bordertop'),
    );
    $totalvatstring = "";
    // tax
    $vatvalues = array(
        "!vat_value" => number_format($billable->total_vat, 2, ',', '.'),
        "!currency" => $billable->currency
    );
    $totalvatstring .= t("!vat_value !currency", $vatvalues) . " <br />";
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("!vat_rate", array("!vat_rate" => $billable_vat_rate)), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => $totalvatstring, 'class' => 'right'),
        ),
        'class' => array('sumrow'),
    );

    // Sum brutto
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("Total with tax"), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => number_format($billable->total_price, 2, ',', '.') .' '. $billable->currency, 'class' => 'right'),
        ),
        'class' => array('sumrow'),
    );

    $data['rows'] = $rows;

    $data['attributes']['class'][] = 'rechnungstabelle';

    //print( theme('table', array(), $rows) );
    $table = theme("table", $data);
    print '<h2>' . $billable->subject . '</h2>';
    print $table;
  }
}
?>