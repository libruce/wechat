<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 17:49
 */

namespace Drupal\wechat_reply_material;


interface NewsMaterialSaveInterface {
  function save(NewsMaterial $newsMaterial);
}