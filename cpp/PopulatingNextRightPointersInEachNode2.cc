namespace PopulatingNextRightPointersInEachNode2 {

class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        if (root == NULL) {
            return;
        }
        
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode * prev = NULL;
        do {
            TreeLinkNode * curNode = q.front();
            q.pop();
            if (prev != NULL) {
                prev->next = curNode;
            }
            prev = curNode;
            
            if (curNode == NULL) {
                if (q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                }
            } else {
                if (curNode->left) {
                    q.push(curNode->left);
                }
                
                if (curNode->right) {
                    q.push(curNode->right);
                }
            }
        } while(true);
        
    }
};
}
