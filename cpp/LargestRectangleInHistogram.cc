namespace LargestRectangleInHistogram {
  class Solution {
  public:
      int largestRectangleArea(vector<int> &height) {
          if (height.empty()) {
              return 0;
          }
          
          stack<int> S;
          
          int maxArea = 0;
          int i = 0;
          while (i < height.size()) {
              if (S.empty() || height[S.top()] <= height[i]) {
                  S.push(i);
                  i++;
              } else {
                  int cur = S.top();
                  S.pop();
                  int curArea = height[cur] * (S.empty()? i : i - S.top() - 1);
                  if (curArea > maxArea) {
                      maxArea = curArea;
                  }
              }
          }
          
          while (!S.empty()) {
              int cur =  S.top();
              S.pop();
              int curArea = height[cur] * (S.empty()? i : i - S.top() - 1);
              if (curArea > maxArea) {
                  maxArea = curArea;
              }
          }
          
          return maxArea;
      }
  };
}
