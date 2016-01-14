<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 17:57
 */

namespace Drupal\wechat_reply_material;

interface NewsItemSaveInterface {
  function save(NewsItem $newsItem);
}