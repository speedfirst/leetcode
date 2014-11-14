package org.speedfirst.leetcode.not_in_oj;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by jiankuan on 11/14/14.
 */
public class Permutation {

    private int swapNum = 0;

    public int getSwapNum() {
        return swapNum;
    }

    public List<List<Integer>> permutation(List<Integer> arr) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        doPermutation(0, arr, res);
        return res;
    }

    private void swap(List<Integer> arr, int i, int j) {
        int tmp = arr.get(i);
        arr.set(i, arr.get(j));
        arr.set(j, tmp);
        swapNum++;
    }

    private void doPermutation(int cur, List<Integer> arr, List<List<Integer>> res) {
        if (cur == arr.size()) {
            res.add(new ArrayList<Integer>(arr));
            return;
        }

        doPermutation(cur + 1, arr, res);

        for (int i = cur + 1; i < arr.size(); i++) {
            swap(arr, cur, i);
            doPermutation(cur + 1, arr, res);
            swap(arr, cur, i);
        }
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(2);
        arr.add(3);
        arr.add(4);
        Permutation p = new Permutation();
        List<List<Integer>> res = p.permutation(arr);
        int i = 1;
        for (List<Integer> perm: res) {
            System.out.print(i + ":\t");
            i++;
            for (int num: perm) {
                System.out.print(num);
                System.out.print(",");
            }
            System.out.println();
        }

        System.out.println("Swap: " + p.getSwapNum());
    }
}
