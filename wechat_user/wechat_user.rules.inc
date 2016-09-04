<?php

/**
 * Implements hook_rules_action_info().
 */
function wechat_user_rules_action_info() {
  return array(
    'wechat_user_login_open_id' => array(
      'parameter' => array(
        'open_id' => array(
          'type' => 'text',
          'label' => t('OpenId'),
          'description' => t('The user whose roles should be changed.'),
          'save' => TRUE,
        )
      ),
      'group' => t('微信'),
      'access callback' => user_access('administer permissions'),
      'label' => t('使用微信OPENID登录'),
      'base' => 'wechat_user_login_open_id',
    ),
    'wechat_user_registry_user' => array(
      'parameter' => array(
        'open_id' => array(
          'type' => 'text',
          'label' => t('OpenId'),
          'description' => t('The user whose roles should be changed.'),
          'save' => TRUE,
        )
      ),
      'group' => t('微信'),
      'access callback' => user_access('administer permissions'),
      'label' => t('注册用户'),
      'base' => 'wechat_user_registry_user',
    ),
    'wechat_user_load_user' => array(
      'parameter' => array(
        'open_id' => array(
          'type' => 'text',
          'label' => t('OpenId'),
          'description' => t('The user whose roles should be changed.'),
          'save' => TRUE,
        )
      ),
      'provides' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('返回的用户实体'),
        ),
      ),
      'group' => t('微信'),
      'access callback' => user_access('administer permissions'),
      'label' => t('使用OpenId提取用户实体'),
      'base' => 'wechat_user_load_user',
    ),
    'wechat_user_load_wechat_user' => array(
      'parameter' => array(
        'open_id' => array(
          'type' => 'text',
          'label' => t('OpenId'),
          'description' => t('The user whose roles should be changed.'),
          'save' => TRUE,
        )
      ),
      'provides' => array(
        'wechat_user' => array(
          'type' => 'wechat_user',
          'label' => t('返回的WechatUser实体'),
        ),
      ),
      'group' => t('微信'),
      'access callback' => user_access('administer permissions'),
      'label' => t('使用OpenId提取WechatUser实体'),
      'base' => 'wechat_user_load_wechat_user',
    ),
  );
}

function wechat_user_load_wechat_user($openid) {
  $wechat_user = wechat_user_load_multiple(FALSE, array('openid' => $openid));
  if (!empty($wechat_user)) {
    $wechat_user = reset($wechat_user);
  }
  return array('wechat_user' => $wechat_user);
}

function wechat_user_login_open_id($openid) {
  $uid = wechat_user_get_user_by_openid($openid);
  watchdog('wechat_user_login', json_encode($uid));
  _wechat_user_login($uid->uid);
}

function wechat_user_load_user($openid) {
  $user = wechat_user_get_user_by_openid($openid);
  return array('user' => $user);
}

/**
 * Implements hook_rules_condition_info().
 */
function wechat_user_rules_condition_info() {
  $condition['wechat_user_registry_status'] = array(
    'label' => t('微信用户注册状态'),
    'parameter' => array(
      'openid' => array(
        'type' => 'text',
        'label' => t('OpenId')
      ),
    ),
    'group' => t('微信'),
    'access callback' => 'rules_user_integration_access',
    'base' => 'wechat_user_registry_status',
  );
  return $condition;
}

function wechat_user_registry_status($openid) {
  if (!wechat_user_get_user_by_openid($openid)) {
    return TRUE;
  }
  return FALSE;
}