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
                <td><?php print t('Invoice Nr. !invoice_nr', array('!invoice_nr' => $invoice_number)); ?></td>                
              </tr>
              <tr>
                <td><?php if ($customer['vat_number']) {print t('VAT number').':&nbsp;'; print $customer['vat_number']; print "<br />";} ?></td>
              </tr>
            </table>  
          </td>
          <td id="rechnungsdatum" class="right">
            <table>
              <tr>
                <td><?php if ($copy) : ?><?php print $copy; ?><?php endif; ?></td>
              </tr>
              <tr>
                <td><?php if ($canceled) : ?><?php print $canceled; ?><?php endif; ?></td>
              </tr>
              <tr>
                <td><?php if ($order_numbers_extern) : ?><?php print t('Your order number: !your_number', array('!your_number' => $order_numbers_extern)); ?><?php endif; ?></td>
              </tr>
              <tr>
                <td><?php if ($order_numbers_intern) : ?><?php print t('Our order number: !our_number', array('!our_number' => $order_numbers_intern)); ?><?php endif; ?></td>
              </tr>
              <tr>
                <td style="height:1cm">&nbsp;</td>
              </tr>
              <tr>
                <td><?php print t('Date').': '.$invoice_date; ?></td>
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
    'amount' => array('data' => t("Quantity"), "class" => "left amount quantity"),
    //'article'   => array('data' => t("Article nr."), "class" => "left article"),
    'description' => array('data' => t("Billable description"), "class" => "left description subject"),
    'price' => array('data' => t("Single price (%curr)", array('%curr' => $currency)), "class" => "right price"),
    'vat' => array('data' => t("Tax rate"), "class" => "right price"),
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
        "class" => "left quantity");
//       // Article number
//        $row[] = array('data' => $billable['article_nr'],
//                      "class" => "left");
    // Description
    
    $row[] = array('data' => trim($billable['subject']),
        "class" => "left subject");
    // price
    $row[] = array('data' => number_format($billable['single_price'], 2, ',', '.'),
        "class" => "right");
    // vat rate
    $row[] = array('data' => $billable['vat_rate'],
        "class" => "right");
    // total
    $row[] = array('data' => number_format($billable['total_price_no_vat'], 2, ',', '.'),
        "class" => "right");

    // Add the Row to the array:
    $rows[] = $row;
  }


  // Sum netto
  $rows[] = array('data' => array(
          0 => '',
          1 => '',
          2 => '',
          3 => array('data' => t("Total without tax"), 'class' => 'right', 'colspan' => 2),
          4 => array('data' => number_format($total_excl_vat, 2, ',', '.') . $curr, 'class' => 'right'),
      ),
      'class' => array('sumrow', 'bordertop'),
  );

  // Tax
  $totalvatstring = "";

  if (is_array($total_vat))
    foreach ($total_vat as $vatposition) {
      $rows[] = array('data' => array(
              0 => '',
              1 => '',
              2 => '',
              3 => array('data' => t("!vat_label", array("!vat_label" => $vatposition['vat_label'])), 'class' => 'right', 'colspan' => 2),
              4 => array('data' => number_format($vatposition['vat_value'], 2, ',', '.'). $curr, 'class' => 'right'),
          ),
          'class' => array('sumrow'),
      );
    
    }
 
  // Sum incl. tax
  $rows[] = array('data' => array(
          0 => '',
          1 => '',
          2 => '',
          3 => array('data' => t("Total with tax"), 'class' => 'right', 'colspan' => 2),
          4 => array('data' => number_format($total, 2, ',', '.') . $curr, 'class' => 'right'),
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
<div class="invoice_notes">
<table id="rechnungshinweis">
  <? if (isset($customer['shipping_name'])){ ?>
  <tr>
    <td>
      <?php if (isset($customer['shipping_name'])) { print t('Your shipping address:'); print "<br/>";} ?>
        <?php if (isset($customer['shipping_name'])) {print "&nbsp;&nbsp;"; print $customer['shipping_name']; print "<br />";} ?>
        <?php if (isset($customer['shipping_address_additionals'])) {print "&nbsp;&nbsp;"; print $customer['shipping_address_additionals']; print "<br />";} ?>
        <?php if (isset($customer['shipping_street'])) {print "&nbsp;&nbsp;"; print $customer['shipping_street']; print "<br />";} ?>
        <?php if (isset($customer['shipping_zip'])) {print "&nbsp;&nbsp;"; print $customer['shipping_zip'];} ?>&nbsp;<?php if (isset($customer['shipping_city'])) {print $customer['shipping_city']; print "<br />";} ?>
        <?php if (isset($customer['shipping_country'])) {print "&nbsp;&nbsp;"; print $customer['shipping_country']; print "<br />";} ?>
    </td>
  </tr>
  <? } ?>
  <tr>
    <td>
<?php
//show skonto if set
if ($skonto_text)
  print $skonto_text."<br />";
  
if (is_array($auto_notes)) {
print implode("<br />\n", $auto_notes);
}

print "<br />" . nl2br($notes);
print "\n";
?>
    </td>
  </tr>
</table>
</div>