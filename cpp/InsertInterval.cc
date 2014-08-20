namespace InsertInterval {
    class Solution {
    public:
        // Seems the binary search is of no use in this problem because later we will remove/insert part of vector,
        // which is O(n). But since I've implemented it, just put it here.
        // When search "start" of interval, return the pos of biggest element <= target
        // When search "end" of interval, return the pos of smallest element >= target
        int binarySearch(vector<Interval> &intervals, Interval newInterval, bool searchStart) {
            int left = 0;
            int right = intervals.size() - 1;
            int target = (searchStart? newInterval.start: newInterval.end);
            int mid;
            while (left <= right) {
                mid = ((right - left) >> 1) + left;
                int cur = (searchStart? intervals[mid].start : intervals[mid].end);
                if (cur == target) {
                    return mid;
                } else if (cur > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
    
            return searchStart? right:left; // if not found, return "floor" pos when searching start or "celing" pos when searching end
        }
    
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> res;
    
            Interval minInterval(INT_MIN, INT_MIN);
            Interval maxInterval(INT_MAX, INT_MAX);
            res.push_back(minInterval);
            res.insert(res.begin() + 1, intervals.begin(), intervals.end());
            res.push_back(maxInterval); // add dummy min and max to make startPos and endPos are always valid
    
            int startPos = binarySearch(res, newInterval, true);
            int endPos = binarySearch(res, newInterval, false);
    
            if (newInterval.start > res[startPos].end){
                if (newInterval.end < res[endPos].start) {
                    // no overlap
                    res.erase(res.begin() + startPos + 1, res.begin() + endPos);
                    res.insert(res.begin() + startPos + 1, newInterval);
                } else {
                    // right overlap, merge right part
                    newInterval.end = res[endPos].end;
                    res.erase(res.begin() + startPos + 1, res.begin() + endPos + 1);
                    res.insert(res.begin() + startPos + 1, newInterval);
                }
            } else {
                if (newInterval.end < res[endPos].start) {
                    // left overlap, merge left part
                    newInterval.start = res[startPos].start;
                    res.erase(res.begin() + startPos, res.begin() + endPos);
                    res.insert(res.begin() + startPos, newInterval);
                } else {
                    // two sides overlap
                    newInterval.start = res[startPos].start;
                    newInterval.end = res[endPos].end;
                    res.erase(res.begin() + startPos, res.begin() + endPos + 1);
                    res.insert(res.begin() + startPos, newInterval);
                }
            }
    
            // remove min and max interval
            res.erase(res.begin(), res.begin() + 1);
            res.pop_back();
            return res;
        }
    };
}
