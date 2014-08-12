namespace ValidParentheses {
    class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '(' || c == '[' || c == '{') {
                    st.push(c);
                } else {
                    if (st.empty()) {
                        return false;
                    }
                    char left = st.top();
                    st.pop();
                    if (c == ')' && left != '(' ||
                        c == ']' && left != '[' ||
                        c == '}' && left != '{') {
                            return false;
                    }
                }
            }
            
            if (st.empty()) {
                return true;
            } else {
                return false;
            }
        }
    };
}
