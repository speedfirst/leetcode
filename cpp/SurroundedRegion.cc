namepsace SurroundeRegion {
     class Solution {
     public:
         void solve(vector<vector<char> > &board) {
             int w = board.size();
             if (w == 0) {
                 return;
             }

             int h = board[0].size();
             if (h == 0) {
                 return;
             }

             // search the top line to find 'O' and mark those live nodes
             for (int i = 0; i < w; i++) {
                 if (board[i][0] == 'O') {
                     markLives(board, i, 0);
                 }
             }

             // search the bottom line to find 'O' and mark those live nodes
             for (int i = 0; i < w; i++) {
                 if (board[i][h - 1] == 'O') {
                     markLives(board, i, h - 1);
                 }
             }

             // search the left line to find 'O' and mark those live nodes
             for (int j = 1; j < h - 1; j++) {
                 if (board[0][j] == 'O') {
                     markLives(board, 0, j);
                 }
             }

             // search the right line to find 'O' and mark those live nodes
             for (int j = 1; j < h - 1; j++) {
                 if (board[w - 1][j] == 'O') {
                     markLives(board, w - 1, j);
                 }
             }

             // flip remaining 'O' to 'X' and 'L' to 'O'
             for (int i = 0; i < w; i++) {
                 for (int j = 0; j < h; j++) {
                     if (board[i][j] == 'O') {
                         board[i][j] = 'X';
                     } else if (board[i][j] == 'L') {
                         board[i][j] = 'O';
                     }
                 }
             }
         }

         // makr live nodes by BFS, the node is marked as 'L'
         void markLives(vector<vector<char> > &board, int startX, int startY) {

             int w = board.size();
             int h = board[0].size();

             queue<pair<int, int> > q;
             pair<int, int> start(startX, startY);
             board[startX][startY] = 'L';
             q.push(start);

             while (!q.empty()) {
                 pair<int, int> cur = q.front();
                 q.pop();
                 int x = cur.first;
                 int y = cur.second;

                 if (x > 0 && board[x - 1][y] == 'O') {
                     board[x - 1][y] = 'L';
                     q.push(make_pair(x - 1, y));
                 }

                 if (x < w - 1 && board[x + 1][y] == 'O') {
                     board[x + 1][y] = 'L';
                     q.push(make_pair(x + 1, y));
                 }

                 if (y > 0 && board[x][y - 1] == 'O') {
                     board[x][y - 1] = 'L';
                     q.push(make_pair(x, y - 1));
                 }
                 if (y < h - 1 && board[x][y + 1] == 'O') {
                     board[x][y + 1] = 'L';
                     q.push(make_pair(x, y + 1));
                 }
             }
         }
     };
}