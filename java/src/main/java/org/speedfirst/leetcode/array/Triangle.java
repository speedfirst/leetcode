package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author jiankuan
 * @date 12/13/14
 */
public class Triangle {
    public int minimumTotal(List<List<Integer>> triangle) {
        int h = triangle.size();
        int size = triangle.get(h - 1).size();
        assert (h == size);
        if (h == 1) {
            return triangle.get(0).get(0);
        }
        int[] sum = new int[size];
        int[] sum2 = new int[size];
        sum[0] = triangle.get(0).get(0);
        for (int i = 2; i <= h; i++) {
            sum2[0] = sum[0] + triangle.get(i - 1).get(0);
            for (int j = 1; j < i - 1; j++) {
                sum2[j] = Math.min(sum[j - 1], sum[j]) + triangle.get(i - 1).get(j);
            }
            sum2[i - 1] = triangle.get(i - 1).get(i - 1) + sum[i - 2];
            int[] tmp = sum2;
            sum2 = sum;
            sum = tmp;
        }

        int min = Integer.MAX_VALUE;
        for (int s : sum) {
            if (s < min) min = s;
        }
        return min;
    }

    public static void main(String[] args) {
        List<List<Integer>> triangle = new ArrayList<>();
        triangle.add(Arrays.asList(-1));
        triangle.add(Arrays.asList(2, 3));
        triangle.add(Arrays.asList(1, -1, -1));
        int res = new Triangle().minimumTotal(triangle);
        System.out.println(res);
    }
}
