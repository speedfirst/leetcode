// https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
namespace RemoveNthNodeFromEndOfList {
    class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            
            if (head == NULL) {
                return NULL;
            }
            
            // first loop to the nth node
            ListNode * cur = head;
            while (cur != NULL && n > 0) {
                cur = cur->next;
                n--;
            }
            
            if (n > 0) {
                return NULL;
            }
            
            // loop to the end
            ListNode dummy(-1);
            dummy.next = head;
            ListNode * prev = &dummy;
            while (cur != NULL) {
                cur = cur->next;
                prev = prev->next;
            }
            
            // remove the node
            prev->next = prev->next->next;
            
            return dummy.next;
        }
    };
}
