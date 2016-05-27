<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/5/26
 * Time: 21:26
 */

namespace Drupal\wechat_scan;


class ScanController {

  function createProduct($data) {
    $data = drupal_json_encode($data);
    $url = "https://api.weixin.qq.com/scan/product/create?access_token={$this->access_token()}";
    return $this->request($url, 'POST', $data);
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