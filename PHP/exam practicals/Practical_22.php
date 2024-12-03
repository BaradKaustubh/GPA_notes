<?php unlink("sample.txt"); ?>
<!DOCTYPE html>
<html>
<head>
    <title>Delete File</title>
</head>
<body>
    <h2>File Deletion</h2>
    <?php if(file_exists("sample.txt")): ?>
        <p>File exists</p>
    <?php else: ?>
        <p>File deleted</p>
    <?php endif; ?>
</body>
</html>
