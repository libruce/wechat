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

//var_dump($b);


$a = '6901382';
$b = '69013821631';
$keystr = $b;
$c = strncmp($a, $b, 7);
$d = is_numeric($keystr);
var_dump($d);

$e = strlen($b);
var_dump($e);