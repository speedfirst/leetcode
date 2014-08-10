namespace WordLadder2 {
  class Solution {
  public:
    typedef unordered_set<string>::iterator HashIter;
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<string> wq; // word queue
        const string EOL(""); // indicate "End Of Level"
        wq.push(start);
        wq.push(EOL);
        bool hasFound = false;
        unordered_map<string,vector<string> > seqHistory; // sequence history
        unordered_set<string> toBeDeleted; // keep the words in the same level that have been found in dict.
        while(!wq.empty()) {
            string origStr = wq.front();
            wq.pop();
            if(origStr != EOL) {
                // try to enumerate each possible one-char change.
                // Here we enumerate "a" -> "z", rather than all the words in dict
                // This way, the complexity is O(m * 26) rather than O(m * n), where m is the length of word, n is the size of dict
                string curStr(origStr);
                for(int i = 0; i < curStr.length(); i++) {
                    char origChar = curStr[i];
                    for(char c = 'a'; c <= 'z'; c++) {
                        curStr[i] = c;
                        if (c == origChar) {
                            continue;
                        }
                        if(curStr == end) {
                            hasFound = true;
                            seqHistory[end].push_back(origStr);
                            // we've already found solution, no need to search more in this path
                            goto END;
                        }
                        
                        if(dict.find(curStr) != dict.end()) {
                            seqHistory[curStr].push_back(origStr);
                            //ensure not insert duplicated words in q
                            if(toBeDeleted.find(curStr) == toBeDeleted.end()) {
                                wq.push(curStr); 
                                toBeDeleted.insert(curStr);
                            }
                        }
                    }
                    curStr[i] = origChar;
                }
            } else {
                if(!wq.empty()) { // end of current level 
                    if(hasFound) break;
                    // clear words in "toBeDeleted" in dict to avoid "endless loop"
                    for(HashIter it = toBeDeleted.begin(); it != toBeDeleted.end(); it++)
                        dict.erase(*it);
                    toBeDeleted.clear();
                    wq.push(EOL);
                }
            }
        END: ;
        }
        
        //build the final result
        vector<vector<string> > res;
        if(seqHistory.find(end) == seqHistory.end())return res;
        vector<string> curRes;
        curRes.push_back(end);
        constructResult(seqHistory, res, curRes, start, end);
        return res;
    }
    
    // build the final result from seqHistory
    void constructResult(unordered_map<string,vector<string> > &seqHistory, 
        vector<vector<string> > &res, vector<string> &curRes, 
        string &start, string &curWord) {
        if(start == curWord) {
            reverse(curRes.begin(), curRes.end());
            res.push_back(curRes);
            reverse(curRes.begin(), curRes.end());
            return;
        }
        vector<string> &prevWords = seqHistory[curWord];
        for(int i = 0; i < prevWords.size(); i++) {
            curRes.push_back(prevWords[i]);
            constructResult(seqHistory, res, curRes, start, prevWords[i]);
            curRes.pop_back();
        }
    }
`};
}
