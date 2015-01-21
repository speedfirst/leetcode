package org.speedfirst.leetcode.heap;

/**
 * Created by jiankuan on 1/21/15.
 */
public class Heapify {

    /**
     * @param A: Given an integer array
     * @return: void
     */
    public void heapify(int[] A) {
        int end = 0;
        while (end < A.length) {
            int pos = end;
            int parentPos = (pos - 1) / 2;
            while (pos > 0) {
                if (parentPos < 0) {
                    break;
                }

                if (A[parentPos] <= A[pos]) {
                    break;
                }

                swap(A, parentPos, pos);
                pos = parentPos;
                parentPos = (pos - 1) / 2;
            }

            end++;
        }
    }

    private void swap(int[] A, int i, int j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }

    public static void main(String[] args) {
        int[] A = {42,30,27,93,8,34,47,64,82,76,70,79,23,5,67,9,97,29,7,61,73,3,44,85,51,49,90,59,38,55,39,62,54,81,26,50,22,71,52,41,77,32,2,96,84,20,48,17,87,94,12,13,89,24,6,74,69,78,65,35,15,28,25,16,33,63};
        Heapify heapify = new Heapify();
        heapify.heapify(A);

        for (int i = 0; i < A.length / 2; i++) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < A.length && A[i] >= A[left]) {
                System.out.println("invalid heap pos " + i + ":" + A[i] + ", left " + left + ":" + A[left]);
            }
            if (right < A.length && A[i] >= A[right]) {
                System.out.println("invalid heap pos " + i + ":" + A[i] + ", right " + right + ":" + A[right]);
            }
        }

        for (int i = 0; i < A.length; i++) {
            System.out.printf("%d\t", i);
        }

        System.out.println();

        for (int i = 0; i < A.length; i++) {
            System.out.printf("%d\t", A[i]);
        }
    }
}
