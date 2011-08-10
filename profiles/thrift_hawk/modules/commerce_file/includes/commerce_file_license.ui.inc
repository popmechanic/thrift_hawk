<?php

/**
 * @file
 * Provides a controller for building an entity overview form.
 */


/** @todo might not need this class, but here for customization ********************************/

/**
 * Default controller for providing UI.
 */
class CommerceFileLicenseEntityUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    return $items;
  }

}
