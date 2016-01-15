<?php
function wechat_user_edit_form(WechatUser $wechatUser) {
  $wechatUser->nickname = utf8_decode($wechatUser->nickname);
  module_load_include('inc', 'wechat_user', 'wechat_user.forms');
  return drupal_get_form('wechat_user_form', $wechatUser, 'edit');
}

function wechat_user_form($form, &$form_state, WechatUser $wechatUser, $op) {

  $form_state['wechatUser'] = $wechatUser;
  $form_state['_op'] = $op;

  $langcode = entity_language('wechat_user', $wechatUser);

  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }
  $form['remark'] = array(
    '#title' => t('备注名称'),
    '#type' => 'textfield',
    '#default_value' => $wechatUser->remark,
  );
  $form['groupid'] = array(
    '#title' => t('所在分组'),
    '#type' => 'select',
    '#options' => WechatUserGroup::Options(),
    '#default_value' => $wechatUser->groupid,
    '#description' => t('Set this to <em>Yes</em> if you would like this category to be selected by default.'),
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
  $wechatUser = $form_state['wechatUser'];
  field_attach_submit('wechat_user', $wechatUser, $form, $form_state);

  $remark = $form_state['values']['remark'];
  $groupid = $form_state['values']['groupid'];
  if ($wechatUser->remark != $remark || $wechatUser->groupid != $groupid) {
    $wechatUser->remark = $remark;
    $wechatUser->groupid = $groupid;
    $wechatUser->push($form_state['_op']);
  }

}

function wechat_user_group_add_form() {
  $wechatUserGroup = new WechatUserGroup();
  module_load_include('inc', 'wechat_user', 'wechat_user.forms');
  return drupal_get_form('wechat_user_group_form', $wechatUserGroup, 'add');
}

function wechat_user_group_edit_form(WechatUserGroup $wechatUserGroup) {
  module_load_include('inc', 'wechat_user', 'wechat_user.forms');
  return drupal_get_form('wechat_user_group_form', $wechatUserGroup, 'edit');
}

function wechat_user_group_form($form, &$form_state, WechatUserGroup $wechatUserGroup, $op) {
  $form_state['wechatUserGroup'] = $wechatUserGroup;
  $form_state['_op'] = $op;

  $form['name'] = array(
    '#title' => t('分组名称'),
    '#type' => 'textfield',
    '#default_value' => $wechatUserGroup->name,
  );
  $form['id'] = array(
    '#title' => t('分组id，由微信分配'),
    '#type' => 'textfield',
    '#default_value' => $wechatUserGroup->id,
    '#disabled' => TRUE,
  );
  $form['count'] = array(
    '#title' => t('分组内用户数量'),
    '#type' => 'textfield',
    '#default_value' => $wechatUserGroup->count,
    '#disabled' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );
  if (!empty($wechatUserGroup->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('删除'),
      '#weight' => 45,
    );
  }
  return $form;
}

function wechat_user_group_form_submit($form, &$form_state) {
  $wechatUserGroup = $form_state['wechatUserGroup'];
  $wechatUserGroup->name = $form_state['values']['name'];
  $wechatUserGroup->push($form_state['_op']);
}