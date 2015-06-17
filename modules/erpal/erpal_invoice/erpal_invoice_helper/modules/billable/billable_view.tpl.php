<div class="billable_field" id="billable_date_delivery">Delivery date: <?php echo date(erpal_lib_get_date_format(false), $billable->date_delivery) ?></div>
<?php $contractor = node_load($billable->contractor_nid); ?>
<div class="billable_field" id="billable_contractor">Contractor: <a href="/node/<?php echo $contractor->nid; ?>"><?php echo $contractor->title; ?></a></div>
<?php $customer = node_load($billable->customer_nid); ?>
<div class="billable_field" id="billable_customer">Customer: <a href="/node/<?php echo $customer->nid; ?>"><?php echo $customer->title; ?></a></div>
<?php if ($billable->subject_nid) :?>
<?php $subject_node = node_load($billable->subject_nid); ?>
<div class="billable_field" id="billable_single_price">Subject: <a href="/node/<?php echo $subject_node->nid; ?>"><?php echo $subject_node->title; ?></a></div>
<?php endif ?>
<?php $currency = $billable->currency; ?> 
<div class="billable_field" id="billable_single_price">Single Price: <?php echo $billable->single_price; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_vat_rate">VAT rate: <?php echo $billable->vat_rate; ?>%</div>
<div class="billable_field" id="billable_quantity">Quantity: <?php echo $billable->quantity ?></div>
<div class="billable_field" id="billable_total_price_no_vat">Total price excluding VAT: <?php echo $billable->total_price_no_vat; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_total_vat">Total VAT: <?php echo $billable->total_vat; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_total_price">Total price: <?php echo $billable->total_price; ?>&nbsp;<?php echo $billable->currency; ?></div>
<div class="billable_field" id="billable_created">Created: <?php echo date(erpal_lib_get_date_format(), $billable->created) ?></div>
<div class="billable_field" id="billable_changed">Changed: <?php echo date(erpal_lib_get_date_format(), $billable->changed) ?></div>
<div class="billable_edit"><?php echo l(t('Edit'), 'billable/'.$billable->billable_id.'/edit'); ?></div>
<?php if ($reduced_list): ?>
<div class="billable_field" id="billable_reduced">Reduced entities: <?php echo $reduced_list ?></div>
<div class="billable_ungroup"><?php echo l(t('Ungroup'), 'billable/'.$billable->billable_id.'/ungroup');?></div>
<?php endif; ?>