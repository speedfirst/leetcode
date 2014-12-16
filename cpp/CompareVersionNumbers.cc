// https://oj.leetcode.com/problems/compare-version-numbers/

class Solution {
public:

    vector<int> splitVer(string s) {
        int i = 0;
        vector<int> res;
        int ver = 0;
        while (i < s.size()) {
            char c = s[i];
            if (c == '.') {
                res.push_back(ver);
                ver = 0;
            } else {
                ver = ver * 10 + (c - '0'); 
            }
            i++;
        }
        res.push_back(ver);
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> ver1s = splitVer(version1);
        vector<int> ver2s = splitVer(version2);
        int i = 0;
        while (i < min(ver1s.size(), ver2s.size())) {
            if (ver1s[i] > ver2s[i]) return 1;
            if (ver1s[i] < ver2s[i]) return -1;
            i++;
        }
        
        // special case "1.0" == "1"
        for(; i < ver1s.size(); i++) if (ver1s[i] > 0) return 1;
        for(; i < ver2s.size(); i++) if (ver2s[i] > 0) return -1;
        return 0;
    }
};
