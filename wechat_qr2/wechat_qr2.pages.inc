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

function wechat_qr2_view_page($entity) {
  $output = '';
  $ticket = UrlEncode($entity->ticket);
//  dpm($entity);
  $output .= "<div style='font-size: 20px'><b>该二维码是个人推荐码</b></div>";
  $expire = TRUE;
  if (($entity->qr_type) || time() < $entity->create_time + $entity->expire) {
    $expire = FALSE;
  }

  if ($expire) {
    $output .= "已过期";
  }
  else {
    $output .= '<img src="' . 'https://mp.weixin.qq.com/cgi-bin/showqrcode?ticket=' . $ticket . '"/>';
    $output .= '
    <div style="padding: 15px">

     <div>点击右上方发送给好友，好友长按二维码识别关注【慢城联盟】，则你推荐好友成功，系统将自动统计你推荐好友数量。</div>
    <div>累计一定数量，将成为本平台忠实粉丝，盟主将邀约你参与线下粉丝聚会活动，欢迎你的加入！</div>
    <div>———————————————————</div>
    <div>注：关注平台后可在“招募会员”中获取自己的专属推广二维码！</div>
    </div>
';
  }
//  $output .= "<div><b>KEY:</b> {$entity->qr_key}</div>";
//  $username = format_username(user_load($entity->uid));
//  $output .= "<div><b>创建者:</b>{$username}</div>";
//  $output .= '<div><b>创建时间:</b>' . format_date($entity->create_time) . '</div>';
//  $output .= '<div><b>过期时间:</b>' . format_date($entity->create_time + $entity->expire) . '</div>';
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
//  dpm($form_state);
  $qr_type = $form_state['values']['qr_type'];
  $qr_key = $form_state['values']['qr_key'];
  if ($qr_type == 0 && !is_numeric($qr_key)) {
    form_set_error('qr_key', t('临时二维码KEY只能是数字'));
  }


//  dpm($form);
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
