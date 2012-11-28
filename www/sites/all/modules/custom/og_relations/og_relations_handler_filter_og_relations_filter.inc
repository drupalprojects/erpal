<?php

/**
 * My custom filter handler
 */
class og_relations_handler_filter_og_relations_filter extends views_handler_filter {

  function query() {
    global $user;
    // Check if user hasn't access to any user of any Organic Group
    if (!user_access('access any og user')) {
      $groups = og_get_groups_by_user($user);
      if (!empty($groups)) {
        // collect all OG Ids of current site user
        $group_ids = array();
        foreach ($groups as $bundle) {
          foreach ($bundle as $group_id) {
            $group_ids[$group_id] = $group_id;
          }
        }
        $this->ensure_my_table();
        $alias = $this->table_alias;
        // Filter users that belong to organic group of current user
        $this->query->add_where($alias, "$alias.gid", $group_ids, "IN");
      }
    }
  }

}
