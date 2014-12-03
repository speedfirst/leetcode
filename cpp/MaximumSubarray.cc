// https://oj.leetcode.com/problems/maximum-subarray/
namespace MaximumSubarray {
    // O(n) solution
    class Solution {
    public:
        int maxSubArray(int A[], int n) {
            if (n == 0) return 0;
            int maxSum = A[0], maxSoFar = A[0];
            for (int i = 1; i < n; i++) {
                maxSoFar = max(maxSoFar + A[i], A[i]);
                maxSum = max(maxSum, maxSoFar);
            }
            return maxSum;
        }
    };
    
    // Divide & Conquer Solution, O(nLog(n))
    class Solution {
    public:
        int findMaxSub(int A[], int L, int R) {
            if (L > R) return INT_MIN;
            
            int mid = ((R - L) >> 2) + L;
            int maxLeft = findMaxSub(A, L, mid - 1);
            int maxRight = findMaxSub(A, mid + 1, R);
            
            int maxMid2Left = 0;
            int sum = 0;
            for (int i = mid - 1; i >= L; i--) {
                sum += A[i];
                maxMid2Left = max(sum, maxMid2Left);
            }
            
            int maxMid2Right = 0;
            sum = 0;
            for (int i = mid + 1; i <= R; i++) {
                sum += A[i];
                maxMid2Right = max(sum, maxMid2Right);
            }
            
            return max(maxMid2Left + A[mid] + maxMid2Right, max(maxLeft, maxRight));
        }
        
        int maxSubArray(int A[], int n) {
            return findMaxSub(A, 0, n - 1);
        }
    };
}
