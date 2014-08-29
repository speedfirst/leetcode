// https://oj.leetcode.com/problems/reverse-words-in-a-string/
namespace EvaluateReversePolishNotation {
    class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            if (tokens.empty()) {
                return 0;
            }
            
            stack<int> S;
            int i = 0;
            // assume the input tokesn are always valid Reverse Polish Notation expression
            while (i < tokens.size()) {
                string cur = tokens[i];
                if (('0' <= cur[0] && cur[0] <= '9') || cur.size() > 1) {
                    int num = atoi(cur.c_str());
                    S.push(num);
                } else {
                    int op2 = S.top();
                    S.pop();
                    int op1 = S.top(); // note op1 is the number put to S ealier
                    S.pop();
                    int res;
                    if (cur == "+") {
                        res = op1 + op2;
                    } else if (cur == "-") {
                        res = op1 - op2;
                    } else if (cur == "*") {
                        res = op1 * op2;
                    } else if (cur == "/") {
                        res = op1 / op2;
                    }
                    S.push(res);
                }
                i++;
            }
            return S.top();
        }
    };
}
