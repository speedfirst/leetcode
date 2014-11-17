// https://oj.leetcode.com/problems/binary-tree-upside-down/
namespace BinaryTreeUpsideDown {
  class Solution {
  public:
    // return the new root and right most child node
    pair<TreeNode *, TreeNode *> doUpsideDownBinaryTree(TreeNode * root) {
        if (root->left->left == NULL) {
            TreeNode * newRoot = root->left;
            newRoot->left = root->right;
            newRoot->right = root;
            root->left = NULL;
            root->right = NULL;
            return make_pair(newRoot, root);
        }
        
        pair<TreeNode *, TreeNode *> res = doUpsideDownBinaryTree(root->left);
        TreeNode * newRightRoot = res.second;
        if (root->right) {
            newRightRoot->left = root->right;
            newRightRoot->right = root;
        } else {
            newRightRoot->right = root;
        }
        root->left = NULL;
        root->right = NULL;
        return make_pair(res.first, root);
    }
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if (root == NULL || root->left == NULL) return root;
        
        return doUpsideDownBinaryTree(root).first;
    }
  };
}
