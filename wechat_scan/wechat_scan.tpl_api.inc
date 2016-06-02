<?php

function wechat_scan_add_product_callback($keystandard, $keystr, $brand_info) {
  $entities = entity_load('wechat_scan_product', FALSE, [
    'keystandard' => $keystandard,
    'keystr' => $keystr
  ]);
  if (!empty($entities)) {
    throw new Exception(format_string('编码 @keystr 的商品已存在', ['@keystr' => $keystr]), 900001);
  }
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->add_product_callback($keystandard, $keystr, $brand_info);
}

/**
 * @param $keystandard
 * @param $keystr
 * @param $extinfo
 * @param int $qrcode_size
 * @return array
 * @todo  生成自定义商品二维码  加  custom  前缀
 */
function wechat_scan_get_custom_qr_callback($keystandard, $keystr, $extinfo, $qrcode_size = 64) {
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->get_custom_qr_callback($keystandard, $keystr, $extinfo, $qrcode_size = 64);
}

function wechat_scan_get_qr_callback($keystandard, $keystr, $type, $qrcode_size = 64) {
  return ["url" => 'http://open.dd:8085/themes/bartik/screenshot.png'];
  $entities = entity_load('wechat_scan_product', FALSE, [
    'keystandard' => $keystandard,
    'keystr' => $keystr
  ]);
  if (empty($entities)) {
    throw new Exception(format_string('编码 @keystr 的商品不存在', ['@keystr' => $keystr]), 900002);
  }
  else {
    $entity = reset($entities);
  }
}

function wechat_scan_get_product_list_callback($offset, $number, $status) {
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->get_product_list_callback($offset, $number, $status);
}

function wechat_scan_get_category_list_callback() {
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->get_category_list_callback();
}

function wechat_scan_get_store_vendorid_list_callback() {
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->get_store_vendorid_list_callback();
}

function wechat_scan_get_brand_tag_list_callback() {
  $Controller = new \Drupal\wechat_scan\WechatScanTplApiController();
  return $Controller->get_brand_tag_list_callback();
}