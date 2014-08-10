namespace ConstructBinaryTreeFromInorderAndPostorderTraversal {
  class Solution {
  public:
    TreeNode *recursiveBuildTree(vector<int> &inorder, int inorderStart, int inorderEnd, unordered_map<int, int> &posInInorder,
                                 vector<int> &postorder, int postorderStart, int postorderEnd) {
        if (inorderStart > inorderEnd) {
            return NULL;
        }

        int val = postorder[postorderEnd];
        postorderEnd--; // trim the last element in postorder
        TreeNode * n = new TreeNode(val);
        int pos = posInInorder[val];

        int leftSubLen = pos - inorderStart;
        n->left = recursiveBuildTree(inorder, inorderStart, pos - 1, posInInorder,
                                     postorder, postorderStart, postorderStart + leftSubLen - 1);
        int rightSubLen = inorderEnd - pos;
        n->right = recursiveBuildTree(inorder, pos + 1, inorderEnd, posInInorder,
                                      postorder, postorderEnd - rightSubLen + 1, postorderEnd);
        return n;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) {
            return NULL;
        }

        // build a map to accelerate searching the position of a given value in "inorder" vector
        unordered_map<int, int> posInInorder;
        for (int i = 0; i < inorder.size(); i++) {
            posInInorder[inorder[i]] = i;
        }

        TreeNode * n = recursiveBuildTree(inorder, 0, inorder.size() - 1, posInInorder, postorder, 0, postorder.size() - 1);
        return n;
    }
};
}
