package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.List;

/**
 * @author jiankuan
 * @date 12/13/14
 */
public class SpiralOrder {

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length;
        if (m == 0) return res;
        int n = matrix[0].length;
        if (n == 0) return res;
        int x = 0;
        int y = -1;
        while (true) {
            for (int i = 0; i < n; i++) {
                res.add(matrix[x][++y]);
            };
            if (--m == 0) break;

            for (int i = 0; i < m; i++) {
                res.add(matrix[++x][y]);
            };
            if (--n == 0) break;

            for (int i = 0; i < n; i++) {
                res.add(matrix[x][--y]);
            };
            if (--m == 0) break;

            for (int i = 0; i < m; i++) {
                res.add(matrix[--x][y]);
            };
            if (--n == 0) break;
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] arr = new int[1][3];
        arr[0][0] = 7;
        arr[0][1] = 6;
        arr[0][2] = 9;
        SpiralOrder spiralOrder = new SpiralOrder();
        List<Integer> res = spiralOrder.spiralOrder(arr);
        for (int num: res) {
            System.out.println(num);
        }

    }
}
