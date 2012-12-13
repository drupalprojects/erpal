<?php
/**
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * This class is an IMAP email fetcher.
 */
 
namespace erpal_crm_mailaction\imap;

class ImapFetcher {
	
	
	private $connection;
	private $error;
	
	/*
	 * Ctor.
	 */
	public function __construct () {
		
		return;
	}
	
	/*
	 * Dtor.
	 */
	public function __destruct () {
	  
	  if ($this->connection == NULL) {
	    return;
	  }
	
		$resourceHandle = $this->connection->getResourceHandle ();
		
		if ($resourceHandle === FALSE || empty($resourceHandle)) {
			return;
		}
		
		imap_close ($resourceHandle);
		
		return;
	}
	
	/**
	 * A helper method for checking whether a host is accessible.
   * 
	 * @param string	$hostAddress	The network address of the host.
	 * @param integer	$post			The network port of the host.
	 * @return boolean					TRUE on success.	
	 */
	public static function checkHostAccessibility ($hostAddress, $port) {
	  
    $socketHandle = @fsockopen ($hostAddress, $port);
    
    if ($socketHandle === FALSE) {
      return FALSE;
    }
    
    fclose ($socketHandle);
    
	  return TRUE;
	}
	
	/**
	 * Creates a connection.
   * 
	 * Use method-chaining to configure this connection.
   * 
	 * @return	ImapConnection	An ImapConnection object. 
	 */
	public function openConnection ($username, $password) {
		
		require_once ('ImapConnection.class.inc');
		
		$this->connection = ImapConnection::createConnection ($username, $password);
		
		return $this->connection;
	}
	
  /**
   * 
   */
	private function decode ($input) {
		
		$output = imap_mime_header_decode($input);
		if (empty ($output)) {
			return $input;
		}
 
		return utf8_encode ($output[0]->text);
	}
	
	/**
	 * Reads mails from mailbox by specific criteria.
   * 
	 * @param string $criteria	The IMAP criteria.
	 * @return array			An array of mails.
	 */
	private function read ($criteria) {
		
		require_once ('ImapMailReader.class.inc');
		
		
		$resourceHandle  = $this->connection->getResourceHandle ();
		$mails			 = array ();		

		$emails = imap_search($resourceHandle, $criteria);
 
		if($emails) {

		  rsort($emails);

		  foreach($emails as $email_number) {
 
 
		  	$overview = imap_fetch_overview($resourceHandle, $email_number,0);
		  	$overview = $overview[0];
		  	
		  	$overview->subject = self::decode ($overview->subject);
		  	$overview->from		 = self::decode ($overview->from);
		  	$overview->to			 = self::decode ($overview->to);
		  	
		  	$mails[]  = (object)array (
		  		'data' 					=> $overview,
		  	/*'messageObject'	=> ImapMailReader::getReader ($resourceHandle, $overview->msgno) */
		  	);
		  }
		}
		
		return $mails;
	}
	
	/**
	 * Reads all unseen mails.
   * 
	 * @return array 	An array of mails.
	 */
	public function readUnseen () {
		
		return $this->read ('UNSEEN');
	}
}

