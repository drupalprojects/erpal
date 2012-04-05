<?php
/*
 * Invoice-template
 * 
 * available variables:
 * $company
 * $customer
 * $invoice_number
 * $invoice_date
 * $billables
 * $auto_notes
 * $notes
 * 
 * $total_excl_vat
 * $total_vat
 * $total
 */
?>



<style type="text/css" media='all'>
<?php
include('/' . drupal_get_path("module", "erpal_invoice_helper") . "/template/printrechnung.css");
?>
</style>

<!-- TEMPLATE Start -->

<div class='rechnung'>

  <div id='absender'><?php print implode(" - ", $customer); ?></div>

  <div id='anschrift'>
    <?php print implode("<br />", $customer); ?>
  </div>

  <div id='rechnungsnummer'>Rechnung Nr. <?php print $invoice_number; ?></div>

  <div id='rechnungsdatum'>Datum: <?php print $invoice_date; ?></div>

  <div id='rechnungstabelle'>

    <?php
    $table = array();

    $data['header'] = array(
        'executed' => array('data' => t("Executed"), "class" => "left executed"),
        'amount' => array('data' => t("Quantity"), "class" => "left amount"),
        //'article'   => array('data' => t("Article nr."), "class" => "left article"),
        'description' => array('data' => t("Description"), "class" => "left description"),
        'price' => array('data' => t("Price p.P. (%curr)", array('%curr' => $currency)), "class" => "right price"),
        'total' => array('data' => t("Total (%curr)", array('%curr' => $currency)), "class" => "right total"),
    );

    // Billables-Table
    if (is_array($billables)) {

      $rows = array();
      foreach ($billables as $billable) {

        $curr = ' ' . $currency;

        $row = array();

        // Executed
        $row[] = array('data' => $billable['date_delivery'],
            "class" => "left");
        // Amount
        $row[] = array('data' => $billable['quantity'],
            "class" => "left");
//       // Article number
//        $row[] = array('data' => $billable['article_nr'],
//                      "class" => "left");
        // Description
        $row[] = array('data' => $billable['subject'],
            "class" => "left");
        // price
        $row[] = array('data' => $billable['single_price'],
            "class" => "right");
        // total
        $row[] = array('data' => $billable['total_price'],
            "class" => "right");

        // Add the Row to the array:
        $rows[] = $row;
      }


      // Sum netto
      $rows[] = array('data' => array(
              0 => '',
              1 => '',
              2 => array('data' => t("Sum excl. VAT"), 'class' => 'right', 'colspan' => 2),
              3 => array('data' => $total_excl_vat . $curr, 'class' => 'right'),
          ),
          'class' => array('sumrow', 'bordertop'),
      );

      // VAT
      $totalvatstring = "";
      if (is_array($total_vat))
        foreach ($total_vat as $vatposition) {

          $vatvalues = array("!var_rate" => $vatposition['var_rate'],
              "!vat_value" => $vatposition['vat_value'],
              "!currency" => $vatposition['currency'],
          );
          $totalvatstring .= t("Rate: !var_rate%, Amount: !vat_value !currency", $vatvalues) . " <br />";
        }
      $rows[] = array('data' => array(
              0 => '',
              1 => '',
              2 => array('data' => t("VAT"), 'class' => 'right', 'colspan' => 2),
              3 => array('data' => $totalvatstring, 'class' => 'right'),
          ),
          'class' => array('sumrow'),
      );

      // Sum brutto
      $rows[] = array('data' => array(
              0 => '',
              1 => '',
              2 => array('data' => t("Sum incl. VAT"), 'class' => 'right', 'colspan' => 2),
              3 => array('data' => $total . $curr, 'class' => 'right'),
          ),
          'class' => array('sumrow'),
      );

      $data['rows'] = $rows;

      //print( theme('table', array(), $rows) );
      print( theme("table", $data));
    }
    ?>



    <div id='rechnungshinweis'>
      <?php
      print implode("<br />", $auto_nodes);
      print $notes;
      ?>
    </div>

  </div>

</div>

<!-- TEMPLATE END -->
