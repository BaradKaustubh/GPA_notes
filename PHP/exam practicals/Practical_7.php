<?php
function factorial($n) {
    return ($n <= 1) ? 1 : $n * factorial($n - 1);
}
$number = 5;
echo "Factorial of $number is: " . factorial($number);
?>
