<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 

namespace erpal_crm_mailaction;

class ImapMailReader {
  
  private $messageNumber;  
  private $resourceHandle;
  private $properties;
  
  private function __construct () {
    
    $this->properties = array (
      'body' => ''
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
 
    $this->properties['body'] = imap_fetchbody($this->resouceHandle, $this->messageNumber, 1);
    $this->properties['body'] = self::decode ($this->properties['body']);

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
  private function getAttachments ($structure) {

  	// TODO: There is a bug with recursion. I don't know more about it, at this time.
  	// TODO: Need property "part" in the data structure.
  	RETURN FALSE; // TODO: 
  	if (isset($structure->parts))	{
  		foreach ($structure->parts as $partOfPart) {
  			$this->hasAttachments($partOfPart);
  		}
  	}	else {
  		if (isset($structure->disposition))	{
  			if ($structure->disposition == 'attachment') {

  				return $structure->dparameters[0]->value;
  			}
  		}
  	}
  	
  	return FALSE;
  }
  
  /*
  * Checks whether the mail has one ore more attachements.
  * @return boolean TRUE on success.
  */
  public function hasAttachments () {

  	return $this->getAttachments ($this->structure) !== FALSE;
  }
  
  /*
   * Saves an attachment to the disk at public file section.
   * @return boolean TRUE on success.
   */
  public function saveAttachments () {
  	
  	$attachment = $this->getAttachments ($this->structure);
  	if ($attachment === FALSE) {
  		return FALSE;
  	}
  	
  	$file = file_save_data(
  		imap_fetchbody($this->resouceHandle, $this->messageNumber, '1.' . $attachment->part),
  		'public://' . $attachment->value,
  		FILE_EXISTS_RENAME
  	);
  	
  	if ($file === FALSE) {
  		return FALSE;
  	}
  	
  	
  	return TRUE;
  }
}

