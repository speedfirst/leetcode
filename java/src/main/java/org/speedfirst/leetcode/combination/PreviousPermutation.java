package org.speedfirst.leetcode.combination;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by jiankuan on 1/22/15.
 */
public class PreviousPermutation {

    /**
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    public ArrayList<Integer> previousPermuation(ArrayList<Integer> nums) {
        // write your code
        if (nums.isEmpty() || nums.size() == 1) {
            return nums;
        }

        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums.get(i) > nums.get(i + 1)) {
                break;
            }
        }

        int pos1 = -1, pos2;
        if (i >= 0) {
            pos1 = i;

            for (i = nums.size() - 1; i > pos1; i--) {
                if (nums.get(i) <  nums.get(pos1)) {
                    break;
                }
            }
            pos2 = i;
            // swap pos1 and pos2
            swap(nums, pos1, pos2);
        }

        // reverse [pos + 1, end of nums]
        int s = pos1 + 1;
        int e = nums.size() - 1;
        while (s < e) {
            swap(nums, s, e);
            s++;
            e--;
        }

        return nums;
    }

    private void swap(ArrayList<Integer> nums, int pos1, int pos2) {
        int tmp = nums.get(pos1);
        nums.set(pos1, nums.get(pos2));
        nums.set(pos2, tmp);
    }

    public static void main(String[] args) {
        PreviousPermutation pp = new PreviousPermutation();
        ArrayList<Integer> nums = new ArrayList(Arrays.asList(1, 2, 5, 3, 4));
        System.out.println(pp.previousPermuation(nums));
        nums = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        System.out.println(pp.previousPermuation(nums));
    }
}
