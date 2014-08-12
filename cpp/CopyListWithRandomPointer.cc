namespace CopyListWithRandomPointer {
    class Solution {
    public:
        // complexity O(3n)
        RandomListNode *copyRandomList(RandomListNode *head) {
    
            // 1 copy nodes
            RandomListNode * cur = head;
            while (cur != NULL) {
                RandomListNode * curNew = new RandomListNode(cur->label);
                curNew->next = cur->next;
                cur->next = curNew;
                cur = curNew->next;
            }
            
            // 2 adjust random pointers
            cur = head;
            while (cur != NULL) {
                RandomListNode * curNew = cur->next;
                curNew->random = (cur->random == NULL? NULL: cur->random->next);
                cur = curNew->next;
            }
            
            // 3 separate the list and generate result
            cur = head;
            RandomListNode dummy(-1);
            RandomListNode * prevNew = &dummy;
            while (cur != NULL) {
                RandomListNode * curNew = cur->next;
                cur->next = curNew->next;
                prevNew->next = curNew;
                cur = cur->next;
                prevNew = curNew;
            }
            prevNew->next = NULL; // mark end of new duplicated list
            
            return dummy.next;
        }
    };
}
