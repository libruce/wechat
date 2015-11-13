<?php
$qr = new WechatQr2();
$qr->bundle = 'user_bind_qr';
$qr->qr_type = '0';
$qr->qr_key = user_bind_get_key();
$qr->uid = $user->uid;
$qr->expire = '300';
//$qr->save();
?>
