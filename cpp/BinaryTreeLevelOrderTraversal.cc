// https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
namespace BinaryTreeLevelOrderTraversal {
    // BFS based solution. Space O(n), Time O(n)
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
    
    // recursion based solution. Space complexity O(1) (if stack is not count in), time complexity is O(n),
    // or more clear 2^(h + 1) - 2 - h, where h is the height of the tree.
    class Solution2 {
    public:
        void traverse(TreeNode * curNode, vector<int> &curLevel, int curHeight, int targetHeight) {
            if (curNode == NULL) {
                return;
            }
            
            if (curHeight == targetHeight) {
                curLevel.push_back(curNode->val);
                return;
            }
            
            traverse(curNode->left, curLevel, curHeight + 1, targetHeight);
            traverse(curNode->right, curLevel, curHeight + 1, targetHeight);
        }
        
        vector<vector<int> > levelOrder(TreeNode *root) {
            vector<vector<int> > res;
            
            int targetHeight = 1;
            while (true) {
                vector<int> curLevel;
                traverse(root, curLevel, 1, targetHeight);
                if (curLevel.empty()) {
                    break;
                } else {
                    res.push_back(curLevel);
                }
                targetHeight++;
            }
            
            return res;
        }
    };
}
