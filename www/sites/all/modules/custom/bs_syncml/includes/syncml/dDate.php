<?php
/**
 * dDate.php
 * Die Mutterklasse der Datumsverarbeitung.
 *
 * @author Steffen Müller
 * @version 1.0
 *
 * Versioning Information:
 *   Last change in repository: $Date: 2007-09-05 12:10:57 +0200 (Mi, 05 Sep 2007) $
 *   Last change in revision: $Revision: 362 $
 *   Last changing author: $Author: Sam $
 *
 */

class dDate
{
	const DAY_MONDAY = 1;
	const DAY_TUESDAY = 2;
	const DAY_WEDNESDAY = 3;
	const DAY_THURSDAY = 4;
	const DAY_FRIDAY = 5;
	const DAY_SATURDAY = 6;
	const DAY_SUNDAY = 0;

	private static $dayMap = array(0 => "sunday", 1 => "monday", 2 => "tuesday", 3 => "wednesday", 4 => "thursday", 5 => "friday", 6 => "saturday");
	private static $timezoneSet = false;
	private static $defaultTimezone = "Europe/Berlin";

	private $stamp = false;

	/**
	 * Creates a new dDate object using the given date information. $date may be:
	 * - false for using NOW
	 * - a SQL timestamp (like YYYY-MM-DD HH:MM:SS)
	 * - an unix timestamp (numeric)
	 * - a date in localized style (resolved via dLocale)
	 * @param $date mixed The date information as described above
	 */
	public function __construct ($date=false)
	{
		// Set the timezone on first date usage
		if (!dDate::$timezoneSet)
		{
			dDate::$timezoneSet = true;
			date_default_timezone_set(dDate::$defaultTimezone);
		}

		// Now
		if ($date === false)
			$this->stamp = time();
		// Unix timestamp
		elseif (is_numeric($date))
			$this->stamp = $date;
		// SQL timestamp
		elseif (preg_match("/^\s*(\d{2}|\d{4})\-(\d{1,2})\-(\d{1,2})\s*((\d{1,2}):(\d{1,2})(:(\d{1,2}))?)?/", $date, $matches))
		{
			if (preg_match("~^0000-00-00\s*00:00:00$~", $date))
				$this->stamp = false;
			else
			{
				$day = isset($matches[3]) ? intval($matches[3]) : 0;
				$month = isset($matches[2]) ? intval($matches[2]) : 0;
				$year = isset($matches[1]) ? intval($matches[1]) : 0;
				$hour = isset($matches[5]) ? intval($matches[5]) : 0;
				$min = isset($matches[6]) ? intval($matches[6]) : 0;
				$sec = isset($matches[8]) ? intval($matches[8]) : 0;
				if ($year < 100)
				{
					if ($year < 70)
						$year += 2000;
					else
						$year += 1900;
				}
				$this->stamp = mktime($hour, $min, $sec, $month, $day, $year);
			}
		}
		// Locale
		else
		{
			$loc = dFrame::GetLocale();
			$this->stamp = $loc->parseDate($date);
		}
	}

	public function __toString ()
	{
		if (!$this->isValid()) return "-";
		return $this->sqlStamp();
	}

	// OUTPUT /////////////////////////////////////////////////////////////////////////////////////

	public function isValid ()
	{
		return $this->stamp !== false;
	}

	public function makeInvalid ()
	{
		$this->stamp = false;
	}

	public function stamp ()
	{
		return $this->stamp;
	}

	public function sqlStamp ()
	{
		return date("Y-m-d H:i:s", $this->stamp);
	}

	public function dayNumber ()
	{
		$val = intval(mktime (12, 0, 0, date("m", $this->stamp), date("d", $this->stamp), date("Y", $this->stamp))/86400);
		return $val+719528;
	}

	public function monthNumber ()
	{
		return intval(date("Y", $this->stamp))*12 +  intval(date("n", $this->stamp)) - 1;
	}

	public function year ()
	{
		return intval(date("Y", $this->stamp));
	}

	public function month ()
	{
		return intval(date("m", $this->stamp));
	}

	/** Returns the day of the month. **/
	public function day ()
	{
		return intval(date("d", $this->stamp));
	}

	public function date ($withtime=false)
	{
		$d = date("d.m.Y", $this->stamp);
		if ($withtime && $this->hasTime())
			$d .= " ".$this->time();
		return $d;
	}

	public function isoDate ()
	{
		return date("Y-m-d", $this->stamp);
	}

	public function time ($seconds=false)
	{
		return date("H:i", $this->stamp);
	}

	public function monthLabel ()
	{
		return LABEL("calendar.month_".intval(date("m", $this->stamp)));
	}

	public function dayLabel ()
	{
		return LABEL("calendar.day_".intval(date("w", $this->stamp)));
	}

	public function dayMonthLabel()
	{
		return date("d.m.", $this->stamp);
	}

