// Problem - 190

// https://leetcode.com/problems/reverse-bits/

// O(1) time complexity and O(1) space complexity solution

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for(int i = 0; i < 32; i++){
            m = m | (n&1) << (31-i);
            n = n >> 1;
        }
        return m;
    }
};
