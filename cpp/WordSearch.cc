namespace WordSearch {
  class Solution {
  public:
      bool dfsSearch(vector<vector<char> > &board, string word, vector<vector<bool> >& visited, int i, int j, int w, int h, int curIdx) {
  
          
          if (word[curIdx] != board[i][j]) {
              return false;
          }
          
          if (curIdx == word.size() - 1) {
              // end of string match
              return true;
          }
          
          visited[i][j] = true;
          bool res;
          
          if (i > 0 && visited[i - 1][j] == false) {
              if (dfsSearch(board, word, visited, i - 1, j, w, h, curIdx + 1)) {return true;}
          }
          
          if (i < w - 1 && visited[i + 1][j] == false) {
              if (dfsSearch(board, word, visited, i + 1, j, w, h, curIdx + 1)) {return true;}
          }
          
          if (j > 0 && visited[i][j - 1] == false) {
              if (dfsSearch(board, word, visited, i, j - 1, w, h, curIdx + 1)) {return true;}
          }
          
          if (j < h - 1 && visited[i][j + 1] == false) {
              if (dfsSearch(board, word, visited, i, j + 1, w, h, curIdx + 1)) {return true;}
          }
          
          visited[i][j] = false;
          
          return false;
      }
      
      bool exist(vector<vector<char> > &board, string word) {
         if (board.empty() || board[0].empty()) {
             return false;
         }
         
         if (word.empty()) {
             return false;
         }
         
         int w = board.size();
         int h = board[0].size();
         
         vector<vector<bool> > visited(w, vector<bool>(h, false));
         
         for (int i = 0; i < board.size(); i++) {
             for (int j = 0; j < board[i].size(); j++) {
                 bool res = dfsSearch(board, word, visited, i, j, w, h, 0);
                 if (res == true) {
                     return true;
                 }
             }
         }
         
         return false;
      }
  };
}
