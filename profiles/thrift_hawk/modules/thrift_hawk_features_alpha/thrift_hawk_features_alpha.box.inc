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
  $box->title = 'How to Use Craigslist to Find the Best Prices';
  $box->description = 'History';
  $box->options = array(
    'body' => array(
      'value' => 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam euismod nunc eu augue bibendum suscipit. Nulla dapibus, nisl ut hendrerit placerat, lectus purus fermentum odio, quis eleifend est lorem eget neque. Etiam et quam velit. Etiam quis augue massa, in imperdiet erat. Sed libero tortor, gravida sed euismod elementum, faucibus ultricies ligula. In pulvinar elit eleifend justo aliquet sed congue felis vehicula. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent a tellus lectus, eget vestibulum ligula. Suspendisse et mi sapien. Etiam fermentum massa vel ipsum rutrum porttitor in at dolor. Duis justo orci, hendrerit sed ullamcorper sed, laoreet mattis libero. Quisque a dui id justo ullamcorper interdum. Morbi viverra rutrum sem a dignissim. Etiam in ligula odio. Sed pulvinar imperdiet fermentum. Morbi ac nibh ut eros tempor mattis sed non nisi. Phasellus bibendum porta justo. Nulla sit amet tellus et nunc ultricies faucibus non eu purus. Phasellus placerat aliquam lacus, vitae consequat augue ultrices a. Donec aliquet sollicitudin nibh, et dignissim mi convallis et.

Sed sit amet enim quis mauris aliquet pulvinar. Nam turpis justo, placerat sed placerat sit amet, feugiat nec sapien. Suspendisse pulvinar, ligula a ullamcorper elementum, urna diam pharetra metus, eget pulvinar nisi arcu eget nunc. Morbi suscipit pellentesque porttitor. Vestibulum dictum ante lacinia justo dictum vitae aliquam ante aliquet. Sed in dolor odio. Integer odio neque, imperdiet in facilisis vitae, fermentum vitae dui. Morbi blandit eros ut sapien mattis congue. Donec et magna eget arcu consequat luctus et sed ante. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Vivamus ligula dolor, ultricies eget convallis eget, adipiscing a felis. Donec volutpat, enim quis accumsan pellentesque, diam nisl accumsan sapien, at porta orci erat at ligula. Nulla facilisi. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Pellentesque vel risus massa. Quisque non enim vel tortor varius congue quis eu enim. Sed varius, erat at dapibus venenatis, dolor ante vulputate neque, et malesuada tellus lectus in ante. Duis quis ante quis metus sagittis dignissim. Sed id est in sapien luctus varius. Quisque aliquam porta aliquet.',
      'format' => 'filtered_html',
    ),
  );
  $export['welcome'] = $box;

  return $export;
}
