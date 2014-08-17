namespace SearchInRotatedSortedArray2  {
    class Solution {
    public:
        bool search(int A[], int n, int target) {
            if (n == 0) {
                return false;
            }
    
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = ((right - left) >> 1) + left;
                if (A[mid] == target) {
                    return true;
                }
                if (A[mid] > A[left]) {
                    if (target >= A[left] && target < A[mid]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1; 
                    }
                } else if (A[mid] < A[left]) {
                    if (target <= A[right] && target > A[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    left++; // we don't know to choose which half part
                }
            }
        
            return false;
        }
    };
}
