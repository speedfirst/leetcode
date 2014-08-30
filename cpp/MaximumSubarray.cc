// https://oj.leetcode.com/problems/maximum-subarray/
namespace MaximumSubarray {
    class Solution {
    public:
        int maxSubArray(int A[], int n) {
            
            int sum = 0;
            int max = INT_MIN;
            for (int i = 0; i < n; i++) {
                
                if (sum < 0) {
                    sum = A[i];
                } else {
                    sum += A[i];
                }
                
                if (sum > max) {
                    max = sum;
                }
            }
            
            return max;
            
        }
    };
}
