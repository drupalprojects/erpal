<?php
/**
 * dSyncMLClient.php - Client für SyncML Server - nur getestet mit Funambol.
 *
 * @author Steffen Müller
 * @version 1.0
 *
 * Versioning Information:
 *   Last change in repository: $Date: 2007-05-19 16:50:18 +0200 (Sa, 19 Mai 2007) $
 *   Last change in revision: $Revision: 288 $
 *   Last changing author: $Author: Sam $
 *
 */

// Die Klasse /////////////////////////////////////////////////////////////////////////////////////
class dSyncMLClient
{
	const ACTION_ADD = 1;
	const ACTION_REPLACE = 2;
	const ACTION_DELETE = 3;

	const EVENT_SYNCITEM = 1;
	const EVENT_SYNCITEMDELETE = 2;
	const EVENT_SYNCITEMRECEIVED = 3;
	const EVENT_SYNCITEMFAILED = 4;
	const EVENT_SYNCDONE = 5;

	private $targetURL;
	private $serverURL;
	private $serverHost;
	private $serverPort;
	private $serverPath;
	private $serverTimeout = 5;
	private $userAgent = "dFrame SyncML Module v1.0";
	private $manufacturer = "Incloud";
	private $version = "1.0";
	private $deviceID;

	private $statistics;
	private $commandNotes = array();

	/**
	 * @var DOMDocument
	 */
	private $packageXML = null;
	private $packageXP;

	private $backends = array();

	private $sessionID = "";
	private $messageID = 1;
	private $commandID = 1;
	private $receivedMsgID = 0;
	private $username = "";
	private $password = "";
	private $needsAuthentication = true;

	private $useDebugLog = false;
	private $debugLog = "";
	private $log = array();

	/**
	 * Creates a new SyncML Client object.
	 * @param $serverurl The URL of the funambol server to connect to, for example "http://fun.dc:7777/funambol/ds"
	 * @param $username The username to use for logging in at the funambol server
	 * @param $password The password for the username
	 */
	public function __construct ($serverurl, $username, $password)
	{
		$this->setServerURL($serverurl);
		$this->sessionID = dCreateUniqueKey(24);
		$this->username = $username;
		$this->password = $password;
		$this->deviceID = "drupal-".  md5(drupal_get_private_key());

		// Init statistics
		$this->statistics = array
		(
			"sent_adds" => 0,
			"sent_updates" => 0,
			"sent_deletes" => 0,
			"received_adds" => 0,
			"received_updates" => 0,
			"received_deletes" => 0,
			"warnings" => 0,
			"errors" => 0
		);
	}

	/**
	 * Changes the auto-generated device id to the given string.
	 * @param $id A string which is used as the device id.
	 */
	public function setDeviceID ($id)
	{
		$this->deviceID = $id;
	}

	/**
	 * Starts a synchronisation process. Typically called after the backends were
	 * added to the object.
	 * @return boolean Always true. If something goes wrong, it throws an exception.
	 */
	public function synchronize ()
	{
		// First package: send what to synchronize and authenticate (implicitly)
		$ts = time();
		foreach ($this->backends as $name => $data)
		{
			$this->backends[$name]["next"] = $ts;
			$a = '<Alert><Data>200</Data><Item><Target><LocURI>'.$data["id"].'</LocURI></Target><Source><LocURI>'.$name.'</LocURI></Source>';
			$a .= '<Meta><Anchor><Last>'.$data["last"].'</Last><Next>'.$ts.'</Next></Anchor></Meta>';
			$a .= '</Item></Alert>';
			$this->addCommand($a);
		}
		$this->sendPackage();

		// Second step: send the local data, possibly splitted among many packages
		foreach ($this->backends as $name => $data)
			$this->sendBackendData($name);

		// Third step: call server to get the remote data
		foreach ($this->backends as $name => $data)
			$this->receiveBackendData($name);
		$this->sendPackage();

		// Fourth step: send map updates for created items and other stuff that may be left in the
		// queue from the callbacks in step 3.
		$this->sendPackage();

		// We're done!
		return true;
	}

	// PUBLIC HELPERS: LOGGING AND STATISTICS /////////////////////////////////////////////////////

	/**
	 * Activates the debug log which tracks the raw HTTP requests and responses.
	 * @param $onoff boolean Whether to activate the debug log or not.
	 */
	public function setDebugLog ($onoff)
	{
		$this->useDebugLog = !!$onoff;
	}

