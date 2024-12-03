<?php
$numbers = [
    [1, 2, 3],
    [4, 5, 10],
    [7, 8, 9]
];

foreach ($numbers as $row) {
    foreach ($row as $number) {
        echo "$number ";
    }
    echo "<br>";
}

$grades = [
    ["Maths" => 90, "Science" => 85, "English" => 95],
    ["Maths" => 80, "Science" => 75, "English" => 85], 
    ["Maths" => 70, "Science" => 65, "English" => 75]
];

foreach ($grades as $student) {
    foreach ($student as $subject => $grade) {
        echo "Grade in $subject: $grade <br>";
    }
    echo "<br>";
}
?>