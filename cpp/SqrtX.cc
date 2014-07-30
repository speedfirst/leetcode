namepsace SqrtX {
  class Solution {
  public:
  
      // newton iteration
      int sqrt(int x) {
          if (x == 0) {
              return 0;
          }
          
          double EPS = 0.00001;
  
          double res = x / 2.0;
          double product;
          do {
              res = (res + x/res) / 2;
              product = res * res;
          } while (abs(product - x) > EPS);
          
          int root = (int)res;
          
          // ensure root * root always <= x
          if (root * root > x) {
              root--;
          }
          
          return root;
      }
  };
}