	/**
	 * Returns the debug log. Only works if it was activated before with setDebugLog.
	 * @return string The debug log
	 */
	public function getDebugLog ()
	{
		if (!$this->useDebugLog)
			throw new Exception("dSyncMLClient::getDebugLog: you have to activate the debuglog first with setDebugLog(true).");
		return $this->debugLog;
	}

	/**
	 * Returns the log book of the synchronisation. Certain message types can be filtered and the log can be returned
	 * as a string or as an array for further processing.
	 * If returned as an array, each array element contains the keys "text", "type" (either "error","warning","message")
	 * and "timestamp".
	 * @param $asstring boolean Optional. If true, return as a string, otherwise as an array as described above.
	 * @param $typefilter string Optional. If set, only shows log entries of the given type. Possible values: "error","warning","message".
	 * @return mixed Either string or array.
	 */
	public function getLog ($asstring=true, $typefilter=false)
	{
		// Cheap shot - return the log as is
		if (!$asstring && !$typefilter)
			return $this->log;

		// Apply the typefilter
		$log = $this->log;
		if ($typefilter)
		{
			for ($i = 0; $i < count($log); $i++)
			{
				if ($log[$i]["type"] != $typefilter)
					unset($log[$i]);
			}
		}

		// Cheap shot 2 - return the filtered array
		if (!$asstring)
			return $log;

		// Make string
		$s = "";
		foreach ($log as $l)
		{
			$d = new dDate($l["timestamp"]);
			$s .= $d->time(true)." ".str_pad($l["type"], 7, " ")." ".$l["text"]."\r\n";
		}
		return $s;
	}

	/**
	 * Returns the statistics collected during the synchronisation. Only useful if called
	 * AFTER synchronize(). The returned array contains the keys:
	 * - sent_adds: count of add operations sent to the server
	 * - sent_updates: count of update operations sent to the server
	 * - sent_deletes: count of delete operations sent to the server
	 * - received_adds: count of add operations received by the server
	 * - received_updates: count of update operations received by the server
	 * - received_deletes: count of delete operations received by the server
	 * - warnings: count of warnings that were written to the log
	 * - errors: count of errors that were written to the log
	 * @return array Array as described above.
	 */
	public function getStatistics ()
	{
		return $this->statistics;
	}

	// BACKEND DEFINITIONS ////////////////////////////////////////////////////////////////////////

	protected function setBackend ($name, $id, dISyncMLClientBackend $backend)
	{
		// Define the backend
		$this->backends[$name] = array
		(
			"id" => $id,
			"syncrange_from" => 0,
			"syncrange_to" => 0,
			"last" => $backend->getLastSyncMLTimestamp(),
			"backend" => $backend
		);
		return true;
	}

	/**
	 * Sets the backend object for the synchronisation of contacts.
	 * @param $backend An object implementing the dISyncMLClientBackend interface.
	 * @return boolean Always returns true.
	 */
	public function setContactBackend (dISyncMLClientBackend $backend)
	{
		return $this->setBackend("contact", "card", $backend);
	}

	// BACKEND SYNCHRONISATION ////////////////////////////////////////////////////////////////////

	protected function sendBackendData ($name)
	{
		// Get the backend and check whether we have to sync anyhow
		$backend = &$this->backends[$name];
		if (!$backend["syncrange_to"])
			return;

		// We have to sync. Create the sync wrapping command.
		$sync = $this->addCommand('<Sync><Target><LocURI>'.$backend["id"].'</LocURI></Target><Source><LocURI>'.$name.'</LocURI></Source></Sync>');

		// Get the changed items in the given time range from the backend
		$srf = $this->toUnixTimestamp($backend["syncrange_from"]);
		$srt = $this->toUnixTimestamp($backend["syncrange_to"]);
		$list = $backend["backend"]->listSyncMLItems($srf, $srt);

		$this->logMessage("Sending data for backend $name in the range of ".$backend["syncrange_from"]." to ".$backend["syncrange_to"]." (".count($list)." items).");

		// The list is an associative array of the form ID => ACTION.
		foreach ($list as $id => $action)
		{
			$cmd = "";
			$verb = "";
			$metatype = null;
			$data = null;

			// Decide about the verb we want to issue
			if ($action == dSyncMLClient::ACTION_ADD) $verb = "Add";
			elseif ($action == dSyncMLClient::ACTION_REPLACE) $verb = "Replace";
			elseif ($action == dSyncMLClient::ACTION_DELETE) $verb = "Delete";
			else
			{
				$this->logError("Invalid action defined in list from backend $name: '$action'");
				continue;
			}

			// If we want to add or replace, create the data.
			if ($action == dSyncMLClient::ACTION_ADD || $action == dSyncMLClient::ACTION_REPLACE)
			{
				$element = $backend["backend"]->getSyncMLItem($id);
				if (!($element instanceof dISyncMLItem))
				{
					$this->logError("Could not get item for adding or replacing from backend $name: '$id'");
					continue;
				}
				$elementmeta = call_user_func(array(get_class($element), "GetSyncMLMeta"));
				$metatype = $elementmeta["mimetype"];
				$data = $element->getSyncMLString();
			}

			// Create the command and issue it
			$cmd = "<$verb>";
			if ($metatype)
				$cmd .= '<Meta><Type>'.$metatype.'</Type></Meta>';
			$cmd .= '<Item><Source><LocURI>'.$id.'</LocURI></Source>';
			if ($data)
				$cmd .= '<Data><![CDATA['.$data.']]></Data>';
			$cmd .= "</Item></$verb>";

			if ($action == dSyncMLClient::ACTION_DELETE)
				$ev = dSyncMLClient::EVENT_SYNCITEMDELETE;
			else
				$ev = dSyncMLClient::EVENT_SYNCITEM;
			$this->addCommand($cmd, $sync, array("backend" => $name, "action" => "notify", "event" => $ev, "id" => $id, "statcommand" => $action));
		}

		$this->sendPackage();

		// Save that we are done
		$this->logMessage("Done sending items for backend '$name'.");
	}

