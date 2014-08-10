namespace ConstructBinaryTreeFromPreorderAndInorderTraversal {
  class Solution {
  public:
      TreeNode * recursiveBuildTree(unordered_map<int, int>& val2posMap, vector<int> &inorder, int inorderStart, int inorderEnd,
                                    vector<int> &preorder, int preorderStart, int preorderEnd) {
          if (inorderStart > inorderEnd) {
              return NULL;
          }
          
          int val = preorder[preorderStart];
          preorderStart++;
          int pos = val2posMap[val];
          TreeNode * n = new TreeNode(val);
          
          int leftSubLen = pos - inorderStart;
          n->left = recursiveBuildTree(val2posMap, inorder, inorderStart, pos - 1, preorder, preorderStart, preorderStart + leftSubLen - 1);
          int rightSubLen = inorderEnd - pos;
          n->right = recursiveBuildTree(val2posMap, inorder, pos + 1, inorderEnd, preorder, preorderEnd - rightSubLen + 1, preorderEnd);
          
          return n;
      }
      
      TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
          if (preorder.empty()) {
              return NULL;
          }
          
          unordered_map<int, int> val2posMap;
          for (int i = 0; i < inorder.size(); i++) {
              val2posMap[inorder[i]] = i;
          }
          
          return recursiveBuildTree(val2posMap, inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
      }
  };
}
