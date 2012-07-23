<?php
/**
 * dISyncMLItem.php - Interface für Klassen, die auf einem SyncML Server synchronisiert
 * werden können und ein entsprechendes Transportmedium bieten (bspw. vCards).
 *
 * @author Steffen Müller
 */

interface dISyncMLItem
{
	/**
	 * Returns the MIME type and other static information about this class of syncml
	 * items. The returned array is a hash with the following keys:
	 * - mimetype: the mimetype of the item, for example "text/x-vcard"
	 * - version: the version of the standard used, for example "2.1"
	 *
	 * @return array The hash as described above.
	 */
	public static function GetSyncMLMeta ();

	/**
	 * Returns the capabilities of this class of syncml items. Can also be false if
	 * there are no special capabilities to present. The list of capabilities is an
	 * array containing hashes with the following keys:
	 * - name: the name of the property, case sensitive.
	 * - enum: optional. Array of possible values for the property. If only one value is possible, enum can be a string.
	 * - params: optional. Array of parameters for the property. If only one parameter is possible, params can be a string.
	 *           Each property / param combination has to have an own entry!
	 * @return array
	 */
	public static function GetSyncMLCapabilities ();

	/**
	 * Returns the text content of the syncml item, for example the vCard.
	 * @return string
	 */
	public function getSyncMLString ();
}

?>