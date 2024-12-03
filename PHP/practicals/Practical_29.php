<?php
$file = "sample.txt";
file_put_contents($file, "Sample content");
?>
<!DOCTYPE html>
<html>
<head>
    <title>Create File</title>
</head>
<body>
    <h2>File Creation</h2>
    <?php if(file_exists($file)): ?>
        <p>File created successfully</p>
    <?php else: ?>
        <p>Error creating file</p>
    <?php endif; ?>
</body>
</html>
