#include <vector>
#include <string>

using namespace std;

namespace GasStation {

	class Solution {
	public:
	    // if fail, return how many node has been passed
	    // if success, return 0
	    int checkFromStart(int start, vector<int> &gas, vector<int> &cost, int size) {
	        int j = start;
	        int cur = 0;
	        int count = 0;
	        while (j != prev(start, size)) {
	            count++;
	            cur += gas[j];
	            if (cur < cost[j]) {
	                return count;
	            }
	            cur -= cost[j];
	            j = next(j, size);
	        }
	        
	        // last trip to the start point
	        count++;
	        cur += gas[j];
	        if (cur < cost[j]) {
	            return count;
	        }
	        
	        return 0;
	    }
	    
	    int prev(int cur, int size) {
	        int res = cur - 1;
	        return (res < 0? res + size: res);
	    }
	    
	    int next(int cur, int size) {
	        int res = cur + 1;
	        return (res >= size? res - size: res);
	    }
	    
	    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	        if (gas.empty() || cost.empty()) {
	            return -1;
	        }
	        
	        if (gas.size() != cost.size()) {
	            return -1;
	        }
	        
	        int size = gas.size();
	        
	        if (size == 1) {
	            return (gas[0] >= cost[0]? 0: -1);
	        }
	        
	        // start from point
	        for (int i = 0; i < size;) {
	            int res = checkFromStart(i, gas, cost, size);
	            if (res == 0) {
	                return i;
	            } else {
	                // jump to first point that's not touched
	                // if we checked i, i+1, i+2, ... k and found we can't go from k to k+1,
	                // it means that any index within [i, k] is impossible to be the start point.
	                // Therefore we start from k + 1
	                i += res;
	                if (i >= size) {
	                    break;
	                }
	            }
	        }
	        
	        return -1;
	    }
	};
        
}