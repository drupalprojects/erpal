<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 
namespace erpal_crm_mailaction;

require_once 'ImapMessageParts.class.inc';

class ImapMailReader extends ImapMessageParts {
  
  private $messageNumber;  
  private $resourceHandle;
  private $properties;
  
  private function __construct () {
    
    $this->properties = array (
      'body'  => '',
      'files' => ''
    );
    
    return;
  }
  
  /*
   * A factory method. It returns an object of this class.
   * @param integer The UID of a specific email in a mailbox.
   */
  public static function getReader ($resourceHandle, $messageNumber) {
    
    $imapMailReader                = new ImapMailreader ();    
    $imapMailReader->messageNumber = $messageNumber;
    $imapMailReader->resouceHandle = $resourceHandle;
    $imapMailReader->structure     = imap_fetchstructure($resourceHandle, $messageNumber);
 
    $imapMailReader->fetchHeader ();
    $imapMailReader->fetchBody   ();
    
    // TODO: WHY THIS DOESN'T WORK?
    imap_setflag_full($resourceHandle, (string)$messageNumber, '\\Seen');
 
    return $imapMailReader;
  }
  
	private function decode ($input) {
		
		$output = imap_mime_header_decode($input);
		if (empty ($output)) {
			return $input;
		}
 
		return utf8_encode ($output[0]->text);
	}
  
  /*
   * Fetches the header of the mail.
   */
  private function fetchHeader () {
 
    $header      = imap_fetchheader($this->resouceHandle, $this->messageNumber);
    $headerArray = (array)imap_rfc822_parse_headers ($header);
 
    foreach ($headerArray as $headerKey=>$headerValue) { 
 
      if (is_array ($headerValue)) {
        $headerValue = array_shift ($headerValue);
      }
      
      if (is_object($headerValue)) {
        
        $headerValue = (array)$headerValue;
        
        foreach ($headerValue as $key=>&$value) {
          $value = self::decode ($value);
          
        }
 
        $headerValue = (object)$headerValue;
      }
      
      $this->properties[$headerKey] = is_string($headerValue) ? self::decode ($headerValue) : $headerValue;
    }    
    
    return;
  }

  
  /*
   * Fetches a mail from mailbox.
   */
  private function fetchBody() {
 
    $parts = self::getParts ($this->resouceHandle, $this->messageNumber, $this->structure);
 
    $this->properties['body']  = self::decode ($parts->message);
    $this->properties['files'] = $parts->attachments;
 
    return; 
  }
  
  /*
   * Getter property for mail informations.
   * @param string $key The key of the property.
   * @return mixed			FALSE if the property not exists. Otherwise the value of the property.
   */
  public function __get ($key) {

    if (! isset ($this->properties[$key])) {
      return FALSE;
    }
 
    return $this->properties[$key];
  }
  
  /*
  * Checks whether the mail has one ore more attachements.
  * @return boolean TRUE on success.
  */
  public function hasAttachments () {

  	return $this->files !== FALSE;
  }
  
  /*
   * Saves an attachment to the disk at public file section.
   * @return boolean TRUE on success.
   */
  public function saveAttachments () {

  	if ($this->hasAttachments () == FALSE) {

  		return FALSE;
  	}
  	
  	$file = null;
 
  	foreach ($this->files as $filename=>$fileData) {
 
    	$file = file_save_data(
    	  $fileData,
    		'public://' . $filename,
    		FILE_EXISTS_RENAME
    	);

    	if ($file === FALSE) {
    		return FALSE;
    	} 
 
    	$this->properties['attachments'][] = $file;
  	}
  	
  	return TRUE;
  }
} 