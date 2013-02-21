<div class="budget_field" id="budget_total_hours">Total hours: <?php echo $budget->total_hours; ?></div>
<div class="budget_field" id="budget_available_hours">Available hours: <?php echo $budget->available_hours; ?></div>
<div class="budget_field" id="budget_date_from">Available from: <?php echo date(_budget_get_date_format(false), $budget->date_from) ?></div>
<div class="budget_field" id="budget_date_till">Available till: <?php echo date(_budget_get_date_format(false), $budget->date_till) ?></div>
<div class="budget_field" id="budget_created">Date created: <?php echo date(_budget_get_date_format(false), $budget->created) ?></div>
<div class="budget_field" id="budget_created">Date changed: <?php echo date(_budget_get_date_format(false), $budget->changed) ?></div>
<div class="budget_edit"><?php echo l(t('Edit'), 'budget/'.$budget->budget_id.'/edit'); ?></div>