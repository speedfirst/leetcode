// https://oj.leetcode.com/problems/max-points-on-a-line/
namespace MaxPointOnALine {
    /**
     * Definition for a point.
     * struct Point {
     *     int x;
     *     int y;
     *     Point() : x(0), y(0) {}
     *     Point(int a, int b) : x(a), y(b) {}
     * };
     */
    class Solution {
    public:
        int maxPoints(vector<Point> &points) {
            
            if (points.size() <= 2) {
                return points.size();
            }
            
            int maxPoints = 0;
            unordered_map<double, int> map; // <slope, count>
            for (int i = 0; i < points.size() - 1; i++) {
                map.clear();
                int verticalNum = 0;
                int samePointNum = 1;
                Point p1 = points[i];
                for (int j = i + 1; j < points.size(); j++) {
                    Point p2 = points[j];
                    
                    if (p1.x == p2.x && p1.y == p2.y) {
                        samePointNum++;
                    } else if (p1.x == p2.x) {
                        verticalNum++;
                    } else {
                        double slope = ((double)(p1.y - p2.y)) / (p1.x - p2.x);
                        
                        unordered_map<double, int>::iterator it = map.find(slope);
                        if (it == map.end()) {
                            map[slope] = 1;
                        } else {
                            map[slope]++;
                        }
                    }
                }
                    
                // traverse the map to find out the max count with slope
                int maxCount = 0;
                for (unordered_map<double, int>::iterator it = map.begin(); it != map.end(); it++ ) {
                    if (it->second > maxCount) {
                        maxCount = it->second;
                    }
                }
                
                if (verticalNum > maxCount) {
                    maxCount = verticalNum;
                }
                
                maxCount += samePointNum;
                
                if (maxCount > maxPoints) {
                    maxPoints = maxCount;
                }
            }
            return maxPoints;
        }
        
    };
}
