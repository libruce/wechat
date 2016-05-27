<?php

function wechat_scan_product_add_form() {
  module_load_include('inc', 'wechat_scan', 'wechat_scan.forms');
  $entity = new WechatScanProduct();
  return drupal_get_form('wechat_scan_product_form', $entity, 'add');
}

function wechat_scan_product_edit_form(WechatScanProduct $product) {
  module_load_include('inc', 'wechat_scan', 'wechat_scan.forms');
  return drupal_get_form('wechat_scan_product_form', $product, 'edit');
}

function wechat_scan_product_form($form, &$form_state, WechatScanProduct $product, $op) {
  $form_state['WechatScanProduct'] = $product;

  $langcode = LANGUAGE_NONE;
  field_attach_form('wechat_scan_product', $product, $form, $form_state, $langcode);

  $form['title'] = array(
    '#title' => t('产品标题'),
    '#type' => 'textfield',
    '#default_value' => $product->title,
    '#required' => TRUE,
  );
  $form['keystandard'] = array(
    '#type' => 'radios',
    '#title' => t('编码格式'),
    '#default_value' => $product->keystandard,
    '#options' => ['ean13' => '条码', 'qrcode' => '二维码'],
    '#disabled' => TRUE,
    '#description' => t('暂时只开放了条码'),
  );
  $form['keystr'] = array(
    '#title' => t('编码'),
    '#type' => 'textfield',
    '#default_value' => $product->keystr,
    '#required' => TRUE,
  );


  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
  );

  if (!empty($product->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('删除'),
      '#submit' => array('wechat_reply_form_submit_delete')
    );
  }
  return $form;
}

function wechat_scan_product_form_submit($form, &$form_state) {
  $entity = $form_state['WechatScanProduct'];
  entity_form_submit_build_entity('wechat_scan_product', $entity, $form, $form_state);

  $entity->save();
  dpm($entity);
  dpm($form_state);


}