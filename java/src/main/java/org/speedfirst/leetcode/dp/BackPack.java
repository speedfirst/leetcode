package org.speedfirst.leetcode.dp;

import java.util.Arrays;

/**
 * Created by jiankuan on 1/20/15.
 */
public class BackPack {

    // dp solution, time complexity O(A.length * m), space complexity originally should be O(A.length * m) but
    // reach O(m) after optimization
    public int backpack(int m, int[] A) {
        if (A.length == 0) {
            return 0;
        }

        int[][] dp = new int[2][m + 1];
        for (int i = 0; i < 2; i++) {
            Arrays.fill(dp[i], 0);
        }

        int prevIdx = 0, curIdx = 1;
        for (int i = 1; i <= A.length; i++) {
            for (int w = 1; w <= m; w++) {
                if (A[i - 1] > w) {
                    dp[curIdx][w] = dp[prevIdx][w];
                } else {
                    dp[curIdx][w] = Math.max(dp[prevIdx][w], A[i - 1] + dp[prevIdx][w - A[i - 1]]);
                }
            }

            // swap curIdx and prevIdx
            prevIdx = prevIdx ^ curIdx;
            curIdx = prevIdx ^ curIdx;
            prevIdx = prevIdx ^ curIdx;
        }

        return dp[prevIdx][m];
    }

    public static void main(String[] args) {
        int[] A = {3, 4, 8, 5};
        int res2 = new BackPack().backpack(10, A);
        System.out.println(res2);
    }
}
