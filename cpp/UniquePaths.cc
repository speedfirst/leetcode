// https://oj.leetcode.com/problems/unique-paths/
namespace UniquePaths {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            
            vector<vector<int> > dp(m, vector<int>(n, 1));
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            
            return dp[m - 1][n - 1];
        }
    };
    
    
    // recursive solution
    // https://oj.leetcode.com/problems/unique-paths/
    class Solution {
    public:
    
        int recPaths(int m, int n, int ** cache) {
             if (cache[m][n] != 0) {
                return cache[m][n];
            }
            
            
            if (m == 1 && n == 1) {
                return 1;
            }
            
            if (m == 1) {
                return recPaths(m, n - 1, cache);
            }
            
            if (n == 1) {
                return recPaths(m - 1, n, cache);
            }
            
            int res = recPaths(m - 1, n, cache) + recPaths(m, n - 1, cache);
            cache[m][n] = res;
            return res;
        }
        
        int uniquePaths(int m, int n) {
            int ** cache = new int * [m + 1];
            for (int i = 0; i <= m; i++) {
                cache[i] = new int[n + 1];
                for (int j = 0; j <= n; j++) {
                    cache[i][j] = 0;
                }
            }
            int res = recPaths(m, n, cache);
            return res;
            
        }
    };
}
