#include <vector>
#include "leetcode_common/tree"
using namespace leetcode;

namespace UniqueBinarySearchTrees2 {
	class Solution {
	public:
	    std::vector<TreeNode *> doGenerateTrees(int s, int e) {
	        std::vector<TreeNode *> nodes;

	        if (s > e) {
	            nodes.push_back(NULL);
	            return nodes;
	        }
	        for (int i = s; i <= e; i++) {
	            std::vector<TreeNode *> leftNodes = doGenerateTrees(s, i - 1);
	            std::vector<TreeNode *> rightNodes = doGenerateTrees(i + 1, e);
	            for (int j = 0; j < leftNodes.size(); j++) {
	                for (int k = 0; k < rightNodes.size(); k++) {
	                    TreeNode * n = new TreeNode(i);
	                    n->left = leftNodes[j];
	                    n->right = rightNodes[k];
	                    nodes.push_back(n);
	                }
	           }
	        }
	        
	        return nodes;

	    }
	    
	    std::vector<TreeNode *> generateTrees(int n) {
	        std::vector<TreeNode *> res;
	        if (n == 0) {
	            res.push_back(NULL);
	            return res;
	        }
	        return doGenerateTrees(1, n);
	    }
	};
}