namespace GenerateParentheses {
    class Solution {
    public:
        void doGen(int n, int numLeft, int numRight, vector<string>& res, string& cur) {
            if (numRight == n) {
                res.push_back(cur);
                return;
            }
            
            if (numLeft < n) {
                cur += "(";
                doGen(n, numLeft + 1, numRight, res, cur);
                cur.resize(cur.size() - 1);
            }
            
            if (numRight < numLeft) {
                cur += ")";
                doGen(n, numLeft, numRight + 1, res, cur);
                cur.resize(cur.size() - 1);
            }
        }
        
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            string cur("");
            if (n == 0) return res;
            doGen(n, 0, 0, res, cur);
            return res;
        }
    };
}
