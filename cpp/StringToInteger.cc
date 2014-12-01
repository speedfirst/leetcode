// https://oj.leetcode.com/problems/string-to-integer-atoi/
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
        return ('0' <= c && c <= '9') ? true : false;
    }
    
    int maxDiv10 = INT_MAX / 10;
    int maxLastDigit = INT_MAX - INT_MAX / 10 * 10;
    
    int atoi(const char *str) {
        if (str == NULL) return 0;
        int pos = 0;
        do {
            if (!isWhitespace(str[pos])) break;
            pos++;
        } while (true);
        int sign = 1;
        if(str[pos] == '+') {
            pos++;
        } else if (str[pos] == '-') {
            sign = -1;
            pos++;
        } else if (!isNum(str[pos])) {
            return 0;
        }

        int num = 0;
        do {
            if (!isNum(str[pos])) return num * sign;
            int digit = str[pos] - '0';
            if (num > maxDiv10 || (num == maxDiv10 && digit > maxLastDigit)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            num = num * 10 + digit;
            pos++;
        } while (true);
        
        return num * sign;
    }
};
