<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 15:45
 */

namespace Drupal\wechat_reply_material;


class FileMaterialSave implements FileMaterialSaveInterface {
  function save(FileMaterial $fileMaterial) {
    $wo = wechat_api_init_wechatobj();
    $file_content = $wo->getForeverMedia($fileMaterial->media_id);


    $file = file_save_data($file_content, 'public://' . $fileMaterial->name);

    dpm($file);

  }
}