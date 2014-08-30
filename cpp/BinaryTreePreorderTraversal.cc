// https://oj.leetcode.com/problems/binary-tree-preorder-traversal/
namespace BinaryTreePreorderTraversal {
    class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> v;
            if (root == NULL) {
                return v;
            }
            
            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty()) {
                TreeNode * cur = s.top();
                v.push_back(cur->val);
                s.pop();
                if (cur->right) {
                    s.push(cur->right);
                }
                
                if (cur->left) {
                    s.push(cur->left);
                }
                
            }
            
            return v;
            
        }
    };
}
