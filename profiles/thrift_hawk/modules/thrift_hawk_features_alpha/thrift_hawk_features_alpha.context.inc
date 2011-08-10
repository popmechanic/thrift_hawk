<?php
/**
 * @file
 * thrift_hawk_features_alpha.context.inc
 */

/**
 * Implementation of hook_context_default_contexts().
 */
function thrift_hawk_features_alpha_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Landing page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-welcome' => array(
          'module' => 'boxes',
          'delta' => 'welcome',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['Landing page'] = $context;

  return $export;
}
