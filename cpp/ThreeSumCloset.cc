namespace ThreeSumCloset {
  class Solution {
  public:
      int getClosetSum(vector<int> &num, int i, int start, int end, int target) {
          
          int j = start;
          int k = end;
          int minDiff = INT_MAX;
          int closetSum;
          while (j < k) {
              if (num[i] + num[j] + num[k] == target) {
                  return target;
              } else if (num[i] + num[j] + num[k] < target) {
                  int diff = target - num[i] - num[j] - num[k];
                  if (diff < minDiff) {
                      minDiff = diff;
                      closetSum = num[i] + num[j] + num[k];
                  }
                  j++;
              } else {
                  int diff = num[i] + num[j] + num[k] - target;
                  if (diff < minDiff) {
                      minDiff = diff;
                      closetSum = num[i] + num[j] + num[k];
                  }
                  k--;
              }
          }
          
          return closetSum;
      }
      
      int threeSumClosest(vector<int> &num, int target) {
          sort(num.begin(), num.end());
          int minDiff = INT_MAX;
          int closetSum;
          for (int i = 0; i < num.size() - 2; i++) {
              int sum = getClosetSum(num, i, i + 1, num.size() - 1, target);
              if (abs(target - sum) < minDiff) {
                  minDiff = abs(target - sum);
                  closetSum = sum;
              }
              
              if (minDiff == 0) {
                  break;
              }
          }
          
          return closetSum;
      }
  };
}
