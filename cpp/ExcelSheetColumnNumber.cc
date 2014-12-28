class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int cur = s[i] - 'A';
            res = res * 26 + cur + 1;
        }
        return res;
    }
};
