<?php $session_list = wechat_kf_chat_get_kf_session($kf_uid); ?>
<?php foreach ($session_list as $user_openid => $session): ?>
  <?php echo theme('wechat_kf_chat_session', array(
    'user_openid' => $user_openid,
    'kf_uid' => $kf_uid
  )); ?>
<?php endforeach; ?>
