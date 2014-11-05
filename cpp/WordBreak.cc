// https://oj.leetcode.com/problems/word-break/
namespace WordBreak {
    class Solution {
    public:
        pair<int, int> findMinLenAndMaxLen(unordered_set<string> &dict) {
            int minLen = INT_MAX;
            int maxLen = INT_MIN;
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
                const string & cur = *it;
                minLen = min((int)cur.size(), minLen);
                maxLen = max((int)cur.size(), maxLen);
            }
            return make_pair(minLen, maxLen);
        }
        
        bool wordBreak(string s, unordered_set<string> &dict) {
            if (s.empty()) return false;
            if (dict.empty()) return false;
            
            pair<int, int> m = findMinLenAndMaxLen(dict);
            int minLen = m.first;
            int maxLen = m.second;
            vector<bool> dp = vector<bool>(s.size() + 1, false);
            dp[0] = true;
            for (int i = 1; i <= s.size(); i++) {
                if (!dp[i - 1]) continue;
                for (int len = minLen; len <= maxLen; len++) {
                    if (i + len - 1 > s.size()) break;
                    string cur = s.substr(i - 1, len);
                    if (dict.find(cur) != dict.end()) {
                        dp[i + len - 1] = true;
                    }
                }
            }
            
            return dp[s.size()];
        }
    };
}
