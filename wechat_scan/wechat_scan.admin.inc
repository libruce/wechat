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
    '#value' => t('设置测试人员'),
  );

  $form['product_getlist'] = array(
    '#type' => 'fieldset',
    '#title' => t('同步商品信息'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
    '#description' => t('从微信服务器同步商品信息到本地服务器。这可能会覆盖本地商品数据。'),
  );
  $form['product_getlist']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('wechat_scan_settings_form_product_getlist'),
    '#value' => t('同步商品信息'),
  );

  /**
   *
   */
  if (wechat_api_isdebug()) {
    $form['test'] = array(
      '#type' => 'fieldset',
      '#title' => t('创建商品测试'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,

    );
    $form['test']['data'] = array(
      '#type' => 'textarea',
      '#title' => t('数据'),
      '#default_value' => variable_get('wechat_scan_test_data', ''),
    );
    $form['test']['submit'] = array(
      '#type' => 'submit',
      '#submit' => array('wechat_scan_settings_form_test'),
      '#value' => t('提交创建商品测试'),
    );

    $form['update'] = array(
      '#type' => 'fieldset',
      '#title' => t('更新商品测试'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,

    );
    $form['update']['data'] = array(
      '#type' => 'textarea',
      '#title' => t('数据'),
    );
    $form['update']['submit'] = array(
      '#type' => 'submit',
      '#submit' => array('wechat_scan_settings_form_testupdate'),
      '#value' => t('提交更新商品测试'),
    );

    $form['getproduct'] = array(
      '#type' => 'fieldset',
      '#title' => t('获取商品数据测试'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,

    );
    $form['getproduct']['data'] = array(
      '#type' => 'textfield',
      '#title' => t('编码'),
    );
    $form['getproduct']['submit'] = array(
      '#type' => 'submit',
      '#submit' => array('wechat_scan_settings_form_getproduct'),
      '#value' => t('获取商品数据'),
    );

    $form['qr'] = array(
      '#type' => 'fieldset',
      '#title' => t('商品二维码生成测试'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,

    );
    $form['qr']['data'] = array(
      '#type' => 'textfield',
      '#title' => t('产品编码'),
    );
    $form['qr']['extinfo'] = array(
      '#type' => 'textarea',
      '#title' => t('商户自定义'),
    );
    $form['qr']['submit'] = array(
      '#type' => 'submit',
      '#submit' => array('wechat_scan_settings_form_qr'),
      '#value' => t('获取二维码数据'),
    );
  }
  return $form;
}

function wechat_scan_settings_form_qr($form, &$form_state) {
  $Controller = new \Drupal\wechat_scan\ScanController();
  $extinfo = $form_state['values']['qr']['extinfo'];
  $data = $form_state['values']['qr']['data'];
  $qr = $Controller->getQr('ean13', $data, $extinfo, 64);
  dpm($qr);
}

function wechat_scan_settings_form_testupdate($form, &$form_state) {
  $data = $form_state['values']['test']['data'];
  $Controller = new \Drupal\wechat_scan\ScanController();
  $data1 = drupal_json_decode($data);
  $r = $Controller->updateProduct($data1);
  dpm($r);
}


function wechat_scan_settings_form_getproduct($form, &$form_state) {
  $Controller = new \Drupal\wechat_scan\ScanController();
  $data = $form_state['values']['getproduct']['data'];
  $r = $Controller->getProduct('ean13', $data);
  dpm($r);
}

//LQ6p-Brzf6o
function wechat_scan_settings_form_test($form, &$form_state) {
  $Controller = new \Drupal\wechat_scan\ScanController();
  try {
    $data = $form_state['values']['test']['data'];
    variable_set('wechat_scan_test_data', $data);
//    dpm($data);
    $data1 = drupal_json_decode($data);
//    dpm($data1);
//    $Controller = new \Drupal\wechat_scan\ScanController();
    $r = $Controller->createProduct($data1);
    dpm($r);


  } catch (Exception $e) {
    dpm($e->getMessage());
  }
}

function wechat_scan_settings_form_product_getlist($form, &$form_state) {
  try {
    $Controller = new \Drupal\wechat_scan\ScanController();
    $list = $Controller->getProductList();
    dpm($list);
//    return;
    $operations = [];
    foreach ($list['key_list'] as $item) {
      $operations[] = [
        'wechat_scan_pull_product',
        [$item['keystandard'], $item['keystr']]
      ];
    }
    batch_set(array(
      'operations' => $operations,
      'title' => '商品信息同步',
    ));

  } catch (Exception $e) {
    drupal_set_message('出现错误', 'error');
  }
}

function wechat_scan_settings_form_merchantinfo($form, &$form_state) {
  $access_token = wechat_api_get_access_token();
  $url = "https://api.weixin.qq.com/scan/merchantinfo/get?access_token={$access_token}";
  $request = drupal_http_request($url);
  if ($request->code == 200) {
    $data = $request->data;
    $data = drupal_json_decode($data);
    if ($data['errcode'] == 0) {
      variable_set('wechat_scan_brand_tag_list', $data['brand_tag_list']);
      variable_set('wechat_scan_verified_list', $data['verified_list']);
    }
  }
}

//ob2sIv3Jgq7HBMplEv-dsRaX_wmg
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
    dpm($data);
  }
  dpm($request);
}


//  $Controller = new \Drupal\wechat_scan\ScanController();
//  $r = $Controller->getProduct('ean13', '6901798143587');
//
//  dpm($r);
//
//  $url = 'http://mmbiz.qpic.cn/mmbiz/PMXyQaV1nePHiax1kCFoZ259646fiaqd1aaiarOoCI5Bn2eVHqkDuTCgVeNrP1EQ4SyBDibcw0fWc7EIAjLEF6goEA/0?wx_fmt=jpeg';
//
//  $content = file_get_contents($url);
//
//
//  $filename = '42° 泸州邮礼天下-喜庆装 500ml';
//  if (module_exists('transliteration')) {
//    module_load_include('inc', 'transliteration');
//
//    $langcode = NULL;
//    if (!empty($_POST['language'])) {
//      $languages = language_list();
//      $langcode = isset($languages[$_POST['language']]) ? $_POST['language'] : NULL;
//    }
//    $filename = transliteration_clean_filename($filename, $langcode);
//  }
//
//  dpm($filename);


//  $a = file_unmanaged_save_data($content);

//  dpm($a);

//  global $user;
//  $file = new stdClass();
//  $file->uid = $user->uid;
//  $file->status = 0;
//  $file->filename = trim(basename($filepath), '.');
//  $file->uri = $filepath;
//  $file->filemime = file_get_mimetype($file->filename);
//  $file->filesize = filesize($filepath);
//
//  file_save($file);
//  dpm($file);

// https://api.weixin.qq.com/scan/product/getlist?access_token=PE8Pe2gEpsHPb5TVoIzu_3f-166mw2pb0UEey0ni-kAf1uvE0bh0BnFSY2TTi8NsgXMF3EafzwHBNQs-PaLmCg