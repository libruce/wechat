<?php

function wechat_scan_add_test($form, &$form_state) {
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

  return $form;
}