// https://oj.leetcode.com/problems/n-queens-ii/
namespace NQueens2 {
  class Solution {
  public:
      long upper;
      long cnt;
      
      void doNQueens(long row, long ld, long rd) {
          if (row == upper) {
              cnt++;
              
          } else {
          
              long pos = upper & (~(row | ld | rd));
              while (pos != 0) {
                  long p = pos & (-pos);
                  pos -= p;
                  doNQueens(row + p, (ld + p) << 1, (rd + p) >> 1);
              }
          }
      }
      
      int totalNQueens(int n) {
          upper = (1 << n) - 1;
          cnt = 0;
          doNQueens(0, 0, 0);
          return cnt;
          
      }
  };
}
