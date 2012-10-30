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

//Just an example of the notes, because there wasn't any
/*
  $notes = "
  Bitte überweisen Sie den Gesamtbetrag bis zum dd.mm.yyyy auf unser Konto.

  Der Gesamtbetrag setzt sich wie folgt zusammen:
  € x.xxx,xx MwsT zu x% auf € yx.xxx,xx netto.



  Vielen Dank für Ihren Auftrag.

  Max Mustermann
  "; */
/*
  $order_numbers_extern = 'ex12345';
  $order_numbers_intern = 'in67890'; */
?>
<link rel="stylesheet" type="text/css" href="<?php print drupal_get_path('module', 'erpal_invoice_helper'); ?>/template/common.css">
<!--
"Ihre Bestellnummer: echo $order_numbers_extern"
"Unsere Auftragsnummer: echo $order_numbers_intern"
-->
<table>
  <tr><td style="height:1.5cm;">&nbsp;</td></tr>
</table>
<table id="head_table">
  <tr>
    <td>
      <div id="absender">
        <?php if ($company['name']) {print $company['name']; print "&nbsp;-";} ?>
        <?php if ($company['street']) {print $company['street']; print "&nbsp;-";} ?>
        <?php if ($company['zip']) {print $company['zip'];} ?>&nbsp;<?php if ($company['city']) {print $company['city'];} ?>
      </div>
      <div id="anschrift">
        <?php if ($customer['name']) {print $customer['name']; print "<br />";} ?>
        <?php if ($customer['address_additionals']) {print "&nbsp;&nbsp;"; print $customer['address_additionals']; print "<br />";} ?>        
        <?php if ($customer['street']) {print "&nbsp;&nbsp;"; print $customer['street']; print "<br />";} ?>
        <?php if ($customer['zip']) {print "&nbsp;&nbsp;"; print $customer['zip'];} ?>&nbsp;<?php if ($customer['city']) {print $customer['city']; print "<br />";} ?>
        <?php if ($customer['country']) {print "&nbsp;&nbsp;"; print $customer['country']; print "<br />";} ?>
      </div>
    </td>      
  </tr>
  <tr>
    <td>      
      <table>
        <tr><td style="height:1.5cm;">&nbsp;</td></tr>
      </table>
      <table id="rechnungsdaten">
        <tr>
          <td id="rechnungsnummer" class="left">
            <table>
              <tr>
                <td>&nbsp;</td>
              </tr>
              <tr>
                <td>&nbsp;</td>
              </tr>
              <tr>
                <td style="height:1cm">&nbsp;</td>
              </tr>
              <tr>
                <td>Rechnung Nr. <?php print $invoice_number; ?></td>
              </tr>
            </table>  
          </td>
          <td id="rechnungsdatum" class="right">
            <table>
              <tr>
                <td><?php if ($copy) : ?><?php print $copy; ?><?php endif; ?></td>
              </tr>
              <tr>
                <td><?php if ($order_numbers_extern) : ?> Ihre Bestellnummer: <?php print $order_numbers_extern; ?><?php endif; ?></td>
              </tr>
              <tr>
                <td><?php if ($order_numbers_intern) : ?> Ihre Auftragsnummer: <?php print $order_numbers_intern; ?><?php endif; ?></td>
              </tr>
              <tr>
                <td style="height:1cm">&nbsp;</td>
              </tr>
              <tr>
                <td>Datum: <?php print $invoice_date; ?></td>
              </tr>
            </table>            
          </td>      
        </tr>   
      </table>
    </td>
  </tr>
</table>

<table>
  <tr><td style="height:0.8cm;">&nbsp;</td></tr>
</table>
<?php
$table = array();

$data['header'] = array(
    'executed' => array('data' => t("Executed"), "class" => "left executed"),
    'amount' => array('data' => t("Quantity"), "class" => "left amount"),
    //'article'   => array('data' => t("Article nr."), "class" => "left article"),
    'description' => array('data' => t("Description"), "class" => "left description"),
    'price' => array('data' => t("Single price (%curr)", array('%curr' => $currency)), "class" => "right price"),
    'total' => array('data' => t("Total (%curr)", array('%curr' => $currency)), "class" => "right total"),
);

$curr = ' ' . $currency;

// Billables-Table
if (is_array($billables)) {

  $rows = array();
  foreach ($billables as $billable) {    

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
    $row[] = array('data' => trim($billable['subject']),
        "class" => "left");
    // price
    $row[] = array('data' => number_format($billable['single_price'], 2, ',', '.'),
        "class" => "right");
    // total
    $row[] = array('data' => number_format($billable['total_price'], 2, ',', '.'),
        "class" => "right");

    // Add the Row to the array:
    $rows[] = $row;
  }


  // Sum netto
  $rows[] = array('data' => array(
          0 => '',
          1 => '',
          2 => array('data' => t("Sum excl. VAT"), 'class' => 'right', 'colspan' => 2),
          3 => array('data' => number_format($total_excl_vat, 2, ',', '.') . $curr, 'class' => 'right'),
      ),
      'class' => array('sumrow', 'bordertop'),
  );

  // VAT
  $totalvatstring = "";

  if (is_array($total_vat))
    foreach ($total_vat as $vatposition) {
      $rows[] = array('data' => array(
              0 => '',
              1 => '',
              2 => array('data' => t("!vat_rate% VAT", array("!vat_rate" => $vatposition['vat_rate'])), 'class' => 'right', 'colspan' => 2),
              3 => array('data' => number_format($vatposition['vat_value'], 2, ',', '.'). $curr, 'class' => 'right'),
          ),
          'class' => array('sumrow'),
      );
    
    }
 
  // Sum brutto
  $rows[] = array('data' => array(
          0 => '',
          1 => '',
          2 => array('data' => t("Sum incl. VAT"), 'class' => 'right', 'colspan' => 2),
          3 => array('data' => number_format($total, 2, ',', '.') . $curr, 'class' => 'right'),
      ),
      'class' => array('sumrow'),
  );

  $data['rows'] = $rows;

  $data['attributes']['class'][] = 'rechnungstabelle';

  //print( theme('table', array(), $rows) );
  $table = theme("table", $data);
  print $table;
}
?>
<table id="rechnungshinweis">
  <tr>
    <td>
<?php
//show skonto if set
if ($skonto_text)
  print $skonto_text."<br />";

if (is_array($auto_notes)) {
print implode("<br />\n", $auto_notes);
}

print "<br />\n" . nl2br($notes);
print "\n";
?>
    </td>
  </tr>
</table>