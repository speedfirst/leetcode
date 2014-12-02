// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int arr[256];
        memset(arr, -1, sizeof(arr));
        int curPos = 0;
        int startPos = 0;
        int maxLen = 0;
        while (curPos < s.size()) {
            char c = s[curPos];
            if (arr[c] >= startPos) {
                startPos = arr[c] + 1;
            }
            arr[c] = curPos;
            maxLen = max(maxLen, curPos - startPos + 1);
            curPos++;
        }
        
        return maxLen;
    }

};
