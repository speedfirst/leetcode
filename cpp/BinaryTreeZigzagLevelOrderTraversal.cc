namespace BinaryTreeZigzagLevelOrderTraversal {
  // a simple binary tree level traversal solution, just note to reverse
  // every second level.
  class Solution {
  public:
      vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
          vector<vector<int> > result;
          if (root == NULL) {
              return result;
          }
          
          TreeNode eol(-1); // dummy node to mark the end of each level
          queue<TreeNode *> q;
          
          q.push(root);
          q.push(&eol);
          vector<int> level;
          int levelCount = 0;
          while (!q.empty()) {
              TreeNode * cur = q.front();
              q.pop();
              
              if (cur != &eol) {
                  level.push_back(cur->val);
                  if (cur->left) {
                      q.push(cur->left);
                  }
                  if (cur->right) {
                      q.push(cur->right);
                  }
              } else {
                  if (levelCount % 2 == 1) {
                      reverse(level.begin(), level.end());
                  }
                  levelCount++;
                  result.push_back(level);
                  level.clear();
                  if (q.empty()) {
                      break;
                  }
                  q.push(&eol);
              }
          }
          
          return result;
      }
  };
}
