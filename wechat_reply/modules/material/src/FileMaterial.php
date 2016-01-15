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
  //素材存储在Drupal的file
  public $file;

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

  static function  load(FileMaterialLoadInterface $fileMaterialLoadInterface, $id) {
    return $fileMaterialLoadInterface->load($id);
  }

  function save(FileMaterialSaveInterface $fileMaterialSaveInterface) {
    $this->save = $fileMaterialSaveInterface;
    $file = $this->save->save($this);
    $this->file = $file;
    $wechatReply = new \WechatReply(array('type' => 'image_material'));
    $wechatReply_wrapper = $wechatReply->wrapper();
    $wechatReply_wrapper->wechat_reply_news_image->set($file);
    $wechatReply_wrapper->wechat_reply_news_image->set($this->name);
    $wechatReply_wrapper->wechat_reply_news_image->set($this->url);
    $wechatReply_wrapper->wechat_reply_news_image->set($this->update_time);

  }
}