<?php
/**
 * @file
 * ogmk_search.views_default.inc
 */

/**
 * @Issue(
 *   "Add token in better exposed filters for getting the minimum and maximum
 *   price indexed"
 *   type="improvement"
 *   priority="normal"
 *   labels="ux"
 * )
 */

/**
 * Implements hook_views_default_views().
 */
function ogmk_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ogmk_search_products';
  $view->description = '';
  $view->tag = 'commerce, ogmk, search';
  $view->base_table = 'search_api_index_node';
  $view->human_name = 'OGMK Search Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_remember'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'basic_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_category_ref' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_labels_ref' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_shop_ref' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_products_ref_commerce_price_amount_decimal_asc' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '9999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning" role="alert"><span class="fa fa-exclamation-triangle"></span> There are no products that match the search criteria you have specified. You may want to expand your search, or have a look at some of our featured products below.</div>';
  /* No results behavior: Global: View area */
  $handler->display->display_options['empty']['view']['id'] = 'view';
  $handler->display->display_options['empty']['view']['table'] = 'views';
  $handler->display->display_options['empty']['view']['field'] = 'view';
  $handler->display->display_options['empty']['view']['empty'] = TRUE;
  $handler->display->display_options['empty']['view']['view_to_insert'] = 'products_featured:block';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Indexed Node: Variants » Price » Amount (decimal) (Min) */
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['field'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['label'] = 'Price';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date Created';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['ogmk_category_ref']['id'] = 'ogmk_category_ref';
  $handler->display->display_options['filters']['ogmk_category_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_category_ref']['field'] = 'ogmk_category_ref';
  $handler->display->display_options['filters']['ogmk_category_ref']['value'] = array();
  $handler->display->display_options['filters']['ogmk_category_ref']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['operator_id'] = 'ogmk_category_ref_op';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['operator'] = 'ogmk_category_ref_op';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Labels */
  $handler->display->display_options['filters']['ogmk_labels_ref']['id'] = 'ogmk_labels_ref';
  $handler->display->display_options['filters']['ogmk_labels_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_labels_ref']['field'] = 'ogmk_labels_ref';
  $handler->display->display_options['filters']['ogmk_labels_ref']['value'] = array();
  $handler->display->display_options['filters']['ogmk_labels_ref']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['operator_id'] = 'ogmk_labels_ref_op';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['label'] = 'Labels';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['operator'] = 'ogmk_labels_ref_op';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['identifier'] = 'labels';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_labels_ref']['type'] = 'select';
  /* Filter criterion: Indexed Node: Shop */
  $handler->display->display_options['filters']['ogmk_shop_ref']['id'] = 'ogmk_shop_ref';
  $handler->display->display_options['filters']['ogmk_shop_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_shop_ref']['field'] = 'ogmk_shop_ref';
  $handler->display->display_options['filters']['ogmk_shop_ref']['value'] = array();
  $handler->display->display_options['filters']['ogmk_shop_ref']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['operator_id'] = 'ogmk_shop_ref_op';
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['label'] = 'Shop';
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['operator'] = 'ogmk_shop_ref_op';
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['identifier'] = 'shop';
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_shop_ref']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Variants » Price » Amount (decimal) (Min) */
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['field'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['operator'] = 'between';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['operator_id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc_op';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['label'] = 'Price Range';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['operator'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc_op';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['identifier'] = 'price';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['group_info']['label'] = 'Variants » Price » Amount (decimal) (Min)';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['group_info']['identifier'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'products';
  $translatables['ogmk_search_products'] = array(
    t('Master'),
    t('Find Products'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('Sort options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div class="alert alert-warning" role="alert"><span class="fa fa-exclamation-triangle"></span> There are no products that match the search criteria you have specified. You may want to expand your search, or have a look at some of our featured products below.</div>'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Relevance'),
    t('Price'),
    t('Date Created'),
    t('Keywords'),
    t('Category'),
    t('Labels'),
    t('Shop'),
    t('Price Range'),
    t('Variants » Price » Amount (decimal) (Min)'),
    t('Page'),
  );
  $export['ogmk_search_products'] = $view;

  /**
   * @Issue(
   *   "Add token in better exposed filters for getting the minimum and maximum
   *   price indexed per shop"
   *   type="improvement"
   *   priority="normal"
   *   labels="ux"
   * )
   * @Issue(
   *   "Display only categories and labels that are available on the currently
   *   viewed shop in the exposed filters form"
   *   type="improvement"
   *   priority="low"
   *   labels="ux"
   * )
   */

  $view = new view();
  $view->name = 'ogmk_search_shop_products';
  $view->description = '';
  $view->tag = 'commerce, ogmk, search, shop, products';
  $view->base_table = 'search_api_index_node';
  $view->human_name = 'OGMK Search Shop Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['sort_remember_roles'] = array(
    1 => 0,
    2 => 0,
    3 => 0,
  );
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'basic_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_param' => 'sort',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_category_ref' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_labels_ref' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ogmk_products_ref_commerce_price_amount_decimal_asc' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_thumbnail_plugin_style';
  $handler->display->display_options['style_options']['columns_horizontal'] = '-1';
  $handler->display->display_options['style_options']['columns_vertical'] = '4';
  $handler->display->display_options['style_options']['columns_xs'] = '12';
  $handler->display->display_options['style_options']['columns_sm'] = '6';
  $handler->display->display_options['style_options']['columns_md'] = '4';
  $handler->display->display_options['style_options']['columns_lg'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="alert alert-warning" role="alert"><span class="fa fa-exclamation-triangle"></span> There are no products in this shop that match the search criteria you have specified. You may want to expand your search, or make a global search so that you get results from other shops as well.</div>';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Indexed Node: Variants » Price » Amount (decimal) (Min) */
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['field'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['label'] = 'Price';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date created';
  /* Contextual filter: Indexed Node: Shop */
  $handler->display->display_options['arguments']['ogmk_shop_ref']['id'] = 'ogmk_shop_ref';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['field'] = 'ogmk_shop_ref';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['default_action'] = 'default';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['default_argument_type'] = 'og_context';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['ogmk_shop_ref']['validate']['type'] = 'og';
  $handler->display->display_options['arguments']['ogmk_shop_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['ogmk_shop_ref']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Keywords';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Indexed Node: Category */
  $handler->display->display_options['filters']['ogmk_category_ref']['id'] = 'ogmk_category_ref';
  $handler->display->display_options['filters']['ogmk_category_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_category_ref']['field'] = 'ogmk_category_ref';
  $handler->display->display_options['filters']['ogmk_category_ref']['value'] = array();
  $handler->display->display_options['filters']['ogmk_category_ref']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['operator_id'] = 'ogmk_category_ref_op';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['operator'] = 'ogmk_category_ref_op';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_category_ref']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Labels */
  $handler->display->display_options['filters']['ogmk_labels_ref']['id'] = 'ogmk_labels_ref';
  $handler->display->display_options['filters']['ogmk_labels_ref']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_labels_ref']['field'] = 'ogmk_labels_ref';
  $handler->display->display_options['filters']['ogmk_labels_ref']['value'] = array();
  $handler->display->display_options['filters']['ogmk_labels_ref']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['operator_id'] = 'ogmk_labels_ref_op';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['label'] = 'Labels';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['operator'] = 'ogmk_labels_ref_op';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['identifier'] = 'labels';
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ogmk_labels_ref']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['ogmk_labels_ref']['type'] = 'select';
  /* Filter criterion: Indexed Node: Variants » Price » Amount (decimal) (Min) */
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['table'] = 'search_api_index_node';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['field'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['operator'] = 'between';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['operator_id'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc_op';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['label'] = 'Price Range';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['operator'] = 'ogmk_products_ref_commerce_price_amount_decimal_asc_op';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['identifier'] = 'price';
  $handler->display->display_options['filters']['ogmk_products_ref_commerce_price_amount_decimal_asc']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/products';
  $translatables['ogmk_search_shop_products'] = array(
    t('Master'),
    t('Find Products'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('Sort options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div class="alert alert-warning" role="alert"><span class="fa fa-exclamation-triangle"></span> There are no products in this shop that match the search criteria you have specified. You may want to expand your search, or make a global search so that you get results from other shops as well.</div>'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Relevance'),
    t('Price'),
    t('Date created'),
    t('All'),
    t('Keywords'),
    t('Category'),
    t('Labels'),
    t('Price Range'),
    t('Page'),
  );
  $export['ogmk_search_shop_products'] = $view;

  return $export;
}
