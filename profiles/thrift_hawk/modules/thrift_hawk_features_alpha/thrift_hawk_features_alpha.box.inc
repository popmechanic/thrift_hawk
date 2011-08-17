<?php
/**
 * @file
 * thrift_hawk_features_alpha.box.inc
 */

/**
 * Implementation of hook_default_box().
 */
function thrift_hawk_features_alpha_default_box() {
  $export = array();

  $box = new stdClass;
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'welcome';
  $box->plugin_key = 'simple';
  $box->title = 'Use Craigslist to Find the Best Prices on Canon 85mm FD Lenses';
  $box->description = 'Landing page copy';
  $box->options = array(
    'body' => array(
      'value' => 'The Canon FD lens mount is a physical standard for connecting a photographic lens to a single-lens reflex camera body. The standard was developed by Canon of Japan and was introduced in March 1971 with the Canon F-1 camera. It was the primary Canon SLR lens mounting system until 1987 when the cameras from the Canon EOS series were first produced using the new EF lens mount. The last camera in the FD system was the Canon T60, from 1990. The FD mount replaced Canon\'s earlier FL mount (which in turn had replaced the R mount); FD-mount cameras could use FL lenses in stop-down metering mode. There is no known meaning for \'FD\', and Canon has never disclosed what, if anything, it stands for.

Although the Canon FD system enjoyed huge popularity in the 1970s and 1980s, the mount system is now obsolete, and Canon FD cameras and lenses are available for low prices on the second-hand market. This makes the system very attractive to 35mm film photographers who demand the highest optical quality, but who do not need auto focus capability.',
      'format' => 'filtered_html',
    ),
  );
  $export['welcome'] = $box;

  return $export;
}
