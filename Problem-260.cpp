// Problem - 260

// https://leetcode.com/problems/single-number-iii/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    vector <int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        int xr = 0;
        for(int val : nums)
            xr ^= val;
        int pos = 0;
        while(1) {                                      //find first set bit from right
            if((xr>>pos) & 1)
                break;
            pos++;
        }
        for(int val : nums) {
            if(val>>pos & 1)
                a ^= val;
            else
                b ^= val;
        }
        return {a, b};
    }
};