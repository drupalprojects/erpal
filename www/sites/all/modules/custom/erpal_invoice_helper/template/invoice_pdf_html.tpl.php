<?php
// spezielles stylesheet für rechnung adden.
drupal_add_css(drupal_get_path("module", "erpal_invoice_helper") . "/template/printrechnung.css");
?>

<!-- TEMPLATE Start -->

<div id='absender'><?php print $company; ?></div>

<div id='anschrift'>
  <?php print implode("<br />", $customer); ?>
</div>

<div id='rechnungsnummer'>Rechnung Nr. <?php print $invoice_number; ?></div>

<div id='rechnungsdatum'>Datum: <?php print theme("date", $invoice_date); ?></div>

<div id='rechnungstabelle'>

  <?php
  $table = array();

  $head = array(
      'executed' => array('data' => t("Executed"), array("class" => "left executed")),
      'amount' => array('data' => t("Executed"), array("class" => "left amount")),
      'article' => array('data' => t("Executed"), array("class" => "left article")),
      'description' => array('data' => t("Executed"), array("class" => "left description")),
      'price' => array('data' => t("Executed"), array("class" => "right price")),
      'total' => array('data' => t("Executed"), array("class" => "right total")),
  );

  dpm($billables);
  if (is_array($billables))
    foreach ($billables as $billable) {
      $row = array();

      //$row[] = array('data' => t("Executed"), array( "class" => "left" )),
    }
  ?>


  <table>
    <thead>
      <tr>
        <th class='left executed'>Ausgeführt</th>
        <th class='left amount'>Menge</th>
        <th class='left article'>Artikelnr.</th>
        <th class='left description'>Artikelbezeichnung</th>
        <th class='right price'>Preis / St. in €</th>
        <th class='right total'>Gesamtbetrag in €</th>
      </tr>
    </thead>

    <tbody>

      <tr class='odd'>
        <td class='left'>06.03.2012</td>
        <td class='left'>5</td>
        <td class='left'>1</td>
        <td class='left'>Projektarbeiten</td>
        <td class='right'>75,00</td>
        <td class='right'>375,00</td>
      </tr>
      <tr class='even'>
        <td class='left'>05.03.2012</td>
        <td class='left'>1</td>
        <td class='left'>2</td>
        <td class='left'>Projektarbeiten mit wesentlich längerem Titel und effektiv gesehen ist das eine sehr viel zu lange Beschreibung aber egal.</td>
        <td class='right'>75,00</td>
        <td class='right'>375,00</td>
      </tr>
      <tr class='odd'>
        <td class='left'>04.03.2012</td>
        <td class='left'>6842</td>
        <td class='left'>13</td>
        <td class='left'>Projektarbeiten</td>
        <td class='right'>14,00</td>
        <td class='right'>97.575,00</td>
      </tr>


      <tr class='sumrow bordertop'>
        <td class='left'></td>
        <td class='left'></td>
        <td class='left'></td>
        <td class='right' colspan=2>Summe Netto:</td>
        <td class='right'>98.123,12 €</td>
      </tr>
      <tr class='sumrow'>
        <td class='left'></td>
        <td class='left'></td>
        <td class='left'></td>
        <td class='right' colspan=2>gesetzl. MwSt.:</td>
        <td class='right'>18.792,47 €</td>
      </tr>
      <tr class='sumrow'>
        <td class='left'></td>
        <td class='left'></td>
        <td class='left'></td>
        <td class='right' colspan=2>Summe Brutto:</td>
        <td class='right'>116.247,12 €</td>
      </tr>
    </tbody>
  </table>


  <div id='rechnungshinweis'>
    <?php
    print $auto_notes;
    print $notes;
    ?>
  </div>

</div>



<!-- TEMPLATE END -->
