// https://oj.leetcode.com/problems/two-sum-iii-data-structure-design/
// O(1) add, O(n) find
class TwoSum {
private:
    unordered_map<int, int> rec;
public:
    void add(int number) {
        rec[number]++;
    }

    bool find(int value) {
        for (auto it = rec.begin(); it != rec.end(); it++) {
            int val = value - it->first;
            if (val == it->first) {
                if (it -> second > 1) return true; // check whether there is duplication?
            } else {
                if (rec.find(val) != rec.end()) {
                    return true;
                }
            }
        }
        return false;
    }
};
