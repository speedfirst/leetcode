namespace MultiplyString {
  
  class Solution {
  public:
    int getLen(string s) {
        int i = 0;
        for (0; i < s.size(); i++) {
            if (s[i] != '0') {
                break;
            }
        }

        return s.size() - i;
    }

    string multiply(string num1, string num2) {
        int len1 = getLen(num1);
        if (len1 == 0) return "0";
        int len2 = getLen(num2);
        if (len2 == 0) return "0";

        int start1 = num1.size() - len1;
        int start2 = num2.size() - len2;
        vector<int> res(len1 + len2, 0);

        int i, j;
        for (i = len1 - 1; i >= 0; i--) {
            int n1 = int(num1[i + start1] - '0');
            int sumCarry = 0; // the carry for sum up
            int prodCarry = 0; // the carry for product
            for (j = len2 - 1; j >= 0; j--) {
                int n2 = int(num2[j + start2] - '0');
                int curRes = n1 * n2 + prodCarry;
                prodCarry = curRes / 10;
                curRes %= 10;
                int pos = i + j + 1; // add 1 to keep res[0] for the final sum carry
                curRes += (res[pos] + sumCarry);
                sumCarry = curRes / 10;
                curRes %= 10;
                res[pos] = curRes;
            }

            // deal with produt carry
            int pos = i;
            res[pos] = prodCarry + sumCarry;

        }

        if (res[0] == 0) {
            res.erase(res.begin());
        }

        string resStr(res.size(), '0'); // trim the possible start '0'

        for (int k = 0; k < res.size(); k++) {
            resStr[k] = char(res[k] + '0');
        }

        return resStr;
    }
  };
}
