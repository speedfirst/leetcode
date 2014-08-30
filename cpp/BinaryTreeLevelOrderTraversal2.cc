// https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
namespace BinaryTreeLevelOrderTraversal2 {
    class Solution {
    public:
        void doJob(vector<TreeNode *> &nodes, vector<vector<int> > &res) {
            vector<TreeNode *> nextLevelNodes;
            for (int i = 0; i < nodes.size(); i++) {
                TreeNode * node = nodes[i];
                if (node->left != NULL) {
                    nextLevelNodes.push_back(node->left);
                }
                
                if (node->right != NULL) {
                    nextLevelNodes.push_back(node->right);
                }
            }
            if (!nextLevelNodes.empty()) {
                doJob(nextLevelNodes, res);
            }
            
            vector<int> * r = new vector<int>();
            for (int i = 0; i < nodes.size(); i++) {
                TreeNode * node = nodes[i];
                r->push_back(node->val);
            }
            res.push_back(*r);
        }
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector<int> > res;
            if (root == NULL) {
                return res;
            }
            vector<TreeNode *> rootLevel;
            rootLevel.push_back(root);
            
            doJob(rootLevel, res);
            return res;
        }
    };
}
