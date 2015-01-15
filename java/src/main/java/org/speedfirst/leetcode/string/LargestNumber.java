package org.speedfirst.leetcode.string;

import java.util.ArrayList;
import java.util.List;

/**
 * @author jiankuan
 * @since 1/15/15
 */
public class LargestNumber {
    public String largestNumber(int[] num) {
        List<String> strs = new ArrayList<>();
        for (int n: num) {
            strs.add(String.valueOf(n));
        }

        strs.sort((String s1, String s2) -> (s2 + s1).compareTo(s1 + s2));

        int i = 0;
        while (i < strs.size() && strs.get(i).equals("0")) {
            i++;
        }

        if (i == strs.size()) {
            return "0";
        }

        StringBuilder sb = new StringBuilder();
        while (i < strs.size()) {
            sb.append(strs.get(i));
            i++;
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        int[] num = new int[]{1};
        String res = new LargestNumber().largestNumber(num);
        System.out.println(res);
    }
}