<?php

/**
 * @return array
 * 微信消息状态定义，将微信消息对象传给回调函数
 * 'status' => array(
 * 'description' => '状态.',
 * 'type' => 'varchar',
 * 'length' => 255,
 * 'not null' => TRUE,
 * ),
 * 'name' => array(
 * 'description' => '状态name.',
 * 'type' => 'varchar',
 * 'length' => 255,
 * 'not null' => TRUE,
 * ),
 * 'function_callback' => array(
 * 'description' => '状态回调函数.',
 * 'type' => 'varchar',
 * 'length' => 255,
 * 'not null' => TRUE,
 * ),
 * 'echo_callback' => array(
 * 'description' => '状态echo函数.',
 * 'type' => 'varchar',
 * 'length' => 255,
 * 'not null' => TRUE,
 * ),
 * 'timeout' => array(
 * 'description' => '超时时间,时间秒。0表示不超时',
 * 'type' => 'int',
 * 'unsigned' => TRUE,
 * 'not null' => TRUE,
 * ),
 */
function hook_wechat_session_status() {
  return array(
    'basic' => array(
      'name' => '普通会话状态',
      'function callback' => 'basic_massage',
      'echo callback' => 'basic_echo',
      'timeout' => 0,
    ),
  );
}