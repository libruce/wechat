<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 17:57
 */

namespace Drupal\wechat_replay_material;


use Drupal\wechat_reply_material\NewsItem;

interface NewsItemSaveInterface {
  function save(NewsItem $newsItem);
}