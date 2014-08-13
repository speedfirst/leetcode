namespace LongestSubstringWithoutRepeatingCharacters {
    class Solution {
    public:
        // complexity worst O(2n)
        int lengthOfLongestSubstring(string s) {
            int appearedPos[256]; // we assume the character range is 0 ~ 255
            memset(appearedPos, -1, 256 * sizeof(int));
            
            int i = 0;
            int len = 0;
            int maxLen = 0;
            while (i < s.size()) {
                char c = s[i];
                int pos = appearedPos[c];
                if (pos == -1) {
                    // this char hasn't appeared
                    appearedPos[c] = i;
                    i++;
                    len++;
                } else {
                    // this char has appeared, reset
                    i = pos + 1;
                    if (len > maxLen) {
                        maxLen = len;
                    }
                    len = 0;
                    memset(appearedPos, -1, 256 * sizeof(int));
                }
            }
            
            return max(len, maxLen);
        }
    };
}
