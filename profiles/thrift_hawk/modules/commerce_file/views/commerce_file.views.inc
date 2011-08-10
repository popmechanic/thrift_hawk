<?php

/**
 * @file
 * Export Drupal Commerce file licenses to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_file_views_data() {
  $data = array();

  // -----------------------------------------------------------------------
  // License Table

  $data['commerce_file_license']['table']['group']  = t('Commerce File License');
  $data['commerce_file_license']['table']['base'] = array(
    'field' => 'license_id',
    'title' => t('Commerce File License'),
    'help' => t('File Licenses granted in the store.'),
  );

  // For other base tables, explain how we join
  // 'left_field' is the primary key in the referenced table.
  // 'field' is the foreign key in this table.
  $data['commerce_file_license']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'commerce_file_license_log' => array(
      'left_field' => 'license_id',
      'field' => 'license_id',
    ),
  );


  $data['commerce_file_license']['license_id'] = array(
    'title' => t('License ID', array(), array('context' => 'a drupal commerce file license')),
    'help' => t('The unique internal identifier of the license.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
  );

  // Expose the license type.
  // - only 1 type for now
/*
  $data['commerce_file_license']['type'] = array(
    'title' => t('License type', array(), array('context' => 'a drupal commerce file license')),
    'help' => t('The type of the license.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_type',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_file_handler_filter_license_type',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
*/

  $data['commerce_file_license']['status'] = array(
    'title' => t('License status'),
    'help' => t('The status of the license.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'commerce_file_handler_filter_license_status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['commerce_file_license']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the license was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_file_license']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the license was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_file_license']['uid'] = array(
    'title' => t('Owner uid'),
    'help' => t('Uid of the file license owner.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name', // display this field in the summary
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('License owner'),
    ),
  );

  $data['commerce_file_license']['granted'] = array(
    'title' => t('Granted date'),
    'help' => t('The date the license was initially granted.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );



  // -----------------------------------------------------------------------
  // Entity Property Fields

  // -- Limits ---------------------------------------------- //
  $data['commerce_file_license']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('The duration of the license.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_duration',
    ),
  );

  $data['commerce_file_license']['expiration'] = array(
    'title' => t('Expiration'),
    'help' => t('The date the license expires.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_expiration',
    ),
  );

  $data['commerce_file_license']['download_limit'] = array(
    'title' => t('Download limit'),
    'help' => t('The number of times the licensed file may be downloaded by the owner.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_limit',
    ),
  );

  $data['commerce_file_license']['address_limit'] = array(
    'title' => t('Address limit'),
    'help' => t('The number of different IP addresses from which the licensed file may be downloaded.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_limit',
    ),
  );


  // -- Access Stats ---------------------------------------- //

  $data['commerce_file_license']['download_count'] = array(
    'title' => t('Current number of downloads'),
    'help' => t('The current number of downloads of the licensed file.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_property',
    ),
  );

  $data['commerce_file_license']['address_count'] = array(
    'title' => t('Current number of addresses'),
    'help' => t('The current number of addresses used to access the licensed file.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_property',
    ),
  );

  $data['commerce_file_license']['time_remaining'] = array(
    'title' => t('Current time remaining'),
    'help' => t('The current time remaining until expiration the license.'),
    'field' => array(
      'handler' => 'commerce_file_handler_field_license_duration',
    ),
  );



  // -- Admin links ---------------------------------------- //
  $data['commerce_file_license']['view_license'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the view of the license.'),
      'handler' => 'commerce_file_handler_field_license_link',
    ),
  );
  $data['commerce_file_license']['edit_license'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the license.'),
      'handler' => 'commerce_file_handler_field_license_link_edit',
    ),
  );
  $data['commerce_file_license']['delete_license'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the license.'),
      'handler' => 'commerce_file_handler_field_license_link_delete',
    ),
  );


  return $data;
}

/**
 * Implements hook_views_plugins
 */
function commerce_file_views_plugins() {
  return array(
    'argument validator' => array(
      'commerce_file_user' => array(
        'title' => t('Commerce File User'),
        'handler' => 'commerce_file_plugin_argument_validate_user',
        'path' => drupal_get_path('module', 'commerce_file') . '/views/handlers', // not necessary for most modules
      ),
    ),
  );
}
