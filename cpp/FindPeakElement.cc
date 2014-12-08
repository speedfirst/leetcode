// https://oj.leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if (num.size() == 0) return INT_MIN;
        for (int i = 1; i < num.size() - 1; i++) {
            if (num[i] > num[i - 1] && num[i] > num[i + 1]) {
                return i;
            }
        }
        return (num[0] > num[num.size() - 1])? 0 : num.size() - 1;
    }
};
