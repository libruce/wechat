<?php
/**
 * @file
 * wechat_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wechat_rules_default_rules_configuration() {
  $items = array();
  $items['rules_subscribe_send_welcome_message'] = entity_import('rules_config', '{ "rules_subscribe_send_welcome_message" : {
      "LABEL" : "\\u5173\\u6ce8\\u4e0b\\u53d1\\u6b22\\u8fce\\u6d88\\u606f",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wechat_messages", "wechat_request" ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "wechat-request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "event" : "event" } }
          }
        },
        { "data_is" : { "data" : [ "wechat-request:field-event" ], "value" : "subscribe" } }
      ],
      "DO" : [
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:openid" ],
            "type" : "text",
            "body" : "{\\r\\n\\u0022content\\u0022:\\u0022\\u6b22\\u8fce\\u5173\\u6ce8\\uff01\\u0022\\r\\n}"
          }
        }
      ]
    }
  }');
  return $items;
}
