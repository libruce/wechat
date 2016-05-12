<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/4/22
 * Time: 14:10
 */

namespace Drupal\wechat_api;

/**
 * Class WechatOpen
 * @package Drupal\wechat_api
 * 微信基础类库，开放平台版
 */
class WechatOpen extends Wechat {
  function __construct($options) {
    $this->access_token = isset($options['access_token']) ? $options['access_token'] : '';
  }

  /**
   * For weixin server validation
   * @param bool $return 是否返回
   */
  function valid($return = FALSE) {
    if ($_SERVER['REQUEST_METHOD'] == "POST") {
      $postStr = file_get_contents("php://input");
      $this->postxml = $postStr;
    }
  }
}