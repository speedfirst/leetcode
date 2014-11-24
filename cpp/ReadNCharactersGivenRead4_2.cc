// https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
        char tmpBuf[4];
        int tmpStart = 0;
        int tmpEnd = 0;
        bool eof = false;
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n == 0) return 0;

        int count = 0;
        bool eof = false;
        do {
            int tmpLen = tmpEnd - tmpStart;
            int copyCount = min(tmpLen, n - count);
            if (copyCount > 0) {
                memcpy(buf + count, tmpBuf + tmpStart, copyCount);
                count += copyCount;
                tmpStart += copyCount;
            }
            if (eof || n == count) {
                break;
            } else {
                int readCount = read4(tmpBuf);
                tmpStart = 0;
                tmpEnd = readCount;
                if (readCount < 4) {
                    eof = true;
                }
            }
        } while (true);

        return count;
    }
};
