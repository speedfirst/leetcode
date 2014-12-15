// https://oj.leetcode.com/problems/maximum-gap/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        
        set<int> S;
        for (int i = 0; i < num.size(); i++) {
            S.insert(num[i]);
        }
        
        set<int>::iterator it = S.begin();
        int prev = *it;
        it++;
        int maxGap = 0;
        for (; it != S.end(); it++) {
            int cur = *it;
            maxGap = max(maxGap, cur - prev);
            prev = cur;
        }
        return maxGap;
    }
};
