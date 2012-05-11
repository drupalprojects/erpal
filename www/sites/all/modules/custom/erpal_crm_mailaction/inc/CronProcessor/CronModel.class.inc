<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 
namespace erpal_crm_mailaction;

class CronModel {
  
  private $nextTask;
  
  /*
   * Ctor.
   */
  public function __construct () {
    
    $this->peekFirst ();

    return;
  }
  
  /*
   * Reads the first available task from the task queue.
   */
  public function peekFirst () {
    
    $result         = db_query ('SELECT qid, messageids FROM {erpal_crm_mailaction_queue} ORDER BY qid ASC LIMIT 1');
    $this->nextTask = $result->fetchObject(); 
    
    return;
  }
  
  /*
   * Adds a bunch of tasks to the task queue.
   * @param array	$messageIDs	An array which contains IMAP message IDs.
   */
  public function addTask (array $messageIDs) {

    db_insert('erpal_crm_mailaction_queue')  
    ->fields(array(
      'messageids' => serialize ($messageIDs)
    ))
    ->execute();
    
    $this->peekFirst ();

    return;
  }
  
  /*
   * Checks whether tasks are available.
   * @return boolean	TRUE on success.
   */
  public function areTasksAvailable () {
    
    return ! empty ($this->nextTask);
  }
  
  /*
   * Runs a next available task and deletes it from tasks queue.
   * @return boolean	TRUE on success, if a task could be processed.
   */
  public function processNextTask () {
    
    if (! $this->areTasksAvailable ()) {
      return FALSE;
    }
    
    // Include important files.
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/ImapFetcher/ImapFetcher.class');
    module_load_include ('inc', 'erpal_crm_mailaction', 'inc/ImapFetcher/ImapMailReader.class');
    
    $imapFetcher  = new ImapFetcher ();
    $connection   = CronProcessor::configureImapConnection($imapFetcher);
    $messageIDs   = unserialize ($this->nextTask->messageids);
    
    foreach ($messageIDs as $messageID) {

      $mail = ImapMailReader::getReader($connection->getResourceHandle(), $messageID);
         dpm ($mail->body);
         
      if ($mail->hasAttachments()) {
        $mail->saveAttachments ();
      }
   
      module_invoke_all ('erpal_crm_mailaction_incoming', $mail->to, $mail->from, $mail->subject, $mail->body);
    }

    db_delete ('erpal_crm_mailaction_queue')
    ->condition ('qid', $this->nextTask->qid)
    ->execute ();
    
    return TRUE;
  }
}