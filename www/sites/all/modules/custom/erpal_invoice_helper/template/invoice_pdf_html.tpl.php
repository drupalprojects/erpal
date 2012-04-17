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



<style>
<?php
  //include('/' . drupal_get_path("module", "erpal_invoice_helper") . "/template/printrechnung.css");
?>

div#absender { 
  font-size: 8pt;
}

div#anschrift {
  height: 140px;
}

table.rechnungstabelle {
 /* border-collapse: collapse;*/
  width: 100%;
  font-size: 8pt;
}

th  {
  font-size: 8pt;
  background-color: #eee;
  border: 3px solid red;
  padding: 3px;
  }

td  {
  font-size: 9pt;
  border-color: #ffaaaa;
  border-style: solid;
  border-width: 0 3px 3px 3px;
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

#rechnungstabelle th.description {
  width: 280pt;
}

tr.bordertop {
  border-top: 1px solid #333;
  margin-top: 5px;
}

div#rechnungshinweis {
  font-size: 9pt;
}




table.footer {
  width:100%; 
}

table.footer td {
  vertical-align: top;
  font-size: 11px;
}
</style>

<!-- TEMPLATE Start -->

  <div id="absender"><?php print implode(" - ", $customer); ?></div>

  <div id="anschrift">
    <?php print implode("<br />", $customer); ?>
  </div>

  <div id="rechnungsnummer">Rechnung Nr. <?php print $invoice_number; ?></div>

  <div id="rechnungsdatum">Datum: <?php print $invoice_date; ?></div>

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
      if(is_array($auto_notes)) print implode("<br />", $auto_notes);
      print $notes;
      ?>
    </div>


<!-- TEMPLATE END -->

<? return; ?>

<!-- EXAMPLE OF CSS STYLE -->
<style>
    h1 {
        color: navy;
        font-family: times;
        font-size: 24pt;
        text-decoration: underline;
    }
    p.first {
        color: #003300;
        font-family: helvetica;
        font-size: 12pt;
    }
    p.first span {
        color: #006600;
        font-style: italic;
    }
    p#second {
        color: rgb(00,63,127);
        font-family: times;
        font-size: 12pt;
        text-align: justify;
    }
    p#second > span {
        background-color: #FFFFAA;
    }
    table.first {
        color: #003300;
        font-family: helvetica;
        font-size: 8pt;
        border-left: 3px solid red;
        border-right: 3px solid #FF00FF;
        border-top: 3px solid green;
        border-bottom: 3px solid blue;
        background-color: #ccffcc;
    }
    td {
        border: 2px solid blue;
        background-color: #ffffee;
    }
    td.second {
        border: 2px dashed green;
    }
    div.test {
        color: #CC0000;
        background-color: #FFFF66;
        font-family: helvetica;
        font-size: 10pt;
        border-style: solid solid solid solid;
        border-width: 2px 2px 2px 2px;
        border-color: green #FF00FF blue red;
        text-align: center;
    }
</style>

<h1 class="title">Example of <i style="color:#990000">XHTML + CSS</i></h1>

<p class="first">Example of paragraph with class selector. <span>Lorem ipsum dolor sit amet, consectetur adipiscing elit. In sed imperdiet lectus. Phasellus quis velit velit, non condimentum quam. Sed neque urna, ultrices ac volutpat vel, laoreet vitae augue. Sed vel velit erat. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Cras eget velit nulla, eu sagittis elit. Nunc ac arcu est, in lobortis tellus. Praesent condimentum rhoncus sodales. In hac habitasse platea dictumst. Proin porta eros pharetra enim tincidunt dignissim nec vel dolor. Cras sapien elit, ornare ac dignissim eu, ultricies ac eros. Maecenas augue magna, ultrices a congue in, mollis eu nulla. Nunc venenatis massa at est eleifend faucibus. Vivamus sed risus lectus, nec interdum nunc.</span></p>

<p id="second">Example of paragraph with ID selector. <span>Fusce et felis vitae diam lobortis sollicitudin. Aenean tincidunt accumsan nisi, id vehicula quam laoreet elementum. Phasellus egestas interdum erat, et viverra ipsum ultricies ac. Praesent sagittis augue at augue volutpat eleifend. Cras nec orci neque. Mauris bibendum posuere blandit. Donec feugiat mollis dui sit amet pellentesque. Sed a enim justo. Donec tincidunt, nisl eget elementum aliquam, odio ipsum ultrices quam, eu porttitor ligula urna at lorem. Donec varius, eros et convallis laoreet, ligula tellus consequat felis, ut ornare metus tellus sodales velit. Duis sed diam ante. Ut rutrum malesuada massa, vitae consectetur ipsum rhoncus sed. Suspendisse potenti. Pellentesque a congue massa.</span></p>

<div class="test">example of DIV with border and fill.<br />Lorem ipsum dolor sit amet, consectetur adipiscing elit. In sed imperdiet lectus.</div>

<br />

<table class="first" cellpadding="4" cellspacing="6">
 <tr>
  <td width="30" align="center"><b>No.</b></td>
  <td width="140" align="center" bgcolor="#FFFF00"><b>XXXX</b></td>
  <td width="140" align="center"><b>XXXX</b></td>
  <td width="80" align="center"> <b>XXXX</b></td>
  <td width="80" align="center"><b>XXXX</b></td>
  <td width="45" align="center"><b>XXXX</b></td>
 </tr>
 <tr>
  <td width="30" align="center">1.</td>
  <td width="140" rowspan="6" class="second">XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX</td>
  <td width="140">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td width="80">XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
 <tr>
  <td width="30" align="center" rowspan="3">2.</td>
  <td width="140" rowspan="3">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
 <tr>
  <td width="80">XXXX<br />XXXX<br />XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
 <tr>
  <td width="80" rowspan="2" >XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
 <tr>
  <td width="30" align="center">3.</td>
  <td width="140">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
 <tr bgcolor="#FFFF80">
  <td width="30" align="center">4.</td>
  <td width="140" bgcolor="#00CC00" color="#FFFF00">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td width="80">XXXX<br />XXXX</td>
  <td align="center" width="45">XXXX<br />XXXX</td>
 </tr>
</table>
