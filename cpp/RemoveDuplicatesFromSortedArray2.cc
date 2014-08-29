// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
namespace RemoveDuplicatesFromSortedArray2 {
    class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if (A == NULL || n < 3) {
                return n;
            }
            
            int i = 2;
            int j = 2;
            int prev = A[0];
            while (j < n) {
                if (A[j] == prev && A[j - 1] == prev) {
                    j++;
                } else {
                    prev = A[j - 1];
                    A[i] = A[j];
                    i++;
                    j++;
                    
                }
            }
            
            return i;
        }
    };
}
