<?php
$conn = mysqli_connect("localhost", "root", "", "practical_25");
$result = mysqli_query($conn, "SELECT * FROM users");

$table_rows = '';
while($row = mysqli_fetch_array($result)) {
    $table_rows .= "<tr><td>{$row['name']}</td><td>{$row['email']}</td></tr>";
}
mysqli_close($conn);
?>
<!DOCTYPE html>
<html>
<head><title>Records</title></head>
<body>
<table border='1'>
<tr><th>Name</th><th>Email</th></tr>
<?php echo $table_rows; ?>
</table>
</body>
</html>