	protected function receiveBackendData ($name)
	{
		$this->logMessage("Asking server to send the data for backend '$name' that changed since '".$this->backends[$name]["last"]."'.");
		$alert = '<Alert><Data>222</Data><Item><Target><LocURI>'.$this->backends[$name]["id"].'</LocURI></Target><Source><LocURI>'.$name.'</LocURI></Source></Item></Alert>';
		$this->addCommand($alert);
	}

	// PACKAGE HANDLING ///////////////////////////////////////////////////////////////////////////

	protected function startPackage ()
	{
		// Reset the command id - it counts only during one package
		$this->commandID = 1;

		// Set the obvious - versions, session, message id
		$this->packageXML = new DOMDocument("1.0", "UTF-8");
		$this->packageXML->loadXML('<?xml version="1.0" encoding="UTF-8"?><SyncML><SyncHdr><VerDTD>1.2</VerDTD><VerProto>SyncML/1.2</VerProto><SessionID>'.$this->sessionID.'</SessionID><MsgID>'.$this->messageID++.'</MsgID><Target><LocURI></LocURI></Target><Source><LocURI></LocURI></Source></SyncHdr><SyncBody></SyncBody></SyncML>');
		if ($this->useDebugLog)
			$this->packageXML->formatOutput = true;

		$this->packageXP = new DOMXPath($this->packageXML);
		$this->packageXP->query('./SyncHdr/Target/LocURI')->item(0)->appendChild($this->packageXML->createTextNode($this->targetURL));
		$this->packageXP->query('./SyncHdr/Source/LocURI')->item(0)->appendChild($this->packageXML->createTextNode($this->deviceID));

		// Set authentication (only basic is supported right now)
		if ($this->needsAuthentication)
		{
			$cred = $this->packageXML->createElement("Cred");
			$meta = $this->packageXML->createElement("Meta");
			$format = $this->packageXML->createElement("Format", "b64");
			$type = $this->packageXML->createElement("Type", "syncml:auth-basic");
			$data = $this->packageXML->createElement("Data", base64_encode($this->username.":".$this->password));

			$cred->appendChild($meta);
			$meta->appendChild($format);
			$meta->appendChild($type);
			$cred->appendChild($data);
			$this->packageXP->query("./SyncHdr")->item(0)->appendChild($cred);
		}

		// This is not the first message package, so approve the header of the last response (> 2 because of the ++ above)!
		if ($this->messageID > 2)
		{
			$cmd = '<Status><MsgRef>'.$this->receivedMsgID.'</MsgRef><CmdRef>0</CmdRef><Cmd>SyncHdr</Cmd><TargetRef>'.$this->targetURL.'</TargetRef><SourceRef>'.$this->deviceID.'</SourceRef><Data>200</Data></Status>';
			$this->addCommand($cmd);
		}

		return true;
	}

