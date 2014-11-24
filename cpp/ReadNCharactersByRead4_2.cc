// https://oj.leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
// not pass the oj but don't know why

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:

    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (n == 0) return 0;
        static vector<char> cache; // cache the data we read so far

        char tmpBuf[4];
        int count = 0;
        int readCount = 4;
        while (cache.size() < n && readCount == 4) {
            readCount = read4(tmpBuf);
            for (int i = 0; i < readCount; i++) {
                cache.push_back(tmpBuf[i]);
            }
        }

        int copyCount = min((int)cache.size(), n);
        copy(cache.begin(), cache.begin() + copyCount, buf);
        cache.erase(cache.begin(), cache.begin() + copyCount);
        return copyCount;
    }
};
