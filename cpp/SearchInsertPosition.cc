// https://oj.leetcode.com/problems/search-insert-position/
namespace SearchInsertPosition {
    class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            int s = 0;
            int e = n;
            while (s < e) {
                int mid = ((e - s) >> 1) + s;
                if (A[mid] < target) {
                    s = mid + 1;
                } else {
                    e = mid;
                }
            }
            
            return s;
            
        }
    };
}
