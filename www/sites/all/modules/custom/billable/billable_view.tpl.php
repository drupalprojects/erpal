<div class="billable_field" id="billable_date_delivery">Delivery date: <?php echo date(_billable_get_date_format(), $billable->date_delivery) ?></div>
<?php $currency = $billable->currency; ?> 
<div class="billable_field" id="billable_single_price">Single Price: <?php echo $billable->single_price; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_vat_rate">VAT rate: <?php echo $billable->vat_rate; ?>%</div>
<div class="billable_field" id="billable_quantity">quantity: <?php echo $billable->quantity ?></div>
<div class="billable_field" id="billable_total_price_no_vat">Total price excluding VAT: <?php echo $billable->total_price_no_vat; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_total_vat">Total VAT: <?php echo $billable->total_vat; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_total_price">Total price: <?php echo $billable->total_price; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_created">Created: <?php echo date(_billable_get_date_format()." H:i:s", $billable->created) ?></div>
<div class="billable_field" id="billable_changed">Changed: <?php echo date(_billable_get_date_format()." H:i:s", $billable->changed) ?></div>
<div class="billable_edit"><?php echo l(t('Edit'), 'billable/'.$billable->billable_id.'/edit'); ?></div>