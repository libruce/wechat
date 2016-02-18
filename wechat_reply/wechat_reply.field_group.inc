<?php
/**
 * @file
 * wechat_reply.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function wechat_reply_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|image|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '0',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|multiple_news|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'multiple_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '6',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|multiple_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|music|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'music';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '0',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '管理',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-admin field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_admin|wechat_reply|music|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|news|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '0',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|text|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '5',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|video|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '0',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|wechat_reply|voice|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'voice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '管理',
    'weight' => '5',
    'children' => array(
      0 => 'field_reply_keyword',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|wechat_reply|voice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|image|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'image';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '2',
    'children' => array(
      0 => 'wechat_reply_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|image|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|multiple_news|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'multiple_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '6',
    'children' => array(
      0 => 'field_news_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|multiple_news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|music|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'music';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '3',
    'children' => array(
      0 => 'wechat_reply_music',
      1 => 'wechat_reply_music_description',
      2 => 'wechat_reply_music_hq_url',
      3 => 'wechat_reply_music_title',
      4 => 'wechat_reply_music_url',
      5 => 'wechat_reply_thumb_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '消息',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_info|wechat_reply|music|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|news|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '2',
    'children' => array(
      0 => 'wechat_reply_news_description',
      1 => 'wechat_reply_news_image',
      2 => 'wechat_reply_news_title',
      3 => 'wechat_reply_news_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|text|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'text';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '5',
    'children' => array(
      0 => 'wechat_reply_content',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|text|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|video|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'video';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '1',
    'children' => array(
      0 => 'wechat_reply_thumb_media',
      1 => 'wechat_reply_video',
      2 => 'wechat_reply_video_description',
      3 => 'wechat_reply_video_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|video|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_info|wechat_reply|voice|form';
  $field_group->group_name = 'group_info';
  $field_group->entity_type = 'wechat_reply';
  $field_group->bundle = 'voice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '消息',
    'weight' => '5',
    'children' => array(
      0 => 'wechat_reply_voice',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_info|wechat_reply|voice|form'] = $field_group;

  return $export;
}
