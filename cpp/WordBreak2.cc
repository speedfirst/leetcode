namespace WorkBreak2 {
  class Solution {
  public:
      
      void findall(vector<vector<int> > &prevs, int endPos, string s, vector<string> &res, string curStr) {
          
          if (endPos == 0) {
              res.push_back(curStr);
              return;
          }
          
          vector<int> & prev = prevs[endPos];
          
          for (vector<int>::iterator it = prev.begin(); it != prev.end(); it++) {
              int prevPos = *it;
              string str = s.substr(prevPos, endPos - prevPos);
              
              string origStr = curStr;
              if (curStr != "") {
                  curStr = str + " " + curStr;
              } else {
                  curStr = str;
                  
              }
              findall(prevs, prevPos, s, res, curStr);
              curStr = origStr;
          }
      }
      
      
      vector<string> wordBreak(string s, unordered_set<string> &dict) {
          
          vector<string> res;
          if (s.empty() || dict.empty()) {
              return res;
          }
          int minLen = INT_MAX;
          int maxLen = 0;
          
          for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
              string str = *it;
              if (str.length() > maxLen) {
                  maxLen = str.length();
              }
              
              if (str.length() < minLen) {
                  minLen = str.length();
              }
          }
          
          int strlen = s.length();
          vector<bool> dp(strlen + 1);
          dp[0] = true;
          vector<vector<int> > prevs(strlen + 1);
          for (int i = 1; i <= strlen; i++) {
              if (dp[i - 1] == false) {
                  continue;
              }
              
              for (int len = minLen; len <= maxLen; len++) {
                  int endPos = i + len;
                  if (endPos > strlen + 1) {
                      break;
                  }
                  
                  string subStr = s.substr(i - 1, len);
                  if (dict.find(subStr) != dict.end()) {
                      dp[endPos - 1] = true;
                      prevs[endPos - 1].push_back(i - 1);
                  }
              }
          }
          
          // can't be break properly
          if (dp[strlen] == false) {
              return res;
          }
          
          findall(prevs, strlen, s, res, "");
          return res;
          
      }
  };
}
