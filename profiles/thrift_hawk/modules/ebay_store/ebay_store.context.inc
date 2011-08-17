<?php
/**
 * @file
 * ebay_store.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function ebay_store_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'eBay store block context';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ebay_store_block-block' => array(
          'module' => 'views',
          'delta' => 'ebay_store_block-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['eBay store block context'] = $context;

  return $export;
}
