<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/5/12
 * Time: 22:35
 */

namespace Drupal\wechat_api;


class Wechat2 extends Wechat {
  function __construct($options) {
    $this->access_token = isset($options['access_token']) ? $options['access_token'] : '';
  }

  function valid($return = FALSE) {
    if ($_SERVER['REQUEST_METHOD'] == "POST") {
      $postStr = file_get_contents("php://input");
      $this->postxml = $postStr;
      watchdog('$postStr', $postStr);
    }
  }

  function sendCustomMessage($data) {
    if (!$this->access_token && !$this->checkAuth()) {
      return FALSE;
    }
    watchdog('api_data', $data);
    //$data = self::json_encode($data);
    //$data = json_encode($data, JSON_UNESCAPED_UNICODE);
    $result = $this->http_post(self::API_URL_PREFIX . self::CUSTOM_SEND_URL . 'access_token=' . $this->access_token, self::json_encode($data));

    watchdog('$result', json_encode(($result)));
    if ($result) {
      $json = json_decode($result, TRUE);
      if (!$json || !empty($json['errcode'])) {
        $this->errCode = $json['errcode'];
        $this->errMsg = $json['errmsg'];
        return FALSE;
      }
      return $json;
    }
    return FALSE;
  }
}