(function ($) {
    Drupal.behaviors.checkStatus = {
        attach: function () {
            jQuery.post(Drupal.settings.userbind.statusUrl, {"uid": Drupal.settings.userbind.uid}, function (data) {
                console.log(data);
                Drupal.behaviors.checkStatus.attach();
                //console.log('test');
            });
        }
    };
})(jQuery);