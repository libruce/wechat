<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 15:43
 */

namespace Drupal\wechat_reply_material;


interface FileMaterialSaveInterface {
  function save(FileMaterial $fileMaterial);
}