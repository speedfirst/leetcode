namespace StringToInteger {
    class Solution {
    public:

        bool isWhitespace(char c) {
            if (c == ' ' ||
                c == '\r' ||
                c == '\n' ||
                c == '\t') {
                return true;
            } else {
                return false;
            }
        }
        
        bool isNum(char c) {
            if ('0' <= c && c <= '9') {
                return true;
            } else {
                return false;
            }
        }
        
        bool isPosOrNeg(char c) {
            if (c == '+' || c == '-') {
                return true;
            } else {
                return false;
            }
        }

        int genResult(int res, bool isNeg) {
            if (res < 0) {
                // overflow
                if (isNeg) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            } 
            
            if (isNeg) {
                res *= -1;
            }
            
            return res;
        }
        
        int genOverflowResult(bool isNeg) {
            if (isNeg) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        
        int atoi(const char *str) {
            int res = 0;
            if (str == NULL) {
                return res;
            }
            
            int len = strlen(str);
            if (len == 0) {
                return res;
            }
            
            const int stat_prenum = 0;
            const int stat_posneg = 1;
            const int stat_num = 2; 
            const int threshold = INT_MAX / 10; // for overflow detection
            
            int st = stat_prenum;
            int i = 0;
            bool isNeg = false;
            while (i < len) {
                char c = str[i];
                switch (st) {
                    case stat_prenum:
                        if (isWhitespace(c)) {i++; continue;}
                        else if (isPosOrNeg(c)) {st = stat_posneg; isNeg = (c == '-'); i++; continue;}
                        else if (isNum(c)) {st = stat_num; res = (c - '0'); i++; continue;}
                        else {return res;}
                        break;
                    case stat_posneg:
                        if (isNum(c)) {st = stat_num; res = (c - '0'); i++; continue;}
                        else {return res;}
                        break;
                    case stat_num:
                        if (isNum(c)) {
                            // judge overflow
                            if (threshold < res ) {
                                return genOverflowResult(isNeg);
                            }
                            res *= 10;
                            res += (c - '0');
                            if (res < 0) { 
                                // judge overlfow again
                                // you can't judge overflow only by judging it's negative or not
                                // because an overlfowed number after * 10
                                // might still be positive. This is why we use "threshold" above.
                                return genOverflowResult(isNeg);
                            }
                            i++;
                            continue;}
                        else { return genResult(res, isNeg);}
                        break;
                    default:
                        break;
                        // do nothing
                }
            }
            
            return genResult(res, isNeg);
        }
    };
}