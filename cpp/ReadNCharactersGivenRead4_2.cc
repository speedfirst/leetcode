// https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

int read4(char *buf);

class Solution {
public:

    char myBuf[4];
    int myBufStart = 0;
    int myBufLen = 0;
    bool eof = false;
    
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int readBytes = 0;
        int bufStart = 0;
        while (!eof && readBytes < n) {
            if (myBufLen == 0) {
                myBufLen = read4(myBuf);
                myBufStart = 0;
                if (myBufLen < 4) eof = true;
            }
            int copiedBytes = min(myBufLen, n - readBytes);
            memcpy(buf + bufStart, myBuf + myBufStart, copiedBytes);
            myBufStart += copiedBytes;
            myBufLen -= copiedBytes;
            bufStart += copiedBytes;
            readBytes += copiedBytes;
        }
        return readBytes;
    }
};
