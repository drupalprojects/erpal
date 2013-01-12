<?php
/**
 * dVCard.php - Einfache, unabhängige Klasse, um mit dem vCard Format umgehen zu können.
 *
 * @author Steffen Müller
 * @version 1.0
 */

// Die Klasse /////////////////////////////////////////////////////////////////////////////////////
class dVCard implements dISyncMLItem
{
	// Unique fields that are parsed from vcards. Maps them on a output array key.
	protected static $MAP = array
	(
		"uid" => "id",
		"fn" => "displayname",
		"title" => "position",
		"bday" => "birthday",
		"nickname" => "nickname",
		"role" => "jobtitle",
		"note" => "note",
		"photo" => "photo"
	);

	// Implicitly contained in the map via special properties. Just for reference.
	protected static $IMPLICIT_MAP = array
	(
		"firstname",
		"lastname",
		"middlename",
		"title",
		"company",
		"department"
	);

	// Properties in addresses (plus "id")
	protected static $ADDRESS_MAP = array
	(
		"street",
		"street2",
		"postalbox",
		"zipcode",
		"city",
		"region",
		"country"
	);

	// The addresses
	protected $addresses;

	// The communications
	protected $comm;

	// The unique variables
	protected $vars;

	// The categories
	protected $categories;

	// PUBLIC STUFF ///////////////////////////////////////////////////////////////////////////////

	/**
	 * Constructs a new vcard
	 * @param $data Mixed Optional. If a string is given, it is parsed as a vcard. Arrays are loaded via loadArray.
	 */
	public function __construct ($data=false)
	{
		$this->vars = array();
		$this->addresses = array();
		$this->comm = array();
		$this->categories = array();

		// Load
		if (is_array($data))
			$this->loadArray($data);
		elseif (is_string($data))
			$this->loadVCard($data);
	}

	/**
	 * Returns the unique properties of the vCard.
	 * See loadArray for further explanation.
	 * @return array
	 */
	public function getProperties ()
	{
		return $this->vars;
	}

	/**
	 * Returns the addresses of the vCard.
	 * See addAddress for further explanation.
	 * @return array Array containing the addresses as arrays
	 */
	public function getAddresses ()
	{
		return $this->addresses;
	}

	/**
	 * Returns the communication channels (phone etc.) of the vCard.
	 * See addCommunication for further explanation.
	 * @return array Array containing communication entries as arrays
	 */
	public function getCommunications ()
	{
		return $this->comm;
	}

	/**
	 * Returns an array containing the categories this vCard is in.
	 * @return array Array containing strings
	 */
	public function getCategories ()
	{
		return $this->categories;
	}

	// ARRAY AND ADDRESS LOADER ///////////////////////////////////////////////////////////////////

	/**
	 * Loads the unique core data for the vCard (fields that cannot be repeated).
	 * @param $data Array An array containing any of the keys as seen in dVCard::$MAP and dVCard::$IMPLICIT_MAP
	 * @return void
	 */
	public function loadArray ($data)
	{
		$rd = array();
		foreach ($data as $key => $val)
		{
			if (!in_array($key, dVCard::$MAP) && !in_array($key, dVCard::$IMPLICIT_MAP))
				continue;
			$rd[strtolower($key)] = $val;
		}
		$this->vars = $rd;
	}

	/**
	 * Adds an address to the vCard.
	 * @param $data Array Array containing the keys as in dVCard::$ADDRESS_MAP
	 * @param $labels Mixed Optional. Array of labels for the address: pref, home, work. If only one label, can be given as string.
	 * @return boolean True on success, false on failure
	 */
	public function addAddress ($data, $labels=false)
	{
		if (!is_array($data)) return false;

		// Check the labels
		if (is_string($labels))
			$labels = array($labels);
		if (!is_array($labels))
			$labels = array();
		foreach ($labels as &$l)
		{
			$l = strtolower($l);
			if (!in_array($l, array("pref", "home", "work")))
				return false;
		}

		// Construct the address
		$rd = array("labels" => $labels);
		foreach ($data as $key => $val)
		{
			if (!in_array($key, dVCard::$ADDRESS_MAP))
				continue;
			$rd[strtolower($key)] = $val;
		}
		$this->addresses[] = $rd;

		return true;
	}

