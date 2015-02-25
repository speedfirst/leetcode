// https://oj.leetcode.com/problems/rotate-array/
class Solution {
public:
    void reverse(int nums[], int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
    void rotate(int nums[], int n, int k) {
        
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
