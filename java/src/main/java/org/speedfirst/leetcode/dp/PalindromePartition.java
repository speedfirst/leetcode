package org.speedfirst.leetcode.dp;

import java.util.ArrayList;
import java.util.List;

/**
 * @author jiankuan
 * @date 12/16/14
 */
public class PalindromePartition {

    public void doPartition(String s, int curPos, List<String> curPartition, List<List<String>> res, boolean[][] dp) {
        if (curPos == s.length()) {
            res.add(new ArrayList<>(curPartition));
            return;
        }
        for (int i = curPos; i < s.length(); i++) {
            if (dp[curPos][i]) {
                String sub = s.substring(curPos, i + 1);
                curPartition.add(sub);
                doPartition(s, i + 1, curPartition, res, dp);
                curPartition.remove(curPartition.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {

        // use dp to find all the palindromes
        boolean[][] dp = new boolean[s.length()][s.length()];

        for (int len = 1; len <= s.length(); len++)  {
            for (int i = 0; i < s.length() - len + 1; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j) && (j - i < 2 || dp[i + 1][j - 1])) dp[i][j] = true;
            }
        }
        List<List<String>> res = new ArrayList<>();
        List<String> curPartition = new ArrayList<>();
        doPartition(s, 0, curPartition, res, dp);
        return res;
    }

    public static void main(String[] args) {
        String s = "bb";
        List<List<String>> res = new PalindromePartition().partition(s);
        res.forEach(System.out::println);
    }

}
