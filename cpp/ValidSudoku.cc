namespace ValidSudoku {
    class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            vector<bool> set(9, false);
            
            // check each line
            for (int i = 0; i < 9; i++) {
                fill(set.begin(), set.end(), false);
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') continue;
                    int v = (int)(board[i][j] - '0') - 1;
                    if (set[v] == true) {
                        return false;
                    } else {
                        set[v] = true;
                    }
                }
            }
            
            // check each col
            for (int i = 0; i < 9; i++) {
                fill(set.begin(), set.end(), false);
                for (int j = 0; j < 9; j++) {
                    if (board[j][i] == '.') continue;
                    int v = (int)(board[j][i] - '0') - 1;
                    if (set[v] == true) {
                        return false;
                    } else {
                        set[v] = true;
                    }
                }
            }
            
            // check 9 sub cube
            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    fill(set.begin(), set.end(), false);
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (board[i + x][j + y] == '.') continue;
                            int v = (int)(board[i + x][j + y] - '0') - 1;
                            if (set[v] == true) {
                                return false;
                            } else {
                                set[v] = true;
                            }
                        }
                    }
                }
            }
            
            return true;
            
        }
    };
}
