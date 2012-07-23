<?php

/**
 * dHTTP.php
 * Eine Klasse, die HTTP Requests darstellt. Basiert auf GuinuX Advanced HTTP Client.
 *
 * @author Steffen Müller
 * @version 2.0
 *
 * Versioning Information:
 *   Last change in repository: $Date: 2007-09-05 12:10:57 +0200 (Mi, 05 Sep 2007) $
 *   Last change in revision: $Revision: 362 $
 *   Last changing author: $Author: Sam $
 *
 */

class dHTTP
{
	private $rawdata = false;
	private $fdata;
	private $host;
	private $port;
	private $timeout;
	private $referer = "dFrame";
	private $cookie = "";
	private $headers = array();
	private $requestheaders = array();
	private $body = "";
	private $verb = "POST";
	private $nobody = false;
	private $autocontentheader = true;
	private $possible_redirects = 4;

	private $debug = false;
	private $debugRequest = false;

	private $rawfilename = false;
	private $rawfilepre = false;
	private $rawfilepost = false;

	public function __construct ($host, $port=80, $timeout=30)
	{
		$this->host = $host;
		$this->port = $port;
		$this->timeout = $timeout;
	}

	public function setVerb ($verb)
	{
		if (!preg_match("/^\w+$/", $verb))
			throw new Exception(LABEL("dhttp.msg_invalidverb", dProtect($verb)));
		$this->verb = strtoupper($verb);

		if ($this->verb == "HEAD")
			$this->nobody = true;
		else
			$this->nobody = false;
	}

	public function setCookie ($cookie)
	{
		$this->cookie = $cookie;
	}

	public function setData (&$data)
	{
		$this->rdata = $data;
	}

	public function setDebug ($onoff)
	{
		$this->debug = $onoff;
	}

	public function getSentRequest ()
	{
		return $this->debugRequest;
	}

	/**
	 * Sets the raw data of the content body. Overwrites setData, addFile and addFileString.
	 * @param $data
	 */
	public function setRawData ($data)
	{
		$this->rawdata = $data;
	}

	/**
	 * Sets the raw data of the content body to be read out of the given file.
	 * Overwrites setData, addFile and addFileString.
	 * @param $data
	 */
	public function setRawDataFile ($fp)
	{
		$this->rawdata = "";
		while (!feof($fp))
			$this->rawdata .= fread($fp, 8192);
	}

	public function streamRawFile ($filename, $prebody=false, $postbody=false)
	{
		$this->rawfilename = $filename;
		$this->rawfilepre = $prebody;
		$this->rawfilepost = $postbody;
	}

	public function addFileString ($fieldname, $filename, &$data)
	{
		$this->fdata[$filename] = array("filename" => $filename, "data" => $data);
	}

	public function addFile ($fieldname, $filename)
	{
		if (!is_file($filename)) return;
		$this->fdata[$fieldname] = array("filename" => basename($filename), "data" => file_get_contents($filename));
	}

	public function setHeader ($name, $value)
	{
		$this->requestheaders[$name] = $value;
	}

	public function disableAutoContentType ()
	{
		$this->autocontentheader = false;
	}

	private function streamRequest ($fp, $path)
	{
		// Decide the length of the request
		if ($this->rawfilename !== false)
			$clength += filesize($this->rawfilename)+strlen($this->rawfilepre)+strlen($this->rawfilepost);
		else
			$clength = strlen($this->rawdata);

		// Daten senden, Daten holen, schließen. Dabei ständig auf Fehler prüfen.
		$success = true;
		$success = fwrite($fp, "{$this->verb} $path HTTP/1.0\r\n") && $success;
		$success = fwrite($fp, "Content-length: ".$clength."\r\n") && $success;
		if ($this->cookie) $success = fwrite($fp, "Cookie: {$this->cookie}\r\n") && $success;
		foreach ($this->requestheaders as $key => $val)
			$success = fwrite($fp, "$key: $val\r\n") && $success;
		$success = fwrite($fp, "Connection: close\r\n\r\n") && $success;
		if (!$this->nobody)
		{
			if ($this->rawfilename !== false)
			{
				// Print pre, then stream file in chunks, then print post.
				if ($this->rawfilepre)
					$success = (fwrite($fp, $this->rawfilepre)!==false) && $success;

				$rfp = fopen($this->rawfilename, "rb");
				if ($rfp)
				{
					while ($success && !feof($rfp))
						$success = (fwrite($fp, fread($rfp, 8192))!==false) && $success;
					fclose($rfp);
				}

				if ($this->rawfilepost)
					$success = (fwrite($fp, $this->rawfilepost)!==false) && $success;
			}
			else
				$success = (fwrite($fp, $this->rawdata)!==false) && $success;
		}

		// Ging beim schreiben etwas schief?
		if (!$success)
			throw new Exception("An error occured while writing the request for {$this->host}$path");
	}

