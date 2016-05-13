<?php

function wechat_scan_product_form($form, &$form_state, WechatScanProduct $product, $op) {
  $form_state['WechatScanProduct'] = $product;

  $form['title'] = array(
    '#title' => t('产品标题'),
    '#type' => 'textfield',
    '#default_value' => $product->title,
    '#size' => 30,
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('保存'),
  );

  if (!empty($product->id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('删除'),
      '#submit' => array('wechat_reply_form_submit_delete')
    );
  }
  return $form;
}

function wechat_scan_product_form_submit($form, &$form_state) {
  $entity = $form_state['WechatScanProduct'];
  entity_form_submit_build_entity('wechat_scan_product', $entity, $form, $form_state);

  $entity->save();
  dpm($entity);
  dpm($form_state);


}