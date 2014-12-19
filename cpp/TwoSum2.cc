// https://oj.leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int s = 0;
        int e = numbers.size() - 1;
        
        while (s < e) {
            int sum = numbers[s] + numbers[e];
            if (sum < target) {
                s++;
            } else if (sum > target) {
                e--;
            } else {
                res.push_back(s + 1);
                res.push_back(e + 1);
                break;
            }
            
        }
        return res;
    }
};
