<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/5/26
 * Time: 21:26
 */

namespace Drupal\wechat_scan;


class ScanController {

//  /**
//   * @param $keystandard
//   * @param $keystr
//   * @todo 同步商品信息
//   */
//  function updateProduct($keystandard, $keystr) {
//    $product = $this->loadProduct($keystandard, $keystr);
//    if ($product instanceof \WechatScanProduct) {
//      $product->update($this->getProduct($keystandard, $keystr));
//    }
//    else {
//      $product = new \WechatScanProduct();
//      $product->update($this->getProduct($keystandard, $keystr));
//    }
//    $product->save();
//  }

  function loadProduct($keystandard, $keystr) {
    $entities = entity_load('wechat_scan_product', FALSE, [
      'keystandard' => $keystandard,
      'keystr' => $keystr
    ]);
    if (!empty($entities)) {
      return reset($entities);
    }
    return FALSE;
  }

  //6901798999999
  function createProduct($data) {
    dpm($data);
    $data = drupal_json_encode($data);
    $url = "https://api.weixin.qq.com/scan/product/create?access_token={$this->access_token()}";
    return $this->request($url, 'POST', $data);
  }

  function  updateProduct($data) {
    $url = "https://api.weixin.qq.com/scan/product/update?access_token={$this->access_token()}";
    $data = json_encode($data, JSON_UNESCAPED_UNICODE);
    dpm($data);
    return $this->request($url, 'POST', $data);
  }

  function getProduct($keystandard, $keystr) {
    $url = "https://api.weixin.qq.com/scan/product/get?access_token={$this->access_token()}";
    $data = [
      'keystandard' => $keystandard,
      'keystr' => $keystr,
    ];
    $data = drupal_json_encode($data);
    return $this->request($url, 'POST', $data);
  }

  /**
   * @param int $offset
   * @param $number
   * @param string $status
   * @todo 拉取商品列表。
   */
  function getProductList($offset = 0, $number = 100, $status = 'all', $keystr = NULL) {
    $url = "https://api.weixin.qq.com/scan/product/getlist?access_token={$this->access_token()}";

    $data = [
      'offset' => $offset,
      'limit' => $number,
      'status' => $status,
      'keystr' => $keystr,
    ];

    return $this->request($url, 'POST', drupal_json_encode($data));

  }

  function  getQr($keystandard, $keystr, $extinfo, $qrcode_size = 64) {
    $data = [
      'keystandard' => $keystandard,
      'keystr' => $keystr,
      'extinfo' => $extinfo,
      'qrcode_size' => $qrcode_size,
    ];

    $url = "https://api.weixin.qq.com/scan/product/getqrcode?access_token={$this->access_token()}";

    return $this->request($url, 'POST', drupal_json_encode($data));
  }

  /**
   * @param $keystandard
   * @param $keystr
   * @param $status
   * @return mixed|string
   * @todo 修改商品在微信的状态，及提交审核/取消发布商品
   */
  function modStatus($keystandard, $keystr, $status) {
    $data = [
      'keystandard' => $keystandard,
      'keystr' => $keystr,
      'status' => $status,
    ];
    $url = "https://api.weixin.qq.com/scan/product/modstatus?access_token={$this->access_token()}";
    return $this->request($url, 'POST', drupal_json_encode($data));
  }

  protected function request($url, $method = 'GET', $data = '', $timeout = 60) {
    try {
      $request = drupal_http_request($url, array(
        'headers' => array(
          'Content-Type' => 'application/json',
        ),
        'method' => $method,
        'data' => $data,
        'timeout' => $timeout,
        'context' => [],
      ));
      if ($request->code != 200) {
        throw new \Exception('网络错误');
      }

      $data = $request->data;
      $data = drupal_json_decode($data);
      return $data;
      if ($data['errcode'] != 0) {
        throw new \Exception($data['errmsg'], $data['errcode']);
      }
      return $data;
    } catch (\Exception $e) {
      watchdog_exception('微信扫一扫接口异常跟踪', $e);
      throw new $e;
    }
  }

  protected function access_token() {
    return wechat_api_get_access_token();
  }
}