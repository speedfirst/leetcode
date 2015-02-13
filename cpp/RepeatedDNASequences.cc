//  https://oj.leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    int getKey(string &s, int start, int end) {
        int sum = 0;
        for (int i = start; i < end; i++) {
            switch (s[i]) {
                case 'A':
                    sum = sum * 10 + 0;
                    break;
                case 'T':
                    sum = sum * 10 + 1;
                    break;
                case 'G':
                    sum = sum * 10 + 2;
                    break;
                case 'C':
                    sum = sum * 10 + 3;
                    break;
                default:
                    return -1;
            }
        }
        
        return sum;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;

        if (s.size() < 10) {
            return res;
        }
        unordered_map<int, int> map;
        for (int i = 0; i < s.size() - 9; i++) {
            int key = getKey(s, i, i + 10);
            if (map.find(key) != map.end()) {
                if (map[key] == 1) {
                    res.push_back(s.substr(i, 10));
                    map[key] = -1;
                }
            } else {
                map[key] = 1;
            }
        }
        
        return res;
    }
};
