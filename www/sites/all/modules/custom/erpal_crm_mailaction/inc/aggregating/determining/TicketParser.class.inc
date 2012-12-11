<?php
/**
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Parses subject and body of a class.
 * It separates quotes from body and extracts an available ticket ID from a subject.
 */

namespace erpal_crm_mailaction\aggregating\determining;


module_load_include ('inc', 'erpal_crm_mailaction', 'inc/aggregating/determining/Properties.class');

class TicketParser extends \erpal_crm_mailaction\misc\Properties {

  const UNKNOWN = FALSE;

	/**
	 * Ctor.
   * 
   * @param  string $subject    The subject of the mail.
   * @param  string $body       The body of the mail.
	 */
  public function __construct ($subject, $body) {
    
    $this->parseSubject ($subject);
    $this->parseBody ($body);

    return;
  }
  
  /**
   * Parses the subject of a mail for a ticket ID.
   * 
   * @param string subject	The mail subject.
   */
  private function parseSubject ($subject) {
    
    $matches = array ();
    
    if (preg_match_all ('/.+\[(\w+):\W*(\d+)\]/i', $subject, $matches) >= 1) {
      $this->ticketID   = trim($matches[2]);
      $this->tickettype = trim($matches[1]);      
      $this->subject   = trim(preg_replace ('#\[\w+:.*\]#', '', $subject));
       
      return;
    }
    
    $this->ticketID     = self::UNKNOWN;
    $this->tickettype   = self::UNKNOWN;

    return;
  }
  
  /**
   * Parses the body and removes unneed lines.
   * 
   * @param string $body	The mail body.
   */
  private function parseBody ($body) {
    
    $this->body = '';
    
    $index = 0;
    $chars = strlen ($body);
    
    while ($index < $chars) {
      
      switch ($body[$index]) {
        case '>':
          while ($index < $chars && $body[$index] != "\n") {
            $index++;
          }
          break;
          
        default:
          $this->body .= $body[$index];
      }
      
      $index++;
    }
    
    return;
  }
}
