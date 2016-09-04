<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 17:51
 */

namespace Drupal\wechat_reply_material;


class NewsMaterialSave implements NewsMaterialSaveInterface {
  function save(NewsMaterial $newsMaterial) {
    dpm($newsMaterial);
    foreach ($newsMaterial->content as $news_item) {

    }
    // TODO: Implement save() method.
  }
}