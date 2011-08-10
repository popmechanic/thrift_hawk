<?php

/**
 * @file
 * Provides metadata for the commerce file license entity.
 */

/**
 * Implements hook_entity_property_info().
 *  - entity module already adds fields from database schema
 */
function commerce_file_entity_property_info() {
  $info = array();

  $properties = &$info['commerce_file_license']['properties'];

  $properties['state'] = array(
    'label' => t('State'),
    'description' => t('The state of the license derived from its status.'),
    'type' => 'token',
    'getter callback' => 'commerce_file_license_property_getter',
    'options list' => 'commerce_file_license_state_options_list',
  );
  $properties['owner'] = array(
    'label' => t("Owner"),
    'type' => 'user',
    'description' => t("The owner of the license."),
    'getter callback' => 'commerce_file_license_property_getter',
    'setter callback' => 'commerce_file_license_property_setter',
    'setter permission' => COMMERCE_FILE_ADMIN_PERM,
    'clear' => array('uid'),
  );
  $properties['limits'] = array(
    'label' => t("License limits"),
    'type' => 'struct',
    'description' => t("A list of associated license limits."),
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'property info' => _commerce_file_license_data_property_info(),
  );
  $properties['data_unlimited_value'] = array(
    'label' => t("License limit unlimited value"),
    'type' => 'integer',
    'description' => t("The unlimited value for a limit. Use this to determine if a limit has been set to unlimited."),
    'getter callback' => 'commerce_file_license_property_getter',
  );

  $properties['request_time'] = array(
    'label' => t("REQUEST TIME"),
    'type' => 'integer',
    'description' => t("The current request timestamp."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['expiration'] = array(
    'label' => t("Expiration"),
    'type' => 'integer',
    'description' => t("The expiration timestamp."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['time_remaining'] = array(
    'label' => t("Time left"),
    'type' => 'integer',
    'description' => t("The time until expiration."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['logs'] = array(
    'label' => t("Access logs"),
    'type' => 'list<commerce_file_license_log>',
    'description' => t("A list of access logs for this license."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['download_count'] = array(
    'label' => t("Download count"),
    'type' => 'integer',
    'description' => t("The current number of downloads for this license."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['address_count'] = array(
    'label' => t("Address count"),
    'type' => 'integer',
    'description' => t("The current number of different IP addresses that have been used to access this license."),
    'getter callback' => 'commerce_file_license_property_getter',
  );
  $properties['addresses'] = array(
    'label' => t("Owner's Addresses"),
    'type' => 'list<text>',
    'description' => t("A list of unique IP addresses that have been used to access this license."),
    'getter callback' => 'commerce_file_license_property_getter',
  );

  return $info;
}


/**
 * Implements hook_entity_property_info()
 */
function commerce_file_entity_property_info_alter(&$info) {
  if (!isset($info['commerce_line_item']) || !isset($info['commerce_line_item']['bundles'])) {
    return;
  }

  // Move the line item field properties to the line item by default;
  // this makes dealing with them more convenient.
  $properties = array();

  foreach ($info['commerce_line_item']['bundles'] as $bundle => $bundle_info) {
    $bundle_info += array('properties' => array());
    $properties += $bundle_info['properties'];
  }

  $field_name = _commerce_file_get_field_names('line_item_files');
  if (isset($properties[$field_name])) {
    $info['commerce_line_item']['properties'][$field_name] = $properties[$field_name];
  }
}
