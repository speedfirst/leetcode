// https://oj.leetcode.com/problems/binary-tree-postorder-traversal/
namespace BinaryTreePostOrderTraversal {

    // iterative solution
    class Solution {
    public:
    
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> s;
            if (root == NULL) {
                return res;
            }
            s.push(root);
            TreeNode * cur = NULL, * prev = NULL;
            while (!s.empty()) {
                cur = s.top();
                if (!prev || prev->left == cur || prev->right == cur) {
                    if (cur->left != NULL) {
                        s.push(cur->left);
                    } else if (cur->right != NULL) {
                        s.push(cur->right);
                    } else {
                        s.pop();
                        res.push_back(cur->val);
                    }
                } else if (cur->left == prev && cur->right != NULL) {
                    s.push(cur->right);
                } else { /* cur->right = prev */
                    s.pop();
                    res.push_back(cur->val);
                }
                
                prev = cur;
            }
            return res;
            
        }
    };
    
    // Recursive Solution
    class Solution1 {
    public:
        void doPostorderTraversal(TreeNode *root, vector<int> &res) {
            if (root == NULL) {
                return;
            }
            
            doPostorderTraversal(root->left, res);
            doPostorderTraversal(root->right, res);
            res.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> res;
            doPostorderTraversal(root, res);
            return res;
            
        }
    };
    
    // Two Stack Solution
    class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            stack<TreeNode*> stack1;
            stack<TreeNode*> stack2;
            vector<int> res;
            if (root == NULL) {
                return res;
            }
            stack1.push(root);
            
            while(!stack1.empty()) {
                TreeNode * n = stack1.top(); stack1.pop();
                stack2.push(n);
                if (n->left != NULL) {
                    stack1.push(n->left);
                }
                
                if (n->right != NULL) {
                    stack1.push(n->right);
                }
            }
            
            while (!stack2.empty()) {
                res.push_back(stack2.top()->val);
                stack2.pop();
            }
            
            return res;
        }
    };
}
