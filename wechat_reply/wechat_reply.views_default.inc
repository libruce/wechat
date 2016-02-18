<?php
/**
 * @file
 * wechat_reply.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wechat_reply_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'reply_messages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'wechat_reply';
  $view->human_name = 'Reply Messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '微信回复消息';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = '更多';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = '应用';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重置';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '排序依据';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = '升序';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = '降序';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = '每页条目数';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- 全部 -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = '偏移量';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一页';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 前一页';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一页 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '末页 »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'msg_type' => 'msg_type',
    'create_time' => 'create_time',
    'field_reply_keyword' => 'field_reply_keyword',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'msg_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'create_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reply_keyword' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '未找到内容！';
  /* Relationship: 微信回应消息: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'wechat_reply';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['label'] = '用户';
  /* Field: 微信回应消息: 微信回应消息 ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'wechat_reply';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  /* Field: 微信回应消息: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'wechat_reply';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '标签';
  /* Field: 微信回应消息: Msg_type */
  $handler->display->display_options['fields']['msg_type']['id'] = 'msg_type';
  $handler->display->display_options['fields']['msg_type']['table'] = 'wechat_reply';
  $handler->display->display_options['fields']['msg_type']['field'] = 'msg_type';
  /* Field: 微信回应消息: Update time */
  $handler->display->display_options['fields']['update_time']['id'] = 'update_time';
  $handler->display->display_options['fields']['update_time']['table'] = 'wechat_reply';
  $handler->display->display_options['fields']['update_time']['field'] = 'update_time';
  $handler->display->display_options['fields']['update_time']['label'] = '更新时间';
  $handler->display->display_options['fields']['update_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['update_time']['second_date_format'] = 'long';
  /* Field: 微信回应消息: 关键字 */
  $handler->display->display_options['fields']['field_reply_keyword']['id'] = 'field_reply_keyword';
  $handler->display->display_options['fields']['field_reply_keyword']['table'] = 'field_data_field_reply_keyword';
  $handler->display->display_options['fields']['field_reply_keyword']['field'] = 'field_reply_keyword';
  $handler->display->display_options['fields']['field_reply_keyword']['type'] = 'text_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'BY';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '操作';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul class="links inline operations">
<li>
<a href="/reply/[id]">查看</a>
</li>
<li>
<a href="/reply/[id]/edit">编辑</a>
</li>
</ul>';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/reply';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '微信回复消息';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['reply_messages'] = array(
    t('Master'),
    t('微信回复消息'),
    t('更多'),
    t('应用'),
    t('重置'),
    t('排序依据'),
    t('升序'),
    t('降序'),
    t('每页条目数'),
    t('- 全部 -'),
    t('偏移量'),
    t('« 第一页'),
    t('‹ 前一页'),
    t('下一页 ›'),
    t('末页 »'),
    t('未找到内容！'),
    t('用户'),
    t('ID'),
    t('.'),
    t(','),
    t('标签'),
    t('Msg_type'),
    t('更新时间'),
    t('关键字'),
    t('BY'),
    t('操作'),
    t('<ul class="links inline operations">
<li>
<a href="/reply/[id]">查看</a>
</li>
<li>
<a href="/reply/[id]/edit">编辑</a>
</li>
</ul>'),
    t('Page'),
    t('more'),
  );
  $export['reply_messages'] = $view;

  return $export;
}
