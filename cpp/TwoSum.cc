// https://oj.leetcode.com/problems/two-sum/
namespace TwoSum {
    class Entry {
    public:
        Entry(int number, int index): num(number), idx(index) {}
        int num;
        int idx;
    };
    
    bool compareEntry(const Entry &a, const Entry &b) {
        return a.num < b.num;
    }
    
    
    class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            
            vector<Entry> entries;
            for (int i = 1; i <= numbers.size(); i++) {
                Entry entry(numbers[i - 1], i);
                entries.push_back(entry);
            }
            
            sort(entries.begin(), entries.end(), compareEntry);
            
            int i = 0; int j = entries.size() - 1;
            while (i < j) {
                int sum = entries[i].num + entries[j].num;
                if (sum > target) {
                    j--;
                } else if (sum < target) {
                    i++;
                } else {
                    vector<int> res;
                    res.push_back(min(entries[i].idx, entries[j].idx));
                    res.push_back(max(entries[i].idx, entries[j].idx));
                    return res;
                }
            }
            
             vector<int> emp;
             return emp;
            
        }
    };
}
