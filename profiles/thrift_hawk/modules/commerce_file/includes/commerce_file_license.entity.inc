<?php

/**
 * @file
 * Provides a base class for CommerceFileLicenseEntity.
 */

/**
 * A Commerce File License entity class.
 *
 * It's suggested, but not required, to extend this class and to override
 * __construct() in order to specify a fixed entity type.
 *
 * For providing an entity label and URI it is suggested to override the
 * defaultLabel() and defaultUri() methods, and to specify the
 * entity_class_label() and entity_class_uri() as respective callbacks in
 * hook_entity_info(). That way modules are able to override your defaults
 * by altering the hook_entity_info() callbacks, while $entity->label() and
 * $entity->uri() reflect this changes as well.
 */
class CommerceFileLicenseEntity extends Entity {
  const DATA_UNLIMITED = COMMERCE_FILE_FIELD_UNLIMITED;

  public $license_id;

  // database fields
  public $uid, $type, $status;
  public $created, $changed, $granted;

  // derived fields
  protected $state;
  protected $bundle, $fieldNames;
  protected $owner, $file;
  protected $limits, $addresses;
  protected $download_allowed = FALSE;


  /**
   * Determine if a value is set to UNLIMITED
   */
  public static function limit_is_unlimited($value) {
    return strcmp($value, self::DATA_UNLIMITED) === 0;
  }

  /**
   * Overridden __construct()
   *  - set fixed entity type
   *  - initialize fields
   */
  public function __construct($values = array(), $entityType = NULL) {
    parent::__construct($values, COMMERCE_FILE_LICENSE_ENTITY_NAME);
    $this->_init_fields();
  }

  /**
   * Initialize all unset fields for default field langauage
   */
  private function _init_fields() {
    $langcode = LANGUAGE_NONE;
    $fieldNames = $this->get_fieldNames();

    if (!empty($fieldNames)) {
      foreach ($fieldNames as $field_name) {
        if (!isset($this->{$field_name})) {
          $this->_init_field_value($field_name);
        }
      }
    }
  }


  // -----------------------------------------------------------------------
  // Expose static properties and methods

  /**
   * Return license property unlimited value
   */
  public function get_data_unlimited_value() {
    return self::DATA_UNLIMITED;
  }

  public function check_limit_is_unlimited($value) {
    return self::limit_is_unlimited($value);
  }


  // -----------------------------------------------------------------------
  // Base Class overridden methods

  /**
   * Implements save()
   */
  public function save() {
    return parent::save();
  }

  /**
   * Implements buildContent()
   *  - add custom fields to the output.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    return $this->get_controller()->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * Specifies the default label, which is picked up by label() by default.
   */
  protected function defaultLabel() {
    $parts = array();
    $file = $this->get_file();
    $owner = $this->get_owner();
    if (!empty($file['filename'])) {
      $parts[] = $file['filename'];
    }
    if (!empty($owner->name)) {
      $parts[] = ' ' . t('owned by ') . $owner->name;
    }

    if (!empty($parts)) {
      return implode(' ', $parts);
    }

    return $this->entityInfo['label'] . ' ' . $this->internalIdentifier();
  }

  /**
   * Specifies the default uri, which is picked up by uri() by default.
   */
  protected function defaultURI() {
    $path = '';
    if (isset($this->entityInfo['admin ui']['path'])) {
      $path = $this->entityInfo['admin ui']['path'] . '/manage/' . $this->internalIdentifier();
    }
    else {
      $path = 'admin/commerce/file-licenses/manage/' . $this->internalIdentifier();
    }

    return array('path' => $path);
  }


  // -----------------------------------------------------------------------
  // Class Methods

  /**
   * Access callback
   */
  public function access($op = 'view', $account = NULL) {
    return entity_access($op, $this->entityType, $this, $account);
  }

  /**
   * Invoke hook
   */
  public function invoke($hook) {
    $this->get_controller()->invoke($hook, $this);
    return $this;
  }

  /**
   * Returns true if license is in the active state
   */
  public function is_active() {
    if (isset($this->status)) {
      $active_statuses = commerce_file_license_statuses(array('state' => 'active'));
      return isset($active_statuses[$this->status]);
    }

    return FALSE;
  }

  /**
   * Log access to the license by the owner
   */
  public function log() {
    global $user;

    // log only if current user is owner
    if ($this->uid == $user->uid) {
      commerce_file_license_log_save(array($this->idKey => $this->internalIdentifier()));
    }

    return $this;
  }


  // -----------------------------------------------------------------------
  // Properties

  /**
   * Entity controller
   *  - Read only
   */
  public function get_controller() {
    return entity_get_controller($this->entityType);
  }

  /**
   * Wrapper
   *  - Read only
   */
  public function get_wrapper() {
    return entity_metadata_wrapper(COMMERCE_FILE_LICENSE_ENTITY_NAME, $this);
  }

  /**
   * Bundle
   *  - Read only
   */
  public function get_bundle() {
    if (!isset($this->bundle)) {
      // If no bundle key provided, then we assume a single bundle, named after the
      // entity type.
      $this->bundle = !empty($this->bundleKey) ? $this->{$this->bundleKey} : $this->entityType;
    }
    return $this->bundle;
  }

