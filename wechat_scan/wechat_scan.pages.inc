<?php

function wechat_scan_add_test($form, &$form_state) {

  $a = "http://p.url.cn/hA5O8rdnQqo/iZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdjiZUkpSTs5DzpwJ821r6a0_yhvkQuT6MunrMDdj";

  $qr = new WechatScanProductQrcode;
  $qr->qrcode_url = $a;
//  $qr->save();

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('获取商品数据测试'),
//    '#collapsible' => TRUE,
//    '#collapsed' => TRUE,
//    '#tree' => TRUE,
  );

  $form['fieldset']['title'] = array(
    '#title' => t('产品标题'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['fieldset']['keystandard'] = array(
    '#type' => 'radios',
    '#title' => t('编码格式'),
    '#options' => ['ean13' => '条码', 'qrcode' => '二维码'],
    '#disabled' => TRUE,
    '#description' => t('暂时只开放了条码'),
  );
  $form['fieldset']['keystr'] = array(
    '#title' => t('编码'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );


  $form['action_info']['attributes'] = array(
    '#type' => 'fieldset',
    '#title' => '商品的推广服务区信息',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#prefix' => '<div id="action_info_wrapper">',
    '#suffix' => '</div>',
  );

  $options = array(
    'media' => t('视频播放'),
    'text' => t('文字介绍'),
    'link_image' => t('图片跳转'),
    'link' => t('普通链接'),
    'user' => t('公众号'),
    'card' => t('微信卡券'),
    'price' => t('建议零售价'),
    'product' => t('微信小店'),
    'store' => t('电商链接'),
    'recommende' => t('商品推荐'),
  );

  $default = isset($item['action_info']['attributes']['wechat_type']) ? $item['action_info']['attributes']['wechat_type'] : 'text';

  if (isset($form_state['triggering_element'])) {
    $default = $form_state['triggering_element']['#value'];
  }

  $form['action_info']['attributes']['wechat_type'] = array(
    '#type' => 'radios',
    '#title' => t('菜单类型'),
    '#default_value' => $default,
    '#options' => $options,
    '#description' => t('点击选择添加不同的菜单类型.'),
    '#required' => TRUE,
    '#ajax' => array(
      'callback' => 'wechat_menu_form_refresh',
      'wrapper' => 'wechat_menu_settings_wrapper',
    ),
  );

  switch ($default) {
    case 'text':
    case 'scancode_waitmsg':
    case 'scancode_push':
    case 'pic_sysphoto':
    case 'pic_photo_or_album':
    case 'pic_weixin':
    case 'location_select': {
      $form['action_info']['attributes']['wechat_key'] = array(
        '#type' => 'textfield',
        '#title' => t('菜单KEY值（key）'),
        '#description' => t('菜单KEY值，用于消息接口推送，不超过128字节'),
        '#required' => TRUE,
      );
      break;
    }
    case 'view': {
      $form['action_info']['attributes']['wechat_url'] = array(
        '#type' => 'textfield',
        '#title' => t('网页链接（url）'),
        '#description' => t('网页链接，用户点击菜单可打开链接，不超过256字节.'),
        '#required' => TRUE,
      );
      break;
    }
    case 'media_id':
    case 'view_limited': {
      $form['action_info']['attributes']['wechat_media_id'] = array(
        '#type' => 'textfield',
        '#title' => t('素材接口返回Media id（media_id）'),
        '#description' => t('调用新增永久素材接口返回的合法media_id.'),
        '#required' => TRUE,
      );
      break;
    }
  }
  //$form['#validate'][] = '_wechat_menu_form_validate';
  return $form;
}

function wechat_menu_form_refresh($form, &$form_state) {
  return $form['action_info']['attributes'];
}
