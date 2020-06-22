// Problem - 1486

// https://leetcode.com/problems/xor-operation-in-an-array/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int xorOperation(int n, int start) {
        int xr = 0;
        for(int i = 0; i < n; i++) {
            xr ^= start + 2 * i;
        }
        return xr;
    }
};