	protected function sendPackage ()
	{
		// Do not send empty packages
		if (!$this->packageXML)
			return;

		// Instantiate HTTP object
		$http = new dHTTP($this->serverHost, $this->serverPort, $this->serverTimeout);
		$http->setVerb("POST");
		if ($this->useDebugLog)
			$http->setDebug(true);

		$http->setHeader("Cache-Control", "no-store,private");
		$http->setHeader("Accept-Charset", "utf-8");
		$http->setHeader("Accept", "application/vnd.syncml+xml,application/xml,text/html");
		$http->setHeader("User-Agent", $this->userAgent);
		$http->setHeader("Content-Type", "application/vnd.syncml+xml");

		// Add final command to close the package
		$this->addCommand('<Final/>');

		// Set it as POST body
		$http->setRawData($this->packageXML->saveXML());

		// Send the request
		$status = $http->send($this->serverPath);

		if ($this->useDebugLog)
		{
			$this->debugLog .= "\r\n\r\n===SENDING REQUEST #".($this->messageID-1)." TO SERVER:===\r\n\r\n";
			$this->debugLog .= $http->getSentRequest();
		}

		// Reset the package xml for the next package
		$this->packageXML = null;


		// Parse response
		try
		{
      dpm($http->getBody());
			$xml = new SimpleXMLElement($http->getBody());

			// Get the message package id
			$this->receivedMsgID = $xml->SyncHdr->MsgID;
			$this->logMessage("Received package with id ".$this->receivedMsgID);

			if ($this->useDebugLog)
			{
				$dbgxml = new DOMDocument("1.0", "UTF-8");
				$dbgxml->loadXML($http->getBody());
				$dbgxml->formatOutput = true;

				$this->debugLog .= "\r\n\r\n===RECEIVED RESPONSE #".$this->receivedMsgID." FROM SERVER:===\r\n\r\n";
				$this->debugLog .= $dbgxml->saveXML();
			}
		}
		catch (Exception $ex)
		{
			$this->logError("Received non-XML response from server: ".$ex->getMessage()."\r\n\r\n".$http->getBody());
		}

		// Work through every child node of the SyncBody
		try
		{
			// Parse for RespURI element
			if ($xml->SyncHdr->RespURI && strcmp($xml->SyncHdr->RespURI, $this->serverURL) != 0)
			{
				$this->logMessage("Parsing new RespURI (".$xml->SyncHdr->RespURI.")");
				$this->setServerURL($xml->SyncHdr->RespURI);
			}

			if(is_object($xml->SyncBody)) foreach ($xml->SyncBody->children() as $cmd)
			{
				$mn = "process".$cmd->getName();
				if ($mn == "processFinal") continue;

				if (method_exists($this, $mn))
					$this->$mn($cmd);
				else
					$this->logWarning("Ignoring received command ".$cmd->getName());
			}
		}
		catch (Exception $ex)
		{
			if ($ex instanceof dSyncMLClientAuthenticationException)
				throw $ex;
			else
				$this->logError("Exception thrown during processing of the response body: ".$ex->getMessage());
		}

		return $xml;
	}

	/**
	 * Adds the given command to the SyncBody of the current message package and returns
	 * the corresponding DOMElement.
	 * @param $cmd The command - either a DOMElement or a XML string of the command element
	 * @param $parent Optional. The parent DOMElement from the response. Useful for nesting commands.
	 * @param $notes Optional. Saves the given mixed data for this command and makes it available in server
	 * responses for this command.
	 * @return DOMElement
	 */
	protected function addCommand ($cmd, $parent=null, $notes=null)
	{
		// Start a package if there is none
		if (!$this->packageXML)
			$this->startPackage();

		// Make a DOMDocumentFragment out of our string
		if (is_string($cmd))
		{
			try
			{
				$frag = $this->packageXML->createDocumentFragment();
				if (!$frag->appendXML($cmd))
					throw new Exception("appendXML failed");

				$cmd = $this->packageXP->query("./*", $frag)->item(0);
			}
			catch (Exception $ex)
			{
				throw new Exception("dSyncMLClient::addCommand: invalid command specified (no good xml): $cmd");
			}
		}
		if (!($cmd instanceof DOMElement))
			return null;

		// Check the parent
		if ($parent === null || !($parent instanceof DOMElement))
			$parent = $this->packageXP->query("./SyncBody")->item(0);

		// Get the command ID
		$cid = $this->commandID++;

		// Add the command id and append it
		if (strtolower($cmd->nodeName) != "final")
			$cmd->insertBefore($this->packageXML->createElement("CmdID", $cid), $cmd->childNodes->item(0));

		// Save the notes (messageID - 1 because of the post increment)
		if ($notes !== null)
			$this->commandNotes[($this->messageID-1).".".$cid] = $notes;

		$parent->appendChild($cmd);
		return $cmd;
	}

