namespace ValidPalindrome {
    class Solution {
    public:
        bool isPalindrome(string s) {
            // empty is considered as a valid palindrome
            if (s.empty()) {
                return true;
            }
            
            int i = 0;
            int j = s.size() - 1;
            while (i < j) {
                int ci = getAlpha(s[i]);
                if (ci == 0) {
                    i++;
                    continue;
                }
                
                int cj = getAlpha(s[j]);
                if (cj == 0) {
                    j--;
                    continue;
                }
                
                if (ci != cj) {
                    return false;
                } else {
                    i++;
                    j--;
                }

            }
            
            return true;
            
        }
        
        /**
         * if c is an upper case character, return the lower case charater;
         * if c is an lower case character, return it directly;
         * if c is an numeric character, return it directly;
         * otherwise, return 0
         */
        char getAlpha(char c) {
            if ('a' <= c && c <= 'z') {
                return c;
            }
            
            if ('A' <= c && c <= 'Z') {
                return (c + 'a' - 'A');
            }
            
            if ('0' <= c && c <= '9') {
                return c;
            }
            
            return 0;
        }
    };
}

