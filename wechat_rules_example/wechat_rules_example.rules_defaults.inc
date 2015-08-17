<?php
/**
 * @file
 * wechat_rules_example.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wechat_rules_example_default_rules_configuration() {
  $items = array();
  $items['rules_components_mclm_name_phone_send_qr'] = entity_import('rules_config', '{ "rules_components_mclm_name_phone_send_qr" : {
      "LABEL" : "Hello + Name + Phone",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_messages", "rules", "wechat_reply" ],
      "USES VARIABLES" : { "request" : {
          "label" : "\\u8bf7\\u6c42\\u6d88\\u606f\\u5b9e\\u4f53",
          "type" : "wechat_request"
        }
      },
      "IF" : [
        { "wechat_messages_request_reply_status" : { "openid" : [ "request:openid" ] } },
        { "entity_is_of_bundle" : {
            "entity" : [ "request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "text" : "text" } }
          }
        },
        { "text_matches" : {
            "text" : [ "request:field-content" ],
            "match" : "^(hello)\\\\+.*\\\\+[0-9]",
            "operation" : "regex"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "2" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "\\u6dfb\\u52a0\\u7684\\u53d8\\u91cf" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "wechat_reply", "id" : [ "variable-added" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "\\u63d0\\u53d6\\u7684\\u5b9e\\u4f53" } }
          }
        },
        { "wechat_reply_drew_message_body" : {
            "USING" : { "wechat_reply" : [ "entity-fetched" ] },
            "PROVIDE" : { "wechat_reply_message_body" : { "wechat_reply_message_body" : "wechat_messages result" } }
          }
        },
        { "wechat_reply_drew_message_body" : {
            "USING" : { "wechat_reply" : [ "entity-fetched" ] },
            "PROVIDE" : { "wechat_reply_message_body" : { "wechat_reply_message_body2" : "wechat_messages result" } }
          }
        },
        { "wechat_messages_send_message" : {
            "user" : [ "request:openid" ],
            "type" : [ "entity-fetched:msg-type" ],
            "body" : [ "wechat-reply-message-body2" ]
          }
        },
        { "wechat_messages_change_reply_status" : { "openid" : [ "request:openid" ], "status" : "1" } }
      ]
    }
  }');
  $items['rules_wechat_search_keywork_reply'] = entity_import('rules_config', '{ "rules_wechat_search_keywork_reply" : {
      "LABEL" : "\\u5173\\u952e\\u5b57\\u67e5\\u8be2\\u56de\\u590d",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_messages", "rules", "wechat_reply_search", "wechat_reply" ],
      "USES VARIABLES" : { "request" : {
          "label" : "\\u8bf7\\u6c42\\u6d88\\u606f\\u5b9e\\u4f53",
          "type" : "wechat_request"
        }
      },
      "IF" : [
        { "wechat_messages_request_reply_status" : { "openid" : [ "request:openid" ] } },
        { "entity_is_of_bundle" : {
            "entity" : [ "request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "text" : "text" } }
          }
        }
      ],
      "DO" : [
        { "wechat_reply_search_get_reply_by_keyword" : {
            "USING" : { "keyword" : [ "request:field-content" ], "no_result" : "3" },
            "PROVIDE" : { "reply_id" : { "reply_id" : "\\u6d88\\u606f\\u5b9e\\u4f53id" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "wechat_reply", "id" : [ "reply-id" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "\\u63d0\\u53d6\\u7684\\u5b9e\\u4f53" } }
          }
        },
        { "wechat_reply_drew_message_body" : {
            "USING" : { "wechat_reply" : [ "entity-fetched" ] },
            "PROVIDE" : { "wechat_reply_message_body" : { "wechat_reply_message_body" : "wechat_messages result" } }
          }
        },
        { "wechat_messages_send_message" : {
            "user" : [ "request:openid" ],
            "type" : [ "entity-fetched:msg-type" ],
            "body" : [ "wechat-reply-message-body" ]
          }
        },
        { "wechat_messages_change_reply_status" : { "openid" : [ "request:openid" ], "status" : "1" } }
      ]
    }
  }');
  $items['rules_wechat_text_message_reply_rules'] = entity_import('rules_config', '{ "rules_wechat_text_message_reply_rules" : {
      "LABEL" : "\\u5fae\\u4fe1\\u6587\\u672c\\u8bf7\\u6c42\\u6d88\\u606f\\u56de\\u590d\\u89c4\\u5219\\u7ec4",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wechat_messages", "wechat_request" ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "wechat-request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "text" : "text" } }
          }
        }
      ],
      "DO" : [
        { "wechat_messages_change_reply_status" : { "openid" : [ "wechat-request:openid" ], "status" : "0" } },
        { "component_rules_components_mclm_name_phone_send_qr" : { "request" : [ "wechat-request" ] } },
        { "component_rules_wechat_search_keywork_reply" : { "request" : [ "wechat-request" ] } }
      ]
    }
  }');
  return $items;
}
