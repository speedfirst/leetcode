namespace DivideTwoIntegers {
class Solution {
  public:
      int divide(int dividend, int divisor) {
          int res = 0, multior = 0;
          long long a = abs((long long)dividend); // Note we have to use long long because abs(INT_MIN) is also INT_MIN
          long long b = abs((long long)divisor);
          int i = 0;
          while(a >= b){
              i++;
              cout<<a<<endl;
              if(a >= (b<<multior)) {
                  res += (1<<multior);
                  a -= (b<<multior);
                  ++multior;
              }
              else {
                  multior = 0;
              }
          }
          cout<<"total loop:"<<i<<endl;
          return ((dividend^divisor)>>31)? 0-res:res;
      }
  };
}
