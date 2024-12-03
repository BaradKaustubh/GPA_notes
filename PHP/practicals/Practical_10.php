<?php
$string = "Hello World";
$length = strlen($string);
echo "The length of the string is: $length";
echo "<br>";

$string1 = "Hello World";
$length1 = 0;
for ($i = 0; $i < strlen($string); $i++) {
    $length1++;
}
echo "The length of the string is: $length1";
?>