namespace JumpGame {
    class Solution {
    public:
        bool canJump(int A[], int n) {
            if (n == 0) {
                return false;
            }
            
            int maxStep = 0;
            for (int i = 1; i < n; i++) {
                maxStep = max(maxStep, A[i - 1]) - 1;
                if (maxStep < 0) {
                    return false;
                }
            }
            
            return maxStep >= 0;
        }
    };
}
