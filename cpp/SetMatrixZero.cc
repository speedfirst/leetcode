// https://oj.leetcode.com/problems/set-matrix-zeroes/
namespace SetMatrixZero {
    class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            
            int m = matrix.size();
            int n = matrix[0].size();
            
            bool firstRow0 = false;
            bool firstCol0 = false;
            
            // check first row
            for (int i = 0; i < n; i++) {
                if (matrix[0][i] == 0) {
                    firstRow0 = true;
                    break;
                }
            }
            
            // check first col
            for (int i = 0; i < m; i++) {
                if (matrix[i][0] == 0) {
                    firstCol0 = true;
                    break;
                }
            }
            
            // check row by row (start from the 2nd row)
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                    }
                }
            }
            
            // check col by col (start from the 2nd col)
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[j][i] == 0) {
                        matrix[j][0] = 0;
                    }
                }
            }
            
            // set cols to 0 if the element of first row is 0
            for (int i = 1; i < n; i++) {
                if (matrix[0][i] == 0) {
                    for (int j = 1; j < m; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
            
            // set rows to 0 if the element of first col is 0
            for (int i = 1; i < m; i++) {
                if (matrix[i][0] == 0) {
                    for (int j = 1; j < n; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            
            if (firstRow0) {
                for (int i = 0; i < n; i++) {
                    matrix[0][i] = 0;
                }
            }
            
            if (firstCol0) {
                for (int i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
            
        }
    };
}
