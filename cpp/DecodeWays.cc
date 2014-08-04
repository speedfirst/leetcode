namespace DecodeWays {
  class Solution {
  public:
      // judge whether s[i] is matched
      bool isSingleCharMatched(string&s, int i) {
          if ('1' <= s[i] && s[i] <= '9') {
              return true;
          } else {
              return false;
          }
      }
      
      // judge wether s[i] and s[i + 1] is matched
      // note '10' and '20' are also valid match
      bool isTwoCharMatched(string& s, int i) {
          if (s[i] == '1') {
              return true;
          }
          
          if (s[i] == '2' && '0' <= s[i + 1] && s[i + 1] <= '6') {
              return true;
          }
          
          return false;
      }
      
      int numDecodings(string s) {
          if (s.empty()) {
              return 0;
          }
          
          vector<int> dp(s.size() + 1, 0);
          dp[0] = 1;
          if (isSingleCharMatched(s, 0)) {
              dp[1] = 1;
          }
          for (int i = 2; i <= s.size(); i++) {
              if (isSingleCharMatched(s, i - 1)) {
                  dp[i] += dp[i - 1];
              }
              if (isTwoCharMatched(s, i - 2)) {
                  dp[i] += dp[i - 2];
              }
          }
          
          return dp[s.size()];
      }
  };
}
