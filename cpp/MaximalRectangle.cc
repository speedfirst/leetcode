namespace MaximalRectangle {
    // Time complexity is O(w * h); memory complexity is O(w). Therefore, we can swap w & h to achieve less memory footprint
    class Solution {
    public:
        void updateHeights(vector<int> & heights, vector<vector<char> > &matrix, int row) {
            for (int i = 0; i < heights.size(); i++) {
                if (matrix[row][i] == '1') {
                    heights[i] += 1;
                } else {
                    heights[i] = 0;
                }
            }
        }
        
        int getMaxRectangleAreaInHistogram(vector<int>& heights) {
            stack<int> S;
            int maxArea = 0;
            S.push(0);
            int i = 1;
            while (i < heights.size()) {
                if (heights[i] < heights[i - 1]) {
                    int prevPos = S.top();
                    while (heights[prevPos] > heights[i]) {
                        S.pop();
                        int w = S.empty()? i : (i - (S.top() + 1));
                        int curArea = w * heights[prevPos];
                        maxArea = max(maxArea, curArea);
                        if (S.empty()) break;
                        prevPos = S.top();
                    }
                }
                S.push(i);
                i++;
            }
            
            while (!S.empty()) {
                int prevPos = S.top();
                S.pop();
                int w = S.empty()? i : (i - (S.top() + 1));
                int curArea = w * heights[prevPos];
                maxArea = max(maxArea, curArea);
            }
            
            return maxArea;
        }
        
        int maximalRectangle(vector<vector<char> > &matrix) {
            int h = matrix.size();
            if (h == 0) {
                return 0;
            }
            
            int w = matrix[0].size();
            if (w == 0) {
                return 0;
            }
            
            vector<int> heights(w, 0);
            
            int maxArea = 0;
            for (int i = 0; i < h; i++) {
                updateHeights(heights, matrix, i);
                int curMaxArea = getMaxRectangleAreaInHistogram(heights);
                maxArea = max(maxArea, curMaxArea);
            }
            
            return maxArea;
        }
    };
}
