// https://oj.leetcode.com/problems/remove-element/
namespace RemoveElement {
    class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
    
            int end = n;
            int cur = 0;
            while (cur < end) {
                if (A[cur] == elem) {
                    A[cur] = A[end - 1];
                    end--;
                    
                } else {
                    cur++;
                }
            }
            
            return end;
            
            
        }
    };
}
