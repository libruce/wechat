<?php
/**
 * @file
 * user_bind.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function user_bind_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'wechat_qr2-user_bind_qr-user_bind_user_referenced'
  $field_instances['wechat_qr2-user_bind_qr-user_bind_user_referenced'] = array(
    'bundle' => 'user_bind_qr',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'wechat_qr2',
    'field_name' => 'user_bind_user_referenced',
    'label' => 'user',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('user');

  return $field_instances;
}
