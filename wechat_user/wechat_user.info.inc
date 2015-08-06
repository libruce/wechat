<?php

class WechatUserMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info['wechat_user']['properties'];

    $properties['uid'] = array(
      'type' => 'integer',
      'label' => t('Drupal user ID'),
      'description' => t('The user ID of drupal user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'uid',
      'required' => TRUE,
    );

    $properties['openid'] = array(
      'type' => 'text',
      'label' => t('Open id'),
      'description' => t('Openid of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'openid',
      'required' => TRUE,
    );

    $properties['subscribe'] = array(
      'label' => t('subscribe'),
      'description' => t('subscribe status of wechat user.'),
      'type' => 'integer',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'subscribe',
    );

    $properties['nickname'] = array(
      'type' => 'text',
      'label' => t('nickname'),
      'description' => t('nickname of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'nickname',
    );

    $properties['sex'] = array(
      'label' => t('sex'),
      'description' => t('sex of wechat user.'),
      'type' => 'token',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'options list' => 'wechat_wechatuser_sex_options_list',
      'schema field' => 'sex',
    );

    $properties['province'] = array(
      'type' => 'text',
      'label' => t('province'),
      'description' => t('province of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'province',
    );

    $properties['city'] = array(
      'type' => 'text',
      'label' => t('city'),
      'description' => t('city of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'city',
    );

    $properties['country'] = array(
      'type' => 'text',
      'label' => t('country'),
      'description' => t('country of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'country',
    );

    $properties['headimgurl'] = array(
      'type' => 'text',
      'label' => t('headimgurl'),
      'description' => t('headimgurl of wechat user.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'headimgurl',
    );

    $properties['subscribe_time'] = array(
      'type' => 'date',
      'label' => t('Subscribe time'),
      'description' => t('Subscribe time of wechat user.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer wechat user',
      'schema field' => 'subscribe_time',
      'required' => TRUE,
    );

    return $info;
  }
}