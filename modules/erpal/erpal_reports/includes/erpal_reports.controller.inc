<?php

/*
 * Erpal Reports entity controller.
 */
class ErpalReportsController extends EntityAPIController {

  public function create(array $values = array()) {
    $values += array(
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $GLOBALS['user']->uid,
    );
    return parent::create($values);
  }

  public function save($entity, \DatabaseTransaction $transaction = NULL) {
    $entity->changed = REQUEST_TIME;
    parent::save($entity, $transaction);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('erpal_reports', $entity);

    $title = $wrapper->title->value();
    if (!empty($title)) {
      $content['title'] = array(
        '#type' => 'item',
        '#title' => t('Title'),
        '#markup' => check_plain($title),
      );
    }

    // Attach all fields and also sort all content items by weight.
    $content = parent::buildContent($entity, $view_mode, $langcode, $content);

    return $content;
  }
}
