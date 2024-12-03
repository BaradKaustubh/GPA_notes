<?php
rename("sample.txt", "new.txt");
?>
<!DOCTYPE html>
<html>
<head>
    <title>Rename File</title>
</head>
<body>
    <h2>File Rename</h2>
    <?php if(file_exists("new.txt")): ?>
        <p>File was successfully renamed.</p>
    <?php else: ?>
        <p>Error renaming file.</p>
    <?php endif; ?>
</body>
</html>
