// https://oj.leetcode.com/problems/sort-colors/
namespace SortColors {
  class Solution {
  public:
  
      void doSwitch(int A[], int i, int j) {
          if (i == j) {
              return;
          }
          
          int temp = A[i];
          A[i] = A[j];
          A[j] = temp;
      }
      void sortColors(int A[], int n) {
          if (n == 0) {
              return;
          }
          
          int pos0 = 0;
          int pos2 = n - 1;
          int cur = 0;
          while (cur <= pos2) {
              if (A[cur] == 0) {
                  if (pos0 < cur) {
                      doSwitch(A, pos0, cur);
                      pos0++;
                  } else {
                      cur++;
                  }
              } else if (A[cur] == 2) {
                  doSwitch(A, pos2, cur);
                  pos2--;
              } else {
                  cur++;
              }
          }
      }
  };
}
