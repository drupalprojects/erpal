<?php

$plugin = array(
  'title' => t('Validate unique entities'),
  'description' => t('Provides special validation for Entity Reference field. An validation error will be shown if entity is added twice or more.'),
  'class' => 'EntityReferenceFieldBehaviorUnique',
  'weight' => 10,
  'behavior type' => 'field',
);
