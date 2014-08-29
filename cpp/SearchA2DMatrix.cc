// https://oj.leetcode.com/problems/search-a-2d-matrix/
namespace SearchA2DMatrix {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            
            int m = matrix.size();
            if (m == 0) {
                return false;
            }
            
            int n = matrix[0].size();
            if (n == 0) {
                return false;
            }
            
            int end = m * n;
            int start = 0;
            
            do {
                int mid = ((end - start) >> 1) + start;
                int curRow = mid / n;
                int curCol = mid % n;
                if (matrix[curRow][curCol] == target) {
                    return true;
                } else if (matrix[curRow][curCol] > target) {
                    end = mid;
                } else {
                    start = mid + 1;
                }
                
            } while (start < end);
            
            return false;
            
        }
    };
}
