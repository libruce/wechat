<?php
/**
 * @file
 * wechat_request.features.inc
 */

/**
 * Implements hook_default_wechat_request_type().
 */
function wechat_request_default_wechat_request_type() {
  $items = array();
  $items['event'] = entity_import('wechat_request_type', '{
    "type" : "event",
    "label" : "\\u4e8b\\u4ef6\\u63a8\\u9001",
    "weight" : "6",
    "data" : null
  }');
  $items['image'] = entity_import('wechat_request_type', '{
    "type" : "image",
    "label" : "\\u56fe\\u7247\\u6d88\\u606f",
    "weight" : "1",
    "data" : null
  }');
  $items['link'] = entity_import('wechat_request_type', '{
    "type" : "link",
    "label" : "\\u94fe\\u63a5\\u6d88\\u606f",
    "weight" : "5",
    "data" : null
  }');
  $items['location'] = entity_import('wechat_request_type', '{
    "type" : "location",
    "label" : "\\u5730\\u7406\\u4f4d\\u7f6e\\u6d88\\u606f",
    "weight" : "4",
    "data" : null
  }');
  $items['shortvideo'] = entity_import('wechat_request_type', '{
    "type" : "shortvideo",
    "label" : "\\u5c0f\\u89c6\\u9891\\u6d88\\u606f",
    "weight" : "3",
    "data" : null
  }');
  $items['text'] = entity_import('wechat_request_type', '{
    "type" : "text",
    "label" : "\\u6587\\u672c\\u6d88\\u606f",
    "weight" : "0",
    "data" : null
  }');
  $items['video'] = entity_import('wechat_request_type', '{
    "type" : "video",
    "label" : "\\u89c6\\u9891\\u6d88\\u606f",
    "weight" : "3",
    "data" : null
  }');
  $items['voice'] = entity_import('wechat_request_type', '{
    "type" : "voice",
    "label" : "\\u8bed\\u97f3\\u6d88\\u606f",
    "weight" : "2",
    "data" : null
  }');
  return $items;
}
