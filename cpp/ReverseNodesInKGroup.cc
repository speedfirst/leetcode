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
    
    //-------------------------------------------------------------------------------
    // This new solution separate the reverse code and main control code
    //-------------------------------------------------------------------------------
    struct ReverseData {
        ListNode * prev2;
        ListNode * cur2;
        int count;
    };
    
    class Solution {
    public:
        ReverseData reverse(ListNode * prev2, int k) {
            ListNode * cur2 = prev2->next;
            int count = 0;
            while (count < k && cur2 != NULL) {
                ListNode * next = cur2->next;
                cur2->next = prev2;
                prev2 = cur2;
                cur2 = next;
                count++;
            }
            
            ReverseData rd;
            rd.prev2 = prev2;
            rd.cur2 = cur2;
            rd.count = count;
            return rd;
        }
        
        ListNode *reverseKGroup(ListNode *head, int k) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            
            if (k <= 1) {
                return head;
            }
            
            ListNode dummy(-1);
            dummy.next = head;
            ListNode * prev = &dummy;
            bool lastRun = false;
            while (true)
                ListNode * cur = prev->next;
                if (cur == NULL) break;
                ReverseData rd = reverse(prev, k);
                prev->next = rd.prev2;
                cur->next = rd.cur2;
                if (lastRun) break;
                if (rd.count < k) {
                    lastRun = true; // don't move forward, set last run flag and revert it back
                } else {
                    prev = cur; // move forward
                }
            }
            
            return dummy.next;
        }
    };
}
