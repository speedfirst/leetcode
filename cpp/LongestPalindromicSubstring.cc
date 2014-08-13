namespace LongestPalindromicSubstring {
    
    // this is a dp solution, both time and space complexity are O(n^2)
    class Solution1 {
    public:
        string longestPalindrome(string s) {
            
            int len = s.size();  
            bool dp[len][len];  
            memset(dp, 0, len * len * sizeof(bool));  
            int maxL = 0, start = 0, end = 0;  
            for(int i = 0; i< len; i++) {  
                for(int j = 0; j < i; j++) {  
                    dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]));  
                    if(dp[j][i] && maxL < (i - j + 1)) {  
                        maxL = i - j + 1;  
                        start = j;  
                        end = i;  
                    }  
                }  
                dp[i][i] =1;  
            }  
            return s.substr(start, end - start + 1);  
        }
    };
    
    
    // This solution enumerates every possible center and try to expand it to a palindrome
    // time complexity is O(n^2), space complexity is O(1)
    class Solution {
    public:

        // search palindrome from a center
        void searchPalindrome(string& s, int startPos1, int startPos2, int& start, int& end) {
            int i = startPos1, j = startPos2;
            while (i >= 0 && j < s.size()) {
                if (s[i] == s[j]) {
                    i--;
                    j++;
                } else {
                    break;
                }
            }
            start = (i + 1);
            end = (j - 1);
        }
        
        string longestPalindrome(string s) {
            if (s.empty()) return s;
            int start, end;
            int maxStart = 0, maxEnd = 0;
            for (int i = 0; i < s.size(); i++) {
                searchPalindrome(s, i, i, start, end); // try search by center s[i]
                if (end - start > maxEnd - maxStart) {
                    maxStart = start;
                    maxEnd = end;
                }
                
                searchPalindrome(s, i, i + 1, start, end); // try search by gap between s[i], s[i + 1]
                if (end - start > maxEnd - maxStart) {
                    maxStart = start;
                    maxEnd = end;
                }
            }
            return s.substr(maxStart, maxEnd - maxStart + 1);  
        }
    };
}
  
