// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
namespace RemoveDuplicatesFromSortedList {
    class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            
            if (head == NULL || head->next == NULL) {
                return head;
            }
            
            ListNode * prev = head;
            ListNode * cur = head->next;
            while (cur != NULL) {
                if (cur->val == prev->val) {
                    prev->next = cur->next;
                    cur = cur->next;
                } else {
                    prev = cur;
                    cur = cur->next;
                }
            }
            
            return head;
            
        }
    };
}
