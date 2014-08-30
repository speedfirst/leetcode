// https://oj.leetcode.com/problems/same-tree/
namespace SameTree {
    class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == NULL && q == NULL) {
                return true;
            }
            
            if (p != NULL && q != NULL) {
                return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            
            return false;
        }
    };
}
