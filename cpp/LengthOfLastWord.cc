namespace LenghOfLastWord {
    class Solution {
    public:
        // test case:
        // ""
        // " "
        // "   "
        // "a"
        // "a b"
        // "a   "
        // "a  b  "
        int lengthOfLastWord(const char *s) {
            
            if (s == NULL) {
                return 0;
            }
            
            int start = -1; // mark the last space before a word
            int end = -1; // mark the last character of a word
            int i = 0;
            while(s[i] != '\0') {
                if (s[i] == ' ' && s[i + 1] != '\0' && s[i + 1] != ' ') {
                    start = i;
                } else if (s[i] != ' ' && (s[i + 1] == '\0' || s[i + 1] == ' ')) {
                    end = i;
                }
                i++;
            }
            return end - start;
            
        }
    };
}
