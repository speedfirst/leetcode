// https://oj.leetcode.com/problems/integer-to-roman/
namespaceIntegerToRoman {
    class Solution {
    public:
    
        static const int n[]; 
        static const string r[]; 
        string intToRoman(int num) {
            
            string res = "";
            int i = 0;
            while (num > 0) {
                
                while (num >= n[i]) {
                    res += r[i];
                    num -= n[i];
                }
                
                i++;
            }
            
            return res;
            
        }
    };
    
    const int Solution::n[] ={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string Solution::r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
}
