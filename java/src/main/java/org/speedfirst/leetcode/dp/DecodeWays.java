package org.speedfirst.leetcode.dp;

/**
 * @author jiankuan
 * @date 12/14/14
 */
public class DecodeWays {

    boolean isValid(String s, int start, int len) {
        if (len == 1) {
            char c = s.charAt(start);
            return c >= '1' && c <= '9';
        }

        if (len == 2) {
            char c1 = s.charAt(start);
            char c2 = s.charAt(start + 1);

            return (c1 == '1' && c2 >= '0' && c2 <= '9') || (c1 == '2' && c2 >= '0' && c2 <= '6');
        }

        return false;
    }


    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        int[] dp = new int[3];
        dp[0] = 1;

        dp[1] = isValid(s, 0, 1)? 1 : 0;
        if (s.length() == 1) return dp[1];

        for (int i = 2; i <= s.length(); i++) {
            dp[2] = 0; // NOTE IT'S VERY IMPORTANT TO RESET TO 0!
            if (dp[1] > 0 && isValid(s, i - 1, 1)) {
                dp[2] += dp[1];
            }

            if (dp[0] > 0 && isValid(s, i - 2, 2)) {
                dp[2] += dp[0];
            }

            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[2];
    }

    public static void main(String[] args) {
        DecodeWays decodeWays = new DecodeWays();
        System.out.println(decodeWays.numDecodings("100"));
    }
}
