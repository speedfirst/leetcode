// https://oj.leetcode.com/problems/one-edit-distance/
// Several cases:
// "", "" --> false, because they are exactly same
// "a", "a" --> false, because they are exactly same
// "a", "" --> true
// "a", "ac" --> true
// "a", "A" --> true

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int diff = s.size() - t.size();
        if (diff > 1 || diff < -1) return false;
        bool foundOneDiff = false;
        int i = 0;
        int j = 0;
        
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++; j++;
            } else {
                if (foundOneDiff) return false;
                if (s.size() == t.size()) {
                    i++; j++;
                } else if (s.size() > t.size()) {
                    i++;
                } else {
                    j++;
                }
                foundOneDiff = true;
            }
        }
        
        if (i == s.size() && j == t.size()) return foundOneDiff; // if we just arrive at the ends of both string, return true if there is only one diff found
        if (i == s.size() || j == t.size()) return !foundOneDiff; // if we arrive at the end of just one string, we have to consider the diff due to length difference as another diff.
    }
};
