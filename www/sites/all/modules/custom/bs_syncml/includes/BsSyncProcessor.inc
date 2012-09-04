<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/*
 * @file 
 * 
 * @author Sebastian Kauschke, Bright Solutions GmbH
 */

require_once('BsSyncMlClientBackend.php');
require_once('syncml/dSyncMlClient.php');
require_once('syncml/dFrame.php');
require_once('syncml/dHTTP.php');
require_once('syncml/dISyncMlClientBackend.php');
require_once('syncml/dISyncMLItem.php');
require_once('syncml/dVCard.php');


class BsSyncProcessor {
  
  private $connectiondata = array();
  private $sids = array();
  private $syncResult = array();
  
  private $syncBackend;
  
  
  /**
   *
   * @param array $connectiondata is an array with the following keys: url, user and password
   */
  public function __construct($connectiondata = array()) {
    
    $this->connectiondata = $connectiondata;
   }
  
  /**
   *
   * @param array $sids An Array of Sids to Sync
   */
  public function processSync($sids) {
    
    //	1) Backend initialisiern:
    $backend = new BsSyncMlClientBackend($sids);

    $server   = $this->connectiondata['server'];
    $usr      = $this->connectiondata['user'];
    $pass     = $this->connectiondata['pass'];

    //Init sync ml client, set to debug mode and register backend
    $sync = new dSyncMLClient($server, $usr, $pass);
    $sync->setContactBackend($backend);
    $sync->setDebugLog(true);

    $out = '';
    try
    {
        $sync->synchronize();
    }
    catch (dSyncMLClientAuthenticationException $ex)
    {
        $out = "SERVER DID NOT ACCEPT LOGIN!<br>";
    }
    catch (Exception $exx)
    {
        $out = "Could not connect to Server<br>";
    }
    
    $out .=  $sync->getDebugLog();
    
    return $out;
  }
  
}
