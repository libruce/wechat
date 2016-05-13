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