<?php
$numbers = array(1, 2, 3, 4, 5);
$numbers[0] = 10;
unset($numbers[2]); 
$numbers[] = 6;

foreach ($numbers as $number) {
    echo "The number is: $number <br>";
}

$num = array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
array_push($num, 11, 12, 13, 14, 15);
array_pop($num);
array_unshift($num, 0);
array_shift($num);

$array1 = array(1, 2, 3);
echo "Array 1: " . implode(", ", $array1) . "<br>";

$array2 = array(4, 5, 6);
echo "Array 2: " . implode(", ", $array2) . "<br>";

$array3 = array_merge($array1, $array2);
echo "Array 3 (merged): " . implode(", ", $array3) . "<br>";

$array4 = array_reverse($array3);
echo "Array 4 (reversed): " . implode(", ", $array4) . "<br>";

$array5 = array_search(3, $array4);
echo "Array 5 (search result): " . $array5 . "<br>";

$array6 = array_keys($array4);
echo "Array 6 (keys): " . implode(", ", $array6) . "<br>";

$array7 = array_values($array4);
echo "Array 7 (values): " . implode(", ", $array7) . "<br>";

$array8 = array_slice($array4, 2, 5);
echo "Array 8 (sliced): " . implode(", ", $array8) . "<br>";

$array9 = array_splice($array4, 2, 5);
echo "Array 9 (spliced): " . implode(", ", $array9) . "<br>";

$array10 = array_sum($array4);
echo "Array 10 (sum): " . $array10 . "<br>";

$array11 = array_product($array4);
echo "Array 11 (product): " . $array11 . "<br>";

$array12 = array_filter($array4, function($value) {
    return $value > 5;
});
echo "Array 12 (filtered): " . implode(", ", $array12) . "<br>";

$array13 = array_map(function($value) {
    return $value * 2;
}, $array4);
echo "Array 13 (mapped): " . implode(", ", $array13) . "<br>";
?>