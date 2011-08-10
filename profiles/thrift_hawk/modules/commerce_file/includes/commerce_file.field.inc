<?php

/**
 * @file
 * Implement an commerce_file field, based on the file module's file field.
 */

// -----------------------------------------------------------------------
// Constants

// field type name this module defines
define('COMMERCE_FILE_FIELD_TYPE', 'commerce_file');

// unlimited value
define('COMMERCE_FILE_FIELD_UNLIMITED', 'UNLIMITED');

// inherited value - assuemed to be an integer value
define('COMMERCE_FILE_FIELD_INHERIT', -1);

// -----------------------------------------------------------------------


/**
 * Implements hook_field_info().
 */
function commerce_file_field_info() {
  // build base field info
  $base = array(
    'label' => t('Commerce File'),
    'description' => t('This field stores the ID of a licensed file as an integer value.'),
    'settings' => array(
      'uri_scheme_options' => array_keys(_commerce_file_get_private_stream_wrappers_options()),
    ),
    'instance_settings' => array(
      'uri_scheme' => _commerce_file_default_system_scheme(),
      'file_extensions' => 'mp4 m4v flv wmv mp3 wav jpg jpeg png pdf doc docx ppt pptx xls xlsx',
      'file_directory' => '',
      'max_filesize' => '',
    ),
    'default_widget' => 'commerce_file_generic',
    'default_formatter' => 'file_default',
    'property_type' => 'commerce_file',
    'property_callbacks' => array('commerce_file_field_property_info_callback'),
  );

  // set license settings default to unlimited
  $license_info = _commerce_file_collate_license_info();
  $instance_defaults = array();
  foreach ($license_info as $k => $info) {
    $instance_defaults[$k] = isset($info['property info']['default']) ? $info['property info']['default'] : COMMERCE_FILE_FIELD_UNLIMITED;
  }
  $base['instance_settings'] += array('data' => $instance_defaults);

  return array(
    COMMERCE_FILE_FIELD_TYPE => array_merge_recursive($base + array(
      'label' => t('Commerce File'),
      'description' => t('This field stores the ID of a licensed file as an integer value.'),
    )),
  );
}

/**
 * Implements hook_field_formatter_info_alter().
 */
function commerce_file_field_formatter_info_alter(&$info) {
  // Add type to file formatters
  $info['file_default']['field types'][] = COMMERCE_FILE_FIELD_TYPE;
  $info['file_table']['field types'][] = COMMERCE_FILE_FIELD_TYPE;
  $info['file_url_plain']['field types'][] = COMMERCE_FILE_FIELD_TYPE;
}

/**
 * Implements hook_field_settings_form().
 */
function commerce_file_field_settings_form($field, $instance, $has_data) {
  $form = array();
  $defaults = field_info_field_settings($field['type']);
  $settings = array_merge($defaults, $field['settings']);

  $scheme_options = _commerce_file_get_private_stream_wrappers_options();

  if (!empty($scheme_options)) {
    $form['uri_scheme_options'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Allowed private upload destinations'),
      '#options' => $scheme_options,
      '#default_value' => $settings['uri_scheme_options'],
      '#disabled' => $has_data,
      '#element_validate' => array('_commerce_file_element_validate_checkboxes')
    );
  }
  else {
    drupal_set_message(t('Commerce File requires a private file scheme. Visit <a href="!url">admin/config/media/file-system</a> to set your private file path. Optionally, a private scheme other than Drupal\'s may be implemented.', array('!url' => url('admin/config/media/file-system'))), 'error');
  }

  return $form;
}

/**
 * Implements hook_field_instance_settings_form().
 */
function commerce_file_field_instance_settings_form($field, $instance) {
  $settings = $instance['settings'];

  // Use the file field instance settings form as a basis.
  $form = file_field_instance_settings_form($field, $instance);

  // build form
  _commerce_file_field_add_license_elements($form, 'instance', $settings);

  // Remove the description option.
  unset($form['description_field']);

  return $form;
}

/**
 * Implements hook_field_load().
 */
