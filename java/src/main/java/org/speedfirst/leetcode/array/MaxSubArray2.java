package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * http://lintcode.com/en/problem/maximum-subarray-ii/
 */
public class MaxSubArray2 {
    public int maxTwoSubArrays(ArrayList<Integer> nums) {
        int[] maxSumLeft = new int[nums.size()];
        int[] maxSumRight= new int[nums.size()];
        int tmp;
        maxSumLeft[0] = tmp = nums.get(0);
        for (int i = 1; i < nums.size(); i++) {
            tmp = Math.max(tmp + nums.get(i), nums.get(i));
            maxSumLeft[i] = Math.max(tmp, maxSumLeft[i - 1]);
        }

        maxSumRight[nums.size() - 1] = tmp = nums.get(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            tmp = Math.max(tmp + nums.get(i), nums.get(i));
            maxSumRight[i] = Math.max(tmp, maxSumRight[i + 1]);
        }

        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.size() - 1; i++)  {
            maxSum = Math.max(maxSum, maxSumLeft[i] + maxSumRight[i + 1]);
        }
        return maxSum;
    }

    public static void main(String[] args) {

        MaxSubArray2 m = new MaxSubArray2();
        int res = m.maxTwoSubArrays(new ArrayList<>(Arrays.asList(1,3,-1,2,-1,2)));
        System.out.println(res);
    }
}
