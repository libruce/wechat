<?php
function wechat_qr2_add_page() {
  $item = menu_get_item();
  //dpm($item);
  $content = system_admin_menu_block($item);
  // Bypass the node/add listing if only one content type is available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('node_add_list', array('content' => $content));
}

function wechat_qr2_add_form($type) {
  $entity = entity_create('wechat_qr2', array('bundle' => $type));
  module_load_include('inc', 'wechat_qr2', 'wechat_reply.pages');
  return drupal_get_form('wechat_qr2_form', $entity, 'add');
}

function wechat_qr2_form($form, &$form_state, $entity, $op) {

  //dpm($entity);
  $form_state['wechat_qr2'] = $entity;

  $langcode = entity_language('wechat_qr2', $entity);


  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }


  $form['qr_key'] = array(
    '#title' => t('二维码KEY'),
    '#type' => 'textfield',
    '#default_value' => $entity->qr_key,
    '#required' => TRUE,
    '#size' => 30,
    '#weight' => 1,
  );
  $form['qr_type'] = array(
    '#title' => t('二维码类型'),
    '#type' => 'radios',
    '#default_value' => isset($entity->qr_type) ? $entity->qr_type : 0,
    '#options' => array(
      '0' => t('临时'),
      '1' => t('永久')
    ),
    '#weight' => 1,
  );
  $form['expire'] = array(
    '#title' => t('过期时间'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->expire) ? $entity->expire : 0,
    '#size' => 30,
    '#weight' => 1,
  );

  field_attach_form('wechat_qr2', $entity, $form, $form_state, $langcode);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );

  if (!empty($entity->id)) {
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


function wechat_qr2_form_submit(&$form, &$form_state) {
  global $user;
  $entity = &$form_state['wechat_qr2'];

  //$message->to_user_name = $form_state['values']['to_user_name'];
  //dpm($form_state);
//  // Notify field widgets.
  field_attach_submit('wechat_qr2', $entity, $form, $form_state);
  //dpm($form_state);
  $entity->title = $form_state['values']['title'];
  $entity->uid = $user->uid;

  drupal_set_message(t('%type reply add success.', array('%type' => $entity->msg_type)));

}
