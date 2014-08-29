// https://oj.leetcode.com/problems/word-break/
namespace WordBreak {
    class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            
            if (s.length() == 0) {
                return true;
            }
            
            if (dict.size() == 0) {
                return false;
            }
            
            // 1. find the words in dict with min and max length
            unordered_set<string>::const_iterator it = dict.begin();
            int minLen = INT_MAX;
            int maxLen = INT_MIN;
            for (; it != dict.end(); it++) {
                int len = (*it).length();
                if (len < minLen) {
                    minLen = len;
                }
                
                if (len > maxLen) {
                    maxLen = len;
                }
            }
            
            
            // 2. run dp
            bool * dp = new bool[s.length() + 1];
            memset(dp, 0, sizeof(bool) * (s.length() + 1));
            dp[0] = true;
            for (int i = 1; i <= s.length() - minLen + 1; i++) {
                
                if (dp[i - 1]) {
                    for (int len = minLen; len <= maxLen; len++) {
                        int endPos = i + len - 1;
                        if (endPos > s.length()) {
                            break;
                        }
                        
                        if (dp[endPos] == true) {
                            continue;
                        }
                        
                        string str = s.substr(i - 1, len);
                        if (dict.find(str) != dict.end()) {
                            dp[endPos] = true;
                            continue;
                        }
                    }
                }
            }
            
            return dp[s.length()];
        }
    };
}
