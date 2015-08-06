<?php
/**
 * @file
 * wechat_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function wechat_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'wechat_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'wechat_user';
  $view->human_name = '微信用户';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '微信用户';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = '更多';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = '应用';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = '重置';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '排序依据';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = '升序';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = '降序';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = '每页条目数';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- 全部 -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = '偏移量';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« 第一页';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ 前一页';
  $handler->display->display_options['pager']['options']['tags']['next'] = '下一页 ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = '末页 »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* 无任何结果时的行为: 全局: 文本域 */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '没有用户信息<a href="/admin/structure/wechat_user">请更新</a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* 字段: Wechat user: headimgurl */
  $handler->display->display_options['fields']['headimgurl']['id'] = 'headimgurl';
  $handler->display->display_options['fields']['headimgurl']['table'] = 'wechat_user';
  $handler->display->display_options['fields']['headimgurl']['field'] = 'headimgurl';
  $handler->display->display_options['fields']['headimgurl']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['headimgurl']['alter']['text'] = '<img width="100" heigth="100" src="[headimgurl]"/>';
  /* 字段: Wechat user: Drupal user ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'wechat_user';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* 字段: Wechat user: Open id */
  $handler->display->display_options['fields']['openid']['id'] = 'openid';
  $handler->display->display_options['fields']['openid']['table'] = 'wechat_user';
  $handler->display->display_options['fields']['openid']['field'] = 'openid';
  /* 字段: Wechat user: nickname */
  $handler->display->display_options['fields']['nickname']['id'] = 'nickname';
  $handler->display->display_options['fields']['nickname']['table'] = 'wechat_user';
  $handler->display->display_options['fields']['nickname']['field'] = 'nickname';
  /* 字段: 全局: 定制文本 */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '操作';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/people/wechat';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = '查看微信用户';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Wechat User';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['wechat_user'] = array(
    t('Master'),
    t('微信用户'),
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
    t('没有用户信息<a href="/admin/structure/wechat_user">请更新</a>'),
    t('headimgurl'),
    t('<img width="100" heigth="100" src="[headimgurl]"/>'),
    t('Drupal user ID'),
    t('.'),
    t(','),
    t('Open id'),
    t('nickname'),
    t('操作'),
    t('Page'),
  );
  $export['wechat_user'] = $view;

  return $export;
}
