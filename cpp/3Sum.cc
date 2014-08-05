namespace ThreeSum {
  class Solution {
  public:
    void twoSum(vector<int> &num, int i, int start, int end, vector<vector<int> > & res) {
        int sum = 0 - num[i];
        int j = start;
        int k = end;
        while (j < k) {
            // remove duplicates
            if (j > start && num[j] == num[j - 1]) {
                j++;
                continue;
            }
            
            if (k < end && num[k] == num[k + 1]) {
                k--;
                continue;
            }
            
            if (num[j] + num[k] == sum) {
                vector<int> cur;
                cur.push_back(num[i]);
                cur.push_back(num[j]);
                cur.push_back(num[k]);
                res.push_back(cur);
                j++;
                k--;
            } else if (num[j] + num[k] > sum) {
                k--;
            } else {
                j++;
            }
        }
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
        if (num.size() < 3) {
            return res;
        }
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue; // remove duplicates
            }
            twoSum(num, i, i + 1, num.size() - 1, res);
        }
        
        return res;
    }
  };
}
