<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 */
 
namespace erpal_crm_mailaction;

class ImapMessageParts {
  
  const PART_MESSAGE     = 'message';
  const PART_ATTACHMENTS = 'attachments';
  
  /*
   * Retrieves the parts of a specific message on a specific connection.
   * @param		resource		$connection				The IMAP connection resource.
   * @param		integer			$messageNumber		The number of the message on the server.
   * @param		object			$structure				The message structure.
   * @return	object												An object of the parts ($obj->message, $obj->attachments[]).
   */
  protected static function getParts ($connection, $messageNumber, $structure) {
 
    $flattenedParts  = isset ($structure->parts) ? self::flattenParts($structure->parts) : array (0=>$structure);
    $foundParts      = array ();
    
    $foundParts[self::PART_MESSAGE]     = '';
    $foundParts[self::PART_ATTACHMENTS] = array ();
    
      
    if ($structure->subtype != 'MIXED') {
      $foundParts[self::PART_MESSAGE] = imap_fetchbody($connection, $messageNumber, 1);
      return (object)$foundParts;
    }
    
    foreach($flattenedParts as $partNumber => $part) {
  
    	switch($part->type) {
    		
    		case 0:
    			// the HTML or plain text part of the email

    			$foundParts[self::PART_MESSAGE] .= self::getPart($connection, $messageNumber, $partNumber, $part->encoding);
 
    		break;
    	
    		case 1:
    			// multi-part headers, can ignore

    		break;
    		case 2:
    			// attached message headers, can ignore
    		break;
    	
    		case 3: // application
    		case 4: // audio
    		case 5: // image
    		case 6: // video
    		case 7: // other
    			$filename = self::getFilenameFromPart($part);
    			if($filename) {
    				// it's an attachment
    				$foundParts[self::PART_ATTACHMENTS][$filename] = self::getPart($connection, $messageNumber, $partNumber, $part->encoding);
    			}
    		break;
    	
    	}
    	
    }
    
    return (object)$foundParts;
  } 
  
  private static function flattenParts($messageParts, $flattenedParts = array(), $prefix = '', $index = 1, $fullPrefix = true) {
  
  	foreach($messageParts as $part) {
  		$flattenedParts[$prefix.$index] = $part;
  		if(isset($part->parts)) {
  			if($part->type == 2) {
  				$flattenedParts = self::flattenParts($part->parts, $flattenedParts, $prefix.$index.'.', 0, false);
  			}
  			elseif($fullPrefix) {
  				$flattenedParts = self::flattenParts($part->parts, $flattenedParts, $prefix.$index.'.');
  			}
  			else {
  				$flattenedParts = self::flattenParts($part->parts, $flattenedParts, $prefix);
  			}
  			unset($flattenedParts[$prefix.$index]->parts);
  		}
  		$index++;
  	}
  
  	return $flattenedParts;
  			
  }
  
  private static function getPart($connection, $messageNumber, $partNumber, $encoding) {
  	
  	$data = imap_fetchbody($connection, $messageNumber, $partNumber);

  	switch($encoding) {
  		case 0: return $data; // QUOTED_PRINTABLE
  		case 1: return quoted_printable_decode($data); // 8BIT
  		case 2: return $data; // BINARY
  		case 3: return base64_decode($data); // BASE64
  		case 4: return quoted_printable_decode($data); // QUOTED_PRINTABLE
  		case 5: return $data; // OTHER
  	}
  	
  	
  }
  
  private static function getFilenameFromPart($part) {
  
  	$filename = '';
  	
  	if($part->ifdparameters) {
  		foreach($part->dparameters as $object) {
  			if(strtolower($object->attribute) == 'filename') {
  				$filename = $object->value;
  			}
  		}
  	}
  
  	if(!$filename && $part->ifparameters) {
  		foreach($part->parameters as $object) {
  			if(strtolower($object->attribute) == 'name') {
  				$filename = $object->value;
  			}
  		}
  	}
  	
  	return $filename;
  	
  }
}
