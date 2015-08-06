<?php

class WechatRequestTypeUIController extends EntityDefaultUIController {
  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = '管理字段';
    return $items;
  }
}

function wechat_request_type_form($form, &$form_state, $wechat_request, $op = 'edit') {


  if ($op == 'clone') {
    $wechat_request->label .= ' (cloned)';
    $wechat_request->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $wechat_request->label,
    '#description' => t('The human-readable name of this message type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($wechat_request->type) ? $wechat_request->type : '',
    '#maxlength' => 32,
    '#disabled' => $wechat_request->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'wechat_request_get_types',
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
    '#default_value' => $wechat_request->weight,
    '#description' => t('When showing message types, those with lighter (smaller) weights get listed before message types with heavier (larger) weights.'),
    '#weight' => 10,
  );

  if (!$wechat_request->isLocked() && $op != 'add' && $op != 'clone') {
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

function wechat_request_type_form_submit(&$form, &$form_state) {
  $wechat_request_type = entity_ui_form_submit_build_entity($form, $form_state);
  $wechat_request_type->save();
  $form_state['redirect'] = 'admin/structure/wechat_request';
}



