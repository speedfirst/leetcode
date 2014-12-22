// https://oj.leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int majEle = num[0];
        int count = 1;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == majEle) count++;
            else {
                count--;
                if (count == 0) {
                    majEle = num[i];
                    count = 1;
                }
            }
        }
        return majEle;
    }
};
