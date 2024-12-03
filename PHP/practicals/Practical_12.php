<?php
$str = "  Hello World! PHP is awesome.   ";

echo "Length of the string: " . strlen($str) . "\n";

$trimmed = trim($str);
echo "String after trim: '$trimmed'\n";

echo "Lowercase string: " . strtolower($str) . "\n";

echo "Uppercase string: " . strtoupper($str) . "\n";

echo "Capitalized string: " . ucwords($str) . "\n";

$pos = strpos($str, "PHP");
if ($pos !== false) {
    echo "'PHP' found at position: $pos\n";
}

echo "Substring: " . substr($str, 7, 5) . "\n";

echo "Replaced string: " . str_replace("awesome", "great", $str) . "\n";

$arr = explode(" ", $trimmed);
echo "Exploded array: ";
print_r($arr);

echo "Imploded string: " . implode("-", $arr) . "\n";
?>
