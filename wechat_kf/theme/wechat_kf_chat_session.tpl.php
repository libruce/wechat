<?php
$user = wechat_user_get_wechat_user_by_openid($user_openid);
$wechat_uid = $user['uid'];
$wechat_user = wechat_user_load((int) $wechat_uid);
$wechat_user = (object) $wechat_user;
$wechat_uid_sha = sha1($wechat_uid);

?>

<div id="message_<?php echo $wechat_uid_sha; ?>" class="message content chat">
  <div class="message user title">
    <img width="100" height="100" src="<?php echo $wechat_user->headimgurl; ?>">
    <?php
    echo $wechat_user->nickname;
    ?>
  </div>

  <div class="message log">

  </div>


</div>
