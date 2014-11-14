package org.speedfirst.leetcode.not_in_oj;

import java.util.Arrays;
import java.util.Random;

/**
 * Created by jiankuan on 11/4/14.
 */
public class FindKthElement {

    private Random r = new Random();

    private void swap(int[] arr, int pos1, int pos2) {
        if (pos1 == pos2) return;
        int tmp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = tmp;
    }

    /**
     *
     * @return pivot's position
     */
    private int partition(int[] arr, int left, int right) {
        int pivotPos = r.nextInt(right - left + 1) + left;
        int pivot = arr[pivotPos];
        swap(arr, pivotPos, right);
        for (int i = left; i < right; i++) {
            if (arr[i] < pivot) {
                swap(arr, left, i);
                left++;
            }
        }
        swap(arr, left, right);
        return left;
    }

    private void doFind(int[] arr, int start, int end, int k) {
        if (start <= end) {
            int pivotPos = partition(arr, start, end);
            if (pivotPos < k) {
                doFind(arr, pivotPos + 1, end, k);
            } else {
                doFind(arr, start, pivotPos - 1, k);
            }
        }
    }

    public int[] find(int[] arr, int k) {
        doFind(arr, 0, arr.length - 1, k - 1);
        return Arrays.copyOfRange(arr, 0, k);
    }

    private static void output(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int element: arr) {
            sb.append(element);
            sb.append(',');
        }
        sb.setLength(sb.length() - 1);
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {
        FindKthElement f = new FindKthElement();
        int arr[] = {4, 9, 6, 2, 8, 7, 1, 5, 3};
        output(f.find(arr.clone(), 1));
        output(f.find(arr.clone(), 3));
        output(f.find(arr.clone(), 5));
        output(f.find(arr.clone(), 6));
    }
}
