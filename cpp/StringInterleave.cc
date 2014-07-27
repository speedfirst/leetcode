namespace StringInterleave {

    // This is a recursion-based search method, which will get TIME LIMIT EXCEEDED error
    class Solution2 {
    public:
        bool checkIsInterleave(string& s1, int idx1, string& s2, int idx2, string& s3, int idx3) {
            if (idx1 == s1.size() && s3.substr(idx3) == s2.substr(idx2)) {
                return true;
            }
            
            if (idx2 == s2.size() && s3.substr(idx3) == s1.substr(idx1)) {
                return true;
            }
            
            if (s3[idx3] == s1[idx1]) {
                // try match from string 1
                bool res = checkIsInterleave(s1, idx1 + 1, s2, idx2, s3, idx3 + 1);
                if (res) { return res;}
            }
            
            if (s3[idx3] == s2[idx2]) {
                // try match from string 2
                bool res = checkIsInterleave(s1, idx1, s2, idx2 + 1, s3, idx3 + 1);
                if (res) { return res;}
            }
            
            return false;
        }
        
        bool isInterleave(string s1, string s2, string s3) {
            if (s3.size() != s1.size() + s2.size()) {
                return false;
            }
            
            return checkIsInterleave(s1, 0, s2, 0, s3, 0);
        }
    };

    // This is the DP solution
    class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if (s1.size() + s2.size() != s3.size()) {
                return false;
            }

            // dp[i][j] = true means s3[0, i + j] is matched by s1[0, i] and s2[0, j]
            vector<vector<bool> > dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

            // initialize dp
            dp[0][0] = true;
            for (int i = 1; i <= s1.size(); i++) {
                dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
            }

            for (int j = 1; j <= s2.size(); j++) {
                dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
            }

            // do dp
            for (int i = 1; i <= s1.size(); i++) {
                for (int j = 1; j <= s2.size(); j++) {
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
                }
            }

            return dp[s1.size()][s2.size()];
        }
    };
}