// https://oj.leetcode.com/problems/swap-nodes-in-pairs/
namespace SwapNodesInPairs {
    class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            
            ListNode dummy(-1);
            dummy.next = head;
            ListNode * prev = &dummy;
            ListNode * cur, *next;
            
            do {
                cur = prev->next;
                next = cur->next;
                
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                
                prev = cur;
                
            } while (prev != NULL && prev->next != NULL && prev->next->next != NULL);
            
            return dummy.next;
        }
    };
}
