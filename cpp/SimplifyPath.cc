namespace SimplifyPath {
    class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> st;
            int pos = 0;
            while (pos < path.size()) {
                int end = path.find('/', pos + 1);
                if (end == -1) {
                    end = path.size();
                }
                string sec(path.begin() + pos + 1, path.begin() + end);
                if (sec == "") {
                    // do nothing;
                } else if (sec == ".") {
                    // do nothing;
                } else if (sec == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(sec);
                }
                pos = end;
            }
    
            vector<string> res;
            while (!st.empty()) {
                res.push_back(st.top());
                st.pop();
                res.push_back("/");
            }
    
            if (res.empty()) {
                return "/";
            }
    
            string resStr = "";
            for (vector<string>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
                resStr += (*it);
            }
    
            return resStr;
        }
    };
}
