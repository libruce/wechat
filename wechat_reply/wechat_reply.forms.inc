<?php


function wechat_reply_add_form($type) {
  $wechat_reply = entity_create('wechat_reply', array('msg_type' => $type));
  module_load_include('inc', 'wechat_reply', 'wechat_reply.forms');
  return drupal_get_form('wechat_reply_form', $wechat_reply, 'add');
}

function wechat_reply_edit_form(WechatReply $wechatReply) {
  module_load_include('inc', 'wechat_reply', 'wechat_reply.forms');
  return drupal_get_form('wechat_reply_form', $wechatReply, 'edit');
}

function wechat_reply_form($form, &$form_state, $wechat_reply, $op) {

  //dpm($wechat_reply);
  $form_state['wechat_reply'] = $wechat_reply;

  $langcode = entity_language('wechat_reply', $wechat_reply);


  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }


  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $wechat_reply->title,
    //'#required' => TRUE,
    '#size' => 30,
    '#weight' => -40,
  );

  field_attach_form('wechat_reply', $wechat_reply, $form, $form_state, $langcode);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );

  if (!empty($wechat_reply->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('删除'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('wechat_reply_form_submit_delete')
    );
  }
  //wechat_response_message_edit_form_submit_delete
  return $form;
}


function wechat_reply_form_submit(&$form, &$form_state) {
  global $user;
  $wechat_reply = &$form_state['wechat_reply'];

  //$message->to_user_name = $form_state['values']['to_user_name'];
  //dpm($form_state);
//  // Notify field widgets.
  field_attach_submit('wechat_reply', $wechat_reply, $form, $form_state);
  //dpm($form_state);
  $wechat_reply->title = $form_state['values']['title'];
  $wechat_reply->uid = $user->uid;
  wechat_reply_save($wechat_reply);

  drupal_set_message(t('%type reply add success.', array('%type' => $wechat_reply->msg_type)));
  $form_state['redirect'] = 'admin/content/reply';
}


function wechat_reply_delete_form_wrapper($wechatReply) {

  module_load_include('inc', 'wechat_reply', 'wechat_reply.forms');
  return drupal_get_form('wechat_reply_delete_form', $wechatReply);
}

function wechat_reply_delete_form($form, &$form_state, $wechatReply) {

  $form_state['wechat_reply'] = $wechatReply;
  $form_state['build_info']['files']['form'] = drupal_get_path('module', 'wechat_reply') . 'wechat_reply.forms.inc';
  $form['#submit'][] = 'wechat_reply_delete_form_submit';
  //module_load_include('inc', 'wechat_reply', 'wechat_reply.forms');
  return $form;
}


function wechat_reply_delete_form_submit($form, &$form_state) {
  $wechat_reply = $form_state['wechat_reply'];
  if (wechat_reply_delete($wechat_reply->id)) {
    drupal_set_message(t('ok'));
  }
  else {
    drupal_set_message(t('%title could not be deleted.'), 'error');
  }
}