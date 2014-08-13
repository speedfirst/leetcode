namespace LongestPalindromicSubstring {
    
    // this is a dp solution, complexity is O(n^2)
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
}
  
