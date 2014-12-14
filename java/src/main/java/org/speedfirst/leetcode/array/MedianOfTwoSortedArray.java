package org.speedfirst.leetcode.array;

/**
 * @author jiankuan
 * @date 12/14/14
 */
// NOTE k always start with 1
public class MedianOfTwoSortedArray {
    public int findKthElementIn2SortedArrays(int A[], int startA, int lenA, int B[], int startB, int lenB, int k) {
        assert (k < lenA || k < lenB);
        if (lenA == 0) return B[startB + k - 1];
        if (lenB == 0) return A[startA + k - 1];

        if (k == 1) {
            return Math.min(A[startA], B[startB]);
        }

        int pa = Math.min(k / 2, lenA);
        int pb = k - pa;
        int i = startA + pa - 1;
        int j = startB + pb - 1;

        if (A[i] < B[j]) {
            return findKthElementIn2SortedArrays(A, i + 1, lenA - i - 1, B, startB, j, k - i - 1);
        } else if (A[i] > B[j]) {
            return findKthElementIn2SortedArrays(A, startA, i, B, j + 1, lenB - j - 1, k - j - 1);
        } else {
            return A[i];
        }
    }

    public double findMedianSortedArrays(int A[], int B[]) {
        int m = A.length;
        int n = B.length;
        if ((m + n) % 2 == 0) {
            double mid1 = findKthElementIn2SortedArrays(A, 0, m, B, 0, n, ((m + n - 1) >> 1) + 1);
            double mid2 = findKthElementIn2SortedArrays(A, 0, m, B, 0, n, ((m + n) >> 1) + 1);
            return (mid1 + mid2) / 2;

        } else {
            return findKthElementIn2SortedArrays(A, 0, m, B, 0, n, ((m + n) >> 1) + 1);
        }
    }

    public static void main(String[] args) {
        MedianOfTwoSortedArray m = new MedianOfTwoSortedArray();
        double res = m.findMedianSortedArrays(new int[]{2, 3, 4}, new int[]{1});
        System.out.println(res);
    }

}
