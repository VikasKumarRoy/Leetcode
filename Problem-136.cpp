//Problem - 136

// https://leetcode.com/problems/single-number/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    int singleNumber(vector <int>& nums) {
        int xr = 0;
        for(int v : nums)
            xr = xr ^ v;
        return xr;
    }
};