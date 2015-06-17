<?php

/**
 * Erpal Reports entity class.
 */
class ErpalReports extends Entity {

  public $id;

  public $rid;

  public $type;

  public $uid;

  public $created;

  public $changed;

  public $dirty;

  public $title;

  public $data;

  public $is_new_revision = TRUE;

  protected function defaultLabel() {
    return check_plain($this->title);
  }

  protected function defaultUri() {
    return array('path' => 'erpal/reports/' . $this->identifier());
  }

}
