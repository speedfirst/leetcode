namespace SudokuSolver {
    class Solution {
    public:
        vector<int> getPossibleValues(vector<vector<char> > &board, int x, int y) {
            vector<bool> set(10, false);
            
            // check current line
            for (int j = 0; j < 9; j++) {
                if (board[x][j] != '.') {
                    int v = (int)(board[x][j] - '0');
                    set[v] = true;
                }
            }
            
            // check current col
            for (int i = 0; i < 9; i++) {
                if (board[i][y] != '.') {
                    int v = (int)(board[i][y] - '0');
                    set[v] = true;
                }
            }
            
            // check current 3 * 3 cube
            int startX = x / 3 * 3;
            int startY = y / 3 * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[startX + i][startY + j] != '.') {
                        int v = (int)(board[startX + i][startY + j] - '0');
                        set[v] = true;
                    }
                }
            }
            
            vector<int> res;
            for (int k = 1; k <= 9; k++) {
                if (set[k] == false) res.push_back(k);
            }
            
            return res;
        }
        
        // search the solution by DFS
        bool doSolveSudoku(vector<vector<char> > &board, int x, int y) {
            
            // search the next pos to be filled
            for (; y < 9; y++) {
                if (board[x][y] == '.') { goto search;}
            }
            
            x++;
            for (; x < 9; x++) {
                for (y = 0; y < 9; y++) {
                    if (board[x][y] == '.') { goto search;}
                }
            }
            
            // all pos have been filled, return true
            return true;
            
    search:
            vector<int> possibleValues = getPossibleValues(board, x, y);
            if (possibleValues.empty()) return false;
            
            for (int k = 0; k < possibleValues.size(); k++) {
                board[x][y] = possibleValues[k] + '0';
                if (doSolveSudoku(board, x, y + 1)) return true;
            }
            // nothing found, revert it back
            board[x][y] = '.';
            return false;
        }
        
        void solveSudoku(vector<vector<char> > &board) {
            doSolveSudoku(board, 0, 0);
        }
    };
}
