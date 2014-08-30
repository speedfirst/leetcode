// https://oj.leetcode.com/problems/single-number/
namespace SingleNumber {
    class Solution {
    public:
        int singleNumber(int A[], int n) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum ^= A[i];
            }
            
            return sum;
        }
    };
}
