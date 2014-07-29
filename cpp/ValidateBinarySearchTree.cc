namespace ValidateBinarySearchTree {
  class Solution {
  public:
  
      bool doIsValidBST(TreeNode *root, int lower, int upper) {
          return (lower < root->val && root->val < upper) &&
                 (root->left == NULL || doIsValidBST(root->left, lower, root->val)) &&
                 (root->right == NULL || doIsValidBST(root->right, root->val, upper));
      }
      
      bool isValidBST(TreeNode *root) {
          if (root == NULL) {
              return true;
          }
          
          return doIsValidBST(root, INT_MIN, INT_MAX);
      }
  };
}
