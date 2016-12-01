<?php
/**
 * @file
 * ogmk_search.features.inc
 */

/**
 * Implements hook_views_api().
 */
function ogmk_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function ogmk_search_default_search_api_index() {
  $items = array();
  $items['node'] = entity_import('search_api_index', '{
    "name" : "Node Index",
    "machine_name" : "node",
    "description" : null,
    "server" : "database",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "created" : { "type" : "integer" },
        "ogmk_boolean" : { "type" : "boolean" },
        "ogmk_category_ref" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "ogmk_category_ref:name" : { "type" : "text", "boost" : "2.0" },
        "ogmk_labels_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "ogmk_labels_ref:name" : { "type" : "list\\u003Ctext\\u003E", "boost" : "2.0" },
        "ogmk_products_ref:commerce_price:amount_decimal" : { "type" : "list\\u003Cdecimal\\u003E" },
        "ogmk_products_ref_commerce_price_amount_decimal_asc" : { "type" : "decimal" },
        "ogmk_products_ref_commerce_price_amount_decimal_desc" : { "type" : "decimal" },
        "ogmk_shop_ref" : { "type" : "integer", "entity_type" : "node" },
        "ogmk_text" : { "type" : "text", "boost" : "2.0" },
        "ogmk_text_with_summary:value" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "3.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "fields" : { "ogmk_products_ref:commerce_price:amount_decimal" : {
                "name" : "Variants \\u00bb Price \\u00bb Amount (decimal)",
                "description" : "",
                "type" : "decimal"
              }
            }
          }
        },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "body:value" : true,
              "ogmk_category_ref:name" : true,
              "ogmk_labels_ref:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "body:value" : true },
            "title" : 0,
            "alt" : 0,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "ogmk_category_ref:name" : true,
              "ogmk_labels_ref:name" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "ogmk_category_ref:name" : true,
              "ogmk_labels_ref:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 *
 * @Issue(
 *   "Do we need both ogmk_category/labels_ref and ogmk_category_labels:name to
 *   be indexed?"
 *   type="investigation"
 *   priority="low"
 *   labels="correctedness"
 * )
 */
function ogmk_search_default_search_api_server() {
  $items = array();
  $items['database'] = entity_import('search_api_server', '{
    "name" : "Database",
    "machine_name" : "database",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 0,
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "node" : {
          "type" : {
            "table" : "search_api_db_node",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : { "table" : "search_api_db_node_text", "type" : "text", "boost" : "3.0" },
          "status" : {
            "table" : "search_api_db_node",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_node",
            "column" : "created",
            "type" : "integer",
            "boost" : "1.0"
          },
          "ogmk_category_ref" : {
            "table" : "search_api_db_node",
            "column" : "ogmk_category_ref",
            "type" : "integer",
            "boost" : "1.0"
          },
          "ogmk_labels_ref" : {
            "table" : "search_api_db_node_ogmk_labels_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "ogmk_shop_ref" : {
            "table" : "search_api_db_node",
            "column" : "ogmk_shop_ref",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_node",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "ogmk_products_ref_commerce_price_amount_decimal_asc" : {
            "table" : "search_api_db_node",
            "column" : "ogmk_products_ref_commerce_price_amount_decimal_asc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "ogmk_products_ref_commerce_price_amount_decimal_desc" : {
            "table" : "search_api_db_node",
            "column" : "ogmk_products_ref_commerce_price_amount_decimal_desc",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "ogmk_category_ref:name" : { "table" : "search_api_db_node_text", "type" : "text", "boost" : "2.0" },
          "ogmk_labels_ref:name" : {
            "table" : "search_api_db_node_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "2.0"
          },
          "ogmk_products_ref:commerce_price:amount_decimal" : {
            "table" : "search_api_db_node_ogmk_products_ref_commerce_price_amount_dec",
            "column" : "value",
            "type" : "list\\u003Cdecimal\\u003E",
            "boost" : "1.0"
          },
          "ogmk_boolean" : {
            "table" : "search_api_db_node",
            "column" : "ogmk_boolean",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "ogmk_text" : { "table" : "search_api_db_node_text", "type" : "text", "boost" : "2.0" },
          "ogmk_text_with_summary:value" : { "table" : "search_api_db_node_text", "type" : "text", "boost" : "1.0" }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
