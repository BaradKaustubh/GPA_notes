<?php
session_start();
if (isset($_SESSION["user"])) {
    header("Location: index.php");
    exit();
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Form</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <?php
        if (isset($_POST["submit"])) {
            require_once "database.php";
            
            $fullName = htmlspecialchars(trim(mysqli_real_escape_string($conn, $_POST["fullname"])));
            $email = htmlspecialchars(trim(mysqli_real_escape_string($conn, $_POST["email"])));
            $password = trim($_POST["password"]);
            $passwordRepeat = trim($_POST["repeat_password"]);
            
            $errors = array();
            
            if (empty($fullName) || empty($email) || empty($password) || empty($passwordRepeat)) {
                array_push($errors, "All fields are required");
            }
            
            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                array_push($errors, "Email is not valid");
            }
            
            if (strlen($password) < 8) {
                array_push($errors, "Password must be at least 8 characters long");
            }
            
            if (!preg_match("/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/", $password)) {
                array_push($errors, "Password must contain at least one uppercase letter, one lowercase letter, one number and one special character");
            }
            
            if ($password !== $passwordRepeat) {
                array_push($errors, "Password does not match");
            }
            
            $sql = "SELECT * FROM users WHERE email = ?";
            $stmt = mysqli_prepare($conn, $sql);
            if ($stmt) {
                mysqli_stmt_bind_param($stmt, "s", $email);
                mysqli_stmt_execute($stmt);
                $result = mysqli_stmt_get_result($stmt);
                $rowCount = mysqli_num_rows($result);
                if ($rowCount > 0) {
                    array_push($errors, "Email already exists!");
                }
                mysqli_stmt_close($stmt);
            } else {
                array_push($errors, "Database error occurred");
            }
            
            if (count($errors) > 0) {
                foreach ($errors as $error) {
                    echo "<div class='alert alert-danger'>" . htmlspecialchars($error) . "</div>";
                }
            } else {
                $passwordHash = password_hash($password, PASSWORD_BCRYPT, ['cost' => 12]);
                
                $sql = "INSERT INTO users (full_name, email, password) VALUES (?, ?, ?)";
                $stmt = mysqli_prepare($conn, $sql);
                if ($stmt) {
                    mysqli_stmt_bind_param($stmt, "sss", $fullName, $email, $passwordHash);
                    if (mysqli_stmt_execute($stmt)) {
                        echo "<div class='alert alert-success'>You are registered successfully.</div>";
                        header("refresh:2;url=login.php");
                    } else {
                        echo "<div class='alert alert-danger'>Registration failed. Please try again.</div>";
                    }
                    mysqli_stmt_close($stmt);
                } else {
                    echo "<div class='alert alert-danger'>Database error. Please try again later.</div>";
                }
            }
            mysqli_close($conn);
        }
        ?>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" autocomplete="off">
            <div class="form-group">
                <input type="text" class="form-control" name="fullname" placeholder="Full Name:" maxlength="50" pattern="[A-Za-z\s]+" title="Only letters and spaces allowed" required>
            </div>
            <div class="form-group">
                <input type="email" class="form-control" name="email" placeholder="Email:" maxlength="100" required>
            </div>
            <div class="form-group">
                <input type="password" class="form-control" name="password" placeholder="Password:" minlength="8" required>
            </div>
            <div class="form-group">
                <input type="password" class="form-control" name="repeat_password" placeholder="Repeat Password:" minlength="8" required>
            </div>
            <div class="form-btn">
                <input type="submit" class="btn btn-primary" value="Register" name="submit">
            </div>
        </form>
        <div>
            <p>Already Registered? <a href="login.php">Login Here</a></p>
        </div>
    </div>
</body>
</html>