	/**
	 * Adds a communication channel (phone etc.) to the vCard.
	 * @param $type String The type of the comm: phone, email, url, fax, cellphone.
	 * @param $labels Mixed An array of labels for the comm: pref, home, work. If only one label, can be given as string.
	 * @param $value The value of the comm.
	 * @return boolean True on success, false on wrong input (check the first two parameters)
	 */
	public function addCommunication ($type, $labels, $value)
	{
		// Check value
		if (!$value)
			return false;

		// Check type
		$type = strtolower($type);
		if (!in_array($type, array("phone", "email", "url", "fax", "cellphone")))
			return false;

		// Check labels
		if (is_string($labels))
			$labels = array($labels);
		if (!is_array($labels))
			$labels = array();
		foreach ($labels as &$l)
		{
			$l = strtolower($l);
			if (!in_array($l, array("pref", "home", "work")))
				return false;
		}

		// Search for the value
		foreach ($this->comm as &$c)
		{
			if ($c["value"] == $value)
			{
				$c["labels"] = array_merge($c["labels"], $labels);
				return true;
			}
		}

		// Add it
		$this->comm[] = array("type" => $type, "labels" => $labels, "value" => $value);
		return true;
	}

	/**
	 * Adds a category or some categories to the vCard
	 * @param $cat Mixed The category to add, a string not containing a comma. If an array is passed, all array elements are added as categories.
	 * @return void
	 */
	public function addCategories ($cat)
	{
		if (is_string($cat))
			$cat = array($cat);
		if (!is_array($cat))
			return;

		foreach ($cat as $c)
		{
			$c = str_replace(",", " ", trim($c));
			if (!in_array($c, $this->categories))
				$this->categories[] = $c;
		}
	}

	// VCARD PARSER ///////////////////////////////////////////////////////////////////////////////

