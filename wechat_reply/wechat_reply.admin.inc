<?php

class WechatReplyTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('管理回复消息字段和类型.');
    return $items;
  }
}

function wechat_reply_type_form($form, &$form_state, $wechat_reply, $op = 'edit') {


  if ($op == 'clone') {
    $wechat_reply->label .= ' (cloned)';
    $wechat_reply->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $wechat_reply->label,
    '#description' => t('The human-readable name of this message type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($wechat_reply->type) ? $wechat_reply->type : '',
    '#maxlength' => 32,
    '#disabled' => $wechat_reply->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'wechat_reply_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this message type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $wechat_reply->description,
    '#description' => t('When showing message types, those with lighter (smaller) weights get listed before message types with heavier (larger) weights.'),
    '#weight' => 10,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save message type'),
    '#weight' => 40,
  );
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#default_value' => $wechat_reply->weight,
    '#description' => t('When showing message types, those with lighter (smaller) weights get listed before message types with heavier (larger) weights.'),
    '#weight' => 10,
  );

  if (!$wechat_reply->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete message type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      //'#submit' => array('wechat_request_message_type_form_submit_delete')
    );
  }
  return $form;
}

function wechat_reply_type_form_submit(&$form, &$form_state) {
  $wechat_reply_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $wechat_reply_type->save();
  //$form_state['redirect'] = 'admin/structure/material';
  //dpm($form);
//  $wechat_request_message_type = entity_ui_form_submit_build_entity($form, $form_state);
//  // Save and go back.
//  $wechat_request_message_type->save();
  $form_state['redirect'] = 'admin/structure/wechat_reply';
}


