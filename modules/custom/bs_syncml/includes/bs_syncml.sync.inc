<?php

require_once('BsSyncProcessor.inc');

function bs_syncml_sync_page() {
  
  $sids = array(1,2,3);
  $connectiondata = array(
      'server'  => 'http://server2.brightsolutions.de:8080/funambol/ds',
      'user' => 'tester',
      'pass' => 'tester',
  );
  $proc = new BsSyncProcessor($connectiondata);
  $out = $proc->processSync($sids);
  
  return "yay<br /><pre>".$out."</pre>";
  
}