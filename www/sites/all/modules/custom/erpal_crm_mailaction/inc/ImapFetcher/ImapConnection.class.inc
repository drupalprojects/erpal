<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * This class is for creating IMAP connections.
 */
 

namespace erpal_crm_mailaction;

class ImapConnection {
	
	private $attributes;
	private $host;
	private $port;
	private $mailFolder;
	private $username;
	private $password;	
	private $connectionString;
	private $connectionResourceHandle;
	private $error;
	
	/*
	 * Ctor.
	 */
	private function __construct () {
		
		$this->attributes		= array ();		
		$this->host					= 'localhost';
		$this->port					= 143;
		$this->mailFolder		= 'INBOX';
		$this->username			= '';
		$this->password			= '';	
		
		return;
	}
	
	/*
	 * Factory method for creating an ImapConnection object.
	 * @param 	string					$username		The username.
	 * @param 	string					$password 	The password.
	 * @return	ImapConnection							An ImapConnection object.
	 */
	public static function createConnection ($username, $password) {
		
		$imapConnection = new ImapConnection ();
		
		$imapConnection->username = $username;
		$imapConnection->password = $password;
		
		return $imapConnection;
	}
	
	/*
	 * Set SSL for this connection.
	 * @return	ImapConnection	An ImapConnection object.
	 */
	public function ssl () {
		
		$this->attributes[] = '/ssl';
		
		return $this;
	}
	
	/*
	* Defines, that the certificates will be validated for this connection.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function validateCertificates () {
	
		if (in_array ('/novalidate-cert', $this->attributes)) {
			return $this;
		}
		
		$this->attributes[] = '/validate-cert';
	
		return $this;
	}
	
	/*
	* Defines, that the certificates don't will be validated for this connection.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function doNotValidateCertificates () {
	
		if (in_array ('/validate-cert', $this->attributes)) {
			return $this;
		}
	
		$this->attributes[] = '/novalidate-cert';
	
		return $this;
	}
	
	/*
	* Force use of start-TLS to encrypt the session, and reject connection to servers that do not support it.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function tls () {
	
		if (in_array ('/notls', $this->attributes)) {
			return $this;
		}
	
		$this->attributes[] = '/tls';
	
		return $this;
	}
	
	/*
	* Do not do start-TLS to encrypt the session, even with servers that support it
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function noTls () {
	
		if (in_array ('/tls', $this->attributes)) {
			return $this;
		}
	
		$this->attributes[] = '/notls';
	
		return $this;
	}
	
	/*
	* Defines that this connection uses POP3.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function pop3 () {
	
		if (in_array ('/imap', $this->attributes)) {
			return $this;
		}
	
		$this->attributes[] = '/pop3';
	
		return $this;
	}
	
	/*
	* Defines that this connection uses POP3.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function imap () {
	
		if (in_array ('/pop3', $this->attributes)) {
			return $this;
		}
	
		$this->attributes[] = '/imap';
	
		return $this;
	}
	
	/*
	* Defines the host address.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function host($host) {
		
		$this->host = $host;
	
		return $this;
	}
	
	/*
	* Defines the host address.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function port($port) {
	
		$this->port = $port;
	
		return $this;
	}
	

	/*
	* Defines that this connection uses POP3.
	* @return	ImapConnection	An ImapConnection object.
	*/
	public function connect () {
	
		$this->connectionString 				= '{' . $this->host . ':' . $this->port . implode ('', $this->attributes) . '}' . $this->mailFolder;
		$this->connectionResourceHandle = @imap_open ($this->connectionString, $this->username, $this->password);
		$this->error                    = imap_last_error ();
		
		return $this->connectionResourceHandle;
	}
	
	/*
	 * Returns the connection string.
	 * @return string The connection string.
	 */
	public function getConnectionString () {
		
		return $this->connectionString;
	}
	
	/*
	 * Retrieves the resource handle of the current connection.
	 * @return resource The resource handle.
	 */
	public function getResourceHandle () {
		
		return $this->connectionResourceHandle;
	}
	
	/*
	 * Retrieves the last occured error.
	 * @return string The error string.
	 */
	public function getError () {
	  
		return $this->error === FALSE ? '' : $this->error;
	}
	
	/*
	 * Checks whether an error occured.
	 * @return boolean 	TRUE if an error occured.
	 */
	public function errorOccured () {
	  
		return $this->error !== FALSE;
	}
}
