// https://oj.leetcode.com/problems/read-n-characters-given-read4/
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (buf == NULL) {
            return 0;
        }
        
        char inbuf[4];
        
        int count = 0;
        int readCount = 4;
        while (count < n && readCount == 4) {
            readCount = read4(inbuf);
            int copiedCount = min(readCount, n - count);
            memcpy(buf, inbuf, copiedCount);
            buf += copiedCount;
            count += copiedCount;
        }
        return count;
    }
};
