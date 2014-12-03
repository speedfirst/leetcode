// https://oj.leetcode.com/problems/merge-k-sorted-lists/
namespace MergeKSortedLists {

  class NodeComparator {
  public:
      bool operator ()(ListNode * n1, ListNode * n2) {
          return n1->val > n2->val;
      }
  };
  
  // time complexity: O(nk*logK), space complexity: O(k)
  class Solution {
  public:
      ListNode *mergeKLists(vector<ListNode *> &lists) {
          
          priority_queue<ListNode *, vector<ListNode *>, NodeComparator> queue;
          
          for (int i = 0; i < lists.size(); i++) {
              if (lists[i] != NULL) {
                  queue.push(lists[i]);
              }
          }
          
          ListNode dummy(-1);
          ListNode * cur = &dummy;
          while(!queue.empty()) {
              ListNode * n = queue.top();
              queue.pop();
              cur->next = n;
              cur = n;
              
              if (n->next != NULL) {
                  queue.push(n->next);
              }
          }
          
          cur->next = NULL;
  
          return dummy.next;
      }
  };
  
  // another solution, merge lists like 4 -> 2 -> 1
  // time complexity: O(nklogk), space complexity: O(1)
  class Solution {
  public:
      ListNode * merge2Lists(ListNode * head1, ListNode * head2) {
          ListNode dummy(-1);
          ListNode * cur = &dummy;
          ListNode * cur1 = head1;
          ListNode * cur2 = head2;
          while (cur1 != NULL && cur2 != NULL) {
              if (cur1->val < cur2->val) {
                  cur->next = cur1;
                  cur1 = cur1->next;
              } else {
                  cur->next = cur2;
                  cur2 = cur2->next;
              }
              cur = cur->next;
          }
          if (cur1 == NULL) {
              cur->next = cur2;
          } else {
              cur->next = cur1;
          }
          return dummy.next;
      }
      
      ListNode *mergeKLists(vector<ListNode *> &lists) {
          if (lists.empty()) return NULL;
          
          while (lists.size() > 1) {
              int pos1 = 0;
              int pos2 = lists.size() - 1;
              while (pos1 < pos2) {
                  ListNode * l = merge2Lists(lists[pos1], lists[pos2]);
                  lists.pop_back();
                  lists[pos1] = l;
                  pos1++;
                  pos2--;
              }
          }
          return lists[0];
      }
  };
}
