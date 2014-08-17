namespace ReverseNodesInKGroup {
    class Solution {
    public:
    
        ListNode *reverseKGroup(ListNode *head, int k) {
    
            if (head == NULL) {
                return NULL;
            }
    
            if (head->next == NULL) {
                return head;
            }
    
            if (k <= 1) {
                return head;
            }
    
            ListNode dummy(-1);
            dummy.next = head;
    
            ListNode * last = &dummy; // mark the last element of previous group
            ListNode * first = head; // mark the first element of current group before reversion; after revision it becomes last
            ListNode * cur = first;
            ListNode * next;
            while (cur != NULL) {
                ListNode * prev = NULL;
                int count = 0;
                while (count < k && cur != NULL) {
                    next = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                    count++;
                }
                
                if (count < k) {
                    // count < k, revert them back
                    cur = prev;
                    prev = next;
                    while (cur != NULL) {
                        next = cur->next;
                        cur->next = prev;
                        prev = cur;
                        cur = next;
                    }
                    break;
                }
                
                last->next = prev;
                first->next = cur;
                last = first;
                if (first != NULL) {
                    first = first->next;
                }
            }
    
            return dummy.next;
        }
    };
}
