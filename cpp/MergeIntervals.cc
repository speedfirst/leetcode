namespace MergeIntervals {
    struct IntervalComp {
        bool operator () (Interval interval1, Interval interval2) {
            return interval1.start < interval2.start;
        }
    };
    
    class Solution {
    public:
    
        vector<Interval> merge(vector<Interval> &intervals) {
            
            if (intervals.empty() || intervals.size() == 1) {
                return intervals;
            }
            
            // sort according to the "start" of interval
            sort(intervals.begin(), intervals.end(), IntervalComp());
            
            int i = 1;
            vector<Interval> res;
            Interval prev = intervals[0];
            res.push_back(prev);
            while (i < intervals.size()) {
                
                Interval cur = intervals[i];
                if (cur.start <= prev.end) {
                    if (cur.end > prev.end) {
                        // half overlap, merge
                        res.pop_back();
                        Interval merged(prev.start, cur.end);
                        prev = merged;
                        res.push_back(merged);
                    } else {
                        // cur interval is contained by prev, ignore it
                        // do nothing
                    } 
                } else { // not overlap, mov prev forward
                    prev = cur;
                    res.push_back(cur);
                }
                i++;
            }
            
            return res;
        }
    };
}
