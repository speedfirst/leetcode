// https://oj.leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() == 0 || s.size() == 1) return s.size();

        int num[256];
        memset(num, 0, sizeof(num));

        int start = 0;
        int end = -1;
        int maxLen = 0;
        int distinctCount = 0;
        while (true) {
            while (distinctCount <= 2) {
                maxLen = max(maxLen, end - start + 1);
                end++;
                if (end == s.size()) break;
                char c = s[end];
                num[c]++;
                if (num[c] == 1) { // 0 --> 1
                    distinctCount++;
                }
            }

            if (end == s.size()) break;

            while (distinctCount > 2) {
                char c = s[start];
                num[c]--;
                if (num[c] == 0) { // 1 --> 0
                    distinctCount--;
                }
                start++;
            }
        }
        return maxLen;
    }
};
