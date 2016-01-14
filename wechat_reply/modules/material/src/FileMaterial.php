<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 15:18
 */

namespace Drupal\wechat_reply_material;

/**
 * Class FileMaterial
 * @package Drupal\wechat_reply_material
 * 文件素材
 */
class FileMaterial {
  //素材存储在Drupal的fid
  public $fid;

  public $media_id;
  public $name;
  public $update_time;
  public $url;

  public $save;

  function __construct(FileMaterialSaveInterface $fileMaterialSaveInterface) {
    // TODO: Implement __construct() method.
    $this->save = $fileMaterialSaveInterface;
    return $this;
  }

  function save() {
    return $this->save->save($this);
  }
}