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
    class Solution2 {
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
    
    // Manacher’s Algorithm, time complexity is O(n), space complexity is O(n)
    class Solution3 {
    public:

        // Transform S into T.
        // For example, S = "abba", T = "^#a#b#b#a#$".
        // ^ and $ signs are sentinels appended to each end to avoid bounds checking
        string preProcess(string s) {
            int n = s.length();
            if (n == 0) return "^$";
            string ret = "^";
            for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
         
            ret += "#$";
            return ret;
        }
         
        string longestPalindrome(string s) {
            string T = preProcess(s);
            int n = T.length();
            int *P = new int[n];
            int C = 0, R = 0;
            for (int i = 1; i < n-1; i++) {
                int i_mirror = 2*C-i; // equals to i' = C - (i-C)
            
                P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            
                // Attempt to expand palindrome centered at i
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
         
                // If palindrome centered at i expand past R,
                // adjust center based on expanded palindrome.
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
         
            // Find the maximum element in P.
            int maxLen = 0;
            int centerIndex = 0;
            for (int i = 1; i < n-1; i++) {
                if (P[i] > maxLen) {
                    maxLen = P[i];
                    centerIndex = i;
                }
            }
            delete[] P;
          
            return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
        }
    };
}
  
