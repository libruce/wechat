<?php
/**
 * @file
 * wechat_user.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function wechat_user_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_wechat_group_id'
  $field_bases['field_wechat_group_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wechat_group_id',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
