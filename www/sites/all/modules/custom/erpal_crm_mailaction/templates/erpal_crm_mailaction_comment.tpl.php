<?php
/*
 * This template will be used for activity comments.
 * 
 * Variables:
 * 
 * $to		-	The email of the email-receiver.
 * $body	- The body of the mail.
 */
?>
<p><strong><?php print t('Sender'); ?>:&nbsp;<?php print $from; ?></strong></p>
<p><strong><?php print t('Receiver'); ?>:&nbsp;<?php print $to; ?></strong></p>
<p><?php print $body; ?></p>