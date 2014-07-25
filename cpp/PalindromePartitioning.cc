namespace PalindromePartitioning {
    class Solution {
    public:
         bool isPalindrome(string& s, int start, int end, vector<vector<int> >& cache) {
            if (cache[start][end] != -1) {
                return cache[start][end] == 1;
            }
            int i = start;
            int j = end;
            while (i < j) {
                if (s[i] != s[j]) {
                    cache[start][end] = 0;
                    return false;
                }
                i++;
                j--;
            }
            cache[start][end] = 1;
            return true;
        }
        
        void recursivePartition(vector<vector<string> >& result, vector<string>& curRes, string &s, int i, vector<vector<int > >& cache) {
            for (int k = i; k < s.size(); k++) {
                if (isPalindrome(s, i, k, cache)) {
                    curRes.push_back(s.substr(i, k - i + 1));
                    if (k == s.size() - 1) {
                        result.push_back(curRes);
                    } else {
                        recursivePartition(result, curRes, s, k + 1, cache);
                    }
                    curRes.pop_back();
                }
            }
        }
        
        vector<vector<string> > partition(string s) {
            vector<vector<string> > result;
            vector<string> curRes;
            
            // initialize cache
            vector<vector<int > > cache(s.size(), vector<int> (s.size(), -1));
            for (int i = 0; i < s.size(); i++) {
                cache[i][i] = 1;
            }
            
            recursivePartition(result, curRes, s, 0, cache);
            return result;
        }
    };
}