// https://oj.leetcode.com/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        do {
           n--; // change the range from 1~26 to 0~25, make everything easier
           int digit = n % 26;
           res = (char (digit + 'A')) + res;
           n /= 26;
        } while(n != 0);
        return res;
    }
};
