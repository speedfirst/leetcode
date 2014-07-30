namespace RemoveDuplicatesFromSortedList2 {
  class Solution {
  public:
      ListNode *deleteDuplicates(ListNode *head) {
          if (head == NULL || head->next == NULL) {
              return head;
          }
          
          ListNode dummy(-1);
          dummy.next = head;
          bool duplicated = false; // indicate duplicate mode
          ListNode * prev = &dummy;
          ListNode * cur = head;
          ListNode * next = head->next;
          
          while (next != NULL) {
              if (cur->val == next->val) {
                  duplicated = true;
              } else {
                  if (duplicated) {
                      duplicated = false;
                      prev->next = next;
                  } else {
                      prev = cur;
                  }
              }
              
               cur = next;
               next = next->next;
          }
          
          if (duplicated) {
              prev->next = next;
          }
          
          return dummy.next;
          
      }
  };
}
