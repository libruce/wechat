<?php $uid_sha = sha1($uid); ?>
<?php
$wechat_user = wechat_user_load($uid);
?>
<div id="message_<?php echo $uid_sha; ?>" class="message content chat">
  <div class="message user title">
    <img width="100" height="100" src="<?php echo $wechat_user->headimgurl; ?>">
    <?php
    echo $wechat_user->nickname;
    ?>
  </div>

  <div class="message log">
    消息记录
  </div>

  <?php
  $form = drupal_get_form('wechat_kf_chat_form', $wechat_user->openid);
  echo render($form);
  ?>
</div>
