<?php
$name = "username";
$value = "computer engineering"; 
$expiry = time() + 3600;

echo setcookie($name, $value, $expiry) ? "Cookie '$name' set successfully." 
    : "Unable to set cookie '$name'.";
?>