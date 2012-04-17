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
  ";
$notes = nl2br($notes);*/


?>
<style>
  * {
    font-size:8pt;
  }
  table#anschrifttabelle {
    width:100%;
  }
  div#absender {
    font-size:0.7em;
  }
  
  div#rechnungsdaten_top {
    height:5cm;
  }
  table#rechnungsdaten {
    width:100%;
  }
  div#rechnungstabelle_top {
    height:5cm;
  }
  table.rechnungstabelle th {
    background-color:#eee;
  }
  table.rechnungstabelle td {
    line-height:1.5em;
  }
  .bordertop td {
    border-top:0.5pt solid #000;
    line-height:2em;
  }
  
  
  .left {
    text-align:left;
  }
  .right {
    text-align:right;
  }
</style>

<table>
  <tr><td style="height:1.0cm;">&nbsp;</td></tr>
</table>
<table id="anschrifttabelle">
  <tr>
    <td>
      <div id="absender"><?php print implode(" - ", $customer); ?></div>
      <div id="anschrift">
<?php print implode("<br />", $customer); ?>
      </div>
    </td>      
  </tr>
</table>
<table>
  <tr><td style="height:1.8cm;">&nbsp;</td></tr>
</table>
<table id="rechnungsdaten">
  <tr>
    <td id="rechnungsnummer" class="left">Rechnung Nr. <?php print $invoice_number; ?></td>
    <td id="rechnungsdatum" class="right">Datum: <?php print $invoice_date; ?></td>      
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

  $data['attributes']['class'][] = 'rechnungstabelle';

  //print( theme('table', array(), $rows) );
  $table = theme("table", $data);
  print $table;
}
?>
<div id="rechnungshinweis">
<?php
if (is_array($auto_notes)) {
  print implode("<br />", $auto_notes);
}
print $notes;
?>
</div>
<?php return; ?>



<!-- OLD TEMPLATE -->
<style>
<?php
//include('/' . drupal_get_path("module", "erpal_invoice_helper") . "/template/printrechnung.css");
?>

  th  {
    font-size: 8pt;    
    padding: 3px;  
  }

  td  {
    font-size: 9pt;    
    vertical-align: top;
  }

  th.left,
  td.left	{
    text-align: left;  
  }

  th.right,
  td.right	{
    text-align: right;
  }


  div#absender { 
    font-size: 8pt;  
  }

  div#anschrift {
    height: 140px;
  }
  table#anschrifttabelle {

  }
  #margin_anschrifttabelle_top {
    height:30cm;
    border:1cm solid;
  }
  td#rechnungsdatum {
    text-align:right;
  }
  table.rechnungstabelle {
    /* border-collapse: collapse;*/
    width: 100%;
    font-size: 8pt;
  }


  #rechnungstabelle th.description {
    width: 10cm;
  }

  tr.bordertop {
    border-top: 2mm solid #333;
    margin-top: 2mm;
  }

  div#rechnungshinweis {
    font-size: 9pt;
  }

  table.footer {
    width:100%; 
  }

  table.footer td {
    vertical-align: top;
    font-size: 8pt;
  }


</style>

<!-- TEMPLATE Start -->
<!--
<div id="absender"><?php print implode(" - ", $customer); ?></div>

<div id="anschrift">
<?php print implode("<br />", $customer); ?>
</div>

<div id="rechnungsnummer">Rechnung Nr. <?php print $invoice_number; ?></div>

<div id="rechnungsdatum">Datum: <?php print $invoice_date; ?></div>
-->
<table id="margin_anschrifttabelle_top">
  <tr><td></td></tr>
</table>
<table id="anschrifttabelle">
  <tr>
    <td colspan="2">
      <div id="absender"><?php print implode(" - ", $customer); ?></div>
      <div id="anschrift">
<?php print implode("<br />", $customer); ?>
      </div>
    </td>      
  </tr>
  <tr>
    <td id="rechnungsnummer">Rechnung Nr. <?php print $invoice_number; ?></td>
    <td id="rechnungsdatum">Datum: <?php print $invoice_date; ?></td>      
  </tr>    
</table>
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

  $data['attributes']['class'][] = 'rechnungstabelle';

  //print( theme('table', array(), $rows) );
  print( theme("table", $data));
}
?>



<div id="rechnungshinweis">
<?php
if (is_array($auto_notes))
  print implode("<br />", $auto_notes);
print $notes;
?>
</div>


<!-- TEMPLATE END -->

<? return; ?>