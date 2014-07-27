#include <vector>
using namespace std;

namespace AddBinary {
	class Solution {
	public:
	    string addBinary(string a, string b) {
	        int carry = 0;
	        string result;
	        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
	            int na = (i >= 0?(a[i] - '0') : 0);
	            int nb = (j >= 0?(b[j] - '0') : 0);
	            int sum = na + nb + carry;
	            int res = sum % 2;
	            carry = sum / 2;
	            result.insert(result.begin(), res + '0'); // for better performance, we can always append the result and reverse it later
	        }
	        
	        if (carry == 1) {
	            result.insert(result.begin(), '1');
	        }
	        
	        return result;
	    }
	};	
}