	/**
	 * Parses the first vCard it encounters in the given string and loads its contents.
	 * Throws an exception in case of no vcard found.
	 * @param $data The vCard string
	 * @return void
	 */
	public function loadVCard ($data)
	{
		if (!preg_match("~BEGIN\s*:\s*VCARD(.*)END\s*:\s*VCARD~s", $data, $m))
			throw new Exception("dVCard::loadVCard: No vCard found in input data.");

		// Parse and select the lines
		$lines = explode("\n", str_replace("\r", "", $m[1]));
		for ($i = 0; $i < count($lines); $i++)
		{
			// Unfold the lines
			if (preg_match("~^\s+~", $lines[$i]) && $i > 0)
			{
				$lines[$i-1] .= $lines[$i];
				array_splice($lines, $i, 1);
				$i--;
				continue;
			}

			// Trim and skip if empty
			$lines[$i] = trim($lines[$i]);
			if (!strlen($lines[$i]))
			{
				array_splice($lines, $i, 1);
				$i--;
				continue;
			}
		}

		$properties = array();

		// Parse each line as a property
		foreach ($lines as $line)
		{
			if (!preg_match("~^(\w+\.)?(\w+)(;[^:]+)?:(.*)$~", $line, $m)) continue;
			$prop = strtolower($m[2]);
			$value = trim($m[4]);

			$paramstrings = explode(";", $m[3]);
			$params = array("type" => array());
			foreach ($paramstrings as $param)
			{
				if (!strlen($param)) continue;
				if (preg_match("~^(\w+)=(.*)~", $param, $m))
				{
					$pn = strtolower($m[1]);
					$pv = $m[2];
				}
				else
				{
					$pv = $param;
					$pn = $this->guessParameterName($param);
				}
				if ($pn == "encoding" || $pn == "type") $pv = strtolower($pv);
				if ($pn == "type")
					$params["type"][] = $pv;
				else
					$params[$pn] = $pv;
			}

			// Apply the given encoding
			if (isset($params["encoding"]))
			{
				if ($params["encoding"] == "base64")
					$value = base64_decode($value);
				if ($params["encoding"] == "quoted-printable")
					$value = quoted_printable_decode($value);
			}

			// Assure the correct character set
			$value = dString::GetUTF8($value);

			// Process special properties
			if ($prop == "n")
			{
				$pieces = $this->explodeValue($value);
				$properties["lastname"] = $pieces[0];
				$properties["firstname"] = $pieces[1];
				$properties["middlename"] = $pieces[2];
				$properties["title"] = $pieces[3];
				continue;
			}
			if ($prop == "adr")
			{
				$labels = array();
				if (in_array("home", $params["type"]))
					$labels[] = "home";
				if (in_array("work", $params["type"]))
					$labels[] = "work";
				if (in_array("pref", $params["type"]))
					$labels[] = "pref";

				$pieces = $this->explodeValue($value);

				$addr = array
				(
					"postalbox" => $pieces[0],
					"street2" => $pieces[1],
					"street" => $pieces[2],
					"city" => $pieces[3],
					"region" => $pieces[4],
					"zipcode" => $pieces[5],
					"country" => $pieces[6]
				);
				$this->addAddress($addr, $labels);
				continue;
			}
			if ($prop == "org")
			{
				$pieces = $this->explodeValue($value);
				$properties["company"] = $pieces[0];
				$properties["department"] = $pieces[1];
				continue;
			}
			if ($prop == "tel" || $prop == "email" || $prop == "url")
			{
				// Decide upon the type of the communication
				$type = "phone";
				if ($prop == "email")
					$type = "email";
				elseif ($prop == "url")
					$type = "url";
				elseif (in_array("fax", $params["type"]))
					$type = "fax";
				elseif (in_array("cell", $params["type"]))
					$type = "cellphone";

				// Ignore certain communication types
				if (in_array("pager", $params["type"]) || in_array("bbs", $params["type"]) || in_array("modem", $params["type"]))
					continue;

				// Decide upon the labels (pref, work, home)
				$labels = array();
				if (in_array("pref", $params["type"]))
					$labels[] = "pref";
				if (in_array("work", $params["type"]))
					$labels[] = "work";
				if (in_array("home", $params["type"]))
					$labels[] = "home";

				$this->addCommunication($type, $labels, $value);
				continue;
			}
			if ($prop == "categories")
			{
				$cats = explode(",", $value);
				$this->addCategories($cats);
				continue;
			}
			if ($prop == "photo")
				continue;
			if ($prop == "bday" && !preg_match("~(^\d{8}$)|(\d{4}-\d{2}-\d{2})~", $value))
				continue;

			// Only overwrite if still empty
			elseif (isset(dVCard::$MAP[$prop]) && empty($properties[dVCard::$MAP[$prop]]))
				$properties[dVCard::$MAP[$prop]] = $value;
		}

		$this->loadArray($properties);
	}

	protected function guessParameterName ($param)
	{
		$param = strtolower($param);
		if (in_array($param, array("inline","url","cid")))
			return "value";
		if (in_array($param, array("7bit","quoted-printable","base64")))
			return "encoding";
		return "type";
	}

	protected function explodeValue ($value)
	{
		$parts = preg_split("~(?<!\\\\);~", $value);
		foreach ($parts as &$p)
			$p = str_replace("\\;", ";", $p);
		return $parts;
	}

	// VCARD CREATOR //////////////////////////////////////////////////////////////////////////////

