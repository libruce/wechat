<?php

function wechat_scan_settings_form($form, &$form_state) {
//  $form['fieldset']['weixin_open_appid'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Appid'),
//    '#default_value' => variable_get('weixin_open_appid', ''),
//    '#required' => TRUE,
//  );
//  $form['fieldset']['weixin_open_appsecret'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Appsecret'),
//    '#default_value' => variable_get('weixin_open_appsecret', ''),
//    '#required' => TRUE,
//  );
//
//  $form['fieldset']['weixin_open_token'] = array(
//    '#type' => 'textfield',
//    '#title' => t('公众号消息校验Token'),
//    '#default_value' => variable_get('weixin_open_token', $token),
//    '#required' => TRUE,
//  );
//  $form['fieldset']['weixin_open_aes_key'] = array(
//    '#type' => 'textfield',
//    '#title' => t('公众号消息加解密Key'),
//    '#default_value' => variable_get('weixin_open_aes_key', $key),
//    '#required' => TRUE,
//  );

  $form['submit'] = array('#type' => 'submit', '#value' => t('提交'));

  return $form;
}

function wechat_scan_settings_form_submit($form, &$form_state) {
  $access_token = wechat_api_get_access_token();
  $url = "https://api.weixin.qq.com/scan/merchantinfo/get?access_token={$access_token}";
  $request = drupal_http_request($url);
  if ($request->code == 200) {
    $data = $request->data;
    $data = drupal_json_decode($data);
    dpm($data);
  }
}