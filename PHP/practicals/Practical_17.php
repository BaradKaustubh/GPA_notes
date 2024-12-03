<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    echo "<h2>Form Data:</h2>";
    echo "Name: {$_POST['name']}<br>";
    echo "Gender: {$_POST['gender']}<br>";
    echo "Subscribed: " . (isset($_POST['subscribe']) ? 'Yes' : 'No');
}
?>
<!DOCTYPE html>
<html>
<head><title>Form</title></head>
<body>
<form method="post">
    <input type="text" name="name" required placeholder="Name"><br><br>
    <select name="gender">
        <option value="male">Male</option>
        <option value="female">Female</option>
        <option value="other">Other</option>
    </select><br><br>
    <input type="checkbox" name="subscribe">Subscribe<br><br>
    <input type="submit" value="Submit">
</form>
</body>
</html>