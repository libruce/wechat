二维码生成模版
<?php

//用户只能访问自己的微信绑定。


$output = "";

$output .= '<p>' . t('使用微信，扫一扫下面的二维码，即可绑定微信账号.') . '</p>';
$img_src = '';

$we_obj = wechat_api_init_wechatobj();
//由于我们使用的wechat SDK，目前没有setAccessToken($access_token)，所以我们这里只能委屈一下了。

//我们使用当前用户的uid作为scene_id，这样用户扫描后，我们收到消息，可以通过scene_id，获取到当前的uid。
$ticket_array = $we_obj->getQRCode($user->uid);
if (!empty($ticket_array['ticket'])) {
  $img_src = $we_obj->getQRUrl($ticket_array['ticket']);
  $output .= '<p><img src="' . $img_src . '" /></p>';

}

echo $output;
?>