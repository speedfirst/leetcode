#include <vector>
#include <string>

using namespace std;

namespace TextJustification {

	class Solution {
	public:
	    vector<string> fullJustify(vector<string> &words, int L) {
	        vector<string> res;
	        if (words.empty() || L == 0) {
	            string str(L, ' ');
	            res.push_back(str);
	            return res;
	        }
	        
	        vector<vector<string> > lines;
	        vector<int> linesLen;
	        int len = 0;
	        vector<string> line;
	        for (int i = 0; i < words.size(); i++) {
	            string w = words[i];
	            if (len + w.size() >= L - line.size() + 1) {
	                lines.push_back(line);
	                linesLen.push_back(len);
	                len = w.size();
	                line.clear();
	            } else {
	                len += w.size();
	            }
	            line.push_back(w);
	        }
	        
	        if (!line.empty()) {
	            lines.push_back(line);
	            linesLen.push_back(len);
	        }


	        string lineText;
	        for (int i = 0; i < lines.size() - 1; i++) {
	            vector<string>& curLine = lines[i];
	            lineText = "";
	            if (curLine.size() == 1) {
	                string padding(L - linesLen[i], ' ');
	                lineText = curLine[0] + padding;
	                res.push_back(lineText);
	            } else {
	                int gapNum = curLine.size() - 1;
	                int spaceNum = L - linesLen[i];
	                int spaceNumPerGap = spaceNum / gapNum;
	                int extraSpaceNum = spaceNum - spaceNumPerGap * gapNum;
	                string bigPadding(spaceNumPerGap + 1, ' ');
	                string smallPadding(spaceNumPerGap, ' ');
	                int j = 0;
	                for (; j < curLine.size() - 1; j++) {
	                    lineText += curLine[j];
	                    if (extraSpaceNum > 0) {
	                        lineText += bigPadding;
	                        extraSpaceNum--;
	                    } else {
	                        lineText += smallPadding;
	                    }
	                }
	                lineText += curLine[j];
	                res.push_back(lineText);
	            }
	        }
	        
	        // handle the last line
	        vector<string> &lastLine = lines[lines.size() - 1];
	        lineText = lastLine[0];
	        for (int k = 1; k < lastLine.size(); k++) {
	            lineText += " ";
	            lineText += lastLine[k];
	        }
	        
	        string lastPadding(L - lineText.size(), ' ');
	        lineText += lastPadding;
	        res.push_back(lineText);
	        return res;
	    }
	};
}