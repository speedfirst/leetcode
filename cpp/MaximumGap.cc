// https://oj.leetcode.com/problems/maximum-gap/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        
        set<int> S;
        for (int i = 0; i < num.size(); i++) {
            S.insert(num[i]);
        }
        
        set<int>::iterator it = S.begin();
        int prev = *it;
        it++;
        int maxGap = 0;
        for (; it != S.end(); it++) {
            int cur = *it;
            maxGap = max(maxGap, cur - prev);
            prev = cur;
        }
        return maxGap;
    }
};

// official bucket based solution
class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        
        int minValue = INT_MAX;
        int maxValue = 0;
        for (int i = 0; i < num.size(); i++) {
            minValue = min(minValue, num[i]);
            maxValue = max(maxValue, num[i]);
        }
        // note, the "double" & "ceil" is very important!!!
        int bucketRange = ceil(((double)(maxValue - minValue) / (num.size() - 1))); 
        int bucketNum = (maxValue - minValue) / bucketRange + 1;
        vector<int> lowers(bucketNum, -1); // -1 means it's empty
        vector<int> uppers(bucketNum, -1);
        
        for (int i = 0; i < num.size(); i++) {
            int bucketPos = (num[i] - minValue) / bucketRange;
            if (lowers[bucketPos] == -1) {
                lowers[bucketPos] = num[i];
                uppers[bucketPos] = num[i];
            } else {
                lowers[bucketPos] = min(lowers[bucketPos], num[i]);
                uppers[bucketPos] = max(uppers[bucketPos], num[i]);
            }
        }
        
        // iterate the buckets to get the max gap
        assert(uppers[0] != -1 && lowers[bucketNum - 1] != -1);
        int maxGap = 0;
        int prevUpper = uppers[0];
        for (int i = 1; i < bucketNum; i++) {
            if (lowers[i] == -1) continue;
            maxGap = max(maxGap, lowers[i] - prevUpper);
            prevUpper = uppers[i];
        }
        
        return maxGap;
    }
};
