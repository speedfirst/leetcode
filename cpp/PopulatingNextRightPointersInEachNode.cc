// https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
namespace PopulatingNextRightPointersInEachNode {
    class Solution {
    public:
        void connect(TreeLinkNode *root) {
            
            if (root == NULL) {
                return;
            }
            
            TreeLinkNode *cur = root;
            cur->next = NULL;
            TreeLinkNode *left = root->left;
            // handle one level case
            if (left == NULL) {
                return;
            }
            
            while (true) {
                
                while (cur != NULL) {
                    cur->left->next = cur->right;
                    if (cur->next != NULL) {
                        cur->right->next = cur->next->left;
                    } else {
                        cur->right = NULL;
                    }
                    cur = cur->next;
                }
                cur = left;
                
                left = left->left;
                if (left == NULL) {
                    break;
                }
            }
        }
    };
}
