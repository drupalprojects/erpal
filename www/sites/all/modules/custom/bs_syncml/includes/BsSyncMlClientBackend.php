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

require_once('syncml/dISyncMlClientBackend.php');

class BsSyncMlClientBackend implements dISyncMLClientBackend {

  protected $data = null;

  public function __construct($sids) {

    $this->data = $sids;
  }

  /**
   * Returns the classname of the objects returned by getSyncMLItem.
   * @return string The classname of an existing class, for example "dVCard".
   */
  public function getSyncMLItemClass() {

    return 'dVCard';
  }

  /**
   * Receives the SyncML item with the given id for synchronization.
   * @param $id The id of the item to receive.
   * @return dISyncMLItem Some object implementing the dISyncMLItem interface, for example a dVCard.
   */
  public function getSyncMLItem($id) {
    // TODO!
    $vcard = array();


    $vcard["id"] = $id;
    $vcard["firstname"] = "Vorname $id";
    $vcard["displayname"] = "Nachname $id";
    $card = new dVcard($vcard);
    
    return $card;
  }

  /**
   * Deletes the SyncML item with the given id. This does NOT mean that it has to be deleted from disk
   * right away - it just tells you that the SyncML server has deleted this item. Do NOT include
   * this item in any further synchronisations for this user.
   * @param $id The id of the item to delete.
   * @return boolean True if deleted successfully, false otherwise.
   */
  public function deleteSyncMLItem($id) {
    
    return true;
  }

  /**
   * Called to save a synchronized SyncML item. The $string is the
   * source code of the synced item (usually a vCard, vCalendar etc.)
   * @param $id The id of the item to update. If null, a new item should be added
   * @param $string The string as received from the SyncML server. For example, a vCard.
   * @return string The id of the saved item
   */
  public function saveSyncMLItem($id, $string) {
    
    dpm("receiving item");
    dpm($string);
    
    return $id;
  }

  /**
   * Returns the ids of all SyncML items that were locally updated in the timeframe from
   * $tsfrom to $tsto. These items will be fetched with getSyncMLItem one for one.
   * The returned array has entries of the form ID => ACTION, with action being one of
   * the dSyncMLClient::ACTION_* constants.
   * @param $tsfrom The timestamp where the timeframe starts. Measured in MILLIseconds since 1.1.1970
   * @param $tsto The timestamp where the timeframe ends. Measured in MILLIseconds since 1.1.1970
   * @return array Array containing the ids as described above.
   */
  public function listSyncMLItems($tsfrom, $tsto) {
    $items = array();
    foreach ($this->data as $key => $data) {
      $items[$key] = dSyncMLClient::ACTION_REPLACE;
    }
//    foreach ($deletions as $del) {
//      //dpm("Sending $del for deletion");
//      echo(t("Sending $del for deletion") . "\n");
//      ob_flush();
//      $items[$del] = dSyncMLClient::ACTION_DELETE;
//    }
    return $items;
  }

  /**
   * Returns the timestamp of the last SyncML synchronisation of this backend object.
   * @return string The timestamp of the last SyncML synchronisation, measured in
   */
  public function getLastSyncMLTimestamp() {
    return 0;
  }

  /**
   * Called by the SyncML client when a noteworthy event has happened. Especially:
   * - EVENT_SYNCITEM: one of the backends items was successfully saved to the server.
   * - EVENT_SYNCITEMRECEIVED: the backend successfully received an item from the server
   * - EVENT_SYNCITEMDELETE: one of the backends items was successfully deleted on the server OR
   *                         the server sent a successful delete request (deleteSyncMLItem was
   *                         called before this notification)
   * - EVENT_SYNCITEMFAILED: the sync for the given item failed. The backend should make a note to retry next sync.
   * - EVENT_SYNCDONE: the whole syncing process for this backend completed successfully, e.g. the client and the server
   *                   sent their modifications. Note, however, that the server might send multiple data packages and
   *                   after each package, this event is triggered. So, the event might me triggered multiple times during
   *                   a sync process.
   *
   * @param $event One of the dSyncMLClient::EVENT_* constants
   * @param $id The id associated with the event. Might be null.
   * @param $timestamp The UNIX timestamp associated with the event
   * @return void
   */
  public function notifySyncMLEvent($event, $id, $timestamp) {
    if ($event == dSyncMLClient::EVENT_SYNCITEM) {
            // We've successfully sent an item to the server. Mark this in the database and update the lasttime.	
            //dpm("synced item $id ... $timestamp");
            $timestamp = date("d.m.Y H:i", $timestamp);
            dpm("syncing item $id ... $timestamp\n");
        }
        if ($event == dSyncMLClient::EVENT_SYNCITEMFAILED) {
            // A synchronisation failed. We dont care.
            //drupal_set_message(t("Synching of node $id has failed, maybe try again later"));
            dpm("Synching of node $id has failed, maybe try again later\n"); ob_flush();
        }
        if ($event == dSyncMLClient::EVENT_SYNCITEMDELETE) {
            //delete sync item received - this is very nice but deleteSyncMLItem() handles this
	    //echo("deleting item $id @ $timestamp\n");
        }
        if ($event == dSyncMLClient::EVENT_SYNCDONE) {
            /* SYNC WAS SUCCESSFUL */
            
          dpm("Sync Successful");
        }
  }

}
