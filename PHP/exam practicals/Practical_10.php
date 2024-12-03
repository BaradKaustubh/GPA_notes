<?php
class Person {
    public $name;
    public $age;

    public function __construct($name, $age) {
        $this->name = $name;
        $this->age = $age;
    }

    public function displayPerson() {
        echo "Name: $this->name <br>";
        echo "Age: $this->age <br>";
    }
}

class Employee extends Person {
    public $salary;
    public $position;

    public function __construct($name, $age, $salary, $position) {
        parent::__construct($name, $age);
        $this->salary = $salary;
        $this->position = $position;
    }

    public function displayEmployee() {
        $this->displayPerson();
        echo "Salary: $this->salary <br>";
        echo "Position: $this->position <br>";
    }
}

$employee = new Employee("John Doe", 30, 50000, "Software Developer");
$employee->displayEmployee();
?>