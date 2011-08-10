<?php
/**
 * @file
 * thrift_hawk_features_alpha.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function thrift_hawk_features_alpha_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
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
function thrift_hawk_features_alpha_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implementation of hook_node_info().
 */
function thrift_hawk_features_alpha_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog'),
      'base' => 'node_content',
      'description' => t('Update your blog to teach other people how to buy and sell your product.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'landingimage' => array(
      'name' => t('Landing Page Image'),
      'base' => 'node_content',
      'description' => t('The product image displayed on your landing page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
