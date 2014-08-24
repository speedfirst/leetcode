namespace TrappingRainWater {
    class Solution {
    public:
        int trap(int A[], int n) {
            if (n == 0) return 0;
            int area = 0;
            
            int prevHeight = 0;
            // scan from left to right
            int curArea = 0;
            for (int i = 0; i < n; i++) {
                if (A[i] >= prevHeight) {  // Note here ">=" is used, and below ">" is used
                    area += curArea;
                    curArea = 0;
                    prevHeight = A[i];
                } else {
                    curArea += (prevHeight - A[i]);
                }
            }
            
            // scan from right to left
            prevHeight = 0;
            curArea = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (A[i] > prevHeight) {
                    area += curArea;
                    curArea = 0;
                    prevHeight = A[i];
                } else {
                    curArea += (prevHeight - A[i]);
                }    
            }
            
            return area;
        }
    };
}
