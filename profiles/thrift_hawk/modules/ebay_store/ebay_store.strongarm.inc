<?php
/**
 * @file
 * ebay_store.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function ebay_store_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_ebay_link';
  $strongarm->value = 0;
  $export['comment_anonymous_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_ebay_link';
  $strongarm->value = 1;
  $export['comment_default_mode_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_ebay_link';
  $strongarm->value = '50';
  $export['comment_default_per_page_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_ebay_link';
  $strongarm->value = '1';
  $export['comment_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_ebay_link';
  $strongarm->value = 1;
  $export['comment_form_location_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_ebay_link';
  $strongarm->value = '1';
  $export['comment_preview_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_ebay_link';
  $strongarm->value = 1;
  $export['comment_subject_field_ebay_link'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ebay_link';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_ebay_link'] = $strongarm;

  return $export;
}
