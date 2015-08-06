<?php
//$user_openid
//$kf_uid
?>

<?php $chat_log = wechat_kf_get_chat_log($user_openid, $kf_uid); ?>
<!--<pre>-->
<?php
//print_r($chat_log);
//?>
<!--</pre>-->
<ul class="chat_log_list clearfix">
  <?php foreach ($chat_log as $openid => $chat_info): ?>
    <?php //$chat_info = (object) $chat_info; ?>
    <div class="chat_log_item <?php echo $chat_info->who_to_who; ?>">

      <?php
      //dpm($chat_info);
      $massage = '';
      $view = '';
      if ($chat_info->who_to_who == 'user_to_kf') {
        $massage = wechat_kf_received_load($chat_info->received_id);
        $view = $massage->view();
      }
      elseif ($chat_info->who_to_who == 'kf_to_user') {
        $massage = wechat_kf_send_load($chat_info->send_id);
        $view = entity_view('wechat_kf_send', array($massage));
      }
      ?>
      <?php echo render($view); ?>

    </div>
  <?php endforeach; ?>
</ul>