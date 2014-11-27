// https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    int getLen(ListNode * head) {
        int len = 0;
        ListNode * cur = head;
        while (cur != NULL) {
            cur = cur->next;
            len++;
        }
        return len;
    }

    ListNode * reverse(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * prev = head;
        ListNode * cur = head->next;
        while (cur != NULL) {
            ListNode * next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = NULL;
        return prev;
    }

    ListNode * getTail(ListNode * head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode * prev = head;
        ListNode * cur = head->next;
        while (cur != NULL) {
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }

    // if n is 0, return the first node
    ListNode * getNthNode(ListNode * head, int n) {
        ListNode * cur = head;
        while (n > 0) {
            cur = cur->next;
            n--;
        }
        return cur;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode * newHeadB = reverse(headB);
        ListNode * tailA = getTail(headA);
        if (tailA != headB) { // no intersection
            reverse(newHeadB); // recover the headB
            return NULL; 
        }
        int q = getLen(headA);
        int n = getLen(newHeadB);
        reverse(newHeadB); // recover the headB
        int m = getLen(headA);
        int x = (m - n + q) / 2;
        return getNthNode(headA, x);
    }
};
