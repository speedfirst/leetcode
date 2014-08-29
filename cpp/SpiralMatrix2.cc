// https://oj.leetcode.com/problems/spiral-matrix-ii/
namespace SpiralMatrix2 {
  class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > res(n, vector<int>(n));
            
            int c = 1;
            int s = n - 1; // end of a side
            int i;
            for (i = 0; i < s; i++, s--) {
                for (int j = i; j < s; j++, c++) {
                    res[i][j] = c;
                }
                
                for (int j = i; j < s; j++, c++) {
                    res[j][s] = c;
                }
                
                for (int j = s; j > i; j--, c++) {
                    res[s][j] = c;
                }
                
                for (int j = s; j > i; j--, c++) {
                    res[j][i] = c;
                }
            }
            
            if (i == s) {
                res[i][i] = c;
            }
            
            return res;
        }
    };
}
