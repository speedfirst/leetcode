// https://oj.leetcode.com/problems/symmetric-tree/
namespace SymmetricTree {
    class Solution {
    public:
    
        bool isSame(TreeNode * a, TreeNode * b) {
            if (a == NULL && b == NULL) {
                return true;
            } 

            if (a == NULL || b == NULL) {
                return false;
            }

            return (a->val == b->val) && isSame(a->left, b->right) && isSame(a->right, b->left);
        }
        bool isSymmetric(TreeNode *root) {
            if (root == NULL) {
                return true;
            } 
            return isSame(root, root);
        }
    };
}
