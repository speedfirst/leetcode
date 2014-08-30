// https://oj.leetcode.com/problems/permutations/
namespace Permutations {
    class Solution {
    public:
        void doPermute(vector<int> &num, int start, int end, vector<vector<int> > &res) {
            if (start == end - 1) {
                vector<int> * onePermutation = new vector<int>(num);
                res.push_back(*onePermutation);
                return;
            }
            
            for (int i = start; i < end; i++) {
                if (start != i) {
                    int temp = num[i];
                    num[i] = num[start];
                    num[start] = temp;
                }
                doPermute(num, start + 1, end, res);
                // switch back
                if (start != i) {
                    int temp = num[i];
                    num[i] = num[start];
                    num[start] = temp;
                }
            }
        }
        
        vector<vector<int> > permute(vector<int> &num) {
            
            vector<vector<int> > res;
            doPermute(num, 0, num.size(), res);
            
            return res;
        }
    };
}
