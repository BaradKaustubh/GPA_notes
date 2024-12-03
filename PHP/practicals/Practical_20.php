<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Form</title>
</head>
<body>
    <form method="post">
        <input type="text" name="name" placeholder="Name"><br><br>
        <input type="text" name="email" placeholder="Email"><br><br>
        <input type="text" name="mobile" placeholder="Mobile"><br><br>
        <input type="submit" value="Submit">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = trim($_POST['name'] ?? '');
        $email = trim($_POST['email'] ?? '');
        $mobile = trim($_POST['mobile'] ?? '');
        
        $errors = [];

        if (empty($name) || !preg_match("/^[a-zA-Z ]*$/", $name)) {
            $errors[] = "Please enter a valid name";
        }

        if (empty($email) || !filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $errors[] = "Please enter a valid email";
        }

        if (empty($mobile) || !preg_match("/^[0-9]{10}$/", $mobile)) {
            $errors[] = "Please enter a valid 10-digit mobile number";
        }

        if ($errors) {
            foreach ($errors as $error) {
                echo "<p style='color: red'>$error</p>";
            }
        } else {
            echo "<p style='color: green'>Success!</p>";
            echo "<p>Name: $name</p>";
            echo "<p>Email: $email</p>";
            echo "<p>Mobile: $mobile</p>";
        }
    }
    ?>
</body>
</html>
