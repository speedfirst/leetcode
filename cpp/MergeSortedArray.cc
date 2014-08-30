// https://oj.leetcode.com/problems/merge-sorted-array/
namespace MergeSortedArray {
    class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            int posA = m - 1;
            int posB = n - 1;
            int dest = m + n - 1;
            
            while (posA >= 0 && posB >= 0) {
                if (A[posA] >= B[posB]) {
                    A[dest] = A[posA];
                    posA--;
                } else {
                    A[dest] = B[posB];
                    posB--;
                }
                dest--;
            }
            
            while (posB >= 0) {
                A[dest] = B[posB];
                dest--;
                posB--;
            } 
            
            // if array A has remaning elements, just leave it there
            
        }
    };
}
