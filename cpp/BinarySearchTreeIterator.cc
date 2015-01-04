/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    
private:
    stack<TreeNode *> S;
public:
    BSTIterator(TreeNode *root) {
        TreeNode * cur = root;
        while (cur != NULL) {
            S.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = INT_MIN;
        if (!S.empty()) {
            TreeNode * cur = S.top();
            res = cur->val;
            S.pop();
            if (cur->right != NULL) {
                cur = cur->right;
                while (cur != NULL) {
                    S.push(cur);
                    cur = cur->left;
                }
            }
            
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
