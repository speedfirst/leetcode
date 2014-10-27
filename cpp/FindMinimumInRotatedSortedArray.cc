// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int> &num) {
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
            if (cur > right_most) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return num[left];
    }
};
