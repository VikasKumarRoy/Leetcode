// Problem - 191

// https://leetcode.com/problems/number-of-1-bits/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ctr = 0;
        while(n) {
            ctr += n & 1;
            n >>= 1;
        }
        return ctr;
    }
};
