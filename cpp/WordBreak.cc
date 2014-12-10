// https://oj.leetcode.com/problems/word-break/
namespace WordBreak {
    // recursive solution, will Time Limit Exceeded in OJ
    class Solution {
    public:
        bool doWordBreak(string &s, int start, unordered_set<string> &dict) {
            if (start == s.size()) return true;
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
                const string& word = *it;
                if (start + word.size() > s.size()) continue;
                if (s.substr(start, word.size()) == word && doWordBreak(s, start + word.size(), dict)) {
                    return true;
                }
            }
            return false;
        }
        
        bool wordBreak(string s, unordered_set<string> &dict) {
            return doWordBreak(s, 0, dict);
        }
    };
    
    // 1-D DP, time complexity O(n^2), space complexity O(n)
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> dp(s.size() + 1, false);
            dp[0] = true;
            for (int i = 1; i <= s.size(); i++) {
                int len = 1;
                while (i - len >= 0) {
                    if (dp[i - len] && dict.find(s.substr(i - len, len)) != dict.end())  {
                        dp[i] = true;
                        break;
                    }
                    len++;
                }
            }
            
            return dp[s.size()];
        }
    };
    
    // another 1-D dp, cal in different direction
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<bool> dp(s.size() + 1, false);
            dp[0] = true;
            for (int i = 1 ; i <= s.size(); i++) {
                if (dp[i - 1]) {
                    for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
                        const string& word = *it;
                        if (i + word.size() - 1 <= s.size() && s.substr(i - 1, word.size()) == word) {
                            dp[i + word.size() - 1] = true;
                        }
                    }
                }
            }
            return dp[s.size()];
        }
    };
    
    // 2-D dp, time complexity O(n^3), space complexity O(n^2)
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            vector<vector<bool> > dp(s.size(), vector<bool>(s.size() + 1, false));
            dp[0][0] = true;
            for (int len = 1; len <= s.size(); len++) {
                for (int i = 0; i <= s.size() - len; i++) {
                    if (dict.find(s.substr(i, len)) != dict.end()) {
                        dp[i][len] = true;
                        continue;
                    }
                    for (int k = 1; k < len; k++) {
                        if (dp[i][k] && dp[i + k][len - k]) {
                            dp[i][len] = true;
                            break;
                        }
                    }
                }
            }
            return dp[0][s.size()];
        }
    };
}
