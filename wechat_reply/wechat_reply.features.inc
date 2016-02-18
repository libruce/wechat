<?php
/**
 * @file
 * wechat_reply.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wechat_reply_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function wechat_reply_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_wechat_reply_type().
 */
function wechat_reply_default_wechat_reply_type() {
  $items = array();
  $items['image'] = entity_import('wechat_reply_type', '{
    "type" : "image",
    "label" : "\\u56fe\\u7247\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  $items['multiple_news'] = entity_import('wechat_reply_type', '{
    "type" : "multiple_news",
    "label" : "\\u591a\\u56fe\\u6587\\u6d88\\u606f",
    "weight" : "10",
    "description" : "",
    "data" : null
  }');
  $items['music'] = entity_import('wechat_reply_type', '{
    "type" : "music",
    "label" : "\\u97f3\\u4e50\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  $items['news'] = entity_import('wechat_reply_type', '{
    "type" : "news",
    "label" : "\\u56fe\\u6587\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  $items['text'] = entity_import('wechat_reply_type', '{
    "type" : "text",
    "label" : "\\u6587\\u672c\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  $items['video'] = entity_import('wechat_reply_type', '{
    "type" : "video",
    "label" : "\\u89c6\\u9891\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  $items['voice'] = entity_import('wechat_reply_type', '{
    "type" : "voice",
    "label" : "\\u8bed\\u97f3\\u6d88\\u606f",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  return $items;
}
