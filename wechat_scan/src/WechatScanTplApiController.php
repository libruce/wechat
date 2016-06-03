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

  function delete_product_callback($spids) {
    foreach ($spids as $spid) {
      $this->delete_product($spid);
    }
    return [];
  }

  protected function delete_product($spid) {
    entity_delete('wechat_scan_product', $spid);
  }

  /**
   * @param $keystandard
   * @param $keystr
   * @return bool
   * @todo 检查商品编码，正确返回 true  不正确返回 false
   */
  protected function checkKeystr($keystandard, $keystr) {
    //@todo 如果是条码类型，检测编码前缀，及格式
    if ($keystandard != 'ean13') {
      if (is_numeric($keystr) && strlen($keystr) == 13) {
        $verified_list = variable_get('wechat_scan_verified_list', []);
        foreach ($verified_list as $verified) {
          if (strncmp($keystr, $verified['verified_firm_code'], 7) == 0) {
            return TRUE;
          }
        }
      }
      return FALSE;
    }
    return TRUE;
  }

  function add_product_callback($keystandard, $keystr, $brand_info) {

    if (!$this->checkKeystr($keystandard, $keystr)) {
      throw new \Exception('商品编码不正确', 900004);
    }

    $product = new \WechatScanProduct();
    $product->keystandard = $keystandard;
    $product->keystr = $keystr;
    $product->title = $brand_info['base_info']['title'];
    $product->data = serialize($brand_info);

    $product->save();
    return [$product];
  }

  function get_product_list_callback($offset, $number, $status) {
    $Query = new \EntityFieldQuery();
    $list = [];
    return ['list' => $list];
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

  function get_category_list_callback() {
    $list = [];
    $verified_list = variable_get('wechat_scan_verified_list', []);
    foreach ($verified_list as $ilist) {
      foreach ($ilist['verified_cate_list'] as $i) {
        $list[$i['verified_cate_id']] = $i['verified_cate_name'];
      }
    }
    return ['list' => $list];
  }

  function get_store_vendorid_list_callback() {
    $list = [
      2 => '亚马逊',
      3 => '当当网',
      4 => '京东',
      9 => '一号店',
      11 => '聚美优品',
      19 => '酒仙网',
    ];
    return ['list' => $list];
  }

  function get_brand_tag_list_callback() {
    $list = [];
    $brand_tag_list = variable_get('wechat_scan_brand_tag_list', []);
    foreach ($brand_tag_list as $i) {
      $list[] = $i;
    }
    return ['list' => $list];
  }

  function  change_product_status_callback($spid, $status) {
    $sproduct = wechat_session_load($spid);
    if (!empty($sproduct) && $sproduct instanceof \WechatScanProduct) {
      $sproduct->setStatus($status);
      $sproduct->save();
    }
    throw new \Exception(format_string('SPID @spid 的商品不存在', ['@spid' => $spid]), 900003);
  }
}