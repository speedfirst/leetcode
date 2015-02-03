package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by jiankuan on 2/4/15.
 */
public class MaxSubArrayDiff {

    public int maxDiffSubArrays(ArrayList<Integer> nums) {
        // write your code

        int[] maxSumLeft = new int[nums.size()];
        int[] maxSumRight= new int[nums.size()];
        int[] minSumRight = new int[nums.size()];
        int[] minSumLeft = new int[nums.size()];

        maxSumLeft[0] = nums.get(0);
        minSumLeft[0] = nums.get(0);
        for (int i = 1; i < nums.size(); i++) {
            maxSumLeft[i] = Math.max(maxSumLeft[i - 1] + nums.get(i), nums.get(i));
            minSumLeft[i] = Math.min(minSumLeft[i - 1] + nums.get(i), nums.get(i));
        }

        maxSumRight[nums.size() - 1] = nums.get(nums.size() - 1);
        minSumRight[nums.size() - 1] = nums.get(nums.size() - 1);
        for (int i = nums.size() - 2; i >= 0; i--) {
            maxSumRight[i] = Math.max(maxSumRight[i + 1] + nums.get(i), nums.get(i));
            minSumRight[i] = Math.min(minSumRight[i + 1] + nums.get(i), nums.get(i));
        }

        int maxDiff = 0;
        for (int i = 0; i < nums.size() - 1; i++)  {
            maxDiff = Math.max(maxDiff, Math.abs(maxSumLeft[i] - minSumRight[i + 1]));
        }
        for (int i = nums.size() - 1; i > 0; i--)  {
            maxDiff = Math.max(maxDiff, Math.abs(maxSumRight[i] - minSumLeft[i - 1]));
        }


        return maxDiff;
    }

    public static void main(String[] args) {
        MaxSubArrayDiff m = new MaxSubArrayDiff();
        int res = m.maxDiffSubArrays(new ArrayList<>(Arrays.asList(-5,3,-4,0,0,0,-1,20,1,1,-1,-1,-1,-1,-1)));
        System.out.println(res);
    }
}
