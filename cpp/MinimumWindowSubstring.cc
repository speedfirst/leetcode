namespace MinimumWindowSubString {
    class Solution {
    public:
        string minWindow(string S, string T) { // Note: T could contain duplicated entries, such as "aab"
            if (T.empty()) return "";
    
            int alphaSet[256];
            fill_n(alphaSet, 256, 0);
            for (int i = 0; i < T.size(); i++) {
                alphaSet[T[i]]++;
            }
    
            int curAlphaSet[256];
            fill_n(curAlphaSet, 256, 0);
    
            int end = 0;
            int start = 0;
            int minStart = 0;
            int minLen = INT_MAX;
            int uniqueCount = 0;
            while (end < S.size()) {
                // move end forward
                char charEnd = S[end];
                if (alphaSet[charEnd] > 0) {
                    curAlphaSet[charEnd]++;
                    if (curAlphaSet[charEnd] <= alphaSet[charEnd]) uniqueCount++;
                    if (uniqueCount == T.size()) {
                        // move forward start
                        
                        while (start <= S.size() - T.size()) {
                            if (minLen > end - start + 1) {
                                minLen = end - start + 1;
                                minStart = start;
                            }
                            char charStart = S[start];
                            if (alphaSet[charStart] > 0) {
                                curAlphaSet[charStart]--;
                                if (curAlphaSet[charStart] < alphaSet[charStart]) {
                                    uniqueCount--;
                                    start++;
                                    break;
                                }
                            }
                            start++;
                        }
                    }
                }
                end++;
            }
    
            return minLen > S.size()? "": S.substr(minStart, minLen);
        }
    };
}
