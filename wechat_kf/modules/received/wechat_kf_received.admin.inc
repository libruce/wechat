<?php

class WechatKfReceivedTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = t('管理回复消息字段和类型.');
    return $items;
  }
}

function wechat_kf_received_type_form($form, &$form_state, $entity, $op = 'edit') {


  if ($op == 'clone') {
    $entity->label .= ' (cloned)';
    $entity->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $entity->label,
    '#description' => t('The human-readable name of this message type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($entity->type) ? $entity->type : '',
    '#maxlength' => 32,
    '#disabled' => $entity->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'wechat_kf_received_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this message type. It must only contain lowercase letters, numbers, and underscores.'),
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
    '#default_value' => $entity->weight,
    '#description' => t('When showing message types, those with lighter (smaller) weights get listed before message types with heavier (larger) weights.'),
    '#weight' => 10,
  );

  if (!$entity->isLocked() && $op != 'add' && $op != 'clone') {
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

function wechat_kf_received_type_form_submit(&$form, &$form_state) {
  $entity_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $entity_type->save();
  //$form_state['redirect'] = 'admin/structure/material';
  //dpm($form);
//  $wechat_request_message_type = entity_ui_form_submit_build_entity($form, $form_state);
//  // Save and go back.
//  $wechat_request_message_type->save();
  $form_state['redirect'] = 'admin/structure/wechat_reply';
}

