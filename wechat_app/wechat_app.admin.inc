<?php

use Drupal\wechat_app\Entity\WechatApp;

function wechat_app_add_form() {
  module_load_include('inc', 'wechat_app', 'wechat_app.admin');
  $entity = new WechatApp();
  return drupal_get_form('wechat_app_entity_form', $entity, 'add');
}

function wechat_app_edit_form(WechatApp $app) {
  module_load_include('inc', 'wechat_app', 'wechat_app.admin');
  return drupal_get_form('wechat_app_entity_form', $app, 'edit');
}

function wechat_app_entity_form($form, &$form_state, WechatApp $entity, $op) {
  $form_state['entity'] = $entity;
  global $base_url;

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => '公众号信息',
    '#description' => '保存后生成接入地址',
  );

  if (!empty($entity->id)) {
    $form['fieldset']['#description'] = format_string("服务器微信接入地址：<b>@base_url/wechat/@id</b>",
      array(
        '@base_url' => $base_url,
        '@id' => $entity->id,
      ));
  }

  $form['fieldset']['name'] = array(
    '#title' => t('名称'),
    '#type' => 'textfield',
    '#default_value' => $entity->name,
  );

  $form['fieldset']['subscription'] = array(
    '#title' => t('公众号原始ID'),
    '#type' => 'textfield',
    '#default_value' => $entity->subscription,
  );
  $form['fieldset']['appid'] = array(
    '#title' => t('AppId'),
    '#type' => 'textfield',
    '#default_value' => $entity->appid,
  );
  $form['fieldset']['appsecret'] = array(
    '#title' => t('Appsecret'),
    '#type' => 'textfield',
    '#default_value' => $entity->appsecret,
  );
  $form['fieldset']['token'] = array(
    '#title' => t('Token'),
    '#type' => 'textfield',
    '#default_value' => $entity->token,
  );
  $form['fieldset']['aes_key'] = array(
    '#title' => t('公众号消息加解密Key'),
    '#type' => 'textfield',
    '#default_value' => $entity->aes_key,
  );

  $form['fieldset']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('是否启用'),
    '#default_value' => $entity->status,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
    '#weight' => 40,
  );

  return $form;
}

function wechat_app_entity_form_submit($form, &$form_state) {
  $entity = $form_state['entity'];
  if ($entity instanceof WechatApp) {
    $entity->name = $form_state['values']['name'];
    $entity->subscription = $form_state['values']['subscription'];
    $entity->appid = $form_state['values']['appid'];
    $entity->appsecret = $form_state['values']['appsecret'];
    $entity->token = $form_state['values']['token'];
    $entity->aes_key = $form_state['values']['aes_key'];
    $entity->status = $form_state['values']['status'];
    $entity->save();
    $form_state['redirect'] = "admin/content/wechat-app/{$entity->id}/edit";
  }
}