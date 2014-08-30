// https://oj.leetcode.com/problems/restore-ip-addresses/
namespace RestoreIPAddresses {
    class Solution {
    public:
    
        bool isValidIPSection(string sec) {
            if (sec.size() > 3 || sec.size() == 0) return false;
            int num = atoi(sec.c_str());
            if (num > 255) return false;
            if (sec[0] == '0' && sec.size() > 1) return false;
            return true;
        }
        vector<string> restoreIpAddresses(string s) {
            int pos1, pos2, pos3;
            vector<string> res;
            
            int len = s.size();
            for (pos1 = 1; pos1 <= 3; pos1++) {
                if (pos1 > len) break;
                string sec1 = s.substr(0, pos1);
                if (!isValidIPSection(sec1)) break;
                for (pos2 = pos1 + 1; pos2 <= pos1 + 3; pos2++) {
                    if (pos2 > len) break;
                    string sec2 = s.substr(pos1, pos2 - pos1);
                    if (!isValidIPSection(sec2)) break;
                    for (pos3 = pos2 + 1; pos3 <= pos2 + 3; pos3++) {
                        if (pos3 > len) break;
                        string sec3 = s.substr(pos2, pos3 - pos2);
                        if (!isValidIPSection(sec3)) break;
                        string sec4 = s.substr(pos3, s.size() - pos3);
                        if (!isValidIPSection(sec4)) continue; // NOTE here!
                        
                        string ipStr = sec1 + "." + sec2 + "." + sec3 + "." + sec4;
                        res.push_back(ipStr);
                    }
                }
            }
            return res;
        }
    };
}
