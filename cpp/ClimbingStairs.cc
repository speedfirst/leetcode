// https://oj.leetcode.com/problems/climbing-stairs/
namespace ClimbingStairs {
    class Solution {
    public:
        int cache[100];
        int climbStairs(int n) {
            if (n == 1) {
                return 1;
            }
            
            if (n == 2) {
                return 2;
            }
            
            if (cache[n] != 0) {
                return cache[n];
            }
            
            int result = climbStairs(n - 1) + climbStairs(n - 2);
            cache[n] = result;
            return result;
        }
    };
}
