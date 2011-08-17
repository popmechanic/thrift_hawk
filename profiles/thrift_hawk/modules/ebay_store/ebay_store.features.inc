<?php
/**
 * @file
 * ebay_store.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ebay_store_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_views_api().
 */
function ebay_store_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function ebay_store_node_info() {
  $items = array(
    'ebay_link' => array(
      'name' => t('eBay link'),
      'base' => 'node_content',
      'description' => t('Add a link to your eBay store. It\'ll be displayed in the right sidebar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
