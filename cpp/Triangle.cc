namespace Triangle {
class Solution {
  public:
      int minimumTotal(vector<vector<int> > &triangle) {
          vector<int> t = triangle[triangle.size() - 1]; // open a vector to record data
          for (int i = t.size() - 2; i >= 0; i--) {
              int count = i + 1;
              for (int j = 0; j < count; j++) {
                  int cur = triangle[i][j];
                  t[j] = cur + min(t[j], t[j + 1]);
              }
          }
          
          return t[0];
      }
  };
}
