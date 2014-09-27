/**
 * https://oj.leetcode.com/problems/maximum-product-subarray/
 */
namespace MaximumProductSubarray {
    class Solution {
    public:
        int maxProduct(int A[], int n) {
            if (n == 0) {
                return 0;
            }
    
            int maxSoFar = A[0];
            int minSoFar = A[0];
            int maxRes = A[0];
            
            for (int i = 1; i < n; i++) {
                int prod1 = A[i] * maxSoFar;
                int prod2 = A[i] * minSoFar;
                maxSoFar = max(A[i], max(prod1, prod2));
                minSoFar = min(A[i], min(prod1, prod2));
                maxRes = max(maxRes, maxSoFar);
            }
            
            return maxRes;
         }
    };
}
