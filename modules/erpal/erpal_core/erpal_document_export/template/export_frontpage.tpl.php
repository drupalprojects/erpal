<div>
  <?php if(isset($logo)) echo '<img class="auto-scale" src="'. $logo .'"/>'; ?>
  <br/><br/><br/><br/><br/><br/><br/><br/><br/><br/>
  <h1><?php print($title); ?></h1>
  <br/><br/><br/><br/><br/><br/>
  
  <?php if(isset($date)): ?>
    <div class='date'>
      <b>Date: </b> <br/><br/>
      <?php echo $date; ?>
    </div> 
  <?php endif; ?>
    
  <?php if(isset($address)): ?>
    <br/><br/><br/>
    <div class='address'>
      <b>Customer:</b><br/><br/>
      <?php if (isset ($address['name'])) echo $address['name'] . '<br/>'; ?>
      <?php if (isset ($address['addition'])) echo $address['addition'] . '<br/>'; ?>
      <?php if (isset ($address['street'])) echo $address['street'] . '<br/>'; ?>
      <?php if (isset ($address['zip'])) echo $address['zip'] . '<br/>'; ?>
      <?php if (isset ($address['city'])) echo $address['city'] . '<br/>'; ?>
      <?php if (isset ($address['country'])) echo $address['country'] ?>
    </div>  
  <?php endif; ?> 
</div>