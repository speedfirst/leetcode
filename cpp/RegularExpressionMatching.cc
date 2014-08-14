namespace RegularExpressionMatching {
    class Solution {
    public:
        bool checkIsMatch(const char *s, int posS, const char * p, int posP) {
            if (s[posS] == '\0' && p[posP] == '\0') { // sample case: s="", p=""
                return true;
            }
            
            if (s[posS] == '\0' && p[posP] != '\0') {
                if (p[posP + 1] == '*') { // sample case: s="", p="c*a*"
                    return checkIsMatch(s, posS, p, posP + 2);
                } else {
                    return false; // sample case: s="", p="a"
                }
            }
            
            if (s[posS] != '\0' && p[posP] == '\0') {
                return false; // sample case: s="abc", p=""
            }
            
            if (p[posP + 1] == '*') {
                bool res = checkIsMatch(s, posS, p, posP + 2);
                if (res) return res;
                
                int i = 1;
                if (p[posP] != '.' && p[posP] == s[posS]) { // sample case: s="aaaab", p="a*b"
                    while (s[posS + i] == s[posS]) {
                        bool res = checkIsMatch(s, posS + i, p, posP + 2);
                        if (res) {
                            return res;
                        }
                        i++;
                    }
                } else if (p[posP] == '.') { // sample case: s="abcde", p=".*e"
                    while (s[posS + i] != '\0') {
                        bool res = checkIsMatch(s, posS + i, p, posP + 2);
                        if (res) {
                            return res;
                        }
                        i++;
                    }
                } else {
                    return false; // sample case: s="abcde", p="d*e"
                }
                return checkIsMatch(s, posS + i, p, posP + 2);
            } else {
                if (s[posS] == p[posP] || p[posP] == '.') { // sample case: s="abcde", p=".bcde" or s="abcde", p="abcde"
                    return checkIsMatch(s, posS + 1, p, posP + 1);
                } else {
                    return false;
                }
            }
        }
        
        bool isMatch(const char *s, const char *p) {
            if (s == NULL || p == NULL) {
                return false;
            }
            
            return checkIsMatch(s, 0, p, 0);
        }
    };
}
