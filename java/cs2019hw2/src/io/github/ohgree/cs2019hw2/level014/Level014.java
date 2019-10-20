package io.github.ohgree.cs2019hw2.level014;

class Point {
    private double[] point;
    public Point(double[] point) {
        this.point = point;
    }
    public int getDimension() {
        return this.point.length;
    }
    public double getPositionAt(int index) {
        if(index < 0 || index >= this.getDimension()) {
            throw new ArrayIndexOutOfBoundsException("Position index is not within the dimension");
        }
        return this.point[index];
    }
}
class EuclideanDistance {
    public static double getDist(Point p1, Point p2) {
        int dimension;
        double partSum, distance;
        dimension = p1.getDimension();
        if(dimension != p2.getDimension())
            return -1;
            //throw new ArithmeticException("Two points given are in different dimensions");

        partSum = 0;
        for(int i=0 ; i<dimension ; i++) {
            partSum += Math.pow(p1.getPositionAt(i)-p2.getPositionAt(i), 2.0);
        }
        distance = Math.sqrt(partSum);
        return distance;
    }
}
class ManhattanDistance {
    public static double getDist(Point p1, Point p2) {
        int dimension;
        double distance = 0;
        dimension = p1.getDimension();
        if(dimension != p2.getDimension())
            return -1;
            //throw new ArithmeticException("Two points given are in different dimensions");

        for(int i=0 ; i<dimension ; i++)
            distance += Math.abs(p1.getPositionAt(i)-p2.getPositionAt(i));
        return distance;
    }
}
public class Level014 {
    public static void main(String[] args) {
        Point p1 = new Point(new double[]{1.0, 2.0, 3.0});
        Point p2 = new Point(new double[]{4.0, 5.0, 6.0});
        System.out.println("Euclidean Distance: " + EuclideanDistance.getDist(p1, p2));
        System.out.println("Manhattan Distance: " + ManhattanDistance.getDist(p1, p2));
        Point p3 = new Point(new double[]{1.0, 2.0, 3.0});
        Point p4 = new Point(new double[]{4.0, 5.0});
        System.out.println("Euclidean Distance: " + EuclideanDistance.getDist(p3, p4));
        System.out.println("Manhattan Distance: " + ManhattanDistance.getDist(p3, p4));
    }
}