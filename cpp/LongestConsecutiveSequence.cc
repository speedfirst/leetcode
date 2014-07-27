#include <unordered_set>
using namespace std;

namespace LongestConsecutiveSequence {
	class Solution {
	public:
	    int longestConsecutive(vector<int> &num) {
	        unordered_set<int> set;
	        
	        for (int i = 0; i < num.size(); i++) {
	            set.insert(num[i]);
	        }
	        
	        int max = 0;
	        for (int i = 0; i < num.size(); i++) {
	            int cur = num[i];
	            int left = cur - 1;
	            int right = cur + 1;
	            set.erase(cur);
	            
	            int count = 1;
	            while(set.find(left) != set.end()) {
	                set.erase(left);
	                count++;
	                left--;
	            }
	            
	            while(set.find(right) != set.end()) {
	                set.erase(right);
	                count++;
	                right++;
	            }
	            
	            if (max < count) {
	                max = count;
	            }
	        }
	        
	        return max;
	    }
	};
}