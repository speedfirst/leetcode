// https://oj.leetcode.com/problems/sort-list/
namespace SortList {
    class Solution {
    public:
    
        ListNode * splitInMid(ListNode * head) {
            if (head == NULL || head->next == NULL) {
                return NULL;
            }
            
            ListNode * slow = head;
            ListNode * fast = head;
            while (fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            ListNode * mid = slow->next;
            slow->next = NULL;
            return mid;
        }
        
        ListNode * merge(ListNode * h1, ListNode * h2) {
            if (h1 == NULL && h2 == NULL) {
                return NULL;
            }
            
            if (h1 == NULL) {
                return h2;
            }
            
            if (h2 == NULL) {
                return h1;
            }
            
            ListNode * c1 = h1;
            ListNode * c2 = h2;
            ListNode dummy(-1);
            ListNode * cur = &dummy;
            
            while (c1 != NULL && c2 != NULL) {
                if (c1->val < c2->val) {
                    cur->next = c1;
                    c1 = c1->next;
                } else {
                    cur->next = c2;
                    c2 = c2->next;
                }
                
                cur = cur->next;
            }
            
            if (c1 == NULL) {
                cur->next = c2;
            } else {
                cur->next = c1;
            }
            
            return dummy.next;
        }
        
        
        ListNode *sortList(ListNode *head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            ListNode * mid = splitInMid(head);
            ListNode * sortedList1 = sortList(head);
            ListNode * sortedList2 = sortList(mid);
            return merge(sortedList1, sortedList2);
        }
    };
}
