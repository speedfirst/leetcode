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
}