	// RESPONSE HANDLING //////////////////////////////////////////////////////////////////////////

	/**
	 * The server answers to one of our commands. Parse the answer, if necessary. No action
	 * has to happen, its just informal.
	 */
	protected function processStatus (SimpleXMLElement $cmd)
	{
		// Special case: status referencing the SyncHeader
		if ($cmd->CmdRef == 0)
		{
			if ($cmd->Data == 212)
				$this->needsAuthentication = false;
			elseif ($cmd->Data != 200)
			{
				if ($cmd->Data == 401)
					throw new dSyncMLClientAuthenticationException();

				throw new Exception("dSyncMLClient::processStatus: the server did not accept our message and returned a status code of '".$cmd->Data."' for our SyncHeader.");
			}
			return;
		}

		// If the sent command wanted some sort of feedback, do it.
		if ((($cmd->Data >= 200 && $cmd->Data < 300) || $cmd->Data == 418 || $cmd->Data == 419) && isset($this->commandNotes[$cmd->MsgRef.".".$cmd->CmdRef]))
		{
			$notes = $this->commandNotes[$cmd->MsgRef.".".$cmd->CmdRef];
			if ($notes["action"] == "notify")
			{
				try
				{
					// Notify the backend
					$ts = $this->toUnixTimestamp($this->backends[$notes["backend"]]["syncrange_to"]);
					$this->backends[$notes["backend"]]["backend"]->notifySyncMLEvent($notes["event"], $notes["id"], $ts);

					// Care for our statistics
					if ($notes["statcommand"] == dSyncMLClient::ACTION_ADD)
						$this->statistics["sent_adds"]++;
					elseif ($notes["statcommand"] == dSyncMLClient::ACTION_REPLACE)
						$this->statistics["sent_updates"]++;
					elseif ($notes["statcommand"] == dSyncMLClient::ACTION_DELETE)
						$this->statistics["sent_deletes"]++;
				}
				catch (Exception $ex)
				{
					$this->logError("Exception occured while notifying SyncML success on id ".$notes["id"].": ".$ex->getMessage());
				}
			}

			if ($cmd->Data == 418)
			{
				if ($cmd->Cmd == "Add")
					$this->logWarning("Problem occured: the item '".$notes["id"]."' from backend '".$notes["backend"]."' was added, but did already exist. It was not saved, but was treated as successful to escape this vicious circle. Check your backend.");
				// In case of Replace, nothing is wrong - funambol says 418 if there was no difference between server and client.
			}
		}
		// If we go in here, there was an error
		elseif (isset($this->commandNotes[$cmd->MsgRef.".".$cmd->CmdRef]))
		{
			$notes = $this->commandNotes[$cmd->MsgRef.".".$cmd->CmdRef];
			if ($notes["action"] == "notify")
			{
				try
				{
					$this->logError("Sync failed for object '".$notes["id"]."' (code ".$cmd->Data."): ".$cmd->Item->Data);
					$ts = $this->toUnixTimestamp($this->backends[$notes["backend"]]["syncrange_to"]);
					$this->backends[$notes["backend"]]["backend"]->notifySyncMLEvent(dSyncMLClient::EVENT_SYNCITEMFAILED, $notes["id"], $ts);
				}
				catch (Exception $ex)
				{
					$this->logError("Exception occured while notifying SyncML failure on id ".$notes["id"].": ".$ex->getMessage());
				}
			}
		}

		// Slow sync?
		if ($cmd->Data == 508 && isset($cmd->SourceRef, $this->backends))
			$this->logWarning("The server requested a slow sync for backend ".$cmd->SourceRef.". We ignore it and proceed. Check your backend: does it update the anchor timestamp correctly?");

		// Status of some command. If a method exists, call it.
		$mn = "status".$cmd->Cmd;
		if (method_exists($this, $mn))
			$this->$mn($cmd);
	}

