// https://oj.leetcode.com/problems/plus-one/
namespace PlusOne {
    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            
            int v = 1;
            for (int i = digits.size() - 1; i >= 0; i--) {
                v += digits[i];
                if (v < 10) {
                    digits[i] = v;
                    v = 0;
                    break;
                } else {
                    digits[i] = v % 10;
                    v = 1;
                }
            }
            
            if (v == 1) {
                digits.insert(digits.begin(), v);
            }
            
            return digits;
            
        }
    };
}