	public function send ($path)
	{
		$boundary = "DFRAMEFIELDBOUNDARY14032302";

		// Datastring zusammensetzen
		if ($this->rawfilename === false && $this->rawdata === false && !$this->nobody)
		{
			if ($this->autocontentheader && !$this->requestheaders["Content-Type"])
				$this->requestheaders["Content-Type"] =  "multipart/form-data; boundary=$boundary";
			$this->rawdata = "";
			foreach ($this->rdata as $key => &$value)
				$this->rawdata .= "--".$boundary."\r\nContent-Disposition: form-data; name=\"$key\"\r\n\r\n".$value."\r\n";
			foreach ($this->fdata as $key => &$value)
				$this->rawdata .= "--".$boundary."\r\nContent-Disposition: form-data; name=\"$key\"; filename=\"".$value['filename']."\"\r\nContent-Type: application/octet-stream\r\n\r\n".$value['data']."\r\n";
			if (strlen($this->rawdata)) $this->rawdata .= "--".$boundary."--";
		}

		// Header bestimmen
		if (!isset($this->requestheaders["Host"]))
			$this->requestheaders["Host"] = preg_replace("!^ssl://!", "", $this->host);
		if (!isset($this->requestheaders["User-Agent"]))
			$this->requestheaders["User-Agent"] = "Mozilla 4.0";


		// Debug request schreiben?
		if ($this->debug)
		{
			$tpath = dFrame::GetTemporaryPath("dhttp", ".txt");
			$fp = fopen($tpath, "w");
			if ($fp)
			{
				$this->streamRequest($fp, $path);
				fclose($fp);
				$this->debugRequest = file_get_contents($tpath);
				dFS::unlink($tpath);
			}
		}

		// Socket öffnen und Request senden
		$fp = fsockopen($this->host,$this->port,$errno,$errstr,$this->timeout);
		if (!$fp) throw new Exception("$host ($errno): $errstr");
		$this->streamRequest($fp, $path);

		// Antwort sammeln
		$res = "";
		while(!feof($fp))
		    $res .= fgets($fp, 1024);
		fclose($fp);

		// Auswerten
		$chunks = preg_split("/\r?\n\r?\n/", $res, 2);
		if (count($chunks) != 2) throw new Exception("Invalid answer from {$this->host}$path: ".$res);
		$headerlines = preg_split("/\r?\n/", $chunks[0]);
		$headers = array();
		foreach ($headerlines as $headerline)
		{
			if (!preg_match("/^([^:]+):\s*(.*)/", $headerline, $ms)) continue;
			$val = $ms[2];
			preg_match_all("/=\\?([\w-]+)\\?(\w)\\?(.*)\\?=/U", $val, $matches);
			for ($i = 0; $i < count($matches[0]); $i++)
			{
				$original = $matches[0][$i];
				$charset = strtolower($matches[1][$i]);
				$encoding = strtolower($matches[2][$i]);
				$text = $matches[3][$i];
				if ($encoding == "q")
					$text = quoted_printable_decode(str_replace("_", " ", $text));
				else if ($encoding == "b")
					$text = base64_decode($text);
				if ($charset == "iso-8859-1")
					$text = utf8_encode($text);
				$val = str_replace($original, $text, $val);
			}
			$headers[strtolower($ms[1])] = $val;
		}
		$this->headers = &$headers;
		$this->body = $chunks[1];

		$status = false;
		if (preg_match("/^HTTP\/[\d\.]+\s*(\d+)/", $res, $m)) $status = $m[1];

		if ($status == 307)
		{
			$this->possible_redirects--;
			if ($this->possible_redirects <= 0)
				throw new Exception(LABEL("dhttp.msg_toomanyredirects"));

			$location = $this->headers["location"];
			$urlinfo = parse_url($location);
			if (!$urlinfo) throw new Exception(LABEL("dhttp.msg_invalidredirect"));
			if ($urlinfo["scheme"] == "https")
				$this->host = "ssl://".$urlinfo["host"];
			else
				$this->host = $urlinfo["host"];
			if (is_numeric($urlinfo["port"]))
				$this->port = $urlinfo["port"];

			return $this->send($urlinfo["path"]);
		}

		return $status;
	}

	public function getHeader ($name)
	{
		return $this->headers[strtolower($name)];
	}

	public function getHeaders ()
	{
		return $this->headers;
	}

	public function &getBody ()
	{
		return $this->body;
	}
}

?>