namespace JumpGame2 {
    class Solution {
    public:
        int jump(int A[], int n) {
            int step = 0;
            int lastCanReach = 0; // mark the last reachable pos
            int maxCanReach = 0;
            int i = 0;
            
            while (i < n) {
                if (i > lastCanReach) { // reach the edge of current range
                    step++;
                    lastCanReach = maxCanReach;
                }
                if (i + A[i] > maxCanReach) maxCanReach = i + A[i];
    
                i++;
            }
            return step;
        }
    };
}
