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
  $items['rules_fans_tongji'] = entity_import('rules_config', '{ "rules_fans_tongji" : {
      "LABEL" : "\\u7c89\\u4e1d\\u6765\\u6e90\\u7edf\\u8ba1",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "qr_services", "wechat_messages", "wechat_request" ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "wechat-request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "event" : "event" } }
          }
        },
        { "qr_services_is_spread_qr" : {
            "event" : [ "wechat-request:field-event" ],
            "qr_key" : [ "wechat-request:field-event-key" ]
          }
        }
      ],
      "DO" : [
        { "qr_services_action_user_login" : { "openid" : [ "wechat-request:openid" ] } },
        { "qr_services_action_fans_reside" : {
            "USING" : {
              "event" : [ "wechat-request:field-event" ],
              "qr_key" : [ "wechat-request:field-event-key" ]
            },
            "PROVIDE" : { "user" : { "user" : "\\u8fd4\\u56de\\u7684\\u4e8c\\u7ef4\\u7801\\u63a8\\u5e7f\\u5458" } }
          }
        },
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:openid" ],
            "type" : "text",
            "body" : "{\\r\\n\\u0022content\\u0022:\\u0022\\u8fd9\\u662f--\\u003E[user:name]\\u003C--\\u7684\\u63a8\\u5e7f\\u7801\\u0022\\r\\n}"
          }
        },
        { "component_rules_from_null_add_info" : {
            "user" : [ "site:current-user" ],
            "info" : "\\u003Ca href=\\u0022[user:url]\\u0022\\u003E[user:name]\\u003C\\/a\\u003E\\u4e8c\\u7ef4\\u7801\\u63a8\\u5e7f\\u3002"
          }
        }
      ]
    }
  }');
  $items['rules_from_null_add_info'] = entity_import('rules_config', '{ "rules_from_null_add_info" : {
      "LABEL" : "\\u5982\\u679c\\u6765\\u6e90\\u7edf\\u8ba1\\u4e3a\\u7a7a\\uff0c\\u5219\\u6dfb\\u52a0\\u6765\\u6e90\\u7edf\\u8ba1\\u8d44\\u6599",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "user" : { "label" : "User", "type" : "user" },
        "info" : { "label" : "info", "type" : "text" }
      },
      "IF" : [
        { "data_is_empty" : { "data" : [ "site:current-user:profile-spread-qr-profile" ] } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "profile2",
              "param_type" : "spread_qr_profile",
              "param_user" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "\\u521b\\u5efa\\u7684\\u5b9e\\u4f53" } }
          }
        },
        { "data_set" : { "data" : [ "entity-created:field-form-spread" ], "value" : [ "info" ] } },
        { "entity_save" : { "data" : [ "entity-created" ], "immediate" : "1" } }
      ]
    }
  }');
  $items['rules_send_gerentuiguangma2'] = entity_import('rules_config', '{ "rules_send_gerentuiguangma2" : {
      "LABEL" : "\\u626b\\u63cf\\u5b98\\u65b9\\u63a8\\u5e7f\\u7801\\u5e76\\u4e0b\\u53d1\\u4e2a\\u4eba\\u63a8\\u5e7f\\u7801",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "qr_services", "wechat_messages", "wechat_request" ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "wechat-request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "event" : "event" } }
          }
        },
        { "qr_services_qr_is_key" : {
            "event" : [ "wechat-request:field-event" ],
            "qr_key" : [ "wechat-request:field-event-key" ],
            "keys" : "saoma_zidongzhuce_fasonggerentuiguangma"
          }
        }
      ],
      "DO" : [
        { "qr_services_action_user_login" : { "openid" : [ "wechat-request:openid" ] } },
        { "qr_services_action_create_spread_qr" : {
            "USING" : {
              "user" : [ "site:current-user" ],
              "qr_key" : "spread_qr_uid_[site:current-user:uid]"
            },
            "PROVIDE" : { "qr" : { "qr" : "\\u8fd4\\u56de\\u7684\\u4e8c\\u7ef4\\u7801\\u5b9e\\u4f53" } }
          }
        },
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:openid" ],
            "type" : "news",
            "body" : "{\\r\\n        \\u0022articles\\u0022: [\\r\\n         {\\r\\n             \\u0022title\\u0022:\\u0022[site:current-user:name]\\u7684\\u63a8\\u5e7f\\u7801\\u0022,\\r\\n             \\u0022description\\u0022:\\u0022\\u70b9\\u51fb\\u8fdb\\u5165\\uff0c\\u6536\\u53d6\\u4e8c\\u7ef4\\u7801\\u0022,\\r\\n             \\u0022url\\u0022:\\u0022[qr:url]\\u0022,\\r\\n             \\u0022picurl\\u0022:\\u0022https:\\/\\/mp.weixin.qq.com\\/cgi-bin\\/showqrcode?ticket=[qr:ticket]\\u0022\\r\\n         }\\r\\n         ]\\r\\n    }"
          }
        },
        { "data_set" : {
            "data" : [ "site:current-user:profile-spread-qr-profile:field-qr-services-qr-key" ],
            "value" : [ "qr:qr-key" ]
          }
        },
        { "data_set" : {
            "data" : [ "site:current-user:profile-spread-qr-profile:field-spread-qr" ],
            "value" : [ "qr" ]
          }
        }
      ]
    }
  }');
  $items['rules_subscribe_send_welcome_message'] = entity_import('rules_config', '{ "rules_subscribe_send_welcome_message" : {
      "LABEL" : "\\u5173\\u6ce8\\u4e0b\\u53d1\\u6b22\\u8fce\\u6d88\\u606f",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "qr_services", "wechat_messages", "wechat_request" ],
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
        { "qr_services_action_user_login" : { "openid" : [ "wechat-request:openid" ] } },
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:openid" ],
            "type" : "text",
            "body" : "{\\r\\n\\u0022content\\u0022:\\u0022\\u6b22\\u8fce\\u5173\\u6ce8\\uff01\\u0022\\r\\n}"
          }
        },
        { "component_rules_from_null_add_info" : {
            "user" : [ "site:current-user" ],
            "info" : "\\u76f4\\u63a5\\u5173\\u6ce8\\uff01"
          }
        }
      ]
    }
  }');
  return $items;
}
