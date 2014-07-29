namespace Combination {
  class Solution {
  public:
  
      void genCombine(vector<vector<int> >& result, vector<int> cur, int idx, int n, int k) {
          int curSize = cur.size();
          if (curSize == k) {
              result.push_back(cur);
              return;
          }
          
          for (int i = idx; i <= n - k + curSize + 1; i++) {
              cur.push_back(i);
              genCombine(result, cur, i + 1, n, k);
              cur.pop_back();
          } 
      }
      
      vector<vector<int> > combine(int n, int k) {
          vector<vector<int> > result;
          if (n < 1 || k > n || k <= 0) {
              return result;
          }
          
          vector<int> cur;
          
          genCombine(result, cur, 1, n, k);
          
          return result;
      } 
  };
}
