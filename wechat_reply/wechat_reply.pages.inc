<?php

function wechat_reply_add_page() {
  $types = wechat_reply_get_types();

  $item = menu_get_item();
  //dpm($item);
  $content = system_admin_menu_block($item);
  // Bypass the node/add listing if only one content type is available.
  if (count($content) == 1) {
    $item = array_shift($content);
    drupal_goto($item['href']);
  }
  return theme('wechat_reply_add_list', array('content' => $content));
}

/**
 * Returns HTML for a list of available node types for node creation.
 *
 * @param $variables
 *   An associative array containing:
 *   - content: An array of content types.
 *
 * @ingroup themeable
 */
function theme_wechat_reply_add_list($variables) {
  $content = $variables['content'];
  $output = '';
//dpm($content);
  if ($content) {
    $output = '<dl class="node-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    $output = '<p>' . t('You have not created any content types yet. Go to the <a href="@create-content">content type creation page</a> to add a new content type.', array('@create-content' => url('admin/structure/types/add'))) . '</p>';
  }

  return $output;
}


function wechat_reply_pages(WechatReply $wechatReply) {
  //dpm($wechatReply);
  $output = '';
  $entity_view = entity_view('wechat_reply', array($wechatReply));
  $output .= render($entity_view);
  return $output;
}

function wechat_reply_delete_confirm($form, &$form_state, WechatReply $wechatReply) {
  $form['#wechat_reply'] = $wechatReply;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['id'] = array('#type' => 'value', '#value' => $wechatReply->id);
  return confirm_form($form,
    //消息
    t('您确定要删除这个消息:ID:%id 标题:%title 类型:%type', array(
      '%id' => $wechatReply->id,
      '%title' => $wechatReply->title,
      '%type' => $wechatReply->msg_type
    )),
    //点取消返回地址
    'reply/' . $wechatReply->id . '/edit',
    //提示
    t('这个操作不能恢复.'),
    //按钮1
    t('删除'),
    //按钮2
    t('取消')
  );
}

function wechat_reply_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {

//    wechat_reply_delete($form['id']);
  }
  $form_state['redirect'] = 'admin/content/reply';
}