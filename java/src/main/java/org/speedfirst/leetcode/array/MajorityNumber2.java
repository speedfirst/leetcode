package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;

public class MajorityNumber2 {

    public int majorityNumber(ArrayList<Integer> nums) {
        int num1 = nums.get(0);
        int num1Count = 1;
        int i = 1;
        while (i < nums.size() && nums.get(i) == num1) {
            i++;
            num1Count++;
        }

        if (i == nums.size()) {
            return num1;
        }

        int num2 = nums.get(i);
        int num2Count = 1;
        i++;
        while (i < nums.size()) {
            if (nums.get(i) == num1) {
                num1Count++;
            } else if (nums.get(i) == num2) {
                num2Count++;
            } else {
                if (num1Count == 0) {
                    num1 = nums.get(i);
                    num1Count = 1;
                } else if (num2Count == 0) {
                    num2 = nums.get(i);
                    num2Count = 1;
                } else {
                    num1Count--;
                    num2Count--;
                }
            }
            i++;
        }

        if (num1Count == 0) {
            return num2;
        } else if (num2Count == 0) {
            return num1;
        } else {
            // double check
            num1Count = 0;
            for (int num: nums) {
                if (num == num1) {
                    num1Count++;
                }
            }

            if (num1Count > nums.size() / 3) {
                return num1;
            } else {
                return num2;
            }
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<>(Arrays.asList(1,1,1,1,2,2,3,3,4,4,4));

        MajorityNumber2 m = new MajorityNumber2();
        int res = m.majorityNumber(nums);
        System.out.println(res);
    }
}