  /**
   * Status
   *  - Read / Write
   */
  public function set_status($value) {
    $statuses = commerce_file_license_statuses();
    if (!isset($statuses[$value])) {
      throw new Exception("Invalid Status: Attempted to set status to an invalid value of '$value'.");
    }

    $this->status = $value;
  }

  /**
   * State
   *  - Read only
   */
  public function get_state() {
    if (!isset($this->state)) {
      $status = commerce_file_license_status_load($this->status);
      $this->state = $status->state;
    }
  }

  /**
   * uid
   *  - Read / Write
   */
  public function set_uid($value) {
    if ($this->uid != $value) {
      $this->uid = $value;
      unset($this->owner);
    }
  }

  /**
   * Owner
   *  - Read only
   */
  public function get_owner() {
    if (!isset($this->owner)) {
      $this->owner = NULL;
      if (isset($this->uid)) {
        $this->owner = user_load($this->uid);
      }
    }
    return $this->owner;
  }

  /**
   * File
   *  - Read / Write
   */
  public function get_file() {
    if (!isset($this->file)) {
      $this->file = array();

      // aggregate file fields on this license
      $files = _commerce_file_field_aggregate_files($this, COMMERCE_FILE_LICENSE_ENTITY_NAME);
      if (!empty($files)) {
        // there can be only 1
        $this->file = reset($files);
      }
    }
    return $this->file;
  }

  public function set_file($field_value = array()) {
    if (!empty($field_value)) {
      $wrapper = $this->get_wrapper();
      $license_line_items_field_name = _commerce_file_get_field_names('license_line_items');

      if (empty($wrapper->{$license_line_items_field_name}) || !$wrapper->{$license_line_items_field_name}->count()) {
        // allow changing only if no line items
        $field_name = _commerce_file_get_field_names('license_file');
        $this->_set_field_value($field_name, $field_value, 'fid');
        $this->file = NULL;
        return TRUE;
      }
    }

    return FALSE;
  }


  // -----------------------------------------------------------------------
  // Field handling

  /**
   * Get field value
   */
  protected function _get_field_value($field_name) {
    $wrapper = $this->get_wrapper();
    if (!empty($wrapper->{$field_name})) {
      return $wrapper->{$field_name}->value();
    }

    return NULL;
  }

  /**
   * Initialize a field value array
   */
  protected function _init_field_value($field_name, $langcode = LANGUAGE_NONE) {
    if (empty($this->{$field_name})) {
      $this->{$field_name} = array($langcode => array());
    }
    elseif (empty($this->{$field_name}[$langcode])) {
      $this->{$field_name}[$langcode] = array();
    }
  }

  /**
   * Set field value
   *
   * @return
   *   TRUE if set
   */
  protected function _set_field_value($field_name, $field_value = array()) {
    $langcode = LANGUAGE_NONE;

    // ensure field is initialized
    $this->_init_field_value($field_name);

    // set value via wrapper to ensure proper setting
    $wrapper = $this->get_wrapper();
    $wrapper->{$field_name} = $field_value;
  }

  /**
   * Add field value
   *
   * @return
   *   TRUE if added
   */
  protected function _add_field_value($field_name, $new_item = NULL, $id_key = NULL) {
    $langcode = LANGUAGE_NONE;

    // ensure field is initialized
    $this->_init_field_value($field_name);

    // add new item if it doesn not exist already
    if (!empty($new_item)) {
      if (!empty($id_key)) {
        // exit if item exists
        foreach ($this->{$field_name}[$langcode] as $delta => $item) {
          if (isset($item[$id_key]) && isset($new_item[$id_key]) && $item[$id_key] == $new_item[$id_key]) {
            return FALSE;
          }
        }
      }

      // add it if we got here
      $this->{$field_name}[$langcode][] = $new_item;

      /** @todo: does this handle other languages or should we be setting with wrapper? ***************************/
    }

    return TRUE;
  }

  /**
   * Get a read only field wrapper
   */
  protected function _get_field_wrapper($field_name) {
    $wrapper = $this->get_wrapper();
    if (!empty($wrapper->{$field_name})) {
      return $wrapper->{$field_name};
    }

    return NULL;
  }

  /**
   * Field Instances
   *  - Read only
   */
  public function get_fieldNames() {
    if (!isset($this->fieldNames)) {
      $instances = field_info_instances($this->entityType, $this->get_bundle());
      $this->fieldNames = !empty($instances) ? array_keys($instances) : array();
    }
    return $this->fieldNames;
  }


  // -----------------------------------------------------------------------
  // Line Item handling

  /**
   * Add a line item
   *
   * @return
   *   TRUE if a new line item was linked
   */
  public function link_line_item($new_line_item_id) {
    $field_name = _commerce_file_get_field_names('license_line_items');
    return $this->_add_field_value($field_name, array('line_item_id' => $new_line_item_id), 'line_item_id');
  }

