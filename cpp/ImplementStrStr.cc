namespace ImplementStrStr {
    // KMP solution, complexity is O(m + n)
    class Solution {
    public:
    
        // generate "next" pattern data
        void getNext(const char* pattern, int * next){
            next[0] = -1;
            int k = -1, j = 0;
            while(pattern[j] != '\0') {
                if(k!= -1 && pattern[k] != pattern[j] )
                    k = next[k];
                ++j; ++k;
                if(pattern[k]== pattern[j])
                    next[j] = next[k];
                else
                    next[j] = k;
            }
        }
    
        char * strStr(char *haystack, char *needle) {
            if( !haystack || !needle)
                return NULL;
    
            // get needle's length
            int len = 0;
            const char * c = needle;
            while(*c++ != '\0') len++;
    
            // get next pattern
            int *next = new int[len + 1];
            getNext(needle, next);
    
            int matchStart = 0; // the start of match
            int i = 0; // the current match pos in haystack
            int j = 0; // the current match pos in needle
            while(haystack[i] != '\0' && needle[j] != '\0') {
                if(haystack[i] == needle[j]) {
                    ++i; ++j;
                } else {
                    // adjust matchStart, i and j according to "next"
                    matchStart += j - next[j];
                    if(next[j] != -1) {
                        j = next[j];
                    } else {
                        j = 0;
                        ++i;
                    }
                }
            } //while
    
            delete []next;
            if(needle[j] == '\0')
                return (haystack + matchStart); // matched
            else
                return NULL;
        }
    };
}
