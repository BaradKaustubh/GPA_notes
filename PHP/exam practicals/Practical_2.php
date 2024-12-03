<?php
$a = 10;
$b = 5;
if ($a > $b) {
    echo "The value of a is greater than b";
} else {
    echo "The value of b is greater than a";
}

$c = 10;
$d = 5;
if ($c > $d) {
    echo "The value of c is greater than d";
} elseif ($c < $d) {
    echo "The value of d is greater than c";
} else {
    echo "The value of c and d are equal";
}

$e = 10;
$f = 5;
if ($e > $f) {
    if ($e == $f) {
        echo "The value of e and f are equal";
    } else {
        echo "The value of e is greater than f";
    }
} else {
    echo "The value of f is greater than e";
}
?>