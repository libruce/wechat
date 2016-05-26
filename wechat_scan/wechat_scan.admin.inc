<?php

function wechat_scan_settings_form($form, &$form_state) {
  $form['merchantinfo'] = array(
    '#type' => 'fieldset',
    '#title' => t('同步商户信息'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['merchantinfo']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('wechat_scan_settings_form_merchantinfo'),
    '#value' => t('同步商户信息'),
  );

  $form['testwhitelist'] = array(
    '#type' => 'fieldset',
    '#title' => t('设置测试人员'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  $form['testwhitelist']['openid'] = array(
    '#type' => 'textarea',
    '#title' => t('微信用户OpenId'),
    '#description' => t('设置测试人员，OpenId。多个用 , 隔开.'),
    '#default_value' => variable_get('wechat_scan_testwhitelist', [
      'openid' => '',
      'username' => ''
    ])['openid'],
  );
  $form['testwhitelist']['username'] = array(
    '#type' => 'textarea',
    '#title' => t('微信用户名'),
    '#description' => t('设置测试人员，微信用户名。多个用 , 隔开.'),
    '#default_value' => variable_get('wechat_scan_testwhitelist', [
      'openid' => '',
      'username' => ''
    ])['username'],
  );
  $form['testwhitelist']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('wechat_scan_settings_form_testwhitelist'),
    '#value' => t('提交'),
  );


  return $form;
}

function wechat_scan_settings_form_merchantinfo($form, &$form_state) {
  $access_token = wechat_api_get_access_token();
  $url = "https://api.weixin.qq.com/scan/merchantinfo/get?access_token={$access_token}";
  $request = drupal_http_request($url);
  if ($request->code == 200) {
    $data = $request->data;
    $data = <<<j
{
 "errcode": 0,
 "errmsg": "ok",
 "verified_cate_list":[
  {
   "verified_cate_id": 200531967,
   "verified_cate_name": "调味品"
  }
 ],
 "verified_firm_code_list":[8888],
 "brand_tag_list":[
  "小耿哥8",
  "testtag"
 ]
}
j;
;
    $data = drupal_json_decode($data);
    dpm($data);
    if ($data['errcode'] == 0) {
      variable_set('wechat_scan_verified_cate_list', $data['verified_cate_list']);
      variable_set('wechat_scan_verified_firm_code_list', $data['verified_firm_code_list']);
      variable_set('wechat_scan_brand_tag_list', $data['brand_tag_list']);
    }
  }

}

function wechat_scan_settings_form_testwhitelist($form, &$form_state) {
  $access_token = wechat_api_get_access_token();
  $url = "https://api.weixin.qq.com/scan/testwhitelist/set?access_token={$access_token}";
  $testwhitelist['openid'] = $form_state['values']['testwhitelist']['openid'];
  $testwhitelist['username'] = $form_state['values']['testwhitelist']['username'];
  variable_set('wechat_scan_testwhitelist', $testwhitelist);
  $openid = drupal_explode_tags($testwhitelist['openid']);
  $username = drupal_explode_tags($testwhitelist['username']);
  $data = [
    'openid' => $openid,
    'username' => $username
  ];
  $data = drupal_json_encode($data);

  $request = drupal_http_request($url, array(
    'headers' => array(
      'Content-Type' => 'application/json',
    ),
    'method' => 'POST',
    'data' => $data,
    'timeout' => 60,
    'context' => [],
  ));

  if ($request->code == 200) {
    $data = $request->data;
    $data = drupal_json_decode($data);
  }
}