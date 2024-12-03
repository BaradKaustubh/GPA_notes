<!DOCTYPE html>
<html>
<head>
    <title>Read File</title>
</head>
<body>
    <h2>File Contents</h2>
    <div style="margin: 20px;">
        <?php
        $file = "sample.txt";
        echo file_exists($file) ? "<p>" . file_get_contents($file) . "</p>" : "<p style='color: red;'>File not found!</p>";
        ?>
    </div>
</body>
</html>
