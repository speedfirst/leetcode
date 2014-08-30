namespace PascalsTriangle {
    class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > res;
            if (numRows == 0) {
                return res;
            }
            vector<int> row1;
            row1.push_back(1);
            res.push_back(row1);
            
            for (int i = 1; i <= numRows - 1; i++) {
                vector<int> row;
                vector<int> prevRow = res[i - 1];
                int n = i + 1;
                for (int j = 0; j < n; j++) {
                    
                    int left = (j > 0)? prevRow[j - 1] : 0;
                    int right = (j < n - 1)? prevRow[j] : 0;
                    row.push_back(left + right);
                }
                res.push_back(row);
            }
            
            return res;
            
        }
    };
}
