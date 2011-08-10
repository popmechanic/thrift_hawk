<?php

/**
 * @file
 * Views for the default Commerce File views.
 */

/**
 * Implements hook_views_default_views().
 */
function commerce_file_views_default_views() {
  $views = array();

// -----------------------------------------------------------------------
// User licenses

$view = new view;
$view->name = 'commerce_user_file_licenses';
$view->description = 'Display a list of licensed files for a user.';
$view->tag = 'commerce';
$view->base_table = 'commerce_file_license';
$view->human_name = 'User Licensed Files';
$view->core = 7;
$view->api_version = '3.0-alpha1';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Files';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access own commerce_file_license';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'commerce_file_license_file' => 'commerce_file_license_file',
  'granted' => 'granted',
  'status' => 'status',
  'time_remaining' => 'time_remaining',
  'address_count' => 'address_count',
  'address_limit' => 'address_limit',
  'download_count' => 'download_count',
  'download_limit' => 'download_limit',
  'download_limit_1' => 'download_limit_1',
  'address_limit_1' => 'address_limit_1',
  'edit_license' => 'edit_license',
  'delete_license' => 'edit_license',
);
$handler->display->display_options['style_options']['default'] = 'granted';
$handler->display->display_options['style_options']['info'] = array(
  'commerce_file_license_file' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'granted' => array(
    'sortable' => 1,
    'default_sort_order' => 'desc',
    'align' => '',
    'separator' => '',
  ),
  'status' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'time_remaining' => array(
    'align' => '',
    'separator' => '',
  ),
  'address_count' => array(
    'align' => '',
    'separator' => '',
  ),
  'address_limit' => array(
    'align' => '',
    'separator' => '',
  ),
  'download_count' => array(
    'align' => '',
    'separator' => '',
  ),
  'download_limit' => array(
    'align' => '',
    'separator' => '',
  ),
  'download_limit_1' => array(
    'align' => '',
    'separator' => '',
  ),
  'address_limit_1' => array(
    'align' => '',
    'separator' => '',
  ),
  'edit_license' => array(
    'align' => '',
    'separator' => '&nbsp; ',
  ),
  'delete_license' => array(
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['order'] = 'desc';
$handler->display->display_options['style_options']['empty_table'] = 1;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'You do not have any licensed files.';
/* Field: Commerce File License: Licensed file */
$handler->display->display_options['fields']['commerce_file_license_file']['id'] = 'commerce_file_license_file';
$handler->display->display_options['fields']['commerce_file_license_file']['table'] = 'field_data_commerce_file_license_file';
$handler->display->display_options['fields']['commerce_file_license_file']['field'] = 'commerce_file_license_file';
$handler->display->display_options['fields']['commerce_file_license_file']['label'] = 'File';
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['external'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['trim'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['alter']['html'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['element_label_colon'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['element_default_classes'] = 1;
$handler->display->display_options['fields']['commerce_file_license_file']['hide_empty'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['empty_zero'] = 0;
$handler->display->display_options['fields']['commerce_file_license_file']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['commerce_file_license_file']['field_api_classes'] = 0;
/* Field: Commerce File License: Granted date */
$handler->display->display_options['fields']['granted']['id'] = 'granted';
$handler->display->display_options['fields']['granted']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['granted']['field'] = 'granted';
$handler->display->display_options['fields']['granted']['label'] = 'Granted on';
$handler->display->display_options['fields']['granted']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['granted']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['granted']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['granted']['alter']['external'] = 0;
$handler->display->display_options['fields']['granted']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['granted']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['granted']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['granted']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['granted']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['granted']['alter']['trim'] = 0;
$handler->display->display_options['fields']['granted']['alter']['html'] = 0;
$handler->display->display_options['fields']['granted']['element_label_colon'] = 0;
$handler->display->display_options['fields']['granted']['element_default_classes'] = 1;
$handler->display->display_options['fields']['granted']['hide_empty'] = 0;
$handler->display->display_options['fields']['granted']['empty_zero'] = 0;
$handler->display->display_options['fields']['granted']['date_format'] = 'medium';
/* Field: Commerce File License: License status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['label'] = 'Status';
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 1;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
/* Field: Commerce File License: Current time remaining */
$handler->display->display_options['fields']['time_remaining']['id'] = 'time_remaining';
$handler->display->display_options['fields']['time_remaining']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['time_remaining']['field'] = 'time_remaining';
$handler->display->display_options['fields']['time_remaining']['label'] = 'Time left';
$handler->display->display_options['fields']['time_remaining']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['external'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['time_remaining']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['time_remaining']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['trim'] = 0;
$handler->display->display_options['fields']['time_remaining']['alter']['html'] = 0;
$handler->display->display_options['fields']['time_remaining']['element_label_colon'] = 1;
$handler->display->display_options['fields']['time_remaining']['element_default_classes'] = 1;
$handler->display->display_options['fields']['time_remaining']['hide_empty'] = 0;
$handler->display->display_options['fields']['time_remaining']['empty_zero'] = 0;
$handler->display->display_options['fields']['time_remaining']['unlimited_text'] = '';
$handler->display->display_options['fields']['time_remaining']['granularity'] = '3';
/* Field: Commerce File License: Current number of addresses */
$handler->display->display_options['fields']['address_count']['id'] = 'address_count';
$handler->display->display_options['fields']['address_count']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['address_count']['field'] = 'address_count';
$handler->display->display_options['fields']['address_count']['label'] = '';
$handler->display->display_options['fields']['address_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['address_count']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['external'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['address_count']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['address_count']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['trim'] = 0;
$handler->display->display_options['fields']['address_count']['alter']['html'] = 0;
$handler->display->display_options['fields']['address_count']['element_label_colon'] = 0;
$handler->display->display_options['fields']['address_count']['element_default_classes'] = 1;
$handler->display->display_options['fields']['address_count']['hide_empty'] = 0;
$handler->display->display_options['fields']['address_count']['empty_zero'] = 0;
/* Field: Commerce File License: Address limit */
$handler->display->display_options['fields']['address_limit']['id'] = 'address_limit';
$handler->display->display_options['fields']['address_limit']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['address_limit']['field'] = 'address_limit';
$handler->display->display_options['fields']['address_limit']['label'] = '';
$handler->display->display_options['fields']['address_limit']['exclude'] = TRUE;
$handler->display->display_options['fields']['address_limit']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['text'] = '[address_count] / [address_limit]';
$handler->display->display_options['fields']['address_limit']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['external'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['address_limit']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['address_limit']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['trim'] = 0;
$handler->display->display_options['fields']['address_limit']['alter']['html'] = 0;
$handler->display->display_options['fields']['address_limit']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['address_limit']['element_default_classes'] = 1;
$handler->display->display_options['fields']['address_limit']['empty'] = 'No Access!';
$handler->display->display_options['fields']['address_limit']['hide_empty'] = 0;
$handler->display->display_options['fields']['address_limit']['empty_zero'] = 1;
/* Field: Commerce File License: Current number of downloads */
$handler->display->display_options['fields']['download_count']['id'] = 'download_count';
$handler->display->display_options['fields']['download_count']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['download_count']['field'] = 'download_count';
$handler->display->display_options['fields']['download_count']['label'] = '';
$handler->display->display_options['fields']['download_count']['exclude'] = TRUE;
$handler->display->display_options['fields']['download_count']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['external'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['download_count']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['download_count']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['trim'] = 0;
$handler->display->display_options['fields']['download_count']['alter']['html'] = 0;
$handler->display->display_options['fields']['download_count']['element_label_colon'] = 0;
$handler->display->display_options['fields']['download_count']['element_default_classes'] = 1;
$handler->display->display_options['fields']['download_count']['hide_empty'] = 0;
$handler->display->display_options['fields']['download_count']['empty_zero'] = 0;
/* Field: Commerce File License: Download limit */
$handler->display->display_options['fields']['download_limit']['id'] = 'download_limit';
$handler->display->display_options['fields']['download_limit']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['download_limit']['field'] = 'download_limit';
$handler->display->display_options['fields']['download_limit']['label'] = '';
$handler->display->display_options['fields']['download_limit']['exclude'] = TRUE;
$handler->display->display_options['fields']['download_limit']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['external'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['download_limit']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['download_limit']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['trim'] = 0;
$handler->display->display_options['fields']['download_limit']['alter']['html'] = 0;
$handler->display->display_options['fields']['download_limit']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['download_limit']['element_default_classes'] = 1;
$handler->display->display_options['fields']['download_limit']['empty'] = 'No Access!';
$handler->display->display_options['fields']['download_limit']['hide_empty'] = 0;
$handler->display->display_options['fields']['download_limit']['empty_zero'] = 1;
/* Field: Commerce File License: Download limit */
$handler->display->display_options['fields']['download_limit_1']['id'] = 'download_limit_1';
$handler->display->display_options['fields']['download_limit_1']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['download_limit_1']['field'] = 'download_limit';
$handler->display->display_options['fields']['download_limit_1']['label'] = 'Downloads';
$handler->display->display_options['fields']['download_limit_1']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['download_limit_1']['alter']['text'] = '[download_count] / [download_limit]';
$handler->display->display_options['fields']['download_limit_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['external'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['download_limit_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['download_limit_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['download_limit_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['download_limit_1']['element_label_colon'] = 1;
$handler->display->display_options['fields']['download_limit_1']['element_default_classes'] = 1;
$handler->display->display_options['fields']['download_limit_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['download_limit_1']['empty_zero'] = 0;
/* Field: Commerce File License: Address limit */
$handler->display->display_options['fields']['address_limit_1']['id'] = 'address_limit_1';
$handler->display->display_options['fields']['address_limit_1']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['address_limit_1']['field'] = 'address_limit';
$handler->display->display_options['fields']['address_limit_1']['label'] = 'IP Addresses';
$handler->display->display_options['fields']['address_limit_1']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['address_limit_1']['alter']['text'] = '[address_count] / [address_limit]';
$handler->display->display_options['fields']['address_limit_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['external'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['address_limit_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['address_limit_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['address_limit_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['address_limit_1']['element_label_colon'] = 1;
$handler->display->display_options['fields']['address_limit_1']['element_default_classes'] = 1;
$handler->display->display_options['fields']['address_limit_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['address_limit_1']['empty_zero'] = 0;
/* Field: Commerce File License: Edit link */
$handler->display->display_options['fields']['edit_license']['id'] = 'edit_license';
$handler->display->display_options['fields']['edit_license']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['edit_license']['field'] = 'edit_license';
$handler->display->display_options['fields']['edit_license']['label'] = '';
$handler->display->display_options['fields']['edit_license']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['external'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['edit_license']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['edit_license']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['trim'] = 0;
$handler->display->display_options['fields']['edit_license']['alter']['html'] = 0;
$handler->display->display_options['fields']['edit_license']['element_label_colon'] = 0;
$handler->display->display_options['fields']['edit_license']['element_default_classes'] = 1;
$handler->display->display_options['fields']['edit_license']['hide_empty'] = 0;
$handler->display->display_options['fields']['edit_license']['empty_zero'] = 0;
$handler->display->display_options['fields']['edit_license']['text'] = 'edit';
/* Field: Commerce File License: Delete link */
$handler->display->display_options['fields']['delete_license']['id'] = 'delete_license';
$handler->display->display_options['fields']['delete_license']['table'] = 'commerce_file_license';
$handler->display->display_options['fields']['delete_license']['field'] = 'delete_license';
$handler->display->display_options['fields']['delete_license']['label'] = '';
$handler->display->display_options['fields']['delete_license']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['external'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['delete_license']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['delete_license']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['trim'] = 0;
$handler->display->display_options['fields']['delete_license']['alter']['html'] = 0;
$handler->display->display_options['fields']['delete_license']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['delete_license']['element_default_classes'] = 1;
$handler->display->display_options['fields']['delete_license']['hide_empty'] = 0;
$handler->display->display_options['fields']['delete_license']['empty_zero'] = 0;
$handler->display->display_options['fields']['delete_license']['text'] = 'delete';
/* Sort criterion: Commerce File License: License ID */
$handler->display->display_options['sorts']['license_id']['id'] = 'license_id';
$handler->display->display_options['sorts']['license_id']['table'] = 'commerce_file_license';
$handler->display->display_options['sorts']['license_id']['field'] = 'license_id';
$handler->display->display_options['sorts']['license_id']['order'] = 'DESC';
/* Contextual filter: Commerce File License: Owner uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'commerce_file_license';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['uid']['specify_validation'] = 1;
$handler->display->display_options['arguments']['uid']['validate']['type'] = 'commerce_file_user';
$handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = '1';
$handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
  3 => '3',
);
$handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
$handler->display->display_options['arguments']['uid']['not'] = 0;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'user/%/licensed-files';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Files';
$handler->display->display_options['menu']['weight'] = '10';
$translatables['commerce_user_file_licenses'] = array(
  t('Master'),
  t('Files'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('You do not have any licensed files.'),
  t('File'),
  t('Granted on'),
  t('Status'),
  t('Time left'),
  t('Unlimited'),
  t('[address_count] / [address_limit]'),
  t('No Access!'),
  t('Downloads'),
  t('[download_count] / [download_limit]'),
  t('IP Addresses'),
  t('edit'),
  t('delete'),
  t('All'),
  t('Page'),
);

  $views[$view->name] = $view;



// -----------------------------------------------------------------------
// Related line items list

$view = new view;
$view->name = 'commerce_license_line_items_list';
$view->description = 'A list of commerce line items related to a file license.  This is used in various admin forms to show the line item references.';
$view->tag = 'commerce';
$view->base_table = 'commerce_file_license';
$view->human_name = 'License Related Line Items';
$view->core = 7;
$view->api_version = '3.0-alpha1';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Related Orders';
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access own commerce_file_license';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['grouping'] = 'order_id_1';
$handler->display->display_options['style_options']['columns'] = array(
  'order_number' => 'order_number',
  'created' => 'created',
  'status' => 'status',
  'order_id_1' => 'order_id_1',
  'line_item_id' => 'line_item_id',
  'line_item_label' => 'line_item_label',
  'line_item_title' => 'line_item_title',
  'quantity' => 'quantity',
  'commerce_total' => 'commerce_total',
);
$handler->display->display_options['style_options']['default'] = 'line_item_id';
$handler->display->display_options['style_options']['info'] = array(
  'order_number' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'status' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'order_id_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'line_item_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'line_item_label' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'line_item_title' => array(
    'align' => '',
    'separator' => '',
  ),
  'quantity' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
  'commerce_total' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
  ),
);
$handler->display->display_options['style_options']['override'] = 1;
$handler->display->display_options['style_options']['sticky'] = 0;
$handler->display->display_options['style_options']['empty_table'] = 1;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = 'There are no line items related to this license.';
/* Relationship: Fields: Referenced line item */
$handler->display->display_options['relationships']['commerce_file_license_line_items_line_item_id']['id'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['relationships']['commerce_file_license_line_items_line_item_id']['table'] = 'field_data_commerce_file_license_line_items';
$handler->display->display_options['relationships']['commerce_file_license_line_items_line_item_id']['field'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['relationships']['commerce_file_license_line_items_line_item_id']['required'] = 1;
/* Relationship: Commerce Line Item: Order ID */
$handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['table'] = 'commerce_line_item';
$handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
$handler->display->display_options['relationships']['order_id']['relationship'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['relationships']['order_id']['required'] = 1;
/* Field: Commerce Order: Order number */
$handler->display->display_options['fields']['order_number']['id'] = 'order_number';
$handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_number']['field'] = 'order_number';
$handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_number']['label'] = '';
$handler->display->display_options['fields']['order_number']['exclude'] = TRUE;
$handler->display->display_options['fields']['order_number']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['external'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['trim'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['order_number']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['order_number']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['order_number']['alter']['html'] = 0;
$handler->display->display_options['fields']['order_number']['element_label_colon'] = 0;
$handler->display->display_options['fields']['order_number']['element_default_classes'] = 1;
$handler->display->display_options['fields']['order_number']['hide_empty'] = 0;
$handler->display->display_options['fields']['order_number']['empty_zero'] = 0;
/* Field: Commerce Order: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'commerce_order';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'order_id';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['exclude'] = TRUE;
$handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['created']['alter']['external'] = 0;
$handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['created']['alter']['trim'] = 0;
$handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['created']['alter']['html'] = 0;
$handler->display->display_options['fields']['created']['element_label_colon'] = 0;
$handler->display->display_options['fields']['created']['element_default_classes'] = 1;
$handler->display->display_options['fields']['created']['hide_empty'] = 0;
$handler->display->display_options['fields']['created']['empty_zero'] = 0;
$handler->display->display_options['fields']['created']['date_format'] = 'long';
/* Field: Commerce Order: Order status */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'commerce_order';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['relationship'] = 'order_id';
$handler->display->display_options['fields']['status']['label'] = '';
$handler->display->display_options['fields']['status']['exclude'] = TRUE;
$handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['status']['alter']['external'] = 0;
$handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['status']['alter']['trim'] = 0;
$handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['status']['alter']['html'] = 0;
$handler->display->display_options['fields']['status']['element_label_colon'] = 0;
$handler->display->display_options['fields']['status']['element_default_classes'] = 1;
$handler->display->display_options['fields']['status']['hide_empty'] = 0;
$handler->display->display_options['fields']['status']['empty_zero'] = 0;
/* Field: Commerce Order: Order ID */
$handler->display->display_options['fields']['order_id_1']['id'] = 'order_id_1';
$handler->display->display_options['fields']['order_id_1']['table'] = 'commerce_order';
$handler->display->display_options['fields']['order_id_1']['field'] = 'order_id';
$handler->display->display_options['fields']['order_id_1']['relationship'] = 'order_id';
$handler->display->display_options['fields']['order_id_1']['label'] = '';
$handler->display->display_options['fields']['order_id_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['order_id_1']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['order_id_1']['alter']['text'] = 'Order [order_number] on [created] &nbsp;([status])
';
$handler->display->display_options['fields']['order_id_1']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['external'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['trim'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['order_id_1']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['order_id_1']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['order_id_1']['alter']['html'] = 0;
$handler->display->display_options['fields']['order_id_1']['element_label_colon'] = 0;
$handler->display->display_options['fields']['order_id_1']['element_default_classes'] = 1;
$handler->display->display_options['fields']['order_id_1']['hide_empty'] = 0;
$handler->display->display_options['fields']['order_id_1']['empty_zero'] = 0;
$handler->display->display_options['fields']['order_id_1']['link_to_order'] = 'customer';
/* Field: Commerce Line Item: Label */
$handler->display->display_options['fields']['line_item_label']['id'] = 'line_item_label';
$handler->display->display_options['fields']['line_item_label']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['line_item_label']['field'] = 'line_item_label';
$handler->display->display_options['fields']['line_item_label']['relationship'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['fields']['line_item_label']['label'] = 'SKU';
$handler->display->display_options['fields']['line_item_label']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['external'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['trim'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['line_item_label']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['line_item_label']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['line_item_label']['alter']['html'] = 0;
$handler->display->display_options['fields']['line_item_label']['element_label_colon'] = 1;
$handler->display->display_options['fields']['line_item_label']['element_default_classes'] = 1;
$handler->display->display_options['fields']['line_item_label']['hide_empty'] = 0;
$handler->display->display_options['fields']['line_item_label']['empty_zero'] = 0;
/* Field: Commerce Line Item: Title */
$handler->display->display_options['fields']['line_item_title']['id'] = 'line_item_title';
$handler->display->display_options['fields']['line_item_title']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['line_item_title']['field'] = 'line_item_title';
$handler->display->display_options['fields']['line_item_title']['relationship'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['fields']['line_item_title']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['external'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['trim'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['line_item_title']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['line_item_title']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['line_item_title']['alter']['html'] = 0;
$handler->display->display_options['fields']['line_item_title']['element_label_colon'] = 1;
$handler->display->display_options['fields']['line_item_title']['element_default_classes'] = 1;
$handler->display->display_options['fields']['line_item_title']['hide_empty'] = 0;
$handler->display->display_options['fields']['line_item_title']['empty_zero'] = 0;
/* Field: Commerce Line Item: Quantity */
$handler->display->display_options['fields']['quantity']['id'] = 'quantity';
$handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
$handler->display->display_options['fields']['quantity']['field'] = 'quantity';
$handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['fields']['quantity']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['external'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['trim'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['quantity']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['quantity']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['quantity']['alter']['html'] = 0;
$handler->display->display_options['fields']['quantity']['element_label_colon'] = 1;
$handler->display->display_options['fields']['quantity']['element_default_classes'] = 1;
$handler->display->display_options['fields']['quantity']['hide_empty'] = 0;
$handler->display->display_options['fields']['quantity']['empty_zero'] = 0;
$handler->display->display_options['fields']['quantity']['set_precision'] = 0;
$handler->display->display_options['fields']['quantity']['precision'] = '0';
$handler->display->display_options['fields']['quantity']['format_plural'] = 0;
/* Field: Line item: Total */
$handler->display->display_options['fields']['commerce_total']['id'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['table'] = 'field_data_commerce_total';
$handler->display->display_options['fields']['commerce_total']['field'] = 'commerce_total';
$handler->display->display_options['fields']['commerce_total']['relationship'] = 'commerce_file_license_line_items_line_item_id';
$handler->display->display_options['fields']['commerce_total']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['external'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['trim'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['commerce_total']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['commerce_total']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['commerce_total']['alter']['html'] = 0;
$handler->display->display_options['fields']['commerce_total']['element_label_colon'] = 1;
$handler->display->display_options['fields']['commerce_total']['element_default_classes'] = 1;
$handler->display->display_options['fields']['commerce_total']['hide_empty'] = 0;
$handler->display->display_options['fields']['commerce_total']['empty_zero'] = 0;
$handler->display->display_options['fields']['commerce_total']['click_sort_column'] = 'amount';
$handler->display->display_options['fields']['commerce_total']['type'] = 'commerce_price_formatted_amount';
$handler->display->display_options['fields']['commerce_total']['settings'] = array(
  'calculation' => FALSE,
);
$handler->display->display_options['fields']['commerce_total']['field_api_classes'] = 0;
/* Contextual filter: Commerce File License: License ID */
$handler->display->display_options['arguments']['license_id']['id'] = 'license_id';
$handler->display->display_options['arguments']['license_id']['table'] = 'commerce_file_license';
$handler->display->display_options['arguments']['license_id']['field'] = 'license_id';
$handler->display->display_options['arguments']['license_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['license_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['license_id']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['license_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['license_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['license_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['license_id']['break_phrase'] = 0;
$handler->display->display_options['arguments']['license_id']['not'] = 0;
$translatables['commerce_license_line_items_list'] = array(
  t('Master'),
  t('Related Orders'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('There are no line items related to this license.'),
  t('Line Item'),
  t('Order'),
  t('Order [order_number] on [created] &nbsp;([status])
'),
  t('SKU'),
  t('Title'),
  t('Quantity'),
  t('.'),
  t(','),
  t('Total'),
  t('All'),
);

  $views[$view->name] = $view;


  return $views;
}
