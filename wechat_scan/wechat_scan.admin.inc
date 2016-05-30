<?php

function wechat_scan_settings_form($form, &$form_state) {
  $form['merchantinfo'] = array(
    '#type' => 'fieldset',
    '#title' => t('同步商户信息'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
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
    '#collapsed' => FALSE,
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
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['product_getlist']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('wechat_scan_settings_form_product_getlist'),
    '#value' => t('同步商品信息'),
  );


  $form['test'] = array(
    '#type' => 'fieldset',
    '#title' => t('测试'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,

  );
  $form['test']['data'] = array(
    '#type' => 'textarea',
    '#title' => t('测试数据'),
    '#default_value' => variable_get('wechat_scan_test_data', ''),
  );
  $form['test']['submit'] = array(
    '#type' => 'submit',
    '#submit' => array('wechat_scan_settings_form_test'),
    '#value' => t('提交'),
  );
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
  return $form;
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
//    $r = $Controller->createProduct($data1);
//    dpm($r);
    $r = $Controller->updateProduct($data1);
    dpm($r);

    $extinfo = drupal_random_key(10);
    $qr = $Controller->getQr('ean13', '6901798999986', $extinfo, 64);

    dpm($extinfo);
    dpm($qr);

  } catch (Exception $e) {
    dpm($e->getMessage());
  }
}

function wechat_scan_settings_form_product_getlist($form, &$form_state) {
  $access_token = wechat_api_get_access_token();

  $url = "https://api.weixin.qq.com/scan/product/getlist?access_token={$access_token}";
  /**
   *
   * {
   * "offset": "1",
   * "limit": "10",
   * "status":"on",
   * }
   */
  $data = [
    'offset' => 1,
    'limit' => 100,
    'status' => 'all',
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

function wechat_scan_settings_form_merchantinfo($form, &$form_state) {
  $access_token = wechat_api_get_access_token();
  $url = "https://api.weixin.qq.com/scan/merchantinfo/get?access_token={$access_token}";
  $request = drupal_http_request($url);

  if ($request->code == 200) {
    $data = $request->data;

    $data = drupal_json_decode($data);
    dpm($data);
    if ($data['errcode'] == 0) {

      variable_set('wechat_scan_brand_tag_list', $data['brand_tag_list']);
      $v = taxonomy_vocabulary_machine_name_load('brand_tag');
      $term = taxonomy_term_load_multiple(FALSE, ['vid' => $v->vid]);
      foreach ($term as $i) {
        taxonomy_term_delete($i->tid);
      }
      if (!empty($data['brand_tag_list']) && is_array($data['brand_tag_list'])) {
        foreach ($data['brand_tag_list'] as $i) {
          $t = new stdClass();
          $t->vid = $v->vid;
          $t->name = $i;
          taxonomy_term_save($t);
        }
      }
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