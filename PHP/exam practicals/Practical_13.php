<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    echo "<h2>Selected Options:</h2>";
    echo "Fruit: {$_POST['fruit']}<br>";
    echo "Color: {$_POST['color']}<br>";
}
?>
<!DOCTYPE html>
<html>
<head><title>Form</title></head>
<body>
<form method="post">
    <select name="fruit">
        <option>Apple</option>
        <option>Banana</option>
        <option>Cherry</option>
    </select><br><br>
    <select name="color">
        <option>Red</option>
        <option>Green</option>
        <option>Blue</option>
    </select><br><br>
    <input type="submit">
</form>
</body>
</html>