<?php
echo isset($_COOKIE['username']) ? "The value of the 'username' cookie is: " . htmlspecialchars($_COOKIE['username']) : "The 'username' cookie is not set.";
