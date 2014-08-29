// https://oj.leetcode.com/problems/pascals-triangle-ii/
namespace PascalsTriangle2 {
    class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> res(rowIndex + 1);
            res[0] = 1;
            
            for (int i = 1; i <= rowIndex; i++) {
                res[i] =  res[i - 1];
                for (int j = i - 1; j >= 1; j--) {
                    res[j] = res[j] + res[j - 1];
                }
            }
            
            return res;
            
        }
    };
}
