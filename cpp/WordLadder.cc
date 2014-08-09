namespace WordLadder {
  class Solution {
  public:
      
      int ladderLength(string start, string end, unordered_set<string> &dict) {
          // BFS Search
          queue<string> wq; // queue for words
          queue<int> lq; // queue for level
          wq.push(start);
          lq.push(1);
          dict.erase(start);
          
          while (!wq.empty()) {
              string s = wq.front();
              wq.pop();
              int level = lq.front();
              lq.pop();
  
              // try to enumerate each possible one-char change.
              // Here we enumerate "a" -> "z", rather than all the words in dict
              // This way, the complexity is O(m * 26) rather than O(m * n), where m is the length of word, n is the size of dict
              for (int i = 0; i < s.size(); i++) {
                  char origChar = s[i];
                  for (char c = 'a'; c <= 'z'; c++) {
                      s[i] = c;
                      if (s == end) {
                          return level + 1;
                      }
                      
                      if (dict.find(s) != dict.end()) {
                          wq.push(s);
                          lq.push(level + 1);
                          dict.erase(s);
                      }
                  }
                  s[i] = origChar;
              }
              
          }
          
          // not found
          return 0;
      }
  };
}
