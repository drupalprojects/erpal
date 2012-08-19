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
<h1>Rechnungsanhang</h1>
<br>&nbsp;<br>&nbsp;<br>
<?php



$billables = _erpal_invoice_helper_invoice_attachment_load_reduced_billables($billables);
foreach ($billables as $billable) {
  if (count($billable->reduced_billables) == 0) {
    continue;
  }
  $data['header'] = array(
      'executed' => array('data' => t("Executed"), "class" => "left executed"),
      'amount' => array('data' => t("Quantity"), "class" => "left amount"),
      'description' => array('data' => t("Description"), "class" => "left description"),
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
      $row[] = array('data' => date(_erpal_basic_helper_date_format_date_only(), $reduced_billable->date_delivery),
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
      $row[] = array('data' => $reduced_billable->single_price,
          "class" => "right");
      // total
      $row[] = array('data' => $reduced_billable->total_price,
          "class" => "right");

      // Add the Row to the array:
      $rows[] = $row;
    }


    // Sum netto
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("Sum excl. VAT"), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => $billable->total_price_no_vat .' '. $billable->currency, 'class' => 'right'),
        ),
        'class' => array('sumrow', 'bordertop'),
    );
    $totalvatstring = "";
    // VAT
    $vatvalues = array(
        "!vat_value" => $billable->total_vat,
        "!currency" => $billable->currency
    );
    $totalvatstring .= t("!vat_value !currency", $vatvalues) . " <br />";
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("!vat_rate% VAT", array("!vat_rate" => $billable->vat_rate)), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => $totalvatstring, 'class' => 'right'),
        ),
        'class' => array('sumrow'),
    );

    // Sum brutto
    $rows[] = array('data' => array(
            0 => '',
            1 => '',
            2 => array('data' => t("Sum incl. VAT"), 'class' => 'right', 'colspan' => 2),
            3 => array('data' => $billable->total_price .' '. $billable->currency, 'class' => 'right'),
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