package org.speedfirst.leetcode.bit;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

/**
 * Created by jiankuan on 1/15/15.
 */
public class FindNotExistedNumber {

    List<Integer> getNotExistedNumber(List<Integer> nums) {
        int[] bitset = new int[256]; // 128 integer * 4byte * 8bit = total 4096 numbers
        Arrays.fill(bitset, 0);
        for (int num: nums) {
            int offset = num & 0x1F;
            int idx = num >> 5;
            bitset[idx] |= (1 << offset);
        }

        // bit set done
        // check
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i <4096; i++) {
            int offset = i & 0x1F;
            int idx = i >> 5;
            boolean exists = (((bitset[idx] >> offset) & 0x1) == 1);
            if (!exists) {
                res.add(i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Random r = new Random();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < 20000; i++) {
            nums.add(r.nextInt(4096));
        }

        FindNotExistedNumber findNotExistedNumber = new FindNotExistedNumber();
        List<Integer> res = findNotExistedNumber.getNotExistedNumber(nums);

        // get expected result
        int[] tmp = new int[4096];
        Arrays.fill(tmp, 0);
        for (int num: nums) {
            tmp[num] = 1;
        }
        List<Integer> expectRes = new ArrayList<>();
        for (int i = 0; i < 4096; i++) {
            if (tmp[i] == 0) {
                expectRes.add(i);
            }
        }
        System.out.println(res.equals(expectRes));
        System.out.println(res);
        System.out.println(expectRes);
    }
}
