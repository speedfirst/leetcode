namepsace PalindromePartitioning2 {
	class Solution {
	public:
	    // This is a double dp solution.
	    // The first dp is to calculate the min cuts. dp[i] = min(dp[j + 1] + 1), given i <= j < n
	    // The second dp is to calculate whether a sub string s[i, j] is a palindrome.
	    // p[i][j] == p[i + 1][j - 1] && s[i] == s[j]
	    //
	    // I tried model the first solution with a 2D dp, but get TIME LIMIT EXCEEDED error
	    int minCut(string s) {
	        if (s.empty() || s.size() == 1) {
	            return 0;
	        }
	        
	        int n = s.size();

	        // dp[i] is the min cuts of sub-string s[i, n)
	        vector<int> dp(s.size() + 1);
	        for (int i = 0; i <= n; i++) {
	            // assume the min cuts is to cut the sub string to single characters
	            // so dp[n - 1] = 0, dp[n - 2] = 1, ...
	            // dp[n] is special, we set it to -1. This is real important because
	            // our dp formula is dp[i] = min(dp[j + 1] + 1). When the whole string
	            // is a palindrome, we will get dp[i] = dp[n] + 1. And here dp[i] should
	            // be 0!
	            dp[i] = n - i - 1;
	        }
	        
	        // p[i][j] indicates whether sub-string s[i, j] is a palindrome 
	        vector<vector<bool> > p(s.size(), vector<bool>(s.size(), false));
	        
	        // scan from the end of string to beginning
	        for (int i = n - 1; i >= 0; i--) {
	            for (int j = i; j < n; j++) {
	                if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
	                    // s[i, j] is panlindrome
	                    p[i][j] = true;
	                    // so we cut from s[i, j] and s[j + 1, n)
	                    dp[i] = min(dp[i], dp[j + 1] + 1);
	                }
	            }
	        }
	        
	        return dp[0];
	    }
	};
}