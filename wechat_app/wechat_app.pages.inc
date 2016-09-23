<?php

function wechat_app_api_callback(\Drupal\wechat_app\Entity\WechatApp $wechatApp) {
  $sdk = wechat_app_init_lib($wechatApp);
  $sdk->valid();
}