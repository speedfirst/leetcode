// https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
namespace MaximumDepthOfBinaryTree {
    class Solution {
    public:
        int maxDepth(TreeNode *root) {
            return root? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;    
        }
    };
}
