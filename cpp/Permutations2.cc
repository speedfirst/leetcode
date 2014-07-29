namespace Permutations2 {
  class Solution {
  public:
  
      void swap(int& num1, int& num2) {
          int tmp = num1;
          num1 = num2;
          num2 = tmp;
      }
  
      // return false means no next permutation
      bool nextPermutation(vector<int> &num) {
          if (num.size() == 1) {
              return false;
          }
          
          // scan from right to left, find the first reversed num
          bool foundReverse = false;
          int i = num.size() - 2;
          for ( ;i >= 0; i--) {
             if (num[i] < num[i + 1]) {
                 foundReverse = true;
                 break;
             } 
          }
          
          if (!foundReverse) {
              return false;
          }
          
          // scan from right to left, find the first number which > num[i]
          int j = num.size() - 1;
          for (; j > i; j--) {
              if (num[j] > num[i]) {
                  break;
              }
          }
          
          // swap num[i] & num[j]
          swap(num[i], num[j]);
          
          // reverse all the numbers in range (i, num.size())
          i++;
          j = num.size() - 1;
          while (i < j) {
              swap(num[i], num[j]);
              i++;
              j--;
          }
          
          return true;
      }
      
      vector<vector<int> > permuteUnique(vector<int> &num) {
          
          vector<vector<int> > result;
          if (num.empty()) {
              return result;
          }
          
          int size = num.size();
          
          // sort is important because our nextPermutate function
          // assumes to generate full-ascending to full-descending
          // permutations
          sort(num.begin(), num.end());
  
          do {
              vector<int> cur(size);
              for (int i = 0; i < size; i++) {
                  cur[i] = num[i];
              }
                  
              result.push_back(cur);
          } while (nextPermutation(num));
          
          return result;
      }
  };
}
