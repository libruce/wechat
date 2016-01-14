<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 14:45
 */

namespace Drupal\wechat_reply_material;


class NewsMaterial {
  //
  public $media_id;
  //
  public $content;
  //这篇图文消息素材的最后更新时间
  public $update_time;

  /**
   * @param array $item
   * @todo 存储一个图文素材，参数要求。使用获取图文素材接口获取的数组
   */
  static function save(array $item) {
    $NewsMaterial = new static();
    $NewsMaterial->content = $item['content'];
    $NewsMaterial->media_id = $item['media_id'];
    $NewsMaterial->update_time = $item['update_time'];
  }
}