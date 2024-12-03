<?php
$errors = [];
$name = $email = '';
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = trim($_POST['name']);
    $email = trim($_POST['email']);
    if (empty($name)) $errors[] = "Name is required";
    if (empty($email)) $errors[] = "Email is required";
}
?>
<!DOCTYPE html>
<html>

<head>
    <title>Simple Form</title>
</head>

<body>
    <form method="post">
        <input type="text" name="name" placeholder="Enter name"><br><br>
        <input type="email" name="email" placeholder="Enter email"><br><br>
        <button type="submit">Submit</button>
        
        <?php if (!empty($errors)): ?>
        <?php foreach($errors as $error): ?>
        <p style="color: red"><?php echo $error; ?></p>
        <?php endforeach; ?>
        <?php endif; ?>

        <?php if (empty($errors) && $_SERVER['REQUEST_METHOD'] == 'POST'): ?>
        <p>Success!</p>
        <p>Name: <?php echo htmlspecialchars($name); ?></p>
        <p>Email: <?php echo htmlspecialchars($email); ?></p>
        <?php endif; ?>

    </form>
</body>

</html>