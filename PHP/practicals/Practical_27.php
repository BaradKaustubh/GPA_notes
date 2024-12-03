<?php
$conn = mysqli_connect("localhost", "root", "", "practical_25");

if($_GET['del']) mysqli_query($conn, "DELETE FROM users WHERE id=$_GET[del]");
if($_POST['upd']) mysqli_query($conn, "UPDATE users SET name='$_POST[name]', email='$_POST[email]' WHERE id=$_POST[id]");

$data = mysqli_query($conn, "SELECT * FROM users");

$table_rows = '';
while($row = mysqli_fetch_assoc($data)) {
    $table_rows .= '<tr>
        <form method="post">
            <input type="hidden" name="id" value="'.$row['id'].'">
            <td><input type="text" name="name" value="'.$row['name'].'"></td>
            <td><input type="email" name="email" value="'.$row['email'].'"></td>
            <td><button name="upd">Update</button> <a href="?del='.$row['id'].'">Delete</a></td>
        </form>
    </tr>';
}
mysqli_close($conn);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Update/Delete Records</title>
</head>
<body>
    <table border="1">
        <?php echo $table_rows; ?>
    </table>
</body>
</html>
