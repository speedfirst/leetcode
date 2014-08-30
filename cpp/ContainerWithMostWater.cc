namespace ContainerWithMostWater {
    class Solution {
    public:
        int maxArea(vector<int> &height) {
            
            if (height.empty()) {
                return 0;
            }
            
            int maxArea = -1;
            int i = 0;
            int j = height.size() - 1;
            
            while (i < j) {
                int curArea = (j - i)  * min(height[i], height[j]);
                maxArea = max(maxArea, curArea);
                
                if (height[i] < height[j]) {
                    i++;
                } else {
                    j--;
                }
            }
            
            return maxArea;
            
        }
    };
}
