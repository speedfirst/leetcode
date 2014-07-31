namespace Power_x_n {
  public class Solution {
      public double pow(double x, int n) {
          boolean positive = true;
          if (n < 0) {
              n = -n;
              positive = false;
          }
          
          double res = 1.0;
          double tmp = x;
          while (n > 0) {
              if (n % 2 == 1) {
                  res *= tmp;
              }
              n >>= 1;
              tmp = tmp * tmp;
          }
          
          if (!positive) {
              res = 1 / res;
          }
          
          return res;
      }
  }
};
