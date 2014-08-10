namespace SearchForARange {
    class Solution {
    public:
        int binarySearchLeftMost(int A[], int n, int target) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int mid = ((right - left) >> 1) + left;
                if (A[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            if (A[left] == target) {
                return left;
            } else {
                return -1;
            }
        }
        
        int binarySearchRightMost(int A[], int n, int target) {
            int left = 0;
            int right = n - 1;
            while (left < right) {
                int mid = ((right - left) >> 1) + left + 1; // NOTE "+ 1" to get right most
                if (A[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            
            if (A[right] == target) {
                return right;
            } else {
                return -1;
            }
        }
        
        vector<int> searchRange(int A[], int n, int target) {
            vector<int> res(2, -1);
            if (A == NULL || n == 0) {
                return res;
            }
            
            int lowerBound = binarySearchLeftMost(A, n, target);
            if (lowerBound == -1) {
                // not found
                return res;
            }
            
            int upperBound = binarySearchRightMost(A, n, target);
            res[0] = lowerBound;
            res[1] = upperBound;
            
            return res;
        }
    };
}
