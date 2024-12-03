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
    <title>Login Form</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <?php
        if (isset($_POST["login"]) && isset($_POST["email"]) && isset($_POST["password"])) {
            $email = filter_var($_POST["email"], FILTER_SANITIZE_EMAIL);
            $password = trim($_POST["password"]);

            if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
                echo "<div class='alert alert-danger'>Please enter a valid email address</div>";
            } else {
                require_once "database.php";
                if ($conn) {
                    $sql = "SELECT * FROM users WHERE email = ?";
                    $stmt = mysqli_prepare($conn, $sql);
                    if ($stmt) {
                        mysqli_stmt_bind_param($stmt, "s", $email);
                        mysqli_stmt_execute($stmt);
                        $result = mysqli_stmt_get_result($stmt);
                        
                        if ($result && mysqli_num_rows($result) > 0) {
                            $user = mysqli_fetch_array($result, MYSQLI_ASSOC);
                            if (password_verify($password, $user["password"])) {
                                session_regenerate_id(true);
                                $_SESSION["user"] = $user["id"];
                                $_SESSION["user_email"] = $user["email"];
                                $_SESSION["user_name"] = $user["full_name"];
                                header("Location: index.php");
                                exit();
                            } else {
                                echo "<div class='alert alert-danger'>Invalid email or password</div>";
                            }
                        } else {
                            echo "<div class='alert alert-danger'>Invalid email or password</div>";
                        }
                        mysqli_stmt_close($stmt);
                    } else {
                        echo "<div class='alert alert-danger'>Database error. Please try again later.</div>";
                    }
                    mysqli_close($conn);
                } else {
                    echo "<div class='alert alert-danger'>Database connection failed</div>";
                }
            }
        }
        ?>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post" autocomplete="off">
            <div class="form-group">
                <input type="email" placeholder="Enter Email:" name="email" class="form-control" required pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,}$">
            </div>
            <div class="form-group">
                <input type="password" placeholder="Enter Password:" name="password" class="form-control" required minlength="8">
            </div>
            <div class="form-btn">
                <input type="submit" value="Login" name="login" class="btn btn-primary">
            </div>
        </form>
        <div><p>Not registered yet? <a href="registration.php">Register Here</a></p></div>
    </div>
</body>
</html>