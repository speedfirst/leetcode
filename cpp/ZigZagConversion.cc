namespace ZigZagConversion {
    class Solution {
    public:
        string convert(string s, int nRows) {
            if (nRows <= 1) {
                return s; // zigzag needs at least 2 rows
            }
            
            int period = 2 * nRows - 2;
            int n = s.size();
            string res("");
            for (int i = 0; i < nRows; i++) {
                for (int j = i; j < n; j += period) {
                    res += s[j]; // period 1, effective on every row
                    
                    // period 2, only effective in non-first and non-last rows
                    if (i > 0 && i < nRows - 1 && j + period - 2 * i < n) {
                        res += s[j + period - 2 * i];
                    }
                }
            }
            
            return res;
        }
    };
}
