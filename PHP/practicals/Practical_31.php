<!DOCTYPE html>
<html>
<head>
    <title>Line Count</title>
</head>
<body>
    <h2>Number of Lines in File</h2>
    <?php
    $file = "sample.txt";
    if(file_exists($file)) {
        echo "Lines: " . count(file($file));
    } else {
        echo "File not found";
    }
    ?>
</body>
</html>
