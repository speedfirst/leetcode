package org.speedfirst.leetcode.array;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by jiankuan on 11/4/14.
 */
public class FindKthElement {

    //param k : description of k
    //param numbers : array of numbers
    //return: description of return
    public int kthLargestElement(int k, ArrayList<Integer> numbers) {
        doQuickSelect(k - 1, numbers, 0, numbers.size() - 1);
        return numbers.get(k - 1);
    }

    // quick select solution
    public void doQuickSelect(int k, ArrayList<Integer> numbers, int s, int e) {
        if (s >= e) {
            return;
        }

        int pivot = numbers.get(e); // left number as pivot
        int left = s;
        for (int i = left; i < e; i++) {
            if (numbers.get(i) > pivot) {
                swap(numbers, i, left);
                left++;
            }
        }

        swap(numbers, left, e);

        if (left > k) {
            doQuickSelect(k, numbers, s, left - 1);
        } else {
            doQuickSelect(k, numbers, left + 1, e);
        }
    }

    private void swap(ArrayList<Integer> numbers, int i, int j) {
        int tmp = numbers.get(i);
        numbers.set(i, numbers.get(j));
        numbers.set(j, tmp);
    }

    public static void main(String[] args) {
        FindKthElement f = new FindKthElement();
        ArrayList<Integer> numbers = new ArrayList<>(Arrays.asList(9, 3, 2, 4, 8));
        System.out.println(f.kthLargestElement(1, (ArrayList<Integer>) numbers.clone()));
        System.out.println(f.kthLargestElement(2, (ArrayList<Integer>) numbers.clone()));
        System.out.println(f.kthLargestElement(3, (ArrayList<Integer>) numbers.clone()));
        System.out.println(f.kthLargestElement(4, (ArrayList<Integer>) numbers.clone()));
        System.out.println(f.kthLargestElement(5, (ArrayList<Integer>) numbers.clone()));

    }
}
