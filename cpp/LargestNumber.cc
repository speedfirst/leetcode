
class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> strs;
        for (auto i: num) {
            strs.push_back(to_string(i));
        }
        
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) { return s1 + s2 > s2 + s1;}); // note we want desc order
        string res = "";
        int i = 0; // ignore leading 0s
        while (i < strs.size() && strs[i] == "0") {
            i++;
        }
        
        // if all "0", ...
        if (i == strs.size()) {
            return "0";
        }
        
        for (; i < strs.size(); i++) {
            res += strs[i];
        }
    
        return res;
    }
};
