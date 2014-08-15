namespace LongestCommonPrefix {
  class Solution {
  public:
      string longestCommonPrefix(vector<string> &strs) {
          if (strs.empty()) {
              return "";
          }
          
          string lcs = strs[0];
          if (strs.size() == 1) {
              return lcs;
          }
          
          for (int i = 0; i < lcs.size(); i++) {
              for (int j = 1; j < strs.size(); j++) {
                  if (i == strs[j].size()) {
                      return lcs.substr(0, i);
                  }
                  if (strs[j][i] != lcs[i]) {
                      return lcs.substr(0, i);
                  }
              }
          }
          
          return lcs;
          
      }
  };
}
