<?php

function wechat_session_settings_form($form, &$form_state) {

  $options = wechat_session_status_options_list();
  //dpm($options);
  $form['required']['wechat_session_default_status'] = array(
    '#type' => 'radios',
    '#title' => t('默认状态'),
    '#default_value' => variable_get('wechat_session_default_status', 'default'),
    '#options' => $options,
    '#required' => TRUE,
  );
  $form['required']['wechat_session_send_modal'] = array(
    '#type' => 'radios',
    '#title' => t('消息回复模式'),
    '#default_value' => variable_get('wechat_session_send_modal', 'asynchrony'),
    '#options' => array(
      'sync' => '同步回复（无法使用客服接口时使用）',
      'asynchrony' => '异步回复（可以使用客服接口时使用）',
      'silent' => '静默（不回复任何消息）',
    ),
    '#required' => TRUE,
  );
  $form['required']['wechat_session_dkf'] = array(
    '#default_value' => variable_get('wechat_session_dkf', 0),
    '#type' => 'checkbox',
    '#title' => t('是否打开多客服.'),
  );
  return system_settings_form($form);
}
