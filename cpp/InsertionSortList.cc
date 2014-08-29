// https://oj.leetcode.com/problems/insertion-sort-list/
namespace InsertionSortList {
    class Solution {
    public:
    
        ListNode *insertionSortList(ListNode *head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            
            ListNode dummyNode(-1);
            ListNode * dummy = &dummyNode;
            dummy->next = head;
            
            ListNode * start = dummy;
            ListNode * end = head;
            ListNode * cur = end->next;
            
            while (cur != NULL) {
                ListNode * target = start;
                while(target != end && cur->val > target->next->val) {
                    target = target->next;
                }
                
                if (target == end) {
                    end = cur;
                } else {
                    end->next = cur->next;
                    cur->next = target->next;
                    target->next = cur;
                }
                
                cur = end->next;
            }
            
            return dummy->next;
            
        }
    };
}
