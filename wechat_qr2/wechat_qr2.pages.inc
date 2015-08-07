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


function wechat_qr2_edit_form($entity) {
  module_load_include('inc', 'wechat_qr2', 'wechat_reply.pages');
  return drupal_get_form('wechat_qr2_form', $entity, 'edit');
}

function wechat_qr2_form($form, &$form_state, $entity, $op) {

  //dpm($entity);
  $form_state['wechat_qr2'] = $entity;

  $langcode = entity_language('wechat_qr2', $entity);


  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }
  $disabled = FALSE;
  if ($op == 'edit') {
    $disabled = TRUE;
  }
  $form['qr_key'] = array(
    '#title' => t('二维码KEY'),
    '#type' => 'textfield',
    '#default_value' => $entity->qr_key,
    '#required' => TRUE,
    '#size' => 30,
    '#weight' => 1,
    '#disabled' => $disabled,
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
    '#disabled' => $disabled,
  );
  $form['expire'] = array(
    '#title' => t('过期时间'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->expire) ? $entity->expire : 604800,
    '#size' => 30,
    '#weight' => 1,
    '#disabled' => $disabled,
  );

  field_attach_form('wechat_qr2', $entity, $form, $form_state, $langcode);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );

  return $form;
}


function wechat_qr2_form_submit(&$form, &$form_state) {
  global $user;
  $entity = &$form_state['wechat_qr2'];
  field_attach_submit('wechat_qr2', $entity, $form, $form_state);
  $entity->qr_key = $form_state['values']['qr_key'];
  $entity->qr_type = $form_state['values']['qr_type'];
  $entity->expire = $form_state['values']['expire'];
  $entity->save();
}
