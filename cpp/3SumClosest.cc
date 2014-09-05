// https://oj.leetcode.com/problems/3sum-closest/
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//    For example, given array S = {-1 2 1 -4}, and target = 1.
//    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
namespace ThreeSumClosest {
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
