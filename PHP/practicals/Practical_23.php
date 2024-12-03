<?php
$cookie_name = "username";
$cookie_value = "computer engineering";
$cookie_expiry = time() + 3600;

setcookie($cookie_name, $cookie_value, $cookie_expiry);
echo "Cookie '$cookie_name' has been set.<br>";

if (isset($_COOKIE[$cookie_name])) {
    echo "Cookie value: " . htmlspecialchars($_COOKIE[$cookie_name]) . "<br>";
}

if (isset($_GET['delete'])) {
    setcookie($cookie_name, '', time() - 3600, '/');
    unset($_COOKIE[$cookie_name]);
    echo "Cookie deleted.<br>";
} else {
    echo "<a href='?delete=1'>Delete Cookie</a><br>";
}
?>