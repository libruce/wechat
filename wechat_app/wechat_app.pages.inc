<?php

function wechat_app_api_callback(\Drupal\wechat_app\Entity\WechatApp $wechatApp) {
  $signature = $_GET["signature"];
  $timestamp = $_GET["timestamp"];
  $nonce = $_GET["nonce"];

  $echoStr = $_GET["echostr"];

  $token = $wechatApp->token;
  $tmpArr = array($token, $timestamp, $nonce);

  sort($tmpArr, SORT_STRING);
  $tmpStr = implode($tmpArr);
  $tmpStr = sha1($tmpStr);

  if ($tmpStr == $signature) {
    echo $echoStr;
    drupal_exit();
  }
  echo "no access";
}