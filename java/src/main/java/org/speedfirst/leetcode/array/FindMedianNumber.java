package org.speedfirst.leetcode.array;

/**
 * Created by jiankuan on 2/2/15.
 */
public class FindMedianNumber {
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    public int median(int[] nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException();
        }

        if (nums.length % 2 == 0) {
            return findKthElement(nums, 0, nums.length - 1, nums.length / 2 - 1);
        } else {
            return findKthElement(nums, 0, nums.length - 1, nums.length / 2);
        }
    }

    private void swap(int[] nums, int i, int j) {
        if (i == j) return;
        nums[i] = nums[i] ^ nums[j];
        nums[j] = nums[i] ^ nums[j];
        nums[i] = nums[i] ^ nums[j];
    }

    private int findKthElement(int[] nums, int s, int e, int k) {
        if (s == e) {
            return nums[s];
        }

        int pivot = nums[e];
        int left = s;
        for (int i = s; i < e; i++) {
            if (nums[i] < pivot) {
                swap(nums, i, left);
                left++;
            }
        }

        swap(nums, left, e);
        if (k < left) {
            return findKthElement(nums, s, left - 1, k);
        } else if (k > left) {
            return findKthElement(nums, left + 1, e, k);
        } else {
            return nums[left];
        }
    }

    public static void main(String[] args) {
        FindMedianNumber findMedianNumber = new FindMedianNumber();
        int res = findMedianNumber.median(new int[]{7, 9, 4, 5});
        System.out.println(res);
    }
}
