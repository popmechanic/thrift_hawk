<?php
/**
 * @file
 * thrift_hawk_features_alpha.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function thrift_hawk_features_alpha_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'blog';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Blog image */
  $handler->display->display_options['fields']['field_blogimg']['id'] = 'field_blogimg';
  $handler->display->display_options['fields']['field_blogimg']['table'] = 'field_data_field_blogimg';
  $handler->display->display_options['fields']['field_blogimg']['field'] = 'field_blogimg';
  $handler->display->display_options['fields']['field_blogimg']['label'] = '';
  $handler->display->display_options['fields']['field_blogimg']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blogimg']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blogimg']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blogimg']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blogimg']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blogimg']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blogimg']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_blogimg']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'blog';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Blog';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['blog'] = $view;

  $view = new view;
  $view->name = 'landingpage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Landing page';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Landing page product image */
  $handler->display->display_options['fields']['field_productimg']['id'] = 'field_productimg';
  $handler->display->display_options['fields']['field_productimg']['table'] = 'field_data_field_productimg';
  $handler->display->display_options['fields']['field_productimg']['field'] = 'field_productimg';
  $handler->display->display_options['fields']['field_productimg']['label'] = '';
  $handler->display->display_options['fields']['field_productimg']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_productimg']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_productimg']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_productimg']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_productimg']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_productimg']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_productimg']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_productimg']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_productimg']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_productimg']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_productimg']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_productimg']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'landingimage' => 'landingimage',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'landing-page';
  $export['landingpage'] = $view;

  return $export;
}
