namespace BinaryTreeMaximumPathSum {
class Solution {
  public:
  
      int doMaxPathSum(TreeNode * root, int & maxSum) {
          if (root == NULL) {
               return 0;
          }
          
          int leftSum = doMaxPathSum(root->left, maxSum);
          int rightSum = doMaxPathSum(root->right, maxSum);
      
          int curSum = root->val;
          curSum = max(curSum, root->val + leftSum);
          curSum = max(curSum, root->val + rightSum);
  
          maxSum = max(curSum, maxSum);
          maxSum = max(root->val + leftSum + rightSum, maxSum);
          return curSum;
      }
      
      int maxPathSum(TreeNode *root) {
          if (root == NULL) {
              return 0;
          }
          int max = INT_MIN;
          doMaxPathSum(root, max);
          return max;
      }
  };
}
