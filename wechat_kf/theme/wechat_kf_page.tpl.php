<div id="wechat_kf" class="clearfix">
  <?php foreach ($uid_list as $uid): ?>
    <?php
    echo theme('wechat_kf_item', array('uid' => $uid));
    ?>
  <?php endforeach; ?>
</div>
