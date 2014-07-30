namespace Subsets {
  // idea, given input [1, 2, 3]
  // first round get:
  //    - <empty>
  // then 2nd round
  //    - <empty>
  //    - 1              <== new added
  // then 3rd round
  //    - <empty>
  //    - 1
  //    - 2              <== new added
  //    - 1, 2           <== new added
  // then 4th round
  //    - <empty>
  //    - 1
  //    - 2
  //    - 1, 2
  //    - 3              <== new added
  //    - 2, 3           <== new added
  //    - 1, 2, 3        <== new added
  
  // each round, we re-iterate the results, duplicate them and append the new element to them, and finally append
  // them in the reuslt
  class Solution {
  public:
      vector<vector<int> > subsets(vector<int> &S) {
          vector<vector<int> > res;
          vector<int> empty;
          res.push_back(empty);
          
          if (S.empty()) {
              return res;
          }
          
          sort(S.begin(), S.end());
          
          for (int i = 0; i < S.size(); i++) {
              int cur = S[i];
              vector<vector<int> > newSets;
              for (int j = 0; j < res.size(); j++) {
                  vector<int> * temp = new vector<int>(res[j]);
                  temp->push_back(cur);
                  newSets.push_back(*temp);
              }
              res.insert(res.begin(), newSets.begin(), newSets.end());
          }
          
          return res;
          
      }
  };
}
