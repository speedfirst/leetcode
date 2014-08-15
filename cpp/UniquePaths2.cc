namespace UniquePaths2 {
  class Solution {
  public:
      int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
          int m = obstacleGrid.size();
          if (m == 0) {
              return 0;
          }
          int n = obstacleGrid[0].size();
          vector<vector<int> > dp(m, vector<int>(n, 1));
          
          // init first row
          int i = 0;
          while (i < m) {
              if (obstacleGrid[i][0] == 1) break;
              i++;
          }
          for (; i < m; i++) dp[i][0] = 0;
          
          // init first col
          int j = 0;
          while (j < n) {
              if (obstacleGrid[0][j] == 1) break;
              j++;
          }
          for (; j < n; j++) dp[0][j] = 0;
          
          for (int i = 1; i < m; i++) {
              for (int j = 1; j < n; j++) {
                  if (obstacleGrid[i][j] == 1) {
                      dp[i][j] = 0;
                  } else {
                      dp[i][j]= dp[i - 1][j] + dp[i][j - 1];
                  }
              }
          }
          
          return dp[m - 1][n - 1];
      }
  };
}
