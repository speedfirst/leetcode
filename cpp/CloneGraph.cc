
#include <queue>
#include <unordered_map>
#include "leetcode_common/graph"
using namespace std;

namepsace CloneGraph {
  class Solution {
  public:
      UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
          if (node == NULL) {
              return NULL;
          }
          unordered_map<leetcode::UndirectedGraphNode *, leetcode::UndirectedGraphNode *> old2newMap;
          queue<UndirectedGraphNode *> q;

          UndirectedGraphNode * nodeNew = new UndirectedGraphNode(node->label);
          old2newMap[node] = nodeNew;
          q.push(node);
          while (!q.empty()) {
             leetcode::UndirectedGraphNode * cur = q.front();
             q.pop();
             UndirectedGraphNode * curNew = old2newMap[cur];
             for (int i = 0; i < cur->neighbors.size(); i++) {
                 UndirectedGraphNode * neighbor = cur->neighbors[i];
                 unordered_map<leetcode::UndirectedGraphNode *, leetcode::UndirectedGraphNode *>::iterator it = old2newMap.find(neighbor);
                 if (it == old2newMap.end()) {
                     UndirectedGraphNode * neighborNew = new leetcode::UndirectedGraphNode(neighbor->label);
                     old2newMap[neighbor] = neighborNew;
                     q.push(neighbor);
                 }
                 curNew->neighbors.push_back(old2newMap[neighbor]);
             }
          }
          
          return nodeNew;
      }
  };
}