namespace SubstringWithConcatenationOfAllWords {
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) {
            return res;
        }
        
        unordered_map<string, int> map;
        for (int k = 0; k < L.size(); k++) {
            map[L[k]]++; // Note there might be duplicated items in L, so you can't simply set 1 here
        }
        int num = L.size();
        int len = L[0].size();
        int i = 0;
        while (i + num * len  - 1 < S.size()) {
            
            int j = 0;
            unordered_map<string, int> map2;
            while (j < num) {
                string cur = S.substr(i + j * len, len);   
                if (map.find(cur) == map.end()) {
                    break; // not found, reset 
                } else {
                    map2[cur]++;
                    if (map2[cur] > map[cur]) {
                        break; // occur more than once
                    }
                }
                j++;
            }
            if (j == num) {
                res.push_back(i);
            }
            i++;
        }
        
        return res;
    }
};
}
