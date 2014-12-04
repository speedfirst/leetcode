package org.speedfirst.leetcode.not_in_oj;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by jiankuan on 12/2/14.
 */
class Point {
    int x, y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Point)) {
            return false;
        }
        Point that = (Point)obj;
        return (that.x == this.x && that.y == this.y);
    }

    @Override
    public int hashCode () {
        return 31*x + y;
    }
}

public class GeometricMedian {
    public Point findMin(Point[] points) {
        Map<Point, Integer> map = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            map.put(points[i], 0);
        }

        Arrays.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                if (p1.x > p2.x)
                    return 1;
                if (p1.x < p2.x)
                    return -1;
                return 0;
            }
        });
        int [] disXToLeftPoints = new int [points.length];
        //find distance from the left
        disXToLeftPoints[0] = 0;
        for (int i = 1; i < disXToLeftPoints.length; i++) {
            disXToLeftPoints[i] = i * (points[i].x - points[i - 1].x) + disXToLeftPoints[i-1];
        }
        //find distance from the right
        int [] disXToRightPoints = new int [points.length];
        disXToRightPoints[points.length - 1] = 0;
        for (int i = disXToRightPoints.length - 2; i >= 0; i--) {
            disXToRightPoints[i] = (points.length - i - 1) * (points[i + 1].x - points[i].x) + disXToRightPoints[i + 1];
        }

        // For points[i], cal the its total distances to all other points in x axis
        for (int i = 0; i < points.length; i++) {
            map.put(points[i], disXToLeftPoints[i] + disXToRightPoints[i]);
        }

        //do the same for y
        Arrays.sort(points, new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                if (p1.y > p2.y)
                    return 1;
                if (p1.y < p2.y)
                    return -1;
                return 0;
            }
        });
        int[] disYToBelowPoints = new int[points.length];
        //find distance from the bottom
        disYToBelowPoints[0] = 0;
        for (int i = 1; i < disYToBelowPoints.length; i++) {
            disYToBelowPoints[i] = i * (points[i].y - points[i - 1].y) + disYToBelowPoints[i - 1];
        }

        //find distance from the right
        int[] disYToUpperPoints = new int[points.length];
        disYToUpperPoints[points.length - 1] = 0;
        for (int i = disYToUpperPoints.length - 2; i >= 0; i--) {
            disYToUpperPoints[i] = (points.length - i - 1) * (points[i + 1].y - points[i].y) + disYToUpperPoints[i + 1];
        }

        // For points[i], cal the its total distances to all other points in y axis
        for (int i = 0; i < points.length; i++) {
            map.put(points[i], map.get(points[i]) + disYToBelowPoints[i] + disYToUpperPoints[i]);
        }

        //calculate the 2d distance by adding x and y
        Point min = null;
        int minDis = Integer.MAX_VALUE;
        for (int i = 0; i < points.length; i++) {
            int dis = map.get(points[i]);
            System.out.println(String.format("Total distance from (%d, %d) is %d", points[i].x, points[i].y, dis));
            if (map.get(points[i]) < minDis) {
                minDis = dis;
                min = points[i];
            }
        }
        System.out.println(String.format("min point is (%d, %d)", min.x, min.y));
        return min;
    }

    public static void main(String[] args) {
        Point p1 = new Point(0, 6);
        Point p2 = new Point(1, 3);
        Point p3 = new Point(3, 5);
        Point p4 = new Point(3, 3);
        Point p5 = new Point(4, 7);
        Point p6 = new Point(2, 4);
        Point[] points = new Point[]{p1, p2, p3, p4, p5, p6};

        // brute force, calculate manhattan distances and Euclidean distance
        for (int i = 0; i < points.length; i++) {
            int manhattanDis = 0;
            double euclideanDis = 0;
            for (int j = 0; j < points.length; j++) {
                manhattanDis += (Math.abs(points[i].x - points[j].x) + Math.abs(points[i].y - points[j].y));
                euclideanDis += Math.sqrt(Math.pow(points[i].x - points[j].x, 2) + Math.pow(points[i].y - points[j].y, 2));
            }
            System.out.println(String.format("Total distance for point (%d, %d) is Manhattan: %d, Euclidean: %f", points[i].x, points[i].y, manhattanDis, euclideanDis));
        }
        System.out.println("=============================================");
        GeometricMedian sol = new GeometricMedian();
        Point p = sol.findMin(points);
        System.out.println(String.format("(%d, %d)", p.x, p.y));
    }
}