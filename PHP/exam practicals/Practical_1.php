<?php
$a = 10;
$b = 5;
echo "a + b = " . ($a + $b) . "<br>";
echo "a - b = " . ($a - $b) . "<br>"; 
echo "a * b = " . ($a * $b) . "<br>";
echo "a / b = " . ($a / $b) . "<br>";
echo "a % b = " . ($a % $b) . "<br>";

$c = 10;
$d = 5;
$c += $d;
echo "c += d = " . $c . "<br>";
$c -= $d;
echo "c -= d = " . $c . "<br>";

$e = 10;
$f = 5;
if ($e == $f) {
    echo "e equals f";
} else {
    echo "e not equals f";
}

$g = 10;
$h = 5;
$i = 15;
if ($g > $h && $g < $i) {
    echo "g is between h and i";
}

$str1 = "Hello";
$str2 = "World";
echo $str1 . " " . $str2;

$num = 10;
echo ++$num . "<br>";
echo --$num . "<br>";
echo $num++ . "<br>";
echo $num-- . "<br>";
?>
