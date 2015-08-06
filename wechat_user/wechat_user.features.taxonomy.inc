<?php
/**
 * @file
 * wechat_user.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function wechat_user_taxonomy_default_vocabularies() {
  return array(
    'wechat_user_group' => array(
      'name' => 'wechat_user_group',
      'machine_name' => 'wechat_user_group',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
