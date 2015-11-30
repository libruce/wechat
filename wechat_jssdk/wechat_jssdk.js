/**
 * Created by sosyuki on 2015/11/30.
 */
(function ($) {
    Drupal.behaviors.wechatJSSDK = {
        attach: function () {
            Drupal.wechatJSSDK = wx || {};
            Drupal.wechatJSSDK.config({
                debug: true,
                appId: Drupal.settings.wechatJSSDK.appId,
                timestamp: Drupal.settings.wechatJSSDK.timestamp,
                nonceStr: Drupal.settings.wechatJSSDK.nonceStr,
                signature: Drupal.settings.wechatJSSDK.signature,
                jsApiList: [
                    // 所有要调用的 API 都要加到这个列表中
                    'checkJsApi',
                    'onMenuShareTimeline',
                    'onMenuShareAppMessage',
                    'onMenuShareQQ',
                    'onMenuShareWeibo',
                    'hideMenuItems',
                    'showMenuItems',
                    'hideAllNonBaseMenuItem',
                    'showAllNonBaseMenuItem',
                    'translateVoice',
                    'startRecord',
                    'stopRecord',
                    'onRecordEnd',
                    'playVoice',
                    'pauseVoice',
                    'stopVoice',
                    'uploadVoice',
                    'downloadVoice',
                    'chooseImage',
                    'previewImage',
                    'uploadImage',
                    'downloadImage',
                    'getNetworkType',
                    'openLocation',
                    'getLocation',
                    'hideOptionMenu',
                    'showOptionMenu',
                    'closeWindow',
                    'scanQRCode',
                    'chooseWXPay',
                    'openProductSpecificView',
                    'addCard',
                    'chooseCard',
                    'openCard'
                ]
            });
        }
    };
})(jQuery);
