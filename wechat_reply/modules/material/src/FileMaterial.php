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

  private $save;

  function __construct($item) {
    foreach ($item as $key => $value) {
      $this->{$key} = $value;
    }
    return $this;
  }

  function save(FileMaterialSaveInterface $fileMaterialSaveInterface) {
    $this->save = $fileMaterialSaveInterface;
    return $this->save->save($this);
  }
}