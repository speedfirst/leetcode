// https://oj.leetcode.com/problems/reverse-words-in-a-string-ii/
class Solution {
public:
    void reverse(string &s, int i, int j) {
        while (i < j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
    void reverseWords(string &s) {
        reverse(s, 0, s.size() - 1);
        int start = 0;
        int end = 1;
        while (end < s.size()) {
            if (s[end] == ' ')  {
                reverse(s, start, end - 1);
                while (end < s.size() && s[end] == ' ') {
                    end++;
                }
                start = end;
            } else {
                end++;
            }
        }
        
        if (start < s.size()) { // do last reverse
            reverse(s, start, end - 1);
        }
    }
};
