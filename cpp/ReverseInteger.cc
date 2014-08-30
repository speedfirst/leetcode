// https://oj.leetcode.com/problems/reverse-integer/
namespace ReverseInteger {
    class Solution {
    public:
        int reverse(int x) {
            
            int symbol = 1;
            if (x < 0) {
                symbol = -1;
            }
            
            x = abs(x);
            int res = 0;
            while (x > 0) {
                res *= 10;
                res += (x % 10);
                x /= 10;
            }
            
            return symbol * res;
            
        }
    };
}
