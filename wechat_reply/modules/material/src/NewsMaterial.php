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

  function __construct($item) {
    // TODO: Implement __construct() method.
    foreach ($item as $key => $value) {
      $this->{$key} = $value;
    }
    return $this;
  }

  private $save;

  /**
   * @param array $item
   * @todo 存储一个图文素材，参数要求。使用获取图文素材接口获取的数组
   */
  function save(NewsMaterialSaveInterface $newsMaterialSaveInterface) {
    $this->save = $newsMaterialSaveInterface;
    return $this->save->save($this);
  }
}