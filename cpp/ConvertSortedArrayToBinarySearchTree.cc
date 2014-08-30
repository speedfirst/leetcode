// https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
namespace ConvertSortedArrayToBinarySearchTree {
    class Solution {
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            return recRun(num, 0, num.size());
        }
        
        TreeNode * recRun(vector<int> &num, int start, int end) {
            if (start >= end) {
                return NULL;
            }
            int mid = ((end - start) >> 1) + start;
            TreeNode * n = new TreeNode(num[mid]);
            n->left = recRun(num, start, mid);
            n->right = recRun(num, mid + 1, end);
            return n;
        }
    };
}
