namespace LongestValidParentheses {
    class Solution {
    public:
        int longestValidParentheses(string s) {
            
            int max = 0;
            stack<int> st;
            int lastInvalidRightParentheses = -1; // assume there is a "hidden" invalid ")" before the start of string
            int i = 0;
            while (i < s.size()) {
                char c = s[i];
                if (c == '(') {
                    st.push(i);
                } else { // ')'
                    if (!st.empty()) {
                        st.pop();
                        int start = st.empty()? lastInvalidRightParentheses: st.top();
                        if (i - start > max) {
                            max = i - start;
                        }
                    } else {
                        lastInvalidRightParentheses = i;
                    }
                }
                i++;
            }
            return max;
            
        }
    };
}
    
