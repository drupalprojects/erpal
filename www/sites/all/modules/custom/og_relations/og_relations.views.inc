<?php

/**
 * Implements of hook_views_data().
 */
function og_relations_views_data() {
  return array(
    'og_membership' => array(
      'og_relations' => array(
        'group' => t('OG User'),
        'title' => t('belongs to group of current user'),
        'help' => t('User belongs to organic group of current user'),
        'filter' => array('handler' => 'og_relations_handler_filter_og_relations_filter'),
      )
    )
  );
}
