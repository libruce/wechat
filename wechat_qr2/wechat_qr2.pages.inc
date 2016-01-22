<?php
function wechat_qr2_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('node_add_list', array('content' => $content));
}

function wechat_qr2_view_page($entity) {
  $output = '';
  $ticket = UrlEncode($entity->ticket);
  $expire = TRUE;
  if (($entity->qr_type) || time() < $entity->create_time + $entity->expire) {
    $expire = FALSE;
  }
  if ($expire) {
    $output .= "已过期";
  }
  else {
    $output .= '<img src="' . 'https://mp.weixin.qq.com/cgi-bin/showqrcode?ticket=' . $ticket . '"/>';
  }
  return $output;
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

  $form_state['wechat_qr2'] = $entity;

  $langcode = entity_language('wechat_qr2', $entity);


  if (empty($langcode)) {
    $langcode = LANGUAGE_NONE;
  }
  $disabled = FALSE;
  if ($op == 'edit') {
    $disabled = TRUE;
  }
  $form['title'] = array(
    '#title' => t('标题'),
    '#type' => 'textfield',
    '#default_value' => $entity->title,
    '#required' => TRUE,
    '#size' => 30,
    '#weight' => -1,
  );

  $form['qr_key'] = array(
    '#title' => t('二维码KEY'),
    '#description' => t('
    <b>临时二维码:</b><br/>
       32位非0整型.<br/>
       最大数:<b>4294967295</b><br/>
    <b>永久二维码:</b><br/>
       数字:1--100000<br/>
       字符串:长度1到64.
    '),
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
    '#states' => array(
      'visible' => array(
        ':input[name="qr_type"]' => array('value' => '0'),
      ),
    ),
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

function wechat_qr2_form_validate($form, &$form_state) {
  $qr_type = $form_state['values']['qr_type'];
  $qr_key = $form_state['values']['qr_key'];
  if ($qr_type == 0 && !is_numeric($qr_key)) {
    form_set_error('qr_key', t('临时二维码KEY只能是数字'));
  }
}

function wechat_qr2_form_submit(&$form, &$form_state) {
  global $user;
  $entity = &$form_state['wechat_qr2'];
  field_attach_submit('wechat_qr2', $entity, $form, $form_state);
  $entity->uid = $user->uid;
  $entity->title = $form_state['values']['title'];
  $entity->qr_key = $form_state['values']['qr_key'];
  $entity->qr_type = $form_state['values']['qr_type'];
  $entity->expire = $form_state['values']['expire'];
  $entity->save();
}