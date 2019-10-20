package io.github.ohgree.cs2019hw2.level013;

import org.jetbrains.annotations.NotNull;

interface Shape {
    double area();
}
class Rectangle implements Shape {
    private double width, height;
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    @Override
    public double area() {
        return this.width * this.height;
    }
}
class Square extends Rectangle {
    public Square(double width) {
        super(width, width);
    }
}
class Circle implements Shape {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double area() {
        return radius * radius * Math.PI;
    }
}
public class Level013 {
    public static void main(String args[]) {
        Shape[] arr = {
                new Circle(5.0),
                new Square(4.0),
                new Rectangle(3.0, 4.0),
                new Square(5.0)
        };
        System.out.println("Total area of the shapes is: " + sumArea(arr));
    }
    static double sumArea(Shape[] shapeArray) {
        double sum = 0;
        for(Shape s: shapeArray) {
            sum += s.area();
        }
        return sum;
    }
}