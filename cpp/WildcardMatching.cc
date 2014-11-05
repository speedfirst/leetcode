namespace WildcardMatching {
    class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if (s == NULL && p == NULL) return false;
            int posS = 0;
            int posP = 0;
            int lastStarMatchPosInS = -1;
            int lastStarPosInP = -1;
            
            while (s[posS] != '\0') {
                if (s[posS] == p[posP] || p[posP] == '?') {
                    posS++;
                    posP++;
                    continue;
                } else if (p[posP] == '*') {
                    lastStarMatchPosInS = posS;
                    lastStarPosInP = posP;
                    posP++;
                    continue;
                } else if (lastStarMatchPosInS != -1) {
                    posS = lastStarMatchPosInS;
                    lastStarMatchPosInS++;
                    posP = lastStarPosInP + 1;
                    continue;
                } else {
                    return false;
                }
            }
            
            while(p[posP] == '*') posP++;
            
            return (s[posS] == '\0' && p[posP] == '\0');
        }
    };
    
    // the abbreviated edition
    class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if (s == NULL || p == NULL) return false;
            int ps = 0, pp = 0, lastPs = -1, lastPp = -1;
            while (s[ps] != '\0') {
                if (s[ps] == p[pp] || p[pp] == '?') { ps++; pp++;}
                else if (p[pp] == '*') {lastPs = ps + 1; lastPp = pp; pp++;}
                else if (lastPs != -1) {ps = lastPs; lastPs++; pp = lastPp + 1;} // reset
                else {return false;}
            }
            
            while (p[pp] == '*') pp++; // trim the trailing "*" chars at the end of p
            return s[ps] == '\0' && p[pp] == '\0';
        }
    };
}
