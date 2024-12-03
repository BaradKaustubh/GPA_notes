<?php

// Check if mysqli extension is loaded
if (!extension_loaded('mysqli')) {
    die("Error: MySQLi extension is not loaded. Please enable it in your PHP configuration.");
}

$hostName = "localhost";
$dbUser = "root"; 
$dbPassword = "";
$dbName = "login_register";

$conn = mysqli_connect($hostName, $dbUser, $dbPassword, $dbName);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

mysqli_set_charset($conn, "utf8mb4");
mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

if (!mysqli_ping($conn)) {
    die("Error: Lost connection to MySQL server");
}

?>