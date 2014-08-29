namespace ReorderList {
    class Solution {
    public:
        ListNode * splitInMid(ListNode * head) {
            if (head == NULL || head->next == NULL) {
                return NULL;
            }
            
            ListNode * slow = head;
            ListNode * fast = head;
            while(fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            ListNode * mid = slow->next;
            slow->next = NULL;
            return mid;
        }
        
        ListNode * reverse(ListNode * head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            
            
            ListNode * prev = NULL;
            ListNode * cur = head;
            ListNode * next = cur->next;
            while (true) {
                cur->next = prev;
                prev = cur;
                if (next == NULL) {
                    break;
                }
                cur = next;
                next = next->next;
            }
            
            return cur;
        }
        
        void reorderList(ListNode *head) {
            if (head == NULL || head->next == NULL) {
                return;
            }
            ListNode * mid = splitInMid(head);
            ListNode * h2 = reverse(mid);
            ListNode * cur1 = head;
            ListNode * cur2 = h2;
            ListNode dummy(-1);
            ListNode * dest = &dummy;
            int i = 0;
            while (cur1 != NULL && cur2 != NULL) {
                if (i % 2 == 0) {
                    dest->next = cur1;
                    cur1 = cur1->next;
                } else {
                    dest->next = cur2;
                    cur2 = cur2->next;
                }
                i++;
                dest = dest->next;
            }
            
            if (cur1 == NULL) {
                dest->next = cur2;
            } else {
                dest->next = cur1;
            }
            
            head = dummy.next;
        }
    };
}
