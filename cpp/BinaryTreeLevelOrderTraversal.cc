// https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
namespace BinaryTreeLevelOrderTraversal {
    class Solution {
    public:
        vector<vector<int> > levelOrder(TreeNode *root) {
            vector<vector<int> > res;
            if (root == NULL) {
                return res;
            }
            
            TreeNode dummyNode(-1); // mark the end of level
            TreeNode * dummy = &dummyNode;
            
            queue<TreeNode *> q;
            q.push(root);
            q.push(dummy);
            vector<int> *v = new vector<int>();
            while (!q.empty()) {
                TreeNode * cur = q.front();
                q.pop();
                if (cur != dummy) {
                    v->push_back(cur->val);
                    if (cur->left) {
                        q.push(cur->left);
                    }
                    if (cur->right) {
                        q.push(cur->right);
                    }
                } else {
                    res.push_back(*v);
                    if (!q.empty()) {
                        q.push(dummy);
                        v = new vector<int>();
    
                    } else {
                        break;
                    }
                }
                
            }
            
            return res;
            
        }
    };
}
