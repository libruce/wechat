<?php
/**
 * Implements hook_rules_event_info().
 */
function wechat_api_rules_event_info() {
  $events['wechat_api_callback_before'] = array(
    'label' => t('收到微信消息处理之前entity'),
    'group' => t('wechat'),
    'variables' => array(
      'entity' => array(
        'type' => 'entity',
        'label' => t('Entity'),
      ),
    ),
  );
  $events['wechat_api_messages_received'] = array(
    'label' => t('收到微信消息处理之前messages_type'),
    'group' => t('wechat'),
    'variables' => array(
      'messages_type' => array(
        'type' => 'text',
        'label' => t('消息类型'),
      ),
    ),
  );

  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function wechat_api_rules_action_info() {
  $action['records_db_point_ceiling'] = array(
    'parameter' => array(
      'message' => array(
        'type' => 'entity',
        'label' => t('消息实体'),
        'description' => t('The user whose roles should be changed.'),
        'save' => TRUE,
      )
    ),
    'group' => t('微信'),
    'access callback' => user_access('administer permissions'),
    'label' => t('微信发送消息'),
    'base' => 'wechat_api_send_message',
  );

  return $action;
}

function wechat_api_send_message($message) {
  $we_obj = wechat_api_init_wechatobj();
  $we_obj->sendCustomMessage($message);
}