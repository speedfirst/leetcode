namespace AddTwoNumbers {

  class Solution {
  public:
      ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
          if (l1 == NULL && l2 == NULL) {
              return NULL;
          }
          
          if (l1 == NULL) {
              return l2;
          }
          
          if (l2 == NULL) {
              return l1;
          }
          
          ListNode dummy(-1);
          ListNode * tail = &dummy;
          int carry = 0;
          while (l1 != NULL && l2 != NULL) {
              int sum = l1->val + l2->val + carry;
              carry = sum / 10;
              ListNode * cur = new ListNode(sum % 10);
              tail->next = cur;
              tail = cur;
              
              l1 = l1->next;
              l2 = l2->next;
          }
          
          ListNode * l = NULL;
          if (l1 != NULL) {
              l = l1;
          } else if (l2 != NULL) {
              l = l2;
          }
          
          // handle the remaining carry
          while (l != NULL) {
              int sum = l->val + carry;
              carry = sum / 10;
              ListNode * cur = new ListNode(sum % 10);
              tail->next = cur;
              tail = cur;
              l = l->next;
          }
          
          // handle the last possible new node due to carry
          if (carry > 0) {
              ListNode * cur = new ListNode(carry);
              tail->next = cur;
          }
          
          return dummy.next;
      }
  };
}
