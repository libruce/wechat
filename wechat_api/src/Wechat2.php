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
      watchdog('$postStr',$postStr);
    }
  }
}