	/**
	 * The server wants us to send him data from a given backend. We will gladly fullfil.
	 */
	protected function processAlert (SimpleXMLElement $cmd)
	{
		// Get which backend should be synchronized
		$target = strtolower($cmd->Item->Target->LocURI);
		if (!isset($this->backends[$target]))
		{
			$this->logWarning("Server alerts us for unknown backend '$target'.");
			return;
		}

		// Get the time range we should synchronize
		if ($cmd->Item->Meta->Anchor->Last)
			$this->backends[$target]["syncrange_from"] = $this->toUnixTimestamp($cmd->Item->Meta->Anchor->Last);
		if ($cmd->Item->Meta->Anchor->Next)
			$this->backends[$target]["syncrange_to"] = $this->toUnixTimestamp($cmd->Item->Meta->Anchor->Next);
		if ($this->backends[$target]["syncrange_from"] == $this->backends[$target]["syncrange_to"])
			$this->backends[$target]["syncrange_from"] = 0;

		$this->logMessage("Server requested data for backend $target in the range of ".$this->backends[$target]["syncrange_from"]." to ".$this->backends[$target]["syncrange_to"]);

		$status = '<Status>';
		$status .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
		$status .= '<CmdRef>'.$cmd->CmdID.'</CmdRef>';
		$status .= '<Cmd>'.$cmd->getName().'</Cmd>';
		$status .= '<TargetRef>'.$cmd->Item->Source->LocURI.'</TargetRef>';
		$status .= '<SourceRef>'.$cmd->Item->Target->LocURI.'</SourceRef>';
		$status .= '<Item><Data><Anchor><Next>'.$cmd->Item->Meta->Anchor->Next.'</Next></Anchor></Data></Item>';
		$status .= '<Data>200</Data>';
		$status .= '</Status>';
		$this->addCommand($status);
	}

	/**
	 * The server sends us sync data!
	 */
	protected function processSync  (SimpleXMLElement $cmd)
	{
		// Get the name of the backend we will synchronize
		$target = strtolower($cmd->Target->LocURI);
		if (!isset($this->backends[$target]))
		{
			$this->logWarning("Server requested to sync unknown backend '$target'.");
			return;
		}

		$this->logMessage("Server sends a data package for backend '$target'.");

		// Send status command for the sync command
		$status = '<Status>';
		$status .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
		$status .= '<CmdRef>'.$cmd->CmdID.'</CmdRef>';
		$status .= '<Cmd>Sync</Cmd>';
		$status .= '<TargetRef>'.$cmd->Source->LocURI.'</TargetRef>';
		$status .= '<SourceRef>'.$cmd->Target->LocURI.'</SourceRef>';
		$status .= '<Data>200</Data>';
		$status .= '</Status>';
		$this->addCommand($status);

		// Add, delete and replace like hell
		$itemcount = 0;
		$map = array();
		foreach ($cmd->children() as $child)
		{
			$cn = strtolower($child->getName());
			if (!in_array($cn, array("add","delete","replace")))
				continue;

			// Prepare an accept status for the command
			$status = '<Status>';
			$status .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
			$status .= '<CmdRef>'.$child->CmdID.'</CmdRef>';
			$status .= '<Cmd>'.$child->getName().'</Cmd>';
			$retcode = 200;
			$itemstatus = "";

			// Process all children in the command
			foreach ($child->children() as $item)
			{
				if (strtolower($item->getName()) != "item") continue;

				// TODO: test this thoroughly
				try
				{
					if ($cn == "add")
					{
						$newid = $this->backends[$target]["backend"]->saveSyncMLItem(null, strval($item->Data));
						if ($newid !== false)
						{
							$map[] = array("target" => $item->Source->LocURI, "source" => $newid);
							$itemstatus .= '<Item><Source><LocURI>'.$item->Source->LocURI.'</LocURI></Source></Item>';

							// Notify the backend of the new item
							$this->backends[$target]["backend"]->notifySyncMLEvent(dSyncMLClient::EVENT_SYNCITEMRECEIVED, $newid, $this->backends[$target]["next"]);

							// Add it to our statistics
							$this->statistics["received_adds"]++;
						}
						else
						{
							$this->logError("Could not add item to backend '$target' (saveSyncMLItem returned false)");
							$retcode = 506;
							break;
						}
					}
					if ($cn == "replace")
					{
						$nid = $this->backends[$target]["backend"]->saveSyncMLItem(strval($item->Target->LocURI), strval($item->Data));
						if ($nid !== false)
						{
							// Notify the backend of the new item
							$this->backends[$target]["backend"]->notifySyncMLEvent(dSyncMLClient::EVENT_SYNCITEMRECEIVED, $nid, $this->backends[$target]["next"]);

							// Add it to our statistics
							$this->statistics["received_updates"]++;
						}
						else
						{
							$this->logError("Could not replace item '".strval($item->Target->LocURI)."' in backend '$target' (saveSyncMLItem returned false)");
							$retcode = 506;
							break;
						}
					}
					if ($cn == "delete")
					{
						$ret = $this->backends[$target]["backend"]->deleteSyncMLItem(strval($item->Target->LocURI));
						if ($ret)
						{
							// Notify the backend of the deleted item
							$this->backends[$target]["backend"]->notifySyncMLEvent(dSyncMLClient::EVENT_SYNCITEMDELETE, strval($item->Target->LocURI), $this->backends[$target]["next"]);

							// Add it to our statistics
							$this->statistics["received_deletes"]++;

						}
						else
						{
							$this->logError("Could not delete item '".strval($item->Target->LocURI)."' from backend '$target' (deleteSyncMLItem returned false)");
							$retcode = 506;
							break;
						}
					}

					$itemcount++;
				}
				catch (Exception $ex)
				{
					$this->logError("Exception occured while processing the received sync command '$cn' with CmdID '".$child->CmdID."', item (source: '".$item->Source->LocURI."', target: '".$item->Target->LocURI."'): ".$ex->getMessage());
				}
			}

			// Finalize the status command
			$status .= '<Data>'.$retcode.'</Data>';
			$status .= $itemstatus;
			$status .= '</Status>';
			$this->addCommand($status);
		}

		// Send the ids of the newly created items back to the server in a MAP command
		if (count($map))
		{
			$mc = '<Map>';
			$mc .= '<Target><LocURI>'.$cmd->Source->LocURI.'</LocURI></Target>';
			$mc .= '<Source><LocURI>'.$cmd->Target->LocURI.'</LocURI></Source>';
			foreach ($map as $m)
			{
				$mc .= '<MapItem>';
				$mc .= '<Target><LocURI>'.$m["target"].'</LocURI></Target>';
				$mc .= '<Source><LocURI>'.$m["source"].'</LocURI></Source>';
				$mc .= '</MapItem>';
			}
			$mc .= '</Map>';
			$this->addCommand($mc);
		}

		// At this point, we might be done with the synchronization of this backend. Notify it. Beware: more packages might come!
		$this->backends[$target]["backend"]->notifySyncMLEvent(dSyncMLClient::EVENT_SYNCDONE, null, $this->backends[$target]["next"]);

		$this->logMessage("Done processing data package for backend '$target' from server ($itemcount items were included).");
	}

