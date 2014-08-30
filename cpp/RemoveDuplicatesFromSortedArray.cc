// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
namespace RemoveDuplicatesFromSortedArray {
  class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            
            if (n <= 1) {
                return n;
            }
            
            int src = 1;
            int dest = 1;
            
            while (src < n) {
                if (A[src] == A[src - 1]) {
                    src++;
                } else {
                    A[dest] = A[src];
                    dest++;
                    src++;
                }
            }
            
            return dest;
            
        }
    };
}
