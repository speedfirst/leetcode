// https://oj.leetcode.com/problems/combination-sum/
namespace CombinationSum {
    class Solution {
    public:
    
        void doCombinationSum(vector<int> &candidates, int target, vector<int> &cur, int pos, int curSum, vector<vector<int> > &res) {
            if (curSum > target) {
                return;
            }
    
            if (curSum == target) {
                res.push_back(cur);
                return;
            }
    
            for (int i = pos; i < candidates.size(); i++) {
                cur.push_back(candidates[i]);
                curSum += candidates[i];
                doCombinationSum(candidates, target, cur, i, curSum, res);
                cur.pop_back();
                curSum -= candidates[i];
            }
        }
    
    
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            vector<vector<int> > res;
            if (candidates.empty()) {
                return res;
            }
    
            sort(candidates.begin(), candidates.end());
            vector<int> cur;
            doCombinationSum(candidates, target, cur, 0, 0, res);
            return res;
        }
    };
}
