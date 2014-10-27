// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int> &num) {
        // actually you can solve this problem by any O(n) enumeration algorithm
        if (num.size() == 0) {
            return INT_MIN;
        }
        
        if (num.size() == 1) {
            return num[0];
        }
        
        int left = 0;
        int right = num.size() - 1;
        int right_most = num[num.size() - 1];
        while (left < right) {
            int mid = ((right - left) >> 1) + left;
            int cur = num[mid];
            if (cur > num[right]) {
                left = mid + 1;
            } else if (cur < num[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        
        return num[left];
    }
};
