package org.speedfirst.leetcode.combination;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by jiankuan on 1/28/15.
 */
public class KSum {

    public int  kSum(int A[], int k, int target) {
        List<List<Integer>> res = new ArrayList<>();
        doKSum(A, k, 0, target, new ArrayList<>(), res);
        return res.size();
    }


    private void doKSum(int[] A, int k, int pos,
                        int target, List<Integer> cur, List<List<Integer>> res) {
        if (k == cur.size() && target == 0) {
            res.add(new ArrayList<>(cur));
            return;
        }

        if (k == cur.size()) {
            return;

        }

        if (target < 0) {
            return;
        }

        for (int i = pos; i < A.length; i++) {
            cur.add(A[i]);
            doKSum(A, k, i + 1, target - A[i], cur, res);

            cur.remove(cur.size() - 1);
        }
    }

    public int kSumDp(int[] A, int k, int target) {
        if (A.length < k) return 0;
        int[][][] d = new int[k + 1][A.length + 1][target + 1];
        for (int i = 1; i <= A.length; i++) {
            if (A[i - 1] <= target) {
                for (int j = i; j <= A.length; j++)
                    d[1][j][A[i - 1]] = 1;
            }
        }

        for (int i = 2; i <= k; i++) {
            for (int j = i; j <= A.length; j++) {
                for (int v = 1; v <= target; v++) {
                    d[i][j][v] = 0;
                    if (j > i) d[i][j][v] += d[i][j - 1][v];
                    if (v >= A[j - 1]) d[i][j][v] += d[i - 1][j - 1][v - A[j - 1]];
                }
            }
        }

        return d[k][A.length][target];
    }

    public static void main(String[] args) {
//        int[] arr = {1,4,6,8,10,13,15,17,18,21,23,26,27,28,29,30,32,35,36};
//        int res = new KSum().kSum(arr, 9, 133);
//        System.out.println(res);
        int[] arr = {1, 2, 3, 4};
        int res = new KSum().kSumDp(arr, 2, 5);
        System.out.println(res);

        int res2 = new KSum().kSum(arr, 2, 5);
        System.out.println(res2);
    }
}
