namespace PermutationSequence {
  class Solution {
  public:
      string getPermutation(int n, int k) {
          if (k < 1) {
              return "";
          }
          
          vector<char> s(n);
          for (int i = 0; i < n; i++) {
              s[i] = (i + '1');
          }
          
          // initialize factorials
          vector<int> factorial(n + 1);
          factorial[0] = 1;
          for (int i = 1; i <= n; i++) {
              factorial[i] = i * factorial[i - 1];
          }
          
          
          vector<char> res(n);
          int cur = 0;
          k--; // make k starts from 0
          // idx = k / (s.len - 1)!
          // k = k % (s.len - 1)!
          while (cur < n) {
              int idx = k / factorial[s.size() - 1];
              res[cur] = s[idx];
              k = k % factorial[s.size() - 1];
              s.erase(s.begin() + idx);
              cur++;
          }
          
          return string(res.begin(), res.end());
      }
  };
}
