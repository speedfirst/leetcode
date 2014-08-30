// https://oj.leetcode.com/problems/unique-binary-search-trees/
namespace UniqueBinarySearchTree {
    class Solution {
    public:
        int cache[1024];
        
        int numTrees(int n) {
            if (n == 0 || n == 1) {
                return 1;
            }
            
            if (cache[n] != 0) {
                return cache[n];
            }
            
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += numTrees(i - 1) * numTrees (n - i);
            }
            
            cache[n] = sum;
            
            return sum;
        }
    };
}
