namespace PathSum2 {

  class Solution {
  public:
      void doPathSum(TreeNode *root, vector<vector<int> > &res, vector<int> &curPath, int sum, int curSum) {
          curSum += root->val;
          curPath.push_back(root->val);
          if (root->left == NULL && root->right == NULL) {
              if (curSum == sum) {
                  vector<int> * newPath = new vector<int>(curPath);
                  res.push_back(*newPath);
              }
          } else {
              if (root->left != NULL) {
                  doPathSum(root->left, res, curPath, sum, curSum);
              }
              
              if (root->right != NULL) {
                  doPathSum(root->right, res, curPath, sum, curSum);
              }
          }
          curPath.pop_back();
      }
      
      vector<vector<int> > pathSum(TreeNode *root, int sum) {
          vector<vector<int> > res;
          if (root == NULL) {
              return res;
          }
          
          vector<int> curPath;
          doPathSum(root, res, curPath, sum, 0);
          
          return res;
          
      }
  };
}