	/**
	 * Returns a vCard string representation of this vCard. The central function.
	 * @param $iso Optional. If true, ISO-8859-1 will be used as encoding, potentially killing UTF-8 chars for the sake of more compatibility.
	 * @return string The vCard as string
	 */
	public function getVCard ($iso=false)
	{
		$vc = "BEGIN:VCARD\r\nVERSION:2.1\r\n";

		// Here we collect all properties to encode them later on
		$props = array();

		// Add the name (no condition, its mandatory!)
		$props[] = array("name" => "n", "value" => array
		(
			isset($this->vars["lastname"]) ? $this->vars["lastname"] : "",
			isset($this->vars["firstname"]) ? $this->vars["firstname"] : "",
			isset($this->vars["middlename"]) ? $this->vars["middlename"] : "",
			isset($this->vars["title"]) ? $this->vars["title"] : ""
		));

		// Add the organisation
		if (!empty($this->vars["company"]) || !empty($this->vars["department"]))
		{
			$props[] = array("name" => "org", "value" => array
			(
				isset($this->vars["company"]) ? $this->vars["company"] : "",
				isset($this->vars["department"]) ? $this->vars["department"] : ""
			));
		}

		// Add all the unique standard properties
		foreach ($this->vars as $key => $val)
		{
			$name = array_search($key, dVCard::$MAP);
			if ($name === false) continue;

			$nameparts = explode("-", $name);
			$name = array_shift($nameparts);
			$props[] = array("name" => $name, "value" => $val, "props" => $nameparts);
		}

		// Add all communication channels
		foreach ($this->comm as $comm)
		{
			$name = "tel";
			if ($comm["type"] == "url") $name = "url";
			if ($comm["type"] == "email")
			{
				$name = "email";
				$comm["labels"][] = "internet";
			}
			if ($comm["type"] == "fax")
				$comm["labels"][] = "fax";
			if ($comm["type"] == "cellphone")
				$comm["labels"][] = "cell";

			$props[] = array("name" => $name, "value" => $comm["value"], "props" => $comm["labels"]);
		}

		// Add all addresses
		foreach ($this->addresses as $addr)
		{
			$vals = array
			(
				isset($addr["postalbox"]) ? $addr["postalbox"] : "",
				isset($addr["street2"]) ? $addr["street2"] : "",
				isset($addr["street"]) ? $addr["street"] : "",
				isset($addr["city"]) ? $addr["city"] : "",
				isset($addr["region"]) ? $addr["region"] : "",
				isset($addr["zipcode"]) ? $addr["zipcode"] : "",
				isset($addr["country"]) ? $addr["country"] : ""
			);

			$props[] = array("name" => "adr", "value" => $vals, "props" => $addr["labels"]);
		}

		// Add the categories
		if (count($this->categories))
			$props[] = array("name" => "categories", "value" => implode(",", $this->categories), "props" => array());

		// The time has come: encode all the collected props
		foreach ($props as $prop)
		{
			// Assemble collection values to properly escaped strings
			if (is_array($prop["value"]))
			{
				foreach ($prop["value"] as &$p)
					$p = str_replace(";", "\\;", $p);
				unset($p);
				$v = implode(";", $prop["value"]);
			}
			else
				$v = $prop["value"];

			// Skip empty attributes
			if (!strlen($v)) continue;

			// Decode UTF-8 if necessary
			if ($iso)
				$v = utf8_decode($v);
			elseif ($prop["name"] != "bday")
				$prop["props"][] = "CHARSET=UTF-8";

			// Encode in Quoted-Printable if necessary
			$needs = false;
			$vlength = strlen($v);
			for ($i = 0; $i < $vlength; $i++)
			{
				if (ord($v{$i}) < 127 && $v{$i} != 10 && $v{$i} != 13) continue;
				$needs = true;
				break;
			}

			if ($needs)
			{
				$v = $this->encodeQuotedPrintable($v);
				$prop["props"][] = "ENCODING=QUOTED-PRINTABLE";
			}

			// Print property name and properties
			$vc .= strtoupper($prop["name"]);
			foreach ($prop["props"] as $p)
				$vc .= ";".strtoupper($p);
			$vc .= ":$v\r\n";
		}
		$vc .= "END:VCARD\r\n";
		return $vc;
	}

