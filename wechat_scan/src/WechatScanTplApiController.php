<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/5/31
 * Time: 17:51
 */

namespace Drupal\wechat_scan;


class WechatScanTplApiController {
  /**
   * @param $keystandard
   * @param $keystr
   * @param $extinfo
   * @param int $qrcode_size
   * @return array
   * @todo 生成自定义商品二维码  加  custom  前缀
   */
  function get_custom_qr_callback($keystandard, $keystr, $extinfo, $qrcode_size = 64) {
    if ($this->checkProductExists($keystandard, $keystr)) {
      //增加前缀
      $extinfo = "custom{$extinfo}";

      return [];
    }
    throw new \Exception(format_string('编码 @keystr 的商品不存在', ['@keystr' => $keystr]), 900002);
  }

  function add_product_callback($keystandard, $keystr, $brand_info) {
    $product = new \WechatScanProduct();
    $product->keystandard = $keystandard;
    $product->keystr = $keystr;
    $product->title = $brand_info['base_info']['title'];
    $product->data = serialize($brand_info);

    $product->save();
    return [$product];
  }

  /**
   * @param $keystandard
   * @param $keystr
   * @return bool
   * @todo 通过商品编码判断商品是否已存在，存在返回 true  其它返回 false
   */
  protected function checkProductExists($keystandard, $keystr) {
    $entities = entity_load('wechat_scan_product', FALSE, [
      'keystandard' => $keystandard,
      'keystr' => $keystr
    ]);
    if (!empty($entities)) {
      return TRUE;
    }
    return FALSE;
  }
}