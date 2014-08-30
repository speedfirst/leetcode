// https://oj.leetcode.com/problems/balanced-binary-tree/
namspace BalancedBinaryTree {
    class Res {
    public:
        Res(bool balanced) : isBalanced(balanced), height(0) {}
        Res(bool balanced, int h) : isBalanced(balanced), height(h) {}
        
        bool isBalanced;
        int height;
    };
    
    
    class Solution {
       
    public:
        bool isBalanced(TreeNode *root) {
            return check(root).isBalanced;
        }
        
        Res check(TreeNode * root) {
            if (root == NULL) {
                return Res(true, 0);
            }
            
            Res a = check(root->left);
            if (a.isBalanced == false) {
                return a;
            }
            
            Res b = check(root->right);
            if (b.isBalanced == false) {
                return b;
            }
            
            bool balanced = (abs(a.height - b.height) <= 1);
            int height = max(a.height, b.height) + 1;
            return Res(balanced, height);
        }
    };
}
