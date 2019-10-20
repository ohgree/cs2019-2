package io.github.ohgree.cs2019hw2.level015;

class Points {
    private double[] point;

    public Points(double[] point) {
        this.point = point;
    }

    public double getSum() {
        double sum = 0;
        for(double d: this.point)
            sum += d;
        return sum;
    }

    @Override
    public String toString() {
        return "[sum of points: " + this.getSum() + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Points))
            return false;

        Points pts = (Points)obj;
        return this.getSum() == pts.getSum();
    }
}

public class Level015 {
    public static void main(String[] args) {
        Points p1 = new Points(new double[]{1.0, 2.0, 3.0});
        Points p2 = new Points(new double[]{4.0, 5.0, 6.0});
        System.out.println(p1);
        System.out.println(p2);
        System.out.println(p1.equals(p2));
        Points p3 = new Points(new double[]{1.0, 4.0, 7.0});
        Points p4 = new Points(new double[]{3.0, 9.0});
        System.out.println(p3);
        System.out.println(p4);
        System.out.println(p3.equals(p4));
        Points p5 = new Points(new double[]{1.0, 2.0});
        Points p6 = null;
        System.out.println(p5);
        System.out.println(p6);
        System.out.println(p5.equals(p6));
    }
}
