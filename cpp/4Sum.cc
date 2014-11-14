// https://oj.leetcode.com/problems/4sum/
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

// Note:
// Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
// The solution set must not contain duplicate quadruplets.
//    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

//    A solution set is:
//    (-1,  0, 0, 1)
//    (-2, -1, 1, 2)
//    (-2,  0, 0, 2)

namespace FourSum {
  class Solution {
  public:
      vector<vector<int> > fourSum(vector<int> &num, int target) {
          vector<vector<int> > res;
          if (num.size() < 4) {
              return res;
          }
  
          sort(num.begin(), num.end());
  
          for (int i = 0; i < num.size() - 3; i++) {
              if (i != 0 && num[i] == num[i - 1]) continue; // skip duplication
              for (int j = i + 1; j < num.size() - 2; j++) {
                  if (j != i + 1 && num[j] == num[j - 1]) continue; // skip duplication
  
                  int m = j + 1;
                  int n = num.size() - 1;
                  while (m < n) {
  
                      if (num[i] + num[j] + num[m] + num[n] == target) {
                          vector<int> curRes;
                          curRes.push_back(num[i]);
                          curRes.push_back(num[j]);
                          curRes.push_back(num[m]);
                          curRes.push_back(num[n]);
  
                          res.push_back(curRes);
                          
                          do {
                              m++;
                          } while(m < n && num[m] == num[m - 1]); // skip duplication
  
                          do {
                              n--;
                          } while(m < n && num[n] == num[n + 1]); // skip duplication
                      } else if (num[i] + num[j] + num[m] + num[n] > target) {
                          do {
                              n--;
                          } while(m < n && num[n] == num[n + 1]); // skip duplication
                      } else {
                          do {
                              m++;
                          } while(m < n && num[m] == num[m - 1]); // skip duplication
                      }
                  }
              }
          }
  
          return res;
      }
  };
}
