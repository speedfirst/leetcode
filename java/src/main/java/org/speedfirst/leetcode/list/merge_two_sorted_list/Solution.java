package org.speedfirst.leetcode.list.merge_two_sorted_list;

/**
 * Created by jiankuan on 11/4/14.
 */
public class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }

        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }

        if (divisor == 1) {
            return dividend;
        }

        if(divisor==Integer.MIN_VALUE)
            return 0;

        int res = 0;
        int additional_one = 0;
        if(dividend==Integer.MIN_VALUE) {
            additional_one = 1;
            dividend += Math.abs(divisor);
        }

        boolean neg = (((dividend ^ divisor) >>> 31) == 1);
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);

        if (dividend < divisor) {
            return 0;
        }

        int digit = 0;
        while ((dividend >> digit) >= divisor) {
            digit++;
        }
        digit--;

        while (digit >= 0) {
            int tmp = (divisor << digit);
            digit--;
            res <<= 1;
            if (tmp <= dividend) {
                res += 1;
                dividend -= tmp;
            }
        }
        res += additional_one;
        return (neg? -res : res);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.divide(-2147483648, -1109186033));
    }
}