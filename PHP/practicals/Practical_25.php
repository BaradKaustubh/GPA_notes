<?php
$conn = mysqli_connect("localhost", "root", "", "practical_25");
if ($_POST) {
    $sql = "INSERT INTO users (name, email) VALUES ('$_POST[name]', '$_POST[email]')";
    if (mysqli_query($conn, $sql)) echo "Record saved";
}
mysqli_close($conn);
?>

<!DOCTYPE html>
<html>
<head><title>Database Form</title></head>
<body>
    <form method="post">
        Name: <input type="text" name="name"><br><br>
        Email: <input type="email" name="email"><br><br>
        <input type="submit" value="Save">
    </form>
</body>
</html>