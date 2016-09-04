<?php
/**
 * @file
 * user_bind.features.inc
 */

/**
 * Implements hook_default_wechat_qr2_type().
 */
function user_bind_default_wechat_qr2_type() {
  $items = array();
  $items['user_bind_qr'] = entity_import('wechat_qr2_type', '{
    "type" : "user_bind_qr",
    "label" : "\\u7528\\u6237\\u7ed1\\u5b9a\\u4e13\\u7528\\u7801",
    "weight" : "0",
    "description" : "",
    "data" : null
  }');
  return $items;
}
