namespace SearchInRotatedSortedArray {
    class Solution {
    public:
        int search(int A[], int n, int target) {
            if (n == 0) {
                return -1;
            }
    
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (A[mid] == target) {
                    return mid;
                }
                if (A[mid] >= A[left]) {
                    if (target >= A[left] && target < A[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1; 
                    }
                } else {
                    if (target <= A[right] && target > A[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
    
            return -1;
        }
    };
}
