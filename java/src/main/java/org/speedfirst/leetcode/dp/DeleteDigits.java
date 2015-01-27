package org.speedfirst.leetcode.dp;

/**
 * Given string A representative a positive integer which has N digits, remove k digits of the number,
 * The remaining digits are arranged according to the original order to become a new positive integer.
 * Try to make the remaining number as small as possible.
 *
 N <= 240 and k <=N,
 样例
 Given an integer A = 178542, k = 4

 return a string "12"


 * Created by jiankuan on 1/26/15.
 */
public class DeleteDigits {

    public String DeleteDigits(String A, int k) {
        String res = doDeleteDigits(A, k);
        int i = 0;
        while (i < res.length()) {
            if (res.charAt(i) == '0') {
                i++;
            } else {
                break;
            }
        }

        if (i < res.length()) {
            return res.substring(i);
        } else {
            return "0";
        }
    }

    public String doDeleteDigits(String A, int k) {
        if (k == 0) {
            return A;
        }
        String minStr = A.substring(1);
        for (int i = 1; i < A.length() ; i++) {
            String curStr = A.substring(0, i) + A.substring(i + 1);
            if (curStr.compareTo(minStr) < 0) {
                minStr = curStr;
            }
        }

        return DeleteDigits(minStr, k - 1);
    }

    public static void main(String[] args) {
        System.out.println(new DeleteDigits().DeleteDigits("178542", 4));
    }
}
