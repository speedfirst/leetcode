// https://oj.leetcode.com/problems/word-break-ii/
// solution based on 1-D dp
class Solution {
public:
    void genStrings(string &s, vector<vector<int> > &bt, int cur, vector<string>& res, string curstr) {
        if (cur == 0) {
            res.push_back(curstr);
            return;
        }

        vector<int> preIdxs = bt[cur];
        for (int i = 0; i < preIdxs.size(); i++) {
            genStrings(s, bt, preIdxs[i], res, s.substr(preIdxs[i], cur - preIdxs[i]) + " " + curstr);
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size() + 1, false);
        vector<vector<int> > bt(s.size() + 1, vector<int>());
        dp[0] = true;
        bt[0].push_back(-1); // mark end
        for (int i = 1 ; i <= s.size(); i++) {
            if (dp[i - 1]) {
                for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
                    const string& word = *it;
                    if (i + word.size() - 1 <= s.size() && s.substr(i - 1, word.size()) == word) {
                        dp[i + word.size() - 1] = true;
                        bt[i + word.size() - 1].push_back(i - 1);
                    }
                }
            }
        }

        // generate result by backtrace
        vector<string> res;
        string curstr = "";
        vector<int> preIdxs = bt[s.size()];
        for (int i = 0; i < preIdxs.size(); i++) {
            genStrings(s, bt, preIdxs[i], res, s.substr(preIdxs[i], s.size() - preIdxs[i]));
        }
        return res;
    }
};
