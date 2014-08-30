// https://oj.leetcode.com/problems/binary-tree-inorder-traversal/
namespace BinaryTreeInorderTraversal {
    // recursive solution is trival, here is the iterative solution
    class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            stack<TreeNode *> s;
            vector<int> v;
            if (root == NULL) {
                return v;
            }
            TreeNode * cur = root;
            
            while (true) {
                if (cur) {
                    s.push(cur);
                    cur = cur->left;
                    
                } else {
                    if (s.empty()) {
                        break;
                    } else {
                        cur = s.top();
                        s.pop();
                        v.push_back(cur->val);
                        cur = cur->right;
                    }
                    
                }
            }

            return v;
    
        }
    };
}
