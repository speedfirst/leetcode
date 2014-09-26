/**
 * https://oj.leetcode.com/problems/count-and-say/
 */
namespace CountAndSay {
  class Solution {
  public:
      string countAndSay(int n) {
          if (n == 0) {
              return "";
          }
          
          if (n == 1) {
              return "1";
          }
          
          string s = countAndSay(n - 1);
          
          char curChar = s[0];
          int count = 1;
          int i = 1;
          string res = "";
          while (i < s.size()) {
              if (s[i] == curChar) {
                  count++;
              } else {
                  res += to_string(count);
                  res += curChar;
                  
                  // reset
                  curChar = s[i];
                  count = 1;
              }
              i++;
          }
          res += to_string(count);
          res += curChar;
          return res;
      }
  };
}
