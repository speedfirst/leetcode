// This recursive in-order solution is NOT an O(1) space solution
// We can implement this idea by an iterative in-order recursion
namespace RecoverBinarySearchTree {
class Solution {
  public:
      TreeNode * pre;
      
      // p keeps the left-most order-reversed node; while q keeps the 
      // right-most one
      TreeNode * p, * q;
      
      void getWrong(TreeNode *root) {
          if (root == NULL) {
              return;
          }
          
          getWrong(root->left);
          if (pre != NULL && root->val < pre->val) {
              if (p == NULL) {
                  p = pre;
                  q = root;
              } else {
                  q = root;
              }
          }
          pre = root;
          getWrong(root->right);
      }
      
      void recoverTree(TreeNode *root) {
          getWrong(root);
          
          // swap
          int tmp = p->val;
          p->val = q->val;
          q->val = tmp;
      }
  };
}
