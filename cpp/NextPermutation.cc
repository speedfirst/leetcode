namespace NextPermutation {
  class Solution {
  public:
      void nextPermutation(vector<int> &num) {
          int i, j, tmp;
          i = num.size() - 2;
          for(; i >= 0; i--) {
              if (num[i] < num[i + 1]) {
                  break;
              }
          }
          
          if (i >= 0) {
              j = num.size() - 1;
              for(; j > i; j--) {
                  if (num[j] > num[i]) {
                      break;
                  }
              }
              
              tmp = num[i];
              num[i] = num[j];
              num[j] = tmp;
          }
          
          i++;
          j = num.size() - 1;
          while (i < j) {
              tmp = num[i];
              num[i] = num[j];
              num[j] = tmp;
              i++;
              j--;
          }
      }
  };
}
