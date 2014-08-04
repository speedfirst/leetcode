namepsace MinimumDepthOfBinaryTree {
  class Solution {
  public:
      int minDepth(TreeNode *root) {
          if (root == NULL) {
              return 0;
          }
          
          int minLeft = minDepth(root->left);
          int minRight = minDepth(root->right);
          
          // not leaf node, we only count the non-null subtree
          if (minLeft * minRight != 0) {
              return min(minLeft, minRight) + 1;
          }
          
          if (minLeft == 0) {
              return minRight + 1;
          } else {
              return minLeft + 1;
          }
          
      }
  };
}
