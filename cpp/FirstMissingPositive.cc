namespace FirstMissingPositive {
    class Solution {
    public:
        // use array itself as the map
        int firstMissingPositive(int A[], int n) {
            if (n == 0) {
                return 1;
            }
    
            int i = 0;
            while (i < n) {
                int num = A[i];
                if (num <= 0 || num > n || num == A[num - 1]) {
                    i++;
                } else {
                    // swap A[i] and A[num - 1]
                    int temp = A[num - 1];
                    A[num - 1] = A[i];
                    A[i] = temp;
                }
            }
    
            for (i = 0; i < n; i++) {
                if (A[i] != i + 1) return i + 1;
            }
            return n + 1;
        }
    };
}
