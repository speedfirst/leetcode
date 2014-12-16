package org.speedfirst.leetcode.dp;

import java.util.Arrays;

/**
 * @author jiankuan
 * @date 12/16/14
 */
public class PalindromePartition2 {
    public int minCut(String s) {

        // first dp, find all the polindromes
        boolean[][] p = new boolean[s.length()][s.length()];

        for (int len = 1; len <= s.length(); len++) {
            for (int i = 0; i < s.length() - len + 1; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j) && (j - i < 2 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                } else {
                    p[i][j] = false;
                }
            }
        }

        // second dp, find the minimum cut
        // string: X X X X X X X X X X X X X
        //             ^       ^
        //             j       i
        // dp[j] is the minimum cut of s[0 .. j - 1]. If s[j .. i - 1] is a palindrome, then dp[i] = dp[j] + 1
        // we iterate j from 0 to i - 1 to find the minimum dp[i]
        int[] dp = new int[s.length() + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = -1; // hope dp[1] = 0;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                // here is a little tricky. In the first dp, the i and j in p[i][j] are "idx" starts with 0
                // For dp[i], i is the ith character of string, which starts with 1
                // so here, p[j][i - 1] is actually p[(j + 1) - 1][(i) - 1]. Note we just minus 1 for i and j
                if (p[j][i - 1]) {
                    dp[i] = Math.min(dp[j] + 1, dp[i]);
                }
            }
        }

        return dp[s.length()];
    }

}
