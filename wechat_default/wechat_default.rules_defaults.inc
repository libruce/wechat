<?php
/**
 * @file
 * wechat_default.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function wechat_default_default_rules_configuration() {
  $items = array();
  $items['rules__shengc'] = entity_import('rules_config', '{ "rules__shengc" : {
      "LABEL" : "\\u89e6\\u53d1\\u4e8c\\u7ef4\\u7801\\u751f\\u6210",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "wechat_messages",
        "wechat_session",
        "wechat_reply",
        "wechat_request"
      ],
      "ON" : { "wechat_request_presave" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "wechat-request" ], "field" : "field_content" } },
        { "wechat_messages_keyword_search" : {
            "text" : [ "wechat-request:field-content" ],
            "match" : "\\u4e8c\\u7ef4\\u7801"
          }
        }
      ],
      "DO" : [
        { "wechat_session_openid_to_status" : { "openid" : [ "wechat-request:from-user-name" ], "status" : "wechat_qr" } },
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
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:from-user-name" ],
            "type" : [ "entity-fetched:msg-type" ],
            "body" : [ "wechat-reply-message-body" ]
          }
        }
      ]
    }
  }');
  $items['rules_exit_kf_status'] = entity_import('rules_config', '{ "rules_exit_kf_status" : {
      "LABEL" : "\\u9000\\u51fa\\u5ba2\\u670d\\u72b6\\u6001",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wechat_kf_received" ],
      "ON" : { "wechat_kf_received_insert" : [] },
      "DO" : [
        { "component_rules_exit_session_kf_status" : { "user_massage" : [ "wechat-kf-received" ] } }
      ]
    }
  }');
  $items['rules_exit_session_kf_status'] = entity_import('rules_config', '{ "rules_exit_session_kf_status" : {
      "LABEL" : "\\u9000\\u51fa\\u5ba2\\u670d\\u72b6\\u6001",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_session", "rules", "wechat_messages" ],
      "USES VARIABLES" : { "user_massage" : {
          "label" : "\\u7528\\u6237\\u53d1\\u9001\\u7684\\u6d88\\u606f",
          "type" : "wechat_kf_received"
        }
      },
      "IF" : [
        { "wechat_session_status" : { "openid" : [ "user-massage:user-openid" ], "status" : "wechat_kf" } },
        { "entity_has_field" : {
            "entity" : [ "user-massage" ],
            "field" : "field_kf_received_text_content"
          }
        },
        { "text_matches" : {
            "text" : [ "user-massage:field-kf-received-text-content" ],
            "match" : "\\u9000\\u51fa"
          }
        }
      ],
      "DO" : [
        { "wechat_session_openid_to_status" : { "openid" : [ "user-massage:user-openid" ], "status" : "basic" } },
        { "wechat_messages_send_message" : {
            "user" : [ "user-massage:user-openid" ],
            "type" : "text",
            "body" : "{\\r\\n         \\u0022content\\u0022:\\u0022\\u5df2\\u9000\\u51fa\\u5ba2\\u670d\\u7cfb\\u7edf\\uff0c\\r\\n\\u6b22\\u8fce\\u60a8\\u7684\\u518d\\u6b21\\u6765\\u8bbf\\u3002\\u0022\\r\\n    }"
          }
        }
      ]
    }
  }');
  $items['rules_get_session_status'] = entity_import('rules_config', '{ "rules_get_session_status" : {
      "LABEL" : "\\u8fd4\\u56de\\u5f53\\u524d\\u72b6\\u6001",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "wechat_messages", "wechat_session" ],
      "ON" : { "wechat_session_message_before" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "event-key" ], "value" : "get_session_status" } }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "wechat_session",
              "property" : "openid",
              "value" : [ "openid" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched2" : "\\u63d0\\u53d6\\u7684\\u5b9e\\u4f53" } }
          }
        },
        { "wechat_messages_send_message" : {
            "user" : [ "openid" ],
            "type" : "text",
            "body" : "{\\r\\n         \\u0022content\\u0022:\\u0022[entity-fetched2:0:status]\\u0022\\r\\n    }"
          }
        }
      ]
    }
  }');
  $items['rules_over_qr_status'] = entity_import('rules_config', '{ "rules_over_qr_status" : {
      "LABEL" : "\\u7ed3\\u675f\\u4e8c\\u7ef4\\u7801\\u751f\\u6210",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "wechat_messages",
        "wechat_session",
        "wechat_reply",
        "wechat_request"
      ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "wechat-request" ], "field" : "field_content" } },
        { "wechat_messages_keyword_search" : { "text" : [ "wechat-request:field-content" ], "match" : "\\u7ed3\\u675f" } }
      ],
      "DO" : [
        { "wechat_session_openid_to_status" : { "openid" : [ "wechat-request:from-user-name" ], "status" : "basic" } },
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "3" },
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
        { "wechat_messages_send_message" : {
            "user" : [ "wechat-request:from-user-name" ],
            "type" : [ "entity-fetched:msg-type" ],
            "body" : [ "wechat-reply-message-body" ]
          }
        },
        { "user_add_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "4" : "4" } }
          }
        }
      ]
    }
  }');
  $items['rules_qr_create'] = entity_import('rules_config', '{ "rules_qr_create" : {
      "LABEL" : "\\u4e8c\\u7ef4\\u7801\\u751f\\u6210\\u6d4b\\u8bd5",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_session", "rules", "wechat_request" ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "wechat_session_status" : {
            "openid" : [ "wechat-request:from-user-name" ],
            "status" : "wechat_qr_save"
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "wechat-request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "voice" : "voice" } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "wechat_qr",
              "param_qr_type" : "1",
              "param_qr_key" : [ "wechat-request:id" ],
              "param_expire" : "3600",
              "param_create_time" : 1435514929
            },
            "PROVIDE" : { "entity_created" : { "entity_created" : "\\u521b\\u5efa\\u7684\\u5b9e\\u4f53" } }
          }
        },
        { "entity_save" : { "data" : [ "entity-created" ] } }
      ]
    }
  }');
  $items['rules_switch_kf_status'] = entity_import('rules_config', '{ "rules_switch_kf_status" : {
      "LABEL" : "\\u5207\\u6362\\u5230\\u5ba2\\u670d\\u72b6\\u6001",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_session", "rules", "wechat_messages" ],
      "USES VARIABLES" : { "request" : {
          "label" : "\\u8bf7\\u6c42\\u6d88\\u606f\\u5b9e\\u4f53",
          "type" : "wechat_request"
        }
      },
      "IF" : [
        { "wechat_session_status" : { "openid" : [ "request:from-user-name" ], "status" : "basic" } },
        { "entity_has_field" : { "entity" : [ "request" ], "field" : "field_content" } },
        { "wechat_messages_keyword_search" : { "text" : [ "request:field-content" ], "match" : "\\u5ba2\\u670d" } }
      ],
      "DO" : [
        { "wechat_session_openid_to_status" : { "openid" : [ "request:from-user-name" ], "status" : "wechat_kf" } },
        { "wechat_messages_send_message" : {
            "user" : [ "request:from-user-name" ],
            "type" : "text",
            "body" : "{\\r\\n         \\u0022content\\u0022:\\u0022\\u6b22\\u8fce\\u4f7f\\u7528\\u5ba2\\u670d\\u7cfb\\u7edf\\u3002\\r\\n\\u6b63\\u5728\\u5206\\u914d\\u5ba2\\u670d\\u4eba\\u5458...\\u0022\\r\\n    }"
          }
        }
      ]
    }
  }');
  $items['rules_switch_qr_create'] = entity_import('rules_config', '{ "rules_switch_qr_create" : {
      "LABEL" : "\\u5207\\u6362\\u5230\\u4e8c\\u7ef4\\u7801\\u751f\\u6210\\u72b6\\u6001 ",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_session", "rules", "wechat_qr" ],
      "USES VARIABLES" : { "request" : {
          "label" : "\\u8bf7\\u6c42\\u6d88\\u606f\\u5b9e\\u4f53",
          "type" : "wechat_request"
        }
      },
      "IF" : [
        { "wechat_session_status" : { "openid" : [ "request:from-user-name" ], "status" : "basic" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "request" ],
            "type" : "wechat_request",
            "bundle" : { "value" : { "event" : "event" } }
          }
        },
        { "entity_has_field" : { "entity" : [ "request" ], "field" : "field_event_key" } },
        { "wechat_qr_key_data" : {
            "event" : [ "request:field-event" ],
            "qr_key" : [ "request:field-event-key" ]
          }
        }
      ],
      "DO" : [
        { "wechat_session_openid_to_status" : { "openid" : [ "request:from-user-name" ], "status" : "wechat_qr_save" } }
      ]
    }
  }');
  $items['rules_switch_qr_save'] = entity_import('rules_config', '{ "rules_switch_qr_save" : {
      "LABEL" : "\\u5207\\u6362\\u5230\\u4e8c\\u7ef4\\u7801\\u7ed1\\u5b9a\\u72b6\\u6001",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "USES VARIABLES" : { "request" : {
          "label" : "\\u8bf7\\u6c42\\u6d88\\u606f\\u5b9e\\u4f53",
          "type" : "wechat_request"
        }
      },
      "DO" : []
    }
  }');
  $items['rules_wechat_session_status_switch'] = entity_import('rules_config', '{ "rules_wechat_session_status_switch" : {
      "LABEL" : "\\u72b6\\u6001\\u5207\\u6362",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "wechat_session", "rules", "wechat_request" ],
      "ON" : { "wechat_request_presave" : [] },
      "IF" : [
        { "wechat_session_status" : { "openid" : [ "wechat-request:from-user-name" ], "status" : "basic" } }
      ],
      "DO" : [
        { "component_rules_switch_kf_status" : { "request" : [ "wechat-request" ] } },
        { "component_rules_switch_qr_create" : { "request" : [ "wechat-request" ] } }
      ]
    }
  }');
  $items['rules_yuyinhujiaokefuceshi'] = entity_import('rules_config', '{ "rules_yuyinhujiaokefuceshi" : {
      "LABEL" : "\\u8bed\\u8a00\\u547c\\u53eb\\u5ba2\\u670d\\u6d4b\\u8bd5",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [
        "wechat_session",
        "rules",
        "wechat_request",
        "wechat_reply_search",
        "wechat_reply",
        "wechat_messages"
      ],
      "ON" : { "wechat_request_insert" : [] },
      "IF" : [
        { "wechat_session_status" : { "openid" : [ "wechat-request:from-user-name" ], "status" : "basic" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "1" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "\\u9ed8\\u8ba4\\u56de\\u590d" } }
          }
        },
        { "wechat_request_main_content" : {
            "USING" : { "wechat_request" : [ "wechat-request" ] },
            "PROVIDE" : { "content" : { "content" : "\\u8fd4\\u56de\\u7684\\u6587\\u672c" } }
          }
        },
        { "wechat_reply_search_get_reply_by_keyword" : {
            "USING" : { "keyword" : [ "content" ], "no_result" : [ "variable-added" ] },
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
            "user" : [ "wechat-request:from-user-name" ],
            "type" : [ "entity-fetched:msg-type" ],
            "body" : [ "wechat-reply-message-body" ]
          }
        }
      ]
    }
  }');
  return $items;
}
