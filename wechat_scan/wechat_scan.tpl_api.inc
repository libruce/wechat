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