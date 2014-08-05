namespace MergeKSortedLists {

  class NodeComparator {
  public:
      bool operator ()(ListNode * n1, ListNode * n2) {
          return n1->val > n2->val;
      }
  };
  
  // complexity: O(nk*logK)
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
}
