// https://oj.leetcode.com/problems/path-sum/
namespace PathSum {
    class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            if (root == NULL ) {
                return false;
            }
            
            sum -= root->val;
            
            if (root->left && hasPathSum(root->left, sum)) {
                return true;
            }
            
            if (root->right && hasPathSum(root->right, sum)) {
                return true;
            } 
            
            if (sum == 0 && root->left == NULL && root->right == NULL) {
                return true;
            }
            
            return false;
        }
    };
}
