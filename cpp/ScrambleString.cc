namespace ScrambleString {
    // This is the recursive solution
    class Solution1 {
    public:
        bool doIsScramble(const string& s1, int start1, const string& s2, int start2, int len, vector<vector<vector<int> > >&cache) {
            
            if (cache[len][start1][start2] != -1) {
                return cache[len][start1][start2] == 1;
            }
            
            if (len == 0) {
                cache[len][start1][start2] = 1;
                return true;
            }
            
            if (len == 1) {
                bool res = (s1[start1] == s2[start2]);
                cache[len][start1][start2] = res? 1 : 0;
                return res;
            }
            
            for (int i = 1; i < len; i++) {
                if ((doIsScramble(s1, start1, s2, start2, i, cache) && 
                     doIsScramble(s1, start1 + i, s2, start2 + i, len - i, cache)) ||
                    (doIsScramble(s1, start1, s2, start2 + len - i, i, cache) && 
                     doIsScramble(s1, start1 + i, s2, start2, len - i, cache))) {
                    cache[len][start1][start2] = 1;
                    return true;
                }
            }
            
            cache[len][start1][start2] = 0;
            return false;
        }
        
        bool isScramble(string s1, string s2) {
            if (s1.size() != s2.size()) {
                return false;
            }
            
            int len = s1.size();
            
            // without this cache algorithm will exceed time limit
            vector<vector<vector<int> > > cache(len + 1, vector<vector<int> >(len + 1, vector<int>(len + 1, -1)));
            
            return doIsScramble(s1, 0, s2, 0, len, cache);
        }
    };
}
