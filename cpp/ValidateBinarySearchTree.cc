namespace ValidateBinarySearchTree {
  class Solution {
  public:
  
      bool doIsValidBST(TreeNode *root, int lower, int upper) {
          bool res;
          if (root->val <= lower || root->val >= upper) {
              return false;
          }
          
          if (root->left != NULL) {
              res = doIsValidBST(root->left, lower, root->val);
              if (!res) {
                  return false;
              }
          }
          
          if (root->right != NULL) {
              res = doIsValidBST(root->right, root->val, upper);
              if (!res) {
                  return false;
              }
          }
          
          return true;
      }
      
      bool isValidBST(TreeNode *root) {
          if (root == NULL) {
              return true;
          }
          
          return doIsValidBST(root, INT_MIN, INT_MAX);
      }
  };
}
