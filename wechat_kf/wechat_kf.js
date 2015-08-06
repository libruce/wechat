(function ($) {
    Drupal.behaviors.wechatKfChat = {
        attach: function (context) {
            //$("div.message.chat form").(function (e) {
            //    //alert('aaa');
            //});
        }
    };
    Drupal.behaviors.RefreshChatLog = {
        attach: function () {
            $(document).ready(function () {
                //alert('asdfsadf');
            });
            //$('body').click
        }
    }
    function refresh() {
        var $wrapper = null;
        Drupal.ajax = Drupal.ajax({
            url: "/wechat_kf/chat_log",
            async: true,
            dataType: 'JSONP',
            success: function () {
                $(".content .message.chat.log").html(htmlobj.responseText)
            },
            failure: function (result) {
                alert('Failed');
            },
            data: {
                'op': 'open'
            }
        });

    }

    Drupal.ajax = Drupal.ajax || {};
    Drupal.ajax.prototype.wechat_kf_ajax = function (ajax, response, status) {
        alert(response);
        //$wrapper = $wrapper || $('#' + response['form-id']).parents('.view.view-commerce-cart-form:eq(0)').parent();
        //
        //$wrapper
        //    .find('div.messages').remove().end()
        //    .prepend(response['message']);
        //
        //if (response.output != '') {
        //    $wrapper.find('#dc-cart-ajax-form-wrapper').html(response.output);
        //    return;
        //}
        //
        //var fake_link = '#dc-cart-ajax-' + response['form-id'];
        //$(fake_link).trigger('click');
    };
    function refresh111() {

        htmlobj = $.ajax({
            url: "/wechat_kf/chat_log",
            async: true,
            dataType: 'JSONP',
            success: function () {
                $(".content .message.chat.log").html(htmlobj.responseText)
            },
            failure: function (result) {
                alert('Failed');
            },
            data: {
                'op': 'open'
            }
        });

    }

    function refreshClick() {
        $('#edit-b4e768f2eadf6d90291356cffcc9c5d36a5f0617-actions-chat-log-refresh').trigger("ajax");
        //alert('asdfa');
    }

    //$(document).ready(function () {
    //    setInterval(refreshClick, 5000)
    //    //alert('asdfsadf');
    //});
    setTimeout(function () {
        refreshClick();
    }, 500);
})(jQuery);
