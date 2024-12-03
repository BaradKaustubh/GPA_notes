<?php
$numbers = array("one" => 1, "two" => 2, "three" => 3);
echo "numbers array: ";
print_r($numbers);
echo "<br>";

$numbers["four"] = 4;
unset($numbers["two"]);
$numbers["five"] = 5;

foreach ($numbers as $key => $value) {
    echo "$key: $value <br>";
}

$num = array("one" => 1, "two" => 2, "three" => 3, "four" => 4, "five" => 5);
echo "num array: ";
print_r($num);
echo "<br>";

if (array_key_exists("one", $num)) {
    echo "The key one exists in the array <br>";
}

$array1 = array("one" => 1, "two" => 2, "three" => 3);
echo "array1: ";
print_r($array1);
echo "<br>";

$array2 = array_keys($array1);
echo "array2: ";
print_r($array2);
echo "<br>";

$array3 = array("one" => 1, "two" => 2, "three" => 3);
echo "array3: ";
print_r($array3);
echo "<br>";

$array4 = array_values($array3);
echo "array4: ";
print_r($array4);
echo "<br>";

$array5 = array("one" => 1, "two" => 2, "three" => 3);
echo "array5: ";
print_r($array5);
echo "<br>";

$array6 = array("four" => 4, "five" => 5, "six" => 6);
echo "array6: ";
print_r($array6);
echo "<br>";

$array7 = array_merge($array5, $array6);
echo "array7: ";
print_r($array7);
echo "<br>";

$array8 = array("one" => 1, "two" => 2, "three" => 3);
echo "array8: ";
print_r($array8);
echo "<br>";

$array9 = array("four" => 4, "five" => 5, "six" => 6);
echo "array9: ";
print_r($array9);
echo "<br>";

$array10 = array_intersect_key($array8, $array9);
echo "array10: ";
print_r($array10);
echo "<br>";

$array11 = array("one" => 1, "two" => 2, "three" => 3);
echo "array11: ";
print_r($array11);
echo "<br>";

$array12 = array("four" => 4, "five" => 5, "six" => 6);
echo "array12: ";
print_r($array12);
echo "<br>";

$array13 = array_combine($array11, $array12);
echo "array13: ";
print_r($array13);
echo "<br>";

$array14 = array("one" => 1, "two" => 2, "three" => 3);
echo "array14: ";
print_r($array14);
echo "<br>";

$array15 = array_flip($array14);
echo "array15: ";
print_r($array15);
echo "<br>";

$array16 = array("one" => 1, "two" => 2, "three" => 3);
echo "array16: ";
print_r($array16);
echo "<br>";

$array17 = array_change_key_case($array16, CASE_UPPER);
echo "array17: ";
print_r($array17);
echo "<br>";

$array18 = array("one" => 1, "two" => 2, "three" => 3);
echo "array18: ";
print_r($array18);
echo "<br>";

$array19 = array_sum($array18);
echo "array19 (sum): $array19<br>";

$array20 = array("one" => 1, "two" => 2, "three" => 3);
echo "array20: ";
print_r($array20);
echo "<br>";

$array21 = array_search(2, $array20);
echo "array21 (search result): $array21<br>";
?>
