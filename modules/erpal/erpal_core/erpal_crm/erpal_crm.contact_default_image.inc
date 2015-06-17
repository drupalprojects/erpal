<?php

/**
 * Set contact default image.
 * Inspired by https://drupal.org/comment/6524566#comment-6524566.
 */
function erpal_crm_contact_add_default_image(){
//  dpm("erpal_crm_contact_add_default_image");
  $image_field = field_info_instance('node', 'field_contact_image', 'erpal_contact');

  $source_dir = drupal_get_path('module', 'erpal_crm') . '/images';
  $filename = "user.png";
  $source = $source_dir . '/' . $filename;
  $destination = 'public://default_images/' . $filename;

//  erpal_crm_set_default_image($image_field, 'field_contact_image', $source, $destination);

  // See if a default image hasn't been set for this field yet
  // uncomment "if" if you want to preserve the images set before
//  if (empty($field['settings']['default_image'])) {

  // Dynamically set the user default image on the field

  // Check to see if it exists already
  $result = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->condition('f.uri', $destination)
    ->execute();
  $fid = $result->fetchField();

  // Simulate an upload of the default user image
  if (!$fid && file_exists($source)) {
    $file = new stdClass;
    $file->filename = $filename;
    $file->timestamp = REQUEST_TIME;
    $file->uri = $source;
    $file->filemime = file_get_mimetype($source);
    $file->uid = 1;
    $file->status = 1;
    $file = file_copy($file, 'public://', FILE_EXISTS_REPLACE);
    $fid = $file->fid;
  }

  $image_field['settings']['default_image'] = (string) $fid;
  field_update_instance($image_field);

//  }

}