namespace SumRootToLeadfNumbers {
  class Solution {
  public:
  
      int doSumNumbers(TreeNode *root, int prevSum) {
          int curNum = prevSum * 10 + root->val;
          if (root->left == NULL && root->right == NULL) {
              return curNum;
          }
          int curSum = 0;
          if (root->left != NULL) { curSum += doSumNumbers(root->left, curNum); }
          if (root->right != NULL) { curSum += doSumNumbers(root->right, curNum); }
          return curSum;
      }
  
  
      int sumNumbers(TreeNode *root) {
          if (root == NULL) {
              return 0;
          }
  
          return doSumNumbers(root, 0);
      }
  };
}
