namespace NQueens {
    class Solution {
    public:
        
        void doSolveNQueens(int n, int i, vector<vector<string> >& res, vector<string>& cur,
            vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
            if (i == n) {
                res.push_back(cur);
                return;
            }
            
            for (int j = 0; j < n; j++) {
                if (col[j] == false && diag1[i - j + n - 1] == false && diag2[i + j] == false) {
                    col[j] = true;
                    diag1[i - j + n - 1] = true;
                    diag2[i + j] = true;
                    string row(n, '.');
                    row[j] = 'Q';
                    cur.push_back(row);
                    doSolveNQueens(n, i + 1, res, cur, col, diag1, diag2);
                    // rever it back
                    cur.pop_back();
                    col[j] = false;
                    diag1[i - j + n - 1] = false;
                    diag2[i + j] = false;
                }
            }
        }
        
        vector<vector<string> > solveNQueens(int n) {
            
            vector<vector<string> > res;
            if (n == 0) return res;
            
            vector<bool> col(n, false);
            vector<bool> diag1(n * 2 - 1, false); // diagonal line "\"
            vector<bool> diag2(n * 2 - 1, false); // diagonal line "/"
            vector<string> cur;
            doSolveNQueens(n, 0, res, cur, col, diag1, diag2);
            return res;
        }
    };
}
