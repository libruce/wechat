<?php
/**
 * Implements hook_rules_event_info().
 */
function wechat_kf_rules_event_info() {
  $events['wechat_kf_process_massage'] = array(
    'label' => t('微信客服模块预处理微信消息之前'),
    'group' => t('微信'),
    'variables' => array(
      'openid' => array(
        'type' => 'text',
        'label' => t('OPENID'),
      ),
    ),
  );
  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function wechat_kf_rules_action_info() {
  $action['wechat_kf_send_message'] = array(
    'parameter' => array(
      'user' => array(
        'type' => 'text',
        'label' => t('接收者'),
        'description' => t('The user whose roles should be changed.'),
        'save' => TRUE,
      ),
      'type' => array(
        'type' => 'text',
        'label' => t('消息类型'),
        'description' => t('The user whose roles should be changed.'),
        'save' => TRUE,
      ),
      'body' => array(
        'type' => 'text',
        'label' => t('消息内容'),
        'save' => TRUE,
      )
    ),
    'group' => t('微信'),
    'access callback' => user_access('administer permissions'),
    'label' => t('微信发送消息客服接口（带客服头像）'),
    'base' => 'wechat_kf_send_message',
  );
  return $action;
}

function wechat_kf_send_message($user, $type, $body) {

}