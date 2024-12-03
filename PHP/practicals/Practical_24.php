<?php session_start(); ?>
<!DOCTYPE html>
<html>
<head>
<title>Session</title>
</head>
<body>
<?php
$_SESSION['name'] = "Kaustubh";
$_SESSION['email'] = "kaustubhbarad@gmail.com";
?>
<p>
Name: <?php echo $_SESSION['name']; ?><br>
Email: <?php echo $_SESSION['email']; ?>
</p>
<?php session_destroy(); ?>
<p>Session Destroyed</p>
</body>
</html>