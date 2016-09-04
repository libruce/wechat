<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/4/22
 * Time: 13:50
 */

$return_template = "<xml>
      <ToUserName><![CDATA[%s]]></ToUserName>
      <FromUserName><![CDATA[%s]]></FromUserName>
      <CreateTime>%s</CreateTime>
      <MsgType><![CDATA[text]]></MsgType>
      <Content><![CDATA[%s]]></Content>
      <FuncFlag>0</FuncFlag>
    </xml>";
$to_user_name = '1';
$from_user_name = '2';
$request_time = '3';
$content = '4';
$result_str = sprintf($return_template, $to_user_name, $from_user_name, $request_time, $content);
var_dump($result_str);