function commerce_file_field_load($entity_type, $entities, $field, $instances, $langcode, &$items, $age) {
  foreach ($entities as $id => $entity) {
    foreach ($items[$id] as $delta => $item) {
      // Unserialize the data array if necessary.
      if (!empty($items[$id][$delta]['data']) && is_string($items[$id][$delta]['data'])) {
        $items[$id][$delta]['data'] = unserialize($items[$id][$delta]['data']);
      }
      else {
        $items[$id][$delta]['data'] = array();
      }
    }
  }

  file_field_load($entity_type, $entities, $field, $instances, $langcode, $items, $age);
}

/**
 * Implements hook_field_prepare_view().
 */
//function commerce_file_field_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items) {
  // set default values for fields set to use default instance settings
//}

/**
 * Implements hook_field_presave().
 */
function commerce_file_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
   foreach ($items as $delta => $item) {
    // Serialize an existing data array.
    if (isset($item['data']) && is_array($item['data'])) {
      $items[$delta]['data'] = serialize($item['data']);
    }
  }

  file_field_presave($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_insert().
 */
function commerce_file_field_insert($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_insert($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_update().
 */
function commerce_file_field_update($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_update($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_delete().
 */
function commerce_file_field_delete($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_delete($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_delete_revision().
 */
function commerce_file_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, &$items) {
  file_field_delete_revision($entity_type, $entity, $field, $instance, $langcode, $items);
}

/**
 * Implements hook_field_is_empty().
 */
function commerce_file_field_is_empty($item, $field) {
  return file_field_is_empty($item, $field);
}

/**
 * Implements hook_field_widget_info().
 */
function commerce_file_field_widget_info() {
  $base = array(
    'field types' => array('commerce_file'),
    'settings' => array(
      'uri_scheme' => _commerce_file_default_system_scheme(),
      'progress_indicator' => 'throbber',
    ),
    'behaviors' => array(
      'multiple values' => FIELD_BEHAVIOR_CUSTOM,
      'default value' => FIELD_BEHAVIOR_NONE,
    ),
  );

  // set license settings default to inherited
  $license_info = _commerce_file_collate_license_info();
  $base['settings'] += array('data' => array_fill_keys(array_keys($license_info), COMMERCE_FILE_FIELD_INHERIT));

  // return widgets
  return  array(
    'commerce_file_generic' => array_merge_recursive($base, array(
      'label' => t('Commerce File'),
    )),
  );
}

/**
 * Implements hook_filefield_sources_widgets().
 *
 * This returns a list of widgets that are compatible with FileField Sources.
 */
function commerce_file_filefield_sources_widgets() {
  // Add any widgets that your module supports here.
  return array('commerce_file_generic');
}

/**
 * Implements hook_field_widget_settings_form().
 */
function commerce_file_field_widget_settings_form($field, $instance) {
  $widget = $instance['widget'];
  $settings = $widget['settings'];

  // Use the file widget settings form.
  $form = file_field_widget_settings_form($field, $instance);

  return $form;
}

/**
 * Implements hook_field_widget_form().
 */
function commerce_file_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  // Add display_field setting to field because file_field_widget_form() assumes it is set.
  $field['settings']['display_field'] = 0;

  // file_field_widget_form() needs uri_scheme on field settings
  $uri_scheme = '';
  if (!empty($instance['widget']['uri_scheme'])) {
    $uri_scheme = $instance['widget']['uri_scheme'];
  }
  elseif (!empty($instance['settings']['uri_scheme'])) {
    $uri_scheme = $instance['settings']['uri_scheme'];
  }
  else {
    $uri_scheme = _commerce_file_field_default_scheme($field, $instance);
  }

  $field['settings']['uri_scheme'] = $uri_scheme;

  // build elements with file_field
  $elements = file_field_widget_form($form, $form_state, $field, $instance, $langcode, $items, $delta, $element);

  // add properties to each element for widget process
  $upload_destination = _commerce_file_tokenize_directory($instance['settings']['file_directory']);
  foreach (element_children($elements) as $delta) {
    $elements[$delta]['#entity_type'] = $instance['entity_type'];
    $elements[$delta]['#upload_destination'] = $upload_destination;
    $elements[$delta]['#value_callback'] = '_commerce_file_field_widget_value';
    $elements[$delta]['#process'][] = '_commerce_file_field_widget_process';

    if ($instance['entity_type'] == COMMERCE_FILE_LICENSE_ENTITY_NAME) {
      $elements[$delta]['#inheritable'] = FALSE;
    }

    // add license limit settings
    $element_settings = isset($elements[$delta]['#default_value']) ? $elements[$delta]['#default_value'] : array();
    _commerce_file_field_add_license_elements($elements[$delta], 'widget', $element_settings, $instance['settings']);
  }

  return $elements;
}

/**
 * An element #process callback for the commerce_file_commerce_file field type.
 *
 * Include custom settings
 */
function _commerce_file_field_widget_process($element, &$form_state, $form) {
  $item = $element['#value'];
  $item['fid'] = $element['fid']['#value'];
  $field = field_widget_field($element, $form_state);
  $instance = field_widget_instance($element, $form_state);

  $element['#theme'] = 'file_widget';
  $element['#attached']['css'][] = drupal_get_path('module', 'commerce_file') . '/css/commerce_file.forms.css';

  if (isset($element['#attributes']['class'])) {
    $element['#attributes']['class'] = array_merge($element['#attributes']['class'], array('file-commerce-file'));
  }
  else {
    $element['#attributes']['class'] = array('file-commerce-file');
  }

  // get scheme options
  $available_scheme_options = _commerce_file_get_private_stream_wrappers_options();
  $scheme_options = _commerce_file_get_private_stream_wrappers_options($field['settings']['uri_scheme_options']);

  // determine default uri_scheme
  $default_scheme = NULL;
  if ($item['fid'] && isset($item['uri'])) {
    // use actual file's scheme
    $default_scheme = file_uri_scheme($item['uri']);

    // force this file's scheme into options if its not in the field selected options
    if (!isset($scheme_options[$default_scheme])) {
      if (isset($available_scheme_options[$default_scheme])) {
        $scheme_options[$default_scheme] = $available_scheme_options[$default_scheme];
      }
      else {
        $scheme_options[$default_scheme] = t('Unknown file scheme');
      }
    }
  }
  elseif (!empty($scheme_options)) {
    // use settings default
    $default_scheme = _commerce_file_field_default_scheme($field, $instance);
  }

  // Warn if there are no scheme options and no default scheme pushed in if we have a file
  if (empty($scheme_options)) {
    $element['#disabled'] = TRUE;
    $error_msg = t('You cannot upload a file. Commerce File requires a private file scheme. Visit <a href="!url">admin/config/media/file-system</a> to set your private file path. Optionally, a private scheme other than Drupal\'s may be implemented.', array('!url' => url('admin/config/media/file-system')));
    if (!empty($available_scheme_options)) {
      $error_msg .= t('<br />There are private file schemes available on your system. Visit the field settings to select schemes allowed for this field.');
    }

    form_error($element, $error_msg);
  }

  // build form
  $scheme_count = count($scheme_options);

  if ($instance['widget']['type'] == 'commerce_file_generic') {
    $element['uri_scheme'] = array(
      '#type' => 'radios',
      '#title' => t('Upload destination'),
      '#options' => $scheme_options,
      '#default_value' => $default_scheme,
      '#description' => t('Select where the final files should be stored. Private file storage has significantly more overhead than public files, but allows restricted access to files within this field.'),
      '#disabled' => !empty($item['fid']),
    );

    // set above file field in an attempt to get them to select first before uploading
    if (!$item['fid']) {
      $element['uri_scheme']['#weight'] = -100;
    }

    // remove upload button due to workflow of selecting scheme before upload
    if ($scheme_count > 1) {
      unset($element['upload_button']);
    }
  }

  return $element;
}

/**
 * The #value_callback for the commerce_file_generic field element.
 */
function _commerce_file_field_widget_value($element, $input = FALSE, $form_state) {
  if ($input !== FALSE) {
    // process license settings for textfields
    $license_info = _commerce_file_collate_license_info();
    foreach ($license_info as $k => $info) {
      if (isset($input['data'][$k])) {
        if ($info['base_element']['#type'] == 'textfield') {
          $input['data'][$k] = (!empty($input['data'][$k]) || $input['data'][$k] === '0') ? intval($input['data'][$k]) : COMMERCE_FILE_FIELD_UNLIMITED;
        }

        // set to special value if the input is equal to the inherited value
        if (isset($element['data'][$k]['#inherited_value']) && $input['data'][$k] == $element['data'][$k]['#inherited_value']) {
          $input['data'][$k] = COMMERCE_FILE_FIELD_INHERIT;
        }
      }
    }

    // set scheme for uploaded file
    if (isset($input['uri_scheme'])) {
      $element['#upload_location'] = $input['uri_scheme'] . '://' . (!empty($element['#upload_destination']) ? $element['#upload_destination'] : '');
    }
  }

  // call file field's value callback to perform managed_file operations
  return file_field_widget_value($element, $input, $form_state);
}


// -----------------------------------------------------------------------
// Form element functions

/**
 * License settings element generator
 */
function _commerce_file_field_add_license_elements(&$parent, $level = 'field', $settings = array(), $inherited_settings = array()) {
  $base = array();
  $defaults = array();
  $license_info = _commerce_file_collate_license_info();

  // allow parent element to suggest inheritable
  $parent_inheritable = isset($parent['#inheritable']) ? $parent['#inheritable'] : TRUE;
  $have_inherited_settings = !empty($inherited_settings);

  switch ($level) {
    case 'widget':
      $defaults = field_info_instance_settings(COMMERCE_FILE_FIELD_TYPE);
      break;
    case 'instance':
      $defaults = field_info_instance_settings(COMMERCE_FILE_FIELD_TYPE);
      break;
    default:
      $defaults = field_info_field_settings(COMMERCE_FILE_FIELD_TYPE);
      break;
  }

  // Initialize license base elements
  foreach ($license_info as $k => &$info) {
    // initialize base element if not defined
    if (!isset($info['base_element'])) {
      $info['base_element'] = array();
    }

    // set base element #inheritable property
    if ($have_inherited_settings) {
      // allow setting definition to override if explicitly set to NOT inherit
      // else set to parent's inheritable
      if (!isset($info['property info']['inheritable']) || $info['property info']['inheritable']) {
        $info['base_element']['#inheritable'] = $parent_inheritable;
      }
    }
    else {
      // force to not inheritable if not inherited settings given
      $info['base_element']['#inheritable'] = FALSE;
    }
  }
  unset($info);

  // build inherited settings for license settings
  $inherited = array('descriptions' => array(), 'values' => array());
  if ($have_inherited_settings) {
    $inherited_tokens = array();

    // alter license info array
    foreach ($license_info as $k => &$info) {
      // skip if non-inheritable
      if (empty($info['base_element']['#inheritable'])) {
        continue;
      }

      // retrieve inherited value
      $inherited['values'][$k] = $inherited_value_k = _commerce_file_license_resolve_setting_value(NULL, $inherited_settings['data'][$k]);
      if (!isset($inherited_value_k)) {
        continue;
      }

      // build inherited description
      $inherited_tokens['%inherited_setting'] = $inherited_value_k;
      $inherited['descriptions'][$k] = t('The default currently is <strong class="commerce-file-inherited-value">%inherited_setting</strong>.', $inherited_tokens);

      // if no setting value then set to inherit by default
      if (!isset($settings['data'][$k])) {
        $settings['data'][$k] = COMMERCE_FILE_FIELD_INHERIT;
      }

      // prepend inherit option to select lists
      if (isset($info['base_element']['#type']) && $info['base_element']['#type'] == 'select') {
        // initialize options
        if (!isset($info['base_element']['#options'])) {
          $info['base_element']['#options'] = array();
        }

        if (!isset($info['base_element']['#options'][COMMERCE_FILE_FIELD_INHERIT])) {
          // Append 'Default' to inherited value
          if (isset($info['base_element']['#options'][$inherited_value_k])) {
            $info['base_element']['#options'][$inherited_value_k] .= ' ' . t('(Default)');
          }
          elseif (_commerce_file_field_setting_is_unlimited($inherited_value_k)) {
            $info['base_element']['#options'] = array($inherited_value_k => t('- Unlimited - (Default)')) + $info['base_element']['#options'];
          }
        }
      }
    }
    unset($info);
  }
  else {
    $inherited_settings = array();
  }

  // merge all defaults
  $values = array_merge($defaults, $inherited_settings, $settings);

  // build form elements
  $elements = array();
  $unlimited_description = t('Leave blank for unlimited.');

  foreach ($license_info as $k => $info) {
    if (!isset($values['data'][$k])) {
      continue;
    }

    // set default value to inherited value if defined
    $default_value = $values['data'][$k];
    $inherited_value = isset($inherited['values'][$k]) ? $inherited['values'][$k] : NULL;
    if (_commerce_file_field_setting_is_inherited($default_value)) {
      $default_value = $inherited_value;
    }

    // initialize element with default value and base element
    $elements[$k] = array('#default_value' => $default_value) + $info['base_element'];
    if (!empty($info['base_element']['#inheritable'])) {
      $elements[$k]['#inherited_value'] = $inherited_value;
    }

    // process specific element types
    switch ($elements[$k]['#type']) {
      case 'textfield':
        // set unlimited to empty '' for textfields
        if (_commerce_file_field_setting_is_unlimited($elements[$k]['#default_value'])) {
          $elements[$k]['#default_value'] = '';
        }

        // add integer validator
        if (!isset($elements[$k]['#element_validate'])) {
          if (isset($info['property info']['type']) && $info['property info']['type'] == 'integer') {
            $elements[$k]['#element_validate'] = array('_commerce_file_element_validate_license_textfield');
          }
        }

        // append description for unlimited.
        if (!empty($unlimited_description)) {
          if (!empty($elements[$k]['#description'])) {
            $elements[$k]['#description'] .= ' ' . $unlimited_description;
          }
          else {
            $elements[$k]['#description'] = $unlimited_description;
          }
        }
        break;

      case 'select':
        // add unlimited option
        $options = &$elements[$k]['#options'];
        if (empty($options)) {
          $options = array(COMMERCE_FILE_FIELD_UNLIMITED => t('- Unlimited -'));
        }
        elseif (!isset($options[COMMERCE_FILE_FIELD_UNLIMITED])) {
          $options = array(COMMERCE_FILE_FIELD_UNLIMITED => t('- Unlimited -')) + $options;
        }
        unset($options);
        break;
    }

    // extend description with inherited description
    if ($elements[$k]['#type'] != 'select' && isset($inherited['descriptions'][$k])) {
      if (!empty($elements[$k]['#description'])) {
        $elements[$k]['#description'] .= ' ' . $inherited['descriptions'][$k];
      }
      else {
        $elements[$k]['#description'] = $inherited['descriptions'][$k];
      }
    }
  }

  // update parent with settings elements
  if (!empty($elements)) {
    $element_container = array(
      '#type' => 'fieldset',
      '#title' => t('Access Limits'),
      '#collapsible' => TRUE,
      '#collapsed' => !empty($settings['fid']),
      '#weight' => 150,
    );

    // merge settings into parent element
    $parent = array_merge($parent, array('data' => ($element_container + $elements)));
  }
}

/**
 * Validate checkbox elements
 *  - remove empty options
 */
function _commerce_file_element_validate_checkboxes($element, &$form_state) {
  form_set_value($element, array_filter($element['#value']), $form_state);
}

/**
 * Helper form element validator: integer >= 0.
 */
function _commerce_file_element_validate_license_textfield($element, &$form_state) {
  $value = $element['#value'];
  $inheritable = !empty($element['#inheritable']);

  // PASS if element is inheritable and value is inherit
  if ($inheritable && _commerce_file_field_setting_is_inherited($value)) {
    return;
  }

  // check if integer >= 0
  if ($value !== '' && (!is_numeric($value) || intval($value) != $value || $value < 0)) {
    $msg = t('%name must be a positive integer or empty for no limit.', array(
      '%name' => $element['#title'],
    ));

    form_error($element, $msg);
  }
}

/**
 * Resolve default scheme based on field, instance, and widget settings
 */
function _commerce_file_field_default_scheme($field, $instance) {
  // get available schemes filtered by field options
  $schemes = _commerce_file_get_private_stream_wrappers($field['settings']['uri_scheme_options']);
  if (empty($schemes)) {
    return NULL;
  }

  // return valid default
  $default = $instance['settings']['uri_scheme'];
  if (!isset($default) || !isset($schemes[$default])) {
    $default = key($schemes);
  }

  return $default;
}

/**
 * Resolves license settings values with inheritance of instance settings
 */
function _commerce_file_license_resolve_setting_value($value, $inherited_value) {
  if (!isset($value) || _commerce_file_field_setting_is_inherited($value)) {
    // check if inherited value is set to unlimited - blank textfields are unlimited
    if (!empty($inherited_value) || $inherited_value === '0') {
      return $inherited_value;
    }

    // default to unlimited
    return COMMERCE_FILE_FIELD_UNLIMITED;
  }

  return $value;
}

/**
 * Check if field limit setting value is set to Unlimited
 */
function _commerce_file_field_setting_is_unlimited($value) {
  return strcmp($value, COMMERCE_FILE_FIELD_UNLIMITED) === 0;
}

/**
 * Check if field limit setting value is set to Unlimited
 */
function _commerce_file_field_setting_is_inherited($value) {
  return strcmp($value, COMMERCE_FILE_FIELD_INHERIT) === 0;
}


// -----------------------------------------------------------------------
// Field property info

/**
 * Callback to alter the property info of price fields.
 *
 * @see commerce_file_field_info().
 */
function commerce_file_field_property_info_callback(&$info, $entity_type, $field, $instance, $field_type) {
  $name = $field['field_name'];
  $property = &$info[$entity_type]['bundles'][$instance['bundle']]['properties'][$name];

  $property['type'] = ($field['cardinality'] != 1) ? 'list<commerce_file>' : 'commerce_file';
  $property['getter callback'] = 'entity_metadata_field_verbatim_get';
  $property['setter callback'] = 'entity_metadata_field_verbatim_set';
  $property['property info'] = commerce_file_field_data_property_info($name);

  unset($property['query callback']);
}


/**
 * Defines info for the properties of the Price field data structure.
 */
function commerce_file_field_data_property_info($name = NULL) {
  return array(
    'file' => array(
      'label' => t('File'),
      'description' => !empty($name) ? t('The file of field %name', array('%name' => $name)) : '',
      'type' => 'file',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
    ),
    'data' => array(
      'label' => t('Data'),
      'description' => !empty($name) ? t('License data array of field %name', array('%name' => $name)) : '',
      'type' => 'struct',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'property info' => _commerce_file_license_data_property_info(),
    ),
  );
}



// -----------------------------------------------------------------------
// Field item operations

/**
 * Resolve all settings for a given field item
 */
function _commerce_file_license_resolve_settings($field_item, $instance) {
  if (empty($field_item['data']) || empty($instance['settings']['data'])) {
    return $field_item;
  }

  // get license setting info
  $license_info = _commerce_file_collate_license_info();

  // resolve only settings defined in license info
  foreach ($field_item['data'] as $setting_key => &$setting_value) {
    if (isset($license_info[$setting_key]) && isset($instance['settings']['data'][$setting_key])) {
      $setting_value = _commerce_file_license_resolve_setting_value($setting_value, $instance['settings']['data'][$setting_key]);
    }
  }
  unset($setting_value);

  return $field_item;
}

/**
 * Aggregate one or more field items' settings into the first field item
 *  - assumes all settings have been resolved for all items
 */
function _commerce_file_field_aggregate_field_items($field_item1/*, $field_item2, ... */) {
  $args = func_get_args();
  $trunk = array_shift($args);

  if (empty($args)) {
    return $trunk;
  }

  foreach ($args as $field_item) {
    if (!isset($field_item['data'])) {
      continue;
    }

    if (!isset($trunk['data'])) {
      $trunk['data'] = $field_item['data'];
    }
    else {
      $trunk['data'] = _commerce_file_license_property_merge($trunk['data'], $field_item['data']);
    }
  }

  return $trunk;
}


// -----------------------------------------------------------------------
// Create field

/**
 * Creates a locked instance of a commerce file field on the specified bundle.
 *
 * @param $field_name
 *   The name of the field; if it already exists, a new instance of the existing
 *     field will be created. For fields governed by the Commerce modules, this
 *     should begin with commerce_.
 * @param $entity_type
 *   The type of entity the field instance will be attached to.
 * @param $bundle
 *   The bundle name of the entity the field instance will be attached to.
 * @param $label
 *   The label of the field instance.
 * @param $weight
 *   The default weight of the field instance widget and display.
 * @param $cardinality
 *   A string indicating the default value of the display formatter's calculation
 *     setting.
 * @param $display
 *   An array of default display data used for the entity's current view modes.
 */
function _commerce_file_create_file_instance($field_name, $entity_type, $bundle, $label, $weight = 0, $cardinality = FIELD_CARDINALITY_UNLIMITED, $required = FALSE) {
  _commerce_file_create_instance(COMMERCE_FILE_FIELD_TYPE, $field_name, $entity_type, $bundle, array(
      'field' => array(
        'cardinality' => $cardinality,
        'locked' => TRUE,
        'uri_scheme_options' => array_keys(_commerce_file_get_private_stream_wrappers_options()),
      ),
      'instance' => array(
        'label' => $label,
        'required' => $required,
        'uri_scheme' => _commerce_file_default_system_scheme(),
        'file_directory' => 'licenses',
        'file_extensions' => 'mp4 m4v flv wmv mp3 wav jpg jpeg png pdf doc docx ppt pptx xls xlsx',
        'widget' => array(
          'type' => 'commerce_file_generic',
          'weight' => $weight,
        ),
        'display' => array('default' => array('label' => 'hidden')),
      ),
  ));
}


// -----------------------------------------------------------------------
// Entity field items

/**
 * Return all commerce_file fields for a given entity, indexed by fid
 */
function _commerce_file_field_aggregate_files($entity, $entity_type = NULL) {
  $aggregated = array();
  $field_type = COMMERCE_FILE_FIELD_TYPE;

  if (empty($entity_type)) {
    $entity_type = _commerce_file_get_entity_type($entity);
    if (empty($entity_type)) {
      return $aggregated;
    }
  }

  // get some entity info
  $entity_wrapper = entity_metadata_wrapper($entity_type, $entity);
  $entity_id = $entity_wrapper->getIdentifier();
  $entity_bundle = $entity_wrapper->getBundle();

  // get field instances for type and bundle
  $instances = _commerce_file_field_info_instances($entity_type, $entity_bundle, $field_type);
  if (empty($instances)) {
    return $aggregated;
  }

  $file_items = array();
  foreach ($instances as $field_name => $instance) {
    $items = $entity_wrapper->{$field_name}->value();
    if (empty($items)) {
      continue;
    }

    // make an array for single value
    if (isset($items['fid'])) {
      $items = array($items);
    }

    // index items on fid
    foreach ($items as $item) {
      if (isset($item['fid'])) {
        $file_items[$item['fid']][] = _commerce_file_license_resolve_settings($item, $instance);
      }
    }
  }

  // aggregate per file
  foreach ($file_items as $fid => $items) {
    $aggregated[$fid] = call_user_func_array('_commerce_file_field_aggregate_field_items', $items);
  }

  return $aggregated;
}

/**
 * Return all commerce_file field type instances
 */
function _commerce_file_field_info_instances($entity_type, $entity_bundle, $field_type = COMMERCE_FILE_FIELD_TYPE) {
  $cache = &drupal_static(__FUNCTION__);

  $field_type = !empty($field_type) ? $field_type : COMMERCE_FILE_FIELD_TYPE;
  $cid = "{$entity_type}::{$entity_bundle}::{$field_type}";

  if (!isset($cache[$cid])) {
    $cache[$cid] = array();

    // find all fields instances
    $instances = field_info_instances($entity_type, $entity_bundle);
    if (!empty($instances)) {
      // find all instances for field type
      foreach ($instances as $field_name => $instance) {
        $field_info = field_info_field($field_name);
        if ($field_info['type'] == $field_type) {
           $cache[$cid][$field_name] = $instance;
        }
      }
    }
  }

  return $cache[$cid];
}
