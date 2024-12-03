<?php
class Rectangle {
    public $length;
    public $width;

    public function __construct($length, $width) {
        $this->length = $length;
        $this->width = $width;
    }

    public function getArea() {
        return $this->length * $this->width;
    }

    public function getPerimeter() {
        return 2 * ($this->length + $this->width);
    }
}

$rect = new Rectangle(10, 5);
echo "Area of the rectangle: " . $rect->getArea() . "<br>";
echo "Perimeter of the rectangle: " . $rect->getPerimeter() . "<br>";
?>
