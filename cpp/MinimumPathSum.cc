// https://oj.leetcode.com/problems/minimum-path-sum/
namespace MinimumPathSum {
    class Solution {
    public:
        int doMinPathSum(vector<vector<int> >&grid, vector<vector<int> >& cache, int m, int n) {
            if (cache[m][n] != -1) {
                return cache[m][n];
            }
            
            int res;
            if (m == 1 && n == 1) {
                res = grid[m - 1][n - 1];
            } else if (m == 1) {
                res = doMinPathSum(grid, cache, m, n - 1) + grid[m - 1][n - 1];
            } else if (n == 1) {
                res = doMinPathSum(grid, cache, m - 1, n) + grid[m - 1][n - 1];
            } else {
                res = min(doMinPathSum(grid, cache, m, n - 1), doMinPathSum(grid, cache, m - 1, n)) + grid[m - 1][n - 1];
            }
            
            cache[m][n] = res;
            return res;
        }
    
        int minPathSum(vector<vector<int> > &grid) {
            if (grid.empty()) return 0;
            int m = grid.size();
            if (grid[0].empty()) return 0;
            int n = grid[0].size();
            
            vector<vector<int> > cache(m + 1, vector<int>(n + 1, -1));
            return doMinPathSum(grid, cache, m, n);
        }
    };
}