  /**
   * Remove a line item
   *
   * @return
   *   TRUE if the line item was unlinked
   */
  public function unlink_line_item($line_item_id) {
    $field_name = _commerce_file_get_field_names('license_line_items');
    $line_item_field = $this->_get_field_value($field_name);

    $changed = FALSE;
    foreach ($line_item_field as $k => $line_item_field_item) {
      if ($line_item_field_item->line_item_id == $line_item_id) {
        unset($line_item_field[$k]);
        $changed = TRUE;
      }
    }

    if ($changed) {
      $this->_set_field_value($field_name, $line_item_field);
    }

    return $changed;
  }


  // -----------------------------------------------------------------------
  // Limits handling

  /**
   * Aggregated Limits
   *
   * @return
   *   An array of aggregated limits for this license
   */
  public function get_limits() {
    if (!isset($this->limits)) {
      $this->limits = array();

      $native = $this->get_file();
      if (empty($native)) {
        return $this->limits;
      }

      // get license wrapper
      $wrapper = $this->get_wrapper();

      // initialize items and add native as trunk
      $items = array($native);
      $native_fid = $native['fid'];

      // line item entity fields
      $line_item_file_field_name = _commerce_file_get_field_names('line_item_files');

      // license fields
      $license_line_items_field_name = _commerce_file_get_field_names('license_line_items');

      // process license line items
      if (!empty($wrapper->{$license_line_items_field_name})) {
        foreach ($wrapper->{$license_line_items_field_name} as $delta => $line_item_wrapper) {
          // exit if no file fiel on line item
          if (empty($line_item_wrapper->{$line_item_file_field_name})) {
            continue;
          }

          // set qty and exit if there is no qty
          $line_qty = $line_item_wrapper->quantity->value();
          if (empty($line_qty)) {
            continue;
          }

          // aggregate files on the line item
          $line_aggregated = _commerce_file_field_aggregate_files($line_item_wrapper->value(), 'commerce_line_item');

          // only add files for our license fid
          if (isset($line_aggregated[$native_fid])) {
            // multiply by quantity if setting is aggregated
            foreach ($line_item_wrapper->{$line_item_file_field_name} as $file_field_wrapper) {
              foreach ($file_field_wrapper->data as $k => $data) {
                if (isset($line_aggregated[$native_fid]['data'][$k]) && !self::limit_is_unlimited($line_aggregated[$native_fid]['data'][$k])) {
                  $data_info = $data->info();
                  if (!empty($data_info) && !empty($data_info['aggregated'])) {
                    $line_aggregated[$native_fid]['data'][$k] *= $line_qty;
                  }
                }
              }
            }

            // store in all items
            $items[] = $line_aggregated[$native_fid];
          }
        }
      }

      // aggregated = native field + sum of all (line item fields X quantity)
      $aggregated = call_user_func_array('_commerce_file_field_aggregate_field_items', $items);

      // store in license
      if (!empty($aggregated['data'])) {
        $this->limits = $aggregated['data'];
      }
    }

    return $this->limits;
  }

  /**
   * Duration
   */
  public function get_duration() {
    $limits = $this->get_limits();
    if (isset($limits['duration'])) {
      return $limits['duration'];
    }
  }

  /**
   * Expiration
   */
  public function get_expiration() {
    $duration = $this->get_duration();

    if (!empty($this->granted) && isset($duration) && !self::limit_is_unlimited($duration)) {
      return $this->granted + $duration;
    }
  }


  // -----------------------------------------------------------------------
  // Access stats

  public function get_logs() {
    return commerce_file_license_log_load_multiple(FALSE, array($this->idKey => $this->internalIdentifier()));
  }
  public function get_download_count() {
    return count($this->get_logs());
  }

  public function get_addresses() {
    if (!isset($this->addresses)) {
      $addrs = array();
      foreach ($this->get_logs() as $log) {
        $addrs[$log->hostname] = $log->hostname;
      }
      $this->addresses = $addrs;
    }

    return $this->addresses;
  }
  public function get_address_count() {
    return count($this->get_addresses());
  }

  public function get_request_time() {
    return REQUEST_TIME;
  }

  public function get_time_remaining() {
    $expiration = $this->get_expiration();
    if (isset($expiration)) {
      $delta = $expiration - REQUEST_TIME;
      return $delta > 0 ? $delta : 0;
    }
  }



  // -----------------------------------------------------------------------
  // Magic Methods

  /**
   * Get / Set
   *  - method is preferred with lazy fallback to object property
   */
  public function __get($name) {
    $method = "get_$name";
    if (method_exists($this, $method)) {
      return $this->{$method}();
    }

    // allow lazy get
    if (isset($this->{$name})) {
      return $this->{$name};
    }
    return NULL;
  }

  public function __set($name, $value) {
    $method = "set_$name";
    if (method_exists($this, $method)) {
      $this->{$method}($value);
    }
    elseif (!method_exists($this, "get_$name")) {
      // allow lazy setting for non read only properties
      $this->{$name} = $value;
    }
  }

  public function __isset($name) {
    $value = $this->__get($name);
    return isset($value);
  }

  public function __unset($name) {
    unset($this->{$name});
  }

}
