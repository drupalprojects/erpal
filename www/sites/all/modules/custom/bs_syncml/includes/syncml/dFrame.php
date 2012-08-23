<?php

// Used in GetTemporaryPath in this stub - set to whatever
$TEMP_PATH = ".";

/**
 * Erzeugt einen extrem zufälligen Schlüssel aus Großbuchstaben, Kleinbuchstaben und Zahlen.
 * @param int $count Optional. Anzahl Stellen, die der Schlüssel lang sein soll. Standard ist 24.
 * @return string Der zufällige Schlüssel
 */
function dCreateUniqueKey ($count=24)
{
	$out = "";
	for ($i = 0; $i < $count; $i++)
	{
		$rnd = rand(0,61);
		if ($rnd <= 25) $out .= chr(65+$rnd);
		else if ($rnd <= 51) $out .= chr(71+$rnd);
		else $out .= ($rnd-52);
	}
	return $out;
}

class dFrame
{
	/**
	 * Returns a writable file path for a temporary file that is guaranteed to be free at the moment.
	 * @param $prefix A prefix for the temporary file name
	 * @return string An absolute file path that can be used to write a temporary file.
	 */
	public static function GetTemporaryPath ($prefix=false)
	{
		global $TEMP_PATH;
		if (!$prefix) $prefix = "tmp";
		$prefix = preg_replace("~[^a-z0-9]_~", "", strtolower($prefix));
		$tries = 64;
		while ($tries > 0)
		{
			$path = $TEMP_PATH.$prefix."_".dCreateUniqueKey();
			if (!is_file($path)) return $path;
			$tries--;
		}
		throw new Exception("Could not create temporary file pathname in 64 tries. Aborting.");
	}
}

class dFS
{
	public static function unlink ($file)
	{
		return @unlink($file);
	}
}

class dString
{
	/**
	 * Checks whether the given string is valid utf-8. If the second parameter
	 * is given, only the first $probe bytes will be checked
	 * @param $str The string.
	 * @param $probe Optional. If set, only the first $probe bytes will be checked.
	 * @return boolean true or false.
	 */
	public static function IsUTF8 ($str, $probe=false)
	{

		$strlen = strlen($str);
		if (!is_numeric($probe) || $probe < 1)
			$length = $strlen;
		else
			$length = $probe;

		for ($i = 0; $i < $length; $i++)
		{
			// Check each byte
			$c = ord($str[$i]);
			if ($c < 0x80) $n = 0; # 0bbbbbbb
			elseif (($c & 0xE0) == 0xC0) $n=1; # 110bbbbb
			elseif (($c & 0xF0) == 0xE0) $n=2; # 1110bbbb
			elseif (($c & 0xF8) == 0xF0) $n=3; # 11110bbb
			elseif (($c & 0xFC) == 0xF8) $n=4; # 111110bb
			elseif (($c & 0xFE) == 0xFC) $n=5; # 1111110b
			else
				return false; // Does not match any sort of utf8 scheme

			// Matched a utf8 scheme - do enough bytes follow as explained?
			for ($j=0; $j<$n; $j++)
			{
				if ((++$i >= $strlen) || ((ord($str[$i]) & 0xC0) != 0x80))
					return false;
			}
		}
		return true;
	}

	/**
	 * Takes either an UTF-8 or an ISO-8859-1 string and returns the string
	 * UTF-8 encoded.
	 * @param $str
	 * @return string as described above
	 */
	public static function GetUTF8 ($str)
	{
		if (dString::IsUTF8($str))
			return $str;
		return utf8_encode($str);
	}
}