	protected function encodeQuotedPrintable ($v)
	{

		// If the quoted printable function exists, use it.
		if (function_exists("quoted_printable_encode"))
			$v = quoted_printable_encode($v);
		// Work around for versions < 5.3
		else
        	$v = preg_replace('/([\000-\010\013\014\016-\037\075\177-\377])/e', "'='.sprintf('%02X', ord('\\1'))", $v);

		// Encode line breaks as they are not recognised as "problematic"
		return preg_replace("~\r?\n~", "=0D=0A", $v);
    }

    // SYNCML INTERFACE ///////////////////////////////////////////////////////////////////////////

    public static function GetSyncMLMeta ()
    {
    	return array("mimetype" => "text/x-vcard", "version" => "2.1");
    }

	public static function GetSyncMLCapabilities ()
    {
    	// The core elements
    	$caps = array
    	(
    		array("name" => "BEGIN", "enum" => "VCARD"),
    		array("name" => "VERSION", "enum" => "2.1"),
    		array("name" => "N"),
    		array("name" => "ORG"),
    		array("name" => "CATEGORIES"),
    		array("name" => "BDAY"),
    		array("name" => "PHOTO"),

    		array("name" => "EMAIL", "params" => array("INTERNET")),
    		array("name" => "EMAIL", "params" => array("INTERNET", "WORK")),
    		array("name" => "EMAIL", "params" => array("INTERNET", "HOME")),
    		array("name" => "EMAIL", "params" => array("INTERNET", "WORK", "PREF")),
    		array("name" => "EMAIL", "params" => array("INTERNET", "HOME", "PREF")),

    		array("name" => "URL"),
    		array("name" => "URL", "params" => "WORK"),
    		array("name" => "URL", "params" => "HOME"),
    		array("name" => "URL", "params" => array("WORK","PREF")),
    		array("name" => "URL", "params" => array("HOME","PREF")),

    		array("name" => "ADR"),
    		array("name" => "ADR", "params" => "WORK"),
    		array("name" => "ADR", "params" => "HOME"),
    		array("name" => "ADR", "params" => array("WORK","PREF")),
    		array("name" => "ADR", "params" => array("HOME","PREF")),

    		array("name" => "TEL"),
    		array("name" => "TEL", "params" => "WORK"),
    		array("name" => "TEL", "params" => "HOME"),
    		array("name" => "TEL", "params" => array("WORK","PREF")),
    		array("name" => "TEL", "params" => array("HOME","PREF")),

    		array("name" => "TEL", "params" => array("FAX")),
    		array("name" => "TEL", "params" => array("FAX", "WORK")),
    		array("name" => "TEL", "params" => array("FAX", "HOME")),
    		array("name" => "TEL", "params" => array("FAX", "WORK", "PREF")),
    		array("name" => "TEL", "params" => array("FAX", "HOME", "PREF")),

    		array("name" => "TEL", "params" => array("CELL")),
    		array("name" => "TEL", "params" => array("CELL", "WORK")),
    		array("name" => "TEL", "params" => array("CELL", "HOME")),
    		array("name" => "TEL", "params" => array("CELL", "WORK", "PREF")),
    		array("name" => "TEL", "params" => array("CELL", "HOME", "PREF")),
    	);

    	// Add the direct mapped text properties
    	foreach (dVCard::$MAP as $k => $v)
    		$caps[] = array("name" => strtoupper($k));

    	// The end property
    	$caps[] = array("name" => "END", "enum" => "VCARD");

    	return $caps;
    }

	public function getSyncMLString ()
	{
		return $this->getVCard();
	}
}
?>