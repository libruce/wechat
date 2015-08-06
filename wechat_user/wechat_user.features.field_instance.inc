<?php
/**
 * @file
 * wechat_user.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function wechat_user_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-wechat_user_group-field_wechat_group_id'
  $field_instances['taxonomy_term-wechat_user_group-field_wechat_group_id'] = array(
    'bundle' => 'wechat_user_group',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_wechat_group_id',
    'label' => 'wechat_group_id',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('wechat_group_id');

  return $field_instances;
}
