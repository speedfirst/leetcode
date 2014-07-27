namespace UniqueBinarySearchTree {
	class Solution {
	public:
	    int numTrees(int n) {
	        if (n == 0) {
	            return 0;
	        }
	        
	        vector<int> dp(n + 1, 0);
	        dp[0] = 1;
	        dp[1] = 1;
	        for (int i = 2; i <= n; i++) {
	            int sum = 0;
	            for (int j = 0; j <= i - 1; j++) {
	                sum += dp[j] * dp[i - j - 1];
	            }
	            dp[i] = sum;
	        }
	        return dp[n];
	    }
	};
}