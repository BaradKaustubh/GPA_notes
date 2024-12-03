<?php
class Car {
    public $make;
    public $model; 
    public $year;

    public function __construct($make, $model, $year) {
        $this->make = $make;
        $this->model = $model;
        $this->year = $year;
    }

    public function displayCarDetails() {
        echo "Car Make: $this->make <br>";
        echo "Car Model: $this->model <br>";
        echo "Manufacturing Year: $this->year <br>";
    }
}

$myCar = new Car("Toyota", "Corolla", 2020);
$myCar->displayCarDetails();
?>
