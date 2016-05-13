<?php

/**
 * wechat_session 覆写的wechat_api 微信接口回调
 */
function wechat_session_callback() {
  try {


    $wechat_obj = wechat_api_init_wechatobj();
    $wechat_obj->valid(variable_get('wechat_api_debug', FALSE));
    $wechat_obj->getRev();

    $openid = $wechat_obj->getRevFrom();
    if (empty($openid)) {
      throw new Exception('Openid为空');
    }
    $wechat_session = wechat_session_load($openid);

    if (empty($wechat_session)) {
      $status_info = wechat_session_set_default_status($openid);
    }
    else {
      //存在判断是否过期
      $status_info = wechat_session_status_load($wechat_session->status);
      $timeout = $status_info['timeout'];
      if ($timeout != 0 && time() > $wechat_session->update_time + $timeout) {
        $status_info = wechat_session_set_default_status($openid);
      }
    }

    $function_callback = $status_info['function callback'];
    $echo_callback = $status_info['echo callback'];

    $send_modal = variable_get('wechat_session_send_modal', 'asynchrony');
    //判断消息回复模式，同步 | 异步。同步回复暂未开发完成
    if ($send_modal == 'asynchrony') {
      //判断是否开启多客服
      if (variable_get('wechat_session_dkf', 0)) {
        $send_to_user_name = $wechat_obj->getRevFrom();
        $send_from_user_name = $wechat_obj->getRevTo();
        $request_time = time();

        $return_template = "
      <xml>
        <ToUserName><![CDATA[%s]]></ToUserName>
        <FromUserName><![CDATA[%s]]></FromUserName>
        <CreateTime>%s</CreateTime>
        <MsgType><![CDATA[transfer_customer_service]]></MsgType>
      </xml>";

        $result_str = sprintf($return_template, $send_to_user_name, $send_from_user_name, $request_time);

        echo $result_str;
      }
      else {
        echo $echo_callback($wechat_obj);
      }
    }
    if ($send_modal == 'silent') {
      echo 'success';
    }

    $function_callback($wechat_obj);
  } catch (Exception $e) {
    watchdog_exception('', $e);
  }
}
