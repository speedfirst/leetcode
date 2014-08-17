namespace LetterCombinationsOfAPhoneNumber {
    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> res;
            
            unordered_map<char, vector<char>> m;
            m['0'] = vector<char>();
            m['1'] = vector<char>();
            
            char charsFor2[] = {'a', 'b', 'c'};
            m['2'] = vector<char>(charsFor2, charsFor2 + 3);
            
            char charsFor3[] = {'d', 'e', 'f'};
            m['3'] = vector<char>(charsFor3, charsFor3+ 3);
            
            char charsFor4[] = {'g', 'h', 'i'};
            m['4'] = vector<char>(charsFor4, charsFor4 + 3);
            
            char charsFor5[] = {'j', 'k', 'l'};
            m['5'] = vector<char>(charsFor5, charsFor5 + 3);
            
            char charsFor6[] = {'m', 'n', 'o'};
            m['6'] = vector<char>(charsFor6, charsFor6 + 3);
            
            char charsFor7[] = {'p', 'q', 'r', 's'};
            m['7'] = vector<char>(charsFor7, charsFor7 + 4);
            
            char charsFor8[] = {'t', 'u', 'v'};
            m['8'] = vector<char>(charsFor8, charsFor8 + 3);
            
            char charsFor9[] = {'w', 'x', 'y', 'z'};
            m['9'] = vector<char>(charsFor9, charsFor9 + 4);
            
            res.push_back("");
            for (int i = 0; i < digits.size(); i++) {
                char d = digits[i];
                vector<char> chars = m[d];
                int n = res.size();
                for (int j = 0; j < n; j++) {
                    string s = res.front();
                    for (int k = 0; k < chars.size(); k++) {
                        s.push_back(chars[k]);
                        res.push_back(s);
                        s.pop_back();
                    }
                    res.erase(res.begin()); // pop front
                }
            }
            
            return res;
            
        }
    };
}
