<?php
/**
 * @file
 * feature_erpal_germany_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_erpal_germany_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: access any og user.
  $permissions['access any og user'] = array(
    'name' => 'access any og user',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'og_relations',
  );

  // Exported permission: access billables view.
  $permissions['access billables view'] = array(
    'name' => 'access billables view',
    'roles' => array(
      0 => 'controller',
      1 => 'financial user',
    ),
    'module' => 'erpal_projects_billable',
  );

  // Exported permission: access bookmarks view.
  $permissions['access bookmarks view'] = array(
    'name' => 'access bookmarks view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_bookmark_helper',
  );

  // Exported permission: access books view.
  $permissions['access books view'] = array(
    'name' => 'access books view',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_book_helper',
  );

  // Exported permission: access calendar view.
  $permissions['access calendar view'] = array(
    'name' => 'access calendar view',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'erpal_calendar_helper',
  );

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access contact view.
  $permissions['access contact view'] = array(
    'name' => 'access contact view',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'project manager',
    ),
    'module' => 'erpal_basic_helper',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: access contracts view.
  $permissions['access contracts view'] = array(
    'name' => 'access contracts view',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
    ),
    'module' => 'erpal_contract_helper',
  );

  // Exported permission: access documents view.
  $permissions['access documents view'] = array(
    'name' => 'access documents view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_docs_helper',
  );

  // Exported permission: access invoices view.
  $permissions['access invoices view'] = array(
    'name' => 'access invoices view',
    'roles' => array(
      0 => 'controller',
      1 => 'financial user',
    ),
    'module' => 'erpal_invoice_helper',
  );

  // Exported permission: access projects view.
  $permissions['access projects view'] = array(
    'name' => 'access projects view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access relations.
  $permissions['access relations'] = array(
    'name' => 'access relations',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'relation',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access spaces view.
  $permissions['access spaces view'] = array(
    'name' => 'access spaces view',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: access sub tasks and tickets details view.
  $permissions['access sub tasks and tickets details view'] = array(
    'name' => 'access sub tasks and tickets details view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access sub tasks and tickets tree view.
  $permissions['access sub tasks and tickets tree view'] = array(
    'name' => 'access sub tasks and tickets tree view',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access sub tasks and tickets view.
  $permissions['access sub tasks and tickets view'] = array(
    'name' => 'access sub tasks and tickets view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tasks details.
  $permissions['access tasks details'] = array(
    'name' => 'access tasks details',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tasks tree.
  $permissions['access tasks tree'] = array(
    'name' => 'access tasks tree',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tasks view.
  $permissions['access tasks view'] = array(
    'name' => 'access tasks view',
    'roles' => array(
      0 => 'external developer',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tickets details.
  $permissions['access tickets details'] = array(
    'name' => 'access tickets details',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tickets tree.
  $permissions['access tickets tree'] = array(
    'name' => 'access tickets tree',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access tickets view.
  $permissions['access tickets view'] = array(
    'name' => 'access tickets view',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access timetrackings view.
  $permissions['access timetrackings view'] = array(
    'name' => 'access timetrackings view',
    'roles' => array(
      0 => 'controller',
      1 => 'external developer',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: access toolbar.
  $permissions['access toolbar'] = array(
    'name' => 'access toolbar',
    'roles' => array(),
    'module' => 'toolbar',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: admin_display_suite.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: admin_fields.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: admin_view_modes.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer billable.
  $permissions['administer billable'] = array(
    'name' => 'administer billable',
    'roles' => array(),
    'module' => 'billable',
  );

  // Exported permission: administer billable types.
  $permissions['administer billable types'] = array(
    'name' => 'administer billable types',
    'roles' => array(),
    'module' => 'billable',
  );

  // Exported permission: administer billables.
  $permissions['administer billables'] = array(
    'name' => 'administer billables',
    'roles' => array(),
    'module' => 'billable',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: administer budgets.
  $permissions['administer budgets'] = array(
    'name' => 'administer budgets',
    'roles' => array(),
    'module' => 'budget',
  );

  // Exported permission: administer comments.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer date_item.
  $permissions['administer date_item'] = array(
    'name' => 'administer date_item',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: administer date_item types.
  $permissions['administer date_item types'] = array(
    'name' => 'administer date_item types',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: administer dependencies.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(),
    'module' => 'conditional_fields',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: administer field collections.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(),
    'module' => 'field_collection',
  );

  // Exported permission: administer fieldgroups.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: administer flags.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: administer front page.
  $permissions['administer front page'] = array(
    'name' => 'administer front page',
    'roles' => array(),
    'module' => 'front_page',
  );

  // Exported permission: administer group.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'og',
  );

  // Exported permission: administer homebox.
  $permissions['administer homebox'] = array(
    'name' => 'administer homebox',
    'roles' => array(),
    'module' => 'homebox',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: administer mini panels.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer own simple_date date_item.
  $permissions['administer own simple_date date_item'] = array(
    'name' => 'administer own simple_date date_item',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer profile types.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: administer profiles.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(),
    'module' => 'profile2',
  );

  // Exported permission: administer quicktabs.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(),
    'module' => 'quicktabs',
  );

  // Exported permission: administer relation types.
  $permissions['administer relation types'] = array(
    'name' => 'administer relation types',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: administer relations.
  $permissions['administer relations'] = array(
    'name' => 'administer relations',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'relation',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: administer simple_date date_item.
  $permissions['administer simple_date date_item'] = array(
    'name' => 'administer simple_date date_item',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer timetrackings.
  $permissions['administer timetrackings'] = array(
    'name' => 'administer timetrackings',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'timetracking',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: change group audience file.
  $permissions['change group audience file'] = array(
    'name' => 'change group audience file',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change group audience project.
  $permissions['change group audience project'] = array(
    'name' => 'change group audience project',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change group audience task.
  $permissions['change group audience task'] = array(
    'name' => 'change group audience task',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change group audience timetracking.
  $permissions['change group audience timetracking'] = array(
    'name' => 'change group audience timetracking',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change group content visibility task.
  $permissions['change group content visibility task'] = array(
    'name' => 'change group content visibility task',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change group content visibility timetracking.
  $permissions['change group content visibility timetracking'] = array(
    'name' => 'change group content visibility timetracking',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: choose project file to group.
  $permissions['choose project file to group'] = array(
    'name' => 'choose project file to group',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: choose task file to group.
  $permissions['choose task file to group'] = array(
    'name' => 'choose task file to group',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_spaces_helper',
  );

  // Exported permission: clone complete books.
  $permissions['clone complete books'] = array(
    'name' => 'clone complete books',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'erpal_book_helper',
  );

  // Exported permission: config erpal.
  $permissions['config erpal'] = array(
    'name' => 'config erpal',
    'roles' => array(),
    'module' => 'erpal_basic_helper',
  );

  // Exported permission: config erpal basic.
  $permissions['config erpal basic'] = array(
    'name' => 'config erpal basic',
    'roles' => array(),
    'module' => 'erpal_basic_helper',
  );

  // Exported permission: config erpal calendar.
  $permissions['config erpal calendar'] = array(
    'name' => 'config erpal calendar',
    'roles' => array(),
    'module' => 'erpal_calendar_helper',
  );

  // Exported permission: config erpal invoice.
  $permissions['config erpal invoice'] = array(
    'name' => 'config erpal invoice',
    'roles' => array(),
    'module' => 'erpal_invoice_helper',
  );

  // Exported permission: config erpal projects.
  $permissions['config erpal projects'] = array(
    'name' => 'config erpal projects',
    'roles' => array(),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: config erpal resource.
  $permissions['config erpal resource'] = array(
    'name' => 'config erpal resource',
    'roles' => array(),
    'module' => 'erpal_resource_helper',
  );

  // Exported permission: create budget.
  $permissions['create budget'] = array(
    'name' => 'create budget',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'budget',
  );

  // Exported permission: create erpal_book content.
  $permissions['create erpal_book content'] = array(
    'name' => 'create erpal_book content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_book_page content.
  $permissions['create erpal_book_page content'] = array(
    'name' => 'create erpal_book_page content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_contact content.
  $permissions['create erpal_contact content'] = array(
    'name' => 'create erpal_contact content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_contract content.
  $permissions['create erpal_contract content'] = array(
    'name' => 'create erpal_contract content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_crm_activity content.
  $permissions['create erpal_crm_activity content'] = array(
    'name' => 'create erpal_crm_activity content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_date content.
  $permissions['create erpal_date content'] = array(
    'name' => 'create erpal_date content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_file content.
  $permissions['create erpal_file content'] = array(
    'name' => 'create erpal_file content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_invoice content.
  $permissions['create erpal_invoice content'] = array(
    'name' => 'create erpal_invoice content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_project content.
  $permissions['create erpal_project content'] = array(
    'name' => 'create erpal_project content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_space content.
  $permissions['create erpal_space content'] = array(
    'name' => 'create erpal_space content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_task content.
  $permissions['create erpal_task content'] = array(
    'name' => 'create erpal_task content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create erpal_timetracking content.
  $permissions['create erpal_timetracking content'] = array(
    'name' => 'create erpal_timetracking content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: create mini panels.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(),
    'module' => 'panels_mini',
  );

  // Exported permission: create relations.
  $permissions['create relations'] = array(
    'name' => 'create relations',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'relation',
  );

  // Exported permission: create simple_date date_item.
  $permissions['create simple_date date_item'] = array(
    'name' => 'create simple_date date_item',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'date_item',
  );

  // Exported permission: create simple_date date_item other anonymous.
  $permissions['create simple_date date_item other anonymous'] = array(
    'name' => 'create simple_date date_item other anonymous',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: create simple_date date_item other users.
  $permissions['create simple_date date_item other users'] = array(
    'name' => 'create simple_date date_item other users',
    'roles' => array(),
    'module' => 'date_item',
  );

  // Exported permission: create timetracking.
  $permissions['create timetracking'] = array(
    'name' => 'create timetracking',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'timetracking',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: delete any erpal_book content.
  $permissions['delete any erpal_book content'] = array(
    'name' => 'delete any erpal_book content',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_book_page content.
  $permissions['delete any erpal_book_page content'] = array(
    'name' => 'delete any erpal_book_page content',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_contact content.
  $permissions['delete any erpal_contact content'] = array(
    'name' => 'delete any erpal_contact content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_contract content.
  $permissions['delete any erpal_contract content'] = array(
    'name' => 'delete any erpal_contract content',
    'roles' => array(
      0 => 'financial user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_crm_activity content.
  $permissions['delete any erpal_crm_activity content'] = array(
    'name' => 'delete any erpal_crm_activity content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_date content.
  $permissions['delete any erpal_date content'] = array(
    'name' => 'delete any erpal_date content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_file content.
  $permissions['delete any erpal_file content'] = array(
    'name' => 'delete any erpal_file content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_invoice content.
  $permissions['delete any erpal_invoice content'] = array(
    'name' => 'delete any erpal_invoice content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_project content.
  $permissions['delete any erpal_project content'] = array(
    'name' => 'delete any erpal_project content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_space content.
  $permissions['delete any erpal_space content'] = array(
    'name' => 'delete any erpal_space content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_task content.
  $permissions['delete any erpal_task content'] = array(
    'name' => 'delete any erpal_task content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_timetracking content.
  $permissions['delete any erpal_timetracking content'] = array(
    'name' => 'delete any erpal_timetracking content',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any simple_date date_item.
  $permissions['delete any simple_date date_item'] = array(
    'name' => 'delete any simple_date date_item',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'date_item',
  );

  // Exported permission: delete own erpal_book content.
  $permissions['delete own erpal_book content'] = array(
    'name' => 'delete own erpal_book content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_book_page content.
  $permissions['delete own erpal_book_page content'] = array(
    'name' => 'delete own erpal_book_page content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_contact content.
  $permissions['delete own erpal_contact content'] = array(
    'name' => 'delete own erpal_contact content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_contract content.
  $permissions['delete own erpal_contract content'] = array(
    'name' => 'delete own erpal_contract content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_crm_activity content.
  $permissions['delete own erpal_crm_activity content'] = array(
    'name' => 'delete own erpal_crm_activity content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_date content.
  $permissions['delete own erpal_date content'] = array(
    'name' => 'delete own erpal_date content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_file content.
  $permissions['delete own erpal_file content'] = array(
    'name' => 'delete own erpal_file content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_invoice content.
  $permissions['delete own erpal_invoice content'] = array(
    'name' => 'delete own erpal_invoice content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_project content.
  $permissions['delete own erpal_project content'] = array(
    'name' => 'delete own erpal_project content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_space content.
  $permissions['delete own erpal_space content'] = array(
    'name' => 'delete own erpal_space content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_task content.
  $permissions['delete own erpal_task content'] = array(
    'name' => 'delete own erpal_task content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own erpal_timetracking content.
  $permissions['delete own erpal_timetracking content'] = array(
    'name' => 'delete own erpal_timetracking content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own simple_date date_item.
  $permissions['delete own simple_date date_item'] = array(
    'name' => 'delete own simple_date date_item',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'date_item',
  );

  // Exported permission: delete relations.
  $permissions['delete relations'] = array(
    'name' => 'delete relations',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'relation',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11.
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 12.
  $permissions['delete terms in 12'] = array(
    'name' => 'delete terms in 12',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 13.
  $permissions['delete terms in 13'] = array(
    'name' => 'delete terms in 13',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 14.
  $permissions['delete terms in 14'] = array(
    'name' => 'delete terms in 14',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 15.
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 16.
  $permissions['delete terms in 16'] = array(
    'name' => 'delete terms in 16',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 17.
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 18.
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any billable.
  $permissions['edit any billable'] = array(
    'name' => 'edit any billable',
    'roles' => array(
      0 => 'financial user',
    ),
    'module' => 'billable',
  );

  // Exported permission: edit any budget.
  $permissions['edit any budget'] = array(
    'name' => 'edit any budget',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'budget',
  );

  // Exported permission: edit any contract profile.
  $permissions['edit any contract profile'] = array(
    'name' => 'edit any contract profile',
    'roles' => array(
      0 => 'controller',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit any erpal_book content.
  $permissions['edit any erpal_book content'] = array(
    'name' => 'edit any erpal_book content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_book_page content.
  $permissions['edit any erpal_book_page content'] = array(
    'name' => 'edit any erpal_book_page content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_contact content.
  $permissions['edit any erpal_contact content'] = array(
    'name' => 'edit any erpal_contact content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_contract content.
  $permissions['edit any erpal_contract content'] = array(
    'name' => 'edit any erpal_contract content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_crm_activity content.
  $permissions['edit any erpal_crm_activity content'] = array(
    'name' => 'edit any erpal_crm_activity content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_date content.
  $permissions['edit any erpal_date content'] = array(
    'name' => 'edit any erpal_date content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_file content.
  $permissions['edit any erpal_file content'] = array(
    'name' => 'edit any erpal_file content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_invoice content.
  $permissions['edit any erpal_invoice content'] = array(
    'name' => 'edit any erpal_invoice content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_project content.
  $permissions['edit any erpal_project content'] = array(
    'name' => 'edit any erpal_project content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_space content.
  $permissions['edit any erpal_space content'] = array(
    'name' => 'edit any erpal_space content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_task content.
  $permissions['edit any erpal_task content'] = array(
    'name' => 'edit any erpal_task content',
    'roles' => array(
      0 => 'external developer',
      1 => 'internal developer',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_timetracking content.
  $permissions['edit any erpal_timetracking content'] = array(
    'name' => 'edit any erpal_timetracking content',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any main profile.
  $permissions['edit any main profile'] = array(
    'name' => 'edit any main profile',
    'roles' => array(
      0 => 'controller',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit any timetracking.
  $permissions['edit any timetracking'] = array(
    'name' => 'edit any timetracking',
    'roles' => array(
      0 => 'project manager',
    ),
    'module' => 'timetracking',
  );

  // Exported permission: edit own comments.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(),
    'module' => 'comment',
  );

  // Exported permission: edit own contract profile.
  $permissions['edit own contract profile'] = array(
    'name' => 'edit own contract profile',
    'roles' => array(
      0 => 'controller',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit own erpal_book content.
  $permissions['edit own erpal_book content'] = array(
    'name' => 'edit own erpal_book content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_book_page content.
  $permissions['edit own erpal_book_page content'] = array(
    'name' => 'edit own erpal_book_page content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_contact content.
  $permissions['edit own erpal_contact content'] = array(
    'name' => 'edit own erpal_contact content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_contract content.
  $permissions['edit own erpal_contract content'] = array(
    'name' => 'edit own erpal_contract content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_crm_activity content.
  $permissions['edit own erpal_crm_activity content'] = array(
    'name' => 'edit own erpal_crm_activity content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_date content.
  $permissions['edit own erpal_date content'] = array(
    'name' => 'edit own erpal_date content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_file content.
  $permissions['edit own erpal_file content'] = array(
    'name' => 'edit own erpal_file content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_invoice content.
  $permissions['edit own erpal_invoice content'] = array(
    'name' => 'edit own erpal_invoice content',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_project content.
  $permissions['edit own erpal_project content'] = array(
    'name' => 'edit own erpal_project content',
    'roles' => array(
      0 => 'internal developer',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_space content.
  $permissions['edit own erpal_space content'] = array(
    'name' => 'edit own erpal_space content',
    'roles' => array(
      0 => 'account manager',
      1 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_task content.
  $permissions['edit own erpal_task content'] = array(
    'name' => 'edit own erpal_task content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own erpal_timetracking content.
  $permissions['edit own erpal_timetracking content'] = array(
    'name' => 'edit own erpal_timetracking content',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own main profile.
  $permissions['edit own main profile'] = array(
    'name' => 'edit own main profile',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: edit relations.
  $permissions['edit relations'] = array(
    'name' => 'edit relations',
    'roles' => array(
      0 => 'account manager',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'relation',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11.
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 12.
  $permissions['edit terms in 12'] = array(
    'name' => 'edit terms in 12',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 13.
  $permissions['edit terms in 13'] = array(
    'name' => 'edit terms in 13',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 14.
  $permissions['edit terms in 14'] = array(
    'name' => 'edit terms in 14',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 15.
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 16.
  $permissions['edit terms in 16'] = array(
    'name' => 'edit terms in 16',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 17.
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 18.
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: erpal print tasks.
  $permissions['erpal print tasks'] = array(
    'name' => 'erpal print tasks',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: export relation types.
  $permissions['export relation types'] = array(
    'name' => 'export relation types',
    'roles' => array(),
    'module' => 'relation',
  );

  // Exported permission: field edit pricing.
  $permissions['field edit pricing'] = array(
    'name' => 'field edit pricing',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: field edit task advanced.
  $permissions['field edit task advanced'] = array(
    'name' => 'field edit task advanced',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: field edit timetracking duration.
  $permissions['field edit timetracking duration'] = array(
    'name' => 'field edit timetracking duration',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: field view pricing.
  $permissions['field view pricing'] = array(
    'name' => 'field view pricing',
    'roles' => array(
      0 => 'controller',
      1 => 'financial user',
      2 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: field view task advanced.
  $permissions['field view task advanced'] = array(
    'name' => 'field view task advanced',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: field view timetracking duration.
  $permissions['field view timetracking duration'] = array(
    'name' => 'field view timetracking duration',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'erpal_projects_helper',
  );

  // Exported permission: flag bookmark_flag.
  $permissions['flag bookmark_flag'] = array(
    'name' => 'flag bookmark_flag',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: flag project_subscriptions.
  $permissions['flag project_subscriptions'] = array(
    'name' => 'flag project_subscriptions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: flag task_subscriptions.
  $permissions['flag task_subscriptions'] = array(
    'name' => 'flag task_subscriptions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: grant content access.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'content_access',
  );

  // Exported permission: grant own content access.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'content_access',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'node',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: skip comment approval.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: unflag bookmark_flag.
  $permissions['unflag bookmark_flag'] = array(
    'name' => 'unflag bookmark_flag',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag project_subscriptions.
  $permissions['unflag project_subscriptions'] = array(
    'name' => 'unflag project_subscriptions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag task_subscriptions.
  $permissions['unflag task_subscriptions'] = array(
    'name' => 'unflag task_subscriptions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: update any simple_date date_item.
  $permissions['update any simple_date date_item'] = array(
    'name' => 'update any simple_date date_item',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'date_item',
  );

  // Exported permission: update own simple_date date_item.
  $permissions['update own simple_date date_item'] = array(
    'name' => 'update own simple_date date_item',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'date_item',
  );

  // Exported permission: use PHP for settings.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(),
    'module' => 'php',
  );

  // Exported permission: use PHP for title patterns.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: use file edit.
  $permissions['use file edit'] = array(
    'name' => 'use file edit',
    'roles' => array(),
    'module' => 'fileedit',
  );

  // Exported permission: use flag import.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: use quick timetracking.
  $permissions['use quick timetracking'] = array(
    'name' => 'use quick timetracking',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'external developer',
      3 => 'financial user',
      4 => 'internal developer',
      5 => 'project manager',
    ),
    'module' => 'timetracking',
  );

  // Exported permission: use text format ds_code.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format filtered_html.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format php_code.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: view any billable.
  $permissions['view any billable'] = array(
    'name' => 'view any billable',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'billable',
  );

  // Exported permission: view any budget.
  $permissions['view any budget'] = array(
    'name' => 'view any budget',
    'roles' => array(
      0 => 'financial user',
      1 => 'project manager',
    ),
    'module' => 'budget',
  );

  // Exported permission: view any contract profile.
  $permissions['view any contract profile'] = array(
    'name' => 'view any contract profile',
    'roles' => array(
      0 => 'controller',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view any main profile.
  $permissions['view any main profile'] = array(
    'name' => 'view any main profile',
    'roles' => array(
      0 => 'account manager',
      1 => 'controller',
      2 => 'financial user',
      3 => 'internal developer',
      4 => 'project manager',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view any timetracking.
  $permissions['view any timetracking'] = array(
    'name' => 'view any timetracking',
    'roles' => array(
      0 => 'controller',
      1 => 'financial user',
      2 => 'internal developer',
      3 => 'project manager',
    ),
    'module' => 'timetracking',
  );

  // Exported permission: view date repeats.
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(),
    'module' => 'date_repeat_field',
  );

  // Exported permission: view own contract profile.
  $permissions['view own contract profile'] = array(
    'name' => 'view own contract profile',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view own main profile.
  $permissions['view own main profile'] = array(
    'name' => 'view own main profile',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: view own simple_date date_item.
  $permissions['view own simple_date date_item'] = array(
    'name' => 'view own simple_date date_item',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'date_item',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: view simple_date date_item.
  $permissions['view simple_date date_item'] = array(
    'name' => 'view simple_date date_item',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'date_item',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(),
    'module' => 'system',
  );

  return $permissions;
}