	/**
	 * The server wants to know our capabilities!
	 */
	protected function processGet (SimpleXMLElement $cmd)
	{
		// Check whether it is the correct devinf
		if (!preg_match("~devinf1~i", $cmd->Item->Target->LocURI))
		{
			$this->logWarning("Server requested get on unsupported ressource '".$cmd->Item->Target->LocURI."'");

			$status = '<Status>';
			$status .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
			$status .= '<CmdRef>'.$cmd->CmdID.'</CmdRef>';
			$status .= '<Cmd>'.$cmd->getName().'</Cmd>';
			$status .= '<TargetRef>'.$cmd->Item->Target->LocURI.'</TargetRef>';
			$status .= '<Data>404</Data>';
			$status .= '</Status>';
			$this->addCommand($status);

			return;
		}

		// Send the status
		$status = '<Status>';
		$status .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
		$status .= '<CmdRef>'.$cmd->CmdID.'</CmdRef>';
		$status .= '<Cmd>'.$cmd->getName().'</Cmd>';
		$status .= '<TargetRef>'.$cmd->Item->Target->LocURI.'</TargetRef>';
		$status .= '<Data>200</Data>';
		$status .= '</Status>';
		$this->addCommand($status);


		// Create the device informations XML
		$res = '<Results>';
		$res .= '<MsgRef>'.$this->receivedMsgID.'</MsgRef>';
		$res .= '<CmdRef>'.$cmd->CmdID.'</CmdRef>';
		$res .= '<TargetRef>'.$cmd->Item->Target->LocURI.'</TargetRef>';
		$res .= '<Meta><Type>application/vnd.syncml-devinf+xml</Type></Meta>';
		$res .= '<Item>';
		$res .= '<Source><LocURI>'.$cmd->Item->Target->LocURI.'</LocURI></Source>';
		$res .= '<Data>';
		$res .= $this->createDeviceInformationXML();
		$res .= '</Data>';
		$res .= '</Item>';
		$res .= '</Results>';
		$this->addCommand($res);

		$this->logMessage("Sending device capabilities to server as requested.");
	}

	// HELPERS ////////////////////////////////////////////////////////////////////////////////////

	protected function logMessage ($message)
	{
		$this->log[] = array("type" => "message", "text" => $message, "timestamp" => time());
	}

