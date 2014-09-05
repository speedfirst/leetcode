// https://oj.leetcode.com/problems/valid-number/
// Validate if a given string is numeric.

// Some examples:
//   "0" => true
//   " 0.1 " => true
//   "abc" => false
//   "1 a" => false
//   "2e10" => true

namespace ValidNumber {
    class Solution {
    public:
        bool isWhiteSpace(char c) {
            return (c == ' ' || c == '\t');
        }
        
        bool isSymbol(char c) {
            return (c == '+' || c == '-');
        }
        
        bool isNum(char c) {
            return ('0' <= c && c <= '9');
        }
        
        bool isE(char c) {
            return (c == 'e' || c == 'E');
        }
        
        bool isNumber(const char *s) {
            enum State {
                START,
                SPACE_PREFIX,
                SYMBOL,
                NUM,
                DOT,
                DOT_WITH_NO_NUM, // Note we have to handle two cases of ".", one is there have been numbers before it (DOT); another is not (DOT_WITH_NO_NUM)
                NUM_AFTER_DOT,
                E,
                E_SYMBOL,
                NUM_AFTER_E,
                SPACE_SUFFIX
            };
            
            
            if (s == NULL) return false;
            int i = 0;
            State state = START;
    
            while (s[i] != '\0') {
                char c = s[i];
                switch (state) {
                    case START:
                        if (isWhiteSpace(c)) state = SPACE_PREFIX;
                        else if (isSymbol(c)) state = SYMBOL;
                        else if (isNum(c)) state = NUM;
                        else if (c == '.') state = DOT_WITH_NO_NUM;
                        else return false;
                        break;
                    case SPACE_PREFIX:
                        if (isWhiteSpace(c)) { /* do nothing */ }
                        else if (isSymbol(c)) state = SYMBOL;
                        else if (isNum(c)) state = NUM;
                        else if (c == '.') state = DOT_WITH_NO_NUM;
                        else return false;
                        break;
                    case SYMBOL:
                        if (isNum(c)) state = NUM;
                        else if (c == '.') state = DOT_WITH_NO_NUM;
                        else return false;
                        break;
                    case NUM:
                        if (c == '.') state = DOT;
                        else if (isNum(c)) { /* do nothing */ }
                        else if (isE(c)) state = E;
                        else if (isWhiteSpace(c)) state = SPACE_SUFFIX;
                        else return false;
                        break;
                    case DOT:
                        if (isNum(c)) state = NUM_AFTER_DOT;
                        else if (isWhiteSpace(c)) state = SPACE_SUFFIX;
                        else if (isE(c)) state = E;
                        else return false;
                        break;
                    case DOT_WITH_NO_NUM:
                        if (isNum(c)) state = NUM_AFTER_DOT;
                        else return false;
                        break;
                    case NUM_AFTER_DOT:
                        if (isNum(c)) { /* do nothing */ }
                        else if (isE(c)) state = E;
                        else if (isWhiteSpace(c)) state = SPACE_SUFFIX;
                        else return false;
                        break;
                    case E:
                        if (isNum(c)) state = NUM_AFTER_E;
                        else if (isSymbol(c)) state = E_SYMBOL;
                        else return false;
                        break;
                    case E_SYMBOL:
                        if (isNum(c)) state = NUM_AFTER_E;
                        else return false;
                        break;
                    case NUM_AFTER_E:
                        if (isNum(c)) { /* do nothing */ }
                        else if (isWhiteSpace(c)) state = SPACE_SUFFIX;
                        else return false;
                        break;
                    case SPACE_SUFFIX:
                        if (isWhiteSpace(c)) { /* do nothing */ }
                        else return false;
                        break;
                    default:
                        return false;
                        
                }
                i++;
            }
            
            return (state == NUM ||
                    state == NUM_AFTER_DOT ||
                    state == NUM_AFTER_E ||
                    state == SPACE_SUFFIX ||
                    state == DOT);
            
        }
    };
}
