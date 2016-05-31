<?php

function wechat_scan_add_action_info_callback($title, $type, $data) {
  $type = trim($type);
  switch ($type) {
    case"media":
    case"text":
    case"link":
    case"user":
    case"card":
    case"price":
    case"product":
    case"store":
    case"recommende": {

    }
    default: {
      throw new Exception('类型错误');
    }
  }
}

function wechat_scan_add_product_callback($keystandard, $keystr, $brand_info) {
  return $brand_info;
}

function wechat_scan_get_custom_qr_callback($keystandard, $keystr, $extinfo, $qrcode_size = 64) {
  $extinfo = "x{$extinfo}";
  return [$extinfo];
}