namespace SpiralMatrix {
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            vector<int> res;
    
            int h = matrix.size();
            if (h == 0) {
                return res;
            }
            int w = matrix[0].size();
            if (w == 0) {
                return res;
            }
    
            // special handle h == 1
            if (h == 1) {
                return matrix[0];
            }
    
            // speical handle w = 1
            if (w == 1) {
                for (int i = 0; i < h; i++) {
                    res.push_back(matrix[i][0]);
                }
                return res;
            }
    
            int startX = 0;
            int startY = 0;
            int endX = w - 1;
            int endY = h - 1;
    
            while (startX < endX && startY < endY) {
                int i = startY;
                int j = startX;
                for (; j < endX; j++) {
                    res.push_back(matrix[i][j]);
                }
    
                for (; i < endY; i++) {
                    res.push_back(matrix[i][j]);
                }
    
                for (; j > startX; j--) {
                    res.push_back(matrix[i][j]);
                }
    
                for(; i > startY; i--) {
                    res.push_back(matrix[i][j]);
                }
                startX++;
                startY++;
                endX--;
                endY--;
            }
    
            if (startX == endX && startY == endY) {
                // only remain a center element
                res.push_back(matrix[startY][startX]);
            } else {
                // remain a sub row
                if (startY == endY) {
                    for (int j = startX; j <= endX; j++) {
                        res.push_back(matrix[startY][j]);
                    }
                }
                
                // remain a sub col
                if (startX == endX) {
                    for (int i = startY; i <= endY; i++) {
                        res.push_back(matrix[i][startX]);
                    }
                }
            }
    
            return res;
        }
    };
}
