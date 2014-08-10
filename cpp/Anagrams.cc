namespace Anagrams {
    // Anagrams definition:
    // if first string contains k1 * c1, k2 * c2, k3 * c3, ...
    // second string contains j1 * c1, j2 * c2, j3 * c3, ...
    // where c1, c2, c3, ... are different characters
    // if k1 == j1 && k2 == j2 && k3 == j3, ...
    // we say these 2 strings are anagrams to each other
    // 
    // if you sort characters of each string belonging to one anagram, the sort result are same
    class Solution {
    public:
        
        vector<string> anagrams(vector<string> &strs) {
            vector<string> res;
            unordered_map<string, int> map; //key is the string with sorted characters, value is the first index of such string
            for (int i = 0; i < strs.size(); i++) {
                string s = strs[i];
                sort(s.begin(), s.end());
                if (map.find(s) == map.end()) {
                    // first occurance, put it in the map
                    map[s] = i;
                } else {
                    // find such string more than once, put it the result
                    res.push_back(strs[i]);
                    int pos = map[s];
                    if (pos != -1) {
                        res.push_back(strs[pos]);
                        map[s] = -1; // mark the first string in map's pos "-1" to avoid it to be added to the result again
                    }
                }
            }
            
            return res;
        }
    };
}
