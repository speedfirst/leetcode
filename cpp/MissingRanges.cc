// https://oj.leetcode.com/problems/missing-ranges/
class Solution {
public:
    vector<string> findMissingRanges(int A[], int n, int lower, int upper) {
        vector<string> res;
        int prev = lower;
        for (int i = 0; i < n; i++) {
            if (A[i] - prev > 1) {
                res.push_back(to_string(prev) + "->" + to_string(A[i] - 1));
            } else if (A[i] - prev == 1) {
                res.push_back(to_string(prev));
            }
            prev = A[i] + 1;
        }
        
        if (upper - prev > 0) {
            res.push_back(to_string(prev) + "->" + to_string(upper));
        } else if (upper == prev) {
            res.push_back(to_string(prev));
        }
        
        return res;
    }
};
