<?php
function wechat_user_edit_form(WechatUser $wechat_user) {
  module_load_include('inc', 'wechat_user', 'wechat_user.forms');
  return drupal_get_form('wechat_user_form', $wechat_user, 'edit');
}

function wechat_user_form($form, &$form_state, WechatUser $wechatUser, $op) {

  $form_state['wechat_user'] = $wechatUser;

  $langcode = entity_language('wechat_user', $wechatUser);

  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }
  $form['remark'] = array(
    '#title' => t('备注名称'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->remark,
  );
  $form['uid'] = array(
    '#title' => t('绑定的用户ID'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->uid,
    '#disabled' => TRUE,
  );
  $form['openid'] = array(
    '#title' => t('OPENID'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->openid,
    '#disabled' => TRUE,
  );
  $form['subscribe'] = array(
    '#title' => t('是否关注'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->subscribe,
    '#disabled' => TRUE,
  );
  $form['nickname'] = array(
    '#title' => t('微信昵称'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->nickname,
    '#disabled' => TRUE,
  );
  $form['sex'] = array(
    '#title' => t('性别'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->sex,
    '#disabled' => TRUE,
  );
  $form['province'] = array(
    '#title' => t('省份'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->province,
    '#disabled' => TRUE,
  );
  $form['city'] = array(
    '#title' => t('城市'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->city,
    '#disabled' => TRUE,
  );
  $form['country'] = array(
    '#title' => t('国家代码'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->country,
    '#disabled' => TRUE,
  );
  $form['headimgurl'] = array(
    '#title' => t('用户头像URL'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->headimgurl,
    '#disabled' => TRUE,
  );
  $form['subscribe_time'] = array(
    '#title' => t('关注时间'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->subscribe_time,
    '#disabled' => TRUE,
  );

  field_attach_form('wechat_user', $wechatUser, $form, $form_state, $langcode);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );
  return $form;
}


function wechat_user_form_submit(&$form, &$form_state) {
  $wechat_user = &$form_state['wechat_user'];
  field_attach_submit('wechat_user', $wechat_user, $form, $form_state);
  $wechat_user->save();
}

