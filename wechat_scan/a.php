<?php
/**
 * Created by PhpStorm.
 * User: sosyuki
 * Date: 2016/5/30
 * Time: 16:33
 */

$a = <<<php
a:1:{s:5:"event";s:21:"scan_product_callback";}
php;

$b = unserialize($a);

var_dump($b);
