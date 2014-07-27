namespace PartitionList {
	class Solution {
	public:
	    ListNode *partition(ListNode *head, int x) {
	        if (head == NULL) {
	            return NULL;
	        }
	        
	        ListNode dummy(-1);
	        dummy.next = head;
	        ListNode * prev = &dummy;
	        ListNode * cur = head;
	        // find the first num >= x
	        while (cur != NULL && cur->val < x) {
	            cur = cur->next;
	            prev = prev->next;
	        }
	        
	        ListNode * dest = prev;
	        if (cur != NULL) {
	            cur = cur->next;
	            prev = prev->next; // move forward 1 step
	        }
	        
	        // keep going, once find a num < x, mov it
	        while (cur != NULL) {
	            if (cur->val < x) {
	                prev->next = cur->next;
	                cur->next = dest->next;
	                dest->next = cur;
	                cur = prev->next;
	                dest = dest->next;
	            } else {
	                cur = cur->next;
	                prev = prev->next;
	            }
	        }
	        
	        return dummy.next;
	    }
	};
}