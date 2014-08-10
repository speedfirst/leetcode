namespace MedianOfTwoSortedArray {
  // this solution has complexity O(m + n)
  class Solution1 {
  public:
      double findMedianSortedArrays(int A[], int m, int B[], int n) {
          
          int i = 0;
          int j = 0;
          int mid = (m + n) / 2;
          bool odd = ((m + n) % 2 == 1);
          
          int count = 0;
          vector<int> medians;
          while (i < m && j < n) {
              int cur;
              if (A[i] < B[j]) {
                  cur = A[i];
                  i++;
              } else {
                  cur = B[j];
                  j++;
              }
              
              if (count == mid - 1) {
                  medians.push_back(cur);
              } else if (count == mid) {
                  medians.push_back(cur);
                  break;
              }
              count++;
          }
          
          if (medians.size() == 2) {
              if (odd) {
                  return medians[1];
              } else {
                  return (medians[0] + medians[1]) / 2.0;
              }
          }
          
          if (medians.size() == 1) {
              if (odd) {
                  if (i < m) {
                      return A[i];
                  } else {
                      return B[j];
                  }
              } else {
                  if (i < m) {
                      return (medians[0] + A[i]) / 2.0;
                  } else {
                      return (medians[0] + B[j]) / 2.0;
                  }
              }
          }
          
          if (medians.size() == 0) {
              if (odd) {
                  if (i < m) {
                      return A[i + mid - count];
                  } else {
                      return B[j + mid - count];
                  }
              } else {
                  if (i < m) {
                      return (A[i + mid - 1 - count] + A[i + mid - count]) / 2.0;
                  } else {
                      return (B[j + mid - 1- count] + B[j + mid - count]) / 2.0;
                  }
              }
          }
          
      }
  
    // this solution is O(log(m + n))  
    class Solution {
    public:
        double findKthElement(int A[], int m, int B[], int n, int k) {
            int startA = 0;
            int startB = 0;
            int ka, kb;
            while (true) {
                if (startA == m) return B[startB + k];
                if (startB == n) return A[startA + k];
                if (k == 0) return min(A[startA], B[startB]);
                if (k == 1) {
                    ka = startA;
                    kb = startB;
                } else {
                    ka = min(m - 1, startA + k / 2 - 1);
                    kb = min(n - 1, startB + k / 2 - 1);
                }
                if (A[ka] <= B[kb]) {
                    k -= (ka - startA + 1);
                    startA = ka + 1;
                } else {
                    k -= (kb - startB + 1);
                    startB = kb + 1;
                }
            }
        }
    
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            int mid = (m + n) / 2;
            if ((m + n) % 2 == 1) {
                return findKthElement(A, m, B, n, mid);
            } else {
                return (findKthElement(A, m, B, n, mid - 1) + findKthElement(A, m, B, n, mid)) / 2.0;
            }
        }
    };
}
