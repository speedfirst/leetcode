// https://oj.leetcode.com/problems/maximum-subarray/
namespace MaximumSubarray {
    // O(n) solution
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
    
    // Divide & Conquer Solution, O(nLog(n))
    class Solution1 {
    public:
        int maxCrossSubArray(int A[], int left, int mid, int right) {
            int maxLeftSum = INT_MIN;
            int maxRightSum = INT_MIN;
            
            // calc left sum
            int sum = 0;
            for (int i = mid; i >= left; i--) {
                sum += A[i];
                if (sum > maxLeftSum) {
                    maxLeftSum = sum;
                }
            }
            
            // calc right sum
            sum = 0;
            for (int i = mid + 1; i <= right; i++) {
                sum += A[i];
                if (sum > maxRightSum) {
                    maxRightSum = sum;
                }
            }
            
            return maxLeftSum + maxRightSum;
        }
        
        int maxOneSideSubArray(int A[], int left, int right) {
            if (left == right) {
                return A[left];
            }
            
            int mid = (left + right) / 2;
            
            return max(maxCrossSubArray(A, left, mid, right),
                    max(maxOneSideSubArray(A, left, mid), maxOneSideSubArray(A, mid + 1, right)));
        }
        
        int maxSubArray(int A[], int n) {
            if (n == 0) {
                return 0;
            }
            
            return maxOneSideSubArray(A, 0, n - 1);
        }
    };
}
