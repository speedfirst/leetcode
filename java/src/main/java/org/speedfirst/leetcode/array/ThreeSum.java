package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by jiankuan on 1/27/15.
 */
public class ThreeSum {

    private void doThreeSum(int[] numbers, int pos, ArrayList<ArrayList<Integer>> res) {
        int num = numbers[pos];
        int s = pos + 1;
        int e = numbers.length - 1;
        int target = -num;
        while (s < e) {
            int sum = numbers[s] + numbers[e];
            if (sum == target) {
                ArrayList<Integer> sol = new ArrayList<>();
                sol.add(num);
                sol.add(numbers[s]);
                sol.add(numbers[e]);
                res.add(sol);
                do {
                    e--;
                } while (s < e && numbers[e] == numbers[e + 1]);
                do {
                    s++;
                } while (s < e && numbers[s] == numbers[s - 1]);
            } else if (sum > target) {
                do {
                    e--;
                } while (s < e && numbers[e] == numbers[e + 1]);
            } else {
                do {
                    s++;
                } while (s < e && numbers[s] == numbers[s - 1]);
            }
        }
    }

    public ArrayList<ArrayList<Integer>> threeSum(int[] numbers) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();

        Arrays.sort(numbers);

        for (int i = 0; i <= numbers.length - 3; i++) {
            if (i != 0 && numbers[i] == numbers[i - 1]) {
                continue;
            }
            doThreeSum(numbers, i, res);

        }

        return res;
    }

    public static void main(String[] args) {
        int[] numbers = {-2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5};
        ArrayList<ArrayList<Integer>> res = new ThreeSum().threeSum(numbers);
        for (ArrayList<Integer> list: res) {
            System.out.println(list);
        }
    }
}
