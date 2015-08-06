<?php
/**
 * 注释说明。
 * 客服系统聊天块
 * 包含所有会话
 */
?>
<?php
echo time();
?>
<?php
global $user;
$kf_uid = 1;
?>
<?php $session_list = wechat_kf_chat_get_kf_session($kf_uid); ?>
<?php foreach ($session_list as $user_openid => $session): ?>
  <?php echo theme('wechat_kf_chat_session', array(
    'user_openid' => $user_openid,
    'kf_uid' => $kf_uid
  )); ?>
<?php endforeach; ?>