	/** Returns the day index in the year. Formula: dayofmonth + 31*month. **/
	public function dayYearIndex ()
	{
		return $this->day() + 31*$this->month();
	}

	// ATTRIBUTES /////////////////////////////////////////////////////////////////////////////////

	/**
	 * Returns a boolean indicating whether the given year is a leap year.
	 * @return bool
	 */
	public function isLeapYear ()
	{
		return (1==date('L', $this->stamp));
	}

	/**
	 * Returns the total number of days in the given month.
	 * @return int An integer between 28 and 31, inclusive.
	 */
	public function getNumberOfDaysInMonth ()
	{
		return intval(date('t', $this->stamp));
	}

	/**
	 * Returns the index of the day from 0-6 (equal to the dDate::DAY_* constants).
	 * @return int
	 */
	public function getDayIndex ()
	{
		return date("w", $this->stamp);
	}

	/**
	 * Returns the week number in the year of this date.
	 * @return int
	 */
	public function getWeekNumber ()
	{
		return intval(date("W", $this->stamp));
	}

	/**
	 * Returns the total number of weeks in the year.
	 * @return int
	 */
	public function getNumberOfWeeksInYear ()
	{
		$d = new dDate(mktime(0,0,0,12,31,date("Y", $this->stamp)));
		$wn = $d->getWeekNumber();
		if ($wn < 50) return 53;
		return $wn;
	}

	/**
	 * Gets the number of seconds ellapsed since midnight at the current day.
	 * @return int
	 */
	public function getDaySeconds ()
	{
		return intval(date("H", $this->stamp))*3600 + intval(date("i", $this->stamp))*60 + intval(date("s", $this->stamp));
	}

	public function hasTime ()
	{
		return ($this->getDaySeconds() > 0);
	}

	public function isToday ()
	{
		return (date("dmY")==date("dmY", $this->stamp));
	}

	public function isFuture ()
	{
		return ($this->stamp > time());
	}

	// MODIFIERS //////////////////////////////////////////////////////////////////////////////////

	public function maxTime ()
	{
		$this->stamp = mktime(23,59,59,date("m", $this->stamp), date("d", $this->stamp), date("Y", $this->stamp));
	}

	public function add ($unit, $factor=1)
	{
		if (!in_array($unit, array("week","month","year","day"))) return false;
		$this->stamp = strtotime("+$factor $unit", $this->stamp);
		return true;
	}

	// RELATIONS (these create and return other dDates) ///////////////////////////////////////////

	public function getStartOfMonth ()
	{
		return new dDate(mktime(0,0,0,date("m", $this->stamp), 1, date("Y", $this->stamp)));
	}

	public function getEndOfMonth ()
	{
		return new dDate(mktime(23,59,59,date("m", $this->stamp), $this->getNumberOfDaysInMonth(), date("Y", $this->stamp)));
	}


	public function getNext ($day, $factor=1)
	{
		$n = $this->getDayName($day);
		if (!$n) return false;
		return new dDate(strtotime("+$factor $n", $this->stamp));
	}

	public function copy ()
	{
		return new dDate($this->stamp);
	}

	// STATIC GENERATION //////////////////////////////////////////////////////////////////////////

	public static function CreateMonth ($month=false, $year=false)
	{
		return new dDate (mktime(0, 0, 0, $month, 1, $year));
	}

	public static function CreateYear ($year=false)
	{
		return new dDate (mktime(0, 0, 0, 1, 1, $year));
	}

	public static function CreateDayNumber ($nr)
	{
		$stamp = ($nr-719528)*86400;
		return new dDate (mktime(0, 0, 0, date("m", $stamp), date("d", $stamp), date("Y", $stamp)));
	}

	public static function CreateMonthNumber ($nr)
	{
		$y = intval($nr / 12);
		$m = ($nr % 12) + 1;
		return new dDate (mktime(0, 0, 0, $m, 1, $y));
	}

	public static function CreateYearWeek ($year, $nr)
	{
		$fm = dDate::GetFirstYearWeekMonday($year);
		$m = date('m', $fm);
		$y = date('Y', $fm);
		$d = date('d', $fm);
		$st = mktime(0, 0, 0, $m, $d+($nr-1)*7, $y);
		return new dDate($st);
	}

	// HELPERS ////////////////////////////////////////////////////////////////////////////////////
	private static function GetFirstYearWeekMonday ($year)
	{
		$first = mktime(0, 0, 0, 1, 1, $year);
		$wt = date('w', $first);
		if ($wt <= 4)
			return mktime(0, 0, 0, 1, 2-$wt, $year);
		elseif ($wt != 1)
			return mktime(0, 0, 0, 1, 9-$wt, $year);
		else
			return $first;
	}

	private function getDayName ($c)
	{
		if (isset(dDate::$dayMap[$c]))
			return dDate::$dayMap[$c];
		else
			return false;
	}
}

?>