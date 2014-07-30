namepsace Subsets2 {
  class Solution {
  public:
      void doSubsetsWithDup(vector<int> &S, int step, vector<vector<int> > &res, vector<int> & output) {
          int prev = INT_MAX;
          for (int i = step; i < S.size(); i++) {
              int cur = S[i];
              if (cur == prev) {   // here to remove the duplication
                  continue;
              }
              prev = cur;
              output.push_back(S[i]);
              res.push_back(output);
              doSubsetsWithDup(S, i + 1, res, output);
              output.pop_back();
          }
          
      }
      
      
      vector<vector<int> > subsetsWithDup(vector<int> &S) {
          
          vector<vector<int> > res;
          if (S.empty()) {
              return res;
          }
          sort(S.begin(), S.end());
          vector<int> empty;
          res.push_back(empty);
          doSubsetsWithDup(S, 0, res, empty);
          
          return res;
          
      }
  };
}
