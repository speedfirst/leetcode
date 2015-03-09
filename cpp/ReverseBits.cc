// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    unordered_map<uint32_t, uint32_t> cache;
    uint32_t reverseBits(uint32_t n) {
        unordered_map<uint32_t, uint32_t>::iterator it = cache.find(n);
        if (it != cache.end()) {
            return it->second;
        }
        
        uint32_t res = 0;
        int val = n;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = val & 0x01;
            res <<= 1;
            res |= bit;
            val >>= 1;
        }
        
        cache[n] = res;
        
        return res;
    }
};
