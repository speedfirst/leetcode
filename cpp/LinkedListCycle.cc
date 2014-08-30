// https://oj.leetcode.com/problems/linked-list-cycle/
namespace LinkedListCycle {
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == NULL) {
                return false;
            }
            
            ListNode * a = head;
            ListNode * b = a;
            
            while(true) {
                a = a->next;
                if (a == NULL) {
                    return false;
                }
                
                b = b->next;
                if (b == NULL) {
                    return false;
                }
                
                b = b->next;
                if (b == NULL) {
                    return false;
                }
                
                if (a == b) {
                    return true;
                }
            }
        }
    };
}