	protected function logWarning ($message)
	{
		$this->log[] = array("type" => "warning", "text" => $message, "timestamp" => time());
		$this->statistics["warnings"]++;
	}

	protected function logError ($message)
	{
		$this->log[] = array("type" => "error", "text" => $message, "timestamp" => time());
		$this->statistics["errors"]++;
	}

	protected function setServerURL ($serverurl)
	{
		// Parse the server URL
		$info = parse_url($serverurl);
		if (!$info)
			throw new Exception("dSyncMLClient constructor: the given server URL '$serverurl' is invalid. Give something like 'http://funambol.com/ds' or the like.");
		$this->serverURL = $serverurl;
		if (!$this->targetURL) $this->targetURL = $serverurl;

		$this->serverHost = $info["host"];
		$this->serverPath = $info["path"];
		$this->serverPort = isset($info["port"]) ? $info["port"] : null;
		if (!$this->serverPort)
		{
			if ($info["scheme"] == "https")
				$this->serverPort = 443;
			else
				$this->serverPort = 80;
		}
		if (!$this->serverPath)
			$this->serverPath = "/";
	}

	// Returns a microsecond timestamp as string
	protected function getTimestamp ()
	{
		$mt = explode(" ", microtime());
		return $mt[1].floor($mt[0]*1000);
	}

	// Cuts the milliseconds from a millisecond timestamp, creating a unix timestamp
	protected function toUnixTimestamp ($mst)
	{
		if (strlen($mst) > 10) return substr($mst, 0, -3);
		return $mst;
	}

	// Creates the device capabilities description XML as a string
	protected function createDeviceInformationXML ()
	{
		$res = '<DevInf>';
		$res .= '<VerDTD>1.2</VerDTD>';
		$res .= '<Man>'.$this->manufacturer.'</Man>';
		$res .= '<SwV>'.$this->version.'</SwV>';
		$res .= '<DevID>'.$this->deviceID.'</DevID>';
		$res .= '<DevTyp>server</DevTyp>';

		// Give each backend the chance to include its datastore
		foreach ($this->backends as $name => $backend)
		{
			// Get the class name, the classes meta data and its capabilities
			$classname = $backend["backend"]->getSyncMLItemClass();
			$elementmeta = call_user_func(array($classname, "GetSyncMLMeta"));
			$caps = call_user_func(array($classname, "GetSyncMLCapabilities"));

			// The usual information
			$res .= '<DataStore>';
			$res .= '<SourceRef>'.$name.'</SourceRef>';
			$res .= '<Rx-Pref><CTType>'.$elementmeta["mimetype"].'</CTType><VerCT>'.$elementmeta["version"].'</VerCT></Rx-Pref>';
			$res .= '<Tx-Pref><CTType>'.$elementmeta["mimetype"].'</CTType><VerCT>'.$elementmeta["version"].'</VerCT></Tx-Pref>';

			// If there are capabilities, print each of them
			if (is_array($caps) && count($caps))
			{
				$res .= '<CTCap>';
				$res .= '<CTType>'.$elementmeta["mimetype"].'</CTType><VerCT>'.$elementmeta["version"].'</VerCT>';
				foreach ($caps as $cap)
				{
					$res .= '<Property><PropName>'.$cap["name"].'</PropName>';

					// Append enum properties
					if (isset($cap["enum"]))
					{
						if (is_array($cap["enum"]))
						{
							foreach ($cap["enum"] as $enum)
								$res .= '<ValEnum>'.$enum.'</ValEnum>';
						}
						elseif (is_string($cap["enum"]))
							$res .= '<ValEnum>'.$cap["enum"].'</ValEnum>';
					}

					// Append parameters
					if (isset($cap["params"]))
					{
						if (is_array($cap["params"]))
						{
							foreach ($cap["params"] as $p)
								$res .= '<PropParam><ParamName>'.$p.'</ParamName></PropParam>';
						}
						elseif (is_string($cap["params"]))
							$res .= '<PropParam><ParamName>'.$cap["params"].'</ParamName></PropParam>';
					}

					$res .= '</Property>';
				}
				$res .= '</CTCap>';
			}

			// Finalize the data store
			$res .= '<SyncCap><SyncType>2</SyncType><SyncType>1</SyncType><SyncType>6</SyncType><SyncType>4</SyncType></SyncCap>';
			$res .= '</DataStore>';
		}

		// Finalize the device informations xml
		$res .= '</DevInf>';

		return $res;
	}
}

/**
 * Exception thrown when the login is wrong
 */
class dSyncMLClientAuthenticationException extends Exception
{

}