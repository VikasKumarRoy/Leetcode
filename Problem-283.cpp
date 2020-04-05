// Problem - 283

// https://leetcode.com/problems/move-zeroes/

// O(n) time complexity and O(1) space complexity solution

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastPos = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[lastPos++], nums[i]);
        }
        return;
    }
};
