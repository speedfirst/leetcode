namespace RotateList {
	// first revert, then rotate, then revert back
	class Solution1 {
	public:
	    ListNode *reverseList(ListNode *head, int &len) {
	        ListNode * prev = NULL;
	        ListNode * cur = head;
	        ListNode * next = cur->next;
	        int l = 1;
	        
	        do {
	            cur->next = prev;
	            prev = cur;
	            cur = next;
	            next = next->next;
	            l++;
	        } while (next != NULL);
	        cur->next = prev;
	        
	        len = l;
	        return cur;
	    }
	    
	    ListNode *rotateRight(ListNode *head, int k) {
	        if (head == NULL || head->next == NULL || k == 0) {
	            return head;
	        }
	        
	        int len = 0;
	        ListNode * newHead = reverseList(head, len);
	        
	        int offset = k % len;
	        
	        // rotate
	        if (offset > 0) { // if offset is 0, do not rotate
	            ListNode * cur = newHead;
	            for (int i = 1; i < offset; i++) {
	                cur = cur->next;
	            }
	            
	            // now cur is the cut point
	            head->next = newHead;
	            newHead = cur->next;
	            cur->next = NULL;
	        }
	        
	        // revert it back
	        head = reverseList(newHead, len);
	        return head;
	    }
	};

	// Another solution. get length, and left rotate length - k
	class Solution {
	public:
    
	    ListNode *rotateRight(ListNode *head, int k) {
	        if (head == NULL || head->next == NULL || k == 0) {
	            return head;
	        }
	        
	        // get list's len & tail
	        int len = 0;
	        ListNode * cur = head;
	        ListNode * tail = NULL;
	        while (cur != NULL) {
	            tail = cur;
	            cur = cur->next;
	            len++;
	        }
	        
	        int offset = (len - k % len) % len;
	        
	        // rotate
	        ListNode * newHead;
	        if (offset > 0) {
	            cur = head;
	            for (int i = 0; i < offset - 1; i++) {
	                cur = cur->next;
	            }
	            newHead = cur->next;
	            cur->next = NULL;
	            tail->next = head;
	        } else {
	            newHead = head; // if offset is 0, do not rotate
	        }
	        
	        return newHead;
	    }
	};
}