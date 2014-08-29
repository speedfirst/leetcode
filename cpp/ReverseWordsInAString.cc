// https://oj.leetcode.com/problems/reverse-words-in-a-string/
namespace ReverseWordsInAString {
    class Solution {
    public:
        void reverseWords(string &s) {
            if (s.length() == 0) {
                return;
            }
            string rs;
            for (int i = s.length() - 1; i >= 0; i--) {
                
                // ignore the white space
                while (i >= 0 && s[i] == ' ') i--;
                if (i < 0) {
                    break;
                }
                string t;
                while (i >= 0 && s[i] != ' ') t.push_back(s[i--]);
                reverse(t.begin(), t.end());
                
                if (!rs.empty()) {
                    rs.push_back(' ');
                }
                
                rs.append(t);
                
            }
            
            s = rs;
            
        }
    };
}
