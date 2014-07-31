namespace ConvertSortedListToBinarySearchTree {
class Solution {
public:

    int getLen(ListNode * head) {
        int len = 0;
        ListNode * cur = head;
        while (cur != NULL) {
            cur = cur->next;
            len++;
        }
        return len;
    }
    
    TreeNode * doSortedListToBST(ListNode ** cur, int start, int end) {
        if (start >= end) {
            return NULL;
        }
        int mid = start + ((end - start) >> 1);
        TreeNode * left = doSortedListToBST(cur, start, mid);
        TreeNode * root = new TreeNode((*cur)->val);
        (*cur) = (*cur)->next;
        TreeNode * right = doSortedListToBST(cur, mid + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        
        if (head == NULL) {
            return NULL;
        }
        
        int len = getLen(head);
        
        return doSortedListToBST(&head, 0, len);
    }
};
}
