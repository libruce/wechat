<?php
function wechat_user_edit_form(WechatUser $wechat_user) {
  module_load_include('inc', 'wechat_user', 'wechat_user.forms');
  return drupal_get_form('wechat_user_form', $wechat_user, 'edit');
}

function wechat_user_form($form, &$form_state, $wechat_user, $op) {

  $form_state['wechat_user'] = $wechat_user;

  $langcode = entity_language('wechat_user', $wechat_user);

  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }

//  public $uid;
//  public $openid;
//  public $subscribe;
//  public $nickname;
//  public $sex;
//  public $province;
//  public $city;
//  public $country;
//  public $headimgurl;
//  public $subscribe_time;

  field_attach_form('wechat_user', $wechat_user, $form, $form_state, $langcode);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );
  //dpm($form_state);
  //wechat_response_message_edit_form_submit_delete
  return $form;
}


function wechat_user_form_submit(&$form, &$form_state) {

  $wechat_user = &$form_state['wechat_user'];

  //$message->to_user_name = $form_state['values']['to_user_name'];
  //dpm($form_state);
//  // Notify field widgets.
  //dpm($form_state);
  field_attach_submit('wechat_user', $wechat_user, $form, $form_state);
  $wechat_user->save();
  // drupal_set_message(t('%type reply add success.', array('%type' => $wechat_user->msg_type)));
  //$form_state['redirect'] = 'admin/content/reply';
}

