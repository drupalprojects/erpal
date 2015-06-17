<?php
/**
 * @file
 * Erpal Reports metadata controller class.
 */

/**
 * Metadata controller class for the Erpal Reports entity.
 */
class ErpalReportsMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    // Make the created and changed property appear as date.
    $properties['changed']['type'] = $properties['created']['type'] = 'date';

    return $info;
  }

}
