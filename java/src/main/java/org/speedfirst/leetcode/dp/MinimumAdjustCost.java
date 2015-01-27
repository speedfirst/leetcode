package org.speedfirst.leetcode.dp;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by jiankuan on 1/27/15.
 */
public class MinimumAdjustCost {

    private int lower(int val, int target) {
        return Math.max(1, val - target);
    }

    private int upper(int val, int target) {
        return Math.min(100, val + target);
    }

    public int MinAdjustmentCost(ArrayList<Integer> A, int target) {
        int[][] dp = new int[A.size()][100 + 1];
        dp[0][0] = Integer.MAX_VALUE;
        for (int v = 1; v <= 100; v++) {
            dp[0][v] = Math.abs(v - A.get(0));
        }

        for (int i = 1; i < A.size(); i++) {
            for (int v = 1; v <= 100; v++) {
                int minCost = Integer.MAX_VALUE;
                for (int midV = Math.max(1, v - target); midV <= Math.min(100, v + target); midV++) {
                    if (dp[i - 1][midV] == Integer.MAX_VALUE) {
                        continue;
                    }
                    minCost = Math.min(minCost, dp[i - 1][midV] + Math.abs(A.get(i) - v));
                }
                dp[i][v] = minCost;
            }
        }

        int minCost = Integer.MAX_VALUE;
        for (int v = 1; v <= 100; v++) {
            minCost = Math.min(minCost, dp[A.size() - 1][v]);
        }

        return minCost;
    }

    public static void main(String[] args) {
        MinimumAdjustCost sol = new MinimumAdjustCost();
        ArrayList<Integer> A = new ArrayList<>( Arrays.asList(12,3,7,4,5,13,2,8,4,7,6,5,7));
        int res = sol.MinAdjustmentCost(A, 2);
        System.out.println(res);
    }
}
