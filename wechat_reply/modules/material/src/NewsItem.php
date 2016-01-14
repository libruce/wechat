<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/1/14
 * Time: 14:51
 */

namespace Drupal\wechat_reply_material;


use Drupal\wechat_replay_material\NewsItemSaveInterface;

class NewsItem {
  //标题
  public $title;
  //作者
  public $author;

  //图文消息的封面图片素材id（必须是永久mediaID）
  public $thumb_media_id;
  //图文消息的封面图片的地址，第三方开发者也可以使用这个URL下载图片到自己服务器中，然后显示在自己网站上
  public $thumb_url;
  //是否显示封面，0为false，即不显示，1为true，即显示
  public $show_cover_pic;

  //图文消息的摘要，仅有单图文消息才有摘要，多图文此处为空
  public $digest;
  //图文消息的具体内容，支持HTML标签，必须少于2万字符，小于1M，且此处会去除JS
  public $content;
  //图文消息的原文地址，即点击“阅读原文”后的URL
  public $content_source_url;
  //图文页的URL
  public $url;

  function __construct(array $news_item) {
    // TODO: Implement __construct() method.
    foreach ($news_item as $key => $value) {
      $this->{$key} = $value;
    }
    return $this;
  }

  function  save(NewsItemSaveInterface $newsItemSaveInterface) {
    return $newsItemSaveInterface->save($this);